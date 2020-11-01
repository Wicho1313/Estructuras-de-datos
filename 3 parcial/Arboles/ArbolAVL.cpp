#include <stdio.h>
#include <stdlib.h>
 struct nodo
{
    int dato;
    int FE;
    struct nodo *ptrIzq, *ptrDer;
};
struct nodo *nuevoNodo(int dato1){
       struct nodo *ptrN;
       ptrN=(struct nodo *)malloc(sizeof(struct nodo));
       ptrN->dato=dato1;
       ptrN->ptrIzq=NULL;
	   ptrN->ptrDer=NULL;
	   ptrN->FE=0;
	return ptrN;
}
void RSII(struct nodo **ptr){
	struct nodo *ptrAuxiliar = (*ptr)->ptrIzq;
	(*ptr)->ptrIzq=ptrAuxiliar->ptrDer;
	ptrAuxiliar->ptrDer=(*ptr);
	(*ptr)=ptrAuxiliar;
}

void RSDD(struct nodo **ptr){
	struct nodo *ptrAuxiliar = (*ptr)->ptrDer;
	(*ptr)->ptrDer=ptrAuxiliar->ptrIzq;
	ptrAuxiliar->ptrIzq=(*ptr);
	(*ptr)=ptrAuxiliar;
}

void RDID(struct nodo **ptr){
	RSDD(&((*ptr)->ptrIzq));
	RSII(&(*ptr));
}

void RDDI(struct nodo **ptr){
	RSII(&((*ptr)->ptrDer));
	RSDD(&(*ptr));
}

int profundidad(struct nodo **ptrRaiz){
    int profI, profD;
    if(*ptrRaiz==NULL)
        return 0;
    else{
        profI=profundidad(&(*ptrRaiz)->ptrIzq);
        profD=profundidad(&(*ptrRaiz)->ptrDer);
        if(profI>profD)
            return profI+1;
        else
            return profD+1;
    }
}

struct nodo * insertar(struct nodo **ptrRaiz, int dato1){
	if(*ptrRaiz==NULL)	
		*ptrRaiz = nuevoNodo(dato1);
	else if((*ptrRaiz)->dato>dato1){
		insertar(&(*ptrRaiz)->ptrIzq,dato1);
		if(profundidad(&(*ptrRaiz)->ptrIzq)-profundidad(&(*ptrRaiz)->ptrDer)==2){															
			if(dato1<((*ptrRaiz)->ptrIzq)->dato)	
				RSII(&(*ptrRaiz));
			else
				RDID(&(*ptrRaiz));		
		}
	}
	else if(dato1>(*ptrRaiz)->dato){
		insertar(&((*ptrRaiz)->ptrDer),dato1);	
		if(profundidad(&(*ptrRaiz)->ptrDer)-profundidad(&(*ptrRaiz)->ptrIzq)==2){
			if(dato1>((*ptrRaiz)->ptrDer)->dato)
				RSDD(&(*ptrRaiz));	
			else
				RDDI(&(*ptrRaiz));		
		}
	}
	return *ptrRaiz;
}
struct nodo* obtieneMasIzq(struct nodo **ptrRaiz){
	struct nodo *nodoActual = *ptrRaiz;
	while(nodoActual->ptrIzq!=NULL){
		nodoActual = nodoActual->ptrIzq;
	}
	return nodoActual;
}
int max(int a,int b){
	return (a>b) ? a:b;
}
int Equilibrar(struct nodo **ptrRaiz){
	if(*ptrRaiz!=NULL){
		(*ptrRaiz)->FE=profundidad(&(*ptrRaiz)->ptrDer)-profundidad(&(*ptrRaiz)->ptrIzq);
		return (*ptrRaiz)->FE;
	}else
		return 0;
}

void eliminar(struct nodo **ptrRaiz,int dato){ 
	if(*ptrRaiz==NULL){
          printf("\nNo esta en el arbol\n");
          return;
          }
    else if((*ptrRaiz)->dato<dato){
		eliminar(&(*ptrRaiz)->ptrDer,dato);
	}else if((*ptrRaiz)->dato>dato){
		eliminar(&(*ptrRaiz)->ptrIzq,dato);
	}else{
		struct nodo *temp = NULL;
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
				
	            struct nodo* temp = obtieneMasIzq(&(*ptrRaiz)->ptrDer);
	            (*ptrRaiz)->dato = temp->dato;
	            eliminar(&(*ptrRaiz)->ptrDer, temp->dato);
		}
	}
	if((*ptrRaiz)!=NULL){
	    int ER = Equilibrar(&(*ptrRaiz));
	 	int EI = Equilibrar(&(*ptrRaiz)->ptrIzq);
	 	int ED = Equilibrar(&(*ptrRaiz)->ptrDer);
	 	
	    if (ER > 1 && EI >= 0){
	    	printf("%s\n","Rota RSDD");
	    	RSDD(&(*ptrRaiz));
	    }

	    if ( ER> 1  && EI< 0){
	        printf("%s\n","Rota RDDI");
	    	RDDI(&(*ptrRaiz));
	    }

	    if (ER < -1 && ED <= 0){
	    	printf("%s\n","Rota RSII");
	    	RSII(&(*ptrRaiz));
	    }
	        
	    if (ER < -1 && ED > 0){
	   		printf("%s\n","Rota RDID");
	        RDID(&(*ptrRaiz));
	    }
	    
	}
	else{
	printf("\nNo esta en el arbol\n");
	return;
}
}
void PreOrden(struct nodo **ptrRaiz){
	if(*ptrRaiz!=NULL){
		printf("%d\n",(*ptrRaiz)->dato);
		PreOrden(&(*ptrRaiz)->ptrIzq);
		PreOrden(&(*ptrRaiz)->ptrDer);
	}
}

