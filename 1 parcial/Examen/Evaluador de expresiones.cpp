#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX 100
#define TRUE	1
#define FALSE	0

typedef unsigned char boolean;

typedef struct elemento{ 		
	char c;						
	float n;
}elemento;
typedef struct nodo{
	elemento e;
	struct nodo *abajo;
}nodo;
typedef struct pila{
	nodo *tope;					
}pila;
void Inicializar(pila *s){
	s -> tope = NULL;	
	return;
}
void Push(pila *s, elemento e){
	nodo *aux; 
	aux = (nodo *)malloc(sizeof(nodo));
	(*aux).e = e;
	aux -> abajo = s -> tope;
	s -> tope = aux;
	return;
}
elemento Top(pila *s){				
	return s -> tope -> e;
}
elemento Pop(pila *s){
	elemento r;	
	nodo *aux;
	r = s -> tope -> e;
	aux = s -> tope;
	s -> tope = s -> tope -> abajo;
	free(aux);
	return r;
}	
boolean Empty(pila *s){
	return (s -> tope == NULL)?TRUE:FALSE;//
}

int Size(pila *s){
	int size = 0;
	nodo *aux;
	aux = s -> tope;
	while( aux != NULL){
		aux = aux -> abajo;
		size++;
	}
	return size;
}
void Destroy(pila *s){
	nodo *aux;
	while(s -> tope != NULL){
		aux = s -> tope -> abajo;
		free(s -> tope);
		s -> tope = aux;
	}
	return;
}

