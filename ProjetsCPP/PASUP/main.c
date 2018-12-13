#include <stdio.h>
#include <stdlib.h>

int fonction(int a, int b);

int main()
{
    printf("Hello world!\n");

    char* p1;
    char* p2;
    char* p3;
    p1=(char*)malloc (4);
    p2=(char*)malloc (4);
    p3=(char*)malloc (4);

    *p1='A';
    *p2='A';
    *p3='A';
    printf("Hello world!\n");


    printf("Adresse : %p\n",p1);
    printf("Adresse : %p\n",p2);
    printf("Adresse : %p\n",p3);
    printf("Hello world!\n");
    printf("valeur : %c\n",*p1);
    printf("valeur : %c\n",*p2);
    printf("valeur : %c\n",*p3);
    p1=p1+32;
    *p1='B';
    printf("Adresse : %p\n",p1);
    printf("Hello world!\n");
    printf("valeur : %c\n",*p1);
    printf("valeur : %c\n",*p2);
    printf("valeur : %c\n",*p3);
    printf("Partie 2\n");

    const int a=10;
    printf("Adresse : %p\n",&a);
    printf("Valeur : %d\n",a);
    int* pa;
    pa= &a;
    printf("Valeur : %d\n",*pa);
    *pa=5;
    printf("Valeur : %d\n",*pa);
    printf("Valeur : %d\n",a);
    int c;
    int b=1;

    while(b<2*a){

    printf("a et b vallenr %d et %d\n",a,b);
    printf("fonction vaut %d\n", 158/fonction(a,b));
    printf("Tout est OK !\n");
    b=b+1;
    }
              return 0;
}
fonction(int a, int b)
{
return (a-b);
}
