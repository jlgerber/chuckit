
#pragma once
#include <QObject>
#include <utility>
#include <QVector>


class QString;
class QStringList;

using HeaderPair = std::pair< QString, QString>;
using HeaderList = QVector<HeaderPair>;

class ChuckitConfig : public QObject
{
public:
    ChuckitConfig(QObject* parent=nullptr);

public slots:
    QString getJokeUrl() const;
    HeaderList getHeaderPairs() const;
    int getJokeCnt() const;

private:
    QString m_url;         // query url
    HeaderList m_headerpairs;
    int m_jokecnt;         // default number of jokes to query for

    explicit ChuckitConfig(const ChuckitConfig& rhs) = delete;
    ChuckitConfig& operator= (const ChuckitConfig& rhs) = delete;
};


