#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#define MAX_CADENA 100
int NumerosPares,NumerosImpares;
int main (){
printf("\n---------------------- EJERCICIO 1 ---------------------\n");
// Declaracion de variables:
int largoVector=0,x=0,i=0,j=0,Aux,Maximo,Minimo,Pos1=0,Pos2=0;
// Ingreso del largo del vector:
printf("Ingrese el largo del vector 1: ");
scanf("%d", &largoVector);
/* Igualando el largo ingresado por el usuario a
la cantidad de posiciones del vector: */
int vector1[largoVector];
// Ingresando los valores a las posiciones del vector:
printf("\nIngrese los valores del vector 1: \n");
for(x=0;x<=largoVector;x++){
    printf("Valor para la posicion \"%d\": ",x);
    scanf("%d",&vector1[x]);
}
// Igualando la cantidad de posiciones del vector 1 al vector 2:
int vector2[largoVector];
// Impresion del vector 1:
printf("\nEl vector 1 esta formado por los n%cmeros: ",163);
for(x=0;x<=largoVector;x++){
    printf("%d ",vector1[x]);
}
// Pasar los valores del vector 1 al vector 2 pero invertidos
for(x=0;x<=largoVector;x++){
    Aux = vector1[x];
    vector2[x] = vector1[largoVector - x];
    vector2[largoVector - x] = Aux;
}
// Imprimir el vector 2:
printf("\nY el vector 2 esta formado por los n%cmeros: ",163);
for(x=0;x<=largoVector;x++){
    printf("%d ",vector2[x]);
}
// Agarrar numeros pares y impares
for(x=0;x<=largoVector;x+=1){
    if(vector1[x]%2==0){
        NumerosPares=NumerosPares+1;
    }
    else{
        NumerosImpares=NumerosImpares+1;
    }
}
// Imprimir numeros pares y impares:
printf("\n\nCantidad de n%cmeros pares en el vector 1: %d",163, NumerosPares);
printf("\nCantidad de n%cmeros impares en el vector 1: %d",163, NumerosImpares);
// Declaracion de maximo y minimo:
Maximo = vector1[0];
Minimo = vector1[0];
// Averiguar maximos y minimos:
for (x=0;x<=largoVector;x++){
    if (vector1[x] > Maximo){
    Maximo = vector1[x];
    Pos1 = x;
    }
    if (vector1[x] < Minimo){
    Minimo = vector1[x];
    Pos2 = x;
    }
}
// Imprimir maximos y minimos
printf("\n\nEl n%cmero m%cximo es el %d que est%c en la posici%cn %d",163, 160, Maximo, 160, 162, Pos1);
printf("\nEl n%cmero m%cnimo es el %d que est%c en la posici%cn %d",163, 161, Minimo, 160, 162, Pos2);
printf("\n---------------------- EJERCICIO 2 ---------------------\n");
char NombreUsuario[25];
char DNI[8];
char Nacimiento[4];
int Posicion=0;
//Ingreso de nombre:
printf("\nIngrese el nombre de usuario: ");
scanf("%s", &NombreUsuario);
//Ingreso de DNI
printf("\nIngrese su DNI: ");
scanf("%s", &DNI);
//Ingreso de nacimiento:
printf("\nIngrese su A%co de nacimiento: ", 164);
scanf("%s", &Nacimiento);
//Comparacion de caracteres en cada posicion del nombre:
for(x=0;x<=25;x++){
    //Igualando Letra al nombre, para poder colocar en el switch
    char Letra = NombreUsuario[x];
    //Comparacion letra por letra:
    switch (Letra){
        case 'a': printf("A");i=i+1;if(i==2){  // i=i+1 (Tengo 1 vocal)
            x=25;
        };break;
        case 'e': printf("E");i=i+1;if(i==2){  // i=1+1 (Tengo 2 vocales)
            x=25;
        };break;
        case 'i': printf("I");i=i+1;if(i==2){  // if(i==2) (Si tengo 2 vocales)
            x=25;
        };break;
        case 'o': printf("O");i=i+1;if(i==2){  // x=25; (x pasa a valer 25)
            x=25;                              // Lo que hace que se cierre el for
        };break;                               // Por ser x=25 (desde) ; x<=25 (hasta)
        case 'u': printf("U");i=i+1;if(i==2){
            x=25;
        };break;
        case 'A': printf("A");i=i+1;if(i==2){
            x=25;
        };break;
        case 'E': printf("E");i=i+1;if(i==2){
            x=25;
        };break;
        case 'I': printf("I");i=i+1;if(i==2){
            x=25;
        };break;
        case 'O': printf("O");i=i+1;if(i==2){
            x=25;
        };break;
        case 'U': printf("U");i=i+1;if(i==2){
            x=25;
        };break;
    }
}
printf(" ");
//Igualando i a 0 para
i=0;
//Comparacion de caracteres en cada posicion del DNI:
//Partiendo el for desde , para que imprima desde esa posicion hasta (Ultimos 3)
for(x=5;x<=7;x++){
    //Igualando Numero1 con DNI, para poder colocar dentro del switch
    char Numero1 = DNI[x];
    //Comparacion letra por letra:
    switch (Numero1){
        case '9': printf("9");i=i+1;if(i==3){
            x=7;
        };break;
        case '8': printf("8");i=i+1;if(i==3){
            x=7;
        };break;
        case '7': printf("7");i=i+1;if(i==3){
            x=7;
        };break;
        case '6': printf("6");i=i+1;if(i==3){
            x=7;
        };break;
        case '5': printf("5");i=i+1;if(i==3){
            x=7;
        };break;
        case '4': printf("4");i=i+1;if(i==3){
            x=7;
        };break;
        case '3': printf("3");i=i+1;if(i==3){
            x=7;
        };break;
        case '2': printf("2");i=i+1;if(i==3){
            x=7;
        };break;
        case '1': printf("1");i=i+1;if(i==3){
            x=7;
        };break;
        case '0': printf("0");i=i+1;if(i==3){
            x=7;
        };break;
    }
}
printf(" ");
for(x=2;x<=3;x++){
    char Numero2 = Nacimiento[x];
    switch (Numero2){
        case '9': printf("J");i=i+1;if(i==2){
            x=3;
        };break;
        case '8': printf("I");i=i+1;if(i==2){
            x=3;
        };break;
        case '7': printf("H");i=i+1;if(i==2){
            x=3;
        };break;
        case '6': printf("G");i=i+1;if(i==2){
            x=3;
        };break;
        case '5': printf("F");i=i+1;if(i==2){
            x=3;
        };break;
        case '4': printf("E");i=i+1;if(i==2){
            x=3;
        };break;
        case '3': printf("D");i=i+1;if(i==2){
            x=3;
        };break;
        case '2': printf("C");i=i+1;if(i==2){
            x=3;
        };break;
        case '1': printf("B");i=i+1;if(i==2){
            x=3;
        };break;
        case '0': printf("A");i=i+1;if(i==2){
            x=3;
        };break;
    }
}
    return 0;
}
