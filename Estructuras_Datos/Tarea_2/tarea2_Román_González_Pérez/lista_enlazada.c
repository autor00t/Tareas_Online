#include "lista_enlazada.h"
#include <stdio.h>
#include <stdlib.h>

void initList(tLista *L)
{
    L->head = L->tail = L->curr = (tNodo *)malloc(sizeof(tNodo));
    L->listSize = L->pos = 0;
}

void clear(tLista *L)
{
    tNodo *temp;
    L->curr = L->head->sig;

    while (L->listSize > 0)
    {
        temp = L->curr->sig;
        free((void *)L->curr);
        L->curr = temp; 
        L->listSize--;
    }

    L->head->sig = NULL;
}

int insert(tLista *L, tElemLista* item)
{
    tNodo *aux = L->curr->sig;
    L->curr->sig = (tNodo *)malloc(sizeof(tNodo));
    L->curr->sig->info[0] = item[0];
    L->curr->sig->info[1] = item[1];
    L->curr->sig->sig = aux;

    if (L->curr == L->tail)
        L->tail = L->curr->sig;

    L->listSize++;

    return L->pos;
}

int erase(tLista *L)
{
    tNodo *temp = L->curr->sig;
    
    if (temp == L->tail) {
        L->tail = L->curr;
    }

    L->curr->sig = temp->sig;
    free((void *)temp);

    L->listSize--;
    return L->pos;
}

void moveToStart(tLista *L)
{
    L->curr = L->head;
    L->pos = 0;
}

void moveToEnd(tLista *L)
{
    L->curr = L->tail;
    L->pos = L->listSize;
}

void prev(tLista *L)
{
    if (L->curr == L->head)
        return;

    tNodo *temp;
    temp = L->head;

    while (temp->sig != L->curr)
        temp = temp->sig;

    L->curr = temp;
    L->pos--;
}

void next(tLista *L)
{
    if (L->curr != L->tail)
    {
        L->curr = L->curr->sig;
        L->pos++;
    }
}

void moveToPos(tLista *L, unsigned int posicion)
{
    unsigned int i;
    if (posicion < 0 || posicion > L->listSize)
        return;

    L->curr = L->head;
    L->pos = 0;

    for (i = 0; i < posicion; i++)
    {
        L->curr = L->curr->sig;
        L->pos++;
    }
}

void append(tLista *L, tElemLista* item)
{
    tNodo *temp = (tNodo *)malloc(sizeof(tNodo));
    temp->info[0] = item[0];
    temp->info[1] = item[1];
    temp->sig = NULL;

    L->tail->sig = temp;
    L->tail = temp;
    L->listSize++;
}

int length(tLista *L)
{
    return L->listSize;
}

int currPos(tLista *L)
{
    return L->pos;
}

tElemLista* getValue(tLista *L)
{
    return L->curr->sig->info;
}

void setValue(tLista* L, tElemLista* item) {
    L->curr->sig->info[0] = item[0];
    L->curr->sig->info[1] = item[1];
}

void deleteList(tLista *L)
{
    tNodo *temp;
    L->curr = L->head;

    while (L->listSize + 1 > 0)
    {
        temp = L->curr->sig;
        free((void *)L->curr);
        L->curr = temp;
        L->listSize--;
    }

    L->head = L->tail = L->curr = NULL;
    L->listSize = 0;
}