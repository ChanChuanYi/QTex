#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

QString fileName;
QFileDialog fd;
fileName = fd.getOpenFileName(this,"yaya open file","","Image(8.jpg)");
}

MainWindow::~MainWindow()
{
    delete ui;
}
