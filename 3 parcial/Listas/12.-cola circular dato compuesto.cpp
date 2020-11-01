#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct persona{
    char name[30];
    int edad;
    float estatura;
    char sexo;
};
struct cola{
        struct persona ar;
        struct cola *ptrSig;
        struct cola *ptrAnt;
};

struct persona guardaValores();
void meter(struct persona y);
void sacar();
void imprimirCola();
int vacio();
struct cola * crearnodo();

struct cola *top=NULL,*base=NULL;
 struct cola *adel;

int main(){
    int opc;
    struct persona aux;
    while(1){
        printf("Elige opcion:\n");
        printf("\n1.-Meter en Cola Circular\n");
        printf("\n2.-Sacar de la Cola Circular\n");
        printf("\n3.-Mostrar Cola\n");
        printf("\n4.-Salir\n");
        scanf("%d", &opc);
        switch(opc){
            case 1:
                aux=guardaValores();
                meter(aux);
            break;
            case 2:
                if(!vacio()){
                	printf("\nEl primero que entra es el primero que sale: \n");
                    printf("\nNombre: %s", base->ar.name);
                    printf("\nEdad: %d", base->ar.edad);
                    printf("\nEstatura: %f", base->ar.estatura);
                    printf("\nSexo: %c", base->ar.sexo);
                    sacar();
                    getchar();
                    getchar();
                }else{
                    printf("Cola vacia\n");
                    top=NULL;
                    base=NULL;
                    getchar();
                    getchar();
                }
            break;
            case 3:
                if(!vacio()){
                    imprimirCola();
                    getchar();
                    getchar();
                }
                else{
                    printf("cola vacia\n");
                    getchar();
                    getchar();
                }
            break;
            case 4:
                return 0;
            break;
            default:
                printf("\nElige una opcion valida\n");
                getchar();
            break;
        }
    }
    return 0;
}
void imprimirCola(){
        printf("\nNombre: %s", adel->ar.name);
        printf("\nEdad: %d", adel->ar.edad);
        printf("\nEstatura: %f", adel->ar.estatura);
        printf("\nSexo: %c\n", adel->ar.sexo);
        adel=adel->ptrSig;
}
void meter(struct persona y){
    struct cola *ptrN;
    ptrN=crearnodo();
    ptrN->ar=y;
    if (top==NULL){
        top=ptrN;
        base=ptrN;
        top->ptrSig=base;
        top->ptrAnt=base;
        base->ptrSig=top;
        base->ptrAnt=top;
    }else{
        top->ptrSig=ptrN;
        ptrN->ptrAnt=top;
        top=top->ptrSig;
        top->ptrSig=base;
        base->ptrAnt=top;
    }
    adel=base;
}
void sacar(){
    if(base==top){
         base->ptrSig=NULL;
         base->ptrAnt=NULL;
         top->ptrSig=NULL;
         top->ptrAnt=NULL;
         base=NULL;
         top=NULL;
         adel=NULL;
     }else{
        struct cola *ptrTemp;
        ptrTemp=base;
        base=base->ptrSig;
        top->ptrSig=base;
        base->ptrAnt=top;
        ptrTemp->ptrSig=NULL;
        ptrTemp->ptrAnt=NULL;
        free(ptrTemp);
    }
    adel=base;
}
int vacio(){
    return base==NULL;
}
struct cola * crearnodo(){
    return (struct cola *)malloc(sizeof(struct cola));
}
struct persona guardaValores(){
    struct persona paux;
    printf("Nombre: ");
    getchar();
    fgets(paux.name,100,stdin);
    strtok(paux.name,"\n");
    printf("Edad: ");
    scanf("%d", &paux.edad);
    printf("Estatura: ");
    scanf("%f", &paux.estatura);
    setbuf(stdin, NULL);
    printf("Sexo : ");
    paux.sexo=getchar();
    return paux;
}
