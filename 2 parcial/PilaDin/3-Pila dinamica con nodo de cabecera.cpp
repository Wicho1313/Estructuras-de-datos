#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int menu();
struct nodo * crearNodo (int valor);
void meterPila (struct nodo *ptrCab, int valor);
void sacarPila (struct nodo *ptrCab);
void mostrarPila(struct nodo * ptrCab);

struct nodo{
	int dato;
	struct nodo *ptrsig;
};

struct nodo * crearNodo (int dato){
	struct nodo *ptrAux;
	ptrAux=(struct nodo *) malloc(sizeof(struct nodo));
	ptrAux->dato=dato;
	ptrAux->ptrsig=NULL;
	return ptrAux;
}

void meterPila (struct nodo *ptrCab, int valor){
	struct nodo * ptrNuevo;
	ptrNuevo=crearNodo(valor);
	if(ptrCab->ptrsig==NULL){
		ptrCab->ptrsig=ptrNuevo;
	}
	else{
		ptrNuevo->ptrsig=ptrCab->ptrsig;
		ptrCab->ptrsig=ptrNuevo;
	}
}

void sacarPila (struct nodo *ptrCab){
	struct nodo *ptrAux;
	ptrAux=ptrCab->ptrsig;
	if(ptrCab->ptrsig!=NULL)
	{
        ptrCab->ptrsig=ptrAux->ptrsig;
        free(ptrAux);
}
else{
     printf("\n Pila vacia");
     }
	
}
void mostrarPila(struct nodo * ptrCab){
	
	struct nodo *ptrCabAux;
	ptrCabAux=ptrCab->ptrsig;
	while(ptrCabAux!=NULL){
            printf("\n En la direccion %lu esta el dato %d ", &ptrCabAux->dato, ptrCabAux->dato);
            ptrCabAux=ptrCabAux->ptrsig;
            }
}
int menu(){
	int opc;
	fflush(stdin);
printf ("\n 1.- Meter pila \n ");
printf ("\n 2.- sacar pila \n ");
printf ("\n 3.- Salir \n ");
scanf ("%d", &opc);
	return (opc);
}

int main()
{
	int dato;
	struct nodo * ptrCab=crearNodo(-1);
	ptrCab->ptrsig=NULL;
	
	for (;;){
int opc=menu();
switch (opc){
	case 1:
		printf("\n Ingrese el dato \n ");
		scanf("%d",&dato);
		meterPila(ptrCab, dato);
        mostrarPila(ptrCab);
    break;
	
	case 2:
		sacarPila(ptrCab);
		mostrarPila(ptrCab);
	break;
	
	case 3:
        exit(0);
	break;
	
				}
			}
			system("pause");
			return 0;
}