boolean otroProceso(){
	char sn, respuesta[20];
	printf("\n\n\t Desea introducir otra expresion ? escriba s para si y n para no: ");
	fflush(stdin);
	scanf("%c",&sn);
	printf("\n Usted selecciono %c \n", sn);
	return (sn == 's' || sn == 'S')?TRUE:FALSE;
}
boolean validarParentesis(char const *cadena){
	int i;
	elemento e1;
	pila p1;
	Inicializar(&p1);
	printf("\n Su expresion %s fue guardada correctamente. \nSe procedera a validar parentesis\n", cadena);
	for(i = 0; i < strlen(cadena); i++){
		if(cadena[i] == '('){
			e1.c = cadena[i];
			Push(&p1, e1);
			printf("\n%i Parentesis '(' introducido a la pila", i+1);
		}
		if(cadena[i] == ')'){
			if(Empty(&p1) == FALSE){
				Pop(&p1);
				printf("\n%i Se detecto ')' por lo que se saco un '(' de la pila", i+1);
			}
			else{
				printf("\n\t%i ERROR, hay mas parentesis que cierran que los que abren \n", i+1);
				return FALSE;
			}
		}
	}
	return (Empty(&p1) == TRUE)?TRUE:FALSE;
}
int precedencia(char c){
	int resultado;
	switch(c){
		case '+': resultado = 1; break;
		case '-': resultado = 1; break;
		case '*': resultado = 2; break;
		case '/': resultado = 2; break;
		case '^': resultado = 3; break;
		case '(': resultado = 0; break;
	}
	return resultado;
}
boolean esOperador(char c){
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')?TRUE:FALSE;
}
float Suma(float a, float b){
	float resultado;
	resultado = a + b;
	return resultado;
}
float Resta(float a, float b){
	float resultado;
	resultado = a - b;
	return resultado;
}
float Multiplicacion(float a, float b){
	float resultado;
	resultado = a * b;
	return resultado;
}
float Division(float a, float b){
	float resultado;
	resultado = a / b;
	return resultado;
}
float Potencia(float a, float b){
	double resultado;
	resultado = pow(a,b); 
	return (float)resultado; 
}
float solucionAlgebra(char const *cadena, int n){
	int i;
	elemento e1;
	pila p1;
	float val[27], valMarcado[27] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
		float resultado, a, b;
	Inicializar(&p1);
	for(i = 0; i < n; i++){
		if(esOperador(cadena[i]) == FALSE && cadena[i] >= 97 && cadena[i] <= 122){ 
			if(valMarcado[cadena[i] - 'a'] == 1 ){ 
				printf("\nIntroduzca un valor para '%c': ", cadena[i]); 
				scanf("%f",&val[cadena[i] - 'a']);
				e1.n = val[cadena[i] - 'a']; 
				Push(&p1,e1);
				printf("\nOperando %f empilado correctamente", val[cadena[i] - 'a']);
				valMarcado[cadena[i] - 'a'] = 0; 
			}
			else{	
				if(valMarcado[cadena[i] - 'a'] == 0 ){
					e1.n = val[cadena[i] - 'a'];
					Push(&p1, e1);
					printf("\nOperando %f empilado correctamente", val[cadena[i] - 'a']);
				}

			}
		}
		if(esOperador(cadena[i]) == TRUE && Empty(&p1) == FALSE){ 
			switch(cadena[i]){
				case '+': 
					e1 = Pop(&p1); 
					b = e1.n; 
					e1 = Pop(&p1);
					a = e1.n;
					e1.n = Suma(a,b); 
					printf("\n Efectuando suma de %f + %f y empilando", a, b); 
					break;
				case '-':
					e1 = Pop(&p1);
					b = e1.n;
					e1 = Pop(&p1);
					a = e1.n;
					e1.n = Resta(a,b);
					printf("\n Efectuando resta: %f - %f y empilando", a, b);
					break;
				case '*':
					e1 = Pop(&p1);
					b = e1.n;
					e1 = Pop(&p1);
					a = e1.n;
					e1.n = Multiplicacion(a,b);
					printf("\n Efectuando multiplicacion: %f * %f y empilando", a, b);
					break;
				case '/':
					e1 = Pop(&p1);
					b = e1.n;
					e1 = Pop(&p1);
					a = e1.n;
					e1.n = Division(a,b);
					printf("\n Efectuando division: %f / %f y empilando", a, b);
					break;
				case '^':
					e1 = Pop(&p1);
					b = e1.n;
					e1 = Pop(&p1);
					a = e1.n;
					e1.n = Potencia(a,b);
					printf("\n Efectuando potencia: %f ^ %f y empilando", a, b);
					break;
			}
			Push(&p1, e1); 
		}
	} 
	e1 = Pop(&p1); 
	resultado = e1.n;
	return resultado; 
}
void pasarPostfijo(char const *cadena){
	elemento e1;
	pila p1;
	int indice = 0; 
	int i, j, tamano = 0, operadorAbajo, operadorArriba; 
	char salidaPostfijo[MAX]; 
	Inicializar(&p1);
	for(i = 0; i < strlen(cadena); i++){
		if(cadena[i] != '(' && cadena[i] != ')') tamano++;
	}
	for(i = 0; i < strlen(cadena); i++){
		if(cadena[i] >= 97 && cadena[i] <= 122){ 
			salidaPostfijo[indice] = cadena[i]; 
			printf("\n%i Operando detectado, agregado a arreglo salidaPostfijo[%d]", i+1, indice);
			indice++;
		}
		if(cadena[i] == '('){ 
			e1.c = cadena[i];
			Push(&p1, e1);
			printf("\n%d Analizando expresion, %c detectado", i+1, e1.c);
		}
		if(cadena[i] == ')' && Empty(&p1) == FALSE){ 
			j = 0;			  
			printf("\n%d ')' Detectado, sacando elementos de la pila hasta encontrar '('", i+1);
			do{					
				e1 = Pop(&p1);
				if(esOperador(e1.c) == TRUE){
					printf("\n%d.%d Operador %c detectado y desempilado, pasado salidaPostfijo[%d]", i + 1, j, e1.c, indice);
					salidaPostfijo[indice] = e1.c; 
					indice ++;
				}
				j++;
			}while(e1.c != '(' && Empty(&p1) == FALSE);
		}
		if(cadena[i] == '+' || cadena [i] == '-' || cadena[i] == '/' || cadena[i] == '*'){
			operadorArriba = precedencia(cadena[i]);
			if(Empty(&p1) == FALSE){
				e1 = Top(&p1);
				operadorAbajo = precedencia(e1.c);	
			}
			else operadorAbajo = 0;
			if(operadorArriba <= operadorAbajo && Empty(&p1) == FALSE){ 
				e1 = Pop(&p1); 
				printf("\n Un operador '%c' no puede estar abajo de un operador '%c', pasando '%c' a salidaPostfijo[%d]", e1.c, cadena[i], e1.c, indice);
				salidaPostfijo[indice] = e1.c; 
				indice++;
				e1.c = cadena[i]; 
				Push(&p1, e1);
				printf("\n El operador '%c' ya pudo ser introducido a la pila", e1.c);
			}
			else{ 
				e1.c = cadena[i];
				Push(&p1, e1);
				printf("\n%d Analizando expresion, %c detectado y empilado", i+1, e1.c);
			}
		}
		if(cadena[i] == '^'){ 
			e1.c = cadena[i]; 
			Push(&p1, e1);
			printf("\n%d Analizando expresion, %c detectado y empilado", i+1, e1.c);
		}
	}
	j = i; 
	printf("\nEl tamano de la pila de operadores es: %d", Size(&p1));
	for(i = 0; i <= Size(&p1); i++){ 
		if(Empty(&p1) == FALSE){
			e1 = Pop(&p1);
			salidaPostfijo[indice] = e1.c;
		}
		printf("\n%d.%d Se saco el operador %c de la pila y se agrego a salidaPostfijo[%d]", j + 1, i, e1.c, indice); 
		indice++;
	}
	if(Empty(&p1) == TRUE){ 
		printf("\nLa pila esta vacia, a continuacion se imprimira la expresion en Postfijo: ");
		printf("\nExpresion en postfijo = ");
		for(i = 0; i < tamano; i++){
			printf("%c", salidaPostfijo[i]);
		}
		Destroy(&p1); 
        fflush(stdin);
		printf("\n\n\n\n\t El resultado de la expresion es: %lf ",solucionAlgebra(salidaPostfijo, tamano));
	}
	else printf("\n ERROR Desconocido"); 
	return;
}

int main(){
	elemento e1;
	pila p1;
	char expresion[MAX]; 
	int i;				 
	while(1){
		Inicializar(&p1);
		printf("Programa que valida y resuelve expresiones algebraicas por medio de una pila");
		printf("Como ejemplo, puede introducir una expresion como (a+b)^a-c\n");
		printf("NOTA: procure no dejar espacios");
		printf("\n\n A continuacion introduzca su expresion: ");
		scanf("%s",expresion);
		if(validarParentesis(expresion) == TRUE){ 
			printf("\nParentesis correctos, se procedera a realizar conversion a postfijo\n");
			Destroy(&p1); 
			pasarPostfijo(expresion); 
		}
		else{ 
			printf("\n Parentesis incorrectos, revise la sintaxis \n");
		}
		if(otroProceso() == TRUE){ 
			Destroy(&p1);
			getchar();
			setbuf(stdin, NULL);
		}
		else break; 
	}
	getchar();
	return 0;
}
