#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct nodo{
	int dato;
	struct nodo *ptrsig;
    struct nodo *ptrant;
};

struct nodo * crearNodo (int dato){
	struct nodo *ptrAux;
	ptrAux=(struct nodo *) malloc(sizeof(struct nodo));
	ptrAux->dato=dato;
	ptrAux->ptrsig=ptrAux->ptrsig;
	ptrAux->ptrant=NULL;
	return ptrAux;
}

void insertar(struct nodo *ptrCab, int entrada){
     struct nodo *nuevo;
     nuevo=crearNodo(entrada);
     if( ptrCab==NULL)
       ptrCab=nuevo;
    else {
    nuevo->ptrsig=ptrCab->ptrsig;
	ptrCab->ptrsig=nuevo;	
    
	}
     }
void recorrer(struct nodo * ptrcima){
	
	struct nodo *ptrCabAux;
	ptrCabAux= ptrcima;
	ptrCabAux=ptrcima->ptrsig;
            printf("\nLista circular no ordenada: "); 
	while(ptrCabAux!=NULL){               
            printf(" %d ", ptrCabAux->dato);
            ptrCabAux=ptrCabAux->ptrsig;
            }
}

  void sacar(int dato1, struct nodo *ptrCab){
     struct nodo *aux, *temp;
   aux=ptrCab;
   if(aux->ptrsig==NULL && aux->dato==dato1){
                        free(aux);
                        ptrCab=NULL;
                        printf("\ndato borrado\n");
                        }
   else{
        if (aux->dato!=dato1 && aux->ptrsig==NULL){
                             printf("\nEl dato no esta en la lista\n");
                             }
        else {
        	
		if(aux->dato==dato1 && aux->ptrsig!=NULL){
                                 temp=aux->ptrsig;
                                 ptrCab=temp;
                                 free (aux);
                                 printf("\ndato borrado\n");
                                 }
                
        else {
             while (1){
                   if (aux->ptrsig->dato==dato1){
                                                 temp=aux->ptrsig;
                                                 aux->ptrsig=temp->ptrsig;
                                                 printf("\ndato borrado\n");
                                                 free (temp);
                                               break;
                                                 }
                   else{
                        aux=aux->ptrsig;
                        if(aux->ptrsig==NULL){
                                              printf("\nel dato no esta en la lista\n");
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

printf ("\n 1.- Meter en lista \n ");
printf ("\n 2.- sacar de la lista \n ");
printf ("\n 3.- Salir \n ");
scanf ("%d", &opc);
	return (opc);
}
int main()
{
	int dato;
	struct nodo * ptrCab=crearNodo(-1);
	ptrCab->ptrsig=NULL;
	ptrCab->ptrant=NULL;
	for (;;){
int opc=menu();
switch (opc){
	case 1:
		printf("\n Ingrese el dato: ");
		scanf("%d",&dato);
insertar	(ptrCab,dato);
		recorrer(ptrCab);
    break;
	
	case 2:
         printf("Seleccione el dato: ");
         scanf("%d",&dato);
         sacar(dato,ptrCab);   
		recorrer(ptrCab);       
	break;
	
	case 3:
		exit(0);
	break;
	
				}
			}
			return 0;
}
