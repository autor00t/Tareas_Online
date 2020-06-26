#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
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
               sucesor(pichula,numeroCuliao )
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