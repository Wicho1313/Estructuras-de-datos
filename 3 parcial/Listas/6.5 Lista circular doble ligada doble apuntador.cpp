#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <stdbool.h>

struct nodo{
	int dato;
	struct nodo *ptrsig;
	struct nodo *ptrant;
};
struct nodo *crearNodo (int dato){
	struct nodo *ptrAux;
	ptrAux=(struct nodo *) malloc(sizeof(struct nodo));
	ptrAux->dato=dato;
	ptrAux->ptrsig=NULL;
	ptrAux->ptrant=NULL;
	return ptrAux;
}
bool Vacia(struct nodo **ptrini){	
	return *ptrini==NULL;
}
void imprimir(struct nodo **ptrinicio,struct nodo **fin, int posi){
	system("cls");
	struct nodo *aux;
	int band=0;
	int cont=1;
	struct nodo *aux2;
	if(Vacia(&(*ptrinicio))==1){
		printf("\nLISTA VACIA\n");
		return;	
	}
	else{
		printf("\nImprime a partir de un nodo \n",posi);
		for(aux=*ptrinicio;aux->ptrsig!=*ptrinicio;aux=aux->ptrsig){
			if(cont==posi){
				for(aux2=aux;aux2->ptrsig!=aux;aux2=aux2->ptrsig){
					printf(" %d ",aux2->dato);
					band++;
				}
				printf(" %d ",aux->ptrant->dato);
					
			}
			else
				cont++;
				if(band!=0){
				return;	
				}
			
		}
		printf("\nPosicion fuera de rango\n");
	}
}

void insertaOrden(struct nodo **ptrini,struct nodo **ptrfinal ,int enter){
     struct nodo *nuevo;
     nuevo=crearNodo(enter);
     if(*ptrini==NULL){
     	*ptrini=nuevo;
     	(*ptrini)->ptrsig=*ptrini; //apunta al el mismo
		(*ptrini)->ptrant=*ptrini; //circular
     	*ptrfinal=nuevo;
	 }
     
     else if(enter<=(*ptrini)->dato){
          nuevo->ptrsig=*ptrini;
          (*ptrini)->ptrant=nuevo;
          *ptrini=nuevo;
          (*ptrfinal)->ptrsig=*ptrini;   //el final apunta al inicio
          (*ptrini)->ptrant=*ptrfinal;   //el inicio al final
          }
     else{
        struct nodo *ptre,*ptra;
        ptra=*ptrini;
          while((ptra->ptrsig!=*ptrini)&&(enter>ptra->dato)){
                  ptre=ptra;
                  ptra=ptra->ptrsig;
            }
          if(enter>ptra->dato){
          	ptre=ptra;
          	nuevo->ptrsig=ptre->ptrsig;//como enter es mayor puntero final al inicio 
          	ptre->ptrsig=nuevo;
          	(*ptrini)->ptrant=nuevo; //puntero del inicio al final puesto que es mayor 
          	nuevo->ptrant=ptre;
          	*ptrfinal=nuevo;
		  }
		  else{
			nuevo->ptrsig=ptre->ptrsig; //circular
          	ptre->ptrsig=nuevo;
          	ptra->ptrant=nuevo;
          	nuevo->ptrant=ptre;
		  }
          
        }
}
int busca(struct nodo **ptrini, struct nodo **ptrfin,int dato1){
     if(Vacia(&(*ptrini))==1){
     	printf("\nLista Vacia\n");
	 }
	 else if ((*ptrini)->ptrsig==*ptrfin){
                               printf("\nNo se encontro el dato!!!\n");
                               return 0;
                               }
     else if((*ptrini)->ptrsig->dato==dato1){
          printf("\n El numero %d encontrado\n",dato1);
          return 1;
          }
     else{
          return(busca(&(*ptrini)->ptrsig,&(*ptrfin)->ptrant,dato1));
          }
     }
void sacar(int dato1, struct nodo **ptrIni, struct nodo **ptrfin){
   struct nodo *aux, *temp;
   aux=*ptrIni;	
   if(*ptrIni==NULL){
   	printf("No esta el dato");
   }
 else if(aux==*ptrIni && aux->dato==dato1 && aux->ptrsig==*ptrIni){
        free(aux);
        *ptrIni=NULL;
        *ptrfin=NULL;
        printf("Dato borrado\n");
        return;
    }
   else{
        if (aux->dato!=dato1 && aux->ptrsig==*ptrIni){
            printf("El dato no esta en la lista\n");
            system ("pause");
            return;
       }
	else {
		if(aux->dato==dato1 && aux->ptrsig!=NULL){
        	temp=aux->ptrsig;
            *ptrIni=temp;
            (*ptrfin)->ptrsig=*ptrIni;
            (*ptrIni)->ptrant=*ptrfin;
            free (aux);
            printf("Dato borrado\n");
            return;
        }
                
    else {
        while (1){
            if (aux->ptrsig->dato==dato1){
                temp=aux->ptrsig;
                aux->ptrsig=temp->ptrsig;
                temp->ptrsig->ptrant=aux;
                printf("Dato borrado");
                if(aux->ptrsig==*ptrIni && aux->ptrant==*ptrIni) *ptrfin=*ptrIni;
                free (temp);
                break;
            }
        	else{
                aux=aux->ptrsig;
                	if(aux==*ptrIni){
                    printf("El dato no esta en la lista");
                    return;
                }
            }
        }
    }
}
}
}

