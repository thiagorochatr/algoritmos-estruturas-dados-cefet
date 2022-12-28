// TRABALHO P2 - ALGORITMOS E ESTRUTURAS DE DADOS - CEFET
// THIAGO ROCHA DUARTE
// GUSTAVO XAVIER SALDANHA
// ERIC MATHEUS FARIAS PINHEIRO

#include <stdio.h>
#include <stdlib.h>

typedef char bool;
const bool false = 0;
const bool true = 1;

typedef struct node {
    char data;
    struct node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

void insertStack(Stack *S, char c) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = c;

    if(S->top) {
        node->next = S->top;
    }
    S->top = node;
}

char removeStack(Stack *S) {
    Node *rm = S->top;
    char c = rm->data;
    S->top = S->top->next;
    free(rm);
    return c;
}

void process(char *s) {
    int i;
    Stack *S = (Stack*)malloc(sizeof(Stack));

    for(i=0; s[i]; i++) {
        if(s[i] == ' ' || s[i] == '.') {
            while(S->top) {
                printf("%c", removeStack(S));
            }

            printf("%c", s[i]);

            if(s[i] == '.') {
                break;
            }
        } else {
            insertStack(S, s[i]);
        }
    }
        
    printf("\n");
}

int main() {
    int i;
    char test[] = "ESTE EXERCICIO E MUITO FACIL.";
    printf("Input:\t%s\n", test);
    
    printf("Output:\t"); 
    process(test);
    return 0;
}