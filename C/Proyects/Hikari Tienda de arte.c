#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTOS 100

typedef struct {
    char nombre[50];
    float precio;
    int cantidad;
} Producto;

Producto productos[MAX_PRODUCTOS];
int num_productos = 0;

void agregar_producto(char *nombre, float precio, int cantidad) {
    strcpy(productos[num_productos].nombre, nombre);
    productos[num_productos].precio = precio;
    productos[num_productos].cantidad = cantidad;
    num_productos++;
}

void mostrar_producto(int indice) {
    printf("Nombre: %s\n", productos[indice].nombre);
    printf("Precio: %.2f\n", productos[indice].precio);
    printf("Cantidad: %d\n", productos[indice].cantidad);
}

void mostrar_productos() {
    for (int i = 0; i < num_productos; i++) {
        printf("%d. ", i + 1);
        mostrar_producto(i);
        printf("\n");
    }
}

int buscar_producto(char *nombre) {
    for (int i = 0; i < num_productos; i++) {
        if (strcmp(productos[i].nombre, nombre) == 0) {
            return i;
        }
    }
    return -1;
}

void vender_producto(int indice, int cantidad) {
    if (indice < 0 || indice >= num_productos) {
        printf("Producto no encontrado\n");
        return;
    }
    if (productos[indice].cantidad < cantidad) {
        printf("No hay suficiente stock\n");
        return;
    }
    
    float total = productos[indice].precio * cantidad;
    printf("Total a pagar: %.2f\n", total);
    
    productos[indice].cantidad -= cantidad;
}

void agregar_stock(int indice, int cantidad) {
    if (indice < 0 || indice >= num_productos) {
        printf("Producto no encontrado\n");
        return;
    }
    productos[indice].cantidad += cantidad;
}

void eliminar_producto(char *nombre) {
    int indice = buscar_producto(nombre);
    if (indice == -1) {
        printf("Producto no encontrado\n");
        return;
    }
    for (int i = indice; i < num_productos - 1; i++) {
        productos[i] = productos[i + 1];
    }
    num_productos--;
    printf("Producto eliminado: %s\n", nombre);
}

void eliminar_stock(int indice, int cantidad) {
    if (indice < 0 || indice >= num_productos) {
        printf("Producto no encontrado\n");
        return;
    }
    
    if (productos[indice].cantidad < cantidad) {
        printf("No hay suficiente stock para eliminar\n");
        return;
    }
    
    productos[indice].cantidad -= cantidad;
    printf("Se eliminaron %d unidades de stock de %s\n", cantidad, productos[indice].nombre);
}

void menu() {
    printf("1. Agregar producto\n");
    printf("2. Mostrar productos\n");
    printf("3. Vender producto\n");
    printf("4. Agregar stock\n");
    printf("5. Eliminar producto\n");
    printf("6. Eliminar stock\n");
    printf("7. Salir\n");
}

int main() {
    // Precargar 5 productos
    agregar_producto("Pintura al oleo", 50.0, 10);
    agregar_producto("Lapices de colores", 10.0, 20);
    agregar_producto("Bloc de dibujo", 5.0, 30);
    agregar_producto("Pinceles", 15.0, 40);
    agregar_producto("Acuarelas", 20.0, 50);

    while (1) {
        menu();
        int opcion;
        printf("Elige una opcion: ");
        scanf("%d", &opcion);

        if (opcion == 1) {
            char nombre[50];
            float precio;
            int cantidad;

            printf("Nombre del producto: ");
            scanf("%s", nombre);
            printf("Precio del producto: ");
            scanf("%f", &precio);
            printf("Cantidad en stock: ");
            scanf("%d", &cantidad);

            agregar_producto(nombre, precio, cantidad);

        } else if (opcion == 2) {
            mostrar_productos();

        } else if (opcion == 3) {
            int indice;
            int cantidad;

            printf("Numero del producto: ");
            scanf("%d", &indice);
            printf("Cantidad a vender: ");
            scanf("%d", &cantidad);

            vender_producto(indice - 1, cantidad);

        } else if (opcion == 4) {
            int indice;
            int cantidad;

            printf("Numero del producto: ");
            scanf("%d", &indice);
            printf("Cantidad a agregar: ");
            scanf("%d", &cantidad);

            agregar_stock(indice - 1, cantidad);

        } else if (opcion == 5) {
            char nombre[50];

            printf("Nombre del producto a eliminar: ");
            scanf("%s", nombre);

            eliminar_producto(nombre);

        } else if (opcion == 6) {
            int numeroProducto;
            int cantidadEliminar;

            printf("Numero del producto para eliminar stock: ");
            scanf("%d", &numeroProducto);

            printf("Cantidad a eliminar del stock: ");
            scanf("%d", &cantidadEliminar);

            eliminar_stock(numeroProducto - 1, cantidadEliminar);

        } else if (opcion == 7) {
            break;
        }
    }
    
    return 0;
}
