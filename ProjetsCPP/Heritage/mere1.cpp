#include <iostream>
#include "mere1.h"

Mere1::Mere1()
{
        std::cout<<"Appel du constructeur de la mère1"<<std::endl;
}

Mere1::~Mere1()
{
        std::cout<<"Appel du destructeur de la mère1"<<std::endl;
}

void Mere1::age()
{
    std::cout<<"appel de la fonction age chez la mere"<<std::endl;
}
