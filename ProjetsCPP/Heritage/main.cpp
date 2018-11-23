#include <iostream>
#include "fille.h"
#include "mere1.h"

using namespace std;

int main()
{
    cout << "Appel mère1" << endl;
    Mere1 maman;
    cout << "Appel fille" << endl;
    FIlle fifille;

    cout << "Appel age mère1" << endl;
    maman.age();
    cout << "Appel âge fille" << endl;
    fifille.age();
    ((Mere1) fifille).age();


    return 0;
}
