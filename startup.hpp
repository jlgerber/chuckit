
#pragma once
#include <QObject>


class MainWindow;
class ChuckitModel;

class Startup : public QObject
{
    Q_OBJECT
public:
    explicit Startup();
    ~Startup();

    void show();
public slots:
    void printJoke(QString joke);
private:
    MainWindow& m_mainwindow;
    ChuckitModel& m_model;

    explicit Startup(const Startup& rhs) = delete;
    Startup& operator= (const Startup& rhs) = delete;
};



