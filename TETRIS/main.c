#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "..\GBT_v2026.1C.01\include\GBT\gbt.h"
#include "fuente.h"
#include "interfaz.h"
#include "tablero.h"
#include "tetrominio.h"
#include "config.h"
#include "color.h"
#include "juego.h"


int main()
{
    if(gbt_iniciar() != 0)
    {
        fprintf(stderr, "Error al iniciar GBT: %s\n", gbt_obtener_log());
        return -1;
    }

    char nombreVentana[128];
    sprintf(nombreVentana, "Tetris %dx%d", ANCHO_VENTANA, ALTO_VENTANA);

    if(gbt_crear_ventana(nombreVentana, ANCHO_VENTANA, ALTO_VENTANA, ESCALA_VENTANA) != 0)
    {
        fprintf(stderr, "Error al crear ventana: %s\n", gbt_obtener_log());
        return -1;
    }

    if(gbt_aplicar_paleta(paletaCGA, CANT_COLORES, GBT_FORMATO_888) != 0)
    {
        fprintf(stderr, "Error al aplicar paleta: %s\n", gbt_obtener_log());
        return -1;
    }

    srand(time(0));

    uint8_t tablero[FILAS_TABLERO][COLUMNAS_TABLERO];

    inicializarTablero(tablero);

    tPieza actual = {3, 0, pieza_T};

    uint8_t corriendo = 1;

    tGBT_Temporizador* temporizadorCaida = gbt_temporizador_crear(1.0);

    while(corriendo)
    {
        gbt_procesar_entrada();

        eGBT_Tecla tecla = gbt_obtener_tecla_presionada();

        if(tecla == GBTK_IZQUIERDA && puedeMoverPieza(&actual, -1, 0))
        {
            actual.x--;
        }

        if(tecla == GBTK_DERECHA && puedeMoverPieza(&actual, 1, 0))
        {
            actual.x++;
        }

        if(tecla == GBTK_ABAJO && puedeMoverPieza(&actual, 0, 1))
        {
            actual.y++;
        }

        if(tecla == GBTK_ESCAPE)
        {
            corriendo = 0;
        }

        // CAIDA AUTOMATICA
        if(gbt_temporizador_consumir(temporizadorCaida))
        {
            if(puedeMoverPieza(&actual, 0, 1))
            {
                actual.y++;
            }
            else
            {
                fijarPiezaEnTablero(tablero, &actual);

                actual.x = 3;
                actual.y = 0;
                actual.forma = pieza_T;
            }
        }

        gbt_borrar_backbuffer(N);

        dibujarTablero(tablero, 34, 4);

        dibujarTetrominio
        (
            actual.forma,
            34 + actual.x * TAM_BLOQUE,
            4 + actual.y * TAM_BLOQUE
        );

        gbt_volcar_backbuffer();

        gbt_esperar(16);
    }

    gbt_temporizador_destruir(temporizadorCaida);
    gbt_destruir_ventana();
    gbt_cerrar();

    return 0;
}
