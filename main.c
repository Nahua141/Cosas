#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "sector.h"
#include "informes.h"
#include "comida.h"
#include "almuerzo.h"

#define T 10
#define TAMSEC 5
#define CANTHARDCODE 10
#define TAMCOM 5
#define TAMAL 50
int menu();
int main()
{
    char seguir='s';
    char confirma;
    int proximoId=1000;
    int proximoIdAlmuerzo= 20000;
    eEmpleado lista[T];
    eSector sectores[TAMSEC] = {{1,"Sistemas"}, {2, "RRHH"}, {3, "Ventas"}, {4, "Compras"}, {5, "Contable"}};
    eComida comidas[TAMCOM] = {{100,"Milanesas", 150}, {102, "Fideos", 120}, {103, "Pizza",140}, {104, "Ensalada", 200}, {105, "Arroz", 135}};
    eAlmuerzo almuerzos[TAMAL];

    inicializarEmpleados(lista, T);
    inicializarAlmuerzos(almuerzos, TAMAL);

    hardcodearEmpleados(lista, CANTHARDCODE);
    proximoId += CANTHARDCODE;

    do
    {
        switch(menu())
        {
        case 1:
            if(altaEmpleado(proximoId, lista, T, sectores, TAMSEC))
            {
                proximoId++;
            }
            break;
        case 2:
            modificarEmpleado(lista, T, sectores, TAMSEC);
            break;
        case 3:
            bajaEmpleado(lista, T, sectores, TAMSEC);
            break;
        case 4:
            printf("Ordenar\n");
            break;
        case 5:
            system("cls");
            mostrarEmpleados(lista, T, sectores, TAMSEC);
            break;
        case 6:
            informar(lista, T, sectores, TAMSEC);
            break;
        case 7:
            if(altaAlmuerzo(proximoIdAlmuerzo,almuerzos, TAMAL, lista, T, sectores, TAMSEC, comidas, TAMCOM))
            {
                proximoIdAlmuerzo++;
            }
            break;
        case 8:
            listarAlmuerzos(almuerzos, TAMAL, comidas, TAMCOM, lista, T);
            break;
        case 9:
            informar(lista, T, sectores, TAMSEC);
            break;
        case 10:
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
    while(seguir=='s');

    /*
        for(int i=0; i<T; i++)
        {

            printf("Ingrese id: ");
            scanf("%d", &lista[i].id);

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(lista[i].nombre);

            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &lista[i].sexo);

            printf("Ingrese edad: ");
            scanf("%d", &lista[i].edad);

            printf("Ingrese sueldo: ");
            scanf("%f", &lista[i].sueldo);
    //distintas formas de pedir que ingresen la fecha de ingreso

            printf("Ingrese fecha de ingreso dd/mm/aaaa: ");
            scanf("%d/%d/%d", &lista[i].fechaIngreso.dia, &lista[i].fechaIngreso.mes, &lista[i].fechaIngreso.anio);

           // otroEmpleado.fechaIngreso= auxFecha;
        }
    */

    /*
        printf("Ingrese fecha de ingreso dd/mm/aaaa: ");
        scanf("%d/%d/%d", &otroEmpleado.fechaIngreso.dia, &otroEmpleado.fechaIngreso.mes, &otroEmpleado.fechaIngreso.anio);
    */
    /*
        printf("Ingrese dia de ingreso: ");
        scanf("%d", &otroEmpleado.fechaIngreso.dia);

        printf("Ingrese mes de ingreso: ");
        scanf("%d", &otroEmpleado.fechaIngreso.mes);

        printf("Ingrese anio de ingreso: ");
        scanf("%d", &otroEmpleado.fechaIngreso.anio);
        */


    //  mostrarEmpleados(lista, T);
    //ordenarEmpleados(lista, T);

    //mostrarEmpleados(lista, T);
    return 0;
}

int menu()
{
    int opcion;
    system("cls");
    printf("*****Gestion de empleados*****\n\n");
    printf("1-Alta empleado\n");
    printf("2-Modificar empleado\n");
    printf("3-Baja empleado\n");
    printf("4-Ordenar empleados\n");
    printf("5-Listar empleados\n");
    printf("6-Informes\n");
    printf("7-Alta almuerzo\n");
    printf("8-Listar almuerzos\n");
    printf("9-Informes\n");
    printf("10-Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}








