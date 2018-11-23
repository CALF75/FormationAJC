#include <iostream>
#include "maclasseavecstatic.h"
using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    maclasseavecstatic obj;
    obj.method1();
    obj.method2();
    obj.method1();
    obj.method2();
    std::cout <<"i vaut maintenant : "<< maclasseavecstatic::i <<"\n"<<std::endl;
    maclasseavecstatic::method3();
        std::cout <<"i vaut maintenant : "<< maclasseavecstatic::i <<"\n"<<std::endl;
    return 0;
}
