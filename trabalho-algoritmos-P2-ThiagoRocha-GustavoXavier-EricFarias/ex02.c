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

void insertNodeStart(List *L, Node *n);
void insertIntStart(List *L, int n);
void print(List *L);
void removeDuplicates(List *L);

void insertNodeStart(List *L, Node *n) {
    n->next = L->start;
    L->start = n;
}

void insertIntStart(List *L, int n) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = n;
    insertNodeStart(L, node);
}

void print(List *L) {
    Node *current = L->start;
    while(current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void removeDuplicates(List *L) {
    Node *current1 = L->start;
    Node *before, *current2;
    Node *rm;
    while(current1) {
        before = current1;
        current2 = current1->next;
        while(current2) {
            if(current2->data == current1->data) {
                rm = current2;
                before->next = current2->next;
                free(rm);
                current2 = before->next;
            } else {
                before = current2;
                current2 = current2->next;
            }
        }
        current1 = current1->next;
    }
}

int main() {
    int i;
    int l[] = {88, 3, 57, 23, 489, 3, 89, 57, 23, 57, 1};
    List *L = (List*)malloc(sizeof(List));
    for(i=0; i<sizeof(l)/sizeof(int); i++) {
        insertIntStart(L, l[i]);
    }
    printf("\nLista origem:\t");
    print(L);
    removeDuplicates(L);
    printf("\nResultado:\t");
    print(L);
    printf("\n");
    free(L);
    return 0;
}
