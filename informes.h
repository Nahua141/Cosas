#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED
int menuInformes();
void informar(eEmpleado vec[], int tam, eSector sectores[], int tamSec);
void informarEmpleadosPorAnio(eEmpleado vec[], int tam, eSector sectores[], int tamSec);
void informarEmpleadosVarones(eEmpleado vec[], int tam, eSector sectores[], int tamSec);
void informarTotalSueldos(eEmpleado vec[], int tam);
void informarEmpleadosSector(eEmpleado empleados[], int tam, eSector sectores[], int tamSec);
void informarEmpleadosPorSector(eEmpleado empleados[], int tam, eSector sectores[], int tamsec);
void infromarTotalSueldosSector(eEmpleado empleados[], int tam, eSector sectores[], int tamSec);
void informarMayorSueldoSector(eEmpleado empleados[], int tam, eSector sectores[], int tamsec);
void informarMayorSueldoEmpleadoSector(eEmpleado empleados[], int tam, eSector sectores[], int tamsec);
void aumentarSueldosSectorPorcentaje(eEmpleado empleados[], int tam, eSector sectores[], int tamsec);
void sectorQueMasCobra(eEmpleado empleados[], int tam, eSector sectores[], int tamsec);
float obtenerTotalSueldosSector(int idSector, eEmpleado empleados[], int tam);
