#ifndef SECTOR_H_INCLUDED
#define SECTOR_H_INCLUDED

typedef struct
{
    int id;//pk
    char descripcion[20];
}eSector;

#endif // SECTOR_H_INCLUDED
void mostrarSectores(eSector sectores[], int tam);
