#include "playwindow.h"
#include "ui_playwindow.h"
#include <QApplication>

PlayWindow::PlayWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlayWindow)
{
    ui->setupUi(this);
    QPixmap pix("D:/Qt_study/TestStudy/TestBlack/images/blackjack_table.png");
    ui->PictureLabel->setPixmap(pix);
    ui->PictureLabel->lower();
    this->setFixedSize(800,500);

    ui->PlayAgainButton->setVisible(false);
}

static int player_score = 0;
static int computer_score = 0;
static int computer_score_ing = 0;
int holdingCardCount = 1;
int holdingCardCountComputer = 1;
int counterNumbers = 0;
int usedValues[20] = {0};
int saveCompFirst = 0;


void PlayWindow::LoadList(){
    cardHolder.clear();
    // Load in Spades
    QPixmap card1("D:/Qt_study/TestStudy/TestBlack/images/cards/ace_of_spades.png");
    QPixmap card2("D:/Qt_study/TestStudy/TestBlack/images/cards/2_of_spades.png");
    QPixmap card3("D:/Qt_study/TestStudy/TestBlack/images/cards/3_of_spades.png");
    QPixmap card4("D:/Qt_study/TestStudy/TestBlack/images/cards/4_of_spades.png");
    QPixmap card5("D:/Qt_study/TestStudy/TestBlack/images/cards/5_of_spades.png");
    QPixmap card6("D:/Qt_study/TestStudy/TestBlack/images/cards/6_of_spades.png");
    QPixmap card7("D:/Qt_study/TestStudy/TestBlack/images/cards/7_of_spades.png");
    QPixmap card8("D:/Qt_study/TestStudy/TestBlack/images/cards/8_of_spades.png");
    QPixmap card9("D:/Qt_study/TestStudy/TestBlack/images/cards/9_of_spades.png");
    QPixmap card10("D:/Qt_study/TestStudy/TestBlack/images/cards/10_of_spades.png");
    QPixmap card11("D:/Qt_study/TestStudy/TestBlack/images/cards/jack_of_spades2.png");
    QPixmap card12("D:/Qt_study/TestStudy/TestBlack/images/cards/queen_of_spades2.png");
    QPixmap card13("D:/Qt_study/TestStudy/TestBlack/images/cards/king_of_spades2.png");

    // Load in Hearts
    QPixmap card14("D:/Qt_study/TestStudy/TestBlack/images/cards/ace_of_hearts.png");
    QPixmap card15("D:/Qt_study/TestStudy/TestBlack/images/cards/2_of_hearts.png");
    QPixmap card16("D:/Qt_study/TestStudy/TestBlack/images/cards/3_of_hearts.png");
    QPixmap card17("D:/Qt_study/TestStudy/TestBlack/images/cards/4_of_hearts.png");
    QPixmap card18("D:/Qt_study/TestStudy/TestBlack/images/cards/5_of_hearts.png");;
    QPixmap card19("D:/Qt_study/TestStudy/TestBlack/images/cards/6_of_hearts.png");
    QPixmap card20("D:/Qt_study/TestStudy/TestBlack/images/cards/7_of_hearts.png");
    QPixmap card21("D:/Qt_study/TestStudy/TestBlack/images/cards/8_of_hearts.png");
    QPixmap card22("D:/Qt_study/TestStudy/TestBlack/images/cards/9_of_hearts.png");
    QPixmap card23("D:/Qt_study/TestStudy/TestBlack/images/cards/10_of_hearts.png");
    QPixmap card24("D:/Qt_study/TestStudy/TestBlack/images/cards/jack_of_hearts2.png");
    QPixmap card25("D:/Qt_study/TestStudy/TestBlack/images/cards/queen_of_hearts2.png");
    QPixmap card26("D:/Qt_study/TestStudy/TestBlack/images/cards/king_of_hearts2.png");

    // Load in clubs
    QPixmap card27("D:/Qt_study/TestStudy/TestBlack/images/cards/ace_of_clubs.png");
    QPixmap card28("D:/Qt_study/TestStudy/TestBlack/images/cards/2_of_clubs.png");
    QPixmap card29("D:/Qt_study/TestStudy/TestBlack/images/cards/3_of_clubs.png");
    QPixmap card30("D:/Qt_study/TestStudy/TestBlack/images/cards/4_of_clubs.png");
    QPixmap card31("D:/Qt_study/TestStudy/TestBlack/images/cards/5_of_clubs.png");
    QPixmap card32("D:/Qt_study/TestStudy/TestBlack/images/cards/6_of_clubs.png");
    QPixmap card33("D:/Qt_study/TestStudy/TestBlack/images/cards/7_of_clubs.png");
    QPixmap card34("D:/Qt_study/TestStudy/TestBlack/images/cards/8_of_clubs.png");
    QPixmap card35("D:/Qt_study/TestStudy/TestBlack/images/cards/9_of_clubs.png");
    QPixmap card36("D:/Qt_study/TestStudy/TestBlack/images/cards/10_of_clubs.png");
    QPixmap card37("D:/Qt_study/TestStudy/TestBlack/images/cards/jack_of_clubs2.png");
    QPixmap card38("D:/Qt_study/TestStudy/TestBlack/images/cards/queen_of_clubs2.png");
    QPixmap card39("D:/Qt_study/TestStudy/TestBlack/images/cards/king_of_clubs2.png");

    // Load in diamonds

    QPixmap card40("D:/Qt_study/TestStudy/TestBlack/images/cards/ace_of_diamonds.png");
    QPixmap card41("D:/Qt_study/TestStudy/TestBlack/images/cards/2_of_diamonds.png");
    QPixmap card42("D:/Qt_study/TestStudy/TestBlack/images/cards/3_of_diamonds.png");
    QPixmap card43("D:/Qt_study/TestStudy/TestBlack/images/cards/4_of_diamonds.png");
    QPixmap card44("D:/Qt_study/TestStudy/TestBlack/images/cards/5_of_diamonds.png");
    QPixmap card45("D:/Qt_study/TestStudy/TestBlack/images/cards/6_of_diamonds.png");
    QPixmap card46("D:/Qt_study/TestStudy/TestBlack/images/cards/7_of_diamonds.png");
    QPixmap card47("D:/Qt_study/TestStudy/TestBlack/images/cards/8_of_diamonds.png");
    QPixmap card48("D:/Qt_study/TestStudy/TestBlack/images/cards/9_of_diamonds.png");
    QPixmap card49("D:/Qt_study/TestStudy/TestBlack/images/cards/10_of_diamonds2.png");
    QPixmap card50("D:/Qt_study/TestStudy/TestBlack/images/cards/jack_of_diamonds2.png");
    QPixmap card51("D:/Qt_study/TestStudy/TestBlack/images/cards/queen_of_diamonds2.png");
    QPixmap card52(":D:/Qt_study/TestStudy/TestBlack/images/cards/king_of_diamonds2.png");

    // add Spades to List
    cardHolder.append(card1);
    cardHolder.append(card2);
    cardHolder.append(card3);
    cardHolder.append(card4);
    cardHolder.append(card5);
    cardHolder.append(card6);
    cardHolder.append(card7);
    cardHolder.append(card8);
    cardHolder.append(card9);
    cardHolder.append(card10);
    cardHolder.append(card11);
    cardHolder.append(card12);
    cardHolder.append(card13);

    // add Hearts to List
    cardHolder.append(card14);
    cardHolder.append(card15);
    cardHolder.append(card16);
    cardHolder.append(card17);
    cardHolder.append(card18);
    cardHolder.append(card19);
    cardHolder.append(card20);
    cardHolder.append(card21);
    cardHolder.append(card22);
    cardHolder.append(card23);
    cardHolder.append(card24);
    cardHolder.append(card25);
    cardHolder.append(card26);

    // add clubs to List
    cardHolder.append(card27);
    cardHolder.append(card28);
    cardHolder.append(card29);
    cardHolder.append(card30);
    cardHolder.append(card31);
    cardHolder.append(card32);
    cardHolder.append(card33);
    cardHolder.append(card34);
    cardHolder.append(card35);
    cardHolder.append(card36);
    cardHolder.append(card37);
    cardHolder.append(card38);
    cardHolder.append(card39);

    // add Diamonds to List
    cardHolder.append(card40);
    cardHolder.append(card41);
    cardHolder.append(card42);
    cardHolder.append(card43);
    cardHolder.append(card44);
    cardHolder.append(card45);
    cardHolder.append(card46);
    cardHolder.append(card47);
    cardHolder.append(card48);
    cardHolder.append(card49);
    cardHolder.append(card50);
    cardHolder.append(card51);
    cardHolder.append(card52);
}

