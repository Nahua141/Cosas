#ifndef ALMUERZO_H_INCLUDED
#define ALMUERZO_H_INCLUDED
#include "empleado.h"
#include "sector.h"
#include "comida.h"
typedef struct
{
    int id;
    int idEmpleado;
    int idComida;
    eFecha fecha;
    int isEmpty;
}eAlmuerzo;

#endif // ALMUERZO_H_INCLUDED

int buscarLibreAlmuerzo(eAlmuerzo vec[], int tam);
void inicializarAlmuerzos(eAlmuerzo almuerzos[], int tam);
void listarAlmuerzos(eAlmuerzo almuerzos[], int tamal, eComida comidas[], int tamcom, eEmpleado empleados[], int tamEmp);
void listarAlmuerzo(eAlmuerzo almuerzo, eComida comidas[], int tamcom, eEmpleado empleados[], int tamEmp);
int altaAlmuerzo(int idAlmuerzo, eAlmuerzo almuerzos[], int tamAl, eEmpleado empleados[], int tamEmp, eSector sectores[], int tamSec, eComida comidas[], int tamCom);
int cargarDescripcionComida(char descripcion[], int id, eComida comida[], int tam);
