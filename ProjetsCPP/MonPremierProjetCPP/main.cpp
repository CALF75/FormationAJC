#include <iostream>

using namespace std;



int Maclasse(int *p1, int *p2)
{
    int temp;
   if (*p1>*p2)
   {
       temp=*p1;
       *p1=*p2;
       *p2=temp;
       return 0;
  }
}
int Maclasse2(int &p1, int &p2)
{
    int temp;
   if (p1>p2)
   {
       temp=p1;
       p1=p2;
       p2=temp;
       return 0;
  }
}
int main()
{

    int a,b;
    a=34;
    b=23;
    cout <<"a vaut "<<a<<" | b vaut "<<b<<"\n"<< endl;
    Maclasse(&a,&b);
    cout <<"a vaut "<<a<<" | b vaut "<<b<<"\n"<< endl;
    a=34;
    b=23;
    cout <<"a vaut "<<a<<" | b vaut "<<b<<"\n"<< endl;
    Maclasse2(a,b);
    cout <<"a vaut "<<a<<" | b vaut "<<b<<"\n"<< endl;

    return 0;
}
