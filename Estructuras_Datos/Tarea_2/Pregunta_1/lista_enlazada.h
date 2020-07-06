#ifndef LISTA_ENLAZADA_H_
#define LISTA_ENLAZADA_H_

typedef int tElemLista;

typedef struct nodo {
    tElemLista info[2]; 
    struct nodo *sig;
} tNodo;

typedef struct {
    tNodo *head;
    tNodo *tail;
    tNodo *curr;
    unsigned int listSize;
    unsigned int pos;
} tLista;

void initList(tLista *L);
/*****
* void initList
******
* Inicializa una lista vacia.
******
* Input: 
* tLista* L : Puntero a un struct tipo tLista.
* .......
******
* Returns:
* void, no retorna nada, en su lugar, genera una lista vacía.
*****/
void clear(tLista *L);
/*****
* void clear
******
* Elimina el contenido de la lista, dejándola vacía.
******
* Input: 
* tLista* L : Puntero a un struct tipo tLista. 
* .......
******
* Returns:
* void, esta funcion no retorna nada, más bien, deja la lista vacía, eliminando su contenido.
*****/
int insert(tLista *L, tElemLista* item);
/*****
* int insert
******
* Inserta el valor en la posición actual.
******
* Input: 
* tLista* L : Puntero a un struct tipo tLista.
* tElemLista* item : Puntero a un elemento de la lista, definido en este caso como entero(int).
* .......
******
* Returns:
* int, este int indica el valor que tendrá el nodo a insertar.
*****/
int erase(tLista *L);
/*****
* int erase
******
* Borra el elemento actual y retorna su posición.
******
* Input: 
* tLista *L : Puntero a un struct tipo tLista.
* .......
******
* Returns: 
* int, retorna la posicion del elemento eliminado.
*****/
void moveToStart(tLista *L);
/*****
* void moveToStart
******
* Cambia lo posición actual al comienzo de la lista.
******
* Input: 
* tLista* L : Puntero a un struct tipo tLista.
* .......
******
* Returns:
* void, esta funcion no retorna nada, esta cambia la posicion del proceso,
* regresando a la primera posicion. 
*****/
void moveToEnd(tLista *L);
/*****
* void moveToEnd
******
* Cambia la posición actual al final de la lista.
******
* Input:
* tLista* L : Puntero a un struct tipo tLista.
* .......
******
* Returns:
* void, esta funcion no retorna nada, esta cambia la posicion del proceso,
* trasladándose a la ultima posicion.
*****/
void prev(tLista *L);
/*****
* void prev 
******
* Cambia la posición actual al nodo anterior
******
* Input:
* tLista* L : Puntero a un struct tipo tLista
* .......
******
* Returns:
* void, esta funcion no retorna nada, esta cambia la posicion del proceso,
* trasladándose a la posición anterior.
*****/ 
void next(tLista *L);
/*****
* void next
******
* Cambia la posición actual al nodo siguiente.
******
* Input:
* tLista* L : Puntero a un struct tipo tLista
* .......
******
* Returns:
* void, esta funcion no retorna nada, esta cambia la posicion del proceso,
* trasladándose a la posición siguiente.
*****/
void moveToPos(tLista *L, unsigned int posicion);
/*****
* void moveToPos
******
* Cambia la posición actual según el input entregado.
******
* Input:
* tLista* L : Puntero a un struct tipo tLista.
* unsigned int posicion: Es un int que indica la posicion a la que se quiere ir.
* .......
******
* Returns:
* void, esta funcion no retorna nada, esta cambia la posicion del proceso
* trasladándose a la posicion especificada por el parametro "posicion".
*****/
void append(tLista *L, tElemLista* item);
/*****
* void append
******
* Agrega un valor en la última posición disponible.
******
* Input: 
* tlista* L : Puntero a un struct tipo tLista.
* tElemLista* item: Puntero a un elemento de la lista, definido en este caso como entero(int).
* .......
******
* Returns:
* void, esta funcion no retorna nada, solo agrega un elemento al final de la lista.
*****/
int length(tLista *L);
/*****
* int lenght
******
* Obtiene la longitud de la lista.
******
* Input:
* tlista *L : Puntero a un struct tipo tLista.
* .......
******
* Returns:
* int, retorna el entero correspondiente al largo de la lista.
*****/
int currPos(tLista *L);
/*****
* int currPos 
******
* Retorna la posición actual de la lista
******
* Input:
* tLista* L : Descripción Parámetro
* .......
******
* Returns:
* int, el entero corresponde a la posición actual
*****/
tElemLista* getValue(tLista *L);
/*****
* tElemLista* getValue 
******
* Obtiene el valor "info" en la posición actual de la lista
******
* Input:
* tLista* L : Puntero a un struct tipo tLista
* .......
******
* Returns:
* tElemLista*, retorna el elemento de la posición actual, este caso, un entero(int)
*****/
void setValue(tLista* L, tElemLista* item);
/*****
* void setValue
******
* Dado una lista L, asigna el valor item en el nodo actual
******
* Input:
* tLista* L : Puntero a un struct tipo tLista
* tElemLista* item : Puntero a un elemento de la lista, definido en este caso como entero(int)
* .......
******
* Returns:
* void, esta funcion no retorna nada, esta asigna un valor al nodo actual
*****/
void deleteList(tLista *L);
/*****
* void deleteList
******
* Borra la lista
******
* Input:
* tLista* L : Puntero a un struct tipo tLista
* .......
******
* Returns:
* void, esta función no retorna nada en sí, dado que su propósito es borrar la lista.
*****/

#endif