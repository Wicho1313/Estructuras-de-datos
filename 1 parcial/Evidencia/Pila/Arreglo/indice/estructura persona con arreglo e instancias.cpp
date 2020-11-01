#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
struct persona
{
       char nombre [20];
       int edad;
       char sexo;
       float est;
};
int main ()
{
    struct persona arreglo [1], *ptrs; //solo para 1 dato de cada uno
    int i;
    for(i=0;i<=0;i++)
    {
           fflush(stdin);
           printf("\n ingrese nombre: ");
           gets(arreglo [i].nombre);
           fflush(stdin);
           printf("\n ingrese edad: ");
           scanf("%d",&arreglo[i].edad);
           fflush(stdin);
           printf("\n Ingrese sexo: ");
           arreglo[i].sexo=getchar();
}
for(i=0;i<=0;i++)
{
         printf ("El nombre es %s , la edad es %d su sexo es %c",arreglo[i].nombre, arreglo[i].edad,arreglo[i].sexo);                
}
system("pause");
return 0;
}
