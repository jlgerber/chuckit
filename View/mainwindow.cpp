#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->teJoke->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setPlainText(QString &str)
{
    ui->teJoke->setPlainText(str);
}

void MainWindow::on_pushButton_clicked()
{
    emit getJoke(1);
}
