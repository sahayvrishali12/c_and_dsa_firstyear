#include <stdio.h>
#include <string.h>

struct date {
    int day;
    int month;
    int year;
};

struct employee {
    char name[50];
    int id;
    float salary;
    struct date dob;
};

void read_employee(struct employee *e) {
    printf("Enter name: ");
    fgets(e->name, sizeof(e->name), stdin);
    e->name[strcspn(e->name, "\n")] = '\0'; // Remove newline character

    printf("Enter id and salary: ");
    scanf("%d %f", &e->id, &e->salary);
    
    printf("Enter date of birth (dd mm yyyy): ");
    scanf("%d %d %d", &e->dob.day, &e->dob.month, &e->dob.year);
}

void display_employee(struct employee e) {
   printf("Name: %s, ID: %d, DOB: %02d/%02d/%04d, Salary: %.2f\n", 
          e.name, e.id, e.dob.day, e.dob.month, e.dob.year, e.salary);
}

int main() {
   struct employee e;

   read_employee(&e);
   display_employee(e);

   return 0;
}
