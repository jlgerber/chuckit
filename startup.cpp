#include "startup.hpp"
#include "View/mainwindow.hpp"
#include "Model/chuckitmodel.hpp"
#include <QDebug>

Startup::Startup() :
    QObject(nullptr) ,
  m_mainwindow{*new MainWindow(nullptr)},
  m_model{*new ChuckitModel(this)}
{
    connect(&m_mainwindow, &MainWindow::getJoke, &m_model, &ChuckitModel::getJoke);
    connect(&m_mainwindow, &MainWindow::getJoke, &m_mainwindow, &MainWindow::setBusy);

    connect(&m_model, &ChuckitModel::tellJoke, this, &Startup::printJoke);
    connect(&m_model, &ChuckitModel::tellJoke, &m_mainwindow, &MainWindow::setNotBusy);

}

Startup::~Startup()
{
    delete &m_mainwindow;
}

void Startup::printJoke(QString joke) {
    qDebug() << "Here is the Joke" << joke << endl;
    m_mainwindow.setPlainText(joke);
}

void Startup::show()
{
    m_mainwindow.show();
}

