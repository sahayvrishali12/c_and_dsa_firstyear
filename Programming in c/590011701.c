#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// System configuration constants
#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define TOTAL_SEMESTERS 8

typedef struct {
    int sap_id;
    int roll_number;
    char full_name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_LENGTH];
    char email_id[MAX_EMAIL_LENGTH];
    int current_year;
    int current_semester;
    float semester_gpas[TOTAL_SEMESTERS];
} StudentRecord;

StudentRecord student_database[MAX_STUDENTS];
int registered_students = 0;

// Function prototypes
void display_main_menu();
void register_new_student();
void find_student_record();
float calculate_overall_cgpa(StudentRecord student);
void show_student_details(StudentRecord student);
void display_yearwise_performance();
void show_all_records();
void remove_student_entry();
void sort_records_by_sap();
void sort_records_by_name();
void clear_input_buffer();

int main() {
    int user_choice;
    do {
        display_main_menu();
        printf("Enter your choice: ");
        scanf("%d", &user_choice);
        clear_input_buffer();

        switch(user_choice) {
            case 1: register_new_student(); break;
            case 2: find_student_record(); break;
            case 3: display_yearwise_performance(); break;
            case 4: show_all_records(); break;
            case 5: remove_student_entry(); break;
            case 6: sort_records_by_sap(); break;
            case 7: sort_records_by_name(); break;
            case 8: printf("Exiting system...\n"); break;
            default: printf("Invalid selection! Please try again.\n");
        }
    } while(user_choice != 8);
    return 0;
}

void display_main_menu() {
    printf("\nAcademic Records Management System\n");
    printf("1. Register New Student\n");
    printf("2. Search Student Record\n");
    printf("3. Display Year-wise CGPA Averages\n");
    printf("4. Show All Student Entries\n");
    printf("5. Remove Student Entry\n");
    printf("6. Sort Records by SAP ID\n");
    printf("7. Sort Records by Name\n");
    printf("8. Exit System\n");
}

void register_new_student() {
    if(registered_students >= MAX_STUDENTS) {
        printf("Database capacity reached!\n");
        return;
    }

    StudentRecord new_entry;

    // SAP ID validation
    printf("\nEnter SAP ID: ");
    scanf("%d", &new_entry.sap_id);
    clear_input_buffer();
    for(int i = 0; i < registered_students; i++) {
        if(student_database[i].sap_id == new_entry.sap_id) {
            printf("Duplicate SAP ID detected!\n");
            return;
        }
    }

    // Collect student information
    printf("Enter Roll Number: ");
    scanf("%d", &new_entry.roll_number);
    clear_input_buffer();

    printf("Enter Full Name: ");
    fgets(new_entry.full_name, MAX_NAME_LENGTH, stdin);
    new_entry.full_name[strcspn(new_entry.full_name, "\n")] = '\0';

    printf("Enter Contact Number: ");
    fgets(new_entry.phone_number, MAX_PHONE_LENGTH, stdin);
    new_entry.phone_number[strcspn(new_entry.phone_number, "\n")] = '\0';

    printf("Enter Email Address: ");
    fgets(new_entry.email_id, MAX_EMAIL_LENGTH, stdin);
    new_entry.email_id[strcspn(new_entry.email_id, "\n")] = '\0';

    // Academic details with validation
    int valid_year = 0;
    while(!valid_year) {
        printf("Enter Current Academic Year (1-4): ");
        scanf("%d", &new_entry.current_year);
        clear_input_buffer();
        if(new_entry.current_year >= 1 && new_entry.current_year <= 4) {
            valid_year = 1;
        } else {
            printf("Invalid year! Please enter between 1 and 4.\n");
        }
    }

    int valid_semester = 0;
    while(!valid_semester) {
        printf("Enter Current Semester (1-8): ");
        scanf("%d", &new_entry.current_semester);
        clear_input_buffer();
        if(new_entry.current_semester >= 1 && new_entry.current_semester <= 8) {
            valid_semester = 1;
        } else {
            printf("Invalid semester! Please enter between 1 and 8.\n");
        }
    }

    // SGPA input with validation
    printf("Enter SGPA for all 8 semesters (space-separated, values between 0 and 10): ");
    for(int i = 0; i < TOTAL_SEMESTERS; i++) {
        float valid_sgpa = 0;
        while(!valid_sgpa) {
            scanf("%f", &new_entry.semester_gpas[i]);
            clear_input_buffer();
            if(new_entry.semester_gpas[i] >= 0 && new_entry.semester_gpas[i] <= 10) {
                valid_sgpa = 1;
            } else {
                printf("Invalid SGPA! Please enter between 0 and 10 for semester %d.\n", i+1);
            }
        }
    }

    student_database[registered_students++] = new_entry;
    printf("Student registration successful!\n");
}


