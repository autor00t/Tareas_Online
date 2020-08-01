#include "oferta.h"
#include "producto.h"
#include <stdlib.h>
#include <stdio.h>

void initOferta(dictOferta *D, int m)
{
    int original = m;

    while (1.0 * original / m > 0.75)
    {
        m++; 
    }

    D->M = m;

    D->HT = (ranuraOferta *) malloc(sizeof(ranuraOferta) * D->M);
    for (int i = 0; i < m; i++)
    {
        D->HT[i].clave = -1; //cuando esta vacio la clave es -1
    }
}

int hashInsertOferta(dictOferta *D, tipoClave k, int cantidad_descuento, int monto_descuento)
{
    int inicio, i;
    int pos = inicio = h(k, D->M);
    tipoInfoOferta temp;
    temp.cantidad_descuento = cantidad_descuento;
    temp.monto_descuento = monto_descuento;

    for (i = 1; D->HT[pos].clave != -1 && D->HT[pos].clave != k; ++i) {
        pos = (inicio + p(k, i)) % D->M;
    }
    if (D->HT[pos].clave == k)
        return 0;
    else
    {
        D->HT[pos].clave = k;
        D->HT[pos].info = temp;
        return 1;
    }
}

int hashPositionOferta(dictOferta *D, tipoClave k)
{
    int inicio, i;
    int pos = inicio = h(k, D->M);

    for (i = 1; D->HT[pos].clave != -1 && D->HT[pos].clave != k; i++)
        pos = (inicio + p(k, i)) % D->M;

    if (D->HT[pos].clave == k)
        return pos;
    else
        return -1;
}

int hashSearchOfertaCantidad(dictOferta *D, int pos) {
    return D->HT[pos].info.cantidad_descuento;
}

int hashSearchOfertaMonto(dictOferta *D, int pos) {
    return D->HT[pos].info.monto_descuento;
}

void clearOferta(dictOferta *D)
{
    free((void *)D->HT);
}
