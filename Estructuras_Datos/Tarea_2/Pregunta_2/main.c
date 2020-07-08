#include "abb.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *archivo_entrada = fopen("input.txt", "r");
    if (archivo_entrada == NULL)
    {
        printf("Ocurrió un error al abrir el archivo.\n");
        exit(1);
    }

    int u;
    char temp;
    fscanf(archivo_entrada, "%d", &u);

    while ((temp = getc(archivo_entrada)) != '\n')
        ;

    tABB ABB;
    initTree(&ABB);

    int elemento, i, bandera = 1;
    int* elementos_preorden;
    char tipo_operacion, resultado_sucesor;

    tipo_operacion = getc(archivo_entrada);

    while (bandera)
    {
        if (tipo_operacion == 'I')
        {
            while ((temp = getc(archivo_entrada)) != ' ')
                ;
            fscanf(archivo_entrada, "%d", &elemento);

            insert(&ABB, elemento);
        }
        else if (tipo_operacion == 'B')
        {
            while ((temp = getc(archivo_entrada)) != ' ')
                ;
            fscanf(archivo_entrada, "%d", &elemento);

            borrar(&ABB, elemento);
        }
        else if (tipo_operacion == 'P')
        {
            elementos_preorden = preOrden(&ABB);

            for (i = 0; i < size(&ABB); ++i)
            {
                printf("%d", elementos_preorden[i]);
                if (i != size(&ABB) - 1)
                {
                    printf(" ");
                }
            }
            printf("\n");

            free((void *)elementos_preorden);
        }
        else if (tipo_operacion == 'S')
        {
            while ((temp = getc(archivo_entrada)) != ' ')
                ;
            fscanf(archivo_entrada, "%d", &elemento);
            if (!(resultado_sucesor = sucesor(&ABB, elemento)))
            {
                if (elemento < u)
                {
                    printf("%d\n", u);
                }
            }
            else
            {
                printf("%d\n", resultado_sucesor);
            }
        }
        while ((tipo_operacion = getc(archivo_entrada)) != '\n' && tipo_operacion != EOF)
            ;
        if (tipo_operacion == EOF)
        {
            bandera = 0;
        }
        else
        {
            tipo_operacion = getc(archivo_entrada);
        }
    }

    clear(&ABB);
    fclose(archivo_entrada);

    return 0;
}