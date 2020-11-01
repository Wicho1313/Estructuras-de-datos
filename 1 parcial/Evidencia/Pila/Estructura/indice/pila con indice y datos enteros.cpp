#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct pila
{ int valor;
   struct pila *sig;
};

typedef struct pila nodo; 


nodo *crearPila(nodo *tope)
{ tope = NULL;
  return tope;
}


nodo *push(int numero, nodo *tope)
{
 nodo *nuevoNodo;
 nuevoNodo=(nodo*)malloc(sizeof(nodo));
 nuevoNodo->valor=numero;
 nuevoNodo->sig=tope;
 tope=nuevoNodo;
 return tope;
}


nodo *pop(nodo *tope)
{
nodo *nodoAEliminar;
       nodoAEliminar=tope;
       tope=tope->sig;  
       free(nodoAEliminar);
   return tope;
}       

void imprimirPila(nodo *tope)
{ nodo *apuntadorAuxiliar;
  apuntadorAuxiliar=tope;
  printf("\n El ultimo valor ingresado es el inicio de la pila ");
  while (apuntadorAuxiliar != NULL)
  { 
  printf("%d - > ",apuntadorAuxiliar->valor);
  apuntadorAuxiliar=apuntadorAuxiliar->sig;
  }
  printf("NULL \n\n");
}
int menu(){
	int opc;
	fflush(stdin);
	
printf ("\n 1.- Meter pila \n ");
printf ("\n 2.- sacar pila \n ");
printf ("\n 3.- salir \n ");
scanf ("%d", &opc);
	return (opc);
}
int main()
{
    int i, dato;
    nodo *inicioPila;
    inicioPila=crearPila(inicioPila);
    for (;;){
int opc=menu();
switch (opc){
       case 1: 
    for (i=0; i<=5; i++){
    printf("Ingresa enteros: ");
    scanf("%d",&dato);
    inicioPila=push(dato,inicioPila);
    } 
    system("cls");
    printf("Empieza  la pila\n\n");
    imprimirPila(inicioPila);
    break;
   case 2:
    inicioPila=pop(inicioPila);   
    printf("Se saco de la pila el ultimo dato ingresado\n\n");
    imprimirPila(inicioPila);
    system("pause");
    break;
    case 3:
         system ("cls");
         break;
}
}
system ("pause");
return 0;
}

