#ifndef ABB_H
#define ABB_H

typedef int tipoElem;

typedef struct nodoArbolBin{
    tipoElem info;
    struct nodoArbolBin *izq;
    struct nodoArbolBin *der;
}tNodo;

typedef struct {
    tNodo *raiz;
    int nElems; 
} tABB;

void initTree(tABB* T);
void clear(tABB* T);
void insert(tABB* T, tipoElem item);
void borrar(tABB* T, tipoElem item);
int find(tABB* T, tipoElem item);
int size(tABB* T);
tipoElem* preOrden(tABB* T);
tipoElem sucesor(tABB* T, tipoElem x); 

#endif