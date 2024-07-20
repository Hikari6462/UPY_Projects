#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[50];
    float price;
    int quantity;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product(char *name, float price, int quantity) {
    strcpy(products[num_products].name, name);
    products[num_products].price = price;
    products[num_products].quantity = quantity;
    num_products++;
}

void show_product(int index) {
    printf("Name: %s\n", products[index].name);
    printf("Price: %.2f\n", products[index].price);
    printf("Quantity: %d\n", products[index].quantity);
}

void show_products() {
    for (int i = 0; i < num_products; i++) {
        printf("%d. ", i + 1);
        show_product(i);
        printf("\n");
    }
}

int find_product(char *name) {
    for (int i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void sell_product(int index, int quantity) {
    if (index < 0 || index >= num_products) {
        printf("Product not found\n");
        return;
    }
    if (products[index].quantity < quantity) {
        printf("Insufficient stock\n");
        return;
    }
    
    float total = products[index].price * quantity;
    printf("Total to pay: %.2f\n", total);
    
    products[index].quantity -= quantity;
}

void add_stock(int index, int quantity) {
    if (index < 0 || index >= num_products) {
        printf("Product not found\n");
        return;
    }
    products[index].quantity += quantity;
}

void delete_product(char *name) {
    int index = find_product(name);
    if (index == -1) {
        printf("Product not found\n");
        return;
    }
    for (int i = index; i < num_products - 1; i++) {
        products[i] = products[i + 1];
    }
    num_products--;
    printf("Product deleted: %s\n", name);
}

void delete_stock(int index, int quantity) {
    if (index < 0 || index >= num_products) {
        printf("Product not found\n");
        return;
    }
    
    if (products[index].quantity < quantity) {
        printf("Not enough stock to delete\n");
        return;
    }
    
    products[index].quantity -= quantity;
    printf("%d units of %s stock deleted\n", quantity, products[index].name);
}

void menu() {
    printf("1. Add product\n");
    printf("2. Show products\n");
    printf("3. Sell product\n");
    printf("4. Add stock\n");
    printf("5. Delete product\n");
    printf("6. Delete stock\n");
    printf("7. Exit\n");
}

int main() {
    // Preload 5 products
    add_product("Oil paint", 50.0, 10);
    add_product("Colored pencils", 10.0, 20);
    add_product("Drawing pad", 5.0, 30);
    add_product("Paint brushes", 15.0, 40);
    add_product("Watercolors", 20.0, 50);

    while (1) {
        menu();
        int option;
        printf("Choose an option: ");
        scanf("%d", &option);

        if (option == 1) {
            char name[50];
            float price;
            int quantity;

            printf("Product name: ");
            scanf("%s", name);
            printf("Product price: ");
            scanf("%f", &price);
            printf("Quantity in stock: ");
            scanf("%d", &quantity);

            add_product(name, price, quantity);

        } else if (option == 2) {
            show_products();

        } else if (option == 3) {
            int index;
            int quantity;

            printf("Product number: ");
            scanf("%d", &index);
            printf("Quantity to sell: ");
            scanf("%d", &quantity);

            sell_product(index - 1, quantity);

        } else if (option == 4) {
            int index;
            int quantity;

            printf("Product number: ");
            scanf("%d", &index);
            printf("Quantity to add: ");
            scanf("%d", &quantity);

            add_stock(index - 1, quantity);

        } else if (option == 5) {
            char name[50];

            printf("Name of product to delete: ");
            scanf("%s", name);

            delete_product(name);

        } else if (option == 6) {
            int productNumber;
            int quantityDelete;

            printf("Product number to delete stock from: ");
            scanf("%d", &productNumber);

            printf("Quantity to delete from stock: ");
            scanf("%d", &quantityDelete);

            delete_stock(productNumber - 1, quantityDelete);

        } else if (option == 7) {
            break;
        }
    }
    
    return 0;
}
