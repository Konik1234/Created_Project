#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <vector>
#include <fstream>
#include <windows.h>
#include "Funkcje.h"


using namespace std;


class Enemy;


class Bohater
{


public:

    vector<string> imiona={};
    struct Character
    {
        string name;
        int strength;
        int speed;
        int agility;
        int experience;
        int level;
        int win;
        int draw;
        int lose;


    };

   Character character;




   string  createnewCharacter(int punkty,vector<string> & wektor)
{
    string imie;
      int zmienna;
    ofstream wejsce("wczytaj.txt", ios::app);
    ifstream wej("wczytaj.txt");

    Pasek();
    cout<<"Wprowadz nazwe twojego bohatera: "<<endl;
    Pasek();
    cin>>character.name;
    Pasek();
    do
    {
        for(auto it=wektor.begin();it !=wektor.end();++it)
        {
            if(character.name == *it)
            {
                cout<<"Wprowazone imie juz istnieje"<<endl;
                cout<<"Prosze wprowadzic nowe imie:"<<endl;
                Pasek();
                cin>>character.name;
                Pasek();
            }
        }
         while(wej>>imie)
    {

        if(imie==character.name)
        {
            Pasek();
            cout<<"Wprowazone imie juz istnieje  w bibliotece"<<endl;
            cout<<"Prosze wprowadzic nowe imie:"<<endl;
                Pasek();
                cin>>character.name;
                Pasek();





        break;

        }
    }

    }while(0);
    wej.close();


    cout<<"Posiadasz "<<punkty<<" punktow umiejetnosci do wykozystania w 3 umiejetnosci"<<endl;
    Pasek();
  do{
        zmienna=punkty;
    cout<<"Podaj wartosc atrybutu sily: "<<endl;
    cin>>character.strength;
    zmienna-=character.strength;

    cout<<"Podaj wartosc atrybutu szybkosci:"<<endl;
    cin>>character.speed;
   zmienna-=character.speed;

     cout<<"Podaj wartosc atrybutu zwinnosci:"<<endl;
    cin>>character.agility;
    zmienna-=character.agility;
    cout<<endl;

     character.level=1;
     character.experience=0;
     character.win=0;
     character.draw=0;
     character.lose=0;

    if(zmienna<0)
    {   system("cls");
        Pasek();
        cout<<"Przekroczyles ilosc punktow do wykorzystania ,Wprowadz je jeszcze raz"<<endl;
         Pasek();

    }
     }while(zmienna<0);


     wejsce<<endl<<endl<<character.name<<endl<<character.strength<<endl<<character.speed<<endl<<character.agility<<endl<<character.level<<endl<<character.experience<<endl<<character.win<<endl<<character.draw<<endl<<character.lose<<endl;
    wejsce.close();
    return character.name;
}


  void pokaz()
 {

     Gwiazda();
     cout<<" \t  Postac:"<<endl;
     Gwiazda();

     Pasek();
      cout << "Imie: " << character.name << endl;
    cout << "Sila: " << character.strength << endl;
    cout << "Szybkosc: " << character.speed << endl;
    cout << "Zwinnosc: " << character.agility << endl;
     cout << "Poziom: " << character.level <<" lvl" <<endl;
      cout << "Doswiadczenie: " << character.experience <<" pkt"<< endl;

    Pasek();

 }
 string loadCharacter()
 {
     string test;
     Pasek();
     cout<<"Wprowadz imie bohatera do zaladowania"<<test<<endl;
     Pasek();
     cin>>test;


     string name;
        int strength;
        int speed;
        int agility;
        int level;
        int experience;
        int win;
        int draw;
        int lose;

   ifstream wej("wczytaj.txt");




    while(wej>>name>>strength>>speed>>agility>>level>>experience>>win>>draw>>lose)
    {

        if(name==test)
        {
            Pasek();
            cout<<"Znaleziono Bohatera o podanym imieniu ->Laduje Bohatera do gry:"<<endl;
            Pasek();
            character.name=name;
            character.strength=strength;
           character.speed=speed;
            character.agility=agility;
            character.experience=experience;
            character.level=level;
            character.win=win;
            character.draw=draw;
            character.lose=lose;

            return character.name;

        break;

        }
    }

    if(character.name!=test)
    {
        Pasek();
        cout<<"nie znalezono w bazie takiego bohatera"<<endl;
        Pasek();
    }
    wej.close();


  }