void mostrarDeFinAInicio(struct nodo **ptrfin,struct nodo **inicio){
	system("cls");
	struct nodo *ptrAux;
	int i=0;
	if(Vacia(&(*inicio))==1){
		printf("\nLISTA VACIA\n");
		return;
	}
	else{	
		
		printf("\nImprime del final al inicio\n");
		for(ptrAux=*ptrfin;ptrAux!=*inicio;ptrAux=ptrAux->ptrant){
		printf(" %d ",ptrAux->dato);
	}
	}
	
	printf(" %d ",(*inicio)->dato);
}

void sacarinicio(struct nodo **ptrfin,struct nodo **inicio){

	struct nodo *ptrAux;
	system("cls");
	printf("\nEliminar dato al inicio\n");
if(Vacia(&(*inicio))==1){
		printf("\nLISTA VACIA\n");
		return;	
	}
	else if(*inicio==*ptrfin){
		printf("\nSe elimino el ultimo nodo: %d\n",(*inicio)->dato);
		free(*inicio);
		*inicio=NULL;
		*ptrfin=NULL;
	}
	else{
		ptrAux=*inicio;
		*inicio=(*inicio)->ptrsig;
		(*inicio)->ptrant=*ptrfin;
		(*ptrfin)->ptrsig=*inicio;
		
		printf("\nSe elimino el dato inicial: %d\n",ptrAux->dato);
		free(ptrAux);
	}
	system("pause");
}

void sacarfinal(struct nodo **ptrfin,struct nodo **inicio){	
	system("cls");
	struct nodo *ptrAux;
	printf("\nEliminar ultimo elemento\n");
	
if(Vacia(&(*inicio))==1){
		printf("\nLISTA VACIA\n");
		return;	
	}
	
	else if(*inicio==*ptrfin){
		printf("\nSe elimino el ultimo nodo: %d\n",(*inicio)->dato);
		free(*inicio);
		*inicio=NULL;
		*ptrfin=NULL;
	}
	else{
		ptrAux=*ptrfin;
		*ptrfin=(*ptrfin)->ptrant;
		(*ptrfin)->ptrsig=*inicio;
		(*inicio)->ptrant=*ptrfin;
		printf("\nSe elimino nodo:%d\n",ptrAux->dato);
		free(ptrAux);
	}
	system("pause");
}

void recorrer(struct nodo **ptrini,struct nodo **ptrfin){
	int cont=0;
	struct nodo *ptrCabAux;
	ptrCabAux= *ptrini;
	if(Vacia(&(*ptrini))==1){
		printf("\nLISTA VACIA\n");
		return;	
	}
	else{

            printf("\nLista circular: ");   
do{
      if(ptrCabAux==*ptrfin)
      cont=1;
            printf(" %d ", ptrCabAux->dato);
            if(ptrCabAux!=*ptrfin)
            ptrCabAux=ptrCabAux->ptrsig;
            
            }	while(ptrCabAux!=*ptrfin||cont==0);
}
}


int main(){
    int dato;
    int option;
    struct nodo *ptrini2=NULL;
    struct nodo *ptrfinal2=NULL;
	struct nodo **ptrini;	
	struct nodo **ptrfinal;
	ptrini=&ptrini2;
	ptrfinal=&ptrfinal2;	
    
    while(1){
        do
	{
		printf("\n1.-Meter un dato \n");
		printf("\n2.-Sacar un dato intermedio  \n");
		printf("\n3.-Sacar el dato final\n");
		printf("\n4.-Scar el dato inicial\n");
		printf("\n5.-Imprimir lista circular de inicio a fin \n");
		printf("\n6.-Imprimir lista circular del final a inicio		\n");
		printf("\n7.-Imprimir a partir de un nodo  \n");
		printf("\n8.-SALIR	\n");
        printf("\nElija opcion: ");
		scanf("%d", &option);
		switch(option)
		{
			case 1:
				printf("\nIntroduzca un dato:");
				scanf("%d",&dato);
				insertaOrden(ptrini,ptrfinal,dato);
		recorrer(ptrini, ptrfinal);	
			break;
			
			case 2:	
				printf("\nIntroduzca el dato a eliminar:");
				scanf("%d",&dato);
				if(busca(ptrini,ptrfinal, dato)!=0){
				sacar(dato,ptrini,ptrfinal);
				recorrer(ptrini, ptrfinal);		
				}
				else{
					printf("\nEl dato no esta\n");
				}
			break;
			
			case 3:
				sacarfinal(ptrfinal, ptrini);
				recorrer(ptrini, ptrfinal);	
				break;
			
			case 4:
				sacarinicio(ptrfinal,ptrini);
					recorrer(ptrini, ptrfinal);	
				break;
			case 5: 
			recorrer(ptrini, ptrfinal);
			break;
			case 6: 
			mostrarDeFinAInicio(ptrfinal,ptrini);
			break;
			case 7:
			printf("\n Ingrese el nodo desde el cual quiere imprimir: ");
			scanf("%d",&dato);
				imprimir(ptrini,ptrfinal,dato);
				break;
			case 8: exit(0);
			break;
			default:
				printf("\nOpcion Invalida\nIngrese otra \n");
				break;
		}
        
        
    } while(option!=8);
}


return 0;
}



