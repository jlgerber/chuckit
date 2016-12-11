#include "chuckconfig.hpp"
#include <QString>

using std::pair;

ChuckitConfig::ChuckitConfig(QObject* parent) :
    QObject(parent),
    m_url{QString("http://api.icndb.com/jokes/random/%1")},
    m_headerpairs { { {"id", "int"}, {"joke", "string"} } },
    m_jokecnt{ 7 }

{}

QString ChuckitConfig::getJokeUrl() const
{
    return m_url;
}

int ChuckitConfig::getJokeCnt() const
{
    return m_jokecnt;
}


HeaderList ChuckitConfig::getHeaderPairs() const {
    return m_headerpairs;
}
