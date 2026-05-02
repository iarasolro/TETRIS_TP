#include "fuente.h"

const uint8_t letra_A[8][8] = {
{N,N,A,A,A,A,N,N},
{N,A,N,N,N,N,A,N},
{A,A,N,N,N,N,A,A},
{A,A,A,A,A,A,A,A},
{A,A,A,A,A,A,A,A},
{A,A,N,N,N,N,A,A},
{A,A,N,N,N,N,A,A},
{A,A,N,N,N,N,A,A}
};

const uint8_t letra_B[8][8] = {
{A,A,A,A,A,A,N,N},
{A,A,N,N,N,N,A,A},
{A,A,N,N,N,N,A,A},
{A,A,A,A,A,A,N,N},
{A,A,N,N,N,N,A,N},
{A,A,N,N,N,N,A,A},
{A,A,A,A,A,A,A,A},
{A,A,A,A,A,A,N,N}
};

const uint8_t letra_C[8][8] = {
{N,A,A,A,A,A,A,N},
{A,A,N,N,N,N,A,A},
{A,A,N,N,N,N,N,A},
{A,A,N,N,N,N,N,N},
{A,A,N,N,N,N,N,N},
{A,A,N,N,N,N,N,A},
{N,A,A,A,A,A,A,A},
{N,A,A,A,A,A,A,N}
};

const uint8_t letra_D[8][8] = {
{A,A,A,A,A,A,N,N},
{A,A,N,N,N,A,A,N},
{A,A,N,N,N,A,A,N},
{A,A,N,N,N,N,A,A},
{A,A,N,N,N,N,A,A},
{A,A,N,N,N,A,A,N},
{A,A,A,A,A,A,A,N},
{A,A,A,A,A,A,N,N}
};

const uint8_t letra_E[8][8] = {
{A,A,A,A,A,A,A,A},
{A,A,N,N,N,N,N,N},
{A,A,N,N,N,N,N,N},
{A,A,A,A,A,N,N,N},
{A,A,N,N,N,N,N,N},
{A,A,N,N,N,N,N,N},
{A,A,A,A,A,A,A,A},
{A,A,A,A,A,A,A,A}
};

const uint8_t letra_F[8][8] = {
{A,A,A,A,A,A,A,A},
{A,A,N,N,N,N,N,N},
{A,A,N,N,N,N,N,N},
{A,A,A,A,A,N,N,N},
{A,A,N,N,N,N,N,N},
{A,A,N,N,N,N,N,N},
{A,A,N,N,N,N,N,N},
{A,A,N,N,N,N,N,N}
};

const uint8_t letra_G[8][8] = {
{N,A,A,A,A,A,A,N},
{A,A,N,N,N,N,N,N},
{A,A,N,N,N,N,N,N},
{A,A,N,N,A,A,A,N},
{A,A,N,N,N,N,A,A},
{A,A,N,N,N,N,A,A},
{N,A,A,A,A,A,A,N},
{N,A,A,A,A,A,A,N}
};

const uint8_t letra_H[8][8] = {
{A,A,N,N,N,N,A,A},
{A,A,N,N,N,N,A,A},
{A,A,N,N,N,N,A,A},
{A,A,A,A,A,A,A,A},
{A,A,N,N,N,N,A,A},
{A,A,N,N,N,N,A,A},
{A,A,N,N,N,N,A,A},
{A,A,N,N,N,N,A,A}
};

const uint8_t letra_I[8][8] = {
{N,N,N,A,A,N,N,N},
{N,N,N,A,A,N,N,N},
{N,N,N,A,A,N,N,N},
{N,N,N,A,A,N,N,N},
{N,N,N,A,A,N,N,N},
{N,N,N,A,A,N,N,N},
{N,N,N,A,A,N,N,N},
{N,N,N,A,A,N,N,N}
};

const uint8_t letra_J[8][8] = {
{N,N,N,A,A,A,A,A},
{N,N,N,N,N,A,A,N},
{N,N,N,N,N,A,A,N},
{N,N,N,N,N,A,A,N},
{N,N,N,N,N,A,A,N},
{N,N,A,A,N,A,A,N},
{N,N,A,A,A,A,A,N},
{N,N,N,A,A,A,N,N}
};

