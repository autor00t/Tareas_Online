#ifndef OFERTA_H_
#define OFERTA_H_

typedef int tipoClave;

typedef struct
{
    int cantidad_descuento;
    int monto_descuento;
} tipoInfoOferta;

typedef struct
{
    tipoClave clave;
    tipoInfoOferta info;
    int vacio;
} ranuraOferta;

typedef struct
{
    int M;
    ranuraOferta *HT;
} dictOferta;

void initOferta(dictOferta *D, int m);
int hashInsertOferta(dictOferta *D, tipoClave K, int cantidad_descuento, int monto_descuento);
int hashPositionOferta(dictOferta *D, tipoClave k);
tipoInfoOferta hashSearchOferta(dictOferta *D, tipoClave k);
void clearOferta(dictOferta *D);

#endif