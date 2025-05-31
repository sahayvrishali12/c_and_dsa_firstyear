#include <stdio.h>
#include <string.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Employee {
    
    char name[50];
    char address[100];
    int age;
    float salary;
    struct Date dob;
};

void readEmployee(struct Employee *emp) {
    printf("Enter name, address, age, salary: ");
    scanf("%s %s %d %f", emp->name, emp->address, &emp->age, &emp->salary);
    printf("Enter Date of Birth (dd mm yyyy): ");
    scanf("%d %d %d", &emp->dob.day, &emp->dob.month, &emp->dob.year);
}

void displayEmployee(struct Employee emp) {
   printf("Name: %s, Address: %s, Age: %d, Salary: %.2f, DOB: %02d/%02d/%04d\n", 
          emp.name, emp.address, emp.age, emp.salary, emp.dob.day, emp.dob.month, emp.dob.year);
}

float calculateAverageSalary(struct Employee *emp, int count) {
    float total = 0;
    for (int i = 0; i < count; i++) total += emp[i].salary;
    return total / count;
}

void sortEmployeesByName(struct Employee *emp, int count) {
    struct Employee temp;
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(emp[i].name, emp[j].name) > 0) {
                temp = emp[i];
                emp[i] = emp[j];
                emp[j] = temp;
            }
        }
    }
}

int main() {
   int choice, employeeCount = 0;
   struct Employee employees[5];

   while (1) {
       printf("\n1. Add Employee\n2. Calculate Average Salary\n3. Display Employees\n4. Sort Employees by Name\n5. Exit\nChoose an option: ");
       scanf("%d", &choice);

       switch (choice) {
           case 1:
               if (employeeCount < 5) {
                   readEmployee(&employees[employeeCount]);
                   employeeCount++;
               } else {
                   printf("Max employees reached.\n");
               }
               break;
           case 2:
               if (employeeCount > 0) {
                   printf("Average Salary: %.2f\n", calculateAverageSalary(employees, employeeCount));
               } else {
                   printf("No employees to calculate average salary.\n");
               }
               break;
           case 3:
               for (int i = 0; i < employeeCount; i++) {
                   displayEmployee(employees[i]);
               }
               break;
           case 4:
               sortEmployeesByName(employees, employeeCount);
               printf("Employees sorted by name.\n");
               break;
           case 5:
               return 0;
           default:
               printf("Invalid option.\n");
       }
   }
}
