#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHAR 200
#define MAX_S 1000000
#define MAX_P 1000

int es_prefijo(char* S, char* P, int n);
char** buscar_str(char** S, int n, char* P, int* largo);

int main() {
    //char** resultado = buscar_str(S, 7, P, &largo);
    //free((void*) resultado);

    return 0;
}

char** buscar_str(char** S, int n, char* P, int* largo) {
    char **resultado = (char**) malloc(sizeof(char*) * n);
    int s_array = 0, i = 0;

    while (s_array < n) {

        if (es_prefijo(S[s_array], P, n)){
            resultado[i] = (char*) malloc(sizeof(char) * MAX_CHAR);
            strcpy(resultado[i++], S[s_array]);
        }

        ++s_array;
    }

    *largo = i;

    return resultado;
}

int es_prefijo(char* S, char* P, int n) {
    for (int i = 0; i < n && P[i] != '\0' && P[i] != EOF; ++i) {
        if (S[i] != P[i])
            return 0;
    }
    return 1;
}