void EnOrden(struct nodo **ptrRaiz){
	if(*ptrRaiz!=NULL){
		EnOrden(&(*ptrRaiz)->ptrIzq);
		printf("%d\n",(*ptrRaiz)->dato);
		EnOrden(&(*ptrRaiz)->ptrDer);
	}
}

void PostOrden(struct nodo **ptrRaiz){
	if(*ptrRaiz!=NULL){
        PostOrden(&(*ptrRaiz)->ptrIzq);
		PostOrden(&(*ptrRaiz)->ptrDer);
		printf("%d\n",(*ptrRaiz)->dato);
	}
}
struct nodo * busca(struct nodo **ptr, int clave){
	if(*ptr==NULL) 
	return NULL;
else if(clave==(*ptr)->dato)
return (*ptr);
else if(clave<(*ptr)->dato)
return busca(&(*ptr)->ptrIzq,clave);
else
return busca(&(*ptr)->ptrDer,clave);
}
void imprimirArbol(struct nodo **ptrRaiz, int contador){
	int i, j;
	i = contador;
	if(*ptrRaiz!=NULL){
		imprimirArbol(&(*ptrRaiz)->ptrDer,i+1);
		printf("\n");
		for(j=1;j<i;j++){
			printf(" - ");
			
		}	
		printf(" %d ",(*ptrRaiz)->dato);		
		imprimirArbol(&(*ptrRaiz)->ptrIzq,i+1);
	}
}
int main(){
 int opc,salir=0,datoEnt,nodosAIngresar,i,prof,datoABuscar,datoABorrar,contV=0;
	struct nodo *ptrc=NULL;
	struct nodo **ptrc2;
	ptrc2=&ptrc;
	printf("Bienvenido(a) al menu\n");
	do{
	fflush(stdin);
printf ("\n 1.- Meter en el Arbol \n ");
printf ("\n 2.- sacar del Arbol \n ");
printf ("\n 3.- Maxima profundidad del Arbol \n ");
printf ("\n 4.- Imprimir en in-orden el Arbol \n ");
printf ("\n 5.- Imprimir en post-orden el Arbol \n ");
printf ("\n 6.- Imprimir en pre-orden el Arbol \n ");
printf ("\n 7.- Visualizar Arbol \n ");
printf ("\n 8.- Buscar un dato \n ");
printf ("\n 9.- Salir \n ");
scanf ("%d", &opc);
switch (opc){
	case 1:
      system("cls");
      printf("Ingrese entero: ");
      scanf("%d",&datoEnt);
      insertar(ptrc2, datoEnt);
      imprimirArbol(ptrc2, datoEnt);
      system("pause");
      system("cls");
		break;
		case 2:
       system("cls");
       printf("Que dato quieres sacar? ");
       scanf("%d",&datoEnt);
       eliminar(ptrc2,datoEnt); 
     imprimirArbol(ptrc2, datoEnt);
       system("pause");
      system("cls");
             break;
	case 3:
         system("cls");
	profundidad(ptrc2);
	system("pause");
	system("cls");
		break;
		case 4:
             system("cls");
             imprimirArbol(ptrc2, datoEnt);
             printf("\n En in-orden: \n");
             EnOrden(ptrc2);
       system("pause");
      system("cls");
		break;
		case 5: 
             system("cls");
             imprimirArbol(ptrc2, datoEnt);
                printf("\n En post-orden: \n");
             PostOrden(ptrc2);
       system("pause");
      system("cls");
		break;
		case 6:
             system("cls");
             imprimirArbol(ptrc2, datoEnt);
                printf("\n En pre-orden: \n");
             PreOrden(ptrc2);
       system("pause");
      system("cls");
		break;
case 7:
      system("cls");
     imprimirArbol(ptrc2, datoEnt);
       system("pause");
     system("cls");
	break;
	case 8:
		printf("ingresa un valor para buscar: ");
		scanf("%d",&datoEnt);
	if(busca(ptrc2,datoEnt)!=NULL)
	printf("\n Si esta en el arbol\n");
	else
	printf("\n No se encontro \n ");
		break;
    case 9:
         exit (0);
		break;
}
}while(opc!=9);	
}

