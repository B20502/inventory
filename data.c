//An inventory system that enters items, prices and the total value.

#include <stdio.h>
#include <string.h>


#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50



typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Item;

Item inventory[MAX_ITEMS];
int numItems = 0;

void addItem(Item item) {
    inventory[numItems] = item;
    numItems++;
}

void displayInventory() {
    printf("Inventory:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s (%d) - $%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price * inventory[i].quantity);
    }
}

void updateItem(char* name, int newQuantity) {
    for (int i = 0; i < numItems; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            inventory[i].quantity = newQuantity;
            return;
        }
    }
    printf("Item not found.\n");
}

float calculateTotalValue() {
    float total = 0.0;
    for (int i = 0; i < numItems; i++) {
        total += inventory[i].price * inventory[i].quantity;
    }
    return total;
}

int main() {
    int choice;
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
    char updateName[MAX_NAME_LENGTH];
    int newQuantity;

    while (1) {
        printf("Inventory Management System\n");
        printf("1. Add item\n");
        printf("2. Display inventory\n");
        printf("3. Update item\n");
        printf("4. Calculate total value\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Item name: ");
                scanf("%s", name);
                printf("Quantity: ");
                scanf("%d", &quantity);
                printf("Price per unit: ");
                scanf("%f", &price);
                Item item= {"name", quantity, price};
                addItem (item);
                printf("Item added successfully!\n");
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                printf("Item name to update: ");
                scanf("%s", updateName);
                printf("New quantity: ");
                scanf("%d", &newQuantity);
                updateItem(updateName, newQuantity);
                printf("Item updated successfully!\n");
                break;
            case 4:
                printf("Total inventory value: $%.2f\n", calculateTotalValue());
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}


