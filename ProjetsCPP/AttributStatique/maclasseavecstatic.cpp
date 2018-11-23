#include "maclasseavecstatic.h"
#include <iostream>

   int maclasseavecstatic::i=0;
maclasseavecstatic::maclasseavecstatic()
{

}

void maclasseavecstatic::method1()
{
    i++;
    std::cout <<"i a été incrémenté avec la méthode 1 et vaut : "<<i<<std::endl;
}

void maclasseavecstatic::method2()
{
    maclasseavecstatic::i=maclasseavecstatic::i+1;
    std::cout <<"i a été incrémenté avec la méthode 2 et vaut : "<<i<<std::endl;
}

void maclasseavecstatic::method3()
{
        maclasseavecstatic::i=maclasseavecstatic::i+5;
}
