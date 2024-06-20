#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "products.dat"

typedef struct {
  char name[50];
  char department[50];
  float price;
} Product;

void createFile() {
  FILE *file = fopen(FILENAME, "wb");
  if (file == NULL) {
    printf("Error opening file for writing.\n");
    return;
  }
  fclose(file);
  printf("File created successfully.\n");
}

void openFile() {
  FILE *file = fopen(FILENAME, "rb");
  if (file == NULL) {
    printf("File does not exist.\n");
    return;
  }
  printf("File opened successfully.\n");
  fclose(file);
}

void viewFile() {
  FILE *file = fopen(FILENAME, "rb");
  if (file == NULL) {
    printf("Error opening file for reading.\n");
    return;
  }

  Product product;
  while (fread(&product, sizeof(Product), 1, file)) 
    printf("Name: %s, Department: %s, Price: %.2f\n", product.name,
           product.department, product.price);
  
  fclose(file);
}

void addRecord() {
  FILE *file = fopen(FILENAME, "ab");
  if (file == NULL) {
    printf("Error opening file for appending.\n");
    return;
  }

  Product product;
  printf("Enter product name: ");
  scanf("%s", product.name);
  printf("Enter department: ");
  scanf("%s", product.department);
  printf("Enter price: ");
  scanf("%f", &product.price);

  fwrite(&product, sizeof(Product), 1, file);
  fclose(file);
  printf("Record added successfully.\n");
}

void findMostExpensive() {
  FILE *file = fopen(FILENAME, "rb");
  if (file == NULL) {
    printf("Error opening file for reading.\n");
    return;
  }

  Product product;
  Product maxProducts[100];
  int count = 0;

  while (fread(&product, sizeof(Product), 1, file)) {
    int found = 0;
    for (int i = 0; i < count; i++) {
      if (strcmp(maxProducts[i].department, product.department) == 0) {
        if (product.price > maxProducts[i].price) 
          maxProducts[i] = product;
        found = 1;
        break;
      }
    }
    if (!found) 
      maxProducts[count++] = product;
  }

  printf("Most expensive products in each department:\n");
  for (int i = 0; i < count; i++) 
    printf("Department: %s, Name: %s, Price: %.2f\n", maxProducts[i].department,
           maxProducts[i].name, maxProducts[i].price);
  fclose(file);
}

int main() {
  int choice;

  do {
    printf("\nMenu:\n");
    printf("1. Create file\n");
    printf("2. Open file\n");
    printf("3. View file contents\n");
    printf("4. Add record\n");
    printf("5. Find most expensive products\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      createFile();
      break;
    case 2:
      openFile();
      break;
    case 3:
      viewFile();
      break;
    case 4:
      addRecord();
      break;
    case 5:
      findMostExpensive();
      break;
    case 6:
      printf("Exiting program.\n");
      break;
    default:
      printf("Invalid choice. Please try again.\n");
    }
  } while (choice != 6);

  return 0;
}