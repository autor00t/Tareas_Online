#include "producto.h"
#include "oferta.h"
#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int codigo_producto;
    char nombre_producto[31];
    int precio;

} producto;

typedef struct {
    int codigo_producto;
    int cantidad_descuento;
    int monto_descuento;
} oferta;

int main() {
    dictProducto Productos;
    dictOferta Ofertas;

    FILE *archivo_producto = fopen("productos.dat", "r");

    if (archivo_producto == NULL) {
        printf("Hubo un error al abrir el archivo productos.dat\n");
        exit(1);
    }

    FILE *archivo_oferta = fopen("ofertas.dat","r");
    
    if (archivo_oferta == NULL) {
        printf("Hubo un error al abrir el archivo ofertas.dat\n");
        exit(1);
    }

    FILE* archivo_compras = fopen("compras.txt","r");
    
    if (archivo_compras == NULL) {
        printf("Hubo un error al abrir el archivo ofertas.dat\n");
        exit(1);
    }

    int M_productos, M_ofertas;

    fread(&M_productos, sizeof(int), 1, archivo_producto);
    fread(&M_ofertas, sizeof(int), 1, archivo_oferta);
    
    initProducto(&Productos, M_productos);
    initOferta(&Ofertas, M_ofertas);

    producto temp_producto;
    oferta temp_oferta;

    int i, j;

    for (i = 0; i < M_productos; i++) {
        fread(&temp_producto, sizeof(producto), 1, archivo_producto);
        hashInsertProducto(&Productos, temp_producto.codigo_producto, temp_producto.nombre_producto, temp_producto.precio);
    }                   
    
    for (i = 0; i < M_ofertas; i++) {
        fread(&temp_oferta, sizeof(oferta),1, archivo_oferta);
        hashInsertOferta(&Ofertas, temp_oferta.codigo_producto, temp_oferta.cantidad_descuento, temp_oferta.monto_descuento);
    }
    
    int cantidad_ranking, cantidad_clientes, cantidad_productos, codigo_producto;
    char temp;

    fscanf(archivo_compras, "%d", &cantidad_ranking);

    tColaP ranking;
    initColaP(&ranking, cantidad_ranking);

    
    while ((temp = getc(archivo_compras)) != '\n')
        ;

    fscanf(archivo_compras, "%d", &cantidad_clientes);
    
    while ((temp = getc(archivo_compras)) != '\n')
        ;
    
    for (i = 0; i < cantidad_clientes; i++) {
        
        fscanf(archivo_compras, "%d", &cantidad_productos);

        while ((temp = getc(archivo_compras)) != '\n')
            ;

        for(j = 0; j < cantidad_productos; j++) {
            fscanf(archivo_compras, "%d", &codigo_producto);

            while ((temp = getc(archivo_compras)) != '\n')
                ;
            
            insertColaP(&ranking, codigo_producto, &Productos, &Ofertas);
        }
    }
    
    fclose(archivo_oferta);
    fclose(archivo_producto);
    fclose(archivo_compras);

    FILE *archivo_ranking = fopen("ranking.txt", "w");
    
    for(i = 0; i < cantidad_ranking; i++) {
        fprintf(archivo_ranking, "%d %s %d %d\n", findMaxCodigo(&ranking), hashSearchProductoNombre(&Productos, hashPositionProducto(&Productos, findMaxCodigo(&ranking))), findMaxCantidad(&ranking), findMaxMonto(&ranking));
        removeMax(&ranking);
    }

    deleteColaP(&ranking);
    clearProducto(&Productos);
    clearOferta(&Ofertas);
    fclose(archivo_ranking);

    return 0;
}
