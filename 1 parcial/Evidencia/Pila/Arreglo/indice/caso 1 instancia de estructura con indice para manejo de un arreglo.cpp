#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
struct elemento
{
  int arreglo [5];
  int i;   
};

int main()
{
      struct elemento var1; 
    for(var1.i=0;var1.i<=4;var1.i++)
    {
           printf("\n Ingresa entero: ");
           scanf("%d", &var1.arreglo[var1.i]);
}
for(var1.i=0;var1.i<=4;var1.i++)
{
       printf("\n En la celda %d esta el valor %d en la direccion %lu ", var1.i,var1.arreglo[var1.i],&var1.arreglo[var1.i]);
}
system("pause");
return 0;
}
