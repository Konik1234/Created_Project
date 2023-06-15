
#include "okno.h"
#include "plansza.h"

#include <QCoreApplication>
#include <QGridLayout>
#include <QLabel>
#include <QLCDNumber>
#include <QPushButton>


//okno::okno(QWidget *parent)

okno::okno(QWidget *parent)
    : QWidget(parent), board(new plansza)
{
    //! [0]
    nextPieceLabel = new QLabel;
    nextPieceLabel->setFrameStyle(QFrame::Box | QFrame::Raised);
    nextPieceLabel->setAlignment(Qt::AlignCenter);
    nextPieceLabel->setStyleSheet("background-color: #CCFFFF;");

    board->setNextPieceLabel(nextPieceLabel);
    board->setFixedSize(350, 600);
    board->setStyleSheet("background-color: #333366;");

    //! [1]
    scoreLcd = new QLCDNumber(5);
    scoreLcd->setSegmentStyle(QLCDNumber::Flat);
    scoreLcd->setStyleSheet("background-color: #CCFFFF;");
    //! [1]
    levelLcd = new QLCDNumber(2);
    levelLcd->setSegmentStyle(QLCDNumber::Flat);
    levelLcd->setStyleSheet("background-color: #CCFFFF;");
    linesLcd = new QLCDNumber(5);
    linesLcd->setSegmentStyle(QLCDNumber::Flat);
    linesLcd->setStyleSheet("background-color: #CCFFFF;");

    //! [2]
    startButton = new QPushButton(tr("&Graj"));
    startButton->setFocusPolicy(Qt::NoFocus);
    startButton->setStyleSheet("background-color: #66FF99;");

    quitButton = new QPushButton(tr("&Wyjdź"));
    quitButton->setFocusPolicy(Qt::NoFocus);
    quitButton->setStyleSheet("background-color: #FF6699;");
    pauseButton = new QPushButton(tr("&Pauza"));
    pauseButton->setFocusPolicy(Qt::NoFocus);
    pauseButton->setStyleSheet("background-color: #FFFF99;");
    //! [3] //! [4]

    connect(startButton, &QPushButton::clicked, board, &plansza::start);
    //! [4] //! [5]
    connect(quitButton , &QPushButton::clicked, qApp, &QCoreApplication::quit);
    connect(pauseButton, &QPushButton::clicked, board, &plansza::pause);
    connect(board, &plansza::scoreChanged,
            scoreLcd, qOverload<int>(&QLCDNumber::display));
    connect(board, &plansza::levelChanged,
            levelLcd, qOverload<int>(&QLCDNumber::display));
    connect(board, &plansza::linesRemovedChanged,
            linesLcd, qOverload<int>(&QLCDNumber::display));
    //! [5]

    //! [6]
    QGridLayout *layout = new QGridLayout;


    layout->addWidget(nextPieceLabel, 1, 0);
    layout->addWidget(createLabel(tr("LEVEL")), 2, 0);
    layout->addWidget(levelLcd, 3, 0);
    layout->addWidget(startButton, 8, 1);
    layout->addWidget(board, 0, 1, 6, 1);
    layout->addWidget(createLabel(tr("WYNIK")), 0, 2);
    layout->addWidget(scoreLcd, 1, 2);
    layout->addWidget(createLabel(tr("LINIA")), 4, 0);
    layout->addWidget(linesLcd, 5, 0);
    layout->addWidget(quitButton, 6, 1);
    layout->addWidget(pauseButton, 7, 1);
    setLayout(layout);

    setStyleSheet("background-color: #BBBBBB;");
    setWindowTitle(tr("Tetrix"));
    resize(800, 600);
}
//! [6]

//! [7]
QLabel *okno
    ::createLabel(const QString &text)
{
    QLabel *label = new QLabel(text);
    label->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    return label;
}
//! [7]
