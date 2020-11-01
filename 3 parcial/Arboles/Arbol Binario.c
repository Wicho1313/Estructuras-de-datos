#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

 struct NodoArbol{
	int dato;
	struct NodoArbol* ptrNodoIzq;
	struct NodoArbol* ptrNodoDer;
};

struct NodoArbol* crearNuevoNodo(int dato){
	struct NodoArbol* nuevoNodo = (struct NodoArbol*) malloc(sizeof(struct NodoArbol));
	nuevoNodo->ptrNodoIzq = NULL;
	nuevoNodo->ptrNodoDer = NULL;
	nuevoNodo->dato = dato;
	return nuevoNodo;
}

void agregarNodoArbol(struct NodoArbol **ptrNodoRaiz,int dato){
	if((*ptrNodoRaiz) == NULL){
		(*ptrNodoRaiz) = crearNuevoNodo(dato);
	}else if((*ptrNodoRaiz)->dato>dato){
		agregarNodoArbol(&((*ptrNodoRaiz)->ptrNodoIzq),dato);
	}else if((*ptrNodoRaiz)->dato<dato){
		agregarNodoArbol(&((*ptrNodoRaiz)->ptrNodoDer),dato);
	}else{
		printf("El dato ya se encuentra en el arbol");
	}
}

void recorrerPuntero (struct NodoArbol **ptr,struct NodoArbol **ptrH, struct NodoArbol **ptrA){
	if((*ptrH)->ptrNodoDer != NULL){
		recorrerPuntero(ptr,&((*ptrH)->ptrNodoDer),ptrA);
	}else{
		(*ptr)->dato = (*ptrH)->dato;
		*ptrA = *ptrH;
		*ptrH= (*ptrH)->ptrNodoIzq;
	}
}

void eliminaNodoArbol(struct NodoArbol **ptrNodoRaiz,int datoEliminar){
	if((*ptrNodoRaiz) == NULL){
		printf("El dato no esta en el arbol");
	}else if(datoEliminar>(*ptrNodoRaiz)->dato){
	
		eliminaNodoArbol(&((*ptrNodoRaiz)->ptrNodoDer),datoEliminar);
	}else if(datoEliminar<(*ptrNodoRaiz)->dato){
		eliminaNodoArbol(&((*ptrNodoRaiz)->ptrNodoIzq),datoEliminar);
	}else{
		
		struct NodoArbol *ptrNodoAux = (*ptrNodoRaiz);
		if((*ptrNodoRaiz)->ptrNodoDer == NULL){
			(*ptrNodoRaiz) = ptrNodoAux->ptrNodoIzq;
		}else if((*ptrNodoRaiz)->ptrNodoIzq == NULL){
			(*ptrNodoRaiz) = ptrNodoAux->ptrNodoDer;
		}else{
			recorrerPuntero(ptrNodoRaiz,&((*ptrNodoRaiz)->ptrNodoIzq),&ptrNodoAux);
			free(ptrNodoAux);
		}
	}
}

void recorrePreOrden(struct NodoArbol **ptrNodoRaiz){
	if((*ptrNodoRaiz)!=NULL){
		printf(" %d ",(*ptrNodoRaiz)->dato);
		recorrePreOrden(&(*ptrNodoRaiz)->ptrNodoIzq);
		recorrePreOrden(&(*ptrNodoRaiz)->ptrNodoDer);
	}
}

void recorreInOrden(struct NodoArbol **ptrNodoRaiz){
	if((*ptrNodoRaiz)!=NULL){
		recorreInOrden(&(*ptrNodoRaiz)->ptrNodoIzq);
		printf(" %d ",(*ptrNodoRaiz)->dato);
		recorreInOrden(&(*ptrNodoRaiz)->ptrNodoDer);
	}
}

void recorrePostOrden(struct NodoArbol **ptrNodoRaiz){
	if((*ptrNodoRaiz)!=NULL){
		recorrePostOrden(&(*ptrNodoRaiz)->ptrNodoIzq);
		recorrePostOrden(&(*ptrNodoRaiz)->ptrNodoDer);
		printf(" %d ",(*ptrNodoRaiz)->dato);
	}
}

void imprimeArbolHorizontal(struct NodoArbol **ptrNodoRaiz,int contador){
	int i,j;
	i=contador;
	if((*ptrNodoRaiz)!=NULL){
		imprimeArbolHorizontal(&((*ptrNodoRaiz)->ptrNodoDer),i+1);
		printf("\n");
		for(j=1;j<i;j++){
			printf(" - ");
		}
		printf("%d",(*ptrNodoRaiz)->dato);
		imprimeArbolHorizontal(&((*ptrNodoRaiz)->ptrNodoIzq),i+1);
	}
}

int main(){
	struct NodoArbol *ptrNodoRaiz = NULL;
	int opcion=0;
	int dato=0;
	int datoEliminar=0;
	do{
		printf("\nSelecciona una opcion\n");
		printf("1)Meter dato al arbol\n");
		printf("2)Sacar dato del arbol\n");
		printf("3)Recorrido preorden\n");
		printf("4)Recorrido inorden\n");
		printf("5)Recorrido postorden\n");
		printf("6)Imprimir arbol\n");
		printf("7)Salir\n");
		printf("\n");
		setbuf(stdin,NULL);
		scanf("%d",&opcion);
		switch(opcion){
			case 1:
				printf("\nIngresa dato \n");
				setbuf(stdin,NULL);
				scanf("%d",&dato);
				agregarNodoArbol(&ptrNodoRaiz,dato);
				break;
			case 2:
				printf("\nIngresa dato a eliminar \n");
				setbuf(stdin,NULL);
				scanf("%d",&datoEliminar);
				eliminaNodoArbol(&ptrNodoRaiz,datoEliminar);
				break;
			case 3:
				printf("\n%s\n","El arbol en preorden es: ");
				recorrePreOrden(&ptrNodoRaiz);
				break;
			case 4:
				printf("\n%s\n","El arbol en Inorden es: ");
				recorreInOrden(&ptrNodoRaiz);
				break;
			case 5:
				printf("\n%s\n","El arbol en Postorden es: ");
				recorrePostOrden(&ptrNodoRaiz);
				break;
			case 6:
				imprimeArbolHorizontal(&ptrNodoRaiz,1);
				break;		
			case 7:
				exit(0);
				break;
			default:
				printf("\nOpcion no valida\n\n");
		}
	}while(opcion!=7);
	return 0;
}
