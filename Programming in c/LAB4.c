#include <stdio.h>
#include <string.h>

struct employee {
    char name[50];
    char address[100];
    float salary;
};

void sort_employees(struct employee *e, int n) {
    struct employee temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(e[i].name, e[j].name) > 0) {
                temp = e[i];
                e[i] = e[j];
                e[j] = temp;
            }
        }
    }
}

int main() {
    struct employee e[5];
    
    for (int i = 0; i < 5; i++) {
        printf("Enter name for employee %d: ", i + 1);
        fgets(e[i].name, sizeof(e[i].name), stdin);
        e[i].name[strcspn(e[i].name, "\n")] = '\0'; // Remove newline character

        printf("Enter address for employee %d: ", i + 1);
        fgets(e[i].address, sizeof(e[i].address), stdin);
        e[i].address[strcspn(e[i].address, "\n")] = '\0'; // Remove newline character

        printf("Enter salary for employee %d: ", i + 1);
        scanf("%f", &e[i].salary);
        getchar(); // Consume newline character left by scanf
    }
    
    sort_employees(e, 5);
    
    printf("Employee Information in alphabetical order:\n");
    
    for (int i = 0; i < 5; i++) {
        printf("Name: %s, Address: %s, Salary: %.2f\n", e[i].name, e[i].address, e[i].salary);
    }
    
    return 0;
}
