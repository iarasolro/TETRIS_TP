#include "tablero.h"
#include "..\GBT_v2026.1C.01\include\GBT\gbt.h"
#include "color.h"

void inicializarTablero(uint8_t** tablero, uint8_t columnasTablero)
{
    for(uint8_t fila = 0; fila < FILAS_TABLERO; fila++)
    {
        for(uint8_t col = 0; col < columnasTablero; col++)
            tablero[fila][col] = T;
    }
}

void dibujarTablero(uint8_t** tablero, uint8_t columnasTablero, uint8_t origenX, uint8_t origenY)
{
    for(uint8_t fila = 0; fila < FILAS_TABLERO; fila++)
    {
        for(uint8_t col = 0; col < columnasTablero; col++)
        {
            if(tablero[fila][col] != T)
                dibujarBloque(origenX + col * TAM_BLOQUE, origenY + fila * TAM_BLOQUE, tablero[fila][col]);
        }
    }
}

void dibujarBloque(uint16_t x, uint16_t y, uint8_t color)
{
    for(uint8_t fila = 0; fila < TAM_BLOQUE; fila++)
    {
        for(uint8_t col = 0; col < TAM_BLOQUE; col++)
        {
            if(fila == 0 || fila == TAM_BLOQUE - 1 || col == 0 || col == TAM_BLOQUE - 1)
                gbt_dibujar_pixel(x + col, y + fila, G);
            else
                gbt_dibujar_pixel(x + col, y + fila, color);
        }
    }
}


void dibujarMarcoTablero(uint8_t columnasTablero, uint8_t origenX, uint8_t origenY)
{
    uint8_t ancho = columnasTablero * TAM_BLOQUE;
    uint8_t alto = FILAS_TABLERO * TAM_BLOQUE;

    for(uint8_t x = 0; x < ancho + 2; x++)
    {
        gbt_dibujar_pixel(origenX - 1 + x, origenY - 1, G);
        gbt_dibujar_pixel(origenX - 1 + x, origenY + alto, G);
    }

    for(uint8_t y = 0; y < alto + 2; y++)
    {
        gbt_dibujar_pixel(origenX - 1, origenY - 1 + y, G);
        gbt_dibujar_pixel(origenX + ancho, origenY - 1 + y, G);
    }
}

void dibujarTetrominio(const uint8_t pieza[TAM_TETROMINIO][TAM_TETROMINIO], uint16_t origenX, uint16_t origenY)
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
