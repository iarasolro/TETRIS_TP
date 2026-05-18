#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

#include <stdint.h>
#include "tablero.h"

typedef enum
{
    ESTADO_MENU,
    ESTADO_JUGANDO,
    ESTADO_PAUSA,
    ESTADO_GAME_OVER
}EstadoJuego;

typedef enum
{
    VERSION_CLASICA,
    VERSION_DX
}VersionJuego;

typedef struct
{
    int x;
    int y;
    uint8_t forma [4][4];

}tPieza;

int inicializarJuego(void);
void cerrarJuego(tGBT_Temporizador* temporizadorCaida, tGBT_Temporizador* temporizadorFijacion);
int puedeMoverPieza(uint8_t** tablero, uint8_t columnasTablero, const tPieza* pieza, int dx, int dy);
void fijarPiezaEnTablero(uint8_t** tablero, const tPieza* pieza);
void reiniciarTemporizadoresJuego(tGBT_Temporizador** temporizadorCaida, tGBT_Temporizador** temporizadorFijacion, uint16_t tiempoCaidaMs);
void reiniciarTemporizadorFijacion(tGBT_Temporizador** temporizador, uint16_t tiempoCaidaMs);
int limpiarLineasCompletas(uint8_t** tablero, uint8_t columnasTablero);
const uint8_t (*obtenerPiezaAleatoria(VersionJuego versionJuego))[4];
void copiarForma(uint8_t destino[4][4], const uint8_t origen[4][4]);
void rotarPieza(tPieza* pieza);
int puedeRotarPieza(uint8_t** tablero, uint8_t columnasTablero, const tPieza* pieza);
void reiniciarPartida(uint8_t** tablero, uint8_t columnasTablero, tPieza* actual, tPieza* siguiente, uint32_t* puntaje,
    uint32_t* nivel, uint32_t* piezasCaidas, uint16_t* tiempoCaidaMs, uint8_t* tocandoSuelo, EstadoJuego* estadoJuego, VersionJuego versionJuego);
void procesarEntradaJuego(eGBT_Tecla tecla, uint8_t** tablero, uint8_t columnasTablero, tPieza* actual, uint32_t* puntaje,
    uint8_t* corriendo, EstadoJuego* estadoJuego, uint8_t tocandoSuelo, tGBT_Temporizador** temporizadorFijacion, uint16_t tiempoCaidaMs);
void actualizarJuego(uint8_t** tablero, uint8_t columnasTablero, tPieza* actual, tPieza* siguiente,
                     uint32_t* puntaje, uint32_t* nivel, uint32_t* piezasCaidas, uint16_t* tiempoCaidaMs, uint8_t* tocandoSuelo,
                     EstadoJuego* estadoJuego, tGBT_Temporizador** temporizadorCaida, tGBT_Temporizador** temporizadorFijacion, VersionJuego versionJuego);
#endif // JUEGO_H_INCLUDED
