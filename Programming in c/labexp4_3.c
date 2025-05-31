#include <stdio.h>
#include <stdlib.h>

// Structure for a polynomial term
typedef struct Node {
    int coeff, power;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int coeff, int power) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term at the end
void insertTerm(Node** poly, int coeff, int power) {
    Node* newNode = createNode(coeff, power);
    if (*poly == NULL) {
        *poly = newNode;
        return;
    }
    Node* temp = *poly;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

// Function to print a polynomial
void printPoly(Node* poly) {
    if (!poly) {
        printf("0\n");
        return;
    }
    while (poly) {
        printf("%dx^%d", poly->coeff, poly->power);
        if (poly->next)
            printf(" + ");
        poly = poly->next;
    }
    printf("\n");
}

// Function to add two polynomials
Node* addPoly(Node* p1, Node* p2) {
    Node* result = NULL, **ptr = &result;
    while (p1 && p2) {
        if (p1->power > p2->power) {
            *ptr = createNode(p1->coeff, p1->power);
            p1 = p1->next;
        } else if (p1->power < p2->power) {
            *ptr = createNode(p2->coeff, p2->power);
            p2 = p2->next;
        } else {
            int sum = p1->coeff + p2->coeff;
            if (sum != 0)
                *ptr = createNode(sum, p1->power);
            p1 = p1->next;
            p2 = p2->next;
        }
        if (*ptr) ptr = &((*ptr)->next);
    }
    while (p1) {
        *ptr = createNode(p1->coeff, p1->power);
        p1 = p1->next;
        ptr = &((*ptr)->next);
    }
    while (p2) {
        *ptr = createNode(p2->coeff, p2->power);
        p2 = p2->next;
        ptr = &((*ptr)->next);
    }
    return result;
}

// Function to subtract two polynomials
Node* subtractPoly(Node* p1, Node* p2) {
    Node* result = NULL, **ptr = &result;
    while (p1 && p2) {
        if (p1->power > p2->power) {
            *ptr = createNode(p1->coeff, p1->power);
            p1 = p1->next;
        } else if (p1->power < p2->power) {
            *ptr = createNode(-p2->coeff, p2->power);
            p2 = p2->next;
        } else {
            int diff = p1->coeff - p2->coeff;
            if (diff != 0)
                *ptr = createNode(diff, p1->power);
            p1 = p1->next;
            p2 = p2->next;
        }
        if (*ptr) ptr = &((*ptr)->next);
    }
    while (p1) {
        *ptr = createNode(p1->coeff, p1->power);
        p1 = p1->next;
        ptr = &((*ptr)->next);
    }
    while (p2) {
        *ptr = createNode(-p2->coeff, p2->power);
        p2 = p2->next;
        ptr = &((*ptr)->next);
    }
    return result;
}

// Function to multiply two polynomials
Node* multiplyPoly(Node* p1, Node* p2) {
    if (!p1 || !p2) return NULL;
    Node* result = NULL;
    for (Node* i = p1; i; i = i->next) {
        for (Node* j = p2; j; j = j->next) {
            int coeff = i->coeff * j->coeff;
            int power = i->power + j->power;
            
            Node* temp = result, *prev = NULL;
            while (temp && temp->power > power) {
                prev = temp;
                temp = temp->next;
            }
            if (temp && temp->power == power) {
                temp->coeff += coeff;
                if (temp->coeff == 0) { 
                    if (prev) prev->next = temp->next;
                    else result = temp->next;
                    free(temp);
                }
            } else {
                Node* newNode = createNode(coeff, power);
                newNode->next = temp;
                if (prev) prev->next = newNode;
                else result = newNode;
            }
        }
    }
    return result;
}

// Function to free memory of a polynomial list
void freePoly(Node* poly) {
    while (poly) {
        Node* temp = poly;
        poly = poly->next;
        free(temp);
    }
}

// Function to take input for a polynomial
Node* inputPoly() {
    Node* poly = NULL;
    int n, coeff, power;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and power: ");
        scanf("%d %d", &coeff, &power);
        insertTerm(&poly, coeff, power);
    }
    return poly;
}

// Menu-driven function
void menu() {
    Node *p1 = NULL, *p2 = NULL, *result = NULL;
    int choice;
    while (1) {
        printf("\nPolynomial Operations:\n");
        printf("1. Input First Polynomial\n");
        printf("2. Input Second Polynomial\n");
        printf("3. Add Polynomials\n");
        printf("4. Subtract Polynomials\n");
        printf("5. Multiply Polynomials\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                freePoly(p1);
                printf("Enter first polynomial:\n");
                p1 = inputPoly();
                break;
            case 2:
                freePoly(p2);
                printf("Enter second polynomial:\n");
                p2 = inputPoly();
                break;
            case 3:
                freePoly(result);
                result = addPoly(p1, p2);
                printf("Sum: ");
                printPoly(result);
                break;
            case 4:
                freePoly(result);
                result = subtractPoly(p1, p2);
                printf("Difference: ");
                printPoly(result);
                break;
            case 5:
                freePoly(result);
                result = multiplyPoly(p1, p2);
                printf("Product: ");
                printPoly(result);
                break;
            case 6:
                freePoly(p1);
                freePoly(p2);
                freePoly(result);
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

// Main function
int main() {
    menu();
    return 0;
}
