#include "maclasse.h"
#include <iostream>
MaClasse::MaClasse(){
    pm=&membre;
}

MaClasse::MaClasse(const MaClasse &a)
{
    membre=a.membre;
 //erreur volontaire
  //  pm=a.pm;
    pm=&membre;
}


void MaClasse::AfficheMembre() {

    std::cout << "Le membre vaut : \n"<<membre<< std::endl;
}
void MaClasse::AfficheContenuPointeur() {

    std::cout << "La valeur du pointeur est : \n"<<pm<< std::endl;
    std::cout << "La valeur vers laquelle pointe le pointeur est : \n"<<*pm<< std::endl;
}