  void poziomy()
  {
           int ilosc=30;
          int s;
          int ss;
          int a;

      if(character.experience>=(10*character.level))
      {

          Gwiazda();
          cout<<"Uzyskales "<<character.level+1<<" poziom!!!";
          Gwiazda();
          character.level++;
          cout<<"Otrzymujesz 30pkt uiejetnocy do wykozystania ";

          Pasek();
          do{
             ilosc=30;

    cout<<"Podaj wartosc atrybutu sily: "<<endl;
    cin>>s;
    ilosc-=s;


    cout<<"Podaj wartosc atrybutu szybkosci:"<<endl;
    cin>>ss;
    ilosc-=ss;


     cout<<"Podaj wartosc atrybutu zwinnosci:"<<endl;
    cin>>a;
    ilosc-=a;

    cout<<endl;

       if(ilosc<0)
       {
           system("cls");
           cout<<"Wykorzystales za duzo punktow!!!, rozdysponuj punkty jeszcze raz"<<endl;
       }
          }while(ilosc<0);
         character.strength+=s;
         character.speed+=ss;
         character.agility+=a;

      }
  }
  void edytuj()
  {
       string plikWejsciowy = "wczytaj.txt";
    string plikTymczasowy = "chwilowy.txt";

    ifstream wejscie(plikWejsciowy);
    ofstream tymczasowy(plikTymczasowy);

      if(wejscie.is_open() && tymczasowy.is_open())
      {
          string linia;
          bool znaleziono =false;



          while(getline(wejscie, linia))
          {
              if(linia.find(character.name)!=string::npos)
              {
                  znaleziono=true;

                   tymczasowy<<character.name<<endl<<character.strength<<endl<<character.speed<<endl<<character.agility<<endl<<character.level<<endl<<character.experience<<endl<<character.win<<endl<<character.draw<<endl<<character.lose<<endl;
                   cout << "Dane zostaly zaktualizowane." <<endl;

              }
              else
                {
                tymczasowy << linia << endl;
                }
          }
           if (!znaleziono) {
            cout << "Nie znaleziono danych dla osoby o imieniu: " << character.name << endl;
        }

         wejscie.close();
        tymczasowy.close();

        remove(plikWejsciowy.c_str());
        rename(plikTymczasowy.c_str(), plikWejsciowy.c_str());
    }
    else {
        cout << "Nie można otworzyć pliku do odczytu/zapisu." << endl;

      }
  }


};

void Wybiez(int a,Bohater tab[100]);

class Enemy:public Bohater
{
public:
float obrazenia;
float obrazenia1;

    void generateEnemy(int punkty1)
    {

         string nazwy[]={"Smok","Ork","Goblin","Nija","Wiedzma","Rusalka"};
       int wielkos=sizeof(nazwy)/sizeof(nazwy[0]);



       character.name=nazwy[rand()%wielkos];
       character.strength=rand()%punkty1+1;
      character.speed=rand()%punkty1+1;
       character.agility=rand()%punkty1+1;
       character.level=rand()%5+1;
       if(character.level==1)
       {
           character.experience=rand()%9;
       }
       else
        {
            character.experience=rand()%10+((character.level-1)*10);

        }

    }

    bool ucieczka(Bohater a)
  {
      return(a.character.speed>2*character.speed);
  }

  float atak_b(Bohater a)
  {
       int krytyk=rand()%5+1;
      if(krytyk==1||krytyk==3)
      {
          obrazenia=(a.character.strength+a.character.agility+a.character.level+(a.character.experience/10))*2;
          cout<<a.character.name<<" zada w walce obrazenia krytyczne"<<endl;
           cout<<endl;
      }
      else
        {
              obrazenia=a.character.strength+a.character.agility+a.character.level+(a.character.experience/10);
        }

      return obrazenia;
  }
  float atak_e()
  {

      int krytyk=rand()%5+1;

      if(krytyk==2||krytyk==4)
      {
           obrazenia1=(character.strength+character.agility+character.level+(character.experience/10))*2;
          cout<<character.name<<" zada w walce obrazenia krytyczne"<<endl;
          cout<<endl;
      }
      else
      {
       obrazenia1=character.strength+character.agility+character.level+(character.experience/10);
      }

      return obrazenia1;
  }

