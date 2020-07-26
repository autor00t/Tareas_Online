#ifndef PRODUCTO_H_
#define PRODUCTO_H_

typedef int tipoClave;

typedef struct {
    char nombre_producto[31];
    int precio;
} tipoInfoProducto;

typedef struct {
    tipoClave clave;
    tipoInfoProducto info;
    int vacio;
} ranuraProducto;

typedef struct {
    int M;
    ranuraProducto* HT;
} dictProducto;

void initProducto(dictProducto* D, int m);
int hashInsertProducto(dictProducto *D, tipoClave K, char* nombre_producto, int precio);
int hashPositionProducto(dictProducto *D, tipoClave k);
tipoInfoProducto hashSearchProducto(dictProducto *D, tipoClave k);
int h(tipoClave k, int m);
long h2(tipoClave k);
long p(tipoClave k, int i);
void clearProducto(dictProducto* D);

#endif