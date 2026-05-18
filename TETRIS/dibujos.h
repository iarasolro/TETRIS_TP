#ifndef DIBUJOS_H_INCLUDED
#define DIBUJOS_H_INCLUDED

#include "..\GBT_v2026.1C.01\include\GBT\gbt.h"
#include "config.h"
#include "color.h"

#include <stdint.h>

#define PIXELES_X_LADO 8
#define PX_PADDING 1
#define TAM_TETROMINIO 4
#define TAM_BLOQUE 6


void dibujar(const uint8_t[][PIXELES_X_LADO], uint16_t oX, uint16_t oY);

#endif // DIBUJOS_H_INCLUDED
