#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "..\GBT_v2026.1C.01\include\GBT\gbt.h"
#include "interfaz.h"
#include "config.h"
#include "color.h"
#include "juego.h"
#include "matriz.h"


int main()
{
    if(inicializarJuego() != 0)
        return -1;

    srand(time(0));

    char nombreJugador[20] = "";
    uint8_t cantLetrasNombre = 0;
    uint8_t columnasTablero = COLUMNAS_TABLERO_CLASICO;
    uint8_t dificultad = 2;

    uint8_t** tablero =(uint8_t**)crearMatriz(FILAS_TABLERO, columnasTablero, sizeof(uint8_t));

    if(!tablero)
        return -1;

    tPieza actual, siguiente;

    uint16_t tiempoCaidaMs = 1000;
    uint8_t tocandoSuelo = 0;
    uint32_t puntaje = 0;
    uint32_t nivel = 1;
    uint32_t piezasCaidas = 0;
    uint8_t corriendo = 1;
    uint8_t reiniciarJuego = 0;

    EstadoJuego estadoJuego = ESTADO_MENU;
    VersionJuego versionJuego = VERSION_CLASICA;

    tGBT_Temporizador* temporizadorCaida = gbt_temporizador_crear(tiempoCaidaMs / 1000.0);
    tGBT_Temporizador* temporizadorFijacion = gbt_temporizador_crear((tiempoCaidaMs / 2) / 1000.0);
    eGBT_Tecla tecla;

    while(corriendo)
    {
        while(corriendo && estadoJuego == ESTADO_MENU)
            procesarMenuPrincipal(&estadoJuego, &corriendo, nombreJugador, &cantLetrasNombre, &dificultad, &tiempoCaidaMs, &versionJuego);

        if(estadoJuego == ESTADO_JUGANDO)
            {
                reiniciarPartida(tablero, columnasTablero, &actual, &siguiente, &puntaje, &nivel, &piezasCaidas, &tiempoCaidaMs, &tocandoSuelo, &estadoJuego, versionJuego);
                reiniciarTemporizadoresJuego(&temporizadorCaida, &temporizadorFijacion, tiempoCaidaMs);
            }

        while(corriendo && estadoJuego == ESTADO_JUGANDO)
        {
            gbt_procesar_entrada();
            tecla = gbt_obtener_tecla_presionada();
            procesarEntradaJuego(tecla, tablero, columnasTablero, &actual, &puntaje, &corriendo, &estadoJuego, tocandoSuelo, &temporizadorFijacion, tiempoCaidaMs);

            if(estadoJuego == ESTADO_PAUSA)
            {
                mostrarPantallaPausa();
                gbt_esperar(16);
                continue;
            }
            actualizarJuego(tablero, columnasTablero, &actual, &siguiente, &puntaje, &nivel, &piezasCaidas, &tiempoCaidaMs, &tocandoSuelo, &estadoJuego, &temporizadorCaida, &temporizadorFijacion, versionJuego);
            dibujarJuego(tablero, columnasTablero, &actual, &siguiente, puntaje, tiempoCaidaMs, nivel, nombreJugador);

            gbt_esperar(16);
        }

        if(estadoJuego == ESTADO_GAME_OVER)
        {
            reiniciarJuego = procesarPantallaGameOver(puntaje);

            if(reiniciarJuego)
            {
                reiniciarPartida(tablero, columnasTablero, &actual, &siguiente, &puntaje, &nivel, &piezasCaidas, &tiempoCaidaMs, &tocandoSuelo, &estadoJuego, versionJuego);
                reiniciarTemporizadoresJuego(&temporizadorCaida, &temporizadorFijacion, tiempoCaidaMs);
            }
            else
                corriendo = 0;
        }
    }

    destruirMatriz((void**)tablero, FILAS_TABLERO);
    cerrarJuego(temporizadorCaida, temporizadorFijacion);

    return 0;
}
