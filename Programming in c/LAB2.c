#include <stdio.h>

struct Student {
    int roll_no;
    char fname[30];
    char lname[30];
};

void sortStudents(struct Student *s, int n) {
    struct Student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i].roll_no > s[j].roll_no) {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

int main() {
    struct Student s[5];
    
    for (int i = 0; i < 5; i++) {
        printf("Enter roll no, first name, last name for student %d: ", i + 1);
        scanf("%d %s %s", &s[i].roll_no, s[i].fname, s[i].lname);
    }
    
    sortStudents(s, 5);
    
    printf("Records in ascending order of roll no:\n");
    for (int i = 0; i < 5; i++) {
        printf("Roll No: %d, First Name: %s, Last Name: %s\n", s[i].roll_no, s[i].fname, s[i].lname);
    }
    
    return 0;
}
