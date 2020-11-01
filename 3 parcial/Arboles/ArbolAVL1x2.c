//ÁRBOL BALANCEADO


#include <stdio.h>
#include <stdlib.h>

//Estructura
typedef struct nodo
{
    int dato;
    int FE;
    struct nodo *ptrIzq, *ptrDer;
}NodoAVL;	


//Declaración de funciones
NodoAVL* nuevoNodo(int x);
NodoAVL* insertarAVL(NodoAVL **ptrRaiz, int x);
int profAVL(NodoAVL *ptrRaiz);
int FactorDeEquilibrio(NodoAVL *ptrRaiz);
void RSII(NodoAVL **ptrR1);
void RSDD(NodoAVL **ptrR1);
void RDID(NodoAVL **ptrR1);
void RDDI(NodoAVL **ptrR1);
void recorridoPreOrden(NodoAVL *ptrRaiz);
void recorridoEnOrden(NodoAVL *ptrRaiz);
void recorridoPostOrden(NodoAVL *ptrRaiz);
void imprimirArbolAVL(NodoAVL *ptrRaiz, int contador);
void eliminaNodoAVL(NodoAVL **ptrRaiz,int dato);


//Función para crear nuevo nodo
NodoAVL* nuevoNodo(int x){
	NodoAVL *ptrNuevo;
	ptrNuevo=(struct nodo *)malloc(sizeof(struct nodo));
	ptrNuevo->dato=x;
	ptrNuevo->ptrIzq=NULL;
	ptrNuevo->ptrDer=NULL;
	ptrNuevo->FE=0;
	return ptrNuevo;
}


//Función para ingresar nuevo nodo
NodoAVL* insertarAVL(NodoAVL **ptrRaiz, int x)
{
	if(*ptrRaiz==NULL)		//Checa si no hay ningun nodo
		*ptrRaiz = nuevoNodo(x);
	else if((*ptrRaiz)->dato>x){//Checa si el nodo de raiz es mayor al dato que se desea ingresar
		insertarAVL(&((*ptrRaiz)->ptrIzq),x);//Ingresa el dato a la izquierda dado que es menor que la raiz
		/*El tipo de rotación depende del factor de equilibrio (FE) del nodo del problema y su descendiente
			*Si FE(nodoRaiz)=2, entonces el nodo que se desea ingresar es hijo derecho.*/
		if(profAVL((*ptrRaiz)->ptrIzq)-profAVL((*ptrRaiz)->ptrDer)==2){															
			if(x<((*ptrRaiz)->ptrIzq)->dato)	
				RSII(&(*ptrRaiz));		//Rotación Simple Izquierda Izquierda
			else
				RDID(&(*ptrRaiz));		//Rotación Doble Izquierda Derecha
		}
	}
	else if(x>(*ptrRaiz)->dato){//Checa si el nodo de raiz es menor al dato que se desea ingresar
		insertarAVL(&((*ptrRaiz)->ptrDer),x);	//Ingresa el dato a la derecha dado que es menor que la raiz
		/*El tipo de rotación depende del factor de equilibrio (FE) del nodo del problema y su descendiente
			*Si FE(nodoRaiz)=-2, entondes el nodo que se desea ingresar es hijo izquierdo.*/
		if(profAVL((*ptrRaiz)->ptrDer)-profAVL((*ptrRaiz)->ptrIzq)==2){
			if(x>((*ptrRaiz)->ptrDer)->dato)
				RSDD(&(*ptrRaiz));		//Rotación Simple Derecha Derecha
			else
				RDDI(&(*ptrRaiz));		//Rotación Doble Derecha Izquierda
		}
	}
	return *ptrRaiz;
}

