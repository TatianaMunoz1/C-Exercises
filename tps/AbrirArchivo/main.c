#include <stdio.h>
#include <stdlib.h>



FILE *fd;


int main()
{
    char direccion[] ="F: hola.txt"; //Direccion donde creo el archivo

    fd= fopen(direccion,"w"); //Crea un archivo de cero escribiendo con w
    if( fd== NULL){
        printf("NO SE PUDO CREAR ARCHIVO");
    }
    else {
        printf("Se creo el archivo");
        printf("\nUbicacion: %s",direccion);
    }

    return 0;
}
