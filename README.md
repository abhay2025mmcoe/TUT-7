# TUT-7
                                                 TUTORIAL 7
—-----------------------------------------------------------------------
Name:- Abhay Dubey
Roll No :- 1131
PRN :- BE25CE1131
Batch :- C
ACTIVITY 7

Create a C program to perform various file operations, including reading
from a file, writing to a file, and displaying the contents of a file. The
program should provide options for the user to select the desired operation
from a menu. Upon selecting an operation, the program should execute the
corresponding functionality using appropriate file handling techniques.
Additionally, the program should handle errors such as file not found or
permission issues gracefully and provide informative messages to the user.


1. Purpose
The program demonstrates how to build a simple employee database system using file handling in C. It allows users to:
Add employee records (name and salary).
Search for an employee’s salary by name.
Exit the program.
2. Core Concepts Involved
🔹 File Handling
Files are used to store employee data permanently.
Two modes are used:
Append mode ("a") → Adds new records without deleting existing ones.
Read mode ("r") → Reads existing records for searching.
🔹 Strings and Input
Employee names are stored as character arrays (char name[M]).
scanf is used for input, but it only reads single-word names (no spaces).
🔹 Control Structures
Loops (do...while) → Used in addEmployees() to allow multiple entries.
Conditionals (if...else) → Used in main() to handle menu choices and in searchSalary() to check if the employee exists.
🔹 Functions
addEmployees() → Handles adding new records.
searchSalary() → Handles searching for a salary.
main() → Provides the menu and controls program flow.
3. Program Flow (Theory)
The program starts and displays a menu.
Based on user choice:
Option 1: Calls addEmployees() → Prompts for name and salary → Stores them in the file.
Option 2: Calls searchSalary() → Prompts for name → Searches file → Displays salary if found.
Option 3: Exits the program.
Any other input → Displays an error message.
File is closed after each operation to ensure data integrity.
4. Advantages
Simple and easy to implement.
Demonstrates basic file handling.
Data persists even after program termination.
5. Limitations
Names cannot contain spaces.
No validation for salary input.
Only exact name matches are supported.
No options to update or delete records.
Data stored in plain text (not secure).
6. Possible Enhancements
Use fgets for names with spaces.
Add error handling for file operations.
Implement update and delete features.
Use binary files for efficiency and security.
Add listing and sorting of employees.
By google , wikipidea ,youtube

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
    

    
