#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int nroCuenta;
    int saldo;
    char nbre[51];
    char direccion[51];
} clienteBanco;

void actualizarSaldos (char* clientes, char* transacciones);

int main(int argc, char** argv) {
    if (argc == 0) {
        printf("No se ingresaron suficientes nombres de archivo.");
        exit(1);
    }
    actualizarSaldos(argv[1], argv[2]);

    return 0;
}

void actualizarSaldos (char* clientes, char* transacciones) {
    FILE* archivo_clientes, *archivo_transacciones;
    if (archivo_clientes = fopen(clientes, "r+")) {
        printf("Hubo un error al abrir el archivo %s.", clientes);
        exit(1);
    }
    if (archivo_transacciones = fopen(clientes, "r")){
        printf("Hubo un error al abrir el archivo %s.", transacciones);
        exit(1);
    }

    clienteBanco cuenta;

    int contador = 0;
    char temp;
    while (fread(&cuenta, sizeof(clienteBanco), 1, archivo_clientes) != 0) {

        char tipo_transaccion = getc(archivo_transacciones);
        int cuenta_1, cuenta_2, cantidad_dinero, bandera = 1, dinero_temporal = cuenta.saldo;

        while (bandera) {
            if (tipo_transaccion == '+') {
                fscanf(archivo_transacciones, " %d %d", &cuenta_1, &cantidad_dinero);
                if (cuenta_1 == cuenta.nroCuenta) {
                    cuenta.saldo += cantidad_dinero;
                }
            }
            else if (tipo_transaccion == '-') {
                fscanf(archivo_transacciones, " %d %d", &cuenta_1, &cantidad_dinero);
                if (cuenta_1 == cuenta.nroCuenta) {
                    cuenta.saldo -= cantidad_dinero;
                }
            }
            else if (tipo_transaccion == '>') {
                fscanf(archivo_transacciones, " %d %d %d", &cuenta_1, &cuenta_2, &cantidad_dinero);
                if (cuenta_1 == cuenta.nroCuenta) {
                    cuenta.saldo -= cantidad_dinero;
                } 
                else if (cuenta_2 == cuenta.nroCuenta) {
                    cuenta.saldo += cantidad_dinero;
                }
            }

            while ((tipo_transaccion = getc(archivo_transacciones)) != '\n' && tipo_transaccion != EOF)
                ;
            if (tipo_transaccion == EOF)
            {
                bandera = 0;
            }
            else
            {
                tipo_transaccion = getc(archivo_transacciones);
            }
        }

        fseek(archivo_clientes, contador, SEEK_SET);
        fwrite(&cuenta, sizeof(clienteBanco), 1, archivo_clientes);

        contador += sizeof(clienteBanco);
    }

    fclose(archivo_clientes);
    fclose(archivo_transacciones);
}