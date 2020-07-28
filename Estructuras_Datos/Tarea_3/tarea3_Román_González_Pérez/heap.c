#include "producto.h"
#include "oferta.h"
#include "heap.h"
#include <stdlib.h>


void initColaP(tColaP *P, int tamano) {
    P->array = (tipoElem*) malloc(sizeof(tipoElem) * tamano);
    P->len = 0;
}

int findMaxCodigo(tColaP *P) {
    return P->array[1].codigo;
}

int findMaxCantidad(tColaP *P) {
    return P->array[1].cantidad;
}

int findMaxMonto(tColaP *P) {
    return P->array[1].monto;
}

int sizeColaP(tColaP *P) {
    return P->len;
}

void flotar(tColaP *P, int i){
    int max;
    tipoElem aux;
    while (i * 2 + 1 <= P->len && (P->array[i].monto < P->array[i * 2].monto || P->array[i].monto < P->array[i * 2 + 1].monto))
    {
        if (P->array[i].monto < P->array[i * 2].monto)
        {
            if (P->array[i].monto < P->array[i * 2 + 1].monto)
            {
                if (P->array[i * 2 + 1].monto > P->array[i * 2].monto)
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
        aux = P->array[i];
        P->array[i] = P->array[max];
        i = max;
        P->array[i] = aux;
    }

    if (i * 2 == P->len && P->array[i].monto < P->array[i * 2].monto) {
        aux = P->array[i];
        P->array[i] = P->array[i * 2];
        i *= 2;
        P->array[i] = aux;
    }
}

void hundir(tColaP *P, int i) {
    tipoElem aux;

    while (i > 1 && P->array[i].monto > P->array[i / 2].monto) {
        aux = P->array[i];
        P->array[i] = P->array[i / 2];
        i /= 2;
        P->array[i] = aux;
    }
}

void removeMax(tColaP *P) {
    if (P->len > 0) {
        int i = 1;
        P->array[i] = P->array[P->len--];
        
        flotar(P, i);
    }
}

void insertColaP(tColaP *P, int codigo, dictProducto* productos, dictOferta* ofertas) {
    int i, posProducto, posOferta, cantidad_descuentos = 0;

    for (i = 1; i <= P->len && P->array[i].codigo != codigo; i++)
        ;
    posProducto = hashPositionProducto(productos, codigo);
    if (P->array[i].codigo == codigo) { 
        P->array[i].cantidad++;

        posOferta = hashPositionOferta(ofertas, codigo);

        if (posOferta != -1) {
            cantidad_descuentos += P->array[i].cantidad / hashSearchOfertaCantidad(ofertas, posOferta);
            P->array[i].monto = P->array[i].cantidad * hashSearchProductoPrecio(productos, posProducto) - (hashSearchOfertaMonto(ofertas, posOferta) * cantidad_descuentos);
        }
        else {
            P->array[i].monto = P->array[i].cantidad * hashSearchProductoPrecio(productos, posProducto);
        }
    }
    else {
        if (posProducto != -1) {
            tipoElem item;
            item.codigo = codigo;
            item.cantidad = 1;
            item.monto = hashSearchProductoPrecio(productos, posProducto);

            P->array[++P->len] = item;
            i = P->len;
        }
    }
    
    flotar(P, i);
    hundir(P, i);
}

void deleteColaP(tColaP *P) {
    free((void*) P->array);
}
