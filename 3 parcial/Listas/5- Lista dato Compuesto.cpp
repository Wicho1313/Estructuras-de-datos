#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

struct nodo{
	int dato;
	float tamu;
	char name[20];
	char sex;
	struct nodo *ptrsig;
};

int comparar(char namae1[20], char namae2[20]){
	int i;
	for(i=0; namae1[i]==namae2[i]; i++);
	if(namae1[i]<namae2[i])
	return 1;
	else
	return 0;
	
}

struct nodo * crearNodo (int dato, char namae[20], float tamu2, char sex2){
	struct nodo *ptrAux;
	ptrAux=(struct nodo *) malloc(sizeof(struct nodo));
	ptrAux->dato=dato;
	strcpy(ptrAux->name,namae);
	ptrAux->sex=sex2;
	ptrAux->tamu=tamu2;
	ptrAux->ptrsig=NULL;
	return ptrAux;
}
void insertaOrden(struct nodo *ptrCab, int enter, char namae[20], float tamu2, char sex2){
     struct nodo *nuevo;
     nuevo=crearNodo(enter, namae, tamu2, sex2);
     if(ptrCab->ptrsig==NULL)
     ptrCab->ptrsig=nuevo;
     else {
	 if(comparar(namae, ptrCab->ptrsig->name)==1){
          nuevo->ptrsig=ptrCab->ptrsig;
          ptrCab->ptrsig=nuevo;
          }
     else{
             struct nodo *ptre,*ptra;
          ptra=ptrCab->ptrsig;
          while((ptra->ptrsig!=NULL)&&(comparar(namae, ptra->name)==0)){
                  ptre=ptra;
                  ptra=ptra->ptrsig;
                  }
          if(comparar(namae, ptra->name)==0)
          ptre=ptra;
          nuevo->ptrsig=ptre->ptrsig;
          ptre->ptrsig=nuevo;
        }
      }
    }
void recorrer(struct nodo * ptrcima){
	
	struct nodo *ptrCabAux;
	ptrCabAux= ptrcima->ptrsig;
            printf("\n\n Lista ordenada:\n\n");  
	while(ptrCabAux!=NULL){     
	         
            printf("Boleta: %d \n", ptrCabAux->dato);
            printf("Nombre:");
            puts(ptrCabAux->name);
            printf("Estatura: %.2f\n",ptrCabAux->tamu);
            printf("Sexo: %c\n", ptrCabAux->sex);
            puts("----------");
            ptrCabAux=ptrCabAux->ptrsig;
            }
}
int busca(struct nodo *ptrCab, int dato1){
     if (ptrCab->ptrsig==NULL){
                               printf("\nNo se encontro el dato\n");
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

int busca2(struct nodo *ptrCab, int dato1){
     if (ptrCab->ptrsig==NULL){
        return 0;
        }
     else if(ptrCab->ptrsig->dato==dato1){
          printf("\n El numero %d ya existe!!\n",dato1);
          puts("Escribe otra Boleta!!");
          return 1;
          }
     else{
          return(busca2(ptrCab->ptrsig,dato1));
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
printf ("\n 1.- Meter en lista (Orden Alfabetico)\n ");
printf ("\n 2.- sacar de la lista (Por Num.Boleta)\n ");
printf ("\n 3.- Salir \n ");
scanf ("%d", &opc);
	return (opc);
}
int main()
{
	int dato;
	char nombre[20];
	float tamu3;
	char sex3;
	struct nodo Nodito, *ptrCab;
	ptrCab=&Nodito;
	ptrCab->dato=-1;
	ptrCab->ptrsig=NULL;
	
	for (;;){
int opc=menu();
switch (opc){
	case 1:
		puts("Numero de Boleta:");
		scanf("%d",&dato);
		while(busca2(ptrCab, dato)==1)
			scanf("%d", &dato);
		fflush(stdin);
		puts("Nombre:");
		gets(nombre);
		puts("estatura:");
		scanf("%f", &tamu3);
		fflush(stdin);
		puts("sexo:");
		scanf("%c", &sex3);
		insertaOrden(ptrCab,dato, nombre, tamu3, sex3);
		recorrer(ptrCab);
    break;
	
	case 2:
         printf("Seleccione el dato: ");
         scanf("%d",&dato);
         if(busca(ptrCab, dato)!=0)
          sacar(dato,ptrCab);
		recorrer(ptrCab);       
	break;
	
	case 3:
		exit(0);
	break;
	
	default:
    	puts("Esta opcion no Existe intenta con otra\n");
	break;
				}
			}
			return 0;
    
    	
}

