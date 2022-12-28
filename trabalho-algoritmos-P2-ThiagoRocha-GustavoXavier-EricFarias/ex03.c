// TRABALHO P2 - ALGORITMOS E ESTRUTURAS DE DADOS - CEFET
// THIAGO ROCHA DUARTE
// GUSTAVO XAVIER SALDANHA
// ERIC MATHEUS FARIAS PINHEIRO

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    double data;
    struct node *next;
} Node;

typedef struct {
    Node *start;
} List;

void insertNodeStart(List *L, Node *n);
void insertDoubleStart(List *L, double n);
void printList(List *L);
List *join(List *L, List *J);
List *order(List*L);

void insertNodeStart(List *L, Node *n) {
    n->next = L->start;
    L->start = n;
}

void insertDoubleStart(List *L, double n) {
    Node *node = (Node*)malloc(sizeof(Node));                 
    node->data = n;
    insertNodeStart(L, node);
}

void printList(List *L) {
    Node *current = L->start;
    while(current) {
        printf("%lf ", current->data);
        current = current->next;
    }
    printf("\n");
}

List *join(List *L, List *J) {
    Node *pL = L->start, *pJ = J->start;
    List *K = (List*)malloc(sizeof(List));
    Node *last;
    if(pL && pJ) {
        if(pL->data < pJ->data) {
            last = K->start = pL;
            pL = pL->next;
        }
        else {
            last = K->start = pJ;
            pJ = pJ->next;
        }
    } else if(pL) {
        last = K->start = pL;
        pL = pL->next;
    }
    else if(pJ) {
        last = K->start = pJ;
        pL = pL->next;
    }
    while(pL && pJ) {
        if(pL->data < pJ->data) {
            last->next = pL;
            last = pL;
            pL = pL->next;
        }
        else {
            last->next = pJ;
            last = pJ;
            pJ = pJ->next;
        }
    }
    while(pL) {
        last->next = pL;
        last = pL;
        pL = pL->next;
    }
    while(pJ) {
        last->next = pJ;
        last = pJ;
        pJ = pJ->next;
    }
    last->next = 0;
    return K;
}

List *order(List *L) {
    List *L2 = (List*)malloc(sizeof(List));

    Node *greater, *gbefore;
    Node *before, *current;

    while(L->start) {
        greater = L->start;
        gbefore = 0;
        before = L->start;
        current = L->start->next;
        
        while(current) {
            if(current->data > greater->data) {
                gbefore = before;
                greater = current;
            }

            before = current;
            current = current->next;
        }

        if(!gbefore) {
            L->start = L->start->next;
        } else {
            gbefore->next = greater->next;
        }

        insertNodeStart(L2, greater);
    }

    return L2;
}

int main() {
    int i;
    double l[] = {3, 45, 413, 27, 766};
    double j[] = {1201, 4817, 26, 5, 812};
    List *L = (List*)malloc(sizeof(List));
    List *J = (List*)malloc(sizeof(List));
    for(i=0; i<sizeof(l)/sizeof(double); i++) {
        insertDoubleStart(L, l[i]);
    }
    for(i=0; i<sizeof(j)/sizeof(double); i++) {
        insertDoubleStart(J, j[i]);
    }
    List *L_order = order(L);
    List *J_order = order(J);
    printf("Lista 1: ");
    printList(L_order);
    printf("Lista 2: ");
    printList(J_order);
    List *K = join(L_order, J_order);
    printf("Fusão: ");
    printList(K);
    free(L);
    free(J);
    free(K);
    free(L_order);
    free(J_order);
    return 0;
}
