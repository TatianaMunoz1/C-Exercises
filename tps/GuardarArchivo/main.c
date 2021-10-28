


/*Crear una función recursiva que tenga como argumentos dos números enteros,
numero1 y numero2, la función tiene que mostrar por consola todos los números
entre numero1 y numero2 y guardarlos en un archivo .txt. Los números numero1
y numero2 deben ser leídos de un archivo números.txt guardado con el siguiente
formato:
12;3
Donde 12 será numero1 y 3 será numero2.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int numero1=0, numero2=0; //Números que se van a usar para la función

void CrearNumero(); //Esta funcion la hice para no andar creando y borrando archivos de texto cada vez que quiera probar el programa.
void LeerNumero();
void ResetArchivo(); //Esta funcion reinicia el archivo para no tener que andar borrando el archivo cada vez que pruebo el programa.
void Recursiva(int n1, int n2);

int main()
{
    CrearNumero();
    LeerNumero();
    ResetArchivo();
    Recursiva(numero1,numero2);

    return 0;
}


void CrearNumero() //Ingreso numeros y los imprimo en el archivo "numeros.txt"
{
    int aux1=0, aux2=0; //Números que se van a usar para crear el archivo numeros.txt
    FILE*Archivo1=fopen("numeros.txt","w");
    printf("Ingrese el numero inicial:");
    scanf("%d",&aux1);
    printf("Ingrese el numero final:");
    scanf("%d",&aux2);
    printf("\n");
    fprintf(Archivo1,"%d;%d,\n",aux1,aux2);
    fclose(Archivo1); //Si esta función no existiese el programa funcionaría igual (Siempre y cuando exista el archivo),
    //es solo como ayuda.

}
void LeerNumero() //Leo los numeros del archivo "numeros.txt" y los guardo en las variables para usar en la función recursiva
{
    FILE*Archivo1=fopen("numeros.txt","r");
    char saux[22];
    char auxn1[10];
    char auxn2[10];
    fgets(saux,22,Archivo1);
    sscanf(saux,"%[^;];%[^\n]",&auxn1,&auxn2);
    numero1=atoi(auxn1);
    numero2=atoi(auxn2);
    fclose(Archivo1);
}

void ResetArchivo() //Reinicio el archivo de la función recursiva
{
    FILE*Archivo1=fopen("archivo.txt","w");
    fclose(Archivo1);
}

void Recursiva(int n1, int n2){ //Imprimo los numeros en "archivo.txt
    FILE*Archivo1=fopen("archivo.txt","a");
    printf("%d\n",n1);
    fprintf(Archivo1,"%d\n",n1);
    if (n1>n2) //Si el primer numero ingresado es mayor que el segundo
    {
        fclose(Archivo1); //Este fclose sirve para que los numeros se impriman en el mismo orden en que se presenta en la consola
        Recursiva(n1-1,n2);
    }
    if (n1<n2) //Si el primer numero ingresado es menor que el segundo
    {
        fclose(Archivo1); //Lo mismo que arriba
        Recursiva(n1+1,n2);
    }

    fclose(Archivo1); //Cuando los numeros son iguales, se cierra el archivo completamente
}
