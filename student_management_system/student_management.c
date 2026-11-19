
#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student
{
    int roll;
    char name[50];
    float marks1, marks2, marks3;
};

struct Student students[MAX];
int count = 0;

// Add Student
void addStudent()
{
    if (count >= MAX)
    {
        printf("\nStudent limit reached!\n");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &students[count].roll);

    for (int i = 0; i < count; i++)
    {
        if (students[i].roll == students[count].roll)
        {
            printf("Roll number already exists!\n");
            return;
        }
    }

    printf("Enter Student Name: ");
    scanf(" %49[^\n]", students[count].name);

    printf("Enter Marks in Subject 1: ");
    scanf("%f", &students[count].marks1);

    printf("Enter Marks in Subject 2: ");
    scanf("%f", &students[count].marks2);

    printf("Enter Marks in Subject 3: ");
    scanf("%f", &students[count].marks3);

    if (students[count].marks1 < 0 || students[count].marks1 > 100 ||
        students[count].marks2 < 0 || students[count].marks2 > 100 ||
        students[count].marks3 < 0 || students[count].marks3 > 100)
    {
        printf("Invalid marks! Enter marks between 0 and 100.\n");
        return;
    }

    count++;
    printf("\nStudent added successfully!\n");
}

// Display Students
void displayStudents()
{
    if (count == 0)
    {
        printf("\nNo student records available!\n");
        return;
    }

    printf("\n========== STUDENT RECORDS ==========\n");

    for (int i = 0; i < count; i++)
    {
        float total = students[i].marks1 +
                      students[i].marks2 +
                      students[i].marks3;

        float percentage = total / 3;

        printf("\nRoll Number: %d\n", students[i].roll);
        printf("Name: %s\n", students[i].name);
        printf("Total Marks: %.2f/300\n", total);
        printf("Percentage: %.2f%%\n", percentage);
    }
}

// Search Student
void searchStudent()
{
    int roll, found = 0;

    printf("\nEnter Roll Number to Search: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++)
    {
        if (students[i].roll == roll)
        {
            printf("\nStudent Found!\n");
            printf("Roll Number: %d\n", students[i].roll);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f, %.2f, %.2f\n",
                   students[i].marks1,
                   students[i].marks2,
                   students[i].marks3);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nStudent not found!\n");
}

// Update Student
void updateStudent()
{
    int roll, found = 0;

    printf("\nEnter Roll Number to Update: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++)
    {
        if (students[i].roll == roll)
        {
            printf("Enter New Name: ");
            scanf(" %49[^\n]", students[i].name);

            printf("Enter New Marks (3 subjects): ");
            scanf("%f %f %f",
                  &students[i].marks1,
                  &students[i].marks2,
                  &students[i].marks3);

            if (students[i].marks1 < 0 || students[i].marks1 > 100 ||
                students[i].marks2 < 0 || students[i].marks2 > 100 ||
                students[i].marks3 < 0 || students[i].marks3 > 100)
            {
                printf("Invalid marks! Update not completed.\n");
                return;
            }

            printf("\nStudent details updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nStudent not found!\n");
}

// Delete Student
void deleteStudent()
{
    int roll, found = 0;

    printf("\nEnter Roll Number to Delete: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++)
    {
        if (students[i].roll == roll)
        {
            for (int j = i; j < count - 1; j++)
            {
                students[j] = students[j + 1];
            }

            count--;
            printf("\nStudent deleted successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nStudent not found!\n");
}

// Main Function
int main()
{
    int choice;

    do
    {
        printf("\n====================================\n");
        printf("       STUDENT MANAGEMENT SYSTEM\n");
        printf("====================================\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");

        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                printf("\nThank you for using Student Management System!\n");
                break;

            default:
                printf("\nInvalid Choice! Try Again.\n");
        }

    } while (choice != 6);

    return 0;
}
