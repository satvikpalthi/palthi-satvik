A personal finance management application built using C and GTK.

# 💰 Smart Personal Finance Manager

## 📌 Project Overview

The **Smart Personal Finance Manager** is a console-based financial management application developed using the C programming language.

This application helps users manage their personal finances by recording income and expenses, tracking transactions, calculating available balances, generating monthly financial reports, and managing monthly budgets.

It uses file handling to store financial information permanently, allowing users to access previously saved transactions and budget details whenever they run the application.

## 🎯 Project Objectives

- To manage personal income and expenses.
- To maintain financial transaction records.
- To calculate total income, expenses, and available balance.
- To track monthly spending.
- To set and monitor monthly budgets.
- To generate monthly financial reports.
- To store financial information using file handling.

## ✨ Features

### 1. Add Income
- Record income amounts.
- Enter the transaction date.
- Automatically save income records.

### 2. Add Expense
- Record daily expenses.
- Select expense categories.
- Enter transaction dates.
- Save expense records.

### 3. View Transactions
- Display all recorded transactions.
- View transaction types, categories, dates, and amounts.

### 4. Financial Dashboard
- Display total income.
- Display total expenses.
- Calculate current balance.
- Show the total number of transactions.

### 5. Search Transactions
- Search transactions using categories.
- Search transactions using dates.
- Display matching transaction details.

### 6. Monthly Report
- Generate monthly income reports.
- Calculate monthly expenses.
- Display monthly financial balance.

### 7. Set Monthly Budget
- Set a monthly spending budget.
- Save the budget information permanently.

### 8. Check Budget
- Compare monthly expenses with the set budget.
- Display remaining budget.
- Show warnings when the budget is exceeded.

### 9. Exit
- Save financial information.
- Close the application safely.

## 📂 Expense Categories

The application supports the following expense categories:

- Food
- Travel
- Shopping
- Education
- Bills
- Other

## 🛠️ Technologies Used

| Technology | Description |
|---|---|
| Programming Language | C |
| Compiler | GCC |
| Interface | Command Line Interface (CLI) |
| Data Storage | Text Files |
| File Handling | File I/O Operations |

## 📚 C Programming Concepts Used

- Variables and Data Types
- Conditional Statements
- Switch Statements
- Loops
- Functions
- Structures (`struct`)
- Arrays
- String Handling
- File Handling (`fopen`, `fscanf`, `fprintf`, `fclose`)
- Standard Input and Output

## 📁 Project Structure

```text
Smart-Personal-Finance-Manager/
│
├── finance manager (1).c
├── transactions.txt
├── budget.txt
└── README.md
```

**Note:** The two text files are created automatically when the application saves financial data. The C source filename can be renamed to `finance.c` for easier compilation.

## ⚙️ How to Run the Project

### Step 1: Clone the Repository

```bash
git clone YOUR_GITHUB_REPOSITORY_LINK
```

### Step 2: Open the Project Folder

```bash
cd Smart-Personal-Finance-Manager
```

### Step 3: Compile the Program

```bash
gcc "finance manager (1).c" -o finance
```

If you rename the source file to `finance.c`, use:

```bash
gcc finance.c -o finance
```

### Step 4: Run the Program

**Windows:**

```bash
finance.exe
```

**Linux:**

```bash
./finance
```

## 💻 Application Menu

```text
=========================================
   SMART PERSONAL FINANCE MANAGER
=========================================

========== MAIN MENU ==========

1. Add Income
2. Add Expense
3. View Transactions
4. Financial Dashboard
5. Search Transactions
6. Monthly Report
7. Set Monthly Budget
8. Check Budget
9. Exit

Enter your choice:
```

## 💾 Data Storage

The application uses file handling to store information:

**transactions.txt**
- Stores income and expense transactions.
- Stores transaction categories.
- Stores transaction dates.
- Stores transaction amounts.

**budget.txt**
- Stores the monthly budget amount.
- Allows the budget to be loaded when the application starts.

This helps maintain financial records even after closing the application.

## 🚀 Future Improvements

- Add user login and authentication.
- Introduce password protection.
- Develop a graphical user interface using GTK.
- Add graphical representations of income and expenses.
- Generate downloadable financial reports.
- Add advanced financial analytics.

## 🎓 Learning Outcomes

Through this project, I gained practical experience in:

- Developing real-world applications using C.
- Understanding structures and functions.
- Implementing file handling for permanent data storage.
- Managing financial calculations.
- Working with arrays and strings.
- Developing menu-driven applications.
- Applying programming concepts to solve real-world problems.

## 👨‍💻 Developer

**Name:** Satvik Palthi

**Project Name:** Smart Personal Finance Manager

**Programming Language:** C

**Project Type:** Console-Based Application

## 📜 License

This project is developed for educational and learning purposes.

---

⭐ If you find this project useful, consider giving this repository a star!
