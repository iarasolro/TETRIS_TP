#ifndef TABLERO_H_INCLUDED
#define TABLERO_H_INCLUDED

#include "..\GBT_v2026.1C.01\include\GBT\gbt.h"
#include "dibujos.h"

#define FILAS_TABLERO 20
#define COLUMNAS_TABLERO_CLASICO 10
#define COLUMNAS_TABLERO_MIN_DX 8
#define COLUMNAS_TABLERO_MAX_DX 16
#define COLUMNAS_TABLERO_MAX 16

void inicializarTablero(uint8_t** tablero, uint8_t columnasTablero);
void dibujarTablero(uint8_t** tablero, uint8_t columnasTablero, uint8_t origenX, uint8_t origenY);

void dibujarMarcoTablero(uint8_t columnasTablero, uint8_t origenX, uint8_t origenY);

void dibujarBloque(uint16_t x, uint16_t y, uint8_t color);




void dibujarTetrominio(const uint8_t pieza[TAM_TETROMINIO][TAM_TETROMINIO], uint16_t origenX, uint16_t origenY);

#endif // TABLERO_H_INCLUDED
