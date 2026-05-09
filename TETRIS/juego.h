#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

#include <stdint.h>
#include "tablero.h"

typedef struct
{
    int x;
    int y;

    const uint8_t (*forma)[4];

} tPieza;

int puedeMoverPieza(const tPieza* pieza, int dx, int dy);
void fijarPiezaEnTablero(uint8_t tablero[FILAS_TABLERO][COLUMNAS_TABLERO], const tPieza* pieza);

#endif // JUEGO_H_INCLUDED
