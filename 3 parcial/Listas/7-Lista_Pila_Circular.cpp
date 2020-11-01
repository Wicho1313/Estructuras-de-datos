#include <stdio.h>
#include <stdlib.h>

struct nodo{
int dato;
struct nodo *ptrsig;	
};
struct nodo *ptrfin;
struct nodo *ptrini;

void meterInicio(){
	struct nodo *ptrNuevo;
	ptrNuevo=(struct nodo *)malloc(sizeof(struct nodo));
	printf("Mete al inicio");
	printf("\n ingresa un dato entero: ");
	scanf("%d",&ptrNuevo->dato);
	ptrNuevo->ptrsig=NULL;
	if(ptrini==NULL){
		printf("Primer nodo! ");
		ptrini=ptrNuevo;
		ptrini->ptrsig=ptrini;
		ptrfin=ptrNuevo;
	}
	else{
	ptrNuevo->ptrsig=ptrini;
	ptrini=ptrNuevo;
	ptrfin->ptrsig=ptrini;
}
}
void meterFinal(){
	struct nodo *ptrNuevo;
	ptrNuevo=(struct nodo *)malloc(sizeof(struct nodo));
	printf("Mete al final");
	printf("\n ingresa un dato entero: ");
	scanf("%d",&ptrNuevo->dato);
	ptrNuevo->ptrsig=NULL;
	if(ptrini==NULL){
		printf("Primer nodo! ");
		ptrini=ptrNuevo;
		ptrini->ptrsig=ptrini;
		ptrfin=ptrNuevo;
	}
	else{
		ptrfin->ptrsig=ptrNuevo;
		ptrNuevo->ptrsig=ptrini;
		ptrfin=ptrNuevo;
	}
}
void sacarInicio(){
	struct nodo *ptrAux;
	system("cls");
	printf("Eliminar un elemento al inicio");
	if(ptrini==NULL){
		printf("La lista esta vacia");
	}
	else if(ptrini==ptrfin){
		printf("\n se elmino el ultimo nodo: %d",ptrini->dato);
    free(ptrini);
    ptrini=NULL;
    ptrfin=NULL;
	}
	else{
		ptrAux=ptrini;
		ptrini=ptrini->ptrsig;
		printf("\n Se elimino el elemento inicial: %d",ptrAux->dato);
		free(ptrAux);
	}
	system("pause");
}
void sacarFinal(){
		struct nodo *ptrAnt,*ptrRec;
	system("cls");
	printf("Elimina un elemento al final");
	if(ptrini==NULL){
		printf("La lista esta vacia");
	}
	else if(ptrini==ptrfin){
		printf("\n Se elmino el ultimo nodo: %d",ptrini->dato);
    free(ptrini);
    ptrini=NULL;
    ptrfin=NULL;
	}
	else{
		ptrAnt=ptrini;
		ptrRec=ptrini->ptrsig;
		while(ptrRec->ptrsig!=ptrini)
		{
			ptrAnt=ptrRec;
			ptrRec=ptrRec->ptrsig;
		}
		ptrAnt->ptrsig=ptrini;
		ptrfin=ptrAnt;
		printf("\n Se elimino el nodo: %d \n",ptrRec->dato);
		free(ptrRec);
	}
	system("pause");
}
void recorrer(){
	int cont=0;
	struct nodo *ptrCabAux;
	ptrCabAux= ptrini;
            printf("\nLista pila circular: ");   
do{
      if(ptrCabAux==ptrfin)
      cont=1;
            printf(" %d ", ptrCabAux->dato);
            if(ptrCabAux!=ptrfin)
            ptrCabAux=ptrCabAux->ptrsig;
            
            }	while(ptrCabAux!=ptrfin||cont==0);
}

int menu(){
	int opc;
	fflush(stdin);
printf ("\n 1.- Meter al inicio \n ");
printf ("\n 2.- Meter al final\n ");
printf ("\n 3.- sacar al incio\n ");
printf ("\n 4.- sacar al final \n ");
printf ("\n 5.- Imprimir lista pila circular \n ");
printf ("\n 6.- Salir \n ");
scanf ("%d", &opc);
	return (opc);
}

int main(){
		for (;;){
int opc=menu();
switch (opc){
	case 1:
    meterInicio();
    recorrer();
	break;
	
	case 2:
	meterFinal();
	recorrer();
	break;
	
	case 3:
		sacarInicio();
		recorrer();		
	break;
	
	case 4:
		sacarFinal();
		recorrer();
	break;
	
	case 5:
			recorrer();
	break;		
	case 6:
		exit(0);
		break;
				}
			}
			system("pause");
			return 0;
	
}

