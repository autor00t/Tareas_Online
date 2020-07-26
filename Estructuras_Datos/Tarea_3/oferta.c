#include "oferta.h"
#include "producto.h"
#include <stdlib.h>
#include <string.h>

void initOferta(dictOferta *D, int m)
{
    int original = m;

    while (1.0 * original / m > 0.75)
    {
        m++; //miren carso enrtoencre esta sotolcuoj, jpp: pero saocnera wn eas eaw enerible turcha wn -oscarito: chauspem la coretnea jp
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

    for (i = 1; D->HT[pos].clave != -1 && D->HT[pos].clave != k; ++i)
    {
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

tipoInfoOferta hashSearchOferta(dictOferta *D, int pos)
{
    return D->HT[pos].info;
}

void clear(dictOferta *D)
{
    free((void *)D->HT);
}
