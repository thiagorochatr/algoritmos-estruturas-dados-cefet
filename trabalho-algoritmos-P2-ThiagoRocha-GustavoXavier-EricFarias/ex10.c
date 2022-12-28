// TRABALHO P2 - ALGORITMOS E ESTRUTURAS DE DADOS - CEFET
// THIAGO ROCHA DUARTE
// GUSTAVO XAVIER SALDANHA
// ERIC MATHEUS FARIAS PINHEIRO

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

void insertStack(Stack *S, char c);
char removeStack(Stack *S);
void print(Stack *S);
Stack *changeBase(int n, int b);

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
    int c = rm->data;
    S->top = S->top->next;
    free(rm);
    return c;
}

void print(Stack *S) {
    while(S->top) {
        printf("%c", removeStack(S));
    }
    printf("\n");
}

Stack *changeBase(int n, int b) {
    Stack *S = (Stack*)malloc(sizeof(Stack));
    int r;
    while(n >= b) {
        r = n % b;
        if(r < 10) {
            insertStack(S, '0'+r);
        } else {
            insertStack(S, 'a'+(r-10));
        }
        n /= b;
    }
    if(n < 10) {
        insertStack(S, '0'+n);
    } else {
        insertStack(S, 'a'+(n-10));
    }
    return S;
}

int main() {
    int i;
    int n;
    int option;
    int bases[] = {2, 8, 16};
    Stack *S;
    printf("\nInsira um número na base 10: ");
    scanf(" %d", &n);
    do {
        printf("\n1 - Decimal para Binário - base 2;\n");
        printf("2 - Decimal para Octal - base 8;\n");
        printf("3 - Decimal para Hexadecimal - base 16;\n");
        printf("4 - Sair.\n");
        printf("\nEscolha a opcao: ");
        scanf(" %d", &option);
        if(option == 1 || option == 2 || option == 3) {
            S = changeBase(n, bases[option-1]);
            printf("\n%d (base 10) na base %d é ", n, bases[option-1]);
            print(S);
            free(S);
        }
    } while (option == 1 || option == 2 || option == 3);
    return 0;
}