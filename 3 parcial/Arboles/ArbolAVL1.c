#include <stdio.h>
#include <stdlib.h>
struct Nodo
{
    int dato;
    int FE;
    struct nodo *ptrIzq, *ptrDer;
};	
struct Nodo* nuevoNodo(int dato1);
struct Nodo* insertarAVL(struct Nodo **ptrRaiz, int dato1);
int profAVL(struct Nodo *ptrRaiz);
int FactorDeEquilibrio(struct Nodo *ptrRaiz);
void RSII(struct Nodo **ptr);
void RSDD(struct Nodo **ptr);
void RDID(struct Nodo **ptr);
void RDDI(struct Nodo **ptr);
void recorridoPreOrden(struct Nodo *ptrRaiz);
void recorridoEnOrden(struct Nodo *ptrRaiz);
void recorridoPostOrden(struct Nodo *ptrRaiz);
void imprimirArbolAVL(struct Nodo *ptrRaiz, int contador);
void eliminaNodoAVL(struct Nodo **ptrRaiz,int dato);

struct Nodo* nuevoNodo(int dato1){
	struct Nodo *ptrNuevo;
	ptrNuevo=(struct Nodo *)malloc(sizeof(struct Nodo));
	ptrNuevo->dato=dato1;
	ptrNuevo->ptrIzq=NULL;
	ptrNuevo->ptrDer=NULL;
	ptrNuevo->FE=0;
	return ptrNuevo;
}

struct Nodo* insertarAVL(struct Nodo **ptrRaiz, int dato1)
{
	if(*ptrRaiz==NULL)		
		*ptrRaiz = nuevoNodo(dato1);
	else if((*ptrRaiz)->dato>dato1){
		insertarAVL(&(*ptrRaiz)->ptrIzq,dato1);
		if(profAVL((*ptrRaiz)->ptrIzq)-profAVL((*ptrRaiz)->ptrDer)==2){															
			if(dato1<((*ptrRaiz)->ptrIzq)->dato)	
				RSII(&(*ptrRaiz));		
			else
				RDID(&(*ptrRaiz));	
		}
	}
	else if(dato1>(*ptrRaiz)->dato){
		insertarAVL(&((*ptrRaiz)->ptrDer),dato1);	
		if(profAVL(&(*ptrRaiz)->ptrDer)-profAVL(&(*ptrRaiz)->ptrIzq)==2){
			if(dato1>((*ptrRaiz)->ptrDer)->dato)
				RSDD(&(*ptrRaiz));		
			else
				RDDI(&(*ptrRaiz));		
		}
	}
	return *ptrRaiz;
}

int profAVL(struct Nodo *ptrRaiz){
    int profI, profD;
    if(ptrRaiz==NULL)
        return 0;
    else{
        profI=profAVL(ptrRaiz->ptrIzq);
        profD=profAVL(ptrRaiz->ptrDer);
        if(profI>profD)
            return profI+1;
        else
            return profD+1;
    }
}

struct Nodo* obtieneMasChico(struct Nodo *ptrRaiz){
	struct Nodo *nodoActual = ptrRaiz;
	while(nodoActual->ptrIzq!=NULL){
		nodoActual = nodoActual->ptrIzq;
	}
	return nodoActual;
}

int max(int a,int b){
	return (a>b) ? a:b;
}

void eliminaNodoAVL(struct Nodo **ptrRaiz,int dato){ 
	if((*ptrRaiz)->dato<dato){
		eliminaNodoAVL(&(*ptrRaiz)->ptrDer,dato);
	}else if((*ptrRaiz)->dato>dato){
		eliminaNodoAVL(&(*ptrRaiz)->ptrIzq,dato);
	}else{
		struct Nodo *temp = NULL;
		if((*ptrRaiz)->ptrDer == NULL || (*ptrRaiz)->ptrIzq == NULL){ 
			if((*ptrRaiz)->ptrDer == NULL && (*ptrRaiz)->ptrIzq == NULL){ 
				temp = (*ptrRaiz);
				(*ptrRaiz) = NULL;
			}else if((*ptrRaiz)->ptrDer == NULL){ 
				temp = (*ptrRaiz)->ptrIzq;
				(*(*ptrRaiz)) = *temp;
			}else if((*ptrRaiz)->ptrIzq == NULL){ 
				temp = (*ptrRaiz)->ptrDer;
				(*(*ptrRaiz)) = *temp;
			}
			free(temp);
		}else{
			printf("%s\n","Aber 2");
			
	            struct Nodo* temp = obtieneMasChico((*ptrRaiz)->ptrDer);
	            printf("%s %d \n","Mas chico: ",temp);
	           
	            (*ptrRaiz)->dato = temp->dato;
  	         
	            eliminaNodoAVL(&(*ptrRaiz)->ptrDer, temp->dato);
		}
	}
	if((*ptrRaiz)!=NULL){
	    int ER = FactorDeEquilibrio(*ptrRaiz);
	 	int EI = FactorDeEquilibrio((*ptrRaiz)->ptrIzq);
	 	int ED = FactorDeEquilibrio((*ptrRaiz)->ptrDer);
	 	
	    if (ER > 1 && EI >= 0){
	    	printf("%s\n","Rota RSDD");
	    	RSDD(ptrRaiz);
	    }

	    if ( ER> 1  && EI< 0){
	        printf("%s\n","Rota RDDI");
	    	RDDI(ptrRaiz);
	    }

	    if (ER < -1 && ED <= 0){
	    	printf("%s\n","Rota RSII");
	    	RSII(ptrRaiz);
	    }
	        
	    if (ER < -1 && ED > 0){
	   		printf("%s\n","Rota RDID");
	        RDID(ptrRaiz);
	    }
	    
	}
}

