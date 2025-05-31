#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

void insertAtBeginning(Node** head, int data);
void insertAtEnd(Node** head, int data);
void insertAtPosition(Node** head, int data, int position);
void deleteFromBeginning(Node** head);
void deleteFromEnd(Node** head);
void deleteFromPosition(Node** head, int position);
int search(Node* head, int key);
void display(Node* head);

int main() {
    Node* head = NULL;
    int choice, data, position;

    do {
        printf("\nDoubly Linked List Menu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Search an Element\n");
        printf("8. Display List\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &position);
                insertAtPosition(&head, data, position);
                break;
            case 4:
                deleteFromBeginning(&head);
                break;
            case 5:
                deleteFromEnd(&head);
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &position);
                deleteFromPosition(&head, position);
                break;
            case 7:
                printf("Enter element to search: ");
                scanf("%d", &data);
                if (search(head, data))
                    printf("Element found.\n");
                else
                    printf("Element not found.\n");
                break;
            case 8:
                display(head);
                break;
            case 9:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 9);

    return 0;
}

void insertAtBeginning(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = *head;
    if (*head) (*head)->prev = newNode;
    *head = newNode;
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (!*head) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtPosition(Node** head, int data, int position) {
    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }
    Node* temp = *head;
    for (int i = 1; temp && i < position - 1; i++) temp = temp->next;
    if (!temp) {
        printf("Invalid position!\n");
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next) temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteFromBeginning(Node** head) {
    if (!*head) {
        printf("List is empty!\n");
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    if (*head) (*head)->prev = NULL;
    free(temp);
}

void deleteFromEnd(Node** head) {
    if (!*head) {
        printf("List is empty!\n");
        return;
    }
    Node* temp = *head;
    while (temp->next) temp = temp->next;
    if (temp->prev) temp->prev->next = NULL;
    else *head = NULL;
    free(temp);
}

void deleteFromPosition(Node** head, int position) {
    if (position == 1) {
        deleteFromBeginning(head);
        return;
    }
    Node* temp = *head;
    for (int i = 1; temp && i < position; i++) temp = temp->next;
    if (!temp) {
        printf("Invalid position!\n");
        return;
    }
    if (temp->prev) temp->prev->next = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    free(temp);
}

int search(Node* head, int key) {
    Node* temp = head;
    while (temp) {
        if (temp->data == key) return 1;
        temp = temp->next;
    }
    return 0;
}

void display(Node* head) {
    if (!head) {
        printf("List is empty!\n");
        return;
    }
    Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

