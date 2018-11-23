#include "heure.h"
#include <iostream>

heure::heure(){}

heure::heure(int a, int b, int c)
{
    h=a;
    m=b;
    s=c;

}

heure heure::operator+(heure heu){
heure resultat(resultat.h=h+heu.h+(m+heu.m +(s+heu.s)/60)/60,resultat.m=(m+heu.m +(s+heu.s)/60)%60,resultat.s=(s+heu.s)%60);

return resultat;
}
void heure::affiche()
{

    std::cout <<"L'heure vaut : "<<h<<" heure(s) et "<<m<<" minute(s) et "<<s<<" seconde(s)."<< std::endl;
}
