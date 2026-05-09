#include "tablero.h"
#include "..\GBT_v2026.1C.01\include\GBT\gbt.h"
#include "color.h"

void inicializarTablero(uint8_t tablero[FILAS_TABLERO][COLUMNAS_TABLERO])
{
    for(uint8_t fila = 0; fila < FILAS_TABLERO; fila++)
    {
        for(uint8_t col = 0; col < COLUMNAS_TABLERO; col++)
        {
            tablero[fila][col] = T;
        }
    }
}

void dibujarBloque(uint16_t x, uint16_t y, uint8_t color)
{
    for(uint8_t fila = 0; fila < TAM_BLOQUE; fila++)
    {
        for(uint8_t col = 0; col < TAM_BLOQUE; col++)
        {
            if(fila == 0 ||
               fila == TAM_BLOQUE - 1 ||
               col == 0 ||
               col == TAM_BLOQUE - 1)
            {
                gbt_dibujar_pixel(x + col, y + fila, G);
            }
            else
            {
                gbt_dibujar_pixel(x + col, y + fila, color);
            }
        }
    }
}

void dibujarTablero(uint8_t tablero[FILAS_TABLERO][COLUMNAS_TABLERO],
                    uint16_t origenX,
                    uint16_t origenY)
{
    for(uint8_t fila = 0; fila < FILAS_TABLERO; fila++)
    {
        for(uint8_t col = 0; col < COLUMNAS_TABLERO; col++)
        {
            if(tablero[fila][col] != T)
            {
                dibujarBloque
                (
                    origenX + col * TAM_BLOQUE,
                    origenY + fila * TAM_BLOQUE,
                    tablero[fila][col]
                );
            }
        }
    }
}

void dibujarTetrominio(const uint8_t pieza[TAM_TETROMINIO][TAM_TETROMINIO],
                       uint16_t origenX,
                       uint16_t origenY)
{
    for(uint8_t fila = 0; fila < TAM_TETROMINIO; fila++)
    {
        for(uint8_t col = 0; col < TAM_TETROMINIO; col++)
        {
            if(pieza[fila][col] != T)
            {
                dibujarBloque
                (
                    origenX + col * TAM_BLOQUE,
                    origenY + fila * TAM_BLOQUE,
                    pieza[fila][col]
                );
            }
        }
    }
}
