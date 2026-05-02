#include <stdio.h>
#include <stdlib.h>

#include "..\GBT_v2026.1C.01\include\GBT\gbt.h"
#include "fuente.h"
#include "interfaz.h"


int main()
{
    uint8_t corriendo = 1;

    if (gbt_iniciar() != 0)
        return 1;

    if (gbt_crear_ventana("Tetris", 128, 128, 5) != 0)
        return 1;

    while (corriendo)
    {
        gbt_procesar_entrada();

        mostrarPantallaPrincipal();

        if (gbt_tecla_presionada(GBTK_ESCAPE))
            corriendo = 0;

        gbt_esperar(16);
    }

    gbt_destruir_ventana();
    gbt_cerrar();

    return 0;
}
