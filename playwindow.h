#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H

#include <QMainWindow>

namespace Ui {
class PlayWindow;
}

class PlayWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlayWindow(QWidget *parent = nullptr);
    ~PlayWindow();
    QList<QPixmap> cardHolder;
    int deckValues[52];
    int usedValues[20];

public slots:
    void LoadList();
    void computerTurn();
private slots:
    void on_HitButton_clicked();

    void on_StandButton_clicked();

    void on_PlayAgainButton_clicked();
    void on_actionQuit_triggered();

private:
    Ui::PlayWindow *ui;
};

#endif // PLAYWINDOW_H
