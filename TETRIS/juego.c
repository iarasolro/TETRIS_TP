#include "juego.h"
#include "tablero.h"
#include "color.h"

int puedeMoverPieza(const tPieza* pieza, int dx, int dy)
{
    for(uint8_t fila = 0; fila < TAM_TETROMINIO; fila++)
    {
        for(uint8_t col = 0; col < TAM_TETROMINIO; col++)
        {
            if(pieza->forma[fila][col] != T)
            {
                int nuevaX = pieza->x + col + dx;
                int nuevaY = pieza->y + fila + dy;

                if(nuevaX < 0 || nuevaX >= COLUMNAS_TABLERO)
                {
                    return 0;
                }

                if(nuevaY < 0 || nuevaY >= FILAS_TABLERO)
                {
                    return 0;
                }
            }
        }
    }

    return 1;
}

void fijarPiezaEnTablero(uint8_t tablero[FILAS_TABLERO][COLUMNAS_TABLERO], const tPieza* pieza)
{
    for(uint8_t fila = 0; fila < TAM_TETROMINIO; fila++)
    {
        for(uint8_t col = 0; col < TAM_TETROMINIO; col++)
        {
            uint8_t color = pieza->forma[fila][col];

            if(color != T)
            {
                int tableroX = pieza->x + col;
                int tableroY = pieza->y + fila;

                tablero[tableroY][tableroX] = color;
            }
        }
    }
}
