#include<stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define IZQUIERDO 0
#define DERECHO 1
typedef struct _nodo{
        int dato;
        int FE;
        struct _nodo *derecho;
        struct _nodo *izquierdo;
        struct _nodo *padre;
 }tipoNodo;
        
typedef tipoNodo *pNodo;
typedef tipoNodo *Arbol;

/*void podar(Arbol *a){
     if(*a){
            podar(&(*a)->izquierdo);
            podar(&(*a)->derecho);
            free(*a);
            *a=NULL;
            }
     }*/

int Vacio(Arbol r){
 return r==NULL;   
}
int EsHoja(pNodo r){
 return !r->derecho && !r->izquierdo;   
}
void Mostrar(Arbol a, int contador){
     int i,j;
     i=contador;
     if(a!=NULL){
          Mostrar(a->derecho, i+1);
          printf("\n");
          for(j=1;j<i;j++)
                  printf("-");
                  printf("%d \n",a->dato);
                  Mostrar(a->izquierdo,i+1);
                  
          }
     }
void RDD(Arbol *raiz, Arbol nodo){
     pNodo Padre=nodo->padre;
     pNodo P=nodo;
     pNodo Q=P->izquierdo;
     pNodo R=Q->derecho;
     pNodo B=R->izquierdo;
     pNodo C=R->derecho;
     if(Padre)
              if(Padre->derecho==nodo) Padre->derecho=R;
              else Padre->izquierdo=R;
     else *raiz=R;
     Q->derecho=B;
     P->izquierdo=C;
     R->izquierdo=Q;
     R->derecho=P;
     
     R->padre=Padre;
     P->padre=Q->padre=R;
     if(B)B->padre=Q;
     if(C) C->padre=P;
     
     switch (R->FE){
            case -1: Q->FE=0; P->FE=1; break;
            case 0: Q->FE=0;P->FE=0; break;
            case 1: Q->FE=-1;P->FE=0; break;
            }
     R->FE=0;
     }
void RDI (Arbol *a, pNodo nodo){
     pNodo Padre=nodo->padre;
     pNodo P=nodo;
     pNodo Q=P->derecho;
     pNodo R=Q->izquierdo;
     pNodo B=R->izquierdo;
     pNodo C=R->derecho;
     if(Padre)
              if(Padre->derecho==nodo)Padre->derecho=R;
              else Padre->izquierdo=R;
     else *a=R;
     P->derecho=B;
     Q->izquierdo=C;
     R->izquierdo=P;
     R->derecho=Q;
     
     R->padre=Padre;
     P->padre=Q->padre=R;
     if(B) B->padre=P;
     if(C) C->padre=Q;
     
     switch(R->FE){
                   case -1:P->FE=0;Q->FE=1; break;
                   case 0: P->FE=0;Q->FE=0; break;
                   case 1: P->FE=1;Q->FE=0; break;
                   }
                   R->FE=0;
     }
void RSD (Arbol *a, pNodo nodo){
     pNodo Padre=nodo->padre;
     pNodo P=nodo;
     pNodo Q=P->izquierdo;
     pNodo B=Q->derecho;
     if(Padre)
              if(Padre->derecho==P)Padre->derecho=Q;
              else Padre->izquierdo=Q;
     else *a=Q;
     P->izquierdo=B;
     Q->derecho=P;
     
     P->padre=Q;
     if(B) B->padre=P;
     Q->padre=Padre;
     
     P->FE=0;
     Q->FE=0;
     }
     void RSI (Arbol *a ,pNodo nodo){
          pNodo Padre=nodo->padre;
          pNodo P=nodo;
          pNodo Q=P->derecho;
          pNodo B=Q->izquierdo;
          
          if(Padre)
                   if(Padre->derecho==P)Padre->derecho=Q;
                   else Padre->izquierdo=Q;
          else *a=Q;
          
          P->derecho=B;
          Q->izquierdo=P;
          
          P->padre=Q;
          if(B) B->padre=P;
          Q->padre=Padre;
          
          P->FE=0;
          Q->FE=0;
          }
