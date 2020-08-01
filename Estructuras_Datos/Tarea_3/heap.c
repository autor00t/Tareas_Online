#include "producto.h"
#include "oferta.h"
#include "heap.h"
#include <stdlib.h>


void initColaP(tColaP *P, int tamano) {
    P->array_size = tamano + 1;
    P->array = (tipoElem**) malloc(sizeof(tipoElem*) * P->array_size);
    P->len = 0;

    for (int i = 0; i < P->array_size; i++) {
        P->array[i] = (tipoElem*) malloc(sizeof(tipoElem));
    }

}

int findMaxCodigo(tColaP *P) {
    return P->array[1]->codigo;
}

int findMaxCantidad(tColaP *P) {
    return P->array[1]->cantidad;
}

int findMaxMonto(tColaP *P) {
    return P->array[1]->cantidad;
}

int sizeColaP(tColaP *P) {
    return P->len;
}

void hundir(tColaP *P, int i){
    int max;
    tipoElem aux;
    while (i * 2 + 1 <= P->len && (P->array[i]->monto < P->array[i * 2]->monto || P->array[i]->monto < P->array[i * 2 + 1]->monto))
    {
        if (P->array[i]->monto < P->array[i * 2]->monto)
        {
            if (P->array[i]->monto < P->array[i * 2 + 1]->monto)
            {
                if (P->array[i * 2 + 1]->monto > P->array[i * 2]->monto)
                {
                    max = i * 2 + 1;
                }
                else
                {
                    max = i * 2;
                }
            }
            else
            {
                max = i * 2;
            }
        }
        else
        {
            max = i * 2 + 1;
        }
        aux.codigo = P->array[i]->codigo;
        aux.cantidad = P->array[i]->cantidad;
        aux.monto = P->array[i]->monto;

        P->array[i]->codigo = P->array[max]->codigo;
        P->array[i]->cantidad = P->array[max]->cantidad;
        P->array[i]->monto = P->array[max]->monto;

        i = max;

        P->array[i]->codigo = aux.codigo;
        P->array[i]->cantidad = aux.cantidad;
        P->array[i]->monto = aux.monto;
    }

    if (i * 2 == P->len && P->array[i]->monto < P->array[i * 2]->monto) {
        aux.codigo = P->array[i]->codigo;
        aux.cantidad = P->array[i]->cantidad;
        aux.monto = P->array[i]->monto;

        P->array[i]->codigo = P->array[i * 2]->codigo;
        P->array[i]->cantidad = P->array[i * 2]->cantidad;
        P->array[i]->monto = P->array[i * 2]->monto;

        i *= 2;

        P->array[i]->codigo = aux.codigo;
        P->array[i]->cantidad = aux.cantidad;
        P->array[i]->monto = aux.monto;
    }
}

void flotar(tColaP *P, int i) {
    tipoElem aux;

    while (i > 1 && P->array[i]->monto > P->array[i / 2]->monto) {
        aux.codigo = P->array[i]->codigo;
        aux.cantidad = P->array[i]->cantidad;
        aux.monto = P->array[i]->monto;

        P->array[i]->codigo = P->array[i / 2]->codigo;
        P->array[i]->cantidad = P->array[i / 2]->cantidad;
        P->array[i]->monto = P->array[i / 2]->monto;

        i /= 2;

        P->array[i]->codigo = aux.codigo;
        P->array[i]->cantidad = aux.cantidad;
        P->array[i]->monto = aux.monto;
    }
}

void removeMax(tColaP *P) {
    if (P->len > 0) {
        int i = 1;
        P->array[i]->codigo = P->array[P->len]->codigo;
        P->array[i]->cantidad = P->array[P->len]->cantidad;
        P->array[i]->monto = P->array[P->len]->monto;

        P->len--;
        hundir(P, i);
    }
}

void insertColaP(tColaP *P, int codigo, dictProducto* productos, dictOferta* ofertas) {
    int i, posProducto, posOferta, cantidad_descuentos = 0;

    for (i = 1; i <= P->len && P->array[i]->codigo != codigo; i++)
        ;
    posProducto = hashPositionProducto(productos, codigo);
    if (i <= P->len && P->array[i]->codigo == codigo) { 
        P->array[i]->cantidad++;

        posOferta = hashPositionOferta(ofertas, codigo);

        if (posOferta != -1) {
            cantidad_descuentos += P->array[i]->cantidad / hashSearchOfertaCantidad(ofertas, posOferta);
            P->array[i]->monto = P->array[i]->cantidad * hashSearchProductoPrecio(productos, posProducto) - (hashSearchOfertaMonto(ofertas, posOferta) * cantidad_descuentos);
        }
        else {
            P->array[i]->monto = P->array[i]->cantidad * hashSearchProductoPrecio(productos, posProducto);
        }
    }
    else {
        if (posProducto != -1) {
            tipoElem item;
            item.codigo = codigo;
            item.cantidad = 1;
            item.monto = hashSearchProductoPrecio(productos, posProducto);

            P->array[++P->len]->codigo = item.codigo;
            P->array[P->len]->cantidad = item.cantidad;
            P->array[P->len]->monto = item.monto;

            i = P->len;
        }
    }

    hundir(P, i);
    flotar(P, i);

}

void deleteColaP(tColaP *P) {
    for (int i = 0; i < P->array_size; i++) {
        free((void*) P->array[i]);
    }

    free((void*) P->array);
}
