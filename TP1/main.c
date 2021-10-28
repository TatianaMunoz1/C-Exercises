int main()
{
    //Define variables
    char nacimiento[4], dni[8], nombre[20];
    int i, vocs=0;
    printf("Ingrese su nombre(minusculas): ");//Pide y asigna el valor a la variable
    scanf("%s",&nombre);
    printf("ingrese su numero de dni(8 digitos): ");//Pide y asigna el valor a la variable
    scanf("%s",&dni);
    printf("ingrese su anio de nacimiento(4 digitos): ");
    scanf("%s",&nacimiento);//Pide y asigna el valor a la variable
    for (i=0; vocs<2;i++){
            switch(nombre[i]){//Busca las vocales e imprime si las encuentra
                case 'a':
                    printf("A");
                    vocs=vocs+1;
                    break;
                case 'e':
                    printf("E");
                    vocs=vocs+1;
                    break;
                case 'i':
                    printf("I");
                    vocs=vocs+1;
                    break;
                case 'o':
                    printf("O");
                    vocs=vocs+1;
                    break;
                case 'u':
                    printf("U");
                    vocs=vocs+1;
                    break;
            }
        }
    printf(" ");
    for (i=5;i<8;i++){//Imprime los ultimos numero de 'dni'
            printf("%c",dni[i]);
    }
    printf(" ");
    for (i=2;i<=4;i++){
            switch(nacimiento[i]){//Cambia los ultimos numeros de 'nacimiento' por letras
                case '0':
                    printf("A");
                    break;
                case '1':
                    printf("B");
                    break;
                case '2':
                    printf("C");
                    break;
                case '3':
                    printf("D");
                    break;
                case '4':
                    printf("E");
                    break;
                case '5':
                    printf("F");
                    break;
                case '6':
                    printf("G");
                    break;
                case '7':
                    printf("H");
                    break;
                case '8':
                    printf("I");
                    break;
                case '9':
                    printf("J");
                    break;
            }
    }
    return 0;
}
