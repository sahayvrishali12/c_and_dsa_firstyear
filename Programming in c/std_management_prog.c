#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 5


typedef struct {
    int sapID;
    int rollNo;
    char name[50];
    char phone[15];
    char email[50];
    int year;
    int semester;
    float sgpa[8];
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Student limit reached!\n");
        return;
    }
    
    Student s;
    printf("Enter SAP ID: ");
    scanf("%d", &s.sapID);
    printf("Enter Roll No: ");
    scanf("%d", &s.rollNo);
    printf("Enter Name: ");
    scanf("%s", s.name);
    printf("Enter Phone: ");
    scanf("%s", &s.phone);
    printf("Enter Email: ");
    scanf("%s", &s.email);
    printf("Enter Year (1-4): ");
    scanf("%d", &s.year);
    printf("Enter Semester (1-8): ");
    scanf("%d", &s.semester);
    for (int i = 0; i < s.semester; i++) {
        printf("Enter SGPA for semester %d: ", i + 1);
        scanf("%f", &s.sgpa[i]);
    }
    
    students[studentCount++] = s;
    printf("Student added successfully!\n");
}

void displayStudent(int sapID) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].sapID == sapID) {
            printf("\n=====================================================\n");
            printf("                  Student Details                  \n");
            printf("=====================================================\n");
            printf("  SAP ID:         %-10d\n", students[i].sapID);
            printf("  Roll No:        %-10d\n", students[i].rollNo);
            printf("  Name:           %-20s\n", students[i].name);
            printf("  Phone:          %-15s\n", students[i].phone);
            printf("  Email:          %-20s\n", students[i].email);
            printf("  Year:           %-10d\n", students[i].year);
            printf("  Semester:       %-10d\n", students[i].semester);
            printf("=====================================================\n");
            printf("                  Semester SGPA                     \n");
            printf("=====================================================\n");
            for (int j = 0; j < students[i].semester; j++) {
                printf("  Semester %-2d: %-5.2f\n", j + 1, students[i].sgpa[j]);
            }
            printf("=====================================================\n");
            return; // Exit the loop once the student is found
        }
    }
    printf("\nStudent not found.\n");
}

float calculateCGPA(int sapID) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].sapID == sapID) {
            float sum = 0;
            for (int j = 0; j < students[i].semester; j++) {
                sum += students[i].sgpa[j];
            }
            return sum / students[i].semester;
        }
    }
    return -1;
}

void displayAllStudents() {
    for (int i = 0; i < studentCount; i++) {
        displayStudent(students[i].sapID);
    }
}

void deleteStudent(int sapID) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].sapID == sapID) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            printf("Student record deleted successfully!\n");
            return;
        }
    }
    printf("Student with SAP ID %d not found.\n", sapID);
}

void menu() {
    int choice, sapID;
    do {
        printf("\n1. Add Student\n2. Search Student\n3. Calculate CGPA\n4. Display All Students\n5. Delete Student\n6. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addStudent(); break;
            case 2: printf("Enter SAP ID: "); scanf("%d", &sapID); displayStudent(sapID); break;
            case 3: printf("Enter SAP ID: "); scanf("%d", &sapID); 
                    printf("CGPA: %.2f\n", calculateCGPA(sapID)); break;
            case 4: displayAllStudents(); break;
            case 5: printf("Enter SAP ID: "); scanf("%d", &sapID); deleteStudent(sapID); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 6);
}

int main() {
    menu();
    return 0;
}
