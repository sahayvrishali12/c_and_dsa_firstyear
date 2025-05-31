#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int d;
    struct Node *n;
} Node;

Node *h = NULL, *t = NULL;

void insBeg(int v) {
    Node *nN = (Node *)malloc(sizeof(Node));
    if (!nN) {
        printf("Memory allocation failed\n");
        return;
    }
    nN->d = v;
    if (!h) {
        h = t = nN;
        t->n = h;
    } else {
        nN->n = h;
        h = nN;
        t->n = h;
    }
    printf("Inserted %d at the beginning.\n", v);
}

void insEnd(int v) {
    Node *nN = (Node *)malloc(sizeof(Node));
    if (!nN) {
        printf("Memory allocation failed\n");
        return;
    }
    nN->d = v;
    nN->n = h;
    if (!h) {
        h = t = nN;
        t->n = h;
    } else {
        t->n = nN;
        t = nN;
    }
    printf("Inserted %d at the end.\n", v);
}

void insPos(int v, int p) {
    if (p < 1) {
        printf("Invalid position.\n");
        return;
    }
    if (p == 1) {
        insBeg(v);
        return;
    }
    Node *tN = h;
    int count = 1;
    while (tN && count < p - 1) {
        tN = tN->n;
        count++;
    }
    if (!tN || tN == t) {
        printf("Position exceeds list length. Inserting at the end.\n");
        insEnd(v);
        return;
    }
    Node *nN = (Node *)malloc(sizeof(Node));
    if (!nN) {
        printf("Memory allocation failed\n");
        return;
    }
    nN->d = v;
    nN->n = tN->n;
    tN->n = nN;
    printf("Inserted %d at position %d.\n", v, p);
}

void delBeg() {
    if (!h) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    Node *tN = h;
    if (h == t) {
        h = t = NULL;
    } else {
        h = h->n;
        t->n = h;
    }
    printf("Deleted %d from the beginning.\n", tN->d);
    free(tN);
}

void delEnd() {
    if (!h) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    if (h == t) {
        delBeg();
        return;
    }
    Node *tN = h;
    while (tN->n != t) {
        tN = tN->n;
    }
    printf("Deleted %d from the end.\n", t->d);
    free(t);
    t = tN;
    t->n = h;
}

void delPos(int p) {
    if (p < 1) {
        printf("Invalid position.\n");
        return;
    }
    if (p == 1) {
        delBeg();
        return;
    }
    Node *tN = h;
    int count = 1;
    while (tN->n && count < p - 1) {
        tN = tN->n;
        count++;
    }
    if (!tN->n || tN->n == h) {
        printf("Position exceeds list length. No deletion performed.\n");
        return;
    }
    Node *dN = tN->n;
    printf("Deleted %d from position %d.\n", dN->d, p);
    tN->n = dN->n;
    if (dN == t) {
        t = tN;
    }
    free(dN);
}

void search(int v) {
    if (!h) {
        printf("List is empty. Nothing to search.\n");
        return;
    }
    Node *tN = h;
    int i = 1;
    do {
        if (tN->d == v) {
            printf("Element %d found at position %d.\n", v, i);
            return;
        }
        tN = tN->n;
        i++;
    } while (tN != h);
    printf("Element %d not found in the list.\n", v);
}

void rev() {
    if (!h || h == t) {
        printf("List is empty or has only one element. No need to reverse.\n");
        return;
    }
    Node *p = NULL, *c = h, *n;
    do {
        n = c->n;
        c->n = p;
        p = c;
        c = n;
    } while (c != h);
    t = h;
    h = p;
    t->n = h;
    printf("List reversed successfully.\n");
}

void disp() {
    if (!h) {
        printf("List is empty.\n");
        return;
    }
    printf("Circular Linked List: ");
    Node *tN = h;
    do {
        printf("%d ", tN->d);
        tN = tN->n;
    } while (tN != h);
    printf("\n");
}

int main() {
    int ch, v, p;
    do {
        printf("\n--- Circular Linked List Operations ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Search Element\n");
        printf("8. Reverse List\n");
        printf("9. Display List\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &ch) != 1) {
            printf("Invalid input. Please enter a number.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }

        switch (ch) {
            case 1: 
                printf("Enter value to insert at beginning: ");
                scanf("%d", &v);
                insBeg(v);
                break;
            case 2: 
                printf("Enter value to insert at end: ");
                scanf("%d", &v);
                insEnd(v);
                break;
            case 3: 
                printf("Enter value and position: ");
                scanf("%d %d", &v, &p);
                insPos(v, p);
                break;
            case 4: 
                delBeg();
                break;
            case 5: 
                delEnd();
                break;
            case 6: 
                printf("Enter position to delete: ");
                scanf("%d", &p);
                delPos(p);
                break;
            case 7: 
                printf("Enter value to search: ");
                scanf("%d", &v);
                search(v);
                break;
            case 8: 
                rev();
                break;
            case 9: 
                disp();
                break;
            case 10: 
                printf("Exiting program. Freeing memory...\n");
                while (h) {
                    Node *tN = h;
                    h = h->n;
                    free(tN);
                }
                printf("Memory freed. Goodbye!\n");
                break;
            default: 
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (ch != 10);

    return 0;
}
