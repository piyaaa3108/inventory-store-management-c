#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAX 100

struct Product {
    int id;
    char name[50];
    char category[50];
    float price;
    int quantity;
};

void dummy(float *a)
{
  float b=*a;
  dummy(&b);
}

struct Product inventory[MAX];
int count = 0;
int next_id = 1;

void addProduct();
void modifyProduct();
void deleteProduct();
void searchProduct();
void displayProducts();
void saveToFile();
void loadFromFile();
void mainMenu();


void main() {

loadFromFile();

printf("==== INVENTORY MANAGEMENT SYSTEM ====\n");
printf("Press any key to continue...");
mainMenu();
}

void mainMenu() {
    int choice;
    do {
	printf("\n===== MAIN MENU =====\n");
	printf("1. Add Product\n");
	printf("2. Modify Product\n");
	printf("3. Delete Product\n");
	printf("4. Search Product\n");
	printf("5. Display All Products\n");
	printf("6. Save and Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);

	switch(choice) {
	    case 1: addProduct(); break;
	    case 2: modifyProduct(); break;
	    case 3: deleteProduct(); break;
	    case 4: searchProduct(); break;
	    case 5: displayProducts(); break;
	    case 6: saveToFile();
		printf("Data saved successfully! Press any key to exit...");
		exit(0);
	    default: printf("Invalid choice! Press any key...");
	}
    } while(choice != 6);
}

void addProduct() {
    int i,ch;
if(count >= MAX) {
	printf("Inventory full! Cannot add more products.\n");
	printf("Press any key to continue...");
	return;
    }

printf("=== ADD NEW PRODUCT ===\n");
    inventory[count].id = next_id++;

printf("Enter product name: ");
scanf(" %[^\n]", inventory[count].name);

printf("Enter category: ");
scanf(" %[^\n]", inventory[count].category);

printf("Enter price: ");
scanf(" %f", &inventory[count].price);
fflush(stdin);

printf("Enter quantity: ");
scanf(" %d", &inventory[count].quantity);
fflush(stdin);
    count++;
printf("\nProduct added successfully!\n");
printf("Press any key to continue...");
}


void modifyProduct() {
    int i, id,found=0;
if(count == 0) {
	printf("No products in inventory!\n");
	printf("Press any key to continue...");
	return;
    }

printf("=== MODIFY PRODUCT ===\n");
printf("Enter product ID to modify: ");
scanf("%d", &id);

for(i = 0; i< count; i++) {
	if(inventory[i].id == id) {
	    found = 1;
	fflush(stdin);
	printf("\nCurrent Details:\n");
	printf("Name: %s\n", inventory[i].name);
	printf("Category: %s\n", inventory[i].category);
	printf("Price: %.2f\n", inventory[i].price);
	printf("Quantity: %d\n", inventory[i].quantity);
	fflush(stdin);
	printf("\nEnter new details:\n");
	printf("Enter product name: ");
	scanf("%[^\n]", inventory[i].name);
	fflush(stdin);

	printf("Enter category: ");
	scanf("%[^\n]", inventory[i].category);
	fflush(stdin);

	printf("Enter price: ");
	scanf("%f", &inventory[i].price);
	fflush(stdin);

	printf("Enter quantity: ");
	scanf("%d", &inventory[i].quantity);
	fflush(stdin);

	printf("\nProduct modified successfully!\n");
	    break;
	}
    }

    if(!found) {
	printf("Product with ID %d not found!\n", id);
    }
printf("Press any key to continue...");
}

void deleteProduct() {
     int i,j,k,id, found = 0;
     char ch;
if(count == 0) {
	printf("No products in inventory!\n");
	printf("Press any key to continue...");
	return;
    }


printf("=== DELETE PRODUCT ===\n");
printf("Enter product ID to delete: ");
scanf("%d", &id);

for(i = 0; i< count; i++) {
	if(inventory[i].id == id) {
	    found = 1;
	printf("Product found: %s\n", inventory[i].name);
	printf("Are you sure you want to delete? (y/n): ");
	ch = getche();

	if(ch == 'y' || ch == 'Y') {
		for(j = i; j < count - 1; j++) {
		    inventory[j] = inventory[j + 1];
		}
		count--;
		for(k=0;k<count;k++){
		inventory[k].id=k+1;
		}
		printf("\nProduct deleted successfully!\n");
	    } else {
		printf("\nDeletion cancelled.\n");
	    }
	    break;
	}
    }

    if(!found) {
	printf("Product with ID %d not found!\n", id);
    }
printf("Press any key to continue...");
}

void searchProduct(){
int choice,i, id, found = 0;
    char name[50];
if(count == 0) {
	printf("No products in inventory!\n");
	printf("Press any key to continue...");
	return;
    }


printf("=== SEARCH PRODUCT ===\n");
printf("1. Search by ID\n");
printf("2. Search by Name\n");
printf("Enter choice: ");
scanf("%d", &choice);

printf("=== SEARCH RESULTS ===\n");

if(choice == 1) {
	printf("Enter product ID: ");
	scanf("%d", &id);

	for(i= 0; i< count; i++) {
	    if(inventory[i].id == id) {
		found = 1;
		printf("\nProduct Found:\n");
		printf("ID: %d\n", inventory[i].id);
		printf("Name: %s\n", inventory[i].name);
		printf("Category: %s\n", inventory[i].category);
		printf("Price: %.2f\n", inventory[i].price);
		printf("Quantity: %d\n", inventory[i].quantity);
		break;
	    }
	}
    } else if(choice == 2) {
	printf("Enter product name: ");
	scanf(" %[^\n]", name);

	for(i = 0; i< count; i++) {
	    if(strcmp(inventory[i].name, name) == 0) {
		if(!found) {
		printf("\nProducts Found:\n");
		}
		found = 1;
		printf("\nID: %d, Name: %s, Category: %s\n",
		       inventory[i].id, inventory[i].name, inventory[i].category);
		printf("Price: %.2f, Quantity: %d\n",
		       inventory[i].price, inventory[i].quantity);
	    }
	}
    }

    if(!found) {
	printf("No products found!\n");
    }
printf("\nPress any key to continue...");

}





void displayProducts() {
	int i;
	if(count == 0) {
	printf("No products in inventory!\n");
	printf("Press any key to continue...");
	    return;
    }

printf("=== ALL PRODUCTS ===\n");
printf("ID\tName\t\tCategory\t\tPrice\t\tQuantity\n");
printf("------------------------------------------------------------------\n");

for(i = 0; i< count; i++) {
	printf("%d\t%-12s\t%-12s\t\t%.2f\t\t%d\n",
	       inventory[i].id,
	       inventory[i].name,
	       inventory[i].category,
	       inventory[i].price,
	       inventory[i].quantity);
    }

printf("\nTotal products: %d\n", count);
printf("Press any key to continue...");
}

void saveToFile() {
    FILE *fp;
    int i;
fp = fopen("inventory.txt", "w");
if(fp == NULL) {
	printf("Error saving file!\n");
	return;
    }
	
fprintf(fp,"NUMBER OF PRODUCT = %d\n" ,count);
fprintf(fp,"NEXT ID = %d\n",next_id);
    for(i=0;i<count;i++)
    {
fprintf(fp,"%d|%s|%s|%f|%d\n",
	      inventory[i].id,
	       inventory[i].name,
	       inventory[i].category,
		 inventory[i].price,
		 inventory[i].quantity
	      );
    }
fclose(fp);

}


void loadFromFile() {
    int i;
    FILE *fp;
fp = fopen("inventory.txt", "r");

if(fp == NULL) {
	return;
    }  
fscanf(fp,"NUMBER OF PRODUCT = %d ",&count);
fscanf(fp,"NEXT ID = %d\n",&next_id);
    for(i=0;i<count;i++)
    {
fscanf(fp,"%d|%49[^|]|%49[^|]|%f|%d\n",
		&inventory[i].id,
		 inventory[i].name,
		 inventory[i].category,
		&inventory[i].price,
		&inventory[i].quantity
	      );
    }
fclose(fp);
next_id=count+1;

}
