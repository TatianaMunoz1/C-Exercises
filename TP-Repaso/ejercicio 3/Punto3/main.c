
/*Dado dos archivos, arc1 y arc2, con nombres de personas, ordenados. Generar un
arc3 con todos los nombres ordenados.
*/
///PUNTO3------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE*Archivo3=fopen("arc3.txt","w");
    fclose(Archivo3);

    int n1,n2;
    char aux1[50],aux2[50];
    int leer1=1;
    int leer2=1;

    FILE*Archivo1=fopen("arc1.txt","r");
    FILE*Archivo2=fopen("arc2.txt","r");
    Archivo3=fopen("arc3.txt","a");

    while(1)
    {
        if(leer1==1){
            fgets(aux1,50,Archivo1);
        }
        if(leer2==1){
            fgets(aux2,50,Archivo2);
        }
        if(strcmp(aux1,aux2)<=0) /*Si son iguales devolvera un 0*/
        {
            fprintf(Archivo3,"%s",aux1);
            leer1=1;
            leer2=0;
        }
        if(strcmp(aux1,aux2)>0)
        {
            fprintf(Archivo3,"%s",aux2);
            leer1=0;
            leer2=1;
        }
        if(feof(Archivo1)){

                fclose(Archivo1);
            while(!feof(Archivo2)){
                fgets(aux2,50,Archivo2);
                fprintf(Archivo3,"%s",aux2);
            }
            //fprintf(Archivo3,"\n%s",aux1);
            fclose(Archivo2);
            fclose(Archivo3);
            break;
        }


        if(feof(Archivo2)){
                fclose(Archivo2);
            while(!feof(Archivo1)){
                fgets(aux1,50,Archivo1);
                //fprintf(Archivo3,"%s",aux1);
            }
            fprintf(Archivo3,"\n%s",aux2);
            fclose(Archivo1);
            fclose(Archivo3);
            break;
        }
    }


    return 0;
}
