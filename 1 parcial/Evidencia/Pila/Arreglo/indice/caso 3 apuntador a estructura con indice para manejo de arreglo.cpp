#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
using namespace std;
struct elemento{
int arreglo [5];
int i;
int *ptrs;
};
int main ()
{
 struct elemento var1, *ptrs;
 ptrs=&var1;
 for (ptrs->i=0;ptrs->i<=4;ptrs->i++)
 {
     printf("\n Ingresa entero: ");
     scanf("%d", &ptrs->arreglo[ptrs->i]);
}
for (ptrs->i=0;ptrs->i<=4;ptrs->i++)
{
    printf("\n En la celda %d esta el valor %d y en la direccion %lu ",ptrs->i, ptrs->arreglo[ptrs->i], &ptrs->arreglo[ptrs->i]);
}
system("pause");
return 0;   
}
