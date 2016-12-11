#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include <QJsonArray>
#include <QJsonObject>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDebug>
#include <memory>

template <typename OutCollection,typename InCollection, typename unop>
  OutCollection map(InCollection col,unop op) {
      OutCollection out;
      for(auto i = col.begin(); i != col.end(); i++) {
          out.push_back(op(*i));
      }
  return out;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_jokecnt{1}
{    
    ui->setupUi(this);
    ui->twJoke->horizontalHeader()->setStretchLastSection(true);

    connect(
        ui->twJoke->horizontalHeader(),
        &QHeaderView::sectionResized,
         ui->twJoke,
        &QTableView::resizeRowsToContents
            );
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::setJokes(QJsonArray &arr)
{
    // clear the table
    ui->twJoke->clearContents();
    ui->twJoke->setRowCount(arr.size());
    qDebug() << "Start table population"<< endl;;
    for(auto r=0;r<arr.size(); r++) {
        auto row = arr[r].toObject();
       int c=0;

        for(auto rw= m_headerpairs.begin(); rw != m_headerpairs.end(); rw++) {
            QTableWidgetItem* item;
            if(rw->second == "string")
                item = new QTableWidgetItem(row.value(rw->first).toString().replace("&quot;", "\"") );
            else if(rw->second=="int")
               item = new QTableWidgetItem(QString::number(row.value(rw->first).toInt()) );
            else if(rw->second == "double")
                 item = new QTableWidgetItem(QString::number(row.value(rw->first).toDouble()) );
            else {
                item = new QTableWidgetItem(row.value(rw->first).toString() );
                qDebug() << "defualt conversion";
            }
            ui->twJoke->setItem(r,c,item );

            c++;
        }


    }
    ui->twJoke->resizeColumnsToContents();
    qDebug() << "End table population"<< endl;;

}

void MainWindow::setTableHeaders(const HeaderList headers)
{
    m_headerpairs = headers;
    ui->twJoke->setHorizontalHeaderLabels(map<QStringList,HeaderList>(headers, [&](HeaderPair strpair){return strpair.first; }));
}

void MainWindow::setNotBusy()
{
    ui->pbBusy->setMaximum(100);
}

void MainWindow::setJokeCnt(int cnt)
{
    m_jokecnt = cnt;
}

void MainWindow::setBusy()
{
    ui->pbBusy->setMaximum(0);
}


void MainWindow::on_btnGetJoke_clicked()
{
    emit getJokes();
}

QStringList MainWindow::getHeaders() const
{
    return map<QStringList,HeaderList>(m_headerpairs, [](HeaderPair strpair){return strpair.first; });

}