void Equilibrar(Arbol *a, pNodo nodo, int rama,int nuevo){
     int salir=FALSE;
     while(nodo &&!salir){
                if(nuevo)
                  if(rama==IZQUIERDO)nodo->FE--;
                  else nodo->FE++;
                else 
                if(rama==IZQUIERDO) nodo->FE++;
                     else nodo->FE--;
               if(nodo->FE==-2){
                                if(nodo->izquierdo->FE==1)RDD(a,nodo);
                                else RSD(a,nodo);
                                salir=TRUE;
                                }
               else if(nodo->FE==2){
                    if(nodo->derecho->FE==-1)RDD(a,nodo);
                    else RSI(a,nodo);
                    salir=TRUE;
                    }
               if(nodo->padre)
                              if(nodo->padre->derecho==nodo)rama=DERECHO;
                              else rama=IZQUIERDO;
                              nodo=nodo->padre;               
                }
     }
void insertar (Arbol *a, int dat){
     pNodo padre=NULL;
     pNodo actual=*a;
     while(!Vacio(actual) && dat!=actual->dato){
                          padre=actual;
                          if(dat<actual->dato)actual=actual->izquierdo;
                          else if(dat>actual->dato)actual=actual->derecho;
                          }
    if(!Vacio(actual)) return;
     if(Vacio(padre)){
                      *a=(Arbol)malloc(sizeof(tipoNodo));
                      (*a)->dato=dat;
                      (*a)->izquierdo=(*a)->derecho=NULL;
                      (*a)->padre=NULL;
                      (*a)->FE=0;
                      }
    else if(dat<padre->dato){
         actual=(Arbol)malloc(sizeof(tipoNodo));
         padre->izquierdo=actual;
         actual->dato=dat;
         actual->izquierdo=actual->derecho=NULL;
         actual->padre=padre;
         actual->FE=0;
         Equilibrar(a,padre,IZQUIERDO, TRUE);
         } 
    else if(dat>padre->dato){
         actual=(Arbol)malloc(sizeof(tipoNodo));
         padre->derecho=actual;
         actual->dato=dat;
         actual->izquierdo=actual->derecho=NULL;
         actual->padre=padre;
         actual->FE=0;
         Equilibrar(a,padre, DERECHO,TRUE);
         }
     }
void Borrar(Arbol *a, int dat){
     pNodo padre=NULL;
     pNodo actual;
     pNodo nodo;
     int aux;
     actual=*a;
     
     while(!Vacio(actual)){
           if(dat==actual->dato){
            if (EsHoja(actual)){
              if(padre)
                if(padre->derecho==actual){
			Equilibrar(a,padre,DERECHO, FALSE);
			padre->derecho=NULL;
				}
                else if (padre->izquierdo==actual){
			Equilibrar(a,padre,IZQUIERDO, FALSE);
			padre->izquierdo=NULL;
                free (actual);
                actual=NULL;
                
				}
                if((padre->derecho==actual &&padre->FE==1) || (padre->izquierdo==actual && padre->FE==-1)){
                                           padre->FE=0;
                                           actual=padre;
                                           padre=actual->padre;
                                           
                           }
                if(padre)
                    if(padre->derecho==actual) Equilibrar(a,padre,DERECHO, FALSE);
                    else Equilibrar(a,padre,IZQUIERDO,FALSE);
                    return;
                    }
              else{
                   padre=actual;
                   if(actual->derecho){
                                       nodo=actual->derecho;
                                       while (nodo->izquierdo){
                                             padre=nodo;
                                             nodo=nodo->izquierdo;
                                             }
                                             }
              else{
                   nodo=actual->izquierdo;
                   while(nodo->derecho){
                                        padre=nodo;
                                        nodo=nodo->derecho;
                                        }
                                        }
                 aux=actual->dato;
                 actual->dato=nodo->dato;
                 nodo->dato=aux;
                 actual=nodo;
                 }
                 }
                 else{
                      padre=actual;
                      if(dat>actual->dato)actual=actual->derecho;
                      else if(dat<actual->dato)actual=actual->izquierdo;
                      }
                      }
                      }              
 void in_orden(Arbol a){
          if(a==NULL) return;
          in_orden(a->izquierdo); 
          printf(" %d ",a->dato);
          in_orden(a->derecho);
          }
void post_orden(Arbol a){
            if (a==NULL)return;
            post_orden(a->izquierdo);
            post_orden(a->derecho);
          printf(" %d ",a->dato);
            }