const uint8_t letra_K[8][8] = {
{A,A,N,N,N,A,A,N},
{A,A,N,N,A,A,N,N},
{A,A,N,A,A,N,N,N},
{A,A,A,A,N,N,N,N},
{A,A,N,A,A,N,N,N},
{A,A,N,N,A,A,N,N},
{A,A,N,N,N,A,A,N},
{A,A,N,N,N,N,A,A}
};

const uint8_t letra_L[8][8] = {
{A,A,N,N,N,N,N,N},
{A,A,N,N,N,N,N,N},
{A,A,N,N,N,N,N,N},
{A,A,N,N,N,N,N,N},
{A,A,N,N,N,N,N,N},
{A,A,N,N,N,N,N,N},
{A,A,A,A,A,A,A,A},
{A,A,A,A,A,A,A,A}
};

const uint8_t letra_M[8][8] = {
{A,A,N,N,N,N,A,A},
{A,A,A,N,N,A,A,A},
{A,A,N,A,A,N,A,A},
{A,A,N,N,N,N,A,A},
{A,A,N,N,N,N,A,A},
{A,A,N,N,N,N,A,A},
{A,A,N,N,N,N,A,A},
{A,A,N,N,N,N,A,A}
};

const uint8_t letra_N[8][8] = {
{A,A,N,N,N,N,A,A},
{A,A,A,N,N,N,A,A},
{A,A,N,A,N,N,A,A},
{A,A,N,N,A,N,A,A},
{A,A,N,N,N,A,A,A},
{A,A,N,N,N,N,A,A},
{A,A,N,N,N,N,A,A},
{A,A,N,N,N,N,A,A}
};

const uint8_t letra_O[8][8] = {
{N,A,A,A,A,A,A,N},
{A,A,N,N,N,N,A,A},
{A,A,N,N,N,N,A,A},
{A,A,N,N,N,N,A,A},
{A,A,N,N,N,N,A,A},
{A,A,N,N,N,N,A,A},
{N,A,A,A,A,A,A,N},
{N,N,A,A,A,N,N,N}
};

const uint8_t letra_P[8][8] = {
{A,A,A,A,A,A,N,N},
{A,A,N,N,N,N,A,A},
{A,A,N,N,N,N,A,A},
{A,A,A,A,A,A,N,N},
{A,A,N,N,N,N,N,N},
{A,A,N,N,N,N,N,N},
{A,A,N,N,N,N,N,N},
{A,A,N,N,N,N,N,N}
};

const uint8_t letra_Q[8][8] = {
{N,A,A,A,A,A,A,N},
{A,A,N,N,N,N,A,A},
{A,A,N,N,N,N,A,A},
{A,A,N,N,N,N,A,A},
{A,A,N,A,N,N,A,A},
{A,A,N,N,A,N,A,A},
{N,A,A,N,A,A,A,N},
{N,N,A,A,A,N,N,A}
};

const uint8_t letra_R[8][8] = {
{A,A,A,A,A,A,N,N},
{A,A,N,N,N,N,A,A},
{A,A,N,N,N,N,A,A},
{A,A,A,A,A,A,N,N},
{A,A,N,A,A,N,N,N},
{A,A,N,N,A,A,N,N},
{A,A,N,N,N,A,A,N},
{A,A,N,N,N,N,A,A}
};

const uint8_t letra_S[8][8] = {
{N,A,A,A,A,A,A,A},
{A,A,N,N,N,N,N,N},
{A,A,N,N,N,N,N,N},
{N,A,A,A,A,A,A,N},
{N,N,N,N,N,N,A,A},
{N,N,N,N,N,N,A,A},
{A,A,A,A,A,A,A,N},
{N,A,A,A,A,A,N,N}
};

