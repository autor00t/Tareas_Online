#include "abb.h"
#include <stdlib.h>

void initTree(tABB* T) {
    T->raiz = NULL;
    T->nElems = 0;
}

/*****
* void initList
******
* Inicializa una lista vacia.
******
* Input: 
* tABB* T : Puntero a struct tipo tABB.
* .......
******
* Returns:
* void, no retorna nada, en su lugar, genera una lista vacía.
*****/

void clearHelp(tNodo *nodo){
    if (nodo == NULL) return;
    clearHelp(nodo->izq);
    clearHelp(nodo->der);
    free((void *) nodo); 
}

/*****
* void clearHelp
******
* Función recursiva auxiliar que ayuda a limpiar el ABB.
******
* Input:
* tNodo *nodo : Puntero a un nodo del ABB.
* .......
******
* Returns:
* void, es una funcion recursiva auxiliar que no retorna nada, en su lugar, ayuda a limpiar el árbol, dejándolo vacío.
*****/

void clear(tABB* T) { 
    clearHelp(T->raiz);
    T->raiz = NULL;
    T->nElems = 0;
}

/*****
* void clear 
******
* Elimina los elementos del ABB, dejándolo vacío.
******
* Input:
* tABB* T : Puntero a struct tipo tABB.
* .......
******
* Returns:
* void, no retorna nada, en su lugar, limpia el árbol . 
*****/

void insertHelp(tNodo** nodo, tNodo* temp) {
    if (*nodo == NULL) {
        *nodo = temp;
        return;
    }
    
    if (temp->info < (*nodo)->info) {
        insertHelp(&(*nodo)->izq, temp);
    }
    else if(temp->info > (*nodo)->info) { 
        insertHelp(&(*nodo)->der, temp);
    }
}

/*****
* void insertHelp
******
* Función recursiva auxiliar que ayuda a insertar el nodo en el ABB.
******
* Input:
* tNodo** nodo : Doble puntero a un nodo del ABB.
* tNodo* temp: Puntero a un nodo del ABB.
* .......
******
* Returns:
* void, es una función recursiva que ayuda a insert para que complete su cometido. 
*****/

void insert(tABB* T, tipoElem item) {
    tNodo* temp = (tNodo *)malloc(sizeof(tNodo));
    temp->izq = NULL;
    temp->der = NULL;
    temp->info = item;

    insertHelp(&T->raiz, temp);
    T->nElems++;
}

/*****
* void insert 
******
* Función que inserta el parametro entregado en el árbol.
******
* Input:
* tABB* T : Puntero a struct tipo tABB.
* tipoElem item : Tipo de dato del ABB, este caso es un entero (int).
* .......
******
* Returns:
* void, no retorna nada, en su lugar, su objetivo es insertar el parametro en el árbol ABB.
*****/

void borrarHelp(tNodo** temp, tipoElem item) {
    if ((*temp)->info == item) {
        if ((*temp)->izq == NULL && (*temp)->der == NULL) {
            free((void*) (*temp));
            (*temp) = NULL;
        }
        else if ((*temp)->izq != NULL && (*temp)->der != NULL) {
            tNodo** aux = temp;
            temp = &((*temp)->izq); 

            while ((*temp)->der != NULL) {
                temp = &((*temp)->der);
            }

            (*aux)->info = (*temp)->info;

            if ((*temp)->izq != NULL) {
                aux = &(*temp)->izq;
                free((void*) *temp);
                *temp = NULL;
            }
            else {
                free((void*) *temp);
                *temp = NULL;
            }
        }
        else {
            tNodo* aux;
            if ((*temp)->izq != NULL) {
                aux = (*temp)->izq;
                free((void*) *temp);
                (*temp) = aux;
            }
            else {
                aux = (*temp)->der;
                free((void*) *temp);
                *temp = aux;
            }
        }
    }
    else if (item < (*temp)->info) {
        if ((*temp)->izq == NULL)
            return;
        borrarHelp(&(*temp)->izq, item);
    }
    else {
        if ((*temp)->der == NULL)
            return;
        borrarHelp(&(*temp)->der, item);
    }
}

/*****
* void borrarHelp
******
* Función recursiva auxiliar, que ayuda a borrar el nodo correspondiente.
******
* Input:
* tNodo** nodo : Doble puntero a un nodo del ABB.
* tipoElem item : Tipo de dato del ABB, este caso es un entero (int)
* .......
******
* Returns:
* void, no retorna nada, en su lugar, ayuda a eliminar el nodo con el valor asociado al input.
*****/

void borrar(tABB* T, tipoElem item) {
    borrarHelp(&T->raiz, item);
    T->nElems--;
}

/*****
* void borrar 
******
* Función que tiene como objetivo borrar el nodo que contenga el valor entregado como parametro.
******
* Input:
* tABB* T : Puntero a struct tipo tABB.
* tipoElem item : Tipo de dato del ABB, este caso es un entero (int)
* .......
******
* Returns:
* void, no retorna nada, en su lugar, elimina el nodo con el valor asociado al input
*****/

