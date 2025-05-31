#include <stdio.h>

struct Student {
    char name[50];
    int roll_no;
    float mark;
};

void readStudent(struct Student *s) {
    printf("Enter name: ");
    scanf("%s", s->name);
    printf("Enter roll no: ");
    scanf("%d", &s->roll_no);
    printf("Enter mark: ");
    scanf("%f", &s->mark);
}

void displayStudent(struct Student s) {
    printf("Name: %s, Roll No: %d, Mark: %.2f\n", s.name, s.roll_no, s.mark);
}

int main() {
    struct Student s;
    readStudent(&s);
    displayStudent(s);
    return 0;
}
