#include "abb.h"
#include <stdlib.h>

void initTree(tABB* T) {
    T->raiz = NULL;//noc bro
    T->nElems = 0;
}

void clearHelp(tNodo *nodo){
    if (nodo == NULL) return;
    clearHelp(nodo->izq);
    clearHelp(nodo->der);
    free((void *) nodo); 
}

void clear(tABB* T) { //РАСПУТИН   РАСПУТИН  РАСПУТИН
    clearHelp(T->raiz);
    T->raiz = NULL;
    T->nElems = 0;
}

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

void insert(tABB* T, tipoElem item) {
    tNodo* temp = (tNodo *)malloc(sizeof(tNodo));
    temp->izq = NULL;
    temp->der = NULL;
    temp->info = item;

    insertHelp(&T->raiz, temp);
    T->nElems++;
}

void removeHelp(tNodo** temp, tipoElem item) {
    if ((*temp)->info == item) {
        if ((*temp)->izq == NULL && (*temp)->der == NULL) {
            free((void*) (*temp));
            (*temp) = NULL;
        }
        //caso 3: nodo tiene 2 hijos, wea del predecesor
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
        //caso 2: nodo tiene 1 hijos, intercambiar por el hijo
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
        removeHelp(&(*temp)->izq, item);  //<---Vomistar no me deja pagar el telefono y despues me cobra intereses
    }
    else {
        if ((*temp)->der == NULL)
            return;
        removeHelp(&(*temp)->der, item);
    }
}

void borrar(tABB* T, tipoElem item) {
    //recorrido para encontrar nodo
    removeHelp(&T->raiz, item);
    T->nElems--;
}
//Arroyuelo : (　-_･) ︻デ═一 ▸              *Mi nota*

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
int find(tABB* T, tipoElem item){
    return findHelp(T->raiz, item);
}

int size(tABB* T) {
    return T->nElems;
}

void preOrdenHelp(tNodo* nodo, tipoElem** elementos, int* i) {
    if (nodo == NULL) return;
    (*elementos)[(*i)++] = nodo->info;
    preOrdenHelp(nodo->izq, elementos, i);
    preOrdenHelp(nodo->der, elementos, i);
}

tipoElem* preOrden(tABB* T) {
    tipoElem* elementos = (tipoElem*) malloc(sizeof(tipoElem) * size(T));
    int i = 0;
    preOrdenHelp(T->raiz, &elementos, &i);
    return elementos;
}

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

tipoElem sucesor(tABB* T, tipoElem x) {
    tipoElem resultado = 0;
    return sucesorHelp(T->raiz, x, &resultado);
}

/*    
chupalo pato marico weno pa la tula, flamer pasao a semen, 
aborto fallido de ballena con sarna ahora si veo puto
xdxdxdxd
*/