PlayWindow::~PlayWindow()
{
    delete ui;
}

void PlayWindow::on_HitButton_clicked()
{
    int deckValues[52] = {1,2,3,4,5,6,7,8,9,10,10,10,10,1,2,3,4,5,6,7,8,9,10,10,10,10,1,2,3,4,5,6,7,8,9,10,10,10,10,1,2,3,4,5,6,7,8,9,10,10,10,10};
    int number = rand() % 52;
    for(int i = 0; i < counterNumbers;){
        if(usedValues[i] == number){
            number = rand() % 52;
        }
        else{
            i++;
        }
    }
    usedValues[counterNumbers] = number;
    ++counterNumbers;
    player_score += deckValues[number];
    ui->PlayerTotalLabel->setText("Your score:" + QString::number(player_score));
    PlayWindow::LoadList();
    switch(holdingCardCount){
        case 1:
            ui->UserFirstCard->setPixmap(cardHolder.at(number));
            break;
        case 2:
            ui->UserSecondCard->setPixmap(cardHolder.at(number));
            break;
        case 3:
            ui->UserThirdCard->setPixmap(cardHolder.at(number));
            break;
        case 4:
            ui->UserFourCard->setPixmap(cardHolder.at(number));
            break;
        case 5:
            ui->UserFiveCard->setPixmap(cardHolder.at(number));
            break;
        case 6:
            ui->UserSixCard->setPixmap(cardHolder.at(number));
            break;
        case 7:
            ui->UserSeventhCard->setPixmap(cardHolder.at(number));
            break;
        case 8:
            ui->UserEightCard->setPixmap(cardHolder.at(number));
            break;
        case 9:
            ui->UserNinethCard->setPixmap(cardHolder.at(number));
            break;
        case 10:
            ui->UserTenthCard->setPixmap(cardHolder.at(number));
            break;

        }

    ++holdingCardCount;
    if(player_score > 21){
        ui->Bust->setText("BUST! ");
        ui->DilerTotalLabel->setText("                        Dealer score:" + QString::number(computer_score));
        ui->DilerFirstCard->setPixmap(cardHolder.at(saveCompFirst));
        ui->HitButton->setEnabled(false);
        ui->PlayAgainButton->setVisible(true);
    }
    if(player_score < 21){
        ui->StandButton->setEnabled(true);
        PlayWindow::computerTurn();
    }
    else if(player_score == 21){
        ui->Result->setText("WIN!");
        ui->DilerTotalLabel->setText("                        Dealer score: " + QString::number(computer_score));
        ui->DilerFirstCard->setPixmap(cardHolder.at(saveCompFirst));
        ui->HitButton->setEnabled(false);
        ui->StandButton->setEnabled(false);
        ui->PlayAgainButton->setVisible(true);
    }
    else{
        ui->StandButton->setEnabled(false);
        ui->PlayAgainButton->setVisible(true);
    }
}
void PlayWindow::computerTurn(){

    int deckValues[52] = {1,2,3,4,5,6,7,8,9,10,10,10,10,1,2,3,4,5,6,7,8,9,10,10,10,10,1,2,3,4,5,6,7,8,9,10,10,10,10,1,2,3,4,5,6,7,8,9,10,10,10,10};
    int number = rand() % 52;
    for(int i = 0; i < counterNumbers;){
        if(usedValues[i] == number){
            number = rand() % 52;
        }
        else{
            i++;
        }
    }
    usedValues[counterNumbers] = number;
    ++counterNumbers;
    computer_score += deckValues[number];
    if(holdingCardCountComputer > 1){
        computer_score_ing += deckValues[number];
        QString n = QString::number(computer_score_ing);
        ui->DilerTotalLabel->setText("                        Dealer score: ? + " + n);
    }
    else{
        saveCompFirst = number;
    }
    PlayWindow::LoadList();
    QPixmap FCard("D:/Qt_study/TestStudy/TestBlack/images/cards/top.png");
    switch(holdingCardCountComputer){
        case 1:
            ui->DilerFirstCard->setPixmap(FCard);
            break;
        case 2:
            ui->DilerSecondCard->setPixmap(cardHolder.at(number));
            break;
        case 3:
            ui->DilerThirdCard->setPixmap(cardHolder.at(number));
            break;
        case 4:
            ui->DilerFourthCard->setPixmap(cardHolder.at(number));
            break;
        case 5:
            ui->DilerFivethCard->setPixmap(cardHolder.at(number));
            break;
        case 6:
            ui->DilerSixthCard->setPixmap(cardHolder.at(number));
            break;
        case 7:
            ui->DilerSeventhCard->setPixmap(cardHolder.at(number));
            break;
        case 8:
            ui->DilerEightCard->setPixmap(cardHolder.at(number));
            break;
        case 9:
            ui->DilerNinethCard->setPixmap(cardHolder.at(number));
            break;
        case 10:
            ui->DilerTenthCard->setPixmap(cardHolder.at(number));
            break;
    }
    ++holdingCardCountComputer;
}


