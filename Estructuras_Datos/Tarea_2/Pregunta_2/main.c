#include "abb.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    /* Por si la cagamos uwuwuwuuwuw
    tABB temp;
    initTree(&temp);
    insert(&temp, 28);
    insert(&temp, 16);
    insert(&temp, 5);
    insert(&temp, 25);
    insert(&temp, 31);
    insert(&temp, 29);
    insert(&temp, 32);
    
    printf("            %d\n", temp.raiz->info);
    printf("    %d               %d\n", temp.raiz->izq->info, temp.raiz->der->info);
    printf("%d       %d     %d           %d\n", temp.raiz->izq->izq->info, temp.raiz->izq->der->info, temp.raiz->der->izq->info, temp.raiz->der->der->info);
    printf("                    %d\n\n\n\n\n\n\n",temp.raiz->der->izq->der->info);
    
    printf("      %d\n", temp.raiz->info);
    printf("%d             %d\n", temp.raiz->izq->info, temp.raiz->der->info);
    printf("   %d      %d            %d\n", temp.raiz->izq->der->info, temp.raiz->der->izq->info, temp.raiz->der->der->info);
    printf("                    %d\n", temp.raiz->der->der->izq->info);
    
    printf("largo: %d\n", size(&temp));
    printf("            %d\n", temp.raiz->info);
    printf("    %d               %d\n", temp.raiz->izq->info, temp.raiz->der->info);
    printf("%d       %d     %d           %d\n\n\n\n\n", temp.raiz->izq->izq->info, temp.raiz->izq->der->info, temp.raiz->der->izq->info, temp.raiz->der->der->info);

    borrar(&temp, 28);

    printf("largo: %d\n", size(&temp));
    printf("            %d\n", temp.raiz->info);
    printf("    %d               %d\n", temp.raiz->izq->info, temp.raiz->der->info);
    printf("%d       %d                %d\n\n\n\n\n", temp.raiz->izq->izq->info, temp.raiz->izq->der->info, temp.raiz->der->der->info);

    tipoElem* test = preOrden(&temp);

    for (int i = 0; i < size(&temp); ++i) {
        printf("%d\n", test[i]);
    }

    free((void*) test);

    printf("El sucesor de %d es %d\n", 32, sucesor(&temp, 32));

    clear(&temp);
    */

    FILE *archivo_entrada = fopen("input.txt", "r");
    if (archivo_entrada == NULL)
    {
        printf("Ocurrió un error al abrir el archivo.");
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