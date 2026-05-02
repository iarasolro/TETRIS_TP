#include "fuente.h"
#include "..\GBT_v2026.1C.01\include\GBT\gbt.h"

void mostrarPantallaPrincipal(void)
{
    gbt_borrar_backbuffer(0);

    dibujarTexto("TETRIS", 3, 2);
    dibujarTexto("ENTER", 3, 6);
    dibujarTexto("ESC", 4, 8);

    gbt_volcar_backbuffer();
}
