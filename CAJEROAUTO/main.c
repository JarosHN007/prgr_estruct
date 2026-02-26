#include <stdio.h>

int main(void) {
    int saldo = 1000;
    int sumar;
    int restar;
    int opc;
    do {
        printf("\n---------------MENU---------------\n");
        printf("INGRESAR ACCION QUE DESEA REALIZAR\n");
        printf("1. Depositar\n");
        printf("2. Retirar\n");
        printf("3. Salir\n");
        scanf("%d",&opc);
        switch (opc) {
            case 1:
                printf("Ingrese cantidad a depositar:\n");
                scanf("%d",&sumar);
                saldo=saldo+sumar;
                printf("Se actualizo el saldo a L. %d \n",saldo);
            break;

            case 2:
                printf("Ingrese cantidad a retirar\n");
                scanf("%d",&restar);
                if (restar>saldo) {
                    printf("No tiene fondos para retirar\n");

                } else {
                    saldo=saldo-restar;
                    printf("Se logro retirar L. %d\nFondos disponibles L. %d\n",restar,saldo);
                }
            break;
        }
    } while (opc>0 && opc<3);

printf("Se salio del menu.\n");


    return 0;
}