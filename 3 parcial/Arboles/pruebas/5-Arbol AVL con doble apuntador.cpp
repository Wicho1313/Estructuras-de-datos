#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct nodo{
       int dato;
       int bal;
       struct nodo *ptrDer;
       struct nodo *ptrIzq;
       };

struct nodo *crearnodo(int dato1){
       struct nodo *ptrN;
       ptrN=(struct nodo*)malloc(sizeof(struct nodo));
       ptrN->dato=dato1;
       ptrN->ptrDer=NULL;
       ptrN->ptrIzq=NULL;
       return ptrN;
       }
int altura(struct nodo **ptr){
	if(*ptr==NULL)
	return 0;
	else
	return ((*ptr)->bal);
}
int maximo(int a, int b){
	if (a>b)
	return a;
	else
	return b;
}
void calculaAltura(struct nodo **p){
	(*p)->bal=1+maximo(altura(&(*p)->ptrIzq),altura(&(*p)->ptrDer));
}
struct nodo *rotaIzq(struct nodo **ptr){
	struct nodo *temp;
	temp=(*ptr)->ptrDer;
	(*ptr)->ptrDer=temp->ptrIzq;
	temp->ptrIzq=(*ptr);
	calculaAltura(&(*ptr));
	calculaAltura(&temp);
	return temp;
}
struct nodo *rotaDer(struct nodo **ptr){
	struct nodo *temp;
	temp=(*ptr)->ptrIzq;
	(*ptr)->ptrIzq=temp->ptrDer;
	temp->ptrDer=(*ptr);
	calculaAltura(&(*ptr));
	calculaAltura(&temp);
	return temp;
}
       struct nodo *balancear(struct nodo **ptr){
	calculaAltura(&(*ptr));
	if(altura(&(*ptr)->ptrIzq)-altura(&(*ptr)->ptrDer)==2){
		printf("Se rota\n");
		if(altura(&(*ptr)->ptrIzq->ptrDer)> altura(&(*ptr)->ptrIzq->ptrIzq)){
			(*ptr)->ptrIzq=rotaIzq(&(*ptr)->ptrIzq);
			return rotaDer(&(*ptr));
		}
	}
	else if(altura(&(*ptr)->ptrDer)-altura(&(*ptr)->ptrIzq)==2){
		printf("se rota\n");
		if(altura(&(*ptr)->ptrDer->ptrIzq)>altura(&(*ptr)->ptrDer->ptrDer)){
			(*ptr)->ptrDer=rotaDer(&(*ptr)->ptrDer);
			return rotaIzq(&(*ptr));
		}
	}
	printf("\n %d",(*ptr)->bal);
	return (*ptr);
	
}
struct nodo * insertar(struct nodo **ptrRaiz, int miDato1){
     if(*ptrRaiz==NULL){
          return crearnodo(miDato1);
          }
     else if(miDato1<(*ptrRaiz)->dato){
          (*ptrRaiz)->ptrIzq=insertar(&((*ptrRaiz)->ptrIzq),miDato1);      
          }
     else if(miDato1>(*ptrRaiz)->dato ){
          (*ptrRaiz)->ptrDer=insertar(&((*ptrRaiz)->ptrDer),miDato1);
          }
     else
	 (*ptrRaiz)->dato=miDato1;
	 return balancear(&(*ptrRaiz));
     }
void recorrerPunt(struct nodo **ptr, struct nodo **ptrH,struct nodo *ptrA){
     if((*ptrH)->ptrDer!=NULL){
          recorrerPunt(ptr,&(*ptrH)->ptrDer,ptrA);
          }
     else{
          (*ptr)->dato=(*ptrH)->dato;
          ptrA=(*ptrH);
          *ptrH=(*ptrH)->ptrIzq;
          }
     }
struct nodo * eliminar(struct nodo **ptr, int clave){
     if(*ptr==NULL){
          printf("No esta en el arbol");
          }
     else if(clave<(*ptr)->dato) {
               eliminar(&(*ptr)->ptrIzq, clave);
                }
     else if(clave>(*ptr)->dato){
                eliminar(&(*ptr)->ptrDer, clave);
          }
     else {
          struct nodo *aux;
          aux=(*ptr);
          if (aux->ptrIzq==NULL){
                (*ptr)=aux->ptrDer;
                }
          else if(aux->ptrDer==NULL){
               (*ptr)=aux->ptrDer;
               }
          else{
               recorrerPunt(ptr,&(*ptr)->ptrIzq,aux);
               free(aux);
               }
          }
          	(*ptr)->dato=clave;
          	balancear(&(*ptr));
     }
void imprimirArbol(struct nodo **ptrRaiz, int contador){
     int i,j;
     i=contador;
     if(*ptrRaiz!=NULL){
          imprimirArbol(&(*ptrRaiz)->ptrDer, i+1);
          printf("\n");
          for(j=1;j<i;j++)
                  printf("-");
                  printf("%d \n",(*ptrRaiz)->dato);
                  imprimirArbol(&(*ptrRaiz)->ptrIzq,i+1);               
          }
     }
int maxProfundidad(struct nodo **ptrRaiz){
    if(*ptrRaiz!=NULL){
         int profIzq, profDer;
         profIzq=maxProfundidad(&(*ptrRaiz)->ptrIzq);
         profDer=maxProfundidad(&(*ptrRaiz)->ptrDer);
         
       if (profIzq>profDer){
             return(profIzq+1);
             }         
    else{
         return (profDer+1);
         }
}
else
return 0;
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
void in_orden(struct nodo **ptrRaiz){
          if(*ptrRaiz==NULL) return;
          in_orden(&(*ptrRaiz)->ptrIzq); 
          printf(" %d ",(*ptrRaiz)->dato);
          in_orden(&(*ptrRaiz)->ptrDer);
          }
void post_orden(struct nodo **ptrRaiz){
            if (*ptrRaiz==NULL)return;
            post_orden(&(*ptrRaiz)->ptrIzq);
            post_orden(&(*ptrRaiz)->ptrDer);
          printf(" %d ",(*ptrRaiz)->dato);
            }
void pre_orden(struct nodo **ptrRaiz){
            if(*ptrRaiz==NULL)return;
          printf(" %d ",(*ptrRaiz)->dato);
            pre_orden(&(*ptrRaiz)->ptrIzq);
            pre_orden(&(*ptrRaiz)->ptrDer);
            }


int main (){
 	
	int datoEnt, opc;
	struct nodo *ptrc=NULL;
	struct nodo **ptrc2;
	ptrc2=&ptrc;
 
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
printf ("\n 9.- Verificar si es hoja \n ");
printf ("\n 10.- Salir \n ");
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
	maxProfundidad(ptrc2);
	system("pause");
	system("cls");
		break;
		case 4:
             system("cls");
             imprimirArbol(ptrc2, datoEnt);
             printf("\n En in-orden: \n");
             in_orden(ptrc2);
       system("pause");
      system("cls");
		break;
		case 5: 
             system("cls");
             imprimirArbol(ptrc2, datoEnt);
                printf("\n En post-orden: \n");
             post_orden(ptrc2);
       system("pause");
      system("cls");
		break;
		case 6:
             system("cls");
             imprimirArbol(ptrc2, datoEnt);
                printf("\n En pre-orden: \n");
             pre_orden(ptrc2);
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
			//if(eshoja(ptrc2)==1)
		//	printf("El dato es hoja");
		//	else 
		//	printf("no es hoja");
		//	break;
    case 10:
         exit (0);
		break;
}
}while(opc!=10);	
}
