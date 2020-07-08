#include "lista_enlazada.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* archivo_entrada = fopen("input1.dat", "r");
    if (archivo_entrada == NULL) {
        printf("Ha ocurrido un error al abrir el archivo.\n");
        exit(1);
    }
    FILE* archivo_salida = fopen("output1.dat", "w");
    if (archivo_salida == NULL) {
        printf("Ha ocurrido un error al crear el archivo de salida.\n");
        exit(1);
    }

    int M, N;
    char temp;
    fscanf(archivo_entrada, "%d", &M);
    
    while ((temp = getc(archivo_entrada)) != '\n')
        ;

    fscanf(archivo_entrada, "%d", &N);

    while ((temp = getc(archivo_entrada)) != '\n')
        ;

    tLista L1;
    int bloque_temp[2] = {1, M}, bloque_pedido[2];
    initList(&L1);
    append(&L1, bloque_temp);     
    tLista L2;
    initList(&L2);

    int argumento, espacio_suficiente;
    char operacion;

    for (int i = 0; i < N; i++) {
        operacion = getc(archivo_entrada);
        while ((temp = getc(archivo_entrada)) != ' ')
            ;
        fscanf(archivo_entrada, "%d", &argumento);
        if (i + 1 != N) {
            while ((temp = getc(archivo_entrada)) != '\n')
                ;
        }
        
        if (operacion == 'm') {
            moveToStart(&L1);
            espacio_suficiente = 0;
            while (currPos(&L1) < length(&L1) && !espacio_suficiente) {
                bloque_temp[0] = getValue(&L1)[0];
                bloque_temp[1] = getValue(&L1)[1];
                if (bloque_temp[1] - bloque_temp[0] + 1 >= argumento)
                    espacio_suficiente = 1;
                else
                    next(&L1);
            }
            if (espacio_suficiente) {
                bloque_pedido[0] = bloque_temp[0];
                bloque_pedido[1] = bloque_temp[0] + argumento - 1;
                append(&L2, bloque_pedido);
                fprintf(archivo_salida, "Bloque de %d bytes asignado a partir del byte %d\n", argumento, bloque_temp[0]);
                bloque_temp[0] = bloque_pedido[1] + 1;                       
                setValue(&L1, bloque_temp);
            }
            else {
                fprintf(archivo_salida, "Bloque de %d bytes NO puede ser asignado\n", argumento);
            }
        }
        else {
            moveToStart(&L2);
            
            while (getValue(&L2)[0] != argumento){
                next(&L2);                 
            }

            bloque_temp[0] = getValue(&L2)[0];
            bloque_temp[1] = getValue(&L2)[1];
            erase(&L2);
            fprintf(archivo_salida, "Bloque de %d bytes liberado\n", bloque_temp[1] - bloque_temp[0] + 1);

            moveToStart(&L1);

            while (getValue(&L1)[0] < bloque_temp[0]) {
                next(&L1);
            }
            
            if (currPos(&L1) != 0) {
                prev(&L1); 
                
                if (getValue(&L1)[1] == bloque_temp[0] - 1) {
                    bloque_temp[0] = getValue(&L1)[0];
                    erase(&L1);
                }
                else {
                    next(&L1);
                }
            }

            if (currPos(&L1) != length(&L1)) {
                if (getValue(&L1)[0] == bloque_temp[1] + 1){
                    bloque_temp[1] = getValue(&L1)[1];
                    erase(&L1);
                }
            }
            
            insert(&L1, bloque_temp);
        }
    }

    if (length(&L2) > 0) {
        int sobrantes = 0;
        moveToStart(&L2);
        while(currPos(&L2) < length(&L2)) {
            sobrantes += getValue(&L2)[1] - getValue(&L2)[0] + 1;
            next(&L2);
        }
                
        fprintf(archivo_salida, "Quedaron %d bloques sin liberar (%d bytes)\n", length(&L2), sobrantes);
    }
    else {
        fprintf(archivo_salida, "Toda la memoria dinámica pedida fue liberada\n");
    }

    fclose(archivo_entrada);
    fclose(archivo_salida);
    deleteList(&L1);
    deleteList(&L2);
   
    return 0;                                                                                       
}
