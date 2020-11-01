#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct nodo{
	int dato;
	struct nodo *ptrsig, *ptrant;
};

struct nodo * crearNodo (int dato){
	struct nodo *ptrAux;
	ptrAux=(struct nodo *) malloc(sizeof(struct nodo));
	ptrAux->dato=dato;
	ptrAux->ptrsig=NULL;
	ptrAux->ptrant=NULL;
	return ptrAux;
}
void insertaOrden(struct nodo *ptrCab, int enter){
     struct nodo *nuevo;
     nuevo=crearNodo(enter);
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
void recorrer(struct nodo * ptrcima){
	
	struct nodo *ptrCabAux;
	ptrCabAux= ptrcima->ptrsig;
            printf(" Lista ordenada ascendente:\n"); 
	while(ptrCabAux!=NULL){     
	         
            printf(" %d ", ptrCabAux->dato);
            ptrCabAux=ptrCabAux->ptrsig;
            }
}

void recorrer2(struct nodo * ptrcima){ 
	
	struct nodo *ptrCabAux;
	ptrCabAux= ptrcima->ptrsig;
            printf(" Lista ordenada descendente:\n"); 
           
		    while(ptrCabAux->ptrsig!=NULL)   
            ptrCabAux=ptrCabAux->ptrsig;   
      
	while(ptrCabAux!=NULL){     
	         
            printf(" %d ", ptrCabAux->dato);
            ptrCabAux=ptrCabAux->ptrant;  
            }
}


int busca(struct nodo *ptrCab, int dato1){
     if (ptrCab->ptrsig==NULL){
                               printf("\nNo se encontro el dato!!!\n");
                               return 0;
                               }
     else if(ptrCab->ptrsig->dato==dato1){
          printf("\n El numero %d encontrado\n",dato1);
          return 1;
          }
     else{
          return(busca(ptrCab->ptrsig,dato1));
          }
     }
void sacar(int dato1, struct nodo *ptrCab){
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
                                              printf("el dato no esta en la lista");
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
	struct nodo * ptrCab=crearNodo(-1);
	ptrCab->ptrsig=NULL;
	
	for (;;){
int opc=menu();
switch (opc){
	case 1:
		printf("\n Ingrese el dato: ");
		scanf("%d",&dato);
		insertaOrden(ptrCab,dato);
		recorrer(ptrCab);
    break;
	
	case 2:
         printf("Seleccione el dato: ");
         scanf("%d",&dato);
         if(busca(ptrCab, dato)!=0)
          sacar(dato,ptrCab);
		recorrer(ptrCab);       
	break;
	
	case 5:
		exit(0);
	break;
	
	case 3:
		recorrer(ptrCab);
		break;
	case 4:
		recorrer2(ptrCab);
		break;
	
	default:
		puts("Esta opcion no existe \n intenta con otra");
		break;
				}
			}
			return 0;
}
