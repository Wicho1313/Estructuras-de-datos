#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct nodo{
	int edad;
	float est;
	char nombre[20];
	char sex;
	struct nodo *ptrsig;
};

struct nodo * crearNodo (int edad2, float est2, char nombre[20],char sex2){
	struct nodo *ptrAux;
	ptrAux=(struct nodo *) malloc(sizeof(struct nodo));
	strcpy(ptrAux->nombre, nombre);
	ptrAux->edad=edad2;
	ptrAux->est=est2;
	ptrAux->sex=sex2;
	ptrAux->ptrsig=NULL;
	return ptrAux;
}

void meterPila (struct nodo *ptrCab, int edad2, float est2, char nombre[20],char sex2){
	struct nodo * ptrNuevo;
	ptrNuevo=crearNodo(edad2, est2, nombre, sex2);
	if(ptrCab->ptrsig==NULL){
		ptrCab->ptrsig=ptrNuevo;
	}
	else{
		ptrNuevo->ptrsig=ptrCab->ptrsig;
		ptrCab->ptrsig=ptrNuevo;
	}
}

void sacarPila (struct nodo *ptrCab){
	struct nodo *ptrAux;
	ptrAux=ptrCab->ptrsig;
	if(ptrCab->ptrsig!=NULL)
	{
        ptrCab->ptrsig=ptrAux->ptrsig;
        free(ptrAux);
}
else{
     printf("\n Pila vacia");
     }
	
}
void mostrarPila(struct nodo * ptrCab){
	
	struct nodo *ptrCabAux;
	ptrCabAux=ptrCab->ptrsig;
	while(ptrCabAux!=NULL){
            printf("\n En la direccion %lu esta la estatura %f ", &ptrCabAux->est, ptrCabAux->est);
             printf("\n En la direccion %lu esta el sexo %c ", &ptrCabAux->sex, ptrCabAux->sex);
              printf("\n En la direccion %lu esta el nombre %s ", &ptrCabAux->nombre, ptrCabAux->nombre);
               printf("\n En la direccion %lu esta la edad %d \n ", &ptrCabAux->edad, ptrCabAux->edad);
            ptrCabAux=ptrCabAux->ptrsig;
            }
}
int menu(){
	int opc;
	fflush(stdin);
printf ("\n 1.- Meter pila \n ");
printf ("\n 2.- sacar pila \n ");
printf ("\n 3.- Salir \n ");
scanf ("%d", &opc);
	return (opc);
}

int main()
{
	int edad3;
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
			printf("ingresa nombre: ");
		gets(nombre);
				fflush(stdin);
		printf("Ingrese edad: ");
		scanf("%d",&edad3);
				fflush(stdin);
		printf("Ingrese est: ");
		scanf("%f",&est3);
				fflush(stdin);
	    printf("ingrese sexo: ");
	    scanf("%c",&sex3);
		meterPila(ptrCab, edad3,est3,nombre,sex3);
      mostrarPila(ptrCab);
    break;
	
	case 2:
		sacarPila(ptrCab);
	mostrarPila(ptrCab);
	break;
	
	case 3:
        exit(0);
	break;
	
				}
			}
			system("pause");
			return 0;
}
