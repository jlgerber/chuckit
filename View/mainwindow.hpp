#pragma once
#include <QMainWindow>
#include <QVector>
#include <utility>

namespace Ui {
    class MainWindow;
    }

class QStringList;
class QString;


using HeaderPair = std::pair< QString, QString>;
using HeaderList = QVector<HeaderPair>;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void getJoke(int);
    void getJokes();

public slots:
    void setBusy();
    void setNotBusy();
    void setJokeCnt(int cnt);
    void setJokes(QJsonArray& arr);
    //void setTableHeaders(const QStringList& headers);
    void setTableHeaders(HeaderList headers);

private slots:
    void on_btnGetJoke_clicked();

private:
    Ui::MainWindow *ui;
    int m_jokecnt;
    HeaderList  m_headerpairs;
    QStringList getHeaders() const;
    //QStringList m_headerlist;
};
