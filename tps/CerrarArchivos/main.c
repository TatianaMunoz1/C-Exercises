#include <stdio.h>
#include <stdlib.h>


FILE *fd1;
FILE *fd2;
int main()
{
    fd1 = fopen("F:\\tps\\Archivo1.txt","a+");
    fd2 = fopen("F:\\tps\\Archivo2.txt","a+");


if (fd1 == NULL || fd2 == NULL){
    printf("No se ha podido comprobar");

}
else{
    printf("Si se pudieron comprobar los archivos");
}




    return 0;
}
