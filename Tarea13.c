#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Brandon Altamirano

#define MAX_PRODUCTS 100

int numProductos = 0;

char nombresPropietarios[MAX_PRODUCTS][50];
char telefonosPropietarios[MAX_PRODUCTS][20];
char correosPropietarios[MAX_PRODUCTS][50];
char direccionesPropietarios[MAX_PRODUCTS][50];
char IDsProductos[MAX_PRODUCTS][11];
char nombresProductos[MAX_PRODUCTS][50];
char cantidadesProductos[MAX_PRODUCTS][20];

void agregarProducto();
void verProductos();
void generarID(char *id);

int main(int argc, char *argv[]) {
    int eleccion;
    srand(time(NULL));

    while (1) {
        printf("****Almacenes de todo****\n");
        printf("Menu de opciones:\n");
        printf("1. Agregar Producto\n");
        printf("2. Ver productos\n");
        printf("3. Salir\n");
        printf("Ingresar opción: ");
        scanf("%d", &eleccion);

        switch (eleccion) {
            case 1:
                printf("ESCRIBIR LA INFORMACIÓN SIN DEJAR ESPACIOS O UTILIZAR LOS SIGUIENTES SIGNOS ( : , ; , . , - , _ )\n");
                agregarProducto();
                break;
            case 2:
                verProductos();
                break;
            case 3:
                printf("****Gracias por usar la bodega***");
                exit(0);
        }
    }
}

void generarID(char *id) {
    id[0] = 'A' + rand() % 26;
    id[1] = 'A' + rand() % 26;
    for (int i = 2; i < 10; i++) {
        id[i] = '0' + rand() % 10;
    }
    id[10] = '\0';
}

void agregarProducto() {
    if (numProductos == MAX_PRODUCTS) {
        printf("No se pueden agregar más productos.\n");
        return;
    }

    printf("\n");
    printf("Ingrese el producto %d: ", numProductos + 1);
    scanf("%s", nombresPropietarios[numProductos]);
    printf("Ingrese el codigo del Producto %d: ", numProductos + 1);
    scanf("%s", correosPropietarios[numProductos]);
    printf("Ingrese la cantidad o unidades del producto %d: ", numProductos + 1);
    scanf("%s", cantidadesProductos[numProductos]);

    generarID(IDsProductos[numProductos]);

    numProductos++;
    printf("\n");
    printf("*******Producto agregado exitosamente*******\n\n");
}

void verProductos() {
    int i;
    if (numProductos == 0) {
        printf("No hay productos para mostrar.\n");
        return;
    }

    for (i = 0; i < numProductos; i++) {
        printf("\n");
        printf("*****Datos del Propietario y su producto:*****\n\n");
        printf("Nombre del producto: %s\n", nombresPropietarios[i]);
       
        printf("Codigo del producto: %s\n", correosPropietarios[i]);
        printf("Cantidad guardada: %s\n", cantidadesProductos[i]);
    }
}
