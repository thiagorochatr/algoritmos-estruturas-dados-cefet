// TRABALHO P2 - ALGORITMOS E ESTRUTURAS DE DADOS - CEFET
// THIAGO ROCHA DUARTE
// GUSTAVO XAVIER SALDANHA
// ERIC MATHEUS FARIAS PINHEIRO

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *start;
} List;

void insertNodeStart(List *L, Node *n) {
    n->next = L->start;
    L->start = n;
}

void insertIntStart(List *L, int n) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = n;

    insertNodeStart(L, node);
}

void printList(List *L) {
    Node *current = L->start;

    while(current) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
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
    int l[] = {4, 35, 769, 46, 89, 276, 581};

    List *L2;
    List *L = (List*)malloc(sizeof(List));
    
    for(i=0; i<sizeof(l)/sizeof(int); i++) {
        insertIntStart(L, l[i]);
    }

    printf("\nLista L:\t");
    printList(L);
    L2 = order(L);
    printf("\nLista K:\t");
    printList(L2);
    printf("\nLista L final:\t");
    printList(L);
    printf("\n");
    free(L);
    free(L2);
    return 0;
}
