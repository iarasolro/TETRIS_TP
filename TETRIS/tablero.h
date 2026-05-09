#ifndef TABLERO_H_INCLUDED
#define TABLERO_H_INCLUDED

#include "..\GBT_v2026.1C.01\include\GBT\gbt.h"
#include "dibujos.h"

#define FILAS_TABLERO 20
#define COLUMNAS_TABLERO 10


void inicializarTablero(uint8_t tablero[FILAS_TABLERO][COLUMNAS_TABLERO]);

void dibujarBloque(uint16_t x, uint16_t y, uint8_t color);

void dibujarTablero(uint8_t tablero[FILAS_TABLERO][COLUMNAS_TABLERO], uint16_t origenX, uint16_t origenY);

void dibujarTetrominio(const uint8_t pieza[TAM_TETROMINIO][TAM_TETROMINIO], uint16_t origenX, uint16_t origenY);

#endif // TABLERO_H_INCLUDED
