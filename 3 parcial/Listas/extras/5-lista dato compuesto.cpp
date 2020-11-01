#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
struct nodo{
	int boleta;
	char nombre[20];
	char sexo;
	float estatura;
	struct nodo *ptrsig;
};

struct nodo * crearNodo ( int boleta2, float est2, char nombre[20],char sex2){
	struct nodo *ptrAux;
	ptrAux=(struct nodo *) malloc(sizeof(struct nodo));
	strcpy(ptrAux->nombre, nombre);
	ptrAux->boleta=boleta2;
	ptrAux->estatura=est2;
	ptrAux->sexo=sex2;
	ptrAux->ptrsig=NULL;
	return ptrAux;
}
void insertaOrden(struct nodo *ptrCab, int boleta2, float est2, char nombre[20],char sex2){
     struct nodo *nuevo;
     nuevo=crearNodo(boleta2, est2, nombre, sex2);
     if(ptrCab==NULL)
     ptrCab=nuevo;
     else if((boleta2<ptrCab->boleta) && (est2<ptrCab->estatura) && (nombre<ptrCab->nombre) && (sex2<ptrCab->sexo)){
          nuevo->ptrsig=ptrCab;
          ptrCab=nuevo;
          }
     else{
          struct nodo *anterior,*p;
          anterior=p=ptrCab;
          while((p->ptrsig!=NULL) && (boleta2>p->boleta) && (est2>p->estatura) && (nombre>p->nombre) && (sex2>p->sexo)){
                  anterior=p;
                  p=p->ptrsig;
                  }
          if((boleta2>p->boleta) && (nombre>p->nombre))
          anterior=p;
          nuevo->ptrsig=anterior->ptrsig;
          anterior->ptrsig=nuevo;
          }
     }

void recorrer(struct nodo * ptrcima){
	
	struct nodo *ptrCabAux;
	ptrCabAux= ptrcima;
            printf(" Lista ordenada:\n"); 
	ptrCabAux=ptrCabAux->ptrsig; 
	while(ptrCabAux!=NULL){     
	         
            printf(" \nboleta: %d \n",ptrCabAux->boleta);
                    printf(" \nestatura: %f \n",ptrCabAux->estatura);
                    printf(" \nsexo: %c \n",ptrCabAux->sexo);
                    printf(" \nnombre: %s \n",ptrCabAux->nombre);
            ptrCabAux=ptrCabAux->ptrsig;
            }
}
int busca(struct nodo *ptrCab, int dato1){
     if (ptrCab->ptrsig==NULL){
                               printf("\nSe borro el primer dato de la lista\n");
                               printf("Ahora la lista esta vacia\n");
                               return 0;
                               }
     else if(ptrCab->boleta==dato1){
          printf("\n la boleta %d encontrada\n",dato1);
          return dato1;
          }
     else{
          return(1+busca(ptrCab->ptrsig,dato1));
          }
     }

     void sacar(int boleta2, struct nodo *ptrCab){
     struct nodo *aux, *temp;
   aux=ptrCab;
   if(aux->ptrsig==NULL && aux->boleta==boleta2){
                        free(aux);
                        ptrCab=NULL;
                        printf("dato borrado\n");
                        }
   else{
        if (aux->boleta!=boleta2 && aux->ptrsig==NULL){
                             printf("el dato no esta en la lista\n");
                             system ("pause");
                             }
        else {
        	
		if(aux->boleta==boleta2 && aux->ptrsig!=NULL){
                                 temp=aux->ptrsig;
                                 ptrCab=temp;
                                 free (aux);
                                 printf("dato borrado\n");
                                 }
                
        else {
             while (1){
                   if (aux->ptrsig->boleta==boleta2){
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
printf ("\n 1.- Meter en lista \n ");
printf ("\n 2.- sacar de la lista \n ");
printf ("\n 3.- Salir \n ");
scanf ("%d", &opc);
	return (opc);
}
int main()
{
	int boleta3;
	float est3;
	char nombre[20];
	char sex3;
struct nodo * ptrCab, nodito;
	ptrCab=&nodito;
	ptrCab->ptrsig=NULL;
	
	for (;;){
int opc=menu();
switch (opc){
	case 1:
		fflush(stdin);
		printf("Ingrese boleta: ");
		scanf("%d",&boleta3);
				fflush(stdin);
                printf("Ingrese est: ");
		scanf("%f",&est3);
				fflush(stdin);
			printf("ingresa nombre: ");
		gets(nombre);
				fflush(stdin);
		
	    printf("ingrese sexo: ");
	    scanf("%c",&sex3);
		insertaOrden(ptrCab,boleta3, est3, nombre, sex3);
		recorrer(ptrCab);
    break;
	
	case 2:
         printf("\nSolo puede sacar de la lista por numero de boleta\n");
         printf("Seleccione el dato: ");
         scanf("%d",&boleta3);
         busca(ptrCab, boleta3);
         system("pause");
          sacar(boleta3,ptrCab);
		recorrer(ptrCab);       
	break;
	
	case 3:
		exit(0);
	break;
	
				}
			}
			return 0;
}

