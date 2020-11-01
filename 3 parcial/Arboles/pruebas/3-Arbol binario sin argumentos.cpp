#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct nodo{
       int dato;
       struct nodo *ptrDer;
       struct nodo *ptrIzq;
       };

struct nodo *ptrRaiz;
       
void insertar(void){
    int miDato1;
    printf("Ingrese entero: ");
      scanf("%d",&miDato1);
      struct nodo *ptrN;
       ptrN=(struct nodo*)malloc(sizeof(struct nodo));
       ptrN->dato=miDato1;
       ptrN->ptrDer=NULL;
       ptrN->ptrIzq=NULL;
     if(ptrRaiz==NULL){
          struct nodo *ptrN2;
       ptrN2=(struct nodo*)malloc(sizeof(struct nodo));
       ptrN2->dato=miDato1;
       ptrN2->ptrDer=NULL;
       ptrN2->ptrIzq=NULL;
          }
     else if(miDato1<ptrRaiz->dato){
          ptrRaiz->ptrIzq=miDato1;
          }
     else{
          ptrRaiz->ptrDer=miDato1;
          }
     }
void recorrerPunt(struct nodo *ptr, struct nodo *ptrH,struct nodo *ptrA){
     if(ptrH->ptrDer!=NULL){
          recorrerPunt(ptr,ptrH->ptrDer,ptrA);
          }
     else{
          ptr->dato=ptrH->dato;
          ptrA=ptrH;
          ptrH=ptrH->ptrIzq;
          }
     }
void eliminar(void){
     int clave;
       printf("Que dato quieres sacar? ");
       scanf("%d",&clave);
     if(ptrRaiz==NULL){
          printf("No esta en el arbol");
          }
     else if(clave<ptrRaiz->dato) {
                eliminar(ptrRaiz->ptrIzq, clave);
                }
     else if(clave>ptr->dato){
                eliminar(ptrRaiz->ptrDer, clave);
          }
     else {
          struct nodo *aux;
          aux=ptrRaiz;
          if (aux->ptrIzq==NULL){
                ptrRaiz=aux->ptrDer;
                }
          else if(aux->ptrDer==NULL){
               ptrRaiz=aux->ptrDer;
               }
          else{
               recorrerPunt(ptrRaiz,ptrRaiz->ptrIzq,aux);
               free(aux);
               }
          }
     }
void imprimirArbol(){
     int i,j,datoEnt;
     i=datoEnt=insertar();
     if(ptrRaiz!=NULL){
          imprimirArbol(ptrRaiz->ptrDer, i+1);
          printf("\n");
          for(j=1;j<i;j++)
                  printf("-");
                  printf("%d \n",ptrRaiz->dato);
                  imprimirArbol(ptrRaiz->ptrIzq,i+1);
          }
     }
int maxProfundidad(struct nodo *ptrRaiz){
    if(ptrRaiz!=NULL){
         int profIzq, profDer;
         profIzq=maxProfundidad(ptrRaiz->ptrIzq);
         profDer=maxProfundidad(ptrRaiz->ptrDer);
         
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
struct nodo * busca(void){
	int clave;
	printf("ingresa un valor para buscar: ");
		scanf("%d",&clave);
	if(ptr==NULL) {
	
	printf("No se encontro\n");
	}
else if(clave==ptr->dato)
	printf("Si esta en el arbol\n"); ;
else if(clave<ptr->dato)
return busca(ptr->ptrIzq,clave);
else
return busca(ptr->ptrDer,clave);
}
void in_orden(struct nodo *ptrRaiz){
          if(ptrRaiz==NULL) return;
          in_orden(ptrRaiz->ptrIzq); 
          printf(" %d ",ptrRaiz->dato);
          in_orden(ptrRaiz->ptrDer);
          }
void post_orden(struct nodo *ptrRaiz){
            if (ptrRaiz==NULL)return;
            post_orden(ptrRaiz->ptrIzq);
            post_orden(ptrRaiz->ptrDer);
          printf(" %d ",ptrRaiz->dato);
            }
void pre_orden(struct nodo *ptrRaiz){
            if(ptrRaiz==NULL)return;
          printf(" %d ",ptrRaiz->dato);
            pre_orden(ptrRaiz->ptrIzq);
            pre_orden(ptrRaiz->ptrDer);
            }
int main (){
 	
	int datoEnt, opc;	
    struct nodo * ptrCab, nodito;
	ptrCab=&nodito;
	ptrCab->ptrIzq=NULL;
	ptrCab->ptrDer=NULL;
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
            insertar();
      imprimirArbol();
      system("pause");
      system("cls");
		break;
		case 2:
       system("cls");
       printf("Que dato quieres sacar? ");
       scanf("%d",&datoEnt);
       eliminar(ptrCab,datoEnt); 
     imprimirArbol(ptrCab, datoEnt);
       system("pause");
      system("cls");
             break;
	case 3:
         system("cls");
	maxProfundidad(ptrCab);
	system("pause");
	system("cls");
		break;
		case 4:
             system("cls");
             imprimirArbol(ptrCab, datoEnt);
             printf("\n En in-orden: \n");
             in_orden(ptrCab);
       system("pause");
      system("cls");
		break;
		case 5: 
             system("cls");
             imprimirArbol();
                printf("\n En post-orden: \n");
             post_orden(ptrCab);
       system("pause");
      system("cls");
		break;
		case 6:
             system("cls");
             imprimirArbol();
                printf("\n En pre-orden: \n");
             pre_orden(ptrCab);
       system("pause");
      system("cls");
		break;
case 7:
      system("cls");
     imprimirArbol();
       system("pause");
     system("cls");
	break;
	case 8:
			busca();
	
		break;
    case 9:
         exit (0);
		break;
}
}while(opc!=9);	
}

