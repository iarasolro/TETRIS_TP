#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>

#define MEM_EST 1
#define MEM_DIN 2


typedef void (*Accion)(void* pve, void* pvda, int filas, int columnas, int fila, int col);

void* crearMatriz(int filas, int columnas, size_t tamElem);
void destruirMatriz(void** mat, int filas);
void recorrerMatriz(int filas, int columnas, void* mat, size_t tamElem, int memMat, Accion accion, void* datosAccion);

#endif // MATRIZ_H_INCLUDED
