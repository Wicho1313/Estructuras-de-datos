#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
struct nodo{
	int bl;
	char name[20];
	char sex;
	float tamu;
	struct nodo *ptrSig, *ptrs;
	int error=-1;
}Nodaso, *ptrCab;

struct nodo * crearNodo ( int bl2, float tamu2, char namer[20],char sex2){
	struct nodo *ptrAux;
	ptrAux=(struct nodo *) malloc(sizeof(struct nodo));
	strcpy(ptrAux->name, namer);
	ptrAux->bl=bl2;
	ptrAux->tamu=tamu2;
	ptrAux->sex=sex2;
	ptrAux->ptrSig=NULL;
	return ptrAux;
}


void insertaOrden(struct nodo *ptrCab, int bl2, float tamu2, char nombre[20],char sex2){
     struct nodo *nuevo;
     nuevo=crearNodo(bl2, tamu2, nombre, sex2);
     int c=(ptrCab->ptrs)->name[0];
     int a=nombre[0];
     if(ptrCab->ptrs==NULL)
     ptrCab->ptrs=nuevo;
     else {if(a<c){
          nuevo->ptrSig=ptrCab->ptrs;
          ptrCab->ptrs=nuevo;
          }
     else{
          struct nodo *anter ,*p;
          anter=p=ptrCab->ptrs;
          int w=p->name[0];
          while((p->ptrSig!=NULL) && (a>w)){
                  anter=p;
                  p=p->ptrSig;
                  }
          if(a>w)
          anter=p;
          nuevo->ptrSig=anter->ptrSig;
          anter->ptrSig=nuevo;
          }
         } }
     
     
     
     
void recorrer(struct nodo *ptrCab){
     int k;
     printf("\nLista ordenada: ");
     for(k=0;ptrCab->ptrs!=NULL;(ptrCab->ptrs)=(ptrCab->ptrs->ptrSig)){
                    printf(" \nboleta: %d \n",ptrCab->ptrs->bl);
                    printf("\nnombre:");
                    puts(ptrCab->ptrs->name);
                    printf(" \nestatura: %f \n",ptrCab->ptrs->tamu);
                    printf(" \nsexo: %c \n",ptrCab->ptrs->sex); 
                    k++;   
					printf("---------------------\n\n");                    
                                           }
     
     }
int busca(struct nodo *ptrCab, int dato1){
     if (ptrCab->ptrs->ptrSig==NULL){
                               printf("\nSe borro el primer dato de la lista\n");
                               printf("Ahora la lista esta vacia\n");
                               return 0;
                               }
     else if(ptrCab->ptrs->bl==dato1){
          printf("\n la boleta %d encontrada\n",dato1);
          return dato1;
          }
     else{
          return(1+busca(ptrCab->ptrs->ptrSig,dato1));
          }
     }

void sacar(int bl2, struct nodo *ptrCab){
     struct nodo *Aux, *Temp;
   Aux=ptrCab->ptrs;
   if(Aux->ptrSig==NULL && Aux->bl==bl2){
                        free(Aux);
                        ptrCab->ptrs=NULL;
                        printf("dato borrado\n");
                        }
   else{
        if (Aux->bl!=bl2 && Aux->ptrSig==NULL){
                             printf("el dato no esta en la lista\n");
                             system ("pause");
                             }
        else {
        	
		if(Aux->bl==bl2 && Aux->ptrSig!=NULL){
                                 Temp=Aux->ptrSig;
                                 ptrCab->ptrs=Temp;
                                 free (Aux);
                                 printf("dato borrado\n");
                                 }
                
        else {
             while (1){
                   if (Aux->ptrSig->bl==bl2){
                                            Temp=Aux->ptrSig;
                                            Aux->ptrSig=Temp->ptrSig;
                                            printf("dato borrado");
                                            free (Temp);
                                            break;
                    }
                   else{
                        Aux=Aux->ptrSig;
                        if(Aux->ptrSig==NULL){
                                              printf("el dato no esta en la lista");
                                              
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
	ptrCab=&Nodaso;
	int bl3;
	float tamu3;
	char names[20];
	char sex3;
	ptrCab->ptrs=NULL;
	
	for (;;){
int opc=menu();
switch (opc){
	case 1:
		fflush(stdin);
		printf("Ingrese boleta: ");
		scanf("%d",&bl3);
        printf("Ingrese est: ");
		scanf("%f",&tamu3);
		fflush(stdin);
		printf("ingresa nombre: ");
		gets(names);
			fflush(stdin);
	    printf("ingrese sexo: ");
	    scanf("%c",&sex3);
	    fflush(stdin);
		insertaOrden(ptrCab,bl3, tamu3, names, sex3);
		recorrer(ptrCab);
    break;
	
	case 2:
         printf("\nSolo puede sacar de la lista por numero de boleta\n");
         printf("Seleccione el dato: ");
         scanf("%d",&bl3);
         busca(ptrCab, bl3);
         system("pause");
          sacar(bl3,ptrCab);
		recorrer(ptrCab);       
	break;
	case 3:
		exit(0);
	break;
	
				}
			}
			return 0;
}

