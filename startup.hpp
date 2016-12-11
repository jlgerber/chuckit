
#pragma once
#include <QObject>


class MainWindow;
class ChuckitModel;
class ChuckitConfig;
class QJsonArray;

class Startup : public QObject
{
    Q_OBJECT
public:
    explicit Startup();
    ~Startup();

    void show();

private:
    MainWindow& m_mainwindow;
    ChuckitConfig& m_config;
    ChuckitModel& m_model;

    explicit Startup(const Startup& rhs) = delete;
    Startup& operator= (const Startup& rhs) = delete;
};



