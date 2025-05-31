#include <stdio.h>
#include <stdlib.h>

struct P {
    int c, e;
    struct P* n;
};

struct P* add(struct P* p1, struct P* p2) {
    struct P *r = NULL, **t = &r;
    while (p1 || p2) {
        struct P* nn = (struct P*)malloc(sizeof(struct P));
        if (!p2 || (p1 && p1->e > p2->e)) {
            nn->c = p1->c; nn->e = p1->e; p1 = p1->n;
        } else if (!p1 || (p2 && p2->e > p1->e)) {
            nn->c = p2->c; nn->e = p2->e; p2 = p2->n;
        } else {
            nn->c = p1->c + p2->c; nn->e = p1->e; p1 = p1->n; p2 = p2->n;
        }
        nn->n = NULL; *t = nn; t = &nn->n;
    }
    return r;
}

struct P* sub(struct P* p1, struct P* p2) {
    struct P *r = NULL, **t = &r;
    while (p1 || p2) {
        struct P* nn = (struct P*)malloc(sizeof(struct P));
        if (!p2 || (p1 && p1->e > p2->e)) {
            nn->c = p1->c; nn->e = p1->e; p1 = p1->n;
        } else if (!p1 || (p2 && p2->e > p1->e)) {
            nn->c = -p2->c; nn->e = p2->e; p2 = p2->n;
        } else {
            nn->c = p1->c - p2->c; nn->e = p1->e; p1 = p1->n; p2 = p2->n;
        }
        nn->n = NULL; *t = nn; t = &nn->n;
    }
    return r;
}

struct P* mul(struct P* p1, struct P* p2) {
    struct P* r = NULL;
    for (; p1; p1 = p1->n) {
        struct P* t2 = p2, *temp = NULL, **t = &temp;
        while (t2) {
            struct P* nn = (struct P*)malloc(sizeof(struct P));
            nn->c = p1->c * t2->c; nn->e = p1->e + t2->e; nn->n = NULL;
            *t = nn; t = &nn->n; t2 = t2->n;
        }
        r = add(r, temp);
    }
    return r;
}

void trav(struct P* p) {
    while (p) {
        printf("%dx^%d ", p->c, p->e);
        p = p->n;
    }
    printf("\n");
}

struct P* inp() {
    struct P *h = NULL, **t = &h;
    int n, c, e;
    printf("Terms: "); scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        struct P* nn = (struct P*)malloc(sizeof(struct P));
        printf("Coeff Exp: "); scanf("%d %d", &c, &e);
        nn->c = c; nn->e = e; nn->n = NULL; *t = nn; t = &nn->n;
    }
    return h;
}

void menu() {
    int c;
    struct P *p1 = NULL, *p2 = NULL;
    while (1) {
        printf("\n1. Input P1\n2. Input P2\n3. Add\n4. Subtract\n5. Multiply\n6. Exit\nChoice: ");
        scanf("%d", &c);
        switch (c) {
            case 1: p1 = inp(); break;
            case 2: p2 = inp(); break;
            case 3: trav(add(p1, p2)); break;
            case 4: trav(sub(p1, p2)); break;
            case 5: trav(mul(p1, p2)); break;
            case 6: exit(0);
            default: printf("Invalid!\n");
        }
    }
}

int main() {
    menu();
    return 0;
}
