#include <stdio.h>
#include <stdlib.h>
#include <string.h>
///PUNTO TRES------------------------------------------------------------
int main()
{
    int i,j;
FILE*arch1=fopen("NombresM.txt","r");
FILE*arch2=fopen("NombresH.txt","r");
FILE*arch3=fopen("NombresO.txt","a");

char auxn1[100];
char auxn2[100];
int n1=1;
int n2=1;

//--------------------
while(1){
    if(n1==1){
    fscanf(arch1,"%s",&auxn1); //Guardo nombres deNOMBRESM
    }
    if(n2==1){              //Guardo nomrbes de NOMBRESH
    fscanf(arch2,"%s",&auxn2);
    }


if(strcmp(auxn1,auxn2)<0){ //Si ambos nombres son iugales entonces da , delo contrario da uno
    fprintf(arch3,"%s\n",auxn1);
    n1=1;
    n2=0;
}
else{
    fprintf(arch3,"%s\n",auxn2);
    n1=0;
    n2=1;
}


char aux[101];
if(feof(arch1)){
    fprintf(arch3,"%s",auxn1);

while(!feof(arch2)){
    fgets(aux,100,arch2);
    fprintf(arch3,"%s",aux);
}
if(feof(arch2)){
    fclose(arch2);
    fclose(arch1);
    break;
}
}

if(feof(arch2)){
    fprintf(arch3,"%s",auxn2);
while(!feof(arch1)){
    fgets(aux,100,arch1);
    fprintf(arch3,"%s",aux);

}
if(feof(arch1)){
    fclose(arch1);
    fclose(arch2);

    break;
}
}




}






    return 0;
}
