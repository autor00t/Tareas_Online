#include "producto.h"
#include <stdlib.h>
#include <string.h>

void initProducto(dictProducto *D, int m) {
    int original = m;
    
    while (1.0 * original / m > 0.75) { 
        m++; 
    }

    D->M = m;

    D->HT = (ranuraProducto*) malloc(sizeof(ranuraProducto) * D->M);
    for (int i = 0; i < m; i++) {
        D->HT[i].clave = -1; //cuando esta vacio la clave es -1
    }
}

int hashInsertProducto(dictProducto *D, tipoClave k, char *nombre_producto, int precio) {
    int inicio, i;
    int pos = inicio = h(k, D->M);
    tipoInfoProducto temp;
    strcpy(temp.nombre_producto, nombre_producto);
    temp.precio = precio;

    for (i = 1; D->HT[pos].clave != -1 && D->HT[pos].clave != k; ++i) {
        pos = (inicio + p(k, i)) % D->M;
    }
    if (D->HT[pos].clave == k)
        return 0;
    else {
        D->HT[pos].clave = k;
        D->HT[pos].info = temp;
        return 1;
    }
}

int hashPositionProducto(dictProducto *D, tipoClave k) {
    int inicio, i;
    int pos = inicio = h(k, D->M);

    for (i = 1; D->HT[pos].clave != -1 && D->HT[pos].clave != k; i++)
        pos = (inicio + p(k, i)) % D->M;

    if (D->HT[pos].clave == k)
        return pos;
    else
        return -1;
}

char* hashSearchProductoNombre(dictProducto *D, int pos) {
    return D->HT[pos].info.nombre_producto;
}

int hashSearchProductoPrecio(dictProducto *D, int pos) {
    return D->HT[pos].info.precio;
}

int h(tipoClave k, int m) {
    int pos;
    pos = k;
    while(pos >=m){
        pos = pos >> 1;
    }
    
    return abs(pos) % m;
}

long h2(tipoClave k) {
    return 10 * k -7;
}   

long p(tipoClave k, int i) {
    return abs(i * h2(k));
}

void clearProducto(dictProducto *D) {
    free((void*) D->HT);
}