#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 100

struct Account {
    int accountNumber;
    char name[100];
    double balance;
};

struct Account accounts[MAX_ACCOUNTS];
int count = 0;

/* Load saved account records */
void loadAccounts(void) {
    FILE *file = fopen("accounts.dat", "rb");

    if (file == NULL) {
        return; /* First run: no data file exists yet */
    }

    while (count < MAX_ACCOUNTS &&
           fread(&accounts[count], sizeof(struct Account), 1, file) == 1) {
        count++;
    }

    fclose(file);
}

/* Save account records */
void saveAccounts(void) {
    FILE *file = fopen("accounts.dat", "wb");

    if (file == NULL) {
        printf("Error: Could not save account data.\n");
        return;
    }

    if (fwrite(accounts, sizeof(struct Account), count, file) != (size_t)count) {
        printf("Error: Could not write all account records.\n");
    }

    fclose(file);
}

/* Find an account by account number */
int findAccount(int number) {
    for (int i = 0; i < count; i++) {
        if (accounts[i].accountNumber == number) {
            return i;
        }
    }

    return -1;
}

/* Create a new account */
void createAccount(void) {
    if (count >= MAX_ACCOUNTS) {
        printf("\nAccount limit reached. Cannot create more accounts.\n");
        return;
    }

    int newNumber = 1001;
    while (findAccount(newNumber) != -1) {
        newNumber++;
    }

    printf("\nEnter customer name: ");
    scanf(" %99[^\n]", accounts[count].name);

    printf("Enter initial deposit: ");
    if (scanf("%lf", &accounts[count].balance) != 1) {
        printf("Invalid amount. Account was not created.\n");
        while (getchar() != '\n' && !feof(stdin)) {
        }
        return;
    }

    if (accounts[count].balance < 0) {
        printf("Initial deposit cannot be negative. Account was not created.\n");
        return;
    }

    accounts[count].accountNumber = newNumber;
    count++;

    saveAccounts();

    printf("\nAccount created successfully!\n");
    printf("Your account number is: %d\n", newNumber);
}

/* Deposit money into an account */
void depositMoney(void) {
    int number;
    double amount;

    printf("\nEnter account number: ");
    if (scanf("%d", &number) != 1) {
        printf("Invalid account number.\n");
        while (getchar() != '\n' && !feof(stdin)) {
        }
        return;
    }

    int index = findAccount(number);

    if (index == -1) {
        printf("Account not found.\n");
        return;
    }

    printf("Enter deposit amount: ");
    if (scanf("%lf", &amount) != 1) {
        printf("Invalid amount.\n");
        while (getchar() != '\n' && !feof(stdin)) {
        }
        return;
    }

    if (amount <= 0) {
        printf("Deposit amount must be greater than zero.\n");
        return;
    }

    accounts[index].balance += amount;
    saveAccounts();

    printf("\nMoney deposited successfully!\n");
    printf("Updated balance: %.2f\n", accounts[index].balance);
}

/* Withdraw money from an account */
void withdrawMoney(void) {
    int number;
    double amount;

    printf("\nEnter account number: ");
    if (scanf("%d", &number) != 1) {
        printf("Invalid account number.\n");
        while (getchar() != '\n' && !feof(stdin)) {
        }
        return;
    }

    int index = findAccount(number);

    if (index == -1) {
        printf("Account not found.\n");
        return;
    }

    printf("Enter withdrawal amount: ");
    if (scanf("%lf", &amount) != 1) {
        printf("Invalid amount.\n");
        while (getchar() != '\n' && !feof(stdin)) {
        }
        return;
    }

    if (amount <= 0) {
        printf("Withdrawal amount must be greater than zero.\n");
        return;
    }

    if (amount > accounts[index].balance) {
        printf("Insufficient balance.\n");
        return;
    }

    accounts[index].balance -= amount;
    saveAccounts();

    printf("\nWithdrawal successful!\n");
    printf("Remaining balance: %.2f\n", accounts[index].balance);
}

/* Display details and balance for one account */
void checkBalance(void) {
    int number;

    printf("\nEnter account number: ");
    if (scanf("%d", &number) != 1) {
        printf("Invalid account number.\n");
        while (getchar() != '\n' && !feof(stdin)) {
        }
        return;
    }

    int index = findAccount(number);

    if (index == -1) {
        printf("Account not found.\n");
        return;
    }

    printf("\n--------- ACCOUNT DETAILS ---------\n");
    printf("Account number : %d\n", accounts[index].accountNumber);
    printf("Customer name  : %s\n", accounts[index].name);
    printf("Balance        : %.2f\n", accounts[index].balance);
    printf("-----------------------------------\n");
}

/* Display all registered accounts */
void displayAllAccounts(void) {
    if (count == 0) {
        printf("\nNo accounts have been created yet.\n");
        return;
    }

    printf("\n========== ALL BANK ACCOUNTS ==========\n");

    for (int i = 0; i < count; i++) {
        printf("\nAccount number : %d\n", accounts[i].accountNumber);
        printf("Customer name  : %s\n", accounts[i].name);
        printf("Balance        : %.2f\n", accounts[i].balance);
    }
}

/* Main menu */
int main(void) {
    int choice;

    loadAccounts();

    do {
        printf("\n====================================\n");
        printf("       BANKING MANAGEMENT SYSTEM\n");
        printf("====================================\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Display All Accounts\n");
        printf("6. Exit\n");
        printf("====================================\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input. Please enter a number.\n");
            while (getchar() != '\n' && !feof(stdin)) {
            }
            continue;
        }

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                displayAllAccounts();
                break;
            case 6:
                printf("\nThank you for using the Banking Management System!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
