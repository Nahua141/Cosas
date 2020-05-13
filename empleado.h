#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
#include "sector.h"
//como hacer una estructuras
typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct//dentro solo se definen variables
{
    //definicion de una estructura
    int id;
    char nombre[20];
    char sexo;
    int edad;
    float sueldo;
    eFecha fechaIngreso;
    int idSector;//fk
    int idObraSocial;
    int isEmpty;
} eEmpleado;
typedef struct
{
    int id;
    char descripcion[20];
}eObraSocial;
#endif // EMPLEADO_H_INCLUDED

void mostrarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamSec);
void mostrarEmpleado(eEmpleado x, eSector sectores[], int tamSec);
void ordenarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamSec);

void inicializarEmpleados(eEmpleado vec[], int tam);
void modificarEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSec);
int buscarLibre(eEmpleado vec[], int tam);
int buscarEmpleado(int id,eEmpleado vec[], int tam);
int  altaEmpleado(int id, eEmpleado vec[], int tam, eSector sectores[], int tamSec);
void bajaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSec);
void hardcodearEmpleados(eEmpleado vec[], int cant);
int cargarDescripcionSector(char descripcion[], int id, eSector sectores[], int tamSec);
