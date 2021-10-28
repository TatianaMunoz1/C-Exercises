/*Crear un programa que permita:
a. Crear una matriz del tamaño que se desee, por medio del teclado, una vez
creada se la quiere guardar en un archivo.txt.
b. Dado un archivo .txt con una matriz cargada que permita la lectura de esa
matriz.
*/
///PUNTO 2-------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ImprimirMatriz();
void MostrarMatriz();


int main()
{

    ImprimirMatriz();
    MostrarMatriz();
    return 0;
}

void ImprimirMatriz()
{
    int a=0;
    int b=0;
    int i=0;
    int j=0;
    printf("Ingrese las dimensiones de la matriz:\n")  ;
      scanf("%d",&a);
    fflush(stdin);
    scanf("%d",&b);
    fflush(stdin);

    int matriz[a][b];

    printf("\nIngrese los valores para llenar la matriz:\n");
    for(i=0;i<a;i++){
        for (j=0;j<b;j++){
            scanf("%d",&matriz[i][j]);
            fflush(stdin);
        }
    }

    FILE*Archivo=fopen("matriz.txt","a");
    for(i=0;i<a;i++){
        for(j=0;j<b;j++){
            fprintf(Archivo,"%d ",matriz[i][j]);
        }
            fprintf(Archivo,"\n");
    }
    fclose(Archivo);

}


void MostrarMatriz()
{
    char aux[100];

    FILE*Archivo=fopen("matriz.txt","r");
    printf("\nLa matriz es:\n ");

    while(fgets(aux,100,Archivo)!=NULL){
            printf("%s ",aux);
        }
    fclose(Archivo);
}





