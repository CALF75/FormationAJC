#include <iostream>
#include "fille.h"
#include "mere.h"

using namespace std;

int main()
{

//mere* p1;
mere* p2;
//mere m;
fille f;
//p1=&m;
p2=&f;
cout<<"Appel de la méthode method"<<endl;
//p1->method();
p2->method();


}
