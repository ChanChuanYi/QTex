#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    clock = new QTimer;
    clock->setInterval(1000);
    connect(clock,SIGNAL(timeout()),this,SLOT(updateTime()));
    clock->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTime()
{

    QTime time;
    time = time.currentTime();

    //qDebug() << time.toString("hh:mm:ss");
    timeSequence.append(time.toString("hh:mm:ss"));

    QDate date;
    date = date.currentDate();
    //qDebug() << date.toString("yyyy-MM-dd");
    QString event ;
    event = ui->textEdit->toPlainText();
    QTime settingTime;
    settingTime = ui->timeEdit->time();
    QDate settingDate ;
    settingDate = ui->calendarWidget->selectedDate();
//    if(date ==settingDate && settingTime = time.msecsTo(1800000)){
//        qDebug()<<event<<"!!!!";
//    }
}



void MainWindow::on_LoadButton_3_clicked()
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this, tr("text"), ""
        , tr("Text files (*.txt)"));
    ui->textEdit->setText(fileName);


}

void MainWindow::on_SaveButton_2_clicked()
{
    QString events;
    events = ui->textEdit->toPlainText();

    QTime settingTime;
    settingTime = ui->timeEdit->time();
    QDate settingDate ;
    settingDate = ui->calendarWidget->selectedDate();
    QVector<QString> timing;
    timing.append(settingDate.toString());
    timing.append(settingTime.toString());
    timing.append(events);
    QFile file("events.txt");
    if(file.open(QFile::WriteOnly|QFile::Truncate|QFile::Text)){
        QTextStream out(&file);
        out<<timing[0]<<" "<<timing[1]<<" "<<timing[2]<<endl;
    }
   // QFile file("events.txt");

//    if(file.open(WriteOnly|Truncate|Text)){
//        QTextStream out(&file);
//        out<<timing<<endl;
//    }

}

void MainWindow::on_ScheduleButton_4_clicked()
{

    QString events ;
    events = ui->textEdit->toPlainText();
    QTime settingTime;
    settingTime = ui->timeEdit->time();
    QDate settingDate ;
    settingDate = ui->calendarWidget->selectedDate();
    QVector<QString> timing;
    timing.append(settingDate.toString());
    timing.append(settingTime.toString());
    timing.append(events);
    ui->label->setText(timing[0]+" "+timing[1]+" "+timing[2]);

}