const uint8_t letra_T[8][8] = {
{A,A,A,A,A,A,A,A},
{N,N,N,A,A,N,N,N},
{N,N,N,A,A,N,N,N},
{N,N,N,A,A,N,N,N},
{N,N,N,A,A,N,N,N},
{N,N,N,A,A,N,N,N},
{N,N,N,A,A,N,N,N},
{N,N,N,A,A,N,N,N}
};

const uint8_t letra_U[8][8] = {
{A,A,N,N,N,N,A,A},
{A,A,N,N,N,N,A,A},
{A,A,N,N,N,N,A,A},
{A,A,N,N,N,N,A,A},
{A,A,N,N,N,N,A,A},
{A,A,N,N,N,N,A,A},
{N,A,A,A,A,A,A,N},
{N,N,N,A,A,N,N,N}
};

const uint8_t letra_V[8][8] = {
{A,N,N,N,N,N,N,A},
{A,N,N,N,N,N,N,A},
{N,A,N,N,N,N,A,N},
{N,A,N,N,N,N,A,N},
{N,N,A,N,N,A,N,N},
{N,N,A,N,N,A,N,N},
{N,N,A,A,A,N,N,N},
{N,N,N,A,A,N,N,N}
};

const uint8_t letra_W[8][8] = {
{A,A,N,N,N,N,A,A},
{A,A,N,N,N,N,A,A},
{A,A,N,N,N,N,A,A},
{A,A,N,N,N,N,A,A},
{A,A,N,A,A,N,A,A},
{A,A,N,A,A,N,A,A},
{A,A,A,N,N,A,A,A},
{A,A,N,N,N,N,A,A}
};

const uint8_t letra_X[8][8] = {
{A,A,N,N,N,N,A,A},
{N,A,A,N,N,A,A,N},
{N,N,A,A,A,A,N,N},
{N,N,N,A,A,N,N,N},
{N,N,A,A,A,A,N,N},
{N,A,A,N,N,A,A,N},
{A,A,N,N,N,N,A,N},
{A,A,N,N,N,N,A,A}
};

const uint8_t letra_Y[8][8] = {
{A,A,N,N,N,N,A,A},
{N,A,A,N,N,A,A,N},
{N,N,A,A,A,A,N,N},
{N,N,N,A,A,N,N,N},
{N,N,N,A,A,N,N,N},
{N,N,N,A,A,N,N,N},
{N,N,N,A,A,N,N,N},
{N,N,N,A,A,N,N,N}
};

const uint8_t letra_Z[8][8] = {
{A,A,A,A,A,A,A,A},
{N,N,N,N,N,A,N,N},
{N,N,N,N,A,N,N,N},
{N,N,N,A,N,N,N,N},
{N,N,A,N,N,N,N,N},
{N,A,N,N,N,N,N,N},
{A,A,A,A,A,A,A,A},
{A,A,A,A,A,A,A,A}
};

/*********************NUMEROS************************/
const uint8_t num_0[8][8] = {
{N,A,A,A,A,A,A,N},
{A,A,N,N,N,N,A,A},
{A,A,N,N,A,N,A,A},
{A,A,N,A,N,N,A,A},
{A,A,N,N,N,N,A,A},
{A,A,N,N,N,N,A,A},
{A,A,N,N,N,N,A,A},
{N,A,A,A,A,A,A,N}
};


const uint8_t num_1[8][8] = {
{N,N,A,A,A,N,N,N},
{N,N,A,A,A,N,N,N},
{N,N,N,A,A,N,N,N},
{N,N,N,A,A,N,N,N},
{N,N,N,A,A,N,N,N},
{N,N,N,A,A,N,N,N},
{N,N,N,A,A,N,N,N},
{N,N,A,A,A,A,N,N}
};

const uint8_t num_2[8][8] = {
{N,A,A,A,A,A,A,N},
{A,A,N,N,N,N,A,A},
{N,N,N,N,N,N,A,A},
{N,N,N,N,N,A,A,N},
{N,N,N,N,A,A,N,N},
{N,N,N,A,A,N,N,N},
{N,N,A,A,N,N,N,N},
{A,A,A,A,A,A,A,A}
};

