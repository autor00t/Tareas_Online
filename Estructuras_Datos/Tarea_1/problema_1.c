#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHAR 200
#define MAX_S 1000000
#define MAX_P 1000

int es_prefijo(char* S, char* P, int n);
char** buscar_str(char** S, int n, char* P, int* largo);
void escribir_archivos(char* nombre_archivo_S, char* nombre_archivo_P);

int main() {
    /*Probar por si la cago
    char* S[MAX_CHAR] = {"aaaww", "aiwffjw", "asfsfad", "aaaoowo"};
    char* P = "aaa";
    int largo;
    char** resultado = buscar_str(S, 4, P, &largo);
    printf("%d\n", largo);
    for (int i = 0; i < largo; ++i)
        printf("%s\n", resultado[i]);
    */
    escribir_archivos("S.txt", "P.txt");
    //free((void*) resultado);
    //
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
    resultado = (char**) realloc(resultado, sizeof(char*) * i);

    return resultado;
}

int es_prefijo(char* S, char* P, int n) {
    for (int i = 0; i < n && P[i] != '\0'; ++i) {
        if (S[i] != P[i])
            return 0;
    }
    return 1;
}

void escribir_archivos(char* nombre_archivo_S, char* nombre_archivo_P) {
    FILE *archivo_S, *archivo_P;

    if ((archivo_S = fopen(nombre_archivo_S, "r")) == NULL) {
        printf("Hubo un error al abrir el archivo %s.\n", nombre_archivo_S);
        exit(1);
    }

    if ((archivo_P = fopen(nombre_archivo_P, "r")) == NULL){
        printf("Hubo un error al abrir el archivo %s.\n", nombre_archivo_P);
        exit(1);
    }

    char* P = (char*) malloc(sizeof(char) * MAX_CHAR);
    char** S = (char**) malloc(sizeof(char*) * MAX_S);

    char temp;
    int n = 0, s_array = 0, s_string = 0;
    S[s_array] = (char*) malloc(sizeof(char) * MAX_CHAR);
    while ((temp = getc(archivo_S)) != EOF) {
        if (temp == '\n') {
            S[s_array++][s_string] = '\0';
            S[s_array] = (char*) malloc(sizeof(char) * MAX_CHAR);
            s_string = 0;
            n++;
        }
        else {
            S[s_array][s_string++] = temp;
        }

    }
    S = (char**) realloc(S, sizeof(char*) * n);
    fclose(archivo_S);

    char** resultado;
    int p_array = 0, largo;
    while ((temp = getc(archivo_P)) != EOF) {
        if (temp == '\n') {
            P[p_array] = '\0';
            p_array = 0;
            resultado = buscar_str(S, n, P, &largo);
            FILE *fp = fopen(strcat(P, ".out"), "w");
            if (fp == NULL) {
                printf("Ocurrió un error al crear el archivo %s.", P);
                exit(1);
            }
            for (int i = 0; i < largo; ++i) {
                fprintf(fp, "%s" ,resultado[i]);
                fprintf(fp, "\n");
            }
            fclose(fp);
            free((void*) resultado);
        }
        else {
            P[p_array++] = temp; 
        }
    }

    free((void *) P);
    free((void *) S);
    fclose(archivo_P);
}
