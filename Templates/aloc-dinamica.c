#include <stdio.h>
#include <stdlib.h>

struct TNoDeCaractere
{
char caractere;
struct TNoDeCaractere * proximo;
};

struct TNoDeCaractere *inicio;

void armazenar (char valor);
void retirar (char valor);
void imprimir();
int listaVazia();

void listar()
{
  struct TNoDeCaractere *p;
  printf("\nCONTEUDO DA LISTA:\n");
  for (p = (*inicio).proximo; p != NULL; p = (*p).proximo)
    printf("%c ", (*p).caractere);
  printf("\n");
}

int main()
{
    char ch;

    inicio = (struct TNoDeCaractere *)malloc(sizeof(struct TNoDeCaractere));
    (*inicio).proximo = NULL;

    for(ch = 'a'; ch < 'p'; ch++)
    {
        printf("\t %c", ch);
        armazenar(ch);
    }
    imprimir();
    //listar();


    free(inicio);
    return 0;
}


void armazenar (char valor)
{
    struct TNoDeCaractere *p, *np;
    //Se a lista está vazia, cria um nó e faz "inicio" apontar para ele.
    if (inicio == NULL)
    {
    np = (struct TNoDeCaractere *)malloc(sizeof(struct TNoDeCaractere));
    (*np).caractere = valor;
    (*np).proximo = NULL;
    inicio = np;
    }
    else //Caso contrário, ou seja, se a lista não está vazia...
    {
        p = inicio;
        //varre toda a lista,
        while ((*p).proximo != NULL)
            p = (*p).proximo;
        //cria o novo nó
        np = (struct TNoDeCaractere *) malloc(sizeof(struct TNoDeCaractere));
        (*np).caractere = valor;
        (*np).proximo = NULL;
        //e liga a lista existente ao novo nó.
        (*p).proximo = np;
    }
}

void retirar (char valor)
{
    struct TNoDeCaractere * pAnt, *p;
    //Verifica se a partir do segundo nó, há nó a ser retirado.
    pAnt = inicio;
    p = (*inicio).proximo;
    while (p != NULL)
    {
        if ((*p).caractere == valor)
        {
            (*pAnt).proximo = (*p).proximo;
            free(p);
            p = (*pAnt).proximo;
        }
        else
        {
            pAnt = (*pAnt).proximo;
            p = (*p).proximo;
        }
    }
    //Testa se a lista está com o valor a ser retirado no primeiro nó.
    if ((*inicio).caractere == valor)
    {
        p = (*inicio).proximo;
        free(inicio);
        inicio = p;
    }
}
int listaVazia()
{
  return ((*inicio).proximo == NULL);
}
void imprimir()
{
     struct TNoDeCaractere *p;
     if (listaVazia())
        printf("\nLista vazia!");
     else
     {
        printf("\n");
        p= (*inicio).proximo;
        while(p != NULL)
        {
            printf("%c \t", (*p).caractere);
            p = (*p).proximo;
        }
     }
}
