#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char title[100];
    char author[50];
    int year;
} Book;

void addBook(FILE *file) {
    Book book;
    printf("Enter Book ID: ");
    scanf("%d", &book.id);
    printf("Enter Book Title: ");
    scanf(" %[^\n]", book.title);
    printf("Enter Book Author: ");
    scanf("%s", book.author);
    printf("Enter Year of Publication: ");
    scanf("%d", &book.year);
    fwrite(&book, sizeof(Book), 1, file);
    printf("Book added successfully.\n");
}

void viewBooks(FILE *file) {
    Book book;
    rewind(file);
    while (fread(&book, sizeof(Book), 1, file)) {
        printf("ID: %d, Title: %s, Author: %s, Year: %d\n", book.id, book.title, book.author, book.year);
    }
}

void deleteBook(FILE *file) {
    FILE *temp = fopen("temp.dat", "wb");
    Book book;
    int id;
    printf("Enter Book ID to delete: ");
    scanf("%d", &id);
    rewind(file);
    while (fread(&book, sizeof(Book), 1, file)) {
        if (book.id != id) {
            fwrite(&book, sizeof(Book), 1, temp);
        }
    }
    fclose(file);
    fclose(temp);
    remove("library.dat");
    rename("temp.dat", "library.dat");
    file = fopen("library.dat", "rb+");
    printf("Book deleted successfully.\n");
}

int main() {
    FILE *file = fopen("library.dat", "rb+");
    if (!file) {
        file = fopen("library.dat", "wb+");
    }
    int choice;
    while (1) {
        printf("\nLibrary Management System:\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Delete Book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addBook(file); break;
            case 2: viewBooks(file); break;
            case 3: deleteBook(file); break;
            case 4: fclose(file); return 0;
            default: printf("Invalid choice, please try again.\n");
        }
    }
}
