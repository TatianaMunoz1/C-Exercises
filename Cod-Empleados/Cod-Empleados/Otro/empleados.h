#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED


struct EmpleadoEstructura;
typedef struct EmpleadoEstructura * Empleado;


Empleado crearEmpleado (char nombre[20], char apellido[20], int codigoEvento);
void mostrarEmpleado (Empleado e);


int getCodigoEvento(Empleado e);

#endif // EMPLEADOS_H_INCLUDED
