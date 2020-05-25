#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHAR 204
#define MAX_S 1000000

int es_prefijo(char *S, char *P);
char **buscar_str(char **S, int n, char *P, int *largo);
void escribir_archivos(char *nombre_archivo_S, char *nombre_archivo_P);

int main()
{
    escribir_archivos("S.txt", "P.txt");

    return 0;
}

char **buscar_str(char **S, int n, char *P, int *largo)
{
    char **resultado = (char **)malloc(sizeof(char *) * n);
    int s_array = 0, i = 0;

    while (s_array < n)
    {

        if (es_prefijo(S[s_array], P))
        {
            resultado[i] = (char *)malloc(sizeof(char) * MAX_CHAR);
            strcpy(resultado[i++], S[s_array]);
        }

        ++s_array;
    }

    *largo = i;
    resultado = (char **)realloc(resultado, sizeof(char *) * i);

    return resultado;
}

/*****
* char** buscar_str
******
* Busca en el arreglo S los strings que tengan como prefijo al string P, para luego agregarlos a un arreglo distinto
* que será retornado al final de la función.
****** 
* Input:
* char** S: Un arreglo de strings. 
* int n: Número de strings que contiene el arreglo S. 
* char* P: Corresponde al prefijo que queremos buscar.
* int* largo: Corresponde al largo del arreglo retornado.  
******
* Returns:
* char**, La función retorna un arreglo de strings pertenecientes al parametro S en el cual cada elemento tiene como prefijo al string P.
*****/

int es_prefijo(char *S, char *P)
{
    for (int i = 0; P[i] != '\0'; ++i)
    {
        if (S[i] != P[i] || S[i] == '\0')
            return 0;
    }
    return 1;
}

/*****
* int es_prefijo
******
* es_prefijo corresponde a la función que nos ayuda a saber si el string P forma parte como prefijo del string S.
******
* Input:
* char* S : String que queremos comparar.
* char* P : Corresponde al string que utilizaremos para comparar.
******
* Returns:
* int, La función retorna 1 si es que el string P es prefijo del string S, de lo contrario, retorna 0.
*****/

void escribir_archivos(char *nombre_archivo_S, char *nombre_archivo_P)
{
    FILE *archivo_S, *archivo_P;

    if ((archivo_S = fopen(nombre_archivo_S, "r")) == NULL)
    {
        printf("Hubo un error al abrir el archivo %s.\n", nombre_archivo_S);
        exit(1);
    }

    if ((archivo_P = fopen(nombre_archivo_P, "r")) == NULL)
    {
        printf("Hubo un error al abrir el archivo %s.\n", nombre_archivo_P);
        exit(1);
    }

    char *P = (char *)malloc(sizeof(char) * MAX_CHAR);
    char **S = (char **)malloc(sizeof(char *) * MAX_S);

    char temp;
    int n = 0, s_array = 0, s_string = 0, bandera = 1;
    S[s_array] = (char *)malloc(sizeof(char) * MAX_CHAR);
    while (bandera)
    {
        temp = getc(archivo_S);
        if (temp == '\n' || temp == EOF)
        {
            S[s_array++][s_string] = '\0';
            if (!strcmp(S[s_array - 1], ""))
            {
                break;
            }
            S[s_array] = (char *)malloc(sizeof(char) * MAX_CHAR);
            s_string = 0;
            n++;
            if (temp == EOF) {
                bandera = 0;
            }
        }
        else if (temp != '\r')
        {
            S[s_array][s_string++] = temp;
        }
    }

    S = (char **)realloc(S, sizeof(char *) * n);
    fclose(archivo_S);
    
    char **resultado;
    int p_array = 0, largo;
    bandera = 1;

    while (bandera)
    {
        temp = getc(archivo_P);

        if (temp == '\n' || temp == EOF)
        {
            P[p_array] = '\0';
            p_array = 0;
            if (!strcmp(P, ""))
            {
                break;
            }

            resultado = buscar_str(S, n, P, &largo);

            FILE *fp = fopen(strcat(P, ".out\0"), "w");
            if (fp == NULL)
            {
                printf("Ocurrió un error al crear el archivo %s.", P);
                exit(1);
            }
            for (int i = 0; i < largo; ++i)
            {
                fprintf(fp, "%s", resultado[i]);
                fprintf(fp, "\n");
            }
            fclose(fp);
            free((void *)resultado);
            if (temp == EOF) 
            {
                bandera = 0;
            }
        }
        else if (temp != '\r')
        {
            P[p_array++] = temp;
        }
    }

    free((void *)P);
    free((void *)S);
    fclose(archivo_P);
}

/*****
* void escribir_archivos
******
* El trabajo de esta función es escribir una cantidad de archivos basados en el número de prefijos que hay en
* el archivo P, cada archivo contiene todas las palabras en S que tengan como prefijo un string de P.
* El nombre del archivo .out, corresponde al nombre del prefijo, Por lo tanto si mi prefijo es 'ol', la función
* creará un archivo llamado 'ol.out' y dentro de él se encontrarán todas las palabras en S que contengan 'ol'.
******
* Input:
* char *nombre_archivo_S: Corresponde al nombre del archivo S   
* char *nombre_archivo_P: Corresponde al nombre del archivo P
******
* Returns:
* void, Esta función no retorna nada dado que su único trabajo es escribir archivos.
*****/