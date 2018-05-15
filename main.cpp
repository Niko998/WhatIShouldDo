#include <iostream>
#include "class.h"
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <vector>

using namespace std;
//Do zrobienia:
//1. dodac usuwanie
//2. Poprawic, zeby dodany pomysl nie wyswietlal sie jako wylosowany


void Od_nowa();
void Kontynuowac();

int main()
{
    //intro
    srand(time(NULL));
    int choose;

    cout << "Co chcesz zrobic?" << endl << "1.Zaczac od nowa" <<endl << "2.Kontynuowac" << endl << "-+-+-+-+-+-+-+-+-+-+-+-+-+-" << endl << "Wpisz 1 lub 2: ";
    cin >> choose;
    switch (choose)
    {
    case 1:  Od_nowa(); break;
    case 2: system("cls"); Kontynuowac(); break;
    }
    return 0;
}
//new work
void Od_nowa()
{
    fstream task1;

    vector <Tasks> Tablica;
    int choose=15, wybor=-1;
    static int i = 0;
    while(1)
    {
        if (wybor<0){
        system("cls");
        cout << "Pomysly: " << endl;}
        else cout <<endl<< "Pozostale pomysly: " << endl;
        Tasks * a = new Tasks;
        Tablica.push_back(*a);
        for (int j=0; j<i;j++)
                    {
                        cout << j+1 << ". ";
                        Tablica[j].wypisywanie();
                    }
        cout <<endl << endl<< "Co chcesz zrobic?" << endl << "1.Dodac nowy pomysl" << endl << "2.Wylosowac" << endl << "3.Zamknac program" << endl << "-+-+-+-+-+-+-+-+-+-+-+-+-+-" << endl << "Wpisz 1 lub 2: ";
        cin >> choose;
        switch (choose)
        {
            //dodawanie nowego zadania i zapisywanie go do pliku
        case 1: system("cls");  Tablica[i].wpisywanie(); i++; break;
        // wypisywanie zadania
        case 2: system("cls"); wybor = rand()%i; cout << "Wylosowany pomysl do zrobienia to: "; Tablica[wybor].wypisywanie(); Tablica.erase(Tablica.begin()+wybor); i--;
                    break;
        case 3: goto wyjscie1;

        }
        }
        wyjscie1:
        task1.open("TODO.txt",ios::out);
        for (int j=0;j<Tablica.size();j++)
        {
            task1 << Tablica[j].task << endl;
        }
        task1.close();
}
//continue work
void Kontynuowac()
{
    fstream task1;
    int i=0, choose, wybor=-1;
    string bufor;
    vector <Tasks> Tablica;
    task1.open("TODO.txt",ios::in);
//wczytywanie z pliku
    Tasks * a=new Tasks;
    while (getline(task1,a->task))
    {
        Tablica.push_back(*a);
        i++;
    }
//wypisywanie
    while (1){
        if (wybor<0){
        system("cls");
        cout << "Pomysly: " << endl;}
        else cout <<endl<< "Pozostale pomysly: " << endl;
        int k=1;
        for (int j=0;j<Tablica.size()-1;j++)
            {
            cout << k++ << ". ";
            Tablica[j].wypisywanie();
            }
        cout <<endl << endl<< "Co chcesz zrobic?" << endl << "1.Dodac nowy pomysl" << endl << "2.Wylosowac" << endl << "3.Zamknac program" << endl << "-+-+-+-+-+-+-+-+-+-+-+-+-+-" << endl << "Wpisz 1 lub 2: ";
        cin >> choose;
        switch (choose)
        {
            //dodawanie nowego zadania i zapisywanie go do pliku
            case 1: {system("cls");  Tasks *a = new Tasks; Tablica.push_back(*a); Tablica[i].wpisywanie();  i++; break;}
        // wypisywanie zadania
            case 2: {system("cls"); wybor = rand()%Tablica.size(); cout << "Wylosowany pomysl do zrobienia to: "; Tablica[wybor].wypisywanie();  Tablica.erase(Tablica.begin()+wybor); i--; break;}
            case 3: goto wyjscie2;
        }
        }
        task1.close();
        wyjscie2:
        task1.open("TODO.txt",ios::out);
        for (int j=0;j<Tablica.size();j++)
        {
            task1 << Tablica[j].task << endl;
        }
        task1.close();
}

