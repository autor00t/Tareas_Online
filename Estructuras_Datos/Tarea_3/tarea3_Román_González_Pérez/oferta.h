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

typedef struct {
    int M;
    ranuraOferta *HT;
} dictOferta;

void initOferta(dictOferta *D, int m);
/*****
* void initOferta.
******
* Inicializa un diccionario.
******
* Input:
* dictOferta* D: Puntero a un struct tipo dictOferta.
* int m: entero que representa el largo del diccionario.
* .......
******
* Returns:
* void: esta función no retorna nada en sí, solo crea un diccionario vacío.
*****/
int hashInsertOferta(dictOferta *D, tipoClave K, int cantidad_descuento, int monto_descuento);
/*****
* int hashInsertOferta.
******
* Inserta un producto en la tabla hash.
******
* Input:
* dictOferta* D : Puntero a un struct tipo dictOferta.
* tipoClave k: Entero de la clave del producto.
* cantidad_descuento: Cantidad de productos para que se aplique el descuento.
* monto_descuento: Monto a descontar de los productos.
* .......
******
* Returns:
* int: retorna 1 si se logró insertar el elemento en la tabla, en cambio, sino se logró insertar se retorna 0.
*****/
int hashPositionOferta(dictOferta *D, tipoClave k);
/*****
* int hashPositionOferta.
******
* Retorna la posición en la que debería estar el elemento, retornando -1 si es que no lo encuentra.
******
* Input:
* dictOferta *D: puntero a struct del tipo dictOferta.
* tipoClave k: Entero de la clave del producto.
* .......
******
* Returns:
* int: entero que corresponde a la posición en la que está el elemento, si no encuentra a este en el diccionario retorna -1.
*****/
int hashSearchOfertaCantidad(dictOferta *D, int pos);
/*****
* int hashSearchOfertaCantidad
******
* dado un diccionario y una posición en él, retorna la cantidad necesaria de productos que se necesitan comprar para aplicar el descuento.
******
* Input:
* dictOferta *D: puntero a struct del tipo dictOferta
* int pos: posición en el arreglo correspondiente al diccionario
* .......
******
* Returns:
* int: retorna la cantidad de productos necesarios para que se aplique el descuento correspondiente.
*****/
int hashSearchOfertaMonto(dictOferta *D, int pos);
/*****
* int hashSearchOfertaMonto
******
* dado un diccionario y una posición en él, retorna el monto a descontar sobre el valor del producto.
******
* Input:
* dictOferta *D: Puntero a un struct del tipo dictOferta.
* int pos: posición del arreglo en el que se encuentra el producto.
* .......
******
* Returns:
* int: retorna el monto a descontar sobre el valor del producto.
*****/
void clearOferta(dictOferta *D);
/*****
* void clearOferta
******
* Libera la memoria del diccionario Producto.
******
* Input:
* dictOferta *D: Puntero a un struct tipo dictOferta.
* .......
******
* Returns:
* void, esta función no retorna nada, solo borra el diccionario y libera la memoria ocupada por él.
*****/

#endif