#include <stdio.h>
#include <string.h>
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

void crear_productos() {
    FILE *fp = fopen("productos.dat", "wb");

    producto inv;
    int i = 12;
    fwrite(&i, sizeof(int), 1, fp);

    inv.codigo_producto = 29130542;
    strcpy(inv.nombre_producto, "uwu");
    inv.precio = 3520;
    fwrite(&inv, sizeof(producto), 1, fp);

    inv.codigo_producto = 2895;
    strcpy(inv.nombre_producto, "iwi");
    inv.precio = 8978;
    fwrite(&inv, sizeof(producto), 1, fp);

    inv.codigo_producto = 78920;
    strcpy(inv.nombre_producto, "ewe");
    inv.precio = 858585;
    fwrite(&inv, sizeof(producto), 1, fp);

    inv.codigo_producto = 8792;
    strcpy(inv.nombre_producto, "anone");
    inv.precio = 8888;
    fwrite(&inv, sizeof(producto), 1, fp);

    inv.codigo_producto = 6969;
    strcpy(inv.nombre_producto, "Belle Delphine's Bath Water");
    inv.precio = 6969;
    fwrite(&inv, sizeof(producto), 1, fp);

    inv.codigo_producto = 4200;
    strcpy(inv.nombre_producto, ";m;");
    inv.precio = 5480;
    fwrite(&inv, sizeof(producto), 1, fp);

    inv.codigo_producto = 134;
    strcpy(inv.nombre_producto, ";_;");
    inv.precio = 130130;
    fwrite(&inv, sizeof(producto), 1, fp);

    inv.codigo_producto = 57410;
    strcpy(inv.nombre_producto, "sal lobos");
    inv.precio = 120120;
    fwrite(&inv, sizeof(producto), 1, fp);

    inv.codigo_producto = 870564;
    strcpy(inv.nombre_producto, "Las pajas");
    inv.precio = 4800;
    fwrite(&inv, sizeof(producto), 1, fp);

    inv.codigo_producto = 911;
    strcpy(inv.nombre_producto, "Torres Gemelas");
    inv.precio = 2000;
    fwrite(&inv, sizeof(producto), 1, fp);

    inv.codigo_producto = 879879;
    strcpy(inv.nombre_producto, "cortada de cocos");
    inv.precio = 5802;
    fwrite(&inv, sizeof(producto), 1, fp);

    inv.codigo_producto = 2020;
    strcpy(inv.nombre_producto, "Papel Higienico");
    inv.precio = 3569;
    fwrite(&inv, sizeof(producto), 1, fp);

    /*
    inv.codigo_producto = 1;
    strcpy(inv.nombre_producto, "Se busca polola");
    inv.precio = 1;
    fwrite(&inv, sizeof(producto), 1, fp);

    inv.codigo_producto = 6470;
    strcpy(inv.nombre_producto, "Anvorguesa");
    inv.precio = 3140;
    fwrite(&inv, sizeof(producto), 1, fp);

    inv.codigo_producto = 6560;
    strcpy(inv.nombre_producto, "Dragon Lore");
    inv.precio = 1999;
    fwrite(&inv, sizeof(producto), 1, fp);

    inv.codigo_producto = 16;
    strcpy(inv.nombre_producto, "Ram Con RGB");
    inv.precio = 70000;
    fwrite(&inv, sizeof(producto), 1, fp);

    inv.codigo_producto = 2029;
    strcpy(inv.nombre_producto, "Caca con mayo");
    inv.precio = 6969;
    fwrite(&inv, sizeof(producto), 1, fp);

    inv.codigo_producto = 27;
    strcpy(inv.nombre_producto, "Black Ice Shield");
    inv.precio = 5436742;
    fwrite(&inv, sizeof(producto), 1, fp);

    inv.codigo_producto = 2021;
    strcpy(inv.nombre_producto, "Ficha del WoW en bolivares");
    inv.precio = 12700000;
    fwrite(&inv, sizeof(producto), 1, fp);
    */
    fclose(fp);
}

void crear_ofertas(){
    FILE *fp = fopen("ofertas.dat", "wb");

    oferta inv;
    int i = 10;
    fwrite(&i, sizeof(int), 1, fp);

    inv.codigo_producto = 29130542; //
    inv.cantidad_descuento= 2;
    inv.monto_descuento = 3520;
    fwrite(&inv, sizeof(oferta), 1, fp);

    inv.codigo_producto = 2895;//
    inv.cantidad_descuento = 3;
    inv.monto_descuento = 100;
    fwrite(&inv, sizeof(oferta), 1, fp);

    inv.codigo_producto = 78920;//
    inv.cantidad_descuento=2;
    inv.monto_descuento = 700000;
    fwrite(&inv, sizeof(oferta), 1, fp);

    inv.codigo_producto = 8792;//
    inv.cantidad_descuento=2;
    inv.monto_descuento = 3000;
    fwrite(&inv, sizeof(oferta), 1, fp);

    inv.codigo_producto = 6969;//
    inv.cantidad_descuento=2;
    inv.monto_descuento = 6969;
    fwrite(&inv, sizeof(oferta), 1, fp);

    inv.codigo_producto = 4200;//
    inv.cantidad_descuento=2;
    inv.monto_descuento = 2500;
    fwrite(&inv, sizeof(oferta), 1, fp);

    inv.codigo_producto = 134;//
    inv.cantidad_descuento = 2;
    inv.monto_descuento = 80000;
    fwrite(&inv, sizeof(oferta), 1, fp);

    inv.codigo_producto = 57410;//
    inv.cantidad_descuento=3;
    inv.monto_descuento = 50500;
    fwrite(&inv, sizeof(oferta), 1, fp);

    inv.codigo_producto = 911;//
    inv.cantidad_descuento=1;
    inv.monto_descuento = 1000;
    fwrite(&inv, sizeof(oferta), 1, fp);

    inv.codigo_producto = 879879;//
    inv.cantidad_descuento= 6969;
    inv.monto_descuento = 4000;
    fwrite(&inv, sizeof(oferta), 1, fp);
    /*
    inv.codigo_producto = 6470;
    inv.cantidad_descuento=9;
    inv.monto_descuento = 1500;
    fwrite(&inv, sizeof(oferta), 1, fp);

    inv.codigo_producto = 6560;
    inv.cantidad_descuento=2;
    inv.monto_descuento = 327;
    fwrite(&inv, sizeof(oferta), 1, fp);

    inv.codigo_producto = 16;
    inv.cantidad_descuento=1;
    inv.monto_descuento = 100;
    fwrite(&inv, sizeof(oferta), 1, fp);

    inv.codigo_producto=2029;
    inv.cantidad_descuento=5;
    inv.monto_descuento = 682;
    fwrite(&inv, sizeof(oferta), 1, fp);

    inv.codigo_producto = 27;
    inv.cantidad_descuento=28;
    inv.monto_descuento = 60000;
    fwrite(&inv, sizeof(oferta), 1, fp);
    */
    fclose(fp);
}

int main() {

    crear_productos();
    crear_ofertas();

    return 0;
}