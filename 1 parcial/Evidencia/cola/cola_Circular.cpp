#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct cola CrearColaCirc(struct cola *c);
int colaVacia(struct cola *c);
int colaLlena(struct cola *c);
void push(struct cola *c, char valor);
int pop(struct cola *c);
int siguiente (int r);
int MostrarCola(struct cola *c);
#define MAX 5
struct cola{
int frente;
int final;
char datos[MAX];       
};
struct cola *c;

struct cola CrearColaCirc(struct cola *c){
       c->frente=0;
       c->final=MAX-1;
       }
       
void push(struct cola *c, char valor)
{
     
 if(!colaLlena(c))
 {
     c->final=siguiente(final);
     c->datos[c->final]=valor;
     
     }
     
     else
     {
         printf("\n La cola esta llena");
         }    
}
int pop(struct cola *c)
{
       int x;
       if(colaVacia(c))
       {
           x=c->datos[c->frente];
           c->frente=siguiente(c->frente);
           return x;
           }
           else
           {
               printf("\n La cola esta vacia");
               }
}
int colaVacia(struct cola *c)
{
if(c->frente==siguiente(c->final))
{
    return 1;
}
else
{
    return 0;
}    
}

int colaLlena(struct cola *c)
{
    if(c->frente==siguiente(siguiente(c->final)))
    {
        return 1;
}
else{
     return 0;
     }
}
int MostrarCola(struct cola *c)
{
    if(colaVacia(c)){
         printf("\n Cola a tope");         
         }
         
    else{
         return(c->datos[c->frente]);
         }
}
int siguiente (int r){
    
 return (r+1)%MAX;   
}
int main()
{
 int opc,y;
 struct cola *c;
do
{
printf("\n 1. Meter ");
printf("\n 2. sacar ");
printf("\n 3. mostrar ");
printf("\n 4. Salir ");
scanf("%d",&opc);
switch(opc)
{
 case 1:
      printf("Ingrese dato: ");
 scanf("%d",&y);
 push(c, y);
 printf("\n Dato insertado!!");
      break;
      case 2:
           pop(c);
           break;
           case 3:
                MostrarCola(c);
                break;
                case 4:
                     break;
 
}
}while (opc!=4);   
    return 0;
}
