#include "startup.hpp"
#include "View/mainwindow.hpp"
#include "Model/chuckitmodel.hpp"
#include "Model/chuckconfig.hpp"

#include <QDebug>
#include <QJsonArray>

Startup::Startup() :
    QObject(nullptr) ,
  m_mainwindow{*new MainWindow(nullptr)},
  m_config{*new ChuckitConfig(this)},
  m_model{*new ChuckitModel(this, m_config)}
{
    m_mainwindow.setJokeCnt(m_config.getJokeCnt());
    m_mainwindow.setTableHeaders(m_config.getHeaderPairs());

    connect(&m_mainwindow, &MainWindow::getJokes, &m_model, &ChuckitModel::getJokes);
    connect(&m_mainwindow, &MainWindow::getJokes, &m_mainwindow, &MainWindow::setBusy);

    connect(&m_model, &ChuckitModel::tellJokes, &m_mainwindow, &MainWindow::setJokes);
    connect(&m_model, &ChuckitModel::tellJokes, &m_mainwindow, &MainWindow::setNotBusy);

}

Startup::~Startup()
{
    delete &m_mainwindow;
}



void Startup::show()
{
    m_mainwindow.show();
}

