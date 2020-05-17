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
    FILE* archivo_clientes, archivo_transacciones;
    if (archivo_clientes = fopen(clientes, "r+")) {
        printf("Hubo un error al abrir el archivo %s.", clientes);
        exit(1);
    }
    if (archivo_transacciones = fopen(clientes, "r")){
        printf("Hubo un error al abrir el archivo %s.", transacciones);
        exit(1);
    }
    


    
}