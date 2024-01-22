#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <string>

namespace Ui {
class MainWindow;
}

class Samochod
{
public:
    void dodajRejestracje(const std::string& rejestracja);

private:
    std::string rejestracja;
    std::vector<std::string> baza;

    friend class MainWindow;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonDodaj_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Samochod samochod;
};

#endif // MAINWINDOW_H
