#include "mainwindow.hpp"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{    
    ui->setupUi(this);
    ui->lblJoke->setAlignment(Qt::AlignVCenter);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setPlainText(QString &str)
{
    ui->lblJoke->setText(str);
}

void MainWindow::setNotBusy()
{
    ui->pbBusy->setMaximum(100);
}

void MainWindow::setBusy()
{
    ui->pbBusy->setMaximum(0);
}

void MainWindow::on_btnGetJoke_clicked()
{
   emit getJoke(1);
}
