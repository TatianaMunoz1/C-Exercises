#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#define TAM 128
//Declaracion de variables globales
void Factura_Costo(),Menu_Envio(),Menu_1(),Eleccion_1(),Eleccion_2(),Envio_Nacional(),Envio_Local();
void Algoritmo_Conveniencia_Local(),Algoritmo_Conveniencia_Nacional();
int x=0,z=0,Cantidad=0,Opcion_1=0,Opcion_2=0,Eleccion[10],Info_Chocolate=0,Continuar=0,Cantidad_TOTAL_GRAMOS=0,Eleccion_Envio_1=0,Eleccion_Provincia=0;
char Seguir[2];float Total_1=0,Totales[10],Cantidad_Gramos[10];char Tiempo[TAM];
//Linea de separacion
char Linea[TAM]="------------------------------------------------------------------------------";
//Estructura chocolcates

struct{
    char Sabor_1[TAM]="Chocolate Negro",Sabor_2[TAM]="Chocolate Blanco";
    char Sabor_3[TAM]="Chocolate con Almendras",Sabor_4[TAM]="Chocolate de Banana";
    char Sabor_5[TAM]="Chocolate de Frutilla",Sabor_6[TAM]="Chocolate Amargo";
    char Sabor_7[TAM]="Chocolate de Naranja",Sabor_8[TAM]="Chocolate de Menta";
    char Sabor_9[TAM]="Chocolate con Leche",Sabor_10[TAM]="Chocolate Vegano";
}Sabores_Chocolates;
//Estructura Provincias
struct{
    char Provincia_1[TAM]="Buenos Aires",Provincia_2[TAM]="Catamarca",Provincia_3[TAM]="Chaco",Provincia_4[TAM]="Chubut";
    char Provincia_5[TAM]="Cordoba",Provincia_6[TAM]="Corrientes",Provincia_7[TAM]="Entre Rios",Provincia_8[TAM]="Formosa";
    char Provincia_9[TAM]="Jujuy",Provincia_10[TAM]="La Pampa",Provincia_11[TAM]="La Rioja",Provincia_12[TAM]="Mendoza";
    char Provincia_13[TAM]="Misiones",Provincia_14[TAM]="Neuquen",Provincia_15[TAM]="Rio Negro",Provincia_16[TAM]="Salta";
    char Provincia_17[TAM]="San Juan",Provincia_18[TAM]="San Luis",Provincia_19[TAM]="Santa Cruz",Provincia_20[TAM]="Santa Fe";
    char Provincia_21[TAM]="Santiago del Estereo",Provincia_22[TAM]="Tierra del Fuego",Provincia_23[TAM]="Tucuman";
}Provincias;
//Estructura de Correos
struct{
    //Nombre de correos:
    char Correo_OCA[TAM]="OCA",Correo_Andreani[TAM]="Andreani",Correo_CArgentino[TAM]="Correo Argentino";
    //OCA LOCAL:
    int Encomienda_Simple_L=5000,Encomienda_Estandar_L=10000,Encomienda_Prioritaria_L=5000,Encomienda_Urgente_L=25000,Estampilla_Exceso_L=145;
    int OCA_Precio_EL_S1=200,OCA_Precio_EL_S2=410,OCA_Precio_EL_S3=550,OCA_Precio_EL_S4=800;
    char E_Simple[TAM]="Encomienda Simple",E_Estandar[TAM]="Encomienda Estandar",E_Prioritaria[TAM]="Encomienda Prioritaria",E_Urgente[TAM]="Encomienda Urgente";
    //OCA NACIONAL:
    int Encomienda_Simple_N=5000,Encomienda_Estandar_N=10000,Encomienda_Prioritaria_N=5000,Encomienda_Urgente_N=25000,Estampilla_Exceso_N=145;
    int OCA_Precio_EN_S1=295,OCA_Precio_EN_S2=500,OCA_Precio_EN_S3=1000,OCA_Precio_EN_S4=1300;
    //Andreani LOCAL Y NACIONAL:
    int Andreani_Pack_1=2000,Andreani_Pack_2=3000,Andreani_Pack_3=5000,Andreani_Pack_4=10000,Andreani_Pack_5=20000;
    int A_Pack_1=550,A_Pack_2=600,A_Pack_3=710,A_Pack_4=850,A_Pack_5=1350;
    char A_P_1[TAM]="Andreani Pack 1",A_P_2[TAM]="Andreani Pack 2",A_P_3[TAM]="Andreani Pack 3",A_P_4[TAM]="Andreani Pack 4",A_P_5[TAM]="Andreani Pack 5";
    //Correo Argentino LOCAL:
    int Encomienda_Clasica_1L=1000,Encomienda_Clasica_2L=5000,Encomienda_Clasica_3L=10000,Encomienda_Clasica_4L=15000,Encomienda_Clasica_5L=20000;
    int E_Clasica_1L=225,E_Clasica_2L=265,E_Clasica_3L=340,E_Clasica_4L=415,E_Clasica_5L=500;
    char E_C_1[TAM]="Encomienda Clásica 1",E_C_2[TAM]="Encomienda Clásica 2",E_C_3[TAM]="Encomienda Clásica 3";
    char E_C_4[TAM]="Encomienda Clásica 4",E_C_5[TAM]="Encomienda Clásica 5";
    //Correo Argentino NACIONAL:
    int Encomienda_Clasica_1N=1000,Encomienda_Clasica_2N=5000,Encomienda_Clasica_3N=10000,Encomienda_Clasica_4N=15000,Encomienda_Clasica_5N=20000;
    int E_Clasica_1N=310,E_Clasica_2N=385,E_Clasica_3N=510,E_Clasica_4N=630,E_Clasica_5N=740;
}Correos;
//Estructura de datos del usuario
struct{
    char Nombre_Completo_Usuario[TAM],DNI_Usuario[TAM],Nombre_Direccion_Usuario[TAM];
    int Numero_Direccion_Usuario=0,Cant_KM_Envio=0;
}Datos_Usuario;
//Funcion principal
int main(){
    Menu_1();
    system("pause");
    return 0;
}
//Menu
void Menu_1(){
    //Vaciado de buffer
    fflush(stdin);
    do{printf("%s\n",Linea);
    //Estructura para fecha
    time_t tiempo = time(0);struct tm *tlocal = localtime(&tiempo);
    strftime(Tiempo,128," %d/%m/%y %H:%M:%S",tlocal);printf("%s",Tiempo);
    printf(" Bienvenidos!\n");Sleep(100);
    puts("\n\t1 > Comprar chocolate.\n\t2 > Informacion de gustos.\n\t3 > Informacion de precios.");
    puts("\t4 > Informacion de promociones.\n\t5 > Salir.");printf("%s\n",Linea);
    printf(" Elija una opcion: ");scanf("%d",&Opcion_1);printf("%s",Linea);switch(Opcion_1){
    case 1:Sleep(500);Eleccion_1();break;
    case 2:Sleep(500);Eleccion_2();break;
    case 3:
    printf(" Chocolate  1 100 gramos = $50\n");
    printf(" Chocolate  2 100 gramos = $50\n");
    printf(" Chocolate  3 100 gramos = $70\n");
    printf(" Chocolate  4 100 gramos = $60\n");
    printf(" Chocolate  5 100 gramos = $60\n");
    printf(" Chocolate  6 100 gramos = $60\n");
    printf(" Chocolate  7 100 gramos = $60\n");
    printf(" Chocolate  8 100 gramos = $60\n");
    printf(" Chocolate  9 100 gramos = $90\n");
    printf(" Chocolate  10 100 gramos = $90\n");
    case 4:printf("Descuento en envio\n");
    }}while(Opcion_1!=5);
}
//Eleccion 1
void Eleccion_1(){
    //Eleccion de sabores
    printf("\n Sabores disponibles:\n\n\t1 > %s.\n\t2 > %s.\n\t3 > %s.\n",Sabores_Chocolates.Sabor_1,Sabores_Chocolates.Sabor_2,Sabores_Chocolates.Sabor_3);
    printf(" \t4 > %s.\n\t5 > %s.\n\t6 > %s.\n\t7 > %s.\n",Sabores_Chocolates.Sabor_4,Sabores_Chocolates.Sabor_5,Sabores_Chocolates.Sabor_6,Sabores_Chocolates.Sabor_7);
    printf(" \t8 > %s.\n\t9 > %s.\n\t10 > %s.\n\n",Sabores_Chocolates.Sabor_8,Sabores_Chocolates.Sabor_9,Sabores_Chocolates.Sabor_10);printf("%s\n",Linea);Sleep(500);
    printf(" Cuantos sabores desea?: ");scanf("%d",&Cantidad);printf("%s\n",Linea);
    if(Cantidad>=1&&Cantidad <=12){printf(" Elija sus sabores e indique la cantidad:\n\n");
    for(x=0;x<Cantidad;x++){printf(" Sabor %d: ",x+1);scanf("%d",&Eleccion[x]);
    if(Eleccion[x]>=1&&Eleccion[x]<=10){
    printf(" Cantidad: ");scanf("%f",&Cantidad_Gramos[x]);}else{
    printf(" El sabor ingresado no es valido.\n");x=x-1;}printf("%s\n",Linea);
    }}else{printf(" La cantidad ingresada no es valida.\n");}
    for(x=0;x<Cantidad;x++){switch(Eleccion[x]){
    case 1:Totales[x]=Cantidad_Gramos[x]*0.5;break;
    case 2:Totales[x]=Cantidad_Gramos[x]*0.5;break;
    case 3:Totales[x]=Cantidad_Gramos[x]*0.7;break;
    case 4:Totales[x]=Cantidad_Gramos[x]*0.6;break;
    case 5:Totales[x]=Cantidad_Gramos[x]*0.6;break;
    case 6:Totales[x]=Cantidad_Gramos[x]*0.6;break;
    case 7:Totales[x]=Cantidad_Gramos[x]*0.6;break;
    case 8:Totales[x]=Cantidad_Gramos[x]*0.6;break;
    case 9:Totales[x]=Cantidad_Gramos[x]*0.9;break;
    case 10:Totales[x]=Cantidad_Gramos[x]*0.9;break;
    }}
    Menu_Envio();
}
//Eleccion 2
void Eleccion_2(){
    //Eleccion de chocolate para descripcion
    printf("\n Elija el chocolate para leer su descripcion:");Sleep(500);
    printf("\n\n\t1 > %s.\n\t2 > %s.\n\t3 > %s.\n",Sabores_Chocolates.Sabor_1,Sabores_Chocolates.Sabor_2,Sabores_Chocolates.Sabor_3);
    printf(" \t4 > %s.\n\t5 > %s.\n\t6 > %s.\n\t7 > %s.\n",Sabores_Chocolates.Sabor_4,Sabores_Chocolates.Sabor_5,Sabores_Chocolates.Sabor_6,Sabores_Chocolates.Sabor_7);
    printf(" \t8 > %s.\n\t9 > %s.\n\t10 > %s.\n",Sabores_Chocolates.Sabor_8,Sabores_Chocolates.Sabor_9,Sabores_Chocolates.Sabor_10);printf("%s\n",Linea);
    printf(" Chocolate N: ");scanf("%d",&Info_Chocolate);printf("%s\n",Linea);
    if(Info_Chocolate>=1&&Info_Chocolate<=10){
    switch(Info_Chocolate){ //Agregar descripcion de cada chocolate:
    case 1:printf("\t\t%s: \'Descripcion\'\n",Sabores_Chocolates.Sabor_1);break;
    case 2:printf("\t\t%s: \'Descripcion\'\n",Sabores_Chocolates.Sabor_2);break;
    case 3:printf("\t\t%s: \'Descripcion\'\n",Sabores_Chocolates.Sabor_3);break;
    case 4:printf("\t\t%s: \'Descripcion\'\n",Sabores_Chocolates.Sabor_4);break;
    case 5:printf("\t\t%s: \'Descripcion\'\n",Sabores_Chocolates.Sabor_5);break;
    case 6:printf("\t\t%s: \'Descripcion\'\n",Sabores_Chocolates.Sabor_6);break;
    case 7:printf("\t\t%s: \'Descripcion\'\n",Sabores_Chocolates.Sabor_7);break;
    case 8:printf("\t\t%s: \'Descripcion\'\n",Sabores_Chocolates.Sabor_8);break;
    case 9:printf("\t\t%s: \'Descripcion\'\n",Sabores_Chocolates.Sabor_9);break;
    case 10:printf("\t\t%s: \'Descripcion\'\n",Sabores_Chocolates.Sabor_10);break;
    }printf("%s",Linea);}else{
    Sleep(500);printf(" El chocolate ingresado no es valido.\n");}
}
//Menu envio
void Menu_Envio(){
    //Eleccion Nacional o Local
    printf(">>>>>>>>>>>>> Proceso de envio:\n%s\n Su envio sera:\n\n\t1) Nacional\t(501/600KM).\n\t",Linea);
    printf("2) Local\t(400/500KM).\n\t3) Ingresar manualmente los Kilometros.\n%s\n",Linea);
    for(x=0;x<=2;x++){
        printf(" Ingrese su eleccion: ",Linea);
        scanf("%d",&Eleccion_Envio_1);
        if(Eleccion_Envio_1==1||Eleccion_Envio_1==2||Eleccion_Envio_1==3){
            x=2;
        }else{
            Sleep(500);printf("%s\n La eleccion ingresada no es valida.\n%s\n",Linea,Linea);
            x=0;
        }
    }
    //Seguimiento de eleccion o ingreso manual de km para determinacion
    switch(Eleccion_Envio_1){
        case 1:Sleep(500);printf("%s\n>>>>>>>>>>>>>>>>> Envio nacional.\n%s\n",Linea,Linea);Envio_Nacional();break;
        case 2:Sleep(500);printf("%s\n>>>>>>>>>>>>>>>>> Envio local.\n",Linea,Linea);Envio_Local();break;
        case 3:Sleep(500);
        for(x=0;x<=2;x++){
            printf("%s\n Porfavor ingrese la cantidad de kilmentros: ",Linea);scanf("%d",&Datos_Usuario.Cant_KM_Envio);
            if(Datos_Usuario.Cant_KM_Envio>0&&Datos_Usuario.Cant_KM_Envio<600){
                if(Datos_Usuario.Cant_KM_Envio>501){
                    Sleep(500);Envio_Nacional();
                }else if(Datos_Usuario.Cant_KM_Envio<501&&Datos_Usuario.Cant_KM_Envio>400){
                    Sleep(500);Envio_Local();
                }
                x=2;
            }else if(Datos_Usuario.Cant_KM_Envio<0){
                Sleep(500);printf("%s\n La cantidad de kilometros ingresada no es valida.\n",Linea);
                x=0;
            }else if(Datos_Usuario.Cant_KM_Envio>600){
                Sleep(500);printf("%s\n La cantidad de kilometros ingresada supera el limite de envio nacional.\n",Linea);
                x=0;
            }
        }break;
    }
}
//Envio Nacional
    //Seleccion de provincia
    printf(" Seleccione su provincia:\n%s\n\t1) %s\t\t13) %s\n\t2) %s\t",Linea,Provincias.Provincia_1,Provincias.Provincia_13,Provincias.Provincia_2);
    printf("\t14) %s\n\t3) %s\t\t15) %s\n\t4) %s\t",Provincias.Provincia_14,Provincias.Provincia_3,Provincias.Provincia_15,Provincias.Provincia_4);
    printf("\t16) %s\n\t5) %s\t\t17) %s\n\t6) %s\t",Provincias.Provincia_16,Provincias.Provincia_5,Provincias.Provincia_17,Provincias.Provincia_6);
    printf("\t18) %s\n\t7) %s\t\t19) %s\n\t8) %s\t",Provincias.Provincia_18,Provincias.Provincia_7,Provincias.Provincia_19,Provincias.Provincia_8);
    printf("\t20) %s\n\t9) %s\t\t21) %s\n\t10) %s\t",Provincias.Provincia_20,Provincias.Provincia_9,Provincias.Provincia_21,Provincias.Provincia_10);
    printf("\t22) %s\n\t11) %s\t\t23) %s\n\t12) %s\n",Provincias.Provincia_22,Provincias.Provincia_11,Provincias.Provincia_23,Provincias.Provincia_12);
    for(x=0;x<=2;x++){
        printf("%s\n Provincia N: ",Linea);scanf("%d",&Eleccion_Provincia);
        if(Eleccion_Provincia==1||Eleccion_Provincia==2||Eleccion_Provincia==3||Eleccion_Provincia==4||Eleccion_Provincia==5||Eleccion_Provincia==6||Eleccion_Provincia==7||
        Eleccion_Provincia==8||Eleccion_Provincia==9||Eleccion_Provincia==10||Eleccion_Provincia==11||Eleccion_Provincia==12||Eleccion_Provincia==13||Eleccion_Provincia==14||
        Eleccion_Provincia==15||Eleccion_Provincia==16||Eleccion_Provincia==17||Eleccion_Provincia==18||Eleccion_Provincia==19||Eleccion_Provincia==20||Eleccion_Provincia==22||
        Eleccion_Provincia==23){
            x=2;
        }else{
            Sleep(500);printf("%s\n El numero no se encuentra en la lista.\n",Linea);
            x=0;
        }
    }
    //Vaciado de buffer
    fflush(stdin);Sleep(500);
    printf("%s\n>>>>>>>>>>>>>>>>> Ingreso de datos para el envio:\n%s\n Ingrese su Nombre Completo: ",Linea,Linea);gets(Datos_Usuario.Nombre_Completo_Usuario);
    printf("%s\n Ingrese su Numero de Documento (DNI): ",Linea);gets(Datos_Usuario.DNI_Usuario);
    printf("%s\n Ingrese su Direccion (Nombre de calle): ",Linea);gets(Datos_Usuario.Nombre_Direccion_Usuario);
    printf("%s\n Ingrese la altura de su direccion (Numero): ",Linea);scanf("%d",&Datos_Usuario.Numero_Direccion_Usuario);
    Algoritmo_Conveniencia_Nacional();
}
//Envio Local
void Envio_Local(){
    fflush(stdin);Sleep(500);
    printf("%s\n>>>>>>>>>>>>>>>>> Ingreso de datos para el envio:\n%s\n Ingrese su Nombre Completo: ",Linea,Linea);gets(Datos_Usuario.Nombre_Completo_Usuario);
    printf("%s\n Ingrese su Numero de Documento (DNI): ",Linea);gets(Datos_Usuario.DNI_Usuario);
    printf("%s\n Ingrese su Direccion (Nombre de calle): ",Linea);gets(Datos_Usuario.Nombre_Direccion_Usuario);
    printf("%s\n Ingrese la altura de su direccion (Numero): ",Linea);scanf("%d",&Datos_Usuario.Numero_Direccion_Usuario);
    //Llmado de funcion
    Algoritmo_Conveniencia_Local();
}
//Conveniencia de precio local
void Algoritmo_Conveniencia_Local(){
    printf("\n%s\n>>>>> A continuacion se le indicara el correo de menor costo\n%s\n",Linea,Linea);Sleep(500);
    for(x=0;x<Cantidad;x++){
        Cantidad_TOTAL_GRAMOS=Cantidad_TOTAL_GRAMOS+Cantidad_Gramos[x];
    }
    if(Cantidad_TOTAL_GRAMOS<=5000){
        printf(" Correo: %s en su seccion: %s Local, con el costo de: $%d\n%s\n",Correos.Correo_OCA,Correos.E_Simple,Correos.OCA_Precio_EL_S1,Linea);Factura_Costo();Sleep(500);
    }
    if(Cantidad_TOTAL_GRAMOS>5000&&Cantidad_TOTAL_GRAMOS<=15000){
        printf(" Correo: %s en su seccion: %s Local, con el costo de: $%d\n",Correos.Correo_OCA,Correos.E_Simple,Correos.OCA_Precio_EL_S1+Correos.Estampilla_Exceso_L);
        printf(" (+1 Estampilla de exceso +10kg)\n%s\n",Linea);Factura_Costo();Sleep(500);
    }
    if(Cantidad_TOTAL_GRAMOS>15000&&Cantidad_TOTAL_GRAMOS<=25000){
        printf(" Correo: %s en su seccion: %s Local, con el costo de: $%d\n",Correos.Correo_OCA,Correos.E_Simple,Correos.OCA_Precio_EL_S1+Correos.Estampilla_Exceso_L+Correos.Estampilla_Exceso_L);
        printf(" (+2 Estampilla de exceso +10kg)\n%s\n",Linea);Factura_Costo();Sleep(500);
    }
}
//Conveniencia de precio nacional
void Algoritmo_Conveniencia_Nacional(){
    printf("\n%s\n>>>>> A continuacion se le indicara el correo de menor costo\n%s\n",Linea,Linea);
    for(x=0;x<Cantidad;x++){
        Cantidad_TOTAL_GRAMOS=Cantidad_TOTAL_GRAMOS+Cantidad_Gramos[x];
    }
    if(Cantidad_TOTAL_GRAMOS<=5000){
        Total_1=Total_1+200;
        printf(" Correo: %s en su seccion: %s Nacional, con el costo de: $%d\n%s\n",Correos.Correo_OCA,Correos.E_Simple,Correos.OCA_Precio_EN_S1,Linea);Factura_Costo();Sleep(500);
    }
    if(Cantidad_TOTAL_GRAMOS>5000&&Cantidad_TOTAL_GRAMOS<=15000){
        Total_1=Total_1+345;
        printf(" Correo: %s en su seccion: %s Nacional, con el costo de: $%d\n",Correos.Correo_OCA,Correos.E_Simple,Correos.OCA_Precio_EN_S1+Correos.Estampilla_Exceso_N);
        printf(" (+1 Estampilla de exceso +10kg)\n%s\n",Linea);Factura_Costo();Sleep(500);
    }
    if(Cantidad_TOTAL_GRAMOS>15000&&Cantidad_TOTAL_GRAMOS<=25000){
        Total_1=Total_1+490;
        printf(" Correo: %s en su seccion: %s Nacional, con el costo de: $%d\n",Correos.Correo_OCA,Correos.E_Simple,Correos.OCA_Precio_EN_S1+Correos.Estampilla_Exceso_N+Correos.Estampilla_Exceso_N);
        printf(" (+2 Estampilla de exceso +10kg)\n%s\n",Linea);Factura_Costo();Sleep(500);
    }
}
//Costo de factura
void Factura_Costo(){
    //Estructura para fecha
    time_t tiempo = time(0);struct tm *tlocal = localtime(&tiempo);
    strftime(Tiempo,128," %d/%m/%y %H:%M:%S",tlocal);printf("%s",Tiempo);
    printf("\tFACTURA:\n\n Producto:\t\t\tPrecio:\n\n");Sleep(500);
    for(x=0;x<Cantidad;x++){Total_1=Total_1+Totales[x];switch(Eleccion[x]){
    case 1:printf(" %s : \t\t$%.2f\n",Sabores_Chocolates.Sabor_1,Totales[x]);break;
    case 2:printf(" %s : \t\t$%.2f\n",Sabores_Chocolates.Sabor_2,Totales[x]);break;
    case 3:printf(" %s : \t$%.2f\n",Sabores_Chocolates.Sabor_3,Totales[x]);break;
    case 4:printf(" %s : \t\t$%.2f\n",Sabores_Chocolates.Sabor_4,Totales[x]);break;
    case 5:printf(" %s : \t$%.2f\n",Sabores_Chocolates.Sabor_5,Totales[x]);break;
    case 6:printf(" %s : \t\t$%.2f\n",Sabores_Chocolates.Sabor_6,Totales[x]);break;
    case 7:printf(" %s : \t$%.2f\n",Sabores_Chocolates.Sabor_7,Totales[x]);break;
    case 8:printf(" %s : \t\t$%.2f\n",Sabores_Chocolates.Sabor_8,Totales[x]);break;
    case 9:printf(" %s : \t\t$%.2f\n",Sabores_Chocolates.Sabor_9,Totales[x]);break;
    case 10:printf(" %s : \t\t$%.2f\n",Sabores_Chocolates.Sabor_10,Totales[x]);break;
    }}
    switch(Eleccion_Envio_1){
        case 1:if(Cantidad_TOTAL_GRAMOS<=5000){
        Total_1=Total_1+200;
        printf(" %s : \t\t$%d\n",Correos.E_Simple,Correos.OCA_Precio_EN_S1);
    }
    if(Cantidad_TOTAL_GRAMOS>5000&&Cantidad_TOTAL_GRAMOS<=15000){
        Total_1=Total_1+345;
        printf(" %s : \t\t$%d\n",Correos.E_Simple,Correos.OCA_Precio_EN_S1+Correos.Estampilla_Exceso_N);
    }
    if(Cantidad_TOTAL_GRAMOS>15000&&Cantidad_TOTAL_GRAMOS<=25000){
        Total_1=Total_1+490;
        printf(" %s : \t\t$%d\n",Correos.E_Simple,Correos.OCA_Precio_EN_S1+Correos.Estampilla_Exceso_N+Correos.Estampilla_Exceso_N);
    }break;
        case 2:if(Cantidad_TOTAL_GRAMOS<=5000){
        Total_1=Total_1+200;
        printf(" %s : \t\t$%d\n",Correos.E_Simple,Correos.OCA_Precio_EL_S1);
    }
    if(Cantidad_TOTAL_GRAMOS>5000&&Cantidad_TOTAL_GRAMOS<=15000){
        Total_1=Total_1+345;
        printf(" %s : \t\t$%d\n",Correos.E_Simple,Correos.OCA_Precio_EL_S1+Correos.Estampilla_Exceso_L);
    }
    if(Cantidad_TOTAL_GRAMOS>15000&&Cantidad_TOTAL_GRAMOS<=25000){
        Total_1=Total_1+490;
        printf(" %s : \t\t$%d\n",Correos.E_Simple,Correos.OCA_Precio_EL_S1+Correos.Estampilla_Exceso_L+Correos.Estampilla_Exceso_L);
    }break;
    }
    printf("\n Su compra tiene un costo total de: $:%.2f\n\n",Total_1);
    switch(Eleccion_Envio_1){
        case 1:printf(" ENVIO NACIONAL\n Retira:\t\t%s\n DNI:\t\t\t%s\n Direccion:\t\t%s ",Datos_Usuario.Nombre_Completo_Usuario,Datos_Usuario.DNI_Usuario,Datos_Usuario.Nombre_Direccion_Usuario);
               printf("%d\n TOTAL KM:\t\t501/600km\n",Datos_Usuario.Numero_Direccion_Usuario);
               switch(Eleccion_Provincia){
                    case 1:printf(" PROVINCIA: \t\t%s\n",Provincias.Provincia_1);break;
                    case 2:printf(" PROVINCIA: \t\t%s\n",Provincias.Provincia_2);break;
                    case 3:printf(" PROVINCIA: \t\t%s\n",Provincias.Provincia_3);break;
                    case 4:printf(" PROVINCIA: \t\t%s\n",Provincias.Provincia_4);break;
                    case 5:printf(" PROVINCIA: \t\t%s\n",Provincias.Provincia_5);break;
                    case 6:printf(" PROVINCIA: \t\t%s\n",Provincias.Provincia_6);break;
                    case 7:printf(" PROVINCIA: \t\t%s\n",Provincias.Provincia_7);break;
                    case 8:printf(" PROVINCIA: \t\t%s\n",Provincias.Provincia_8);break;
                    case 9:printf(" PROVINCIA: \t\t%s\n",Provincias.Provincia_9);break;
                    case 10:printf(" PROVINCIA: \t\t%s\n",Provincias.Provincia_10);break;
                    case 11:printf(" PROVINCIA: \t\t%s\n",Provincias.Provincia_11);break;
                    case 12:printf(" PROVINCIA: \t\t%s\n",Provincias.Provincia_12);break;
                    case 13:printf(" PROVINCIA: \t\t%s\n",Provincias.Provincia_13);break;
                    case 14:printf(" PROVINCIA: \t\t%s\n",Provincias.Provincia_14);break;
                    case 15:printf(" PROVINCIA: \t\t%s\n",Provincias.Provincia_15);break;
                    case 16:printf(" PROVINCIA: \t\t%s\n",Provincias.Provincia_16);break;
                    case 17:printf(" PROVINCIA: \t\t%s\n",Provincias.Provincia_17);break;
                    case 18:printf(" PROVINCIA: \t\t%s\n",Provincias.Provincia_18);break;
                    case 19:printf(" PROVINCIA: \t\t%s\n",Provincias.Provincia_19);break;
                    case 20:printf(" PROVINCIA: \t\t%s\n",Provincias.Provincia_20);break;
                    case 21:printf(" PROVINCIA: \t\t%s\n",Provincias.Provincia_21);break;
                    case 22:printf(" PROVINCIA: \t\t%s\n",Provincias.Provincia_22);break;
                    case 23:printf(" PROVINCIA: \t\t%s\n",Provincias.Provincia_23);break;
                }break;
        case 2:printf(" ENVIO LOCAL\n Retira: %s\n DNI: %s\n Direccion: %s ",Datos_Usuario.Nombre_Completo_Usuario,Datos_Usuario.DNI_Usuario,Datos_Usuario.Nombre_Direccion_Usuario);
               printf("%d\n TOTAL KM: 400/500km\n",Datos_Usuario.Numero_Direccion_Usuario);break;
    }
    if(Datos_Usuario.Cant_KM_Envio>501){
        Sleep(500);printf(" ENVIO NACIONAL\n Retira: %s\n DNI: %s\n Direccion: %s ",Datos_Usuario.Nombre_Completo_Usuario,Datos_Usuario.DNI_Usuario,Datos_Usuario.Nombre_Direccion_Usuario);
        printf("%d\n TOTAL KM: %d",Datos_Usuario.Numero_Direccion_Usuario,Datos_Usuario.Cant_KM_Envio);
    }else if(Datos_Usuario.Cant_KM_Envio<501&&Datos_Usuario.Cant_KM_Envio>400){
        Sleep(500);printf(" ENVIO LOCAL\n Retira: %s\n DNI: %s\n Direccion: %s ",Datos_Usuario.Nombre_Completo_Usuario,Datos_Usuario.DNI_Usuario,Datos_Usuario.Nombre_Direccion_Usuario);
        printf("%d\n TOTAL KM: %d\n",Datos_Usuario.Numero_Direccion_Usuario,Datos_Usuario.Cant_KM_Envio);
    }
}
