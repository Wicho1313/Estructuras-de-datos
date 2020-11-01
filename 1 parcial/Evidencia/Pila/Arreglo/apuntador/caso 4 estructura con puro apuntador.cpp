#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
struct elemento{
  int arreglo [5];
  int *ptr, *ptrs;     
};
int main()
{
 struct elemento var1, *ptrs;
 ptrs=&var1;
 for(ptrs->ptr=ptrs->arreglo;ptrs->ptr<=&ptrs->arreglo [4];ptrs->ptr++)
 {
        printf("\n Ingrese dato: ");
        scanf("%d", ptrs->ptr);
}   
for (ptrs->ptr=ptrs->arreglo;ptrs->ptr<=&ptrs->arreglo [4];ptrs->ptr++)
{
    printf("\n En la celda %d esta el valor %d en la direccion %lu ",(int)(ptrs->ptr-ptrs->arreglo), *ptrs->ptr, ptrs->ptr);
}
system("pause");
return 0;
}
