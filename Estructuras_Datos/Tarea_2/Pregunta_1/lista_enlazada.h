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
void clear(tLista *L);
int insert(tLista *L, tElemLista* item);
int erase(tLista *L);
void moveToStart(tLista *L);
void moveToEnd(tLista *L);
void prev(tLista *L); 
void next(tLista *L);
void moveToPos(tLista *L, unsigned int posicion);
void append(tLista *L, tElemLista* item);
int length(tLista *L);
int currPos(tLista *L);
tElemLista* getValue(tLista *L);
void setValue(tLista* L, tElemLista* item);
void deleteList(tLista *L);

#endif