    Bohater Fight(Bohater a)
  {


      int p_d=rand()%25%+10;
      int wynik_b=0;
      int wynik_m=0;
    Gwiazda();
    cout<<"\t   !!!walka!!!! "<<endl<<"\t"<<a.character.name<<" Vs "<<character.name<<endl;
    Gwiazda();


    if(ucieczka(a))
    {   Pasek();
        cout<<a.character.name<< " Pokonal wroga bez walki"<<endl;
        cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
        cout<<"Zdobywasz  doswiadczenie:"<<p_d<<" pkt"<<endl;
        Pasek();
       a.character.experience+=p_d;
       a.character.win+=1;

    }
    else
    {
         float obr_b=atak_b(a);
      float obr_e=atak_e();

     if(obr_b>obr_e)// Siła
    {
      wynik_b++;
      Pasek();
      cout<<a.character.name<<" zadaje "<<obr_b<<"pkt obrazenia!!!"<<endl;
      Gwiazda();
      cout<<character.name<<" zadaje "<<obr_e<<"pkt obrazenia!!!"<<endl;
      Pasek();

    }
    else if(obr_b<obr_e)
    {
        wynik_m++;
        Pasek();
        cout<<a.character.name<<" zadaje "<<obr_b<<"pkt obrazenia!!!"<<endl;
        Gwiazda();
      cout<<character.name<<" zadaje "<<obr_e<<"pkt obrazenia!!!"<<endl;
      Pasek();
    }


   //Ostateczne porównanie
   if(wynik_b>wynik_m)
   {
       Gwiazda();
       cout<<"Wygrywa "<<a.character.name<<endl;
       Gwiazda();
       cout<<"Zdobywasz  doswiadczenie:"<<p_d<<" pkt"<<endl;
       a.character.experience+=p_d;
       a.character.win+=1;

   }
   else if(wynik_b<wynik_m)
   {
       Gwiazda();
       cout<<"Wygrywa "<<character.name<<"!!!"<<endl;
       Gwiazda();
       cout<<endl;
       a.character.lose+=1;
   }
   else if(wynik_b==wynik_m)
    {
        cout<<"Remis!!!";
        a.character.draw+=1;
    }
    }
    return a;
  }


};



int main()
{
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);

    srand(time(nullptr));
     vector<string> imiona={};
    int punkty=100;
    int punkty1=50;
    Bohater tab[100];
    Enemy tab1[100];
     int start=1;
       int b=1;
     int pomocnicza=0;
   char opcja;
   int wybor;
   int l_bohatera;





   while(start)
   {

        Menu();
       cin>>wybor;

       switch(wybor)
       {
       case 1:
           system("cls");
           SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
           imiona.push_back(tab[pomocnicza].createnewCharacter(punkty,imiona));
           system("cls");
           tab[pomocnicza].pokaz();
           Kontynuluj();
           pomocnicza++;
           system("cls");

        break;

       case 2:
           system("cls");
           SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
           imiona.push_back(tab[pomocnicza].loadCharacter());
           if(tab[pomocnicza].character.name!="")
           {
               tab[pomocnicza].pokaz();
           }
             Kontynuluj();
           pomocnicza++;
            system("cls");


        break;

       case 3:


            char opcja1;
            b=1;


           while(b)
           {
           system("cls");
           SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
           Wybiez(pomocnicza,tab);
           cin>>l_bohatera;
           cout<<endl;
           system("cls");
           Pasek();
           cout<<"\t Twoii przeciwnicy"<<endl;
           Pasek();
           for(int i=0;i<3;i++)
           {
               tab1[i].generateEnemy(punkty1);
               tab1[i].pokaz();
           }

           Kontynuluj();
           system("cls");

           for(int i=0;i<3;i++)
           {
               tab[l_bohatera]=tab1[i].Fight(tab[l_bohatera]);
               Kontynuluj();
               system("cls");
           }
           tab[l_bohatera].poziomy();
           tab[l_bohatera].pokaz();
           Kontynuluj();
           system("cls");

           Pasek();
       cout<<"\t Czy chcesz kontynuowac Walki? "<<endl;
       cout<<"\t         NIE(n) TAK(t)"<<endl;
       Pasek();

       cin>>opcja1;

        if(opcja1=='n')
        {
       b=0;
        }
        else
        {
            b=1;
        }

        system("cls");

           }
        break;

       case 4:
        system("cls");
        Pasek();
       cout<<"\t Czy napewno chcesz opuscic GRE? "<<endl;
       cout<<"\t         NIE(n) TAK(t)"<<endl;
       Pasek();

       cin>>opcja;

        if(opcja=='n')
        {
       start=1;
        }
        else
        {
       start=0;
        }
        system("cls");
        break;

       default:
           system("cls");
           cout<<"Wybrales nie poprawna opcje"<<endl;
           Kontynuluj();
           system("cls");

        break;

       case 5:
           system("cls");
           Wybiez(pomocnicza,tab);
           cin>>l_bohatera;
           tab[l_bohatera].edytuj();
           Kontynuluj();
           system("cls");

        break;
       }
   }
    return 0;
}


void Wybiez(int a,Bohater tab[100])
{

    Pasek();
    cout<<"\t   Wybierz Bohatera "<<endl;
    Pasek();

    for(int i=0;i<a;i++)
    {
        cout<<i<<"\t "<<tab[i].character.name<<endl;
    }
    Pasek();


}



