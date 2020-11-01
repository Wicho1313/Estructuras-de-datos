#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
 
struct cola {
 int dato;
 struct cola *s;
 };
struct cola *p,*aux,*u;

void push (int dat)
{
     aux=(struct cola *)malloc(sizeof(cola));
aux->dato=dat;
if(u)
{
u->s=aux;
aux->s=NULL;
u=aux;
}
else
{
p=u=aux;
}
}
void pop()
{
if(p)
{
aux=p;
cout<<"\nElimino a " <<p->dato;
p=aux->s;
free (aux);
}
else
{
printf("\n No hay datos");
}
}

void mostrar()
{
int i;
if(!u)
{
printf("\n No hay datos en la cola");
return;
}
aux=p;
while(aux)
{
cout<<"\n"<<++i<<" - "<<aux->dato;
aux=aux->s;
}
}

int main()
{
int opc,y;
do
{
printf("\n 1. Meter ");
printf("\n 2. sacar ");
printf("\n 3. mostrar ");
printf("\n 4. Salir ");
scanf("%d",&opc);
switch(opc)
{
case 1: printf("Ingrese dato: ");
 scanf("%d",&y);
 push(y);
 printf("\n Dato insertado!!");
 break;
case 2: pop();
 break;
case 3: mostrar(); break;
case 4:
     system("pause");
     system("cls");
default: printf("\n Opcion no valida!!"); break;
}
}while(opc!=4);
return 0;
}
