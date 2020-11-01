#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
struct persona{
char nombre [20];
int edad;
float est;
char sexo;
};
struct elemento{
struct persona arreglo[5], *ptr;
};
int main()
{
 struct elemento var, *ptrs;
 ptrs=&var;
 for(ptrs->ptr=ptrs->arreglo;ptrs->ptr<=&ptrs->arreglo[4];ptrs->ptr++)
 {
     fflush(stdin);                                                      
printf("\n Ingresa nombre: ");
gets(ptrs->ptr->nombre);
 fflush(stdin);    
printf("\n Ingresa edad: ");
scanf("%d", &ptrs->ptr->edad);
 fflush(stdin);    
printf("\n ingresa Estatura: ");
scanf("%f",&ptrs->ptr->est);
 fflush(stdin);    
printf("\n Ingresa el sexo: ");
ptrs->ptr->sexo=getchar();       
}   
for(ptrs->ptr=ptrs->arreglo;ptrs->ptr<=&ptrs->arreglo[4];ptrs->ptr++)
{
       printf("\n En la cellda %d la cadena %s en la direccion %lu ",(int)(ptrs->ptr-ptrs->arreglo), ptrs->ptr->nombre, &ptrs->ptr->nombre);
        printf("\n En la cellda %d la edad %d en la direccion %lu ",(int)(ptrs->ptr-ptrs->arreglo),ptrs->ptr->edad, &ptrs->ptr->edad);
         printf("\n En la cellda %d la estatura %f en la direccion %lu ",(int)(ptrs->ptr-ptrs->arreglo), ptrs->ptr->est, &ptrs->ptr->est);
          printf("\n En la cellda %d la sexo %c en la direccion %lu ",(int)(ptrs->ptr-ptrs->arreglo),ptrs->ptr->sexo, &ptrs->ptr->sexo);
}
system("pause");
return 0; 
}
