#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;
class Enemy;

class Bohater
{
public:
    struct Character
    {
        string name;
        int strength;
        int speed;
        int agility;
    };

   Character character;

    void  createCharacter(int punkty)
{
    cout<<"Wprowadz nazwe twojego bohatera: "<<endl;
    cin>>character.name;

    cout<<"Posiadasz "<<punkty<<" punktow umiejetnosci do wykozystania w 3 umiejetnosci"<<endl;
    cout<<endl;

    cout<<"Podaj wartosc atrybutu sily: "<<endl;
    cin>>character.strength;
    punkty-=character.strength;

    cout<<"Podaj wartosc atrybutu szybkosci:"<<endl;
    cin>>character.speed;
    punkty-=character.speed;

     cout<<"Podaj wartosc atrybutu zwinnosci:"<<endl;
    cin>>character.agility;
    punkty-=character.agility;

    if(punkty<0)
    {
        cout<<"Przekroczyles ilosc punktow do wykorzystania ,Wszystkie atrybuty zostaly wyzerowane"<<endl;
        character.strength=0;
        character.speed=0;
        character.agility=0;
    }
}


  void pokaz()
 {
      cout << "Postac: " << character.name << endl;
    cout << "Sila: " << character.strength << endl;
    cout << "Szybkosc: " << character.speed << endl;
    cout << "Zwinnosc: " << character.agility << endl;

 }


};

class Enemy:public Bohater
{
public:

    void generateEnemy(int punkty1)
    {
         string nazwy[]={"Smok","Ork","Goblin","Nija","Wiedzma","Rusalka"};
       int wielkos=sizeof(nazwy)/sizeof(nazwy[0]);

       srand(time(nullptr));

       character.name=nazwy[rand()%wielkos];
       character.strength=rand()%punkty1+1;
      character.speed=rand()%punkty1+1;
       character.agility=rand()%punkty1+1;
    }
};
void Fight(Bohater a,Enemy b);

int main()
{

    srand( time( NULL ) );

    int punkty=100;
    int punkty1=50;
    Bohater a;
    Enemy b;
     int start=1;
   char opcja;

   while(start)
   {

    a.createCharacter(punkty);
    cout<<endl;
    a.pokaz();
    cout<<endl;
    b.generateEnemy(punkty1);
    cout<<endl;
    b.pokaz();
    cout<<endl;
    Fight(a,b);
    cout<<endl;

    cout<<"Jesli chcesz zagrac jeszcze raz klinij t jesli nie kliknij co kolwiek innego"<<endl;
   cin>>opcja;


     if(opcja=='t')
   {
       start=1;
   }
   else
   {
       start=0;
   }

   }




    return 0;
}


void Fight(Bohater a,Enemy b)
  {
      int wynik_b=0;
      int wynik_m=0;

    cout<<"Walka!!!! "<<a.character.name<<" Vs "<<b.character.name<<endl;
    cout<<endl;

    if(a.character.strength>b.character.strength)// Siła
    {
      wynik_b++;

    }
    else if(a.character.strength<b.character.strength)
    {
        wynik_m++;
    }
    if(a.character.speed>b.character.speed)//Szybkość
    {
      wynik_b++;

    }
    else if(a.character.speed<b.character.speed)
    {
        wynik_m++;
    }
    if(a.character.agility>b.character.agility)//Zwiność
    {
      wynik_b++;

    }
    else if(a.character.agility<b.character.agility)
    {
        wynik_m++;
    }
   //Ostateczne porównanie
   if(wynik_b>wynik_m)
   {
       cout<<"Wygrywa "<<a.character.name<<"!!!"<<endl;
   }
   else if(wynik_b<wynik_m)
   {
       cout<<"Wygrywa "<<b.character.name<<"!!!"<<endl;
   }
   else
    {
        cout<<"Remis!!!";
    }
  }

