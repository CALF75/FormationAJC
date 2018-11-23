#include "fille.h"
#include "mere1.h"
#include <iostream>
FIlle::FIlle() {

      std::cout<<"Appel du constructeur de la fille"<<std::endl;
}
FIlle::~FIlle() {

      std::cout<<"Appel du destructeur de la fille"<<std::endl;
}

void FIlle::age()
{
    std::cout<<"appel de la fonction age chez la FILLE"<<std::endl;
    Mere1::age();
}