int findHelp(tNodo* nodo, tipoElem item){    
    if (nodo == NULL) return 0;
    if (nodo->info == item) {
        return 1;
    }
    if (item < nodo->info)
        return findHelp(nodo->izq, item);
    else
        return findHelp(nodo->der, item);
}

/*****
* int findHelp 
******
* Función recursiva auxilar que ayuda a encontrar el nodo que tenga como valor el input entregado.
******
* Input:
* tNodo *nodo : Puntero a un nodo del ABB.
* tipoElem item : Tipo de dato del ABB, este caso es un entero (int)
* .......
******
* Returns:
* int, funcion recursiva auxiliar que retorna 0 en el caso de que no se encuentre el nodo, o 1 en el caso contrario.
*****/

int find(tABB* T, tipoElem item){
    return findHelp(T->raiz, item);
}

/*****
* int find 
******
* Busca un elemento en el ABB, retornando 0 si no lo encuentra
******
* Input:
* tABB* T : Puntero a struct tipo tABB.
* tipoElem item : Tipo de dato del ABB, este caso es un entero (int)
* .......
******
* Returns:
* int, funcion que retorna 0 en  caso de que no se encuentre el nodo, o 1 en el caso contrario.
*****/

int size(tABB* T) {
    return T->nElems;
}

/*****
* int size
******
* Retorna el numero de nodos que tiene el ABB.
******
* Input:
* tABB* T : Puntero a struct tipo tABB.
* .......
******
* Returns:
* int, el entero representa la cantidad de nodos actuales en el ABB.
*****/

void preOrdenHelp(tNodo* nodo, tipoElem** elementos, int* i) {
    if (nodo == NULL) return;
    (*elementos)[(*i)++] = nodo->info;
    preOrdenHelp(nodo->izq, elementos, i);
    preOrdenHelp(nodo->der, elementos, i);
}

/*****
* void preOrdenHelp
******
* Resumen Función
******
* Input:
* tNodo *nodo : Puntero a un nodo del ABB.
* tipoElem** elementos: Doble puntero al tipo de dato del ABB, en este caso, de tipo entero(int)
* int* i: Puntero a elemento int
* .......
******
* Returns:
* void, es una funcion recursiva auxiliar que recorre el ABB, pero no retorna nada.
*****/

tipoElem* preOrden(tABB* T) {
    tipoElem* elementos = (tipoElem*) malloc(sizeof(tipoElem) * size(T));
    int i = 0;
    preOrdenHelp(T->raiz, &elementos, &i);
    return elementos;
}

/*****
* tipoElem* preOrden 
******
* Funcion que retorna un arreglo de los nodos en pre-orden
******
* Input:
* tABB* T : Puntero a struct tipo tABB.
* .......
******
* Returns:
* tipoElem*, esta función devuelve un arreglo con el recorrido preOrden realizado por la funcion
*****/

tipoElem sucesorHelp(tNodo* nodo, tipoElem x, tipoElem* resultado) {
    if (nodo == NULL)
        return 0;
    else if (nodo->izq != NULL && sucesorHelp(nodo->izq, x, resultado))
        return *resultado;
    else if (x < nodo->info) 
        return (*resultado = nodo->info);
    else if(nodo->der != NULL && sucesorHelp(nodo->der, x, resultado))
        return *resultado;
    return 0;
}

/*****
* tipoElem sucesorHelp 
******
* Funcion recursiva auxiliar para encontrar el sucesor
******
* Input:
* tNodo *nodo : Puntero a un nodo del ABB.
* tipoElem x :  Elemento del ABB de tipo entero(int) del cual queremos encontrar su sucesor.
* tipoElem* resultado: Puntero al elemento del ABB, en este caso, de tipo entero (int).
* .......
******
* Returns:
* tipoElem, funcion recursiva auxiliar que retorna el valor del sucesor.
*****/

tipoElem sucesor(tABB* T, tipoElem x) {
    tipoElem resultado = 0;
    return sucesorHelp(T->raiz, x, &resultado);
}

/*****
* tipoElem sucesor 
******
* Esta funciona hace uso de la función recursiva sucesorHelp con el fin de encontrar el sucesor de la variable x.
* En el caso de que no se encuentre un sucesor, retorna 0.
******
* Input:
* tABB* T : Puntero a struct tipo tABB.
* tipoElem x : Valor del cual queremos encontrar su sucesor.
* .......
******
* Returns:
* tipoElem, esta función retorna el sucesor del parametro x, en caso de que no se encuentre, se retorna 0
*****/
/*
                       __
                     .'  '.
                 _.-'/  |  \
    ,        _.-"  ,|  /  0 `-.
    |\    .-"       `--""-.__.'=====================-,
    \ '-'`        .___.--._)=========================|
     \            .'      |                          |
      |     /,_.-'        |     PONGAME 100 :3       |
    _/   _.'(             |                          |
   /  ,-' \  \            |        PORFAUWU          |
   \  \    `-'            |            <3            |
    `-'                   '--------------------------'
*/