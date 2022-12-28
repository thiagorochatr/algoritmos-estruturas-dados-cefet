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
    Node *top;
} Stack;

void insertStack(Stack *S, double x) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = x;
    
    if(S->top) {
        node->next = S->top;
    }
    S->top = node;
}

double removeStack(Stack *S) {
    Node *rm = S->top;
    double n = rm->data;
    S->top = S->top->next;    
    return n;
}

void order(Stack *S) {
    double top;
    Stack *smaller = (Stack*)malloc(sizeof(Stack));
    Stack *bigger = (Stack*)malloc(sizeof(Stack));
    
    while(S->top) {
        top = removeStack(S);
        
        while(smaller->top && smaller->top->data > top) {
            insertStack(bigger, removeStack(smaller));
        }

        while(bigger->top && bigger->top->data < top){
            insertStack(smaller, removeStack(bigger));
        }

        insertStack(smaller, top);
    }
    while(bigger->top) {
        insertStack(smaller, removeStack(bigger));
    }

    while(smaller->top) {
        insertStack(S, removeStack(smaller));
    }
}

void printStack(Stack *S) {
    Node *current = S->top;
    while(current) {
        printf("%.2lf ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int i;
    double p[] = {743, 83, 928, 38, 38, 458, 29, 5};
    
    Stack *S = (Stack*)malloc(sizeof(Stack));

    for(i=0; i<sizeof(p)/sizeof(double); i++) {
        insertStack(S, p[i]);
    }

    printf("Pilha original:\t\t\t"); 
    printStack(S);

    order(S);

    printf("Pilha em ordem crescente:\t"); 
    printStack(S);
    return 0;
}