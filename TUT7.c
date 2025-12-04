#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 #define FILENAME "employees.txt"
#define M 50

void addEmployees() {
    FILE *fp = fopen( FILENAME, "a"); 

    char name[M];
    double salary;
    char choice;

    do {
        printf("Enter employee name: ");
        scanf("%s", name);
        printf("Enter salary: ");
        scanf("%lf", &salary);

        fprintf(fp, "%s %.2f\n", name, salary);

        printf("Add another employee? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    fclose(fp);
}


void searchSalary() {
    FILE *fp = fopen( FILENAME, "r");
    
    char name[M], searchName[M];
    double salary;
    int found = 0;

    printf("Enter employee name to search: ");
    scanf("%s", searchName);

    while (fscanf(fp, "%s %lf", name, &salary) != EOF) {
        if (strcmp(name, searchName) == 0) {
            printf("Salary of %s: %.2f\n", name, salary);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee %s not found.\n", searchName);
    }

    fclose(fp);
}

void main() {
    int n;

    
        printf("\n======== Employee Database info =======\n\n");
        printf("1. Add Employees\n\n");
        printf("2. Search Salary by Name\n\n");
        printf("3. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &n);

if (n== 1) {
            addEmployees();
        }
        else if (n == 2) {
            searchSalary();
        }
        else if (n== 3) {
            printf("Exiting program.\n");
        }
        else {
            printf("Invalid choice. Try again.\n");
        }
    

    
}

