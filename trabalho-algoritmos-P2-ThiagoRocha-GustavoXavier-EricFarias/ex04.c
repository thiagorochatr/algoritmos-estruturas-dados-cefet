// TRABALHO P2 - ALGORITMOS E ESTRUTURAS DE DADOS - CEFET
// THIAGO ROCHA DUARTE
// GUSTAVO XAVIER SALDANHA
// ERIC MATHEUS FARIAS PINHEIRO

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[256];
} Plane;

typedef struct node {
    Plane data;
    struct node *prox;
} Node;

typedef struct {
    Node *front;
    Node *back;
} Row;

int menu();
void insert(Row *F, Plane n);
Plane removePlane(Row *F);
Plane front(Row *F);
void printRow(Row *L);
int size(Row *F);

int menu() {
    int option;
    printf("\n>>>>>>>> MENU <<<<<<<<\n");
    printf("1 - Listar o número de aviões aguardando na fila de decolagem;\n");
    printf("2 - Autorizar a decolagem do primeiro avião da fila;\n");
    printf("3 - Adicionar um avião à fila de espera;\n");
    printf("4 - Listar todos os aviões na fila de espera;\n");
    printf("5 - Listar as características do primeiro avião da fila;\n");
    printf("6 - Sair.\n");
    do {
        printf("Insira a opção desejada - 1 a 6: ");
        scanf(" %d", &option);
    } while(option < 1 || option > 6);
    return option;
}

void insert(Row *F, Plane n) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = n;
    if(F->back) {
        F->back->prox = node;
        F->back = node;
    } else {
        F->back = F->front = node;
    }
}

Plane removePlane(Row *F) {
    Plane a = F->front->data;
    Node *n = F->front;
    F->front = F->front->prox;
    free(n);
    return a;
}

Plane front(Row *F) {
    return F->front->data;
}

void printRow(Row *F) {
    Node *atual = F->front;
    if(size(F) > 0) {
        printf("INÍCIO DA FILA - ");
        while(atual) {
            printf(" %s(%d)",
            atual->data.name, atual->data.id);
            atual = atual->prox;
        }
        printf("\n");
    } else {
        printf("Não existem aviões na fila.\n\n");
    }
}

int size(Row *F) {
    int tam = 0;
    Node *atual;
    for(atual = F->front; atual; atual = atual->prox) {
        tam++;
    }
    return tam;
}

int main() {
    Row *F = (Row*)malloc(sizeof(Row));
    Plane a;
    int option;
    while(1) {
        option = menu();
        if(option == 1)
            printf("Tamanho da fila: %d\n\n", size(F));
        else if(option == 2) {
            if(size(F) > 0){
            a = removePlane(F);
            printf("%s(%d) com decolagem autorizada!\n\n",
                    a.name, a.id);
                    }
            else {
            printf("Não existem aviões na fila.\n\n");
            }
        } else if(option == 3) {
            printf("Insira o nome do avião: ");
            scanf("%s", a.name);
            printf("Insira o ID do avião: ");
            scanf("%d", &a.id);
            insert(F, a);
        } else if(option == 4) {
            printRow(F);
        } else if(option == 5) {
            if(size(F) > 0){
                a = front(F);
                printf("Nome: %s\n", a.name);
                printf("ID: %d\n\n", a.id);
            } else {
                printf("Não existem aviões na fila.\n\n");
            }
        } else if(option == 6)
            break;
    }
    free(F);
    return 0;
}
