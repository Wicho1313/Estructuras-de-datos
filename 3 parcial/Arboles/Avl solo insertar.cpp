#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct Nodoa {
	int dato;
	struct Nodoa *izq;
	struct Nodoa *der;
} *Avl;

Avl nuevoa () { return NULL; }

int esnuevoa (Avl a) { return a == NULL; }

int raiz (Avl a) { return a->dato; }
Avl derecho (Avl a) { return a->der; }
Avl izquierdo (Avl a) { return a->izq; }

Avl consa (int dato, Avl i, Avl d) {
	Avl t;
	t = (Avl) malloc (sizeof (struct Nodoa));
	t->dato = dato;
	t->der = d;
	t->izq = i;

	return t;	
}

int eshoja (Avl a) {
	if (a->der == NULL && a->izq == NULL)
		return 1;
	return 0;
}

int maximo (int a, int b) {
	if (a > b)
		return a;
	return b;
}

int altura (Avl a) {
	if (a == NULL)
		return 0;
	else if (eshoja (a))
		return 1;
	else if (derecho (a) == NULL){
		return 1 + altura (izquierdo (a));
	} else if (izquierdo (a) == NULL){
		return 1 + altura (derecho (a));
	} else {
		return 1 + maximo (altura (derecho (a)), altura (izquierdo (a)));
	}
}

Avl equilibra (Avl a) {
	return a;
	int d, i, r;
	if (a == NULL)
		return nuevoa ();
	else {
		d = altura (derecho (a));
		i = altura (izquierdo (a));
		r = d - i;
		if (r == 0 || r == 1 || r == -1){
			return consa (raiz (a), equilibra (izquierdo (a)), equilibra (derecho (a)));
		} else if (d > i) {
			return consa (raiz (derecho (a)), consa (raiz (a), izquierdo (a), izquierdo (derecho(a))), derecho (derecho (a)));
		} else if (i > d)
			return consa (raiz (izquierdo (a)), izquierdo (izquierdo (a)), consa (raiz (a), derecho (izquierdo (a)), derecho (a)));
	}
}

Avl agrega (int dato, Avl a) {
	Avl t;
	if (a == NULL) {
		t = (Avl) malloc (sizeof (struct Nodoa));
		t->dato = dato;
		t->der=NULL;
		t->izq=NULL;
		return t;
	}
	
	if (altura (derecho (a)) > altura (izquierdo (a))){
		return equilibra (consa (dato, consa (raiz(a), izquierdo (a), nuevoa()), derecho (a)));
	} else
		return equilibra (consa (dato, izquierdo (a), consa (raiz (a), nuevoa (), derecho(a))));
	
}

int impavl (Avl a) {
	if (eshoja (a)){
		printf ("hoja: %d, ", raiz (a));
		return 0;
	} else if (derecho (a) == NULL) {
		printf (" izquierdo: %d, ", raiz (a));
		impavl (izquierdo (a));
	} else if (izquierdo (a) == NULL) {
		impavl (derecho (a));
		printf ("derecho: %d ", raiz (a));
	} else {
		impavl (derecho(a));
		printf ("<- %d -> ", raiz (a));
		impavl (izquierdo (a));
	}
}
void imprimirArbol(Avl a, int contador){
     int i,j;
     i=contador;
     if(a!=NULL){
          imprimirArbol(derecho(a), i+1);
          printf("\n");
          for(j=1;j<i;j++)
                  printf("-");
                  printf("%d \n",raiz(a));
                  imprimirArbol(izquierdo(a),i+1);
                  
          }
     }
/**
Avl insertavl (FILE *ptrF) {
	Avl a = nuevoa ();
	char temp[10];
	char c;
	int i = 0;
	
	inicializar (temp);
	
	while (!feof (ptrF)) {
		if (esnum (c = getc(ptrF))) {
			temp[i] = c;
			i++;
		} else if (c == ','){
			a = agrega(atoi (temp), a);
			i = 0;
			inicializar (temp);
		} else
			continue;
	}
	a = agrega (atoi(temp), a);
	return a;
}
*/


