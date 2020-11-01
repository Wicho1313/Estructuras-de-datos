/************************************************
* Programa que comprar dos cadenas utilizando 	*
* la funcion strcmp()							*
* Autor: Gilberto Irving Oledo Enriquez			*
************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define tamCad 20
int main(){
	char cad1[tamCad];
	char cad2[tamCad];
		scanf("%s", &cad1);
	 fflush( stdin );
		scanf("%s", &cad2);
	if(strcmp(cad1,cad2)==0){
		printf("Ambas cadenas son iguales");	
	}
	else{
		printf("Las cadenas son distintas");
		system("pause");
	}	
	return 0;
}