void PlayWindow::on_StandButton_clicked()
{
    if(player_score < computer_score){
        ui->Result->setText("WIN! ");
        ui->DilerTotalLabel->setText("                        Dealer score:" + QString::number(computer_score));
        ui->DilerFirstCard->setPixmap(cardHolder.at(saveCompFirst));
    }
    else if(player_score == computer_score){
        ui->Result->setText("DRAW! ");
        ui->DilerTotalLabel->setText("                        Dealer score: " + QString::number(computer_score));
        ui->DilerFirstCard->setPixmap(cardHolder.at(saveCompFirst));
    }
    else{
        ui->Result->setText("LOSE! :( ");
        ui->DilerTotalLabel->setText("                        Dealer score:  " + QString::number(computer_score));
        ui->DilerFirstCard->setPixmap(cardHolder.at(saveCompFirst));
    }
    ui->HitButton->setEnabled(false);
    ui->StandButton->setEnabled(false);
    ui->PlayAgainButton->setVisible(true);
}


void PlayWindow::on_PlayAgainButton_clicked()
{
    player_score = 0;
    computer_score = 0;
    computer_score_ing = 0;
    holdingCardCount = 1;
    holdingCardCountComputer = 1;
    counterNumbers = 0;
    ui->PlayerTotalLabel->setText("Your score: 0");
    ui->DilerTotalLabel->setText("                        Dealer score:  ?");

    ui->Bust->clear();
    ui->Result->clear();

    ui->UserFirstCard->clear();
    ui->UserSecondCard->clear();
    ui->UserThirdCard->clear();
    ui->UserFourCard->clear();
    ui->UserFiveCard->clear();
    ui->UserSixCard->clear();
    ui->UserSeventhCard->clear();
    ui->UserEightCard->clear();
    ui->UserNinethCard->clear();
    ui->UserTenthCard->clear();

    ui->DilerFirstCard->clear();
    ui->DilerSecondCard->clear();
    ui->DilerThirdCard->clear();
    ui->DilerFourthCard->clear();
    ui->DilerFivethCard->clear();
    ui->DilerSixthCard->clear();
    ui->DilerSeventhCard->clear();
    ui->DilerEightCard->clear();
    ui->DilerNinethCard->clear();
    ui->DilerTenthCard->clear();

    ui->HitButton->setEnabled(true);
    ui->StandButton->setEnabled(false);
    ui->PlayAgainButton->setVisible(false);

}

void PlayWindow::on_actionQuit_triggered()
{
    QApplication::exec();
}
