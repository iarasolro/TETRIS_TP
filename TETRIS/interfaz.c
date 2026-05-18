#include "interfaz.h"

void mostrarMenuPrincipal(void)
{
    gbt_borrar_backbuffer(N);

    dibujarTexto("TETRIS", 3, 1);

    dibujarTexto("N-NOMBRE", 1, 4);
    dibujarTexto("D-DIFICULTAD", 1, 5);
    dibujarTexto("F-FORMATO", 1, 6);
    dibujarTexto("V-VERSION", 1, 7);
    dibujarTexto("A-AYUDA", 1, 8);

    dibujarTexto("ENTER-JUGAR", 3, 9);
    dibujarTexto("ESC-SALIR", 4, 10);

    gbt_volcar_backbuffer();
}

void procesarMenuPrincipal(EstadoJuego* estadoJuego, uint8_t* corriendo, char nombreJugador[], uint8_t* cantLetrasNombre, uint8_t* dificultad, uint16_t* tiempoCaidaMs, VersionJuego* versionJuego)
{
    gbt_procesar_entrada();
    eGBT_Tecla tecla = gbt_obtener_tecla_presionada();

    switch(tecla)
    {
        case GBTK_n: procesarPantallaNombre(nombreJugador, cantLetrasNombre); break;
        case GBTK_d: procesarPantallaDificultad(dificultad, tiempoCaidaMs); break;
        case GBTK_v: procesarPantallaVersion(versionJuego); break;
        case GBTK_a: procesarPantallaAyuda(); break;
        case GBTK_ENTER: *estadoJuego = ESTADO_JUGANDO; break;
        case GBTK_ESCAPE: *corriendo = 0; break;
        default: break;
    }

    mostrarMenuPrincipal();
    gbt_esperar(16);
}

void mostrarPantallaNombre(const char* nombreJugador)
{
    gbt_borrar_backbuffer(N);

    dibujarTexto("NOMBRE", 2, 3);
    dibujarTexto(nombreJugador, 2, 5);
    dibujarTexto("ENTER", 2, 8);
    dibujarTexto("ESC", 2, 9);

    gbt_volcar_backbuffer();
}

void procesarPantallaNombre(char nombreJugador[], uint8_t* cantLetrasNombre)
{
    uint8_t editando = 1;

    while(editando)
    {
        gbt_procesar_entrada();
        eGBT_Tecla tecla = gbt_obtener_tecla_presionada();

        if(tecla >= GBTK_a && tecla <= GBTK_z && *cantLetrasNombre < 19)
        {
            nombreJugador[*cantLetrasNombre] = tecla - 32;
            (*cantLetrasNombre)++;
            nombreJugador[*cantLetrasNombre] = '\0';
        }

        if(tecla == GBTK_RETROCESO && *cantLetrasNombre > 0)
        {
            (*cantLetrasNombre)--;
            nombreJugador[*cantLetrasNombre] = '\0';
        }

        if(tecla == GBTK_ENTER || tecla == GBTK_ESCAPE)
            editando = 0;

        mostrarPantallaNombre(nombreJugador);
        gbt_esperar(16);
    }
}

void mostrarPantallaDificultad(uint8_t dificultad)
{
    gbt_borrar_backbuffer(N);

    dibujarTexto("DIFIC", 2, 2);

    dibujarTexto("1 FACIL", 2, 4);
    dibujarTexto("2 NORMAL", 2, 6);
    dibujarTexto("3 DIFIC", 2, 8);

    if(dificultad == 1)
        dibujarTexto("ACTUAL FACIL", 1, 11);

    else if(dificultad == 2)
        dibujarTexto("ACTUAL NORMAL", 1, 11);

    else
        dibujarTexto("ACTUAL DIFIC", 1, 11);

    dibujarTexto("ESC", 2, 14);

    gbt_volcar_backbuffer();
}

void procesarPantallaDificultad(uint8_t* dificultad, uint16_t* tiempoCaidaMs)
{
    uint8_t editando = 1;

    while(editando)
    {
        gbt_procesar_entrada();
        eGBT_Tecla tecla = gbt_obtener_tecla_presionada();

        switch(tecla)
        {
            case GBTK_1: *dificultad = 1; *tiempoCaidaMs = 1500; break;
            case GBTK_2: *dificultad = 2; *tiempoCaidaMs = 1000; break;
            case GBTK_3: *dificultad = 3; *tiempoCaidaMs = 700; break;
            case GBTK_ESCAPE: editando = 0; break;
            default: break;
        }

        mostrarPantallaDificultad(*dificultad);
        gbt_esperar(16);
    }
}

