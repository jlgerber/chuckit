#include "chuckitmodel.hpp"
#include <QNetworkAccessManager>
#include <QString>
#include <QByteArray>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

ChuckitModel::ChuckitModel(QObject *parent) :
    QObject(parent),
    m_netman{*new QNetworkAccessManager(this)}

{
    connect(&m_netman, &QNetworkAccessManager::finished, this, &ChuckitModel::readReady);
}

void ChuckitModel::getJoke(int num) {
    m_netman.get(QNetworkRequest( QUrl(QString("http://api.icndb.com/jokes/random/%1").arg(QString::number(num)))));
}

void ChuckitModel::readReady(QNetworkReply* reply) {
    QByteArray data = reply->readAll();
    QString joke_str=data;
    QJsonDocument d = QJsonDocument::fromJson(joke_str.toUtf8());
    QJsonObject root = d.object();
    auto value_array = root["value"].toArray();
    auto value_obj = value_array[0];
    auto joke = value_obj.toObject()["joke"];

    emit(tellJoke(joke.toString().replace("&quot;", "\"")));
}
