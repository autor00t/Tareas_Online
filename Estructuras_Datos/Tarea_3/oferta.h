#ifndef OFERTA_H_
#define OFERTA_H_

typedef int tipoClave;

typedef struct {
    int cantidad_descuento;
    int monto_descuento;
} tipoInfoOferta;

typedef struct {
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
/*****
* TipoFunción NombreFunción
******
* Resumen Función
******
* Input:
* tipoParámetro NombreParámetro : Descripción Parámetro
* .......
******
* Returns:
* TipoRetorno, Descripción retorno
*****/
int hashInsertOferta(dictOferta *D, tipoClave K, int cantidad_descuento, int monto_descuento);
/*****
* TipoFunción NombreFunción
******
* Resumen Función
******
* Input:
* tipoParámetro NombreParámetro : Descripción Parámetro
* .......
******
* Returns:
* TipoRetorno, Descripción retorno
*****/
int hashPositionOferta(dictOferta *D, tipoClave k);
/*****
* TipoFunción NombreFunción
******
* Resumen Función
******
* Input:
* tipoParámetro NombreParámetro : Descripción Parámetro
* .......
******
* Returns:
* TipoRetorno, Descripción retorno
*****/
int hashSearchOfertaCantidad(dictOferta *D, int pos);
/*****
* TipoFunción NombreFunción
******
* Resumen Función
******
* Input:
* tipoParámetro NombreParámetro : Descripción Parámetro
* .......
******
* Returns:
* TipoRetorno, Descripción retorno
*****/
int hashSearchOfertaMonto(dictOferta *D, int pos);
/*****
* TipoFunción NombreFunción
******
* Resumen Función
******
* Input:
* tipoParámetro NombreParámetro : Descripción Parámetro
* .......
******
* Returns:
* TipoRetorno, Descripción retorno
*****/
void clearOferta(dictOferta *D);
/*****
* TipoFunción NombreFunción
******
* Resumen Función
******
* Input:
* tipoParámetro NombreParámetro : Descripción Parámetro
* .......
******
* Returns:
* TipoRetorno, Descripción retorno
*****/

#endif