#include <iostream>
#include "maclasse.h"
using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    MaClasse var;
    var.membre=100;
    var.AfficheMembre();
    var.AfficheContenuPointeur();

        std::cout << "Suite exercice=====\n"<< std::endl;
    MaClasse var2 = MaClasse(var);
    var2.AfficheMembre();
    var2.AfficheContenuPointeur();
    var2.membre=130;
    var2.AfficheMembre();
    var2.AfficheContenuPointeur();

    return 0;
}
