#include <stdio.h>
#include <stdlib.h>



void Binario(int n);

int main()
{
int numero;

do{
printf("\nDigite su numero: ");
scanf("%i",&numero);
}while(numero<0);


Binario(numero);
    return 0;
}
void Binario(int n){
    if(n>1){
            Binario(n/2);
    }
     else {
            printf("%i",n%2);

     }

}
