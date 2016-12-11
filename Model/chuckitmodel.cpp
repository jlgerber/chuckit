#include "chuckitmodel.hpp"

#include <QNetworkAccessManager>
#include <QString>
#include <QByteArray>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

#include "chuckconfig.hpp"
// todo: refactor model. NetworkAccessManager should be injected as a service
// class HttpJokeProvider : IJokeProvider or class TestJokeProvider : IJokeProvider
ChuckitModel::ChuckitModel(QObject *parent, ChuckitConfig& config) :
    QObject(parent),
    m_netman{*new QNetworkAccessManager(this)},
    m_config{config},
    m_joke_cnt{config.getJokeCnt()},
    m_joke_url{config.getJokeUrl()}
{
    connect(&m_netman, &QNetworkAccessManager::finished, this, &ChuckitModel::readReady);
}

void ChuckitModel::setJokeCount(int num)
{
    m_joke_cnt = num;
}

void ChuckitModel::setJokeUrl(const QString& url) {
    m_joke_url = url;
}

void ChuckitModel::getJoke(int num) {
    QString url = m_joke_url.arg(QString::number(num));
    qDebug() << "ChuckitModel::getJoke url:" << url;

    m_netman.get( QNetworkRequest(QUrl(url)));
}

void ChuckitModel::getJokes()
{
   this->getJoke(m_joke_cnt);
}

// PRIVATES -----------------------------
void ChuckitModel::readReady(QNetworkReply* reply) {
    QByteArray data = reply->readAll();
    QString joke_str=data;
    QJsonDocument d = QJsonDocument::fromJson(joke_str
                                              .toUtf8()
                                              );
    QJsonObject root = d.object();
    auto value_array = root["value"].toArray();
    emit(tellJokes(value_array));
}
