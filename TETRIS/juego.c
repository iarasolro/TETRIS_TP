#include "juego.h"
#include "tablero.h"
#include "color.h"
#include "tetrominio.h"
#include "color.h"

#include <stdio.h>

int inicializarJuego(void)
{
    if(gbt_iniciar() != 0)
    {
        fprintf(stderr, "Error al iniciar GBT: %s\n", gbt_obtener_log());
        return -1;
    }

    char nombreVentana[128];
    sprintf(nombreVentana,"Tetris %dx%d", ANCHO_VENTANA, ALTO_VENTANA);

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

    return 0;
}

void cerrarJuego(tGBT_Temporizador* temporizadorCaida, tGBT_Temporizador* temporizadorFijacion)
{
    gbt_temporizador_destruir(temporizadorCaida);
    gbt_temporizador_destruir(temporizadorFijacion);
    gbt_destruir_ventana();
    gbt_cerrar();
}

int puedeMoverPieza(uint8_t** tablero, uint8_t columnasTablero, const tPieza* pieza, int dx, int dy)
{
    for(uint8_t fila = 0; fila < TAM_TETROMINIO; fila++)
    {
        for(uint8_t col = 0; col < TAM_TETROMINIO; col++)
        {
            if(pieza->forma[fila][col] != T)
            {
                int nuevaX = pieza->x + col + dx;
                int nuevaY = pieza->y + fila + dy;

                if(nuevaX < 0 || nuevaX >= columnasTablero)
                    return 0;

                if(nuevaY < 0 || nuevaY >= FILAS_TABLERO)
                    return 0;

                if(tablero[nuevaY][nuevaX] != T)
                    return 0;
            }
        }
    }

    return 1;
}

void fijarPiezaEnTablero(uint8_t** tablero, const tPieza* pieza)
{
    for(uint8_t fila = 0; fila < TAM_TETROMINIO; fila++)
    {
        for(uint8_t col = 0; col < TAM_TETROMINIO; col++)
        {
            uint8_t color = pieza->forma[fila][col];

            if(color != T)
            {
                int tableroX = pieza->x + col;
                int tableroY = pieza->y + fila;

                tablero[tableroY][tableroX] = color;
            }
        }
    }
}

void reiniciarTemporizadoresJuego(tGBT_Temporizador** temporizadorCaida, tGBT_Temporizador** temporizadorFijacion, uint16_t tiempoCaidaMs)
{
    gbt_temporizador_destruir(*temporizadorCaida);
    gbt_temporizador_destruir(*temporizadorFijacion);

    *temporizadorCaida = gbt_temporizador_crear(tiempoCaidaMs / 1000.0);

    *temporizadorFijacion = gbt_temporizador_crear((tiempoCaidaMs / 2) / 1000.0);
}

void reiniciarTemporizadorFijacion(tGBT_Temporizador** temporizador, uint16_t tiempoCaidaMs)
{
    gbt_temporizador_destruir(*temporizador);

    *temporizador = gbt_temporizador_crear((tiempoCaidaMs / 2) / 1000.0);
}

int limpiarLineasCompletas(uint8_t** tablero, uint8_t columnasTablero)
{
    int lineasEliminadas = 0;

    for(int fila = FILAS_TABLERO - 1; fila >= 0; fila--)
    {
        int completa = 1;

        for(int col = 0; col < columnasTablero; col++)
        {
            if(tablero[fila][col] == T)
                completa = 0;
        }

        if(completa)
        {
            uint8_t* filaCompleta = tablero[fila];
            for(int f = fila; f > 0; f--)
                tablero[f] = tablero[f - 1];

            tablero[0] = filaCompleta;

            for(int col = 0; col < columnasTablero; col++)
                tablero[0][col] = T;

            lineasEliminadas++;
            fila++;
        }
    }

    return lineasEliminadas;
}

const uint8_t (*obtenerPiezaAleatoria(VersionJuego versionJuego))[4]
{
    if(versionJuego == VERSION_DX)
    {
        switch(rand() % 11)
        {
            case 0: return pieza_I;
            case 1: return pieza_O;
            case 2: return pieza_T;
            case 3: return pieza_S;
            case 4: return pieza_Z;
            case 5: return pieza_J;
            case 6: return pieza_L;
            case 7: return pieza_X;
            case 8: return pieza_C;
            case 9: return pieza_P;
            default: return pieza_B;
        }
    }
    switch(rand() % 7)
    {
        case 0: return pieza_I;
        case 1: return pieza_O;
        case 2: return pieza_T;
        case 3: return pieza_S;
        case 4: return pieza_Z;
        case 5: return pieza_J;
        default: return pieza_L;
    }
}

void copiarForma(uint8_t destino[4][4], const uint8_t origen[4][4])
{
    for(uint8_t fila = 0; fila < 4; fila++)
    {
        for(uint8_t col = 0; col < 4; col++)
        {
            destino[fila][col] = origen[fila][col];
        }
    }
}

void rotarPieza(tPieza* pieza)
{
    uint8_t temporal[4][4];

    for(uint8_t fila = 0; fila < 4; fila++)
    {
        for(uint8_t col = 0; col < 4; col++)
        {
            temporal[col][3 - fila] = pieza->forma[fila][col];
        }
    }

    for(uint8_t fila = 0; fila < 4; fila++)
    {
        for(uint8_t col = 0; col < 4; col++)
        {
            pieza->forma[fila][col] = temporal[fila][col];
        }
    }
}

