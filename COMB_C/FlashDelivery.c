#include <stdio.h>
//FUNCIONES

//ENVIO
float calcularEnvio(float km) {
    km=km*1.20;
    return km;
}

//DESCUENTO
float   aplicarDescuento(float subtotal, char cupon) {
    switch (cupon) {
        case 's':
            subtotal= subtotal-(subtotal*0.10);
            break;
        case'g':
            subtotal=subtotal-(subtotal*0.20);
            break;
        case 'n':
            subtotal;
            break;
    }
    return subtotal;
}

//MOSTRAR PEDIDO
void mostrarticket(float comida,float envio,float total) {
    printf("---------- TICKET ----------\n");
    printf("Comida: L. %.2f\n", comida);
    printf("Envio:  L. %.2f\n", envio);
    printf("Total:  L. %.2f\n", total);
}

int main(void) {
    float comida, envio, total, subtotal, km, ventatotal=0;
    int opc;
    char cupon;
    do {
        printf("\n-----------MENU-----------\n");
        printf("Ingrese la opcion deseada\n");
        printf("1.Registrar Pedido\n");
        printf("2.Ver reporte de ventas\n");
        printf("3.Salir\n");
        scanf("%d",&opc);
        switch (opc) {
            case 1:
                printf("Ingrese el precio de la comida: L. \n");
                scanf("%f", &comida);

                printf("Ingrese la distancia del pedido (km): \n");
                scanf("%f", &km);

                envio = calcularEnvio(km);
                subtotal = envio + comida;

                printf("Cuenta con descuento Silver (s) o Golden (g)? (n para ninguno):\n");
                scanf(" %c", &cupon);

                total = aplicarDescuento(subtotal, cupon);
                mostrarticket(comida, envio, total);

                ventatotal = ventatotal + total;

                break;
            case 2:
                printf("Se ha vendido un total de L. %.2f \n",ventatotal);
                break;
        }
    } while (opc>0 && opc<3);
    return 0;
}