const uint8_t num_3[8][8] = {
{N,A,A,A,A,A,A,N},
{A,A,N,N,N,N,A,A},
{N,N,N,N,N,N,A,A},
{N,N,A,A,A,A,N,N},
{N,N,N,N,N,N,A,A},
{N,N,N,N,N,N,A,A},
{A,A,N,N,N,N,A,A},
{N,A,A,A,A,A,A,N}
};

const uint8_t num_4[8][8] = {
{N,N,N,A,A,N,N,N},
{N,N,A,A,A,N,N,N},
{N,A,A,N,A,N,N,N},
{A,A,N,N,A,N,N,N},
{A,A,A,A,A,A,A,N},
{N,N,N,N,A,N,N,N},
{N,N,N,N,A,N,N,N},
{N,N,N,N,A,N,N,N}
};

const uint8_t num_5[8][8] = {
{A,A,A,A,A,A,A,A},
{A,A,N,N,N,N,N,N},
{A,A,A,A,A,A,N,N},
{N,N,N,N,N,N,A,A},
{N,N,N,N,N,N,A,A},
{N,N,N,N,N,N,A,A},
{A,A,N,N,N,N,A,A},
{N,A,A,A,A,A,A,N}
};

const uint8_t num_6[8][8] = {
{N,A,A,A,A,A,A,N},
{A,A,N,N,N,N,N,N},
{A,A,N,N,N,N,N,N},
{A,A,A,A,A,A,N,N},
{A,A,N,N,N,N,A,A},
{A,A,N,N,N,N,A,A},
{A,A,N,N,N,N,A,A},
{N,A,A,A,A,A,A,N}
};

const uint8_t num_7[8][8] = {
{A,A,A,A,A,A,A,A},
{N,N,N,N,N,N,A,A},
{N,N,N,N,N,A,A,N},
{N,N,N,N,A,A,N,N},
{N,N,N,A,A,N,N,N},
{N,N,A,A,N,N,N,N},
{N,A,A,N,N,N,N,N},
{N,A,A,N,N,N,N,N}
};

const uint8_t num_8[8][8] = {
{N,A,A,A,A,A,A,N},
{A,A,N,N,N,N,A,A},
{A,A,N,N,N,N,A,A},
{N,A,A,A,A,A,A,N},
{A,A,N,N,N,N,A,A},
{A,A,N,N,N,N,A,A},
{A,A,N,N,N,N,A,A},
{N,A,A,A,A,A,A,N}
};

const uint8_t num_9[8][8] = {
{N,A,A,A,A,A,A,N},
{A,A,N,N,N,N,A,A},
{A,A,N,N,N,N,A,A},
{A,A,N,N,N,N,A,A},
{N,A,A,A,A,A,A,A},
{N,N,N,N,N,N,A,A},
{N,N,N,N,N,N,A,A},
{N,A,A,A,A,A,A,N}
};

/************************CARACTERES ESPECIALES*************************/
const uint8_t espacio[8][8] =
{
    {N,N,N,N,N,N,N,N},
    {N,N,N,N,N,N,N,N},
    {N,N,N,N,N,N,N,N},
    {N,N,N,N,N,N,N,N},
    {N,N,N,N,N,N,N,N},
    {N,N,N,N,N,N,N,N},
    {N,N,N,N,N,N,N,N},
    {N,N,N,N,N,N,N,N}
};

const uint8_t punto[8][8] =
{
    {N,N,N,N,N,N,N,N},
    {N,N,N,N,N,N,N,N},
    {N,N,N,N,N,N,N,N},
    {N,N,N,N,N,N,N,N},
    {N,N,N,N,N,N,N,N},
    {N,N,N,N,N,N,N,N},
    {N,N,N,A,A,N,N,N},
    {N,N,N,A,A,N,N,N}
};

const uint8_t coma[8][8] =
{
    {N,N,N,N,N,N,N,N},
    {N,N,N,N,N,N,N,N},
    {N,N,N,N,N,N,N,N},
    {N,N,N,N,N,N,N,N},
    {N,N,N,N,N,N,N,N},
    {N,N,N,A,A,N,N,N},
    {N,N,N,A,A,N,N,N},
    {N,N,N,A,N,N,N,N}
};

const uint8_t punto_y_coma[8][8] =
{
    {N,N,N,N,N,N,N,N},
    {N,N,N,A,A,N,N,N},
    {N,N,N,A,A,N,N,N},
    {N,N,N,N,N,N,N,N},
    {N,N,N,N,N,N,N,N},
    {N,N,N,A,A,N,N,N},
    {N,N,N,A,A,N,N,N},
    {N,N,N,A,N,N,N,N}
};

const uint8_t dos_puntos[8][8] =
{
    {N,N,N,N,N,N,N,N},
    {N,N,N,N,N,N,N,N},
    {N,N,N,A,A,N,N,N},
    {N,N,N,A,A,N,N,N},
    {N,N,N,N,N,N,N,N},
    {N,N,N,A,A,N,N,N},
    {N,N,N,A,A,N,N,N},
    {N,N,N,N,N,N,N,N}
};

const uint8_t guion[8][8] =
{
    {N,N,N,N,N,N,N,N},
    {N,N,N,N,N,N,N,N},
    {N,N,N,N,N,N,N,N},
    {N,A,A,A,A,A,A,N},
    {N,A,A,A,A,A,A,N},
    {N,N,N,N,N,N,N,N},
    {N,N,N,N,N,N,N,N},
    {N,N,N,N,N,N,N,N}
};

const uint8_t guion_bajo[8][8] =
{
    {N,N,N,N,N,N,N,N},
    {N,N,N,N,N,N,N,N},
    {N,N,N,N,N,N,N,N},
    {N,N,N,N,N,N,N,N},
    {N,N,N,N,N,N,N,N},
    {N,N,N,N,N,N,N,N},
    {N,A,A,A,A,A,A,N},
    {N,A,A,A,A,A,A,N}
};

const uint8_t admiracion[8][8] =
{
    {N,N,N,A,A,N,N,N},
    {N,N,N,A,A,N,N,N},
    {N,N,N,A,A,N,N,N},
    {N,N,N,A,A,N,N,N},
    {N,N,N,A,A,N,N,N},
    {N,N,N,N,N,N,N,N},
    {N,N,N,A,A,N,N,N},
    {N,N,N,A,A,N,N,N}
};

const uint8_t (*obtenerCaracter(char caracter))[8]
{
    switch(caracter)
    {
        case 'A': return letra_A;
        case 'B': return letra_B;
        case 'C': return letra_C;
        case 'D': return letra_D;
        case 'E': return letra_E;
        case 'F': return letra_F;
        case 'G': return letra_G;
        case 'H': return letra_H;
        case 'I': return letra_I;
        case 'J': return letra_J;
        case 'K': return letra_K;
        case 'L': return letra_L;
        case 'M': return letra_M;
        case 'N': return letra_N;
        case 'O': return letra_O;
        case 'P': return letra_P;
        case 'Q': return letra_Q;
        case 'R': return letra_R;
        case 'S': return letra_S;
        case 'T': return letra_T;
        case 'U': return letra_U;
        case 'V': return letra_V;
        case 'W': return letra_W;
        case 'X': return letra_X;
        case 'Y': return letra_Y;
        case 'Z': return letra_Z;

        case '0': return num_0;
        case '1': return num_1;
        case '2': return num_2;
        case '3': return num_3;
        case '4': return num_4;
        case '5': return num_5;
        case '6': return num_6;
        case '7': return num_7;
        case '8': return num_8;
        case '9': return num_9;

        case ' ': return espacio;
        case '.': return punto;
        case ',': return coma;
        case ';': return punto_y_coma;
        case ':': return dos_puntos;
        case '-': return guion;
        case '!': return admiracion;

        default: return espacio;
    }
}

void dibujarTexto(const char* texto, uint16_t x, uint16_t y)
{
    while(*texto)
    {
        dibujar(obtenerCaracter(*texto), x, y);
        x++;
        texto++;
    }
}
