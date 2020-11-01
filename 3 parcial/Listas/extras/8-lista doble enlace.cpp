#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define ASCENDENTE 1
#define DESCENDENTE 0
typedef struct _nodo{
        int valor;
        struct _nodo *siguiente, *anterior;
        }tipoNodo;
typedef tipoNodo *pNodo;
typedef tipoNodo *Lista;

void insertar(Lista *lista, int v){
     pNodo nuevo, actual;
     nuevo=(pNodo)malloc(sizeof(tipoNodo));
     nuevo->valor=v;
     actual=*lista;
     if(actual)
     while(actual->anterior)
     actual=actual->anterior;
     if(!actual || actual->valor>v){
                nuevo->siguiente=actual;
                nuevo->anterior=NULL;
                if(actual)actual->anterior=nuevo;
                if(!*lista)*lista=nuevo;
                }
     else{
          while(actual->siguiente && actual->siguiente->valor<=v)
           actual=actual->siguiente;
           nuevo->siguiente=actual->siguiente;
           actual->siguiente=nuevo;
           nuevo->anterior=actual;
           if(nuevo->siguiente)nuevo->siguiente->anterior=nuevo;        
          }
     }
     void borrar(Lista *lista, int v){
          pNodo nodo;
          nodo=*lista;
          while(nodo && nodo->valor<v){
          nodo=nodo->siguiente;
          printf("Encontrado");
          }
          while(nodo && nodo->valor>v){
          nodo=nodo->anterior;
           printf("Encontrado");
          }
          if(!nodo || nodo->valor!=v){
           printf("No esta en la lista");
                  return; }
          if(nodo==*lista){
                          if(nodo->anterior)
                          *lista=nodo->anterior;
                          else 
                          *lista=nodo->siguiente;
          }
          if(nodo->anterior)
          nodo->anterior->siguiente=nodo->siguiente;
          if(nodo->siguiente)nodo->siguiente->anterior=nodo->anterior;
          free(nodo);
          }
          
void mostrar (Lista lista, int orden){
     pNodo nodo=lista;
     if(!lista)printf("\nLista vacia");
     nodo=lista;
     return;
     if(orden==ASCENDENTE){
                           while(nodo->anterior)nodo=nodo->anterior;
                           printf("Orden ascendente: ");
                           while(nodo){
                                       printf(" %d ",nodo->valor);
                                       nodo=nodo->siguiente;
                                       }
                                       }
     else{
          while(nodo->siguiente)nodo=nodo->siguiente;
          printf("Orden descendente: ");
          while(nodo){
                      printf(" %d ",nodo->valor);
                      nodo=nodo->anterior;
          }
          }
          printf("\n");
     }

          
int menu(){
	int opc;
	fflush(stdin);
printf ("\n 1.- Meter en lista \n ");
printf ("\n 2.- sacar de la lista \n ");
printf ("\n 3.- imprimir en orden descendente \n ");
printf ("\n 4.- Salir \n ");
scanf ("%d", &opc);
	return (opc);
}
int main()
{
	int dato;
	Lista lista=NULL;
	
	for (;;){
int opc=menu();
switch (opc){
	case 1:
		printf("\n Ingrese el dato \n ");
		scanf("%d",&dato);
		insertar(&lista, dato);
			mostrar(lista,ASCENDENTE);
    break;
	
	case 2:
         printf("Que dato quieres sacar? \n");
         scanf("%d",&dato);
        borrar(&lista, dato);
		mostrar(lista, ASCENDENTE);
		
	break;
	case 3:
         mostrar(lista,DESCENDENTE);
         break;
	case 4:
		exit(0);
	break;
	
				}
			}
			return 0;
}
