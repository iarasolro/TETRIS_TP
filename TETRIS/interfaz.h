#ifndef INTERFAZ_H_INCLUDED
#define INTERFAZ_H_INCLUDED

#define TABLERO_X   18
#define TABLERO_Y   4

#define UI_X 7
#define SIG_Y 1
#define SIG_PIEZA_X 76
#define SIG_PIEZA_Y 35

#define JUGADOR_Y   6
#define PUNTAJE_Y   8
#define TIEMPO_Y    10
#define NIVEL_Y     12


#include "juego.h"
#include "fuente.h"
#include "..\GBT_v2026.1C.01\include\GBT\gbt.h"
#include "dibujos.h"
#include "config.h"
#include "color.h"

#include <stdio.h>

void mostrarMenuPrincipal(void);
void procesarMenuPrincipal(EstadoJuego* estadoJuego, uint8_t* corriendo, char nombreJugador[], uint8_t* cantLetrasNombre, uint8_t* dificultad, uint16_t* tiempoCaidaMs, VersionJuego* versionJuego);

void mostrarPantallaNombre(const char* nombreJugador);
void procesarPantallaNombre(char nombreJugador[], uint8_t* cantLetrasNombre);

void mostrarPantallaDificultad(uint8_t dificultad);
void procesarPantallaDificultad(uint8_t* dificultad, uint16_t* tiempoCaidaMs);

void mostrarPantallaAyuda(void);
void procesarPantallaAyuda(void);

void mostrarPantallaVersion(VersionJuego versionJuego);
void procesarPantallaVersion(VersionJuego* versionJuego);


void dibujarJuego(uint8_t** tablero, uint8_t columnasTablero, const tPieza* actual, const tPieza* siguiente, uint32_t puntaje, uint16_t tiempoCaidaMs, uint32_t nivel, const char* nombreJugador);
uint8_t procesarPantallaGameOver(uint32_t puntaje);
void dibujarPantallaGameOver(uint32_t puntaje);
void mostrarPantallaPausa(void);

#endif