int maxProfundidad(Avl a){
    if(esnuevoa(a)!=NULL){
         int profIzq, profDer;
         profIzq=maxProfundidad(izquierdo(a));
         profDer=maxProfundidad(derecho(a));
         
       if (profIzq>profDer){
             return(profIzq+1);
             }         
    else{
         return (profDer+1);
         }
}
else
return 0;
}
int buscavl (Avl a, int num) {
	if (eshoja (a)){
		if (raiz(a) == num)
			return 1;
		else
			return 1;
	} else if (derecho (a) == NULL) {
		if (raiz (a) == num)
			return 1;
		else
			return 1 + buscavl (izquierdo (a), num);
	} else if (izquierdo (a) == NULL) {
		if (raiz (a) == num)
			return 1;
		else
			return 1 + buscavl (derecho (a), num);
	} else {
		return 1 + buscavl (derecho(a), num) + buscavl (izquierdo (a), num);
	}
}
void recorrerPunt(Avl ptr, Avl ptrH,Avl ptrA){
     if(ptrH->der!=NULL){
          recorrerPunt(ptr,ptrH->der,ptrA);
          }
     else{
          ptr->dato=ptrH->dato;
          ptrA=ptrH;
          ptrH=ptrH->izq;
          }
     }
void eliminar(Avl a, int clave){
     if(a==NULL){
          printf("No esta en el arbol");
          }
     else if(clave<raiz(a)) {
                eliminar(izquierdo(a), clave);
                }
     else if(clave>raiz(a)){
                eliminar(derecho(a), clave);
          }
     else {
         
          if (izquierdo(a)==NULL){
                a=derecho(a);
                }
          else if(derecho(a)==NULL){
               a=derecho(a);
               }
          else{
               recorrerPunt(a,izquierdo(a),a);
             
               }
          }
     }
void in_orden(Avl a){
          if(a==NULL) return;
          in_orden(izquierdo(a)); 
          printf(" %d ",raiz(a));
          in_orden(derecho(a));
          }
void post_orden(Avl a){
            if (a==NULL)return;
            post_orden(izquierdo(a));
            post_orden(derecho(a));
          printf(" %d ",raiz(a));
            }
void pre_orden(Avl a){
            if(a==NULL)return;
          printf(" %d ",raiz(a));
            pre_orden(izquierdo(a));
            pre_orden(derecho(a));
            }
            
//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------            
//----------------------------------------------------------------------------------------------            
int main()
{
    int opc, datoEnt;
    Avl a=nuevoa();
    
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
      	a=agrega(datoEnt,a);
      	impavl(a);
      	imprimirArbol(a,datoEnt);
          printf("\nEntero agregado\n");
      	system("pause");
      	system("cls");
		break;
		
	   case 2:
       	system("cls");
       	printf("Que dato quieres sacar? ");
       	scanf("%d",&datoEnt);
       	eliminar(a,datoEnt); 
       	impavl(a);
       	system("pause");
       	system("cls");
      	break;
	
	   case 3:
        system("cls");
		maxProfundidad(a);
		system("pause");
		system("cls");
		break;
		
		
	   case 4:
		system("cls");
		impavl(a);
		printf("\n En in-orden: \n");
    	in_orden(a);
    	system("pause");
      	system("cls");
		break;
		
	   case 5: 
        system("cls");
        impavl(a);
        printf("\n En post-orden: \n");
        post_orden(a);
       	system("pause");
      	system("cls");
		break;
		
	   case 6:
        system("cls");
        impavl(a);
        printf("\n En pre-orden: \n");
        pre_orden(a);
       	system("pause");
      	system("cls");
		break;
	  
	  case 7:
      	system("cls");
     	impavl(a);
       	system("pause");
     	system("cls");
		break;
		
	   case 8:
		printf("ingresa un valor para buscar: ");
		scanf("%d",&datoEnt);
		if(buscavl(a,datoEnt)!=NULL)
		printf("\n Si esta en el arbol\n");
		else
		printf("\n No se encontro \n ");
		break;
    
	   case 9:
        exit (0);
		break;
	  }
	} 
	while(opc!=9);	


}



