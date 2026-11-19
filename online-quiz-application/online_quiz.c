
#include <stdio.h>

int main()
{
    int answer;
    int score = 0;

    printf("====================================\n");
    printf("       ONLINE QUIZ APPLICATION\n");
    printf("====================================\n");

    // Question 1
    printf("\n1. Which language is used for C programming?\n");
    printf("A. Python\n");
    printf("B. C\n");
    printf("C. Java\n");
    printf("D. HTML\n");
    printf("Enter your answer (1-4): ");
    scanf("%d", &answer);

    if (answer == 2)
    {
        printf("Correct Answer!\n");
        score++;
    }
    else
    {
        printf("Wrong Answer! Correct answer is B. C\n");
    }

    // Question 2
    printf("\n2. Who developed the C language?\n");
    printf("1. James Gosling\n");
    printf("2. Dennis Ritchie\n");
    printf("3. Guido van Rossum\n");
    printf("4. Bjarne Stroustrup\n");
    printf("Enter your answer (1-4): ");
    scanf("%d", &answer);

    if (answer == 2)
    {
        printf("Correct Answer!\n");
        score++;
    }
    else
    {
        printf("Wrong Answer! Correct answer is 2. Dennis Ritchie\n");
    }

    // Question 3
    printf("\n3. Which symbol is used to end a C statement?\n");
    printf("1. :\n");
    printf("2. .\n");
    printf("3. ;\n");
    printf("4. ,\n");
    printf("Enter your answer (1-4): ");
    scanf("%d", &answer);

    if (answer == 3)
    {
        printf("Correct Answer!\n");
        score++;
    }
    else
    {
        printf("Wrong Answer! Correct answer is 3. ;\n");
    }

    // Question 4
    printf("\n4. Which function is used to display output in C?\n");
    printf("1. scanf()\n");
    printf("2. printf()\n");
    printf("3. main()\n");
    printf("4. return()\n");
    printf("Enter your answer (1-4): ");
    scanf("%d", &answer);

    if (answer == 2)
    {
        printf("Correct Answer!\n");
        score++;
    }
    else
    {
        printf("Wrong Answer! Correct answer is 2. printf()\n");
    }

    // Question 5
    printf("\n5. Which data type stores whole numbers in C?\n");
    printf("1. float\n");
    printf("2. char\n");
    printf("3. int\n");
    printf("4. double\n");
    printf("Enter your answer (1-4): ");
    scanf("%d", &answer);

    if (answer == 3)
    {
        printf("Correct Answer!\n");
        score++;
    }
    else
    {
        printf("Wrong Answer! Correct answer is 3. int\n");
    }

    // Final Result
    printf("\n====================================\n");
    printf("             QUIZ RESULT\n");
    printf("====================================\n");

    printf("Total Questions : 5\n");
    printf("Correct Answers : %d\n", score);
    printf("Wrong Answers   : %d\n", 5 - score);
    printf("Total Score     : %d/5\n", score);
    printf("Percentage      : %.2f%%\n", (score / 5.0) * 100);

    if (score >= 3)
    {
        printf("Result: PASS\n");
    }
    else
    {
        printf("Result: FAIL\n");
    }

    printf("====================================\n");

    return 0;
}
