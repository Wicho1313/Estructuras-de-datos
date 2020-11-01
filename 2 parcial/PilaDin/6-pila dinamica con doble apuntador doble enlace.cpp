#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct nodo{
int dato;	
struct nodo *ptrsiguiente, *ptrant;
	
};
int pilaVacia(struct nodo **ptrcima){
	if(*ptrcima==NULL){
		return 1;
	}
	else{
		return 0;
	}
}
struct nodo * NuevoNodo(int dato1){
	struct nodo *aux;
	aux=(struct nodo *)malloc(sizeof(struct nodo));
	aux->dato=dato1;
	aux->ptrsiguiente=NULL;
	aux->ptrant=NULL;
	return aux;
}
void meter(struct nodo **ptrcima, int entrada){
	struct nodo *ptrNuevo;
	ptrNuevo= NuevoNodo(entrada);
	if(*ptrcima!=NULL){
		ptrNuevo->dato=entrada;
		ptrNuevo->ptrsiguiente=*ptrcima;
		(*ptrcima)->ptrant;
		*ptrcima=ptrNuevo;
	}
	else
	{
	*ptrcima=ptrNuevo;
	}
}
int sacar(struct nodo **ptrcima){
	struct nodo *ptrtemp;
	int valor;
	ptrtemp= *ptrcima;
	valor=(*ptrcima)->dato;
	*ptrcima=(*ptrcima)->ptrsiguiente;
	if(*ptrcima!=NULL)
		(*ptrcima)->ptrant=NULL;
	free(ptrtemp);
	return valor;
	
}
void mostrarPila(struct nodo ** ptrcima){
	
	struct nodo *ptrCabAux;
	ptrCabAux=*ptrcima;
	while(ptrCabAux!=NULL){
            printf("\n En la direccion %lu esta el dato %d ", &ptrCabAux->dato, ptrCabAux->dato);
            ptrCabAux=ptrCabAux->ptrsiguiente;
            }
}
int main(){
	
	int datoEnt, opc;
	struct nodo *ptrc=NULL;
	struct nodo **ptrc2;
	ptrc2=&ptrc;
 
	do{
	fflush(stdin);
printf ("\n 1.- Meter pila \n ");
printf ("\n 2.- sacar pila \n ");
printf ("\n 3.- Salir \n ");
scanf ("%d", &opc);
switch (opc){
	case 1:
		 printf("Ingrese entero: ");
         scanf("%d",&datoEnt);
		meter(ptrc2,datoEnt);
		  mostrarPila(ptrc2);
		break;
	case 2:
			if(pilaVacia(ptrc2)==1){
				printf("\nLa pila está vacia ");
				getchar();
			}
			else{
				printf("El dato recuperado es: %d ",sacar(ptrc2));
			}
			
		  mostrarPila(ptrc2);
		break;
	case 3:
		break;
}
}while(opc!=3);	
}