void pre_orden(Arbol a){
            if(a==NULL)return;
          printf(" %d ",a->dato);
            pre_orden(a->izquierdo);
            pre_orden(a->derecho);
            }
 int Buscar(Arbol a, int dat){
     pNodo actual=a;
     while(!Vacio(actual)){
                           if(dat==actual->dato){
                           printf("Dato encontrado");
                           return TRUE;}
                           else if(dat<actual->dato)actual=actual->izquierdo;
                           else if(dat>actual->dato)actual=actual->derecho;
                           }
                        printf("No está en el arbol");
                        return FALSE;   
     }
int Altura(Arbol a, int dat){
         int altura=0;
         pNodo actual=a;
         while(!Vacio(actual)){
                               if(dat==actual->dato)return altura;
                               else{
                                    altura++;
                                    if(dat<actual->dato)actual=actual->izquierdo;
                                    else if(dat>actual->dato)actual=actual->derecho;
         }
         }
         printf("No esta en el arbol");
         return -1;
         }
void auxContador(Arbol nodo, int *c){
     (*c)++;
     if(nodo->izquierdo)auxContador(nodo->izquierdo,c);
     if(nodo->derecho) auxContador(nodo->derecho,c);
     }
void auxAltura(pNodo nodo, int a, int *altura){
     if(nodo->izquierdo)auxAltura(nodo->izquierdo,a+1,altura);
     if(nodo->derecho)auxAltura(nodo->derecho,a+1,altura);
     if(EsHoja(nodo)&&a>*altura) *altura=a;
     }
     int AlturaArbol(Arbol a, int *altura){
         *altura=0;
         auxAltura(a,0,altura);
         return *altura;
         }
int numeroNodos(Arbol a, int *contador){
 *contador=0;
 auxContador(a,contador);
 return *contador;   
}
int main()
{
    int opc, datoEnt;
    Arbol ArbolInt=NULL;
    
	do 
	{
	  fflush(stdin);
	  printf ("\n 1.- Meter en el Arbol \n ");
	  printf ("\n 2.- sacar del Arbol \n ");
	  printf ("\n 3.- Maxima profundidad del Arbol \n ");
	  printf ("\n 4.- Imprimir en in-orden el Arbol \n ");
	  printf ("\n 5.- Imprimir en post-orden el Arbol \n ");
	  printf ("\n 6.- Imprimir en pre-orden el Arbol \n ");
	  printf ("\n 7.- Visualizar Arbol \n ");
	  printf ("\n 8.- Buscar un dato \n ");
	  printf ("\n 9.- Salir \nOpcion?:  ");
	  scanf ("%d", &opc);
	
	  switch (opc)
	  {
	   case 1:
      	system("cls");
      	printf("Ingrese entero: ");
      	scanf("%d",&datoEnt);
      	insertar(&ArbolInt,datoEnt);
      	Mostrar(ArbolInt,0);
          printf("\nEntero agregado\n");
      	system("pause");
      	system("cls");
		break;
		
	   case 2:
       	system("cls");
       	printf("Que dato quieres sacar? ");
       	scanf("%d",&datoEnt);
       	Borrar(&ArbolInt,datoEnt); 
       	Mostrar(ArbolInt,0);
       	system("pause");
       	system("cls");
      	break;
	
	   case 3:
        system("cls");
		printf("Altura del arbol %d\n",AlturaArbol(ArbolInt,&datoEnt));
		system("pause");
		system("cls");
		break;
		
		
	   case 4:
		system("cls");
			Mostrar(ArbolInt,0);
			printf("\n En in-orden: \n");
      	    in_orden(ArbolInt);
    	system("pause");
      	system("cls");
		break;
		
	   case 5: 
        system("cls");
      	Mostrar(ArbolInt,0);
    	 printf("\n En post-orden: \n");
		 post_orden(ArbolInt);
       	system("pause");
      	system("cls");
		break;
		
	   case 6:
        system("cls");
		Mostrar(ArbolInt,0);
        printf("\n En pre-orden: \n");
        pre_orden(ArbolInt);
       	system("pause");
      	system("cls");
		break;
	  
	  case 7:
      	system("cls");
     	Mostrar(ArbolInt,0);
       	system("pause");
     	system("cls");
		break;
		
	   case 8:
		printf("ingresa un valor para buscar: ");
		scanf("%d",&datoEnt);
		Buscar(ArbolInt,datoEnt);
		break;
    
	   case 9:
        exit (0);
		break;
	  }
	} 
	while(opc!=9);	


}