void mostrarPantallaAyuda(void)
{
    gbt_borrar_backbuffer(N);

    dibujarTexto("AYUDA", 3, 1);

    dibujarTexto("FLECHAS", 1, 4);
    dibujarTexto("MOVER", 1, 5);

    dibujarTexto("ARRIBA", 1, 7);
    dibujarTexto("ROTAR", 1, 8);

    dibujarTexto("P PAUSA", 1, 10);

    dibujarTexto("ESC MENU", 1, 12);

    dibujarTexto("ENTER VOLVER", 1, 15);

    gbt_volcar_backbuffer();
}

void procesarPantallaAyuda(void)
{
    uint8_t viendo = 1;

    while(viendo)
    {
        gbt_procesar_entrada();

        eGBT_Tecla tecla = gbt_obtener_tecla_presionada();

        if(tecla == GBTK_ENTER || tecla == GBTK_ESCAPE)
            viendo = 0;

        mostrarPantallaAyuda();

        gbt_esperar(16);
    }
}

void mostrarPantallaVersion(VersionJuego versionJuego)
{
    gbt_borrar_backbuffer(N);

    dibujarTexto("VERSION", 2, 2);
    dibujarTexto("1 CLASICA", 1, 5);
    dibujarTexto("2 DX", 1, 7);

    if(versionJuego == VERSION_CLASICA)
        dibujarTexto("ACTUAL CLASICA", 1, 11);
    else
        dibujarTexto("ACTUAL DX", 1, 11);

    dibujarTexto("ESC", 2, 15);
    gbt_volcar_backbuffer();
}

void procesarPantallaVersion(VersionJuego* versionJuego)
{
    uint8_t editando = 1;
    while(editando)
    {
        gbt_procesar_entrada();
        eGBT_Tecla tecla = gbt_obtener_tecla_presionada();

        switch(tecla)
        {
            case GBTK_1: *versionJuego = VERSION_CLASICA; break;
            case GBTK_2: *versionJuego = VERSION_DX; break;
            case GBTK_ESCAPE: editando = 0; break;
            default: break;
        }

        mostrarPantallaVersion(*versionJuego);

        gbt_esperar(16);
    }
}

void dibujarJuego(uint8_t** tablero, uint8_t columnasTablero, const tPieza* actual, const tPieza* siguiente,
                  uint32_t puntaje, uint16_t tiempoCaidaMs, uint32_t nivel, const char* nombreJugador)
{
    gbt_borrar_backbuffer(N);

    dibujarMarcoTablero(columnasTablero, TABLERO_X, TABLERO_Y);
    dibujarTablero(tablero, columnasTablero, TABLERO_X, TABLERO_Y);

    dibujarTetrominio(actual->forma, TABLERO_X + actual->x * TAM_BLOQUE, TABLERO_Y + actual->y * TAM_BLOQUE);

    dibujarTexto("JUG:", UI_X, JUGADOR_Y - 1);
    dibujarTexto(nombreJugador, UI_X, JUGADOR_Y);

    dibujarTexto("SIG:", UI_X, SIG_Y);
    dibujarTetrominio(siguiente->forma, SIG_PIEZA_X, SIG_PIEZA_Y);

    char textoPuntaje[20];
    sprintf(textoPuntaje, "PTS:%d", puntaje);
    dibujarTexto(textoPuntaje, UI_X, PUNTAJE_Y);

    char textoTiempo[20];
    sprintf(textoTiempo, "T:%d", (int)tiempoCaidaMs);
    dibujarTexto(textoTiempo, UI_X, TIEMPO_Y);

    char textoNivel[20];
    sprintf(textoNivel, "NIVEL:%d", nivel);
    dibujarTexto(textoNivel, UI_X, NIVEL_Y);

    gbt_volcar_backbuffer();
}

uint8_t procesarPantallaGameOver(uint32_t puntaje)
{
    dibujarPantallaGameOver(puntaje);

    uint8_t esperandoRespuesta = 1;

    while(esperandoRespuesta)
    {
        gbt_procesar_entrada();

        eGBT_Tecla tecla =
            gbt_obtener_tecla_presionada();

        if(tecla == GBTK_ENTER)
            return 1;

        if(tecla == GBTK_ESCAPE)
            return 0;

        gbt_esperar(16);
    }

    return 0;
}

void dibujarPantallaGameOver(uint32_t puntaje)
{
    gbt_borrar_backbuffer(N);

    dibujarTexto("GAME", 4, 4);
    dibujarTexto("OVER", 4, 5);

    char textoPuntajeFinal[20];
    sprintf(textoPuntajeFinal, "PTS:%d", puntaje);
    dibujarTexto(textoPuntajeFinal, 3, 7);

    gbt_volcar_backbuffer();
}

void mostrarPantallaPausa(void)
{
    gbt_borrar_backbuffer(N);
    dibujarTexto("PAUSA", 4, 5);
    gbt_volcar_backbuffer();
}
