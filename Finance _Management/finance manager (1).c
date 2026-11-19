
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

struct Transaction {
    int type;               // 1 = Income, 2 = Expense
    char category[30];
    char date[20];          // YYYY-MM-DD
    double amount;
};

struct Transaction transactions[MAX];

int count = 0;
double monthlyBudget = 0;

/* Function declarations */
void loadData();
void saveData();
void addIncome();
void addExpense();
void viewTransactions();
void showDashboard();
void searchTransaction();
void monthlyReport();
void setBudget();
void checkBudget();
double calculateIncome();
double calculateExpenses();
double calculateMonthlyExpenses(const char month[]);

/* Load saved transactions */
void loadData() {
    FILE *fp = fopen("transactions.txt", "r");

    if (fp != NULL) {
        while (count < MAX &&
               fscanf(fp, "%d %29s %19s %lf",
                      &transactions[count].type,
                      transactions[count].category,
                      transactions[count].date,
                      &transactions[count].amount) == 4) {
            count++;
        }
        fclose(fp);
    }

    FILE *bp = fopen("budget.txt", "r");

    if (bp != NULL) {
        fscanf(bp, "%lf", &monthlyBudget);
        fclose(bp);
    }
}

/* Save transactions */
void saveData() {
    FILE *fp = fopen("transactions.txt", "w");

    if (fp == NULL) {
        printf("\nError saving transactions!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d %s %s %.2f\n",
                transactions[i].type,
                transactions[i].category,
                transactions[i].date,
                transactions[i].amount);
    }

    fclose(fp);

    FILE *bp = fopen("budget.txt", "w");

    if (bp != NULL) {
        fprintf(bp, "%.2f", monthlyBudget);
        fclose(bp);
    }
}

/* Calculate total income */
double calculateIncome() {
    double total = 0;

    for (int i = 0; i < count; i++) {
        if (transactions[i].type == 1) {
            total += transactions[i].amount;
        }
    }

    return total;
}

/* Calculate total expenses */
double calculateExpenses() {
    double total = 0;

    for (int i = 0; i < count; i++) {
        if (transactions[i].type == 2) {
            total += transactions[i].amount;
        }
    }

    return total;
}

/* Calculate expenses for a particular month */
double calculateMonthlyExpenses(const char month[]) {
    double total = 0;

    for (int i = 0; i < count; i++) {
        if (transactions[i].type == 2 &&
            strncmp(transactions[i].date, month, 7) == 0) {
            total += transactions[i].amount;
        }
    }

    return total;
}

/* Add income */
void addIncome() {
    if (count >= MAX) {
        printf("\nTransaction storage is full!\n");
        return;
    }

    struct Transaction t;

    t.type = 1;
    strcpy(t.category, "Income");

    printf("\nEnter income amount: ");

    if (scanf("%lf", &t.amount) != 1 || t.amount <= 0) {
        printf("Invalid amount!\n");
        while (getchar() != '\n');
        return;
    }

    printf("Enter date (YYYY-MM-DD): ");
    scanf("%19s", t.date);

    if (strlen(t.date) != 10 ||
        t.date[4] != '-' || t.date[7] != '-') {
        printf("Invalid date format!\n");
        return;
    }

    transactions[count++] = t;

    saveData();

    printf("\nIncome added successfully!\n");
}

/* Add expense */
void addExpense() {
    if (count >= MAX) {
        printf("\nTransaction storage is full!\n");
        return;
    }

    struct Transaction t;

    t.type = 2;

    printf("\nEnter expense amount: ");

    if (scanf("%lf", &t.amount) != 1 || t.amount <= 0) {
        printf("Invalid amount!\n");
        while (getchar() != '\n');
        return;
    }

    printf("\nSelect Expense Category\n");
    printf("1. Food\n");
    printf("2. Travel\n");
    printf("3. Shopping\n");
    printf("4. Education\n");
    printf("5. Bills\n");
    printf("6. Other\n");

    int choice;

    printf("Enter category: ");

    if (scanf("%d", &choice) != 1) {
        printf("Invalid category!\n");
        while (getchar() != '\n');
        return;
    }

    switch (choice) {
        case 1:
            strcpy(t.category, "Food");
            break;

        case 2:
            strcpy(t.category, "Travel");
            break;

        case 3:
            strcpy(t.category, "Shopping");
            break;

        case 4:
            strcpy(t.category, "Education");
            break;

        case 5:
            strcpy(t.category, "Bills");
            break;

        case 6:
            strcpy(t.category, "Other");
            break;

        default:
            printf("Invalid category!\n");
            return;
    }

    printf("Enter date (YYYY-MM-DD): ");
    scanf("%19s", t.date);

    if (strlen(t.date) != 10 ||
        t.date[4] != '-' || t.date[7] != '-') {
        printf("Invalid date format!\n");
        return;
    }

    transactions[count++] = t;

    saveData();

    printf("\nExpense added successfully!\n");
}