int profAVL(NodoAVL *ptrRaiz){
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

NodoAVL* obtieneMasChico(NodoAVL *ptrRaiz){//Obtiene el left most de un nodo dado
	NodoAVL *nodoActual = ptrRaiz;
	while(nodoActual->ptrIzq!=NULL){
		nodoActual = nodoActual->ptrIzq;
	}
	return nodoActual;
}

int max(int a,int b){
	return (a>b) ? a:b;
}

void eliminaNodoAVL(NodoAVL **ptrRaiz,int dato){ 
	if((*ptrRaiz)->dato<dato){
		eliminaNodoAVL(&(*ptrRaiz)->ptrDer,dato);
	}else if((*ptrRaiz)->dato>dato){
		eliminaNodoAVL(&(*ptrRaiz)->ptrIzq,dato);
	}else{
		NodoAVL *temp = NULL;
		if((*ptrRaiz)->ptrDer == NULL || (*ptrRaiz)->ptrIzq == NULL){ //Caso de 0 o 1 hijo
			if((*ptrRaiz)->ptrDer == NULL && (*ptrRaiz)->ptrIzq == NULL){ //Caso de 0 hijos
				temp = (*ptrRaiz);
				(*ptrRaiz) = NULL;
			}else if((*ptrRaiz)->ptrDer == NULL){ //Caso de 1 hijo
				temp = (*ptrRaiz)->ptrIzq;
				(*(*ptrRaiz)) = *temp;
			}else if((*ptrRaiz)->ptrIzq == NULL){ //Caso de 1 hijo
				temp = (*ptrRaiz)->ptrDer;
				(*(*ptrRaiz)) = *temp;
			}
			free(temp);
		}else{
			printf("%s\n","Aber 2");
				//Obtenemos el leftmost del nodo derecho
	            NodoAVL* temp = obtieneMasChico((*ptrRaiz)->ptrDer);
	            printf("%s %d \n","Mas chico: ",temp);
	            //Copiamos el dato del leftmost a este nodo
	            (*ptrRaiz)->dato = temp->dato;
	            //Borramos, aunque ealmente lo que se hace es mover
	            eliminaNodoAVL(&(*ptrRaiz)->ptrDer, temp->dato);
		}
	}
	if((*ptrRaiz)!=NULL){
		/*Aqui esta el puto error*/
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
	else{
         printf("El arbol esta vacio");
         return;
         }
}

int FactorDeEquilibrio(NodoAVL *ptrRaiz){
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

void RSII(NodoAVL **ptrR1){
	NodoAVL *ptrAuxiliar = (*ptrR1)->ptrIzq;
	(*ptrR1)->ptrIzq=ptrAuxiliar->ptrDer;
	ptrAuxiliar->ptrDer=(*ptrR1);
	(*ptrR1)=ptrAuxiliar;
}

void RSDD(NodoAVL **ptrR1){
	NodoAVL *ptrAuxiliar = (*ptrR1)->ptrDer;
	(*ptrR1)->ptrDer=ptrAuxiliar->ptrIzq;
	ptrAuxiliar->ptrIzq=(*ptrR1);
	(*ptrR1)=ptrAuxiliar;
}

void RDID(NodoAVL **ptrR1){
	RSDD(&((*ptrR1)->ptrIzq));
	RSII(&(*ptrR1));
}

void RDDI(NodoAVL **ptrR1){
	RSII(&((*ptrR1)->ptrDer));
	RSDD(&(*ptrR1));
}

void recorridoPreOrden(NodoAVL *ptrRaiz){
	if(ptrRaiz!=NULL){
		printf("%d\n",ptrRaiz->dato);
		recorridoPreOrden(ptrRaiz->ptrIzq);
		recorridoPreOrden(ptrRaiz->ptrDer);
	}
}

void recorridoEnOrden(NodoAVL *ptrRaiz){
	if(ptrRaiz!=NULL){
		recorridoEnOrden(ptrRaiz->ptrIzq);
		printf("%d\n",ptrRaiz->dato);
		recorridoEnOrden(ptrRaiz->ptrDer);
	}
}

void recorridoPostOrden(NodoAVL *ptrRaiz){
	if(ptrRaiz!=NULL){
		recorridoPostOrden(ptrRaiz->ptrIzq);
		recorridoPostOrden(ptrRaiz->ptrDer);
		printf("%d\n",ptrRaiz->dato);
	}
}

void imprimirArbolAVL(NodoAVL *ptrRaiz, int contador){
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

void menu_principal(NodoAVL *ptrRaiz)
{
    int opcion,salir=0,miDato,nodosAIngresar,i,prof,datoABuscar,datoABorrar,contV=0;
    NodoAVL *ptrAux;
	printf("Bienvenido(a) al menu\n");
	do{
		printf("Selecciona una opcion\n");
		printf("1)Meter datos en el arbol\n");
		printf("2)Realizar el recorrido el PreOrden\n");
		printf("3)Realizar el recorrido el EnOrden\n");
		printf("4)Realizar el recorrido el PostOrden\n");
		printf("5)Ver la profundidad del arbol\n");
		printf("6)Borrar un dato\n");
		printf("7)Mostrar el arbol\n");
		printf("8)Salir\n");
		printf("\n");
		scanf("%d",&opcion);
		switch(opcion){
			case 1:
				printf("Ingresa el numero de datos que desees ingresar:\n");
				scanf("%d",&nodosAIngresar);
				for(i=0;i<nodosAIngresar;i++){
					printf("\nIngresa dato %d:\n",i+1);
					scanf("%d",&miDato);
					ptrAux=insertarAVL(&ptrRaiz,miDato);
					printf("\nDato %d ingresado\n\n",i+1);
					contV++;
				}
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
}

int main()
{
	NodoAVL *ptrRaiz;
	ptrRaiz=NULL;
	printf("ARBOL BUSQUEDA BINARIA\n");
	menu_principal(ptrRaiz);
	return 0;
}

