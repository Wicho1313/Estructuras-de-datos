#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct nodo{
	int dato;
	struct nodo *ptrsig, *ptrant;
};
struct nodo *ptrCab;

void insertaOrden(void){
	int enter;
	printf("\n Ingrese el dato: ");
		scanf("%d",&enter);
     struct nodo *nuevo;
     nuevo=(struct nodo *) malloc(sizeof(struct nodo));
	nuevo->dato=enter;
	nuevo->ptrsig=NULL;
	nuevo->ptrant=NULL;
     if(ptrCab->ptrsig==NULL)
     ptrCab->ptrsig=nuevo;
     else if(enter<=ptrCab->ptrsig->dato){
          nuevo->ptrsig=ptrCab->ptrsig;
          ptrCab->ptrsig->ptrant=nuevo; 
          ptrCab->ptrsig=nuevo;
          }
     else{
             struct nodo *ptre,*ptra;
          ptra=ptrCab->ptrsig;
          while((ptra->ptrsig!=NULL)&&(enter>ptra->dato)){
                  ptre=ptra;
                  ptra=ptra->ptrsig;
                  }
          if(enter>ptra->dato)
          ptre=ptra;
          nuevo->ptrsig=ptre->ptrsig;
          ptre->ptrsig=nuevo;
          nuevo->ptrant=ptre; 
           nuevo->ptrsig->ptrant=nuevo;
          }
     }
void recorrer(void){
	
	struct nodo *ptrCabAux;
	ptrCabAux= ptrCab->ptrsig;
            printf(" \nLista ordenada ascendente:\n"); 
	while(ptrCabAux!=NULL){     
	         
            printf(" %d ", ptrCabAux->dato);
            ptrCabAux=ptrCabAux->ptrsig;
            }
}

void recorrer2(void){ 
	
	struct nodo *ptrCabAux;
	ptrCabAux= ptrCab->ptrsig;
            printf(" \nLista ordenada descendente:\n"); 
           
		    while(ptrCabAux->ptrsig!=NULL)   
            ptrCabAux=ptrCabAux->ptrsig;   
      
	while(ptrCabAux!=NULL){     
	         
            printf(" %d ", ptrCabAux->dato);
            ptrCabAux=ptrCabAux->ptrant;  
            }
}

void sacar(void){
	int dato1;
	 printf("Seleccione el dato: ");
         scanf("%d",&dato1);
     struct nodo *aux, *temp;
   aux=ptrCab;
   if(aux->ptrsig==NULL && aux->dato==dato1){
                        free(aux);
                        ptrCab=NULL;
                        printf("dato borrado\n");
                        }
   else{
        if (aux->dato!=dato1 && aux->ptrsig==NULL){
                             printf("el dato no esta en la lista\n");
                             system ("pause");
                             }
        else {
        	
		if(aux->dato==dato1 && aux->ptrsig!=NULL){
                                 temp=aux->ptrsig;
                                 ptrCab=temp;
                                 free (aux);
                                 printf("dato borrado\n");
                                 }
                
        else {
             while (1){
                   if (aux->ptrsig->dato==dato1){
                                                 temp=aux->ptrsig;
                                                 aux->ptrsig=temp->ptrsig;
                                                 printf("dato borrado");
                                                 free (temp);
                                               break;
                                                 }
                   else{
                        aux=aux->ptrsig;
                        if(aux->ptrsig==NULL){
                                              printf("el dato no esta en la lista\n");
                                              return;
                                              }
                                              }
                      }
                  }
            }
        }
    }
int menu(){
	int opc;
	fflush(stdin);
printf ("\n 1.- Meter en lista \n ");
printf ("\n 2.- sacar de la lista \n ");
printf ("\n 3.- Imprimir lista ascendente \n ");   
printf ("\n 4.- Imprimir lista Descendente \n ");  
printf ("\n 5.- Salir \n ");
scanf ("%d", &opc);
	return (opc);
}
int main()
{
	int dato;
struct nodo nodito;
ptrCab=&nodito;
ptrCab->dato=-1;
ptrCab->ptrsig=NULL;
ptrCab->ptrant=NULL;
	
	for (;;){
int opc=menu();
switch (opc){
	case 1:
		insertaOrden();
		recorrer();
    break;
	
	case 2:
          sacar();
		recorrer();       
	break;
	
	case 5:
		exit(0);
	break;
	
	case 3:
		recorrer();
		break;
	case 4:
		recorrer2();
		break;
	
	default:
		puts("Esta opcion no existe \n intenta con otra");
		break;
				}
			}
			return 0;
}
