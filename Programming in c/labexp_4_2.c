#include <stdio.h>
#include <stdlib.h>

struct N {
    int d;
    struct N* n;
};

struct N* h = NULL;

void insBeg(int d) {
    struct N* nn = (struct N*)malloc(sizeof(struct N));
    nn->d = d;
    nn->n = h;
    h = nn;
}

void insEnd(int d) {
    struct N* nn = (struct N*)malloc(sizeof(struct N));
    nn->d = d;
    nn->n = NULL;
    if (!h) {
        h = nn;
        return;
    }
    struct N* t = h;
    while (t->n) t = t->n;
    t->n = nn;
}

void insPos(int d, int p) {
    struct N* nn = (struct N*)malloc(sizeof(struct N));
    nn->d = d;
    if (p == 1) {
        nn->n = h;
        h = nn;
        return;
    }
    struct N* t = h;
    for (int i = 1; t && i < p - 1; i++) t = t->n;
    if (!t) return;
    nn->n = t->n;
    t->n = nn;
}

void delBeg() {
    if (!h) return;
    struct N* t = h;
    h = h->n;
    free(t);
}

void delEnd() {
    if (!h) return;
    struct N* t = h, *p = NULL;
    while (t->n) {
        p = t;
        t = t->n;
    }
    if (!p) h = NULL;
    else p->n = NULL;
    free(t);
}

void delPos(int p) {
    if (!h) return;
    struct N* t = h;
    if (p == 1) {
        h = h->n;
        free(t);
        return;
    }
    struct N* pN = NULL;
    for (int i = 1; t && i < p; i++) {
        pN = t;
        t = t->n;
    }
    if (!t) return;
    pN->n = t->n;
    free(t);
}

void search(int k) {
    struct N* t = h;
    int p = 1;
    while (t) {
        if (t->d == k) {
            printf("Found at %d\n", p);
            return;
        }
        t = t->n;
        p++;
    }
    printf("Not found\n");
}

void rev() {
    struct N *p = NULL, *c = h, *n = NULL;
    while (c) {
        n = c->n;
        c->n = p;
        p = c;
        c = n;
    }
    h = p;
}

void trav() {
    struct N* t = h;
    while (t) {
        printf("%d -> ", t->d);
        t = t->n;
    }
    printf("NULL\n");
}

void menu() {
    int c, d, p;
    while (1) {
        printf("\n1. Insert Beg\n2. Insert End\n3. Insert Pos\n4. Delete Beg\n5. Delete End\n6. Delete Pos\n7. Search\n8. Reverse\n9. Traverse\n10. Exit\nChoice: ");
        scanf("%d", &c);
        switch (c) {
            case 1: printf("Data: "); scanf("%d", &d); insBeg(d); break;
            case 2: printf("Data: "); scanf("%d", &d); insEnd(d); break;
            case 3: printf("Data Pos: "); scanf("%d %d", &d, &p); insPos(d, p); break;
            case 4: delBeg(); break;
            case 5: delEnd(); break;
            case 6: printf("Pos: "); scanf("%d", &p); delPos(p); break;
            case 7: printf("Search: "); scanf("%d", &d); search(d); break;
            case 8: rev(); break;
            case 9: trav(); break;
            case 10: exit(0);
            default: printf("Invalid!\n");
        }
    }
}

int main() {
    menu();
    return 0;
}
