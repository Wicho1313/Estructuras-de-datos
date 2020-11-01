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
struct persona arreglo [5];
int i;
};
int main()
{
    struct elemento var;
for(var.i=0;var.i<=4;var.i++)
{
       fflush(stdin);                      
       printf("\n Ingresa nombre: "); 
       gets(var.arreglo[var.i].nombre);
       fflush(stdin); 
       printf("\n Ingrese edad: ");
       scanf("%d",&var.arreglo[var.i].edad);
       fflush(stdin); 
       printf("\n Ingresa estatura: ");
       scanf("%f",&var.arreglo[var.i].est);
       fflush(stdin); 
       printf("\n Ingresa sexo: ");
       var.arreglo[var.i].sexo=getchar();
}    
for(var.i=0;var.i<=4;var.i++)
{
       printf("\n En la celda %d esta la cadena %s y en la direccion %lu ", var.i, var.arreglo[var.i].nombre, &var.arreglo[var.i].nombre);
         printf("\n En la celda %d esta la edad %d y en la direccion %lu ", var.i, var.arreglo[var.i].edad, &var.arreglo[var.i].edad);
           printf("\n En la celda %d esta la estatura %f y en la direccion %lu ", var.i, var.arreglo[var.i].est, &var.arreglo[var.i].est);
             printf("\n En la celda %d esta el sexo %c y en la direccion %lu ", var.i, var.arreglo[var.i].sexo, &var.arreglo[var.i].sexo);
             
}
system("pause");
return 0;
}
