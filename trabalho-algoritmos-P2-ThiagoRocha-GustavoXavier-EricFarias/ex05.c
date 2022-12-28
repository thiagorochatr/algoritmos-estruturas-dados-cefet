// TRABALHO P2 - ALGORITMOS E ESTRUTURAS DE DADOS - CEFET
// THIAGO ROCHA DUARTE
// GUSTAVO XAVIER SALDANHA
// ERIC MATHEUS FARIAS PINHEIRO

#include <stdio.h>
#include <stdlib.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef struct node {
    char data;
    struct node *prox;
} Node;

typedef struct {
    Node *front;
    Node *back;
} Row;

typedef struct {
    Node *top;
} Stack;

typedef struct {
    Node *start;
    Node *end;
} List;

bool isChar(char c);
Node *createNode(char c);
void insertList(List *L, char c);
void insertRow(Row *R, char c);
char removeRow(Row *R);
void insertStack(Stack *S, char c);
char removeStack(Stack *S);
void print(List *L);
List *order(List *L);

bool isChar(char c) {
    int i;
    for(i=0; i<10; i++) {
        if(c == '0'+i) {
            return true;
        }
    }
    return false;
}

Node *createNode(char c) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = c;
    node->prox = 0;
    return node;
}

void insertList(List *L, char c) {
    Node *node = createNode(c);
    if(L->end) {
        L->end->prox = node;
        L->end = node;
    } else {
        L->start = L->end = node;
    }
}

void insertRow(Row *R, char c) {
    Node *node = createNode(c);
    if(R->front) {
        R->back->prox = node;
        R->back = node;
    } else {
        R->front = R->back = node;
    }
}

char removeRow(Row *R) {
    Node *rm = R->front;
    char c = rm->data;
    R->front = R->front->prox;
    free(rm);
    return c;
}

void insertStack(Stack *S, char c) {
    Node *node = createNode(c);
    if(S->top) {
        node->prox = S->top;
    }
    S->top = node;
}

char removeStack(Stack *S) {
    Node *rm = S->top;
    char c = rm->data;
    S->top = S->top->prox;
    free(rm);
    return c;
}

void print(List *L) {
    Node *current = L->start;
    while(current) {
        printf("%c ", current->data);
        current = current->prox;
    }
    printf("\n");
}

List *order(List *L) {
    List *K = (List*)malloc(sizeof(List));
    Stack *S = (Stack*)malloc(sizeof(Stack));
    Row *R = (Row*)malloc(sizeof(Row));
    Node *current = L->start;
    char c;
    while(current) {
        c = current->data;
        if(isChar(c)) {
            insertStack(S, c);
        } else {
            insertRow(R, c);
        }
        current = current->prox;
    }
    while(R->front) {
        insertList(K, removeRow(R));
    }
    while(S->top) {
        insertList(K, removeStack(S));
    }
    return K;
}

int main() {
    int i;
    List *L = (List*)malloc(sizeof(List));
    char test1[] = "T67HI23AG9O";
    char test2[] = "GU76ST0A7V99O0";
    List *K;
    for(i=0; test1[i]; i++) {
        insertList(L, test1[i]);
    }
    printf("Lista 1\n");
    printf("Lista inicial:\t");
    print(L);
    K = order(L);
    printf("Resultado:\t");
    print(K);
    printf("\n");
    L->start = L->end = 0;
    for(i=0; test2[i]; i++) {
        insertList(L, test2[i]);
    }
    printf("Lista 2\n");
    printf("Lista inicial:\t");
    print(L);
    K = order(L);
    printf("Resultado:\t");
    print(K);
    printf("\n");
    return 0;
}
