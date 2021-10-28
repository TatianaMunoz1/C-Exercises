main()
{
    //Define variables
    int largovector;
    int i, inv=0;
    int par=0, imp=0;
    int max=-99999, min=99999, posmax, posmin;
    printf("Ingrese el largo deseado para el vector: ");
    scanf("%d", &largovector);//Pide y asigna el valor ingresado a la variable
    int vector[largovector];//Define el primer vector
    for (i=0; i<largovector; i++){
        printf("Ingrese un valor para la posicion %d del vector 1: ", i);
        scanf("%d", &vector[i]);//Pide y asigna los valores ingresados al vector
    }
    int vectorinv[largovector];//Define el segundo vector
    for (i=largovector-1; i>=0;i--){
        vectorinv[inv]=vector[i];//Asigna los valor del primer vector al segundo vector invertidos
        inv=inv+1;
    }
    printf("El vector 1 esta formado por los numeros: ");
        for (i=0; i<largovector;i++){
        printf(" %d,", vector[i]);//Imprime los valores del primer vector
        if (vector[i]%2==0){//Busca la cantidad de numeros pares dentro del vector
            par=par+1;
        }
        else{//Busca la cantidad de numeros impares dentro del vector
            imp=imp+1;
        }
        if (vector[i]>=max){//Busca el numero maximo dentro del vector
                max=vector[i];
                posmax=i;
        }
        if (vector[i]<=min){//Busca el numero minimo dentro del vector
                min=vector[i];
                posmin=i;
        }
    }
    printf("\nEl vector 2 esta formado por los numeros: ");
    for (i=0; i<largovector;i++){
        printf(" %d,", vectorinv[i]);//Imprime los valores del segundo vector
    }
    printf("\nLa cantidad de numeros pares en el vector 1 es: %d", par);
    printf("\nLa cantidad de numeros impares en el vector 1 es: %d", imp);
    printf("\nEl numero maximo del vector 1 es: %d", max);
    printf(" y su posicion en el vector es %d", posmax);
    printf("\nEl numero minimo del vector 1 es: %d", min);
    printf(" y su posicion en el vector es %d", posmin);
    return 0;
}
