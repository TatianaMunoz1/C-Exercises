
#include <stdio.h>
#include <string.h>

 int comprobar(int numero); //Parametros

 int main(){
 int numero;
 int x;


 printf("Digite un numero: ");
 scanf("%i",&numero);



 x = comprobar(numero);

 if(x==0){
    printf("el numero es par ");
 }
 else{
    printf("el numero es impar");
 }
 }

 int comprobar(int numero){
 if(numero%2==0){
    return 0;
 }
 else{
    return 1;
 }

 }
