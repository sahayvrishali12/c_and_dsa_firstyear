#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int d;
    struct Node *n;
} Node;

Node *h = NULL, *t = NULL;

void insBeg(int v) {
    Node *nN = (Node *)malloc(sizeof(Node));
    nN->d = v;
    if (!h) h = t = nN, t->n = h;
    else nN->n = h, h = nN, t->n = h;
}

void insEnd(int v) {
    Node *nN = (Node *)malloc(sizeof(Node));
    nN->d = v, nN->n = h;
    if (!h) h = t = nN, t->n = h;
    else t->n = nN, t = nN;
}

void insPos(int v, int p) {
    if (p == 1) return insBeg(v);
    Node *tN = h;
    for (int i = 1; tN && i < p - 1; i++) tN = tN->n;
    if (!tN || tN == t) return insEnd(v);
    Node *nN = (Node *)malloc(sizeof(Node));
    nN->d = v, nN->n = tN->n, tN->n = nN;
}

void delBeg() {
    if (!h) return;
    Node *tN = h;
    if (h == t) h = t = NULL;
    else h = h->n, t->n = h;
    free(tN);
}

void delEnd() {
    if (!h) return;
    if (h == t) return delBeg();
    Node *tN = h;
    while (tN->n != t) tN = tN->n;
    free(t), t = tN, t->n = h;
}

void delPos(int p) {
    if (p == 1) return delBeg();
    Node *tN = h;
    for (int i = 1; tN->n && i < p - 1; i++) tN = tN->n;
    if (!tN->n || tN->n == h) return;
    Node *dN = tN->n;
    tN->n = dN->n;
    if (dN == t) t = tN;
    free(dN);
}

void search(int v) {
    Node *tN = h;
    int i = 1;
    if (!h) return printf("Not found\n");
    do {
        if (tN->d == v) return printf("Found at %d\n", i);
        tN = tN->n, i++;
    } while (tN != h);
    printf("Not found\n");
}

void rev() {
    if (!h || h == t) return;
    Node *p = t, *c = h, *n;
    do {
        n = c->n, c->n = p, p = c, c = n;
    } while (c != h);
    t = h, h = p;
}

void disp() {
    if (!h) return printf("Empty\n");
    Node *tN = h;
    do printf("%d ", tN->d), tN = tN->n;
    while (tN != h);
    printf("\n");
}

int main() {
    int ch, v, p;
    do {
        printf("1. InsBeg 2. InsEnd 3. InsPos 4. DelBeg 5. DelEnd 6. DelPos 7. Search 8. Rev 9. Disp 10. Exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1: scanf("%d", &v), insBeg(v); break;
            case 2: scanf("%d", &v), insEnd(v); break;
            case 3: scanf("%d %d", &v, &p), insPos(v, p); break;
            case 4: delBeg(); break;
            case 5: delEnd(); break;
            case 6: scanf("%d", &p), delPos(p); break;
            case 7: scanf("%d", &v), search(v); break;
            case 8: rev(); break;
            case 9: disp(); break;
        }
    } while (ch != 10);
    return 0;
}
