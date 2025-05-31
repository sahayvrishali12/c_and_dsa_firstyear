#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define SEMESTERS 8

typedef struct {
    int sap_id;
    int roll_no;
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    int year;
    int semester;
    float sgpas[SEMESTERS];
} Student;

Student students[MAX_STUDENTS];
int student_count = 0;

void display_menu();
void add_student();
void search_student();
float calculate_cgpa(Student s);
void display_student(Student s);
void show_year_avg();
void display_all();
void delete_student();
void sort_by_sap();
void sort_by_name();
void clear_input_buffer();

// Main driver program
int main() {
    int choice;
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clear_input_buffer();

        switch(choice) {
            case 1: add_student(); break;
            case 2: search_student(); break;
            case 3: show_year_avg(); break;
            case 4: display_all(); break;
            case 5: delete_student(); break;
            case 6: sort_by_sap(); break;
            case 7: sort_by_name(); break;
            case 8: printf("Exiting program...\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while(choice != 8);
    return 0;
}

void display_menu() {
    printf("\nStudent Management System\n");
    printf("1. Add Student\n");
    printf("2. Search Student\n");
    printf("3. Show Year-wise Average CGPA\n");
    printf("4. Display All Students\n");
    printf("5. Delete Student\n");
    printf("6. Sort by SAP ID\n");
    printf("7. Sort by Name\n");
    printf("8. Exit\n");
}

void add_student() {
    if(student_count >= MAX_STUDENTS) {
        printf("Maximum student capacity reached!\n");
        return;
    }

    Student new_student;

    printf("\nEnter SAP ID: ");
    scanf("%d", &new_student.sap_id);
    clear_input_buffer();

    // Check for duplicate SAP ID
    for(int i = 0; i < student_count; i++) {
        if(students[i].sap_id == new_student.sap_id) {
            printf("Student with this SAP ID already exists!\n");
            return;
        }
    }

    printf("Enter Roll No: ");
    scanf("%d", &new_student.roll_no);
    clear_input_buffer();

    printf("Enter Full Name: ");
    fgets(new_student.name, MAX_NAME_LENGTH, stdin);
    new_student.name[strcspn(new_student.name, "\n")] = '\0';

    printf("Enter Phone Number: ");
    fgets(new_student.phone, MAX_PHONE_LENGTH, stdin);
    new_student.phone[strcspn(new_student.phone, "\n")] = '\0';

    printf("Enter Email ID: ");
    fgets(new_student.email, MAX_EMAIL_LENGTH, stdin);
    new_student.email[strcspn(new_student.email, "\n")] = '\0';

    printf("Enter Current Year (1-4): ");
    scanf("%d", &new_student.year);
    clear_input_buffer();

    printf("Enter Current Semester (1-8): ");
    scanf("%d", &new_student.semester);
    clear_input_buffer();

    printf("Enter SGPA for 8 semesters (space separated): ");
    for(int i = 0; i < SEMESTERS; i++) {
        scanf("%f", &new_student.sgpas[i]);
    }
    clear_input_buffer();

    students[student_count++] = new_student;
    printf("Student added successfully!\n");
}

void search_student() {
    int search_id;
    printf("Enter SAP ID to search: ");
    scanf("%d", &search_id);
    clear_input_buffer();

    for(int i = 0; i < student_count; i++) {
        if(students[i].sap_id == search_id) {
            display_student(students[i]);
            printf("CGPA: %.2f\n", calculate_cgpa(students[i]));
            return;
        }
    }
    printf("Student not found!\n");
}

float calculate_cgpa(Student s) {
    float total = 0;
    for(int i = 0; i < SEMESTERS; i++) {
        total += s.sgpas[i];
    }
    return total / SEMESTERS;
}

void display_student(Student s) {
    printf("\nSAP ID: %d\n", s.sap_id);
    printf("Roll No: %d\n", s.roll_no);
    printf("Name: %s\n", s.name);
    printf("Phone: %s\n", s.phone);
    printf("Email: %s\n", s.email);
    printf("Year: %d\n", s.year);
    printf("Semester: %d\n", s.semester);
    printf("SGPAs: ");
    for(int i = 0; i < SEMESTERS; i++) {
        printf("%.2f ", s.sgpas[i]);
    }
    printf("\n");
}

void show_year_avg() {
    int year_total[4] = {0};
    float cgpa_total[4] = {0};

    for(int i = 0; i < student_count; i++) {
        int year_index = students[i].year - 1;
        if(year_index >= 0 && year_index < 4) {
            year_total[year_index]++;
            cgpa_total[year_index] += calculate_cgpa(students[i]);
        }
    }

    printf("\nYear-wise Average CGPA:\n");
    for(int i = 0; i < 4; i++) {
        if(year_total[i] > 0) {
            printf("Year %d: %.2f\n", i+1, cgpa_total[i]/year_total[i]);
        } else {
            printf("Year %d: No students\n", i+1);
        }
    }
}

void display_all() {
    printf("\nAll Student Records:\n");
    for(int i = 0; i < student_count; i++) {
        display_student(students[i]);
        printf("----------------------------\n");
    }
}

void delete_student() {
    int delete_id;
    printf("Enter SAP ID to delete: ");
    scanf("%d", &delete_id);
    clear_input_buffer();

    for(int i = 0; i < student_count; i++) {
        if(students[i].sap_id == delete_id) {
            // Shift remaining elements
            for(int j = i; j < student_count-1; j++) {
                students[j] = students[j+1];
            }
            student_count--;
            printf("Student deleted successfully!\n");
            return;
        }
    }
    printf("Student not found!\n");
}

int compare_sap(const void *a, const void *b) {
    Student *s1 = (Student *)a;
    Student *s2 = (Student *)b;
    return s1->sap_id - s2->sap_id;
}

void sort_by_sap() {
    qsort(students, student_count, sizeof(Student), compare_sap);
    printf("Records sorted by SAP ID!\n");
    display_all();
}

int compare_name(const void *a, const void *b) {
    Student *s1 = (Student *)a;
    Student *s2 = (Student *)b;
    return strcmp(s1->name, s2->name);
}

void sort_by_name() {
    qsort(students, student_count, sizeof(Student), compare_name);
    printf("Records sorted by Name!\n");
    display_all();
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
