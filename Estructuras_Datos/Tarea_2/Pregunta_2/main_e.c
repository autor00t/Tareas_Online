#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
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
    // tu conoces a arroyuelo??
    // tu no conoces a arroyuelo
    int u,numeroCuliao;
    char operacion1[20]; 
    FILE *archivo_entrada; 
        if((archivo_entrada = fopen("input.txt", "r")) == NULL){
            printf("Hubo un problema al abrir el archivo");
            exit(1);
        }
    fscanf(archivo_entrada,"%d",&u);
    while(fscanf(archivo_entrada,"%s",operacion1)==1){
        if (strcmp(operacion1,"SUCESOR")==0){
            printf("la operacion es sucesor puto\n");
              // sucesor(pichula,numeroCuliao )
        }
        else if (strcmp(operacion1,"INSERTAR")==0){
            printf("insertarle un dildo a arroyuelo.jpg\n");
        }
        else if (strcmp(operacion1,"PREORDEN")==0){
            printf("preorden conchetumare\n"); 
        }
        else if (strcmp(operacion1,"BORRAR")==0){
            printf("me borraste wey\n");
        }
        else{ 
         numeroCuliao= atoi(operacion1); //es legal usar atoi???
         printf("%d\n",numeroCuliao); //wena pato, tu puedes, confia en ti, confia en tus capacidades, confia en tu ser, congija ees n que pussdes
        }
    }
    return 0;
    fclose(archivo_entrada); //ayudante que esta 
    //leyendo esto, prometo que no me demore 3 
    //horas seguidas programando esto
    //saludos
}