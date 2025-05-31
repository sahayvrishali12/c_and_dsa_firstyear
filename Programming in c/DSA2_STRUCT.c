 666666#include <stdio.h>

//**first part of the code.**

struct student {
    char name[50];
    int roll_no;
    float mark;
    char lastn[50];
};

int main() {
    struct student s;

    /*printf("Enter student name: ");
    fgets(s.name, sizeof(s.name), stdin);*/
    printf("\nStudent name:");
    //scanf (" %s", s[i].name);
    scanf ("%[^\n]%*c", s.name);
    /* printf("Enter student last name: ");
    fgets(s.lastn, sizeof(s.lastn), stdin);*/
    
    printf("\nEnter roll number: ");
    scanf("%d", &s.roll_no);
    
    printf("\nEnter marks: ");
    scanf("%f", &s.mark);


    printf("\nStudent Details:\n\n");
    printf("Name: %s", s.name);
    printf("\nRoll Number: %d\n", s.roll_no);
    printf("Marks: %.2f\n", s.mark);

    return 0;
}
