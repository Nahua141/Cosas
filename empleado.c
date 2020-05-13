#include "empleado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataWarehouse.h"
void mostrarEmpleado(eEmpleado x, eSector sectores[], int tamSec)
{
    char nombreSector[20];

    cargarDescripcionSector(nombreSector, x.idSector, sectores, tamSec);

    printf("%d   %10s      %c     %d    %6.2f   %02d/%02d/%4d  %10s\n", x.id, x.nombre, x.sexo, x.edad, x.sueldo, x.fechaIngreso.dia, x.fechaIngreso.mes, x.fechaIngreso.anio, nombreSector);

}
void mostrarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamSec)
{
    int flag=0;

    printf("*****Listado de empleados*****\n");
    printf(" Id       Nombre     Sexo   Edad    Sueldo   Fecha ingreso  Sector\n\n");
    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0)
        {
            mostrarEmpleado(vec[i], sectores, tamSec);
            flag = 1;
        }
    }
    if(flag==0)
    {
        printf("No hay empleados que listar\n");
    }
}
void ordenarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamSec)
{
    eEmpleado auxEmpleado;
    //burbujeo.
    for(int i=0; i< tam; i++)
    {
        for(int j=i; j<tam; j++)
        {
            if(vec[i].sexo > vec[j].sexo)
            {
                auxEmpleado=vec[i];
                vec[i]=vec[j];
                vec[j]=auxEmpleado;
            }
            else if (vec[i].sexo ==vec[j].sexo && strcmp(vec[i].nombre, vec[j].nombre)> 0)
            {
                auxEmpleado=vec[i];
                vec[i]=vec[j];
                vec[j]=auxEmpleado;
            }
        }
    }
}
void inicializarEmpleados(eEmpleado vec[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i].isEmpty=1;
    }
}
int buscarLibre(eEmpleado vec[], int tam)
{
    int indice=-1;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 1)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
int buscarEmpleado(int id, eEmpleado vec[], int tam)
{
    int indice=-1;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].id == id && vec[i].isEmpty == 0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
int altaEmpleado(int idx, eEmpleado vec[], int tam, eSector sectores[], int tamSec)
{
    int todoOk = 0;
    int indice = buscarLibre(vec, tam);
    //int id;
   // int existe;
    eEmpleado auxEmpleado;
    system("cls");

    printf("*****Estamos en alta empleado*****\n\n");

    if(indice == -1)//si hay lugar
    {
        printf("Sistema completo\n\n");
    }
    else
    {
        /*
        printf("Ingrese id: ");
        scanf("%d", &id);
        existe=buscarEmpleado(id, vec, tam);

        if(existe != -1)//si el id ya esta
        {
            printf("Ya existe un empleado regitrado con ese id\n");
        }
        else
        {
        */
        auxEmpleado.id=idx;

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(auxEmpleado.nombre);

        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &auxEmpleado.sexo);

        printf("Ingrese edad: ");
        scanf("%d", &auxEmpleado.edad);

        printf("ingrese sueldo: ");
        scanf("%f", &auxEmpleado.sueldo);

        printf("Ingrese fecha ingreso: ");
        scanf("%d/%d/%d", &auxEmpleado.fechaIngreso.dia, &auxEmpleado.fechaIngreso.mes, &auxEmpleado.fechaIngreso.anio);

        mostrarSectores(sectores, tamSec);
        printf("\n\nIngrese id del sector: ");
        scanf("%d", &auxEmpleado.idSector);

        auxEmpleado.isEmpty=0;

        vec[indice]=auxEmpleado;//copio al vector el empleado nuevo.
        todoOk = 1;
        //}
    }
    return todoOk;
}
void bajaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSec)
{
    int id;
    int indice;
    char confirma;
    system("cls");
    printf("*****Baja empleado*****\n\n");
    printf("Ingrese id: ");
    scanf("%d", &id);

    indice=buscarEmpleado(id, vec, tam);

    if(indice == -1)
    {

        printf("No hay registro de un empleado con el id: %d", id);
    }
    else
    {
        mostrarEmpleado(vec[indice], sectores, tamSec);

        printf("\nConfirma baja?: ");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma== 's')
        {
            vec[indice].isEmpty=1;
            printf("Se ha realizado la baja con exito\n\n");
        }
        else
        {
            printf("Se ha cancelado la operacion\n\n");
        }
    }
}
void modificarEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSec)
{
    int id;
    int indice;
    char confirma;
    float nuevoSueldo;
    system("cls");
    printf("*****Modificar empleado*****\n\n");
    printf("Ingrese id: ");
    scanf("%d", &id);

    indice=buscarEmpleado(id, vec, tam);

    if(indice == -1)
    {

        printf("No hay registro de un empleado con el id: %d", id);
    }
    else
    {
        mostrarEmpleado(vec[indice], sectores, tamSec);

        printf("\nModifica sueldo?: ");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma== 's')
        {
            printf("Ingrese nuevo sueldo: ");
            scanf("%f", &nuevoSueldo);
            vec[indice].sueldo= nuevoSueldo;
            printf("Se ha actualizado el sueldo con exito\n\n");
        }
        else
        {
            printf("Se ha cancelado la operacion\n\n");
        }
    }
}
void hardcodearEmpleados(eEmpleado vec[], int cant)
{
     for(int i=0; i<cant; i++)
    {
        vec[i].id = ids[i];
        strcpy(vec[i].nombre, nombres[i]);
        vec[i].edad= edades[i];
        vec[i].sexo=sexos[i];
        vec[i].sueldo=sueldos[i];
        vec[i].fechaIngreso.dia=dias[i];
        vec[i].fechaIngreso.mes=meses[i];
        vec[i].fechaIngreso.anio=anios[i];
        vec[i].idSector = idsSector[i];
        vec[i].isEmpty = 0;
    }
}
int cargarDescripcionSector(char descripcion[], int id, eSector sectores[], int tam)
{
    int todoOk = 0;

    for(int i=0; i<tam; i++)
    {
        if(sectores[i].id == id)
        {
            strcpy(descripcion, sectores[i].descripcion);
            todoOk = 1;
        }
    }
    return todoOk;
}
