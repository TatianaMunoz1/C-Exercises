#include <stdio.h> //Libreria Entrada y salida
#include <stdlib.h> //Libreria Estandar
#include <string.h> //Libreria de Strings
void funcionBienvenida(char* nombre); //Declaracion de funcion sin retorno apuntando a valor de un char
void funcionDespedida(char* nombre);//Declaracion  de funcion apuntando a valor de  un char
int main()
{
 char nombre1[30] = "Romina Masilla"; //Declaro una cadena de caracters y defino su contenido
 char nombre2[30] = "Nicolas Perez"; //Declaro una segunda cadena de caracteres y defino su contenido
 funcionBienvenida (&nombre1); //Llamo a la funcion externa y toma como referencia la direccion de memoria de la variable nombre 1
 getche(); //sirve para dar una pausa al programa, y solo continua si el usuario aprieta alguna tecla, esta se muestra en pantalla y luego continua el programa
 system("CLS"); //Se limpia la pantalla
 funcionDespedida(&nombre2); //Se llama a otra funcion dandole como referencia
 getche();
 system("CLS");
 return 0;
}
//Debe mostrar Bienvenida Romina Mansilla, a Programacion de la UNLa
//2018
void funcionBienvenida(char *nombre) //Desarollo la funcion usando un puntero ya que en el prototipo se pide asi, puntero de los valores de la variable tipo cadena de caracteres, nombre (Romina Mansilla)
{
 printf("Bienvenida %s, a Programacion de la UNLa 2018.",nombre); //Se imprime texto y el nombre almacenado en la variable nombre (Romina Mansilla)
}
//Debe mostrar Vos Nicolas Perez estas despedido ------>
void funcionDespedida(char *nombre) //Desarollo de la funcion apuntando a una variable llamada nombre, posteriormente se le asignara un valor dentro del main que sera &nombre2, la direccion de memoria de la cadena nombre 2
 printf("Vos %s estas despedido ------->",nombre); //Imprime texto y el nombre que se esta usando en esa funcion void al ingresar desde el main (Nicolas Perez)

}
