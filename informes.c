#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "sector.h"
#include "informes.h"

int menuInformes()
{
    char opcion;
    system("cls");
    printf("*****Informes Empleados*****\n\n");
    printf("a-Listar empleados de un anio\n");
    printf("b-Listar los empleado varones\n");
    printf("c-Total sueldos a pagar\n");
    printf("d-Informe Empleados sector\n");
    printf("e-Informe empleados por sectores\n");
    printf("f-Informe sueldos sector\n");
    printf("g-Informe mayor sueldo sector\n");
    printf("h-Informe mayor sueldo por sectores\n");
    printf("i-Aumentar sueldo sector\n");
    printf("j-Sector que mas cobra\n");
    printf("k-Informe k\n");
    printf("l-Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);

    return opcion;
}

void informar(eEmpleado vec[], int tam, eSector sectores[], int tamSec)
{
    char seguir = 's';
    char confirma;

    do
    {
        switch(menuInformes())
        {
        case 'a':
            informarEmpleadosPorAnio(vec, tam, sectores, tamSec);
            break;
        case 'b':
            informarEmpleadosVarones(vec, tam, sectores, tamSec);
            break;
        case 'c':
            informarTotalSueldos(vec, tam);
            break;
        case 'd':
            informarEmpleadosSector(vec, tam, sectores, tamSec);
            break;
        case 'e':
            informarEmpleadosPorSector(vec, tam, sectores, tamSec);
            break;
        case 'f':
            infromarTotalSueldosSector(vec, tam, sectores, tamSec);
            break;
        case 'g':
            informarMayorSueldoSector(vec, tam, sectores, tamSec);
            break;
        case 'h':
            informarMayorSueldoEmpleadoSector(vec, tam, sectores, tamSec);
            break;
        case 'i':
            aumentarSueldosSectorPorcentaje(vec, tam, sectores, tamSec);
            break;
        case 'j':
            sectorQueMasCobra(vec, tam, sectores, tamSec);
            break;
        case 'k':
            printf("Informe k");
            break;
        case 'l':
            printf("Confirma salida?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma== 's')
            {
                seguir='n';
            }
            break;
        }
        system("pause");
    }
    while(seguir =='s');
}
void informarEmpleadosPorAnio(eEmpleado vec[], int tam, eSector sectores[], int tamSec)
{
    int anio;
    int flag=0;

    system("cls");
    printf("*****Empleados por anio de ingreso*****\n");

    printf("Ingrese anio: ");
    scanf("%d", &anio);

    printf(" Id       Nombre     Sexo   Edad    Sueldo   Fecha ingreso\n\n");

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0 && vec[i].fechaIngreso.anio == anio)
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
void informarEmpleadosVarones(eEmpleado vec[], int tam, eSector sectores[], int tamSec)
{

    int flag=0;

    system("cls");
    printf("*****Empleados varones*****\n");



    printf(" Id       Nombre     Sexo   Edad    Sueldo   Fecha ingreso\n\n");

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0 && vec[i].sexo == 'm')
        {
            mostrarEmpleado(vec[i], sectores, tamSec);
            flag = 1;
        }
    }
    if(flag==0)
    {
        printf("No hay empleados varones que listar\n");
    }
}
void informarTotalSueldos(eEmpleado vec[], int tam)
{
    float total = 0;
    system("cls");
    printf("*****Informe total sueldos a pagar*****\n\n");
    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            total += vec[i].sueldo;
        }
    }
    printf("Total sueldos a pagar $ %.2f\n\n", total);
}
void informarEmpleadosPorSector(eEmpleado empleados[], int tam, eSector sectores[], int tamsec)
{
    int flag;
    system("cls");
    printf("*****Informe empleados por sector*****\n\n");
    //recorro los sectores
    for(int s=0; s < tamsec; s++)
    {
        flag = 0;
        printf("Sector: %s\n",sectores[s].descripcion);
        printf(" --------------\n\n");
        //recorro los empleados buscando aquellos del sector donde estoy parado
        for(int e=0; e < tam; e++)
        {
            if(empleados[e].isEmpty == 0 && empleados[e].idSector == sectores[s].id)
            {
                mostrarEmpleado(empleados[e], sectores, tamsec);
                flag = 1;
            }
        }
        if(flag == 0)
        {
            printf("\nNo hay empleados en este sector\n\n");
        }
        printf("\n------------------------------------------------\n");
    }

}
void informarEmpleadosSector(eEmpleado empleados[], int tam, eSector sectores[], int tamSec)
{
    int idSector;
    int flag = 0;
    system("cls");
    printf("*****Informe empleados sector*****\n\n");
    mostrarSectores(sectores, tamSec);
    printf("Ingrese id del sector: ");
    scanf("%d", &idSector);
    printf(" Id       Nombre     Sexo   Edad    Sueldo   Fecha ingreso  Sector\n\n");
    for(int i=0; i<tam; i++)
    {
        if(empleados[i].isEmpty == 0 && empleados[i].idSector == idSector)
        {
            mostrarEmpleado(empleados[i], sectores, tamSec);
            flag=1;
        }
    }
    if(flag == 0)
    {
        printf("No hay empleados en este sector\n\n");
    }
}
void infromarTotalSueldosSector(eEmpleado empleados[], int tam, eSector sectores[], int tamSec)
{
    int idSector;
    float totalSueldos = 0;
    char descripcionSector[20];
    system("cls");
    printf("*****Informe total sueldos sector*****\n\n");
    mostrarSectores(sectores, tamSec);
    printf("Ingrese id del sector: ");
    scanf("%d", &idSector);

    for(int i=0; i<tam; i++)
    {
        if(empleados[i].isEmpty == 0 && empleados[i].idSector == idSector)
        {
            totalSueldos= totalSueldos + empleados[i].sueldo;

        }
    }
    cargarDescripcionSector(descripcionSector, idSector, sectores, tamSec);
    printf("\nTotal sueldos sector %s: $%.2f\n\n", descripcionSector, totalSueldos);
}
void informarMayorSueldoSector(eEmpleado empleados[], int tam, eSector sectores[], int tamsec)
{
    int idSector;
    int flag = 0;
    float mayorSueldo = 0;
    char nombreSector[20];

    system("cls");
    printf("*****Informe mayor sueldo sector*****\n\n");

    mostrarSectores(sectores, tamsec);
    printf("Ingrese id del sector: ");
    scanf("%d", &idSector);

    for(int i=0; i<tam; i++)
    {
        if(empleados[i].isEmpty == 0 && empleados[i].idSector == idSector)
        {
            if(empleados[i].sueldo > mayorSueldo || flag == 0)
            {
                mayorSueldo = empleados[i].sueldo;
                flag = 1;
            }
        }
    }

    cargarDescripcionSector(nombreSector, idSector, sectores, tamsec);

    printf("\nEl mayor sueldo del sector %s es: $%.2f\n\n",nombreSector, mayorSueldo);
}
void informarMayorSueldoEmpleadoSector(eEmpleado empleados[], int tam, eSector sectores[], int tamsec)
{
    int flag;
    float mayorSueldo;
    system("cls");
    printf("*****Informe mayor suledo por sector*****\n\n");
    //recorro los sectores
    for(int s=0; s < tamsec; s++)
    {
        flag = 0;
        mayorSueldo = 0;
        printf("Sector: %s\n",sectores[s].descripcion);
        printf(" --------------\n\n");
        //recorro los empleados buscando aquellos del sector donde estoy parado
        for(int e=0; e < tam; e++)
        {
            if(empleados[e].isEmpty == 0 && empleados[e].idSector == sectores[s].id)
            {
                if(empleados[e].sueldo > mayorSueldo || flag == 0)
            {
                mayorSueldo = empleados[e].sueldo;
                flag = 1;
            }

            }
        }
        if(flag == 0)
        {
            printf("\nNo hay empleados en este sector\n\n");
        }

        printf("\nEl mayor sueldo es: $%.2f\n", mayorSueldo);

        printf("\n------------------------------------------------\n");
    }
}
void aumentarSueldosSectorPorcentaje(eEmpleado empleados[], int tam, eSector sectores[], int tamsec)
{
    int idSector;
    int flag = 0;
    char nombreSector[20];
    int porcentaje;
    float aumento;

    system("cls");
    printf("*****Modificar sueldos sector porcentaje*****\n\n");

    mostrarSectores(sectores, tamsec);
    printf("Ingrese id del sector: ");
    scanf("%d", &idSector);

    printf("Ingrese porcentaje aumento: ");
    scanf("%d", &porcentaje);

    for(int i=0; i<tam; i++)
    {
        if(empleados[i].isEmpty == 0 && empleados[i].idSector == idSector)
        {
            aumento = empleados[i].sueldo*porcentaje / 100;
            empleados[i].sueldo = empleados[i].sueldo + aumento;
            flag=1;
        }
    }
    if(flag == 1)
    {
        printf("Se han modificado los sueldos con exito\n");
    }
    else
    {
        printf("No hay empleados a quienes aumentar el sueldo\n");
    }

    cargarDescripcionSector(nombreSector, idSector, sectores, tamsec);


}
float obtenerTotalSueldosSector(int idSector, eEmpleado empleados[], int tam)
{
    float totalSueldos = 0;

    for(int i=0; i< tam; i++)
    {
        if(empleados[i].isEmpty == 0 && empleados[i].idSector == idSector)
        {
            totalSueldos += empleados[i].sueldo;
        }
    }
    return totalSueldos;
}
void sectorQueMasCobra(eEmpleado empleados[], int tam, eSector sectores[], int tamsec)
{
    float totalSueldos[tamsec];
    float mayorTotal;
    int flag = 0;

    system("cls");
    printf("*****Sector que mas cobra*****\n\n");

    for(int s=0; s < tamsec; s++)
    {
        totalSueldos[s]= obtenerTotalSueldosSector(sectores[s].id, empleados, tam);

    }
    for(int s = 0; s < tamsec; s++)
    {
        if(totalSueldos[s] > mayorTotal || flag == 0)
        {
            mayorTotal= totalSueldos[s];
            flag = 1;
        }
    }
    printf("El total de sueldos mayor es $%.2f y pertenece al sector: \n\n", mayorTotal);
    for(int s=0; s<tamsec; s++)
    {
        if(totalSueldos[s] == mayorTotal)
        {
            printf(" %s\n", sectores[s].descripcion);
        }
    }
}

