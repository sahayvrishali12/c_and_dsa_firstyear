#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtPosition(int data, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }
    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid Position\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFromBeginning() {
    if (head == NULL) return;
    struct Node* temp = head;
    head = head->next;
    free(temp);
}

void deleteFromEnd() {
    if (head == NULL) return;
    struct Node* temp = head, *prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL) {
        head = NULL;
    } else {
        prev->next = NULL;
    }
    free(temp);
}

void deleteFromPosition(int position) {
    if (head == NULL) return;
    struct Node* temp = head;
    if (position == 1) {
        head = head->next;
        free(temp);
        return;
    }
    struct Node* prev = NULL;
    for (int i = 1; temp != NULL && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

void searchElement(int key) {
    struct Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element found at position %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Element not found\n");
}

void reverseList() {
    struct Node *prev = NULL, *current = head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}


int compareInts(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void mergeWithArray() {
    // Create temporary array
    int values[1000];
    int count = 0;
    
    // Store first list elements
    struct Node* current = head;
    while(current != NULL) {
        values[count++] = current->data;
        current = current->next;
    }
    
    // Create second list
    struct Node* second_head = NULL;
    int n, data;
    printf("Enter number of elements in second list: ");
    scanf("%d", &n);
    
    for(int i=0; i<n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &data);
        
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->next = NULL;
        
        // Maintain sorted insertion for second list
        if(second_head == NULL) {
            second_head = new_node;
        } else {
            struct Node *curr = second_head, *prev = NULL;
            while(curr && curr->data < data) {
                prev = curr;
                curr = curr->next;
            }
            if(prev == NULL) {
                new_node->next = second_head;
                second_head = new_node;
            } else {
                prev->next = new_node;
                new_node->next = curr;
            }
        }
    }
    
    // Add second list elements to array
    current = second_head;
    while(current != NULL) {
        values[count++] = current->data;
        current = current->next;
    }
    
    // Sort combined array
    qsort(values, count, sizeof(int), compareInts);
    
    // Rebuild merged list
    struct Node* merged_head = NULL;
    struct Node* tail = NULL;
    
    for(int i=0; i<count; i++) {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = values[i];
        new_node->next = NULL;
        
        if(merged_head == NULL) {
            merged_head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }
    
    // Cleanup and update
    current = head;
    while(current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    
    current = second_head;
    while(current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    
    head = merged_head;
    printf("Lists merged and sorted successfully!\n");
}

void traverseList() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void detectLoop() {
    struct Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            printf("Loop detected in the linked list\n");
            return;
        }
    }
    printf("No loop detected\n");
}

void menu() {
    int choice, data, pos;
    while (1) {
       printf("\n1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n4. Delete from Beginning\n5. Delete from End\n6. Delete from Position\n7. Search Element\n8. Reverse List\n9. Merge with another linked list\n10. Traverse List\n11. Detect Loop\n12. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &pos);
                insertAtPosition(data, pos);
                break;
            case 4:
                deleteFromBeginning();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteFromPosition(pos);
                break;
            case 7:
                printf("Enter element to search: ");
                scanf("%d", &data);
                searchElement(data);
                break;
            case 8:
                reverseList();
                break;
            case 9: 
                mergeWithArray();
                break;
            case 10:
                traverseList();
                break;
            case 11:
                detectLoop();
                break;
            case 12:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}

int main() {
    menu();
    return 0;
}
