#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QString>
#include <QFileDialog>
#include <QTime>
#include <QTimer>
#include <QDateTime>
#include <QVector>
#include <QDate>
#include <QFile>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer *clock;
    QVector<QString> timeSequence;

private slots:
    void updateTime();

    void on_LoadButton_3_clicked();
    void on_SaveButton_2_clicked();
    void on_ScheduleButton_4_clicked();
};




#endif // MAINWINDOW_H
