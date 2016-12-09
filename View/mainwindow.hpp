#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

namespace Ui {
    class MainWindow;
    }

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setPlainText(QString& str);

signals:
    void getJoke(int);

public slots:
    void setBusy();
    void setNotBusy();

private slots:
    void on_btnGetJoke_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_HPP
