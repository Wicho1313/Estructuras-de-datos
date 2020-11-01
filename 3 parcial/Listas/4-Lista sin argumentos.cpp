#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct nodo{
	int dato;
	struct nodo *ptrsig;
}*ptrCab;
	
void insertaOrden(void){
	int enter;
		printf("\n Ingrese el dato: ");
		scanf("%d",&enter);	
     struct nodo *nuevo;
     nuevo=(struct nodo *) malloc(sizeof(struct nodo));
	nuevo->dato=enter;
    nuevo->ptrsig=NULL;
	 if(ptrCab->ptrsig==NULL)
     ptrCab->ptrsig=nuevo;
     else if(enter<=ptrCab->ptrsig->dato){
          nuevo->ptrsig=ptrCab->ptrsig;
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
          }
     }
void recorrer(void){
	
	struct nodo *ptrCabAux;
	ptrCabAux= ptrCab->ptrsig;
            printf(" Lista ordenada:\n");  
	while(ptrCabAux!=NULL){     
	         
            printf(" %d ", ptrCabAux->dato);
            ptrCabAux=ptrCabAux->ptrsig;
            }
}

     void sacar(void){
     	int dato1;
printf("Seleccione el dato a sacar: ");
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
                             printf("El dato no esta en la lista\n");
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
//La funcion buscar no se necesita en este programa ya que en la funcion de sacar
// ya se hace la busqueda del dato

/*void busca(void){
	int dato1;
printf("Seleccione el dato: ");
         scanf("%d",&dato1);
     if (ptrCab->ptrsig==NULL){
                               printf("\nNo se encontro el dato\n");
                               return;
                               }
     else {
         if(ptrCab->ptrsig->dato==dato1) 
		 printf("\n El numero %d encontrado\n",dato1);
    sacar();
          }
     }*/

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
struct nodo nodito;
ptrCab=&nodito;
ptrCab->dato=-1;
ptrCab->ptrsig=NULL;	
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
	
	case 3:
		exit(0);
	break;

	default:
		puts("Esta opcion no existe \n intenta con otra");
		break;
	
				}
			}
			return 0;
}

