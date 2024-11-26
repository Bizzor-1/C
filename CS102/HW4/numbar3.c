#include <stdio.h>
#include <string.h>

typedef struct {
    int accountNumber;
    char name[50];
    float balance;
} Information;
Information info[100];

int count = 0;
void addCustomer() {
    printf("Enter account number: ");
    scanf("%d", &info[count].accountNumber);
    getchar();
    printf("Enter customer name: ");
    fgets(info[count].name, 50, stdin);
    info[count].name[strcspn(info[count].name, "\n")] = '\0';
    printf("Enter initial balance: ");
    scanf("%f", &info[count].balance);
    printf("Customer added successfully.\n");
    printf("\n");
    count++;
}

void deposit() {
    int i,acselect,acc_id;
    float deposit;
    printf("Enter account number for deposit: ");
    scanf("%d", &acselect);
    for (i = 0; i < count; i++) {
        if (info[i].accountNumber ==  acselect) {
                printf("Enter amount to deposit: ");
                scanf("%f", &deposit);
                info[i].balance += deposit;
                printf("Deposit successful. New balance: %.2f\n", info[i].balance);
                printf("\n");
        }
    }

}

void withdraw() {
    int i,acselect,acc_id;
    float withdraw;
    printf("Enter account number for withdraw: ");
    scanf("%d", &acselect);
    for (i = 0; i < count; i++) {
        if (info[i].accountNumber ==  acselect) {
                printf("Enter amount to withdraw: ");
                scanf("%f", &withdraw);
                info[i].balance -= withdraw;
                printf("Withdraw successful. New balance: %.2f\n", info[i].balance);
                printf("\n");
        }
    }
}

void displayCustomer() {
    int i;
    printf("Customer List:\n");
    for (i = 0; i < count; i++) {
        printf("Account Number: %d, Name: %s, Balance: %.2f\n", info[i].accountNumber, info[i].name, info[i].balance);
    }
    printf("\n");

}

int main () {
    int i,input;

    do {
        printf("Bank Management System\n");
        printf("1. Add New Customer\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Display All Customers\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &input);
        if (input == 1) {
            addCustomer();
        } else if (input == 2) {
            deposit();
        } else if (input == 3) {
            withdraw();
        } else if (input == 4) {
            displayCustomer();
        } else {
            printf("Exiting program.");
        }
    } while (input != 5);

    return 0;
}