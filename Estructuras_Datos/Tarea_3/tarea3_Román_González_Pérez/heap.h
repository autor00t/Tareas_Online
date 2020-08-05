#ifndef HEAP_H_
#define HEAP_H_

typedef struct {
    int codigo;
    int cantidad;
    int monto;
} tipoElem;

typedef struct {
    tipoElem** array;
    int array_size;
    int len;
} tColaP;

void initColaP(tColaP *P, int tamano);
/*****
* void initColaP.
******
* Inicializa una cola de prioridad.
******
* Input:
* tColaP *P: struct del tipo tColaP.
* int tamano: largo del arreglo.
* .......
******
* Returns:
* void: esta función no retorna nada en sí, en su lugar incializa una cola de prioridad.
*****/
int findMaxCodigo(tColaP *P);
/*****
* int findMaxCodigo.
******
* Busca el valor máximo de la cola de prioridad, y retorna su código.
******
* Input:
* tColaP *P: struct del tipo tColaP .
* .......
******
* Returns:
* int: retorna el código del valor máximo. 
*****/
int findMaxCantidad(tColaP *P);
/*****
* int findMaxCantidad.
******
* dada la cola de prioridad, retorna la cantidad de veces que se compró el producto con valor máximo.
******
* Input:
* tColaP *P: struct del tipo tColaP.
* .......
******
* Returns:
* int: retorna cantidad de veces que se compró el producto.
*****/
int findMaxMonto(tColaP *P);
/*****
* int findMaxMonto.
******
* dada una cola de prioridad, retorna el monto total recaudado del valor máximo.
******
* Input:
* tColaP *P: struct del tipo tColaP.
* .......
******
* Returns:
* int: monto total recaudado por el producto.
*****/
int sizeColaP(tColaP *P);
/*****
* int sizeColaP.
******
* Función que retorna el tamaño de la cola de prioridad.
******
* Input:
* tColaP *P: struct del tipo tColaP.
* .......
******
* Returns:
* int, retorna la longitud de la cola de prioridad.
*****/
void flotar(tColaP *P, int i);
/*****
* void flotar
******
* Esta funcion mantiene las condiciones del heap, comprobando si el elemento seleccionado corresponde en el lugar en el que se flota.
******
* Input:
* tColaP *P: struct del tipo tColaP.
* .......
******
* Returns:
* void, esta funcion no retorna nada.
*****/
void hundir(tColaP *P, int i); 
/*****
* void hundir.
******
* Esta funcion mantiene las condiciones del heap, bajando los elementos que no cumplan estas.
******
* Input:
* tColaP *P: struct del tipo tColaP.
* .......
******
* Returns:
* void, esta funcion no retorna nada.
*****/
void removeMax(tColaP *P);
/*****
* void removeMax
******
* Remueve el valor de la cima del heap.
******
* Input:
* tColaP *P: struct del tipo tColaP.
* .......
******
* Returns:
* void, esta funcion no retorna nada, en su lugar, remueve el elemento de mayor prioridad del heap.
*****/
void insertColaP(tColaP *P, int codigo, dictProducto* productos, dictOferta* oferta);
/*****
* void insertColaP.
******
* Inserta elementos en el heap.
******
* Input:
* tColaP *P: struct del tipo tColaP.
* int codigo: Entero referente al código del producto.
* dictProducto* productos: Puntero a un struct tipo dictProducto.
* dictOferta* oferta: Puntero a un struct tipo dictOferta.
* .......
******
* Returns:
* void, esta función no retorna nada, solo inserta elementos en la cola de prioridad.
*****/
void deleteColaP(tColaP *P);
/*****
* void deleteColaP.
******
* Libera la memoria del heap.
******
* Input:
* tColaP *P: struct del tipo tColaP.
* .......
******
* Returns:
* void, esta función no retorna nada, solo elimina la cola de prioridad y libera la memoria utilizada.
*****/

#endif
