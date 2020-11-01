#include <stdlib.h>
#include <stdio.h>
struct nodoPila{
	int dato;
	struct nodoPila *ptrsiguiente, *ptrant; 
};
struct nodoPila *ptRef;

void meterpila(void)
{
	int valor;
	printf("\n introdusca un entero: ");
	scanf("%d",&valor);
	struct nodoPila *ptrNuevo;
	ptrNuevo=(struct nodoPila *)malloc(sizeof(struct nodoPila));
	ptrNuevo->dato=valor;
	ptrNuevo->ptrsiguiente=NULL;
	ptrNuevo->ptrant=NULL;
	if(ptRef==NULL){
		ptRef=ptrNuevo;
	}
	else{
		ptrNuevo->ptrsiguiente=ptRef;
		(ptRef)->ptrant;
		ptRef=ptrNuevo;
	}
	printf("\n Se agrego un elemento");
	system("pause");
}
void sacarpila(void){
     struct nodoPila *ptrAux;
     int valor;
      if(ptRef==NULL){
		printf("Esta vacia");
	}
	else{
	ptrAux=ptRef;
          ptRef=ptRef->ptrsiguiente;
          	valor=ptrAux->dato;
          	(ptRef)->ptrant=NULL;
          printf("Se elimino el dato: %d", valor);
          free(ptrAux);
	}
}
     void mostrarPila(void){
	
	struct nodoPila *ptrCabAux;
	ptrCabAux=ptRef;
	while(ptrCabAux!=NULL){
            printf("\n En la direccion %lu esta el dato %d ", &ptrCabAux->dato, ptrCabAux->dato);
            ptrCabAux=ptrCabAux->ptrsiguiente;
            }
}
void instrucciones(void){
	int opc;
	do{
	fflush(stdin);
printf ("\n 1.- Meter pila \n ");
printf ("\n 2.- sacar pila \n ");
printf ("\n 3.- Salir \n ");
scanf ("%d", &opc);
switch (opc){
	case 1:
		meterpila();
	mostrarPila ();
		break;
	case 2:
         sacarpila();
        mostrarPila ();
		break;
	case 3:
		exit(0);
		break;

}
}while(opc!=4);
}
int main()
{
instrucciones();
return 0;
}
