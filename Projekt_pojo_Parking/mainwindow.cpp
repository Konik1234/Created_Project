#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QFile>
#include <QStandardPaths>
#include <QMessageBox>

float cenna=0;
QTimer timer1;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFile file(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"\\dane.txt");

    if(!file.open(QIODevice::ReadWrite))
  {
        QMessageBox::information(0,"error",file.errorString());
  }

    QTextStream in(&file);
  while(!in.atEnd())
    {
        QListWidgetItem* item = new QListWidgetItem(in.readLine(),ui->listWidget);
         ui->listWidget->addItem(item);
    }

  file.close();
}

MainWindow::~MainWindow()
{
    delete ui;

  QFile file(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"\\dane.txt");

  if(!file.open(QIODevice::ReadWrite))
  {
         QMessageBox::information(0,"error",file.errorString());
  }

  QTextStream out(&file);

  for(int i=0;i <ui->listWidget->count();++i)
  {
         out<<ui->listWidget->item(i)->text()<<"\n";
  }

  file.close();
}

void MainWindow::on_pushButtonDodaj_clicked()
{
  QListWidgetItem* item= new QListWidgetItem(ui->lineEditRejestracja->text(),ui->listWidget);
    QString rejestracja = ui->lineEditRejestracja->text();
    std::string rejestracjaStd = rejestracja.toStdString();






    ui->listWidget->addItem(item);

    item->setFlags(item->flags()| Qt::ItemIsEditable);
    samochod.dodajRejestracje(rejestracjaStd);
    ui->lineEditRejestracja->clear();
    ui->lineEditRejestracja->setFocus();




    QAbstractButton::connect(&timer1,&QTimer::timeout,[&](){
        cenna=cenna+0.5;
        ui->label_2->setText(QString::number(cenna)+ " zł");

    });
    timer1.start(1000);
}

void Samochod::dodajRejestracje(const std::string& rejestracja)
{
    this->rejestracja = rejestracja;
    baza.push_back(rejestracja);
}

void MainWindow::on_pushButton_clicked()
{
    int p=cenna;
    QListWidgetItem* item = ui->listWidget->takeItem(ui->listWidget->currentRow());
    delete item;
    ui->label_3->setText("Zapłacono "+QString::number(p)+" zł"+ "  Brama Otwarta");
    ui->label_2->clear();
    ui->label_2->deleteLater();
}

