#include <stdio.h>
#include <stdlib.h>
void Intercambiar(int num1, int num2); //Se declara la funcion con sus parametros prototipos
void IntercambiarConPunteros(int *num1, int *num2); //Se declara el segundo prototipo funcion void con sus parametros
void PonerEnCero(int *num1);//Declaracion de prototipo
int main()
{
 int edadUno; //Declaro variable
 int edadDos; //Declaro variable2
 edadUno=22; //Le asigno valores
 edadDos=30; //" "     " "
 PonerEnCero(&edadDos); //Llamo a la funcion usando como referencia, parametro la direccion de memoria de la variable edadDos que contiene el numero=30


 IntercambiarConPunteros(&edadUno,&edadDos); //Llamo a la segunda funcion, dandole como referencia la direccionde memoria de las dos variables que contiene sus respectivos valores
 printf("\nEdad 1:%d",edadUno); //Imprimo el actual valor de edadUno(0)
 printf("\nEdad 2:%d",edadDos); //Imprimo el actual valor de edadDos(22)
 return 0;
}
void PonerEnCero(int *num1) //Declaro la variable como puntero ya que en el prototipo superior se exige un puntero
{
 *num1=0; //El puntero que apunta sobre el valor que contiene esa variable, dentro del main se indicara que sera la variable edadDos (es decir 30), se igualara su valor a 0 por lo que edadDos ahora comienza a valer 0 a partir de este punto una vez que ingresa a esta funcion
 //edadDos=0 y edadUno=22
}
void IntercambiarConPunteros(int *num1, int *num2) //Desarollo la funcion tomando como parametro dos punteros enteros
{
 int aux; //Declaro una variable entera auxiliar
 aux= *num1; //La variable auxiliar tomara el valor que contiene el num1 ya que apunta ahi, es decir, una vez que el programa entre en esta funcion esta variable sera edadUno, por ende, auxiliar empezara a valer 22
 //En este momento valen aux= 22 y *num1=22
 *num1=*num2; //el puntero de la primer variable (edadUno) tomara el valor que contiene el puntero 2 (edadDos)
 //En este momento (una vez ingresado a esta funcion posterior a la funcion PonerEnCero) *num1=0 y *num2=0
 *num2=aux; //El puntero2 toma el valor de auxiliar, es decir, el antiguo valor de *num1
 //*num2=22 y aux=22
}
