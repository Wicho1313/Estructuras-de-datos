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
 struct elemento var;
 for(var.ptr=var.arreglo;var.ptr<=&var.arreglo[4];var.ptr++)
 {
     fflush(stdin);                                                      
printf("\n Ingresa nombre: ");
gets(var.ptr->nombre);
 fflush(stdin);    
printf("\n Ingresa edad: ");
scanf("%d", &var.ptr->edad);
 fflush(stdin);    
printf("\n ingresa Estatura: ");
scanf("%f",&var.ptr->est);
 fflush(stdin);    
printf("\n Ingresa el sexo: ");
var.ptr->sexo=getchar();       
}   
for(var.ptr=var.arreglo;var.ptr<=&var.arreglo[4];var.ptr++)
{
       printf("\n En la cellda %d la cadena %s en la direccion %lu ",(int)(var.ptr-var.arreglo), var.ptr->nombre, &var.ptr->nombre);
        printf("\n En la cellda %d la edad %d en la direccion %lu ",(int)(var.ptr-var.arreglo), var.ptr->edad, &var.ptr->edad);
         printf("\n En la cellda %d la estatura %f en la direccion %lu ",(int)(var.ptr-var.arreglo), var.ptr->est, &var.ptr->est);
          printf("\n En la cellda %d la sexo %c en la direccion %lu ",(int)(var.ptr-var.arreglo), var.ptr->sexo, &var.ptr->sexo);
}
system("pause");
return 0; 
}
