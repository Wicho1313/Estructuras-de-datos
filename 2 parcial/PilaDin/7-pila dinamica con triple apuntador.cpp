#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct nodo{
int dato;	
struct nodo *ptrsiguiente;	
};
int pilaVacia(struct nodo ***ptrcima){
	if(**ptrcima==NULL){
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
	return aux;
}
void meter(struct nodo ***ptrcima, int entrada){
	struct nodo *ptrNuevo;
	ptrNuevo= NuevoNodo(entrada);
	if(**ptrcima!=NULL){
		ptrNuevo->dato=entrada;
		ptrNuevo->ptrsiguiente=**ptrcima;
		**ptrcima=ptrNuevo;
	}
	else
	{
	**ptrcima=ptrNuevo;
	}
}
int sacar(struct nodo ***ptrcima){
	struct nodo *ptrtemp;
	int valor;
	ptrtemp= **ptrcima;
	valor=(**ptrcima)->dato;
	**ptrcima=(**ptrcima)->ptrsiguiente;
	free(ptrtemp);
	return valor;
	
}
void mostrarPila(struct nodo *** ptrcima){
	
	struct nodo *ptrCabAux;
	ptrCabAux=**ptrcima;
	while(ptrCabAux!=NULL){
            printf("\n En la direccion %lu esta el dato %d ", &ptrCabAux->dato, ptrCabAux->dato);
            ptrCabAux=ptrCabAux->ptrsiguiente;
            }
}
int main(){
	
	int datoEnt, opc;
	struct nodo *ptrc=NULL;
	struct nodo **ptrc2=NULL;
	struct nodo ***ptrc3;
	ptrc2=&ptrc;
	ptrc3=&ptrc2;
 
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
		meter(ptrc3,datoEnt);
		  mostrarPila(ptrc3);
		break;
	case 2:
			if(pilaVacia(ptrc3)==1){
				printf("\nLa pila está vacia ");
				getchar();
			}
			else{
				printf("El dato recuperado es: %d ",sacar(ptrc3));
			}
			mostrarPila(ptrc3);
		break;
	case 3:
		break;
}
}while(opc!=3);	
}
