
/*
Una vez hecho esto se quiere poner en cero la edadDos por medio de la función
ponerEnCero y
1)PONER EN CERO LA EDAD DOS USANDO LA FUNCION ponerenCero
2)Intercambiar valores de edadUno y edad Dos

Que cambios
Solo es válido agregar * y/o &, no se puede realizar otra operación.
*/

#include <stdio.h>
#include <stdlib.h>
void Intercambiar(int num1, int num2);
void IntercambiarConPunteros(int *num1, int *num2);
void PonerEnCero(int *num1);
int main()
{
 int edadUno;
 int edadDos;
 edadUno=22;
 edadDos=30;

 PonerEnCero(&edadDos);

IntercambiarConPunteros(&edadUno,&edadDos);

 printf("\nEdad 1:%d",edadUno);
 printf("\nEdad 2:%d",edadDos);

 return 0;
}

void PonerEnCero(int *num1){
    *num1=0;
}

void IntercambiarConPunteros(int *num1, int *num2)
{
 int aux;
 aux= *num1;
 *num1=*num2;
 *num2=aux;
}

