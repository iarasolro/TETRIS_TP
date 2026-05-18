#include "matriz.h"

void* crearMatriz(int filas, int columnas, size_t tamElem)
{///como no se crea en el stack, lo puedo devolver, no se destruye en esta funcion
    void** mat = malloc(filas * sizeof(void*));

    if(!mat)
        return NULL;

    void** ult = mat + filas - 1;

    for(void** i = mat; i <= ult; i++)
    {
        *i = malloc(columnas * tamElem);

        if(!*i)
        {
            for(void** j = mat; j < i; j++)
                free(*j);

            free(mat);

            return NULL;
        }
    }

    return mat;
}

void destruirMatriz(void** mat, int filas)
{
    void** ult = mat + filas - 1;

    for(void** i = mat; i <= ult; i++)
        free(*i);

    free(mat);
}

void recorrerMatriz(int filas, int columnas, void* mat, size_t tamElem, int memMat, Accion accion, void* datosAccion)
{
    if(memMat == MEM_EST)
    {
        for(int i = 0; i < filas; i++)
        {
            for(int j = 0; j < columnas; j++)
            {
                accion(mat + (i * columnas + j) * tamElem, datosAccion, filas, columnas, i, j);
            }
        }
    }
    else
    {
        void** matDin = (void**)mat;
        for(int i = 0; i < filas; i++)
        {
            for(int j = 0; j < columnas; j++)
            {
                accion(matDin[i] + j * tamElem, datosAccion, filas, columnas, i, j);
            }
        }
    }
}
