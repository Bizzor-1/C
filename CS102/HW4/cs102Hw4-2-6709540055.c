#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
    float income;
} Register;

Register regis[101];
int count = 0;

void responce (int input) {
    int i;
    
    if (input == 1) {
        printf("Enter ID: ");
        scanf("%d", &regis[count].id);
        getchar();
        printf("Enter Name: ");
        fgets(regis[count].name, 50, stdin);
        regis[count].name[strcspn(regis[count].name, "\n")] = '\0';
        printf("Enter Age: ");
        scanf("%d", &regis[count].age);
        printf("Enter Monthly Income: ");
        scanf("%f", &regis[count].income);
        printf("Person registered successfully.\n");
        count++;
        printf("==\n");
    }

    if (input == 2) {
        if (count == 0) {
            printf("No registered persons to display\n");
        } else {
            printf("%-5s %-15s %-5s %-15s\n", "ID", "Name", "Age", "Monthly Income");
            for (i = 0; i < count; i++) {
               printf("%-5d %-15s %-5d %-15.2f\n", regis[i].id, regis[i].name, regis[i].age, regis[i].income); 
            }
            printf("==\n");
        }

    }
}

int main () {
    
    int i;
    int input;
    do {
        printf("Poverty Registration System\n");
        printf("1. Register New Person\n");
        printf("2. Display All Registered Persons\n");
        printf("3. Exit\n");
        printf("==\n");
        printf("Enter your choice: ");
        scanf("%d", &input);
        if (input == 1 || input == 2) {
            responce(input);
        }
        if (input == 3){
            printf("Exiting program.");
        }
    } while (input != 3);
    return 0;
}