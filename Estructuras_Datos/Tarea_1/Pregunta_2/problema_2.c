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
    if (argc != 3) {
        printf("No se ingresaron suficientes nombres de archivo.\n");
        exit(1);
    }
    actualizarSaldos(argv[1], argv[2]);

    return 0;
}


void actualizarSaldos (char* clientes, char* transacciones) {
    FILE* archivo_clientes, *archivo_transacciones;
    if ((archivo_clientes = fopen(clientes, "r+"))) {
        printf("Hubo un error al abrir el archivo %s.", clientes);
        exit(1);
    }
    if ((archivo_transacciones = fopen(transacciones, "r"))) {
        printf("Hubo un error al abrir el archivo %s.", transacciones);
        exit(1);
    }

    clienteBanco cuenta;

    int contador = 0;
    int cuenta_1, cuenta_2, cantidad_dinero, bandera = 1;

    while (fread(&cuenta, sizeof(clienteBanco), 1, archivo_clientes) != 0) {

        tipo_transaccion = getc(archivo_transacciones);
        bandera = 1;

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

/*****
* void actualizarSaldos
******
* El papel de esta función es ir tomando cliente a cliente su número de cuenta para luego recorrer el archivo
* transacciones y buscar todas las operaciones bancarias en las que esté presente esta misma. Cada vez que la
* función encuentra una operación bancaria relacionada a la cuenta, cambia el valor de un saldo temporal, para
* luego obtener el saldo final y este actualizarlo en el archivo clientes.
******
* Input:
* char* clientes     : Corresponde a un archivo binario, el cual procederemos a actualizar.
* char* transacciones: Corresponde a un archivo ASCII, que iremos recorriendo para encontrar operaciones bancarias.
* ....... 
******
* Returns:
* void, esta función no retorna nada en sí, si no que actualiza el archivo binario
* clientes, que va a contener todos los saldos post transacciones.
*****/
