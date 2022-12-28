// TRABALHO P2 - ALGORITMOS E ESTRUTURAS DE DADOS - CEFET
// THIAGO ROCHA DUARTE
// GUSTAVO XAVIER SALDANHA
// ERIC MATHEUS FARIAS PINHEIRO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef struct node {
    char data;
    struct node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

void insertStack(Stack *S, char c);
char removeStack(Stack *S);
bool palindrome(const char *s);


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

bool palindrome(const char *s) {
    int i;
    int n = strlen(s);
    Stack *S = (Stack*)malloc(sizeof(Stack));
    for(i=0; i<n/2; i++) {
        insertStack(S, s[i]);
    }
    for(i+=n%2; s[i]; i++) {
        if(s[i] != removeStack(S)) {
            return false;
        }
    }
    return true;
}

int main() {
    int i;
    const char * testes[] = {"ABCBA", "XYZZYX",
                             "CARACOL", "ARARA",
                             "BRASA", "REVIVER", "OXO"};
    for(i=0; i<7; i++) {
        printf("PALAVRA %d\n", i+1);
        printf("%s ", testes[i]);
        if(!palindrome(testes[i])) {
            printf(" não é palindromo\n\n");
        } else {
            printf("é palindromo\n\n");
        }
    }
    return 0;
}
