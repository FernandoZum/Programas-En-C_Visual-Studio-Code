#include <stdio.h>

#define MAX_PRODUCTOS 100
#define MAX_NOMBRE 50
#define MAX_DESCRIPCION 100

int cantProductos = 0;
int id[100];
char nombre[100][50];
char descripcion[100][100];
int cantidad[100];
float precio[100];

void verProductos();
void ingresarProducto();
void modificarProducto();
void eliminarProducto();
int main() {
    int numopcion;
    do {
        printf("\nBienvenido a la Bodega\n");
        printf("Menu de Productos\n");
        printf("1. Ver productos\n");
        printf("2. Ingreso de productos\n");
        printf("3. Modificacion de productos\n");
        printf("4. Eliminar producto\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &numopcion);
        switch (numopcion) {
            case 1:
                verProductos();
                break;
            case 2:
                ingresarProducto();
                break;
            case 3:
                modificarProducto();
                break;
            case 4:
                eliminarProducto();
                break;
            case 5:
                printf("Gracias por utilizar nuestro programa\n");
                break;
            default:
                printf("Opción no encontrada. Debe seleccionar el numero que se encuentra en el menu\n");
                break;
        }
    } while (numopcion != 5);
    return 0;
}
void verProductos() {
    printf("\n***Ver Productos***\n");
    if (cantProductos == 0) {
        printf("No existe producto\n");
        return;
    }
    printf("ID      Nombre      Descripción      Cantidad      Precio\n");
    for (int i = 0; i < cantProductos; i++) {
        printf("%d      %s      %s      %d      %.2f\n", id[i], nombre[i], descripcion[i], cantidad[i], precio[i]);
    }
}
void ingresarProducto() {
    printf("\n***Ingreso de Productos***\n");
    if (cantProductos == MAX_PRODUCTOS) {
        printf("Limite maximo de productos.\n");
        return;
    }
    printf("Ingrese el ID del producto: ");
    scanf("%d", &id[cantProductos]);
    printf("Ingrese el nombre del producto: ");
    scanf(" %[^\n]", nombre[cantProductos]);
    printf("Ingrese la descripcion del producto: ");
    scanf(" %[^\n]", descripcion[cantProductos]);
    printf("Ingrese la cantidad del producto: ");
    scanf("%d", &cantidad[cantProductos]);
    printf("Ingrese el precio del producto: ");
    scanf("%f", &precio[cantProductos]);
    cantProductos++;
    printf("El producto se ha ingresado.\n");
}
void modificarProducto() {
    printf("\n***Modificar un Producto***\n");
    if (cantProductos == 0) {
        printf("No existe producto\n");
        return;
    }
    int idProducto;
    int indice = -1;
    printf("Ingrese el ID del producto a modificar: ");
    scanf("%d", &idProducto);
    for (int i = 0; i < cantProductos; i++) {
        if (id[i] == idProducto) {
            indice = i;
            break;
        }
    }
    if (indice == -1) {
        printf("El producto que busca no existe\n");
        return;
    }
    printf("Ingrese el nuevo nombre del producto: ");
    scanf(" %[^\n]", nombre[indice]);
    printf("Ingrese la nueva descripción del producto: ");
    scanf(" %[^\n]", descripcion[indice]);
    printf("Ingrese la nueva cantidad del producto: ");
    scanf("%d", &cantidad[indice]);
    printf("Ingrese el nuevo precio del producto: ");
    scanf("%f", &precio[indice]);
    printf("El producto se ha modificado...\n");
}
void eliminarProducto() {
    printf("\n***Eliminar Producto***\n");
    if (cantProductos == 0) {
        printf("No existe producto\n");
        return;
    }
    int idProducto;
    int indice = -1;
    printf("Ingrese el ID del producto a eliminar: ");
    scanf("%d", &idProducto);

    for (int i = 0; i < cantProductos; i++) {
        if (id[i] == idProducto) {
            indice = i;
            break;
        }
    }
    if (indice == -1) {
        printf("No existe producto\n");
        return;
    }
    for (int i = indice; i < cantProductos - 1; i++) {
        id[i] = id[i + 1];
        cantidad[i] = cantidad[i + 1];
        precio[i] = precio[i + 1];
    }
    id[cantProductos - 1] = 0;
    cantidad[cantProductos - 1] = 0;
    precio[cantProductos - 1] = 0.0;
    cantProductos--;
    printf("El producto se ha eliminado...\n");
}
