
#pragma once
#include <QObject>

class QNetworkAccessManager;
class QString;
class QByteArray;
class QNetworkReply;
class QJsonArray;
class ChuckitConfig;

class ChuckitModel : public QObject
{
    Q_OBJECT
public:
    explicit ChuckitModel(QObject *parent, ChuckitConfig& config);

public slots:
    void setJokeCount(int num);
    void setJokeUrl(const QString& url);
    void getJoke(int num=1);
    void getJokes();

signals:
    void tellJokes(QJsonArray& jokes);

private slots:
    void readReady(QNetworkReply *reply);
private:
    QNetworkAccessManager& m_netman;

    ChuckitConfig& m_config;

    int m_joke_cnt=1;
    QString m_joke_url;


    explicit ChuckitModel(const ChuckitModel& rhs) = delete;
    ChuckitModel& operator= (const ChuckitModel& rhs) = delete;
};


