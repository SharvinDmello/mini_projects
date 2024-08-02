#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct info{
    char name[30];
    int work_id;
    int age;
    int pincode;
    char housename[30];
};

void add_data(FILE *file){
    struct info data;
    printf("Enter the name: ");
    scanf("%s", &data.name);
    printf("Enter the working id number: ");
    scanf("%d", &data.work_id);
    printf("Enter the age: ");
    scanf("%d", &data.age);
    printf("Enter the postal pincode: ");
    scanf("%d", &data.pincode);
    printf("Enter the house name: ");
    scanf("%s", &data.housename);
    fwrite(&data, sizeof(struct info), 1, file);
    printf("Data added to the file successfully.\n");
}

void view_data(FILE *file){
    struct info data;
    rewind(file);
    while(fread(&data, sizeof(struct info), 1, file)){
        printf("NAME: %s\nID: %d\nAGE: %d\nPINCODE: %d\nHOUSE NAME: %d", data.name, data.work_id, data.age, data.pincode, data.housename);
    }
}

void update_data(FILE *file){
    struct info data;
    int id;
    printf("Enter the id to update: ");
    scanf("%d", &id);
    rewind(file);
    while(fread(&data, sizeof(struct info), 1, file)){
        if(data.work_id == id){
            fseek(file, -sizeof(struct info), SEEK_CUR);
            printf("Enter the neww name: ");
            scanf("%s", &data.name);
            printf("Enter the new age: ");
            scanf("%d", &data.age);
            printf("Enter the new pincode: ");
            scanf("%d", &data.pincode);
            printf("Enter the new house name: ");
            scanf("%s", &data.housename);
            fwrite(&data, sizeof(struct info), 1, file);
            printf("data updation was successful.\n");
            return;
        }
    }
    printf("Data not found.\n");
}

void delete_data(FILE *file) {
    FILE *temp = fopen("temp.xls", "wb");
    struct info data;
    int id;
    printf("Enter ID of the person to delete his/her information: ");
    scanf("%d", &id);
    rewind(file);
    while (fread(&data, sizeof(struct info), 1, file)) {
        if (data.work_id != id) {
            fwrite(&data, sizeof(struct info), 1, temp);
        }
    }
    fclose(file);
    fclose(temp);
    remove("database.xls");
    rename("temp.xls", "database.xls");
    file = fopen("database.xls", "rb+");
    printf("information daletion was successful.\n");
}

int main() {
    FILE *file = fopen("database.xls", "rb+");
    if (!file) {
        file = fopen("database.xls", "wb+");
    }
    int choice;
    while (1) {
        printf("\nSimple Database Management System:\n");
        printf("1. Add information\n");
        printf("2. View information\n");
        printf("3. Update information\n");
        printf("4. Delete information\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: add_data(file); break;
            case 2: view_data(file); break;
            case 3: update_data(file); break;
            case 4: delete_data(file); break;
            case 5: fclose(file); return 0;
            default: printf("Invalid choice, please try again.\n");
        }
    }
}