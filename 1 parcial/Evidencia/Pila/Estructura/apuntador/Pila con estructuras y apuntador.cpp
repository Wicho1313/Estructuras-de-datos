#include<conio.h>
#include<stdio.h>
#include <string.h>

#define TAM 3
void meterpila(struct pila *ptrpila, struct nodo *ptrdato);
void sacarpila(struct pila *ptrpila, struct nodo *ptrdato);
int pilallena(struct pila *ptrpila);
int pilavacia(struct pila *ptrpila);
struct nodo{
char nombre [10];
int edad;
float est;
char sexo;
};
struct pila{
	struct nodo arreglo [3];
		struct nodo *ptrcima;
};
void meterpila(struct pila *ptrpila, struct nodo *ptrdato)
{
	strcpy(ptrpila->ptrcima->nombre, ptrdato->nombre);
	ptrpila->ptrcima->edad=ptrdato->edad;
	ptrpila->ptrcima->est=ptrdato->est;
	ptrpila->ptrcima->sexo=ptrdato->sexo;
	printf("\n Ingresa dato \n %s %d %f %c",ptrpila->ptrcima->nombre, ptrpila->ptrcima->edad, ptrpila->ptrcima->est,ptrpila->ptrcima->sexo);
	ptrpila->ptrcima++;
}
void sacarpila(struct pila *ptrpila, struct nodo *ptrdato){
	ptrpila->ptrcima--;
	strcpy(ptrdato->nombre, ptrpila->ptrcima->nombre);
	ptrdato->edad=ptrpila->ptrcima->edad;
	ptrdato->est=ptrpila->ptrcima->est;
	ptrdato->sexo=ptrpila->ptrcima->sexo;
}
int pilallena(struct pila *ptrpila){
	if(ptrpila->ptrcima==&ptrpila->arreglo[TAM]){
	return 1;
	}
	else{
		return 0;}
}
int pilavacia(struct pila *ptrpila){
	if (ptrpila->ptrcima==ptrpila->arreglo){
return 1;}
	else {
	return 0;}
	}
int menu(){
	int opc;
	fflush(stdin);
	
printf ("\n 1.- Meter pila \n ");
printf ("\n 2.- sacar pila \n ");
printf ("\n 3.- salir \n ");
scanf ("%d", &opc);
	return (opc);
}
int main()
{
	int opc;
	struct pila mipila;
	struct pila *miptrpila;
	miptrpila=&mipila;
	miptrpila->ptrcima=miptrpila->arreglo;
	struct nodo midato, *miptrdato;
	miptrdato=&midato;
for (;;){
int opc=menu();
switch (opc){

		case 1:
		    if (pilallena(miptrpila)!=1)
		    {
		    	fflush(stdin);
		    	printf("\n Ingrese nombre: \n");
		    	gets(miptrdato->nombre);
		    	fflush(stdin);
		    	printf("\n Ingrese edad: \n");
		    	scanf("%d", &miptrdato->edad);
		    	fflush(stdin);
		    	printf("\n Ingrese estatura: \n");
		    	scanf("%f", &miptrdato->est);
		    	fflush(stdin);
		    	printf("\n Ingrese sexo: \n");
		    	scanf("%c", &miptrdato->sexo);
		    	fflush(stdin);
		    	meterpila(miptrpila, miptrdato);
			}
			else{
				printf("\n La pila está llena \n" );
				getchar();
			}
		     break;
		case 2:
		    if (pilavacia(miptrpila)!=1)
		    {
		    	sacarpila (miptrpila, miptrdato);
		    	printf ("\n Recuperado %s %d %f %c", miptrdato->nombre, miptrdato->edad, miptrdato->est, miptrdato->sexo);
			}
			else
			{
				printf ("\n La pila esta llena \n ");
				getchar ();
			}
			 break;
		case 3:
		    
			 break;
}
	}
		return 0;
}


