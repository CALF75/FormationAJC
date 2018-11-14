#include <stdio.h>
#include <stdlib.h>

enum {SUCCESS, FAIL};
void charreadwrite(FILE *fin, FILE *fout);
int main()
{
printf("Ici1.\n");
FILE *fptr1=NULL;
FILE *fptr2=NULL;
printf("Ici2.\n");
char filename1[]="./fic1.txt";
char filename2[]="/home/ajc184/fic2.txt";
printf("Ici1.\n");
int reval = SUCCESS;
printf("Ici2.\n");
fptr1 = fopen(filename1,"r");
fptr2 = fopen(filename2,"w");

printf("IciOK.\n");
if(fptr1==NULL)
{
printf("ouverture de %s impossible.\n",filename1);
reval = FAIL;

}else if (fptr2==NULL)
{
printf("ouverture de %s impossible. \n",filename2);
reval = FAIL;
}else{
printf("IciOK2.\n");
charreadwrite(fptr1,fptr2);

fclose(fptr1);
fclose(fptr2);

}
return reval;
}

void charreadwrite(FILE *fin, FILE *fout)
{
int c;

while((c=fgetc(fin))!=EOF){

putchar(c);
fputc(c,fout);
}
}
