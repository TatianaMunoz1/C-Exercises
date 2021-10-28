1-
Ordenar por DNI, los 5 clientes ya cargados. Para ordenar y a modo de ejemplo y ayuda se adjunta el método de ordenamiento para vectores. Crear/modificar la función que ordena a la estructura e invocarla desde el main.


struct  Cliente{

int DNI;

char nombreYApellido[50];

}clientes[5];



  int x,y,tmp;

 int n = TAMANIO; //tamaño del vector a[]

 for(x = 1; x < n; x++) {

      for(y = 0; y < n - x; y++) {

           if(a[y] > a[y + 1]) {

                tmp = a[y];

                a[y] = a[y + 1];

                a[y + 1] = tmp;             }         }     }


2-
Dado el siguiente archivo .h, realizar el .c pertinente, el main.c para testear el funcionamiento y de ser necesario agregar mas funciones o procedimientos al .h;

struct  AlumnoEstructura;

typedef AlumnoEstructura * Alumno;

Alumno crearAlumno (int dni, char nombre[20], char apellido[20], float promedio);

void mostrarAlumno (Alumno a);



}


3-Comentar y mencionar que imprime el siguiente código fuente:

int main(void)

{  int arreglo[] = {1,23,17,4,-5,100,2,8};

    int *ptr;

    int i;

    ptr = &arreglo[0];

   for (i = 0; i < 8; i++) {

       printf("%d\n", arreglo[i]);

       printf("%d\n", *(ptr +2));}

 return 0;}


4- Realizar un procedimiento recursivo que muestre todos los numeros desde un int inicial, hasta un int final. Puede ser ascedente o decreciente.

