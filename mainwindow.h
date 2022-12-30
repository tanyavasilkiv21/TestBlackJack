#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "playwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ExitButton_clicked();
    void on_StartButton_clicked();
    void on_actionQuit_triggered();

private:
    Ui::MainWindow *ui;
    PlayWindow *wPlay;
};
#endif // MAINWINDOW_H
