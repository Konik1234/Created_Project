
#ifndef OKNO_H
#define OKNO_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QLCDNumber;
class QLabel;
class QPushButton;
QT_END_NAMESPACE
class plansza;

class okno: public QWidget
{
     Q_OBJECT
public:
    okno(QWidget *parent = nullptr);

private:
    QLabel *createLabel(const QString &text);

    plansza *board;
    QLabel *nextPieceLabel;
    QLCDNumber *scoreLcd;
    QLCDNumber *levelLcd;
    QLCDNumber *linesLcd;
    QPushButton *startButton;
    QPushButton *quitButton;
    QPushButton *pauseButton;
};

#endif // OKNO_H
