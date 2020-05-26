#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int nroCuenta;
    int saldo;
    char nbre[51];
    char direccion[51];
} clienteBanco;

void escribirxd(clienteBanco* cuentas) {
    FILE *fp = fopen("clientes.dat", "w");

    fwrite(cuentas, sizeof(clienteBanco), 6, fp);

    fclose(fp);
}

void imprimirxd() {
    FILE *fp = fopen("clientes.dat", "r");
    clienteBanco temp;

    while (fread(&temp, sizeof(clienteBanco), 1, fp) != 0) {
        printf("nroCuenta: %d\nsaldo: %d\nnbre: %s\ndireccion: %s\n\n", temp.nroCuenta, temp.saldo, temp.nbre, temp.direccion);
    }

    fclose(fp);
}

int main() {
    clienteBanco cuentas[6];

    cuentas[0].nroCuenta = 1;
    cuentas[0].saldo = 2000;
    strcpy(cuentas[0].nbre, "dieguito maradona");
    strcpy(cuentas[0].direccion, "pythoniaxd");

    cuentas[1].nroCuenta = 2;
    cuentas[1].saldo = 500;
    strcpy(cuentas[1].nbre, "deuman");
    strcpy(cuentas[1].direccion, "grafos");

    cuentas[2].nroCuenta = 2019;
    cuentas[2].saldo = 800000;
    strcpy(cuentas[2].nbre, "anone");
    strcpy(cuentas[2].direccion, "anone casa");

    cuentas[3].nroCuenta = 2020;
    cuentas[3].saldo = 758000;
    strcpy(cuentas[3].nbre, "crepayuelo");
    strcpy(cuentas[3].direccion, "villa arepa");

    cuentas[4].nroCuenta = 2021;
    cuentas[4].saldo = 980000;
    strcpy(cuentas[4].nbre, "funaisimo");
    strcpy(cuentas[4].direccion, "coquimbo");

    cuentas[5].nroCuenta = 10000000;
    cuentas[5].saldo = 9000000;
    strcpy(cuentas[5].nbre, "covid");
    strcpy(cuentas[5].direccion, "murcielagosxd");

    //escribirxd(cuentas);
    imprimirxd();

    return 0;
}