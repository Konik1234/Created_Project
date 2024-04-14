#include <iostream>
#include "Funkcje.h"
#include <windows.h>

using namespace std;


void Menu()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
    cout<<endl;
   cout<<"-----------------------------------------------------------------------------------"<<endl;
   cout<<endl;
     cout<<"\t ************************"<<endl;
    cout<<"\t      Witaj w menu"<<endl;
    cout<<"\t ************************"<<endl;
    cout<<"\t |1. Stworz nowa postac"<<endl;
     cout<<"\t |2. Wczytaj postac"<<endl;
      cout<<"\t |3. Graj"<<endl;
       cout<<"\t |4. Wyjdz z programu"<<endl;
       cout<<"\t |5. Zapisz osiagniecia"<<endl;
    cout<<endl;
   cout<<"-----------------------------------------------------------------------------------"<<endl;
   cout<<endl;
}
