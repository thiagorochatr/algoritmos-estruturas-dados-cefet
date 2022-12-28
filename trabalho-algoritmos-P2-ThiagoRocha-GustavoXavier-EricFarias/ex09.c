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
    Node *front;
    Node *back;
} Row;

typedef struct {
    Node *top;
} Stack;

Node *createNode(double c);
void insertRow(Row *R, double c);
double removeRow(Row *R);
void insertStack(Stack *S, double c);
double removeStack(Stack *S);
void print(Row *R);
void invert(Row *R);

Node *createNode(double c) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = c;
    node->next = 0;
    return node;
}

void insertRow(Row *R, double c) {
    Node *node = createNode(c);
    if(R->front) {
        R->back->next = node;
        R->back = node;
    } else {
        R->front = R->back = node;
    }
}

double removeRow(Row *R) {
    Node *rm = R->front;
    double c = rm->data;
    R->front = R->front->next;
    free(rm);
    return c;
}

void insertStack(Stack *S, double c) {
    Node *node = createNode(c);
    if(S->top) {
        node->next = S->top;
    }
    S->top = node;
}

double removeStack(Stack *S) {
    Node *rm = S->top;
    double c = rm->data;
    S->top = S->top->next;
    free(rm);
    return c;
}

void print(Row *R) {
    Node *current = R->front;
    while(current) {
        printf("%lf ", current->data);
        current = current->next;
    }
    printf("\n");
}

void invert(Row *R) {
    Stack *S = (Stack*)malloc(sizeof(Stack));
    while(R->front) {
        insertStack(S, removeRow(R)); 
    }
    while(S->top) {
        insertRow(R, removeStack(S));
    }
}

int main() {
    int i;
    double arr[] = {34, 3839, 4, 482, 923, 83};
    Row *R = (Row*)malloc(sizeof(Row));
    for(i=0; i<sizeof(arr)/sizeof(double); i++) {
        insertRow(R, arr[i]);
    }
    printf("Fila original:\t");
    print(R);
    invert(R);
    printf("Fila invertida:\t");
    print(R);
    return 0;
}
