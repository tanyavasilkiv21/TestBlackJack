#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("D:/Qt_study/TestStudy/TestBlack/images/Start.png");
    ui->PictureLabel->setPixmap(pix);
    ui->PictureLabel->setFixedSize(840,626);
    ui->PictureLabel->lower();
    this->setFixedSize(840,626);
    this->statusBar()->setSizeGripEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ExitButton_clicked()
{
  QApplication::exit();
}

void MainWindow::on_StartButton_clicked()
{
    wPlay = new PlayWindow(this);
    wPlay->show();
    this->hide();
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::exit();
}
