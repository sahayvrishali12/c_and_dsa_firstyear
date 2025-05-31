#include <stdio.h>

struct employee {
    char name[50];
    char address[100];
    int age;
    float salary;
};

float average_salary(struct employee *e, int n) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += e[i].salary;
    }
    return total / n;
}

int main() {
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);
    getchar(); 
    struct employee e[n];
    
    for (int i = 0; i < n; i++) {
        printf("Enter name for employee %d: ", i + 1);
        fgets(e[i].name, sizeof(e[i].name), stdin);
        
        printf("Enter address for employee %d: ", i + 1);
        fgets(e[i].address, sizeof(e[i].address), stdin);
        
        printf("Enter age and salary for employee %d: ", i + 1);
        scanf("%d %f", &e[i].age, &e[i].salary);
        getchar(); 
    
    printf("Average Salary: %.2f\n", average_salary(e, n));
    
    return 0;
}

