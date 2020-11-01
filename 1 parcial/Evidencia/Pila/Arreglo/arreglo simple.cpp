#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
int main()
{
 int arreglo [10], *ptr;
 for (ptr=arreglo;ptr<=&arreglo[9];ptr=ptr+1)
 {
     printf("\n Ingresa entero");
     scanf("%d", ptr);
 }
 for(ptr=arreglo;ptr<=&arreglo[9];ptr=ptr+1)
 {
 printf("\n En la celda %d esta el valor %d y en la direccion %lu", (int)(ptr-arreglo), *ptr,ptr);
}   
system ("pause");
    return 0;
}
