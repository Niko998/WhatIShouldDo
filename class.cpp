#include <iostream>
#include "class.h"


using namespace std;

Tasks::Tasks()
{

}

void Tasks::wpisywanie()
{
    cout << "Wpisz nowy pomysl: ";
    cin.sync();
    getline(cin, task);
}

void Tasks::wypisywanie()
{
    cout << task << endl;
}

void Tasks::dopisywanie(string a)
{
    task=a;
}
