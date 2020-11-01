#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
struct persona{
char nombre[20];
char sexo;
int edad;
};
int main ()
{
struct persona arreglo[10], *ptrs;   
    for(ptrs=arreglo;ptrs<=&arreglo[9];ptrs=ptrs+1)
    {
        fflush(stdin);                                           
        printf("\n Ingresa nombre: ");
        gets(ptrs->nombre);
        fflush(stdin);    
        printf("\n ingresa sexo: ");
        ptrs->sexo=getchar();
        fflush(stdin);    
        printf("\n Ingresa edad: ");
        scanf("%d", &ptrs->edad);                                           
}
printf("\n el tamaño es: %d", sizeof(struct persona));
ptrs=arreglo;
printf("\n El arreglo inicia en: %lu", ptrs);
for(;ptrs<=&arreglo[9];ptrs=ptrs+1)
{
       printf("\n El nombre es: %s su sexo es: %c y su edad es: %d",ptrs->nombre,ptrs->sexo, ptrs->edad);
}
system("pause");
return 0;
}