/* View all transactions */
void viewTransactions() {
    printf("\n========== TRANSACTION HISTORY ==========\n");

    if (count == 0) {
        printf("No transactions available.\n");
        return;
    }

    printf("%-5s %-12s %-15s %-15s\n",
           "No.", "Type", "Category", "Amount");

    printf("-----------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-5d %-12s %-15s %.2f\n",
               i + 1,
               transactions[i].type == 1 ? "Income" : "Expense",
               transactions[i].category,
               transactions[i].amount);

        printf("     Date: %s\n", transactions[i].date);
    }
}

/* Dashboard */
void showDashboard() {
    double income = calculateIncome();
    double expense = calculateExpenses();
    double balance = income - expense;

    printf("\n========== FINANCIAL DASHBOARD ==========\n");

    printf("Total Income   : Rs. %.2f\n", income);
    printf("Total Expenses : Rs. %.2f\n", expense);
    printf("Current Balance: Rs. %.2f\n", balance);

    printf("Total Transactions: %d\n", count);

    printf("=========================================\n");
}

/* Search transactions */
void searchTransaction() {
    char keyword[30];
    int found = 0;

    printf("\nEnter category or date to search: ");
    scanf("%29s", keyword);

    printf("\n========== SEARCH RESULTS ==========\n");

    for (int i = 0; i < count; i++) {
        if (strstr(transactions[i].category, keyword) != NULL ||
            strstr(transactions[i].date, keyword) != NULL) {

            printf("\nType: %s",
                   transactions[i].type == 1 ? "Income" : "Expense");

            printf("\nCategory: %s", transactions[i].category);
            printf("\nDate: %s", transactions[i].date);
            printf("\nAmount: Rs. %.2f\n", transactions[i].amount);

            found = 1;
        }
    }

    if (!found) {
        printf("No matching transactions found.\n");
    }
}

/* Monthly financial report */
void monthlyReport() {
    char month[8];

    double income = 0;
    double expense = 0;

    printf("\nEnter month (YYYY-MM): ");
    scanf("%7s", month);

    if (strlen(month) != 7 || month[4] != '-') {
        printf("Invalid month format!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        if (strncmp(transactions[i].date, month, 7) == 0) {
            if (transactions[i].type == 1) {
                income += transactions[i].amount;
            } else {
                expense += transactions[i].amount;
            }
        }
    }

    printf("\n========== MONTHLY REPORT ==========\n");

    printf("Month          : %s\n", month);
    printf("Monthly Income : Rs. %.2f\n", income);
    printf("Monthly Expense: Rs. %.2f\n", expense);
    printf("Monthly Balance: Rs. %.2f\n", income - expense);

    printf("====================================\n");
}

/* Set monthly budget */
void setBudget() {
    printf("\nEnter your monthly budget: Rs. ");

    if (scanf("%lf", &monthlyBudget) != 1 ||
        monthlyBudget <= 0) {
        printf("Invalid budget!\n");
        monthlyBudget = 0;
        while (getchar() != '\n');
        return;
    }

    saveData();

    printf("\nMonthly budget saved successfully!\n");
}

/* Check monthly budget */
void checkBudget() {
    char month[8];

    if (monthlyBudget <= 0) {
        printf("\nPlease set your budget first!\n");
        return;
    }

    printf("\nEnter month (YYYY-MM): ");
    scanf("%7s", month);

    if (strlen(month) != 7 || month[4] != '-') {
        printf("Invalid month format!\n");
        return;
    }

    double expense = calculateMonthlyExpenses(month);

    printf("\n========== BUDGET STATUS ==========\n");

    printf("Monthly Budget : Rs. %.2f\n", monthlyBudget);
    printf("Total Expenses : Rs. %.2f\n", expense);
    printf("Remaining      : Rs. %.2f\n",
           monthlyBudget - expense);

    if (expense > monthlyBudget) {
        printf("\nWARNING: You exceeded your budget!\n");
    } else if (expense == monthlyBudget) {
        printf("\nYou have used your entire budget!\n");
    } else {
        printf("\nYou are within your budget.\n");
    }

    printf("===================================\n");
}

/* Main function */
int main() {
    int choice;

    loadData();

    printf("\n");
    printf("=========================================\n");
    printf("   SMART PERSONAL FINANCE MANAGER\n");
    printf("=========================================\n");

    do {
        printf("\n========== MAIN MENU ==========\n");

        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. View Transactions\n");
        printf("4. Financial Dashboard\n");
        printf("5. Search Transactions\n");
        printf("6. Monthly Report\n");
        printf("7. Set Monthly Budget\n");
        printf("8. Check Budget\n");
        printf("9. Exit\n");

        printf("\nEnter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Please enter a valid number!\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                addIncome();
                break;

            case 2:
                addExpense();
                break;

            case 3:
                viewTransactions();
                break;

            case 4:
                showDashboard();
                break;

            case 5:
                searchTransaction();
                break;

            case 6:
                monthlyReport();
                break;

            case 7:
                setBudget();
                break;

            case 8:
                checkBudget();
                break;

            case 9:
                saveData();
                printf("\nThank you for using Finance Manager!\n");
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
        }

    } while (choice != 9);

    return 0;
}
