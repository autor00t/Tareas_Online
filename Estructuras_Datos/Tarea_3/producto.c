#include "producto.h"
#include <stdlib.h>
#include <string.h>

void initProducto(dictProducto *D, int m) {
    int original = m;
    //while (!primo(m))
    //    m++; // tas bien mati____
    //nop ;//; ;=; ;-;/
    /*if (original / m > 0.8) {
        m++;
        while (!primo(m))
            m++;
    }*/
    while (1.0 * original / m > 0.75) { 
        m++; //miren carso enrtoencre esta sotolcuoj, jpp: pero saocnera wn eas eaw enerible turcha wn -oscarito: chauspem la coretnea jp
    }

    D->M = m;

    D->HT = (ranuraProducto*) malloc(sizeof(ranuraProducto) * D->M);
    for (int i = 0; i < m; i++) {
        D->HT[i].clave = -1; //cuando esta vacio la clave es -1
    }
}

int hashInsertProducto(dictProducto *D, tipoClave k, char *nombre_producto, int precio) {
    int inicio, i;
    int pos = inicio = h(k, D->M);
    tipoInfoProducto temp;
    strcpy(temp.nombre_producto, nombre_producto);
    temp.precio = precio;

    for (i = 1; D->HT[pos].clave != -1 && D->HT[pos].clave != k; ++i) {
        pos = (inicio + p(k, i)) % D->M;
    }
    if (D->HT[pos].clave == k)
        return 0;
    else {
        D->HT[pos].clave = k;
        D->HT[pos].info = temp;
        return 1;
    }
}

int hashPositionProducto(dictProducto *D, tipoClave k) {
    int inicio, i;
    int pos = inicio = h(k, D->M);

    for (i = 1; D->HT[pos].clave != -1 && D->HT[pos].clave != k; i++)
        pos = (inicio + p(k, i)) % D->M;

    if (D->HT[pos].clave == k)
        return pos;
    else
        return -1;
}

tipoInfoProducto hashSearchProducto(dictProducto *D, int pos) {
    return D->HT[pos].info;
}

int h(tipoClave k, int m) {
    int pos;
    pos = k;
    while(pos >=m){
        pos = pos >> 1;
    }

    return abs(pos) % m;
}

long h2(tipoClave k) {
    return 2 * k * k + 8;
    /*
    long int pos = 0;
    int i;
    char array[11];
    sprintf(array,"%d", k);
    for (i = 0; i < strlen(array); ++i){
            pos += array[i]*(10^i)// NO SE ELEVAR BROOO;
    }
    return (pos/5);  
    */
}

long p(tipoClave k, int i) {//QUE ME DEVUELVA LA POSICION FINAL
                            //que quiero meter la wea
    return i * h2(k);
}

void clearProducto(dictProducto *D) {
    free((void*) D->HT);
}

/*
int hashInsert(ranura HT[], tipoClave k, tipoInfo I) {
    int inicio, i;
    int pos = inicio = h(k);
    for (i = 1; HT[pos].clave != VACIA && HT[pos].clave != k; i++)
        pos = (inicio + p(k, i)) % M; // próxima ranura en la secuencia
    if (HT[pos].clave == k)
        return 0; // inserción no exitosa: clave repetida
    else
    {
        HT[pos].clave = k;
        HT[pos].info = I;
        return 1; // inserción exitosa
}
    }

typedef struct tabla_hash {
	char *key;
	char *value;
	
}tabla_hash; // Struct que representa la tabla de hashing

typedef struct{
	tabla_hash **entrada;
}ht_t; //Representa una entrada en la tabla de hashing, un bloque.

ht_t *ht_create(void){
	//Aloja la memoria para la tabla
	ht_t *hashtable = malloc(sizeof(ht_t*) * TABLE_SIZE);


	//Aloja la memoria de los bloques de la tabla
	hashtable->entrada = malloc(sizeof(tabla_hash*) * TABLE_SIZE);

	//Coloca cada bloque de la tabla, con  valor NULL para operarlo apropiadamente.
	int i=0;
	for (; i < TABLE_SIZE; ++i){
		hashtable->entrada[i]=NULL;
	}
	return hashtable;
*/