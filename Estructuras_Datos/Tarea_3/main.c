#include "producto.h"
#include "oferta.h"
#include <stdio.h>
#include <stdlib.h>

/*void factor_carga(dictProducto* D) {
    float N = 0.0;
    for (int i = 0; i < D->M; ++i) {
        if (D->HT[i].clave != -1) {
            N++;
        }
    }

    printf("El factor de carga es %f\n", N / (float) D->M);
}*/

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
    /*dictProducto D;
    
    initProducto(&D, 31);
    printf("M: %d\n", D.M);
    hashInsertProducto(&D, 2020, "Papel Higienico", 140);
    printf("1\n");
    hashInsertProducto(&D, 430, "Aceite", 40);
    printf("2\n");
    hashInsertProducto(&D, 1981, "Arroz", 50);
    printf("3\n");
    hashInsertProducto(&D, 1346, "Lata de Atun", 85);
    printf("4\n");
    hashInsertProducto(&D, 1918, "Azucar", 98);
    printf("5\n");
    hashInsertProducto(&D, 2075, "Lays", 44);
    printf("6\n");
    hashInsertProducto(&D, 1958, "Pan", 10);
    printf("7\n");
    hashInsertProducto(&D, 1945, "sum sum sum", 999);
    printf("8\n");
    hashInsertProducto(&D, 1050, "anone", 222);
    printf("9\n");
    hashInsertProducto(&D, 884, "UwU", 289);
    printf("10\n");
    hashInsertProducto(&D, 750, ";m;", 662);
    printf("11\n");
    hashInsertProducto(&D, 2589, ";_;", 532);
    printf("12\n");
    hashInsertProducto(&D, 1957, "t.t", 3141);
    printf("13\n");
    hashInsertProducto(&D, 1956, "T.T", 3140);
    printf("14\n");
    hashInsertProducto(&D, 1955, "U-U", 3214);
    printf("15\n");
    hashInsertProducto(&D, 3560, "me", 11);
    printf("16\n");
    hashInsertProducto(&D, 3124, "eche", 51);
    printf("17\n");
    hashInsertProducto(&D, 6142, "datos", 6124);
    printf("18\n");
    hashInsertProducto(&D, 2000, "mati", 412);
    printf("19\n");
    hashInsertProducto(&D, 777, "ayuda", 2819);
    printf("20\n");
    hashInsertProducto(&D, 666, "beast", 2134);
    printf("21\n");
    hashInsertProducto(&D, 5371, "im", 9012);
    printf("22\n");
    hashInsertProducto(&D, 2130, "the", 3459);
    printf("23\n");
    hashInsertProducto(&D, 1023, "worst", 4210);
    printf("24\n");
    hashInsertProducto(&D, 153, "e.e", 65);
    printf("25\n");
    hashInsertProducto(&D, 1642, "i.i", 1523);
    printf("26\n");
    hashInsertProducto(&D, 7777, "L_?", 6775);
    printf("27\n");
    hashInsertProducto(&D, 1234, "U_RR", 9123);
    printf("28\n");
    hashInsertProducto(&D, 9281, "Gaming", 9013);
    printf("29\n");
    hashInsertProducto(&D, 9104, "Warlord", 7139);
    printf("30\n");
    hashInsertProducto(&D, 1253, "XQCoW", 4152);
    printf("31\n");

    factor_carga(&D);   
    clear(&D);*/

    dictProducto Productos;
    dictOferta Ofertas;

    FILE *archivo_producto = fopen("productos.dat", "r");

    if (archivo_producto == NULL) {
        printf("Hubo un error al abrir el archivo productos.dat\n");
        exit(1);
    }

    FILE* archivo_oferta = fopen("ofertas.dat","r");
    
    if (archivo_oferta == NULL) {
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

    int i;
    
    for (i = 0; i < M_productos; i++) {
        fread(&temp_producto, sizeof(producto), 1, archivo_producto);
        hashInsertProducto(&Productos, temp_producto.codigo_producto, temp_producto.nombre_producto, temp_producto.precio);
    }

    for (i = 0; i < M_ofertas; i++) {
        fread(&temp_oferta, sizeof(oferta),1, archivo_oferta);
        hashInsertOferta(&Ofertas, temp_oferta.codigo_producto, temp_oferta.cantidad_descuento, temp_oferta.monto_descuento);
    }

    fclose(archivo_producto);
    fclose(archivo_oferta);

    return 0;
}