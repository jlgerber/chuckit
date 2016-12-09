
#pragma once
#include <QObject>

class QNetworkAccessManager;
class QString;
class QByteArray;
class QNetworkReply;

class ChuckitModel : public QObject
{
    Q_OBJECT
public:
    explicit ChuckitModel(QObject *parent=0);
public slots:
    void getJoke(int num=1);
signals:
    void tellJoke(QString joke);
private slots:
    void readReady(QNetworkReply *reply);
private:
    QNetworkAccessManager& m_netman;

    explicit ChuckitModel(const ChuckitModel& rhs) = delete;
    ChuckitModel& operator= (const ChuckitModel& rhs) = delete;
};


