#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_QUESTIONS 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char sap_id[15];
    int marks[MAX_QUESTIONS];
} Student;

void askQuestions(Student *student) {
    const char *questions[MAX_QUESTIONS] = {
        "What is the sum of 5 and 3?",
        "What is 10 multiplied by 2?",
        "Divide 20 by 4. What's the result?",
        "If you add 7 to 8, what do you get?",
        "Subtract 3 from 12. What's the answer?",
        "What is the product of 6 and 4?",
        "How many sides does a triangle have?",
        "What is the square root of 9?",
        "Which number is greater: 15 or 12?",
        "What is 25 divided by 5?"
    };

    const int answers[MAX_QUESTIONS] = {2, 4, 3, 3, 2, 2, 1, 2, 1, 2};
    const char *options[MAX_QUESTIONS][4] = {
        {"6", "8", "10", "12"},
        {"5", "10", "15", "20"},
        {"3", "4", "5", "6"},
        {"12", "13", "15", "16"},
        {"7", "9", "10", "15"},
        {"18", "24", "30", "36"},
        {"3", "4", "5", "6"},
        {"1", "3", "4", "9"},
        {"15", "12", "Both are equal", "Cannot be determined"},
        {"1", "5", "6", "7"}
    };

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("Question %d: %s\n", i + 1, questions[i]);
        for (int j = 0; j < 4; j++) {
            printf("%d. %s\n", j + 1, options[i][j]);
        }
        int answer;
        printf("Enter your answer (1-4): ");
        scanf("%d", &answer);
        if (answer == answers[i]) {
            student->marks[i] = 1;
        } else {
            student->marks[i] = 0;
        }
    }
}

int main() {
    Student student;
    printf("Enter your name: ");
    fgets(student.name, MAX_NAME_LENGTH, stdin);
    student.name[strcspn(student.name, "\n")] = '\0';

    printf("Enter your SAP ID: ");
    fgets(student.sap_id, 15, stdin);
    student.sap_id[strcspn(student.sap_id, "\n")] = '\0';

    askQuestions(&student);

    int totalMarks = 0;
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        totalMarks += student.marks[i];
    }

    printf("Total marks: %d/%d\n", totalMarks, MAX_QUESTIONS);

    return 0;
}