int FactorDeEquilibrio(struct Nodo *ptrRaiz){
	if(ptrRaiz!=NULL){
		printf("Calculando FE: %d \n",ptrRaiz);
		ptrRaiz->FE=profAVL(ptrRaiz->ptrDer)-profAVL(ptrRaiz->ptrIzq);
		printf("%s %d\n","FactorDeEquilibrio: ",ptrRaiz->FE);
		return ptrRaiz->FE;
	}else{
		printf("%s\n","EL NODO DEL FE ES NULO");
		return 0;
	}
}

void RSII(struct Nodo **ptr){
	NodoAVL *ptrAuxiliar = (*ptr)->ptrIzq;
	(*ptr)->ptrIzq=ptrAuxiliar->ptrDer;
	ptrAuxiliar->ptrDer=(*ptr);
	(*ptr)=ptrAuxiliar;
}

void RSDD(struct Nodo **ptr){
	struct Nodo *ptrAuxiliar = (*ptr)->ptrDer;
	(*ptr)->ptrDer=ptrAuxiliar->ptrIzq;
	ptrAuxiliar->ptrIzq=(*ptr);
	(*ptr)=ptrAuxiliar;
}

void RDID(struct Nodo **ptr){
	RSDD(&((*ptr)->ptrIzq));
	RSII(&(*ptr));
}

void RDDI(struct Nodo **ptr){
	RSII(&((*ptr)->ptrDer));
	RSDD(&(*ptr));
}

void recorridoPreOrden(struct Nodo *ptrRaiz){
	if(ptrRaiz!=NULL){
		printf("%d\n",ptrRaiz->dato);
		recorridoPreOrden(ptrRaiz->ptrIzq);
		recorridoPreOrden(ptrRaiz->ptrDer);
	}
}

void recorridoEnOrden(struct Nodo *ptrRaiz){
	if(ptrRaiz!=NULL){
		recorridoEnOrden(ptrRaiz->ptrIzq);
		printf("%d\n",ptrRaiz->dato);
		recorridoEnOrden(ptrRaiz->ptrDer);
	}
}

void recorridoPostOrden(struct Nodo *ptrRaiz){
	if(ptrRaiz!=NULL){
		recorridoPostOrden(ptrRaiz->ptrIzq);
		recorridoPostOrden(ptrRaiz->ptrDer);
		printf("%d\n",ptrRaiz->dato);
	}
}

void imprimirArbolAVL(struct Nodo *ptrRaiz, int contador){
	int i, j;
	i = contador;
	if(ptrRaiz!=NULL){
		imprimirArbolAVL(ptrRaiz->ptrDer,i+1);
		printf("\n");
		for(j=1;j<i;j++){
			printf(" - ");
			
		}	
		printf(" %d ",ptrRaiz->dato);		
		imprimirArbolAVL(ptrRaiz->ptrIzq,i+1);
	}
}

int main (){
    int opcion,salir=0,miDato,nodosAIngresar,i,prof,datoABuscar,datoABorrar,contV=0;
    	struct Nodo *ptrRaiz;
	ptrRaiz=NULL;
	do{
		printf("\nSelecciona una opcion\n");
		printf("1.-Meter datos en el arbol\n");
		printf("2.-Realizar el recorrido el PreOrden\n");
		printf("3.-Realizar el recorrido el EnOrden\n");
		printf("4.-Realizar el recorrido el PostOrden\n");
		printf("5.-Ver la profundidad del arbol\n");
		printf("6.-Borrar un dato\n");
		printf("7.-Mostrar el arbol\n");
		printf("8.-Salir\n");
		printf("\n");
		scanf("%d",&opcion);
		switch(opcion){
			case 1:
			
					printf("\nIngresa dato %d:\n",i);
					scanf("%d",&miDato);
					ptrAux=insertarAVL(&ptrRaiz,miDato);
					printf("\nDato ingresado\n\n",i);
				
				imprimirArbolAVL(ptrRaiz,contV);
			break;
			case 2:
				printf("\nRecorrido PreOrden:\n");
				recorridoPreOrden(ptrRaiz);
				printf("\n");
			break;
			case 3:
				printf("\nRecorrido EnOrden:\n");
				recorridoEnOrden(ptrRaiz);
				printf("\n");
			break;
			case 4:
				printf("\nRecorrido PostOrden:\n");
				recorridoPostOrden(ptrRaiz);
				printf("\n");
			break;
			case 5:
				prof=profAVL(ptrRaiz);
				printf("\nProfundidad del arbol: %d\n",prof);
				printf("\n");
            break;
            case 6:
            	printf("Nodo a borrar:\n");
				scanf("%d",&datoABorrar);
				eliminaNodoAVL(&ptrRaiz,datoABorrar);
				printf("\n\n");
            break;
            case 7:
				printf("\nEl arbol es:\n");
				imprimirArbolAVL(ptrRaiz,contV);
				printf("\n\n");
			break;
			case 8:
				salir=1;
			break;
			default:
				printf("\n\nOpcion no valida\n\n");
		}
	}while(salir==0);
	return 0;
}


