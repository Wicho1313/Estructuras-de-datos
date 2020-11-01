#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
using namespace std;
struct elemento
{
  int arreglo [5];
  int *ptr;     
};

int main()
{
 struct elemento var1, *ptr;
 ptr=&var1;
 for(var1.ptr=var1.arreglo;var1.ptr<=&var1.arreglo[4];var1.ptr++)
 {
printf("\n Ingresa entero: ");
scanf("%d", var1.ptr);
}   
for(var1.ptr=var1.arreglo;var1.ptr<=&var1.arreglo[4];var1.ptr++)
{
       printf("\n En la celda %d esta el valor %d en la localizacion %lu ",(int)(var1.ptr-var1.arreglo), *var1.ptr, var1.ptr);
}  
system ("pause");
return 0;
}