int puedeRotarPieza(uint8_t** tablero, uint8_t columnasTablero, const tPieza* pieza)
{
    tPieza copia = *pieza;

    rotarPieza(&copia);

    for(uint8_t fila = 0; fila < 4; fila++)
    {
        for(uint8_t col = 0; col < 4; col++)
        {
            if(copia.forma[fila][col] != T)
            {
                int x = copia.x + col;
                int y = copia.y + fila;

                if(x < 0 || x >= columnasTablero)
                {
                    return 0;
                }

                if(y < 0 || y >= FILAS_TABLERO)
                {
                    return 0;
                }

                if(tablero[y][x] != T)
                {
                    return 0;
                }
            }
        }
    }

    return 1;
}

void reiniciarPartida(uint8_t** tablero, uint8_t columnasTablero, tPieza* actual, tPieza* siguiente, uint32_t* puntaje,
    uint32_t* nivel, uint32_t* piezasCaidas, uint16_t* tiempoCaidaMs, uint8_t* tocandoSuelo, EstadoJuego* estadoJuego, VersionJuego versionJuego)
{
    inicializarTablero(tablero, columnasTablero);

    actual->x = 3;
    actual->y = 0;
    copiarForma(actual->forma, obtenerPiezaAleatoria(versionJuego));

    siguiente->x = 0;
    siguiente->y = 0;
    copiarForma(siguiente->forma, obtenerPiezaAleatoria(versionJuego));

    *puntaje = 0;
    *nivel = 1;
    *piezasCaidas = 0;
    *tiempoCaidaMs = 1000;
    *tocandoSuelo = 0;
    *estadoJuego = ESTADO_JUGANDO;
}

void procesarEntradaJuego(eGBT_Tecla tecla, uint8_t** tablero, uint8_t columnasTablero, tPieza* actual, uint32_t* puntaje,
    uint8_t* corriendo, EstadoJuego* estadoJuego, uint8_t tocandoSuelo, tGBT_Temporizador** temporizadorFijacion, uint16_t tiempoCaidaMs)
{
    if(tecla == GBTK_p)
    {
        if(*estadoJuego == ESTADO_PAUSA)
            *estadoJuego = ESTADO_JUGANDO;
        else
            *estadoJuego = ESTADO_PAUSA;
    }

    if(tecla == GBTK_ESCAPE)
        *corriendo = 0;

    if(*estadoJuego == ESTADO_PAUSA)
        return;

    if(tecla == GBTK_ARRIBA &&
       puedeRotarPieza(tablero, columnasTablero, actual))
    {
        rotarPieza(actual);

        if(tocandoSuelo)
            reiniciarTemporizadorFijacion(temporizadorFijacion, tiempoCaidaMs);
    }

    if(tecla == GBTK_IZQUIERDA && puedeMoverPieza(tablero, columnasTablero, actual, -1, 0))
    {
        actual->x--;

        if(tocandoSuelo)
            reiniciarTemporizadorFijacion(temporizadorFijacion, tiempoCaidaMs);
    }

    if(tecla == GBTK_DERECHA &&
       puedeMoverPieza(tablero, columnasTablero, actual, 1, 0))
    {
        actual->x++;

        if(tocandoSuelo)
            reiniciarTemporizadorFijacion(temporizadorFijacion, tiempoCaidaMs);
    }

    if(tecla == GBTK_ABAJO &&
       puedeMoverPieza(tablero, columnasTablero, actual, 0, 1))
    {
        actual->y++;
        *puntaje += 1;
    }
}

void actualizarJuego(uint8_t** tablero, uint8_t columnasTablero, tPieza* actual, tPieza* siguiente,
                     uint32_t* puntaje, uint32_t* nivel, uint32_t* piezasCaidas, uint16_t* tiempoCaidaMs, uint8_t* tocandoSuelo,
                     EstadoJuego* estadoJuego, tGBT_Temporizador** temporizadorCaida, tGBT_Temporizador** temporizadorFijacion, VersionJuego versionJuego)
{
    if(gbt_temporizador_consumir(*temporizadorCaida))
    {
        if(puedeMoverPieza(tablero, columnasTablero, actual, 0, 1))
        {
            actual->y++;
            *tocandoSuelo = 0;
        }
        else
        {
            if(!(*tocandoSuelo))
            {
                *tocandoSuelo = 1;
                reiniciarTemporizadorFijacion(temporizadorFijacion, *tiempoCaidaMs);
            }
        }
    }

    if(*tocandoSuelo && gbt_temporizador_consumir(*temporizadorFijacion))
    {
        fijarPiezaEnTablero(tablero, actual);

        (*piezasCaidas)++;

        if(*piezasCaidas % 10 == 0)
        {
            *tiempoCaidaMs = *tiempoCaidaMs * 97 / 100;

            (*nivel)++;

            gbt_temporizador_destruir(*temporizadorCaida);
            *temporizadorCaida = gbt_temporizador_crear(*tiempoCaidaMs / 1000.0);
            reiniciarTemporizadorFijacion(temporizadorFijacion, *tiempoCaidaMs);
        }

        uint16_t lineas = limpiarLineasCompletas(tablero, columnasTablero);

        if(lineas == 1)
            *puntaje += lineas * 100;
        else if(lineas == 2)
            *puntaje += lineas * 105;
        else if(lineas == 3)
            *puntaje += lineas * 110;
        else if(lineas == 4)
            *puntaje += lineas * 120;

        actual->x = 3;
        actual->y = 0;

        copiarForma(actual->forma, siguiente->forma);
        copiarForma(siguiente->forma, obtenerPiezaAleatoria(versionJuego));

        *tocandoSuelo = 0;

        if(!puedeMoverPieza(tablero, columnasTablero, actual, 0, 0))
            *estadoJuego = ESTADO_GAME_OVER;
    }
}


