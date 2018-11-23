#include <iostream>
#include "heure.h"
using namespace std;

int main()
{

    heure heure1(15,36,52);
    heure heure2(1,36,9);
    heure1.affiche();
    heure2.affiche();
    heure heure3;
    heure3 = heure1+heure2;
    heure3.affiche();

    heure heure4;
    heure4 = heure2+heure1;
    heure4.affiche();

    return 0;
}