void find_student_record() {
    int search_sap;
    printf("Enter SAP ID for search: ");
    scanf("%d", &search_sap);
    clear_input_buffer();

    for(int i = 0; i < registered_students; i++) {
        if(student_database[i].sap_id == search_sap) {
            show_student_details(student_database[i]);
            printf("Calculated CGPA: %.2f\n", calculate_overall_cgpa(student_database[i]));
            return;
        }
    }
    printf("No matching record found!\n");
}

float calculate_overall_cgpa(StudentRecord student) {
    float cumulative_score = 0;
    for(int i = 0; i < TOTAL_SEMESTERS; i++) {
        cumulative_score += student.semester_gpas[i];
    }
    return cumulative_score / TOTAL_SEMESTERS;
}

void show_student_details(StudentRecord student) {
    printf("\nSAP ID: %d\n", student.sap_id);
    printf("Roll Number: %d\n", student.roll_number);
    printf("Student Name: %s\n", student.full_name);
    printf("Contact Number: %s\n", student.phone_number);
    printf("Email Address: %s\n", student.email_id);
    printf("Academic Year: %d\n", student.current_year);
    printf("Current Semester: %d\n", student.current_semester);
    printf("Semester GPAs: ");
    for(int i = 0; i < TOTAL_SEMESTERS; i++) {
        printf("%.2f ", student.semester_gpas[i]);
    }
    printf("\n");
}

void display_yearwise_performance() {
    int students_per_year[4] = {0};
    float cgpa_accumulator[4] = {0};

    for(int i = 0; i < registered_students; i++) {
        int year_index = student_database[i].current_year - 1;
        if(year_index >= 0 && year_index < 4) {
            students_per_year[year_index]++;
            cgpa_accumulator[year_index] += calculate_overall_cgpa(student_database[i]);
        }
    }

    printf("\nAcademic Year Performance Overview:\n");
    for(int i = 0; i < 4; i++) {
        if(students_per_year[i] > 0) {
            printf("Year %d Average CGPA: %.2f\n", i+1, cgpa_accumulator[i]/students_per_year[i]);
        } else {
            printf("Year %d: No enrolled students\n", i+1);
        }
    }
}

void show_all_records() {
    printf("\nComplete Student Database:\n");
    for(int i = 0; i < registered_students; i++) {
        show_student_details(student_database[i]);
        printf("----------------------------------------\n");
    }
}

void remove_student_entry() {
    int target_sap;
    printf("Enter SAP ID for deletion: ");
    scanf("%d", &target_sap);
    clear_input_buffer();

    for(int i = 0; i < registered_students; i++) {
        if(student_database[i].sap_id == target_sap) {
            // Shift subsequent entries to maintain continuity
            for(int j = i; j < registered_students-1; j++) {
                student_database[j] = student_database[j+1];
            }
            registered_students--;
            printf("Student record successfully removed!\n");
            return;
        }
    }
    printf("No matching record found for deletion!\n");
}

// Comparator for SAP ID sorting (ascending)
int compare_sap_ids(const void *first_record, const void *second_record) {
    StudentRecord *record_a = (StudentRecord *)first_record;
    StudentRecord *record_b = (StudentRecord *)second_record;
    return record_a->sap_id - record_b->sap_id;
}

void sort_records_by_sap() {
    qsort(student_database, registered_students, sizeof(StudentRecord), compare_sap_ids);
    printf("Records sorted by SAP ID:\n");
    show_all_records();
}

// Comparator for name sorting (alphabetical)
int compare_student_names(const void *first_record, const void *second_record) {
    StudentRecord *record_a = (StudentRecord *)first_record;
    StudentRecord *record_b = (StudentRecord *)second_record;
    return strcmp(record_a->full_name, record_b->full_name);
}

void sort_records_by_name() {
    qsort(student_database, registered_students, sizeof(StudentRecord), compare_student_names);
    printf("Records sorted alphabetically:\n");
    show_all_records();
}

// Clear residual input to prevent scan issues
void clear_input_buffer() {
    int buffer_char;
    while ((buffer_char = getchar()) != '\n' && buffer_char != EOF);
}
