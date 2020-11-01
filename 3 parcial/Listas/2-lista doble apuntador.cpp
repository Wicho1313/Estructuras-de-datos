#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct nodo{
	int dato;
	struct nodo *ptrsig;
};

struct nodo * crearNodo (int dato){
	struct nodo *ptrAux;
	ptrAux=(struct nodo *) malloc(sizeof(struct nodo));
	ptrAux->dato=dato;
	ptrAux->ptrsig=NULL;
	return ptrAux;
}
void insertaOrden(struct nodo **ptrCab, int enter){
     struct nodo *nuevo;
     nuevo=crearNodo(enter);
     if((*ptrCab)->ptrsig==NULL)
     (*ptrCab)->ptrsig=nuevo;
     else if(enter<=(*ptrCab)->ptrsig->dato){
          nuevo->ptrsig=(*ptrCab)->ptrsig;
          (*ptrCab)->ptrsig=nuevo;
          }
     else{
             struct nodo *ptre,*ptra;
          ptra=(*ptrCab)->ptrsig;
          while((ptra->ptrsig!=NULL)&&(enter>ptra->dato)){
                  ptre=ptra;
                  ptra=ptra->ptrsig;
                  }
          if(enter>ptra->dato)
          ptre=ptra;
          nuevo->ptrsig=ptre->ptrsig;
          ptre->ptrsig=nuevo;
          }
     }
void recorrer(struct nodo ** ptrcima){
	
	struct nodo *ptrCabAux;
	ptrCabAux= (*ptrcima)->ptrsig;
            printf(" Lista ordenada:\n");  
	while(ptrCabAux!=NULL){     
	         
            printf(" %d ", ptrCabAux->dato);
            ptrCabAux=ptrCabAux->ptrsig;
            }
}
int busca(struct nodo **ptrCab, int dato1){
     if ((*ptrCab)->ptrsig==NULL){
                               printf("\nNo se encontro el dato\n");
                               return 0;
                               }
     else if((*ptrCab)->ptrsig->dato==dato1){
          printf("\n El numero %d encontrado\n",dato1);
          return 1;
          }
     else{
          return(busca(&(*ptrCab)->ptrsig,dato1));
          }
     }

     void sacar(int dato1, struct nodo **ptrCab){
     struct nodo *aux, *temp;
   aux=(*ptrCab);
   if(aux->ptrsig==NULL && aux->dato==dato1){
                        free(aux);
                        *ptrCab=NULL;
                        printf("dato borrado\n");
                        }
   else{
        if (aux->dato!=dato1 && aux->ptrsig==NULL){
                             printf("El dato no esta en la lista\n");
                             system ("pause");
                             }
        else {
        	
		if(aux->dato==dato1 && aux->ptrsig!=NULL){
                                 temp=aux->ptrsig;
                                 *ptrCab=temp;
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
printf ("\n 3.- Salir \n ");
scanf ("%d", &opc);
	return (opc);
}
int main()
{
	int dato;
	struct nodo *ptrc=crearNodo(-1);
	struct nodo **ptrc2;
	ptrc2=&ptrc;
	
	for (;;){
int opc=menu();
switch (opc){
	case 1:
		printf("\n Ingrese el dato: ");
		scanf("%d",&dato);
		insertaOrden(ptrc2,dato);
		recorrer(ptrc2);
    break;
	
	case 2:
         printf("Seleccione el dato: ");
         scanf("%d",&dato);  
        if(busca(ptrc2, dato)!=0) ;
          sacar(dato,ptrc2);
		recorrer(ptrc2);       
	break;
	
	case 3:
		exit(0);
	break;
	
				}
			}
			return 0;
}

