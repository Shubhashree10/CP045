#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for maximum users and elements
#define MAX_USERS 100
#define MAX_ELEMENTS 100

// Structure to represent user data
struct User {
    char username[50];
    char password[50];
    int isAdmin;
};

// Structure to represent an element
struct Element {
    int value;
};

// Global variables
struct User users[MAX_USERS];
struct Element elements[MAX_ELEMENTS];
int numUsers = 0;
int numElements = 0;
struct User *currentUser = NULL; // To track the logged-in user

// Function prototypes
void login();
void adminMenu();
void customerMenu();
void addElement();
void deleteElement();
void updateElement();
void sortElements(int algorithm);
void printElements();

int main() {
    // Sample admin and customer users (for demonstration)
    strcpy(users[numUsers].username, "admin");
    strcpy(users[numUsers].password, "adminpass");
    users[numUsers].isAdmin = 1;
    numUsers++;

    strcpy(users[numUsers].username, "customer");
    strcpy(users[numUsers].password, "customerpass");
    users[numUsers].isAdmin = 0;
    numUsers++;

    int choice;

    // Main application loop
    while (1) {
        printf("\nMain Menu:\n");
        printf("1. Login\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                login();
                break;

            case 2:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void login() {
    char username[50];
    char password[50];

    printf("\nLogin Page\n");
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    // Check if the user exists and the password is correct
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            currentUser = &users[i];

            if (currentUser->isAdmin) {
                adminMenu();
            } else {
                customerMenu();
            }
            return;
        }
    }

    printf("Invalid username or password. Please try again.\n");
}

void adminMenu() {
    int choice;

    while (1) {
        printf("\nAdmin Menu:\n");
        printf("1. Add Element\n");
        printf("2. Delete Element\n");
        printf("3. Update Element\n");
        printf("4. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addElement();
                break;

            case 2:
                deleteElement();
                break;

            case 3:
                updateElement();
                break;

            case 4:
                currentUser = NULL;
                return;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void customerMenu() {
    int choice;

    while (1) {
        printf("\nCustomer Menu:\n");
        printf("1. Sort Elements (Bubble Sort)\n");
        printf("2. Sort Elements (Selection Sort)\n");
        printf("3. Print Elements\n");
        printf("4. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                sortElements(1); // 1 for Bubble Sort
                break;

            case 2:
                sortElements(2); // 2 for Selection Sort
                break;

            case 3:
                printElements();
                break;

            case 4:
                currentUser = NULL;
                return;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void addElement() {
    if (numElements < MAX_ELEMENTS) {
        printf("Enter the element to add: ");
        scanf("%d", &elements[numElements].value);
        numElements++;
        printf("Element added successfully.\n");
    } else {
        printf("Maximum element limit reached. Cannot add more elements.\n");
    }
}

void deleteElement() {
    if (numElements > 0) {
        int pos;
        printf("Enter the position of the element to delete (0-%d): ", numElements - 1);
        scanf("%d", &pos);
        if (pos >= 0 && pos < numElements) {
            for (int i = pos; i < numElements - 1; i++) {
                elements[i] = elements[i + 1];
            }
            numElements--;
            printf("Element deleted successfully.\n");
        } else {
            printf("Invalid position.\n");
        }
    } else {
        printf("No elements to delete.\n");
    }
}

void updateElement() {
    if (numElements > 0) {
        int pos, newValue;
        printf("Enter the position of the element to update (0-%d): ", numElements - 1);
        scanf("%d", &pos);
        if (pos >= 0 && pos < numElements) {
            printf("Enter the new value: ");
            scanf("%d", &newValue);
            elements[pos].value = newValue;
            printf("Element updated successfully.\n");
        } else {
            printf("Invalid position.\n");
        }
    } else {
        printf("No elements to update.\n");
    }
}

void sortElements(int algorithm) {
    int temp;
    for (int i = 0; i < numElements - 1; i++) {
        for (int j = 0; j < numElements - i - 1; j++) {
            if (algorithm == 1) { // Bubble Sort
                if (elements[j].value > elements[j + 1].value) {
                    // Swap elements[j] and elements[j + 1]
                    temp = elements[j].value;
                    elements[j].value = elements[j + 1].value;
                    elements[j + 1].value = temp;
                }
            } else if (algorithm == 2) { // Selection Sort
                if (elements[j].value > elements[j + 1].value) {
                    // Swap elements[j] and elements[j + 1]
                    temp = elements[j].value;
                    elements[j].value = elements[j + 1].value;
                    elements[j + 1].value = temp;
                }
            }
        }
    }
    printf("Elements sorted successfully.\n");
}

void printElements() {
    if (numElements > 0) {
        printf("Sorted Elements: ");
        for (int i = 0; i < numElements; i++) {
            printf("%d ", elements[i].value);
        }
        printf("\n");
    } else {
        printf("No elements to print.\n");
    }
}
