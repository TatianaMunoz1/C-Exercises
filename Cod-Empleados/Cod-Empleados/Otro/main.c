#include <stdio.h>
#include <stdlib.h>

#include "eventos.h"
#include "empleados.h"


Evento vectorDeEvento[100];



Evento crearEventoDesdeChar(char aux[100]);
void cargarVectorDeEventos();
void mostrarEventos();

Empleado crearEmpleadoDesdeChar(char aux[100]);


int main()
{
    printf("Bienvenido al sistema \n");


   cargarVectorDeEventos();
    mostrarEventos();

    return 0;
}
