// ALGORITMOS E ESTRUTURAS DE DADOS - TESTE P1 VALENDO 2.0 PONTOS
// THIAGO ROCHA DUARTE
// GUSTAVO XAVIER SALDANHA

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <math.h>

void criarLista(int ***l, int n)
{
  int i;
  *l = (int **)malloc(sizeof(int*[n]));
  for(i=0; i < n; i = i+1)
    (*l)[i] = NULL;
}

void limparLista(int ***l, int n)
{
  int i;
  for(i=0; i < n; i = i+1)
    if ((*l)[i] != NULL) free((*l)[i]);
  free(*l);
}

int elementosNaLista(int ** l, int n)
{
  int i;
  for(i=0; i < n; i = i+1)
    if (l[i] == NULL) break;
  return i;
}

int buscarNaLista(int ** l, int n, int x)
{
  int i, busca;
  busca = -1; //flag para erro
  for (i=0; i < n; i = i+1)
  {
    if (l[i] == NULL) break;

  }
  return busca;
}

int inserirNaLista(int ** l, int n, int x)
{
  int i, M;
  M = elementosNaLista(l,n);
  if (M<n)
    if (buscarNaLista(l, n, x) == -1)
    {
       l[ M ] = (int *) malloc( sizeof( int ) );
      *l[ M ] = x;
      return 1;
    }
    else return 0; //Elemento j� existe
  else return -1; //Overflow
}

int excluirDaLista(int ** l, int n, int x)
{
  int i, indice, M;
  M = elementosNaLista(l,n);
  if (M != 0)
  {
    indice = buscarNaLista(l, n, x);
    if (indice != -1)
    {
      if (indice == n-1)
      {
        free(l[indice]);
        l[indice] = NULL;
      }
      else {
             for (i = indice; i < M; i = i+1) l[i] = l[i+1];
             l[n-1] = NULL;
           }
      return 1;
    }
    else return 0; //Elemento n�o existe
  }
  else return -1; //Underflow
}

void imprimirLista(int ** l, int n)
{
  int i, M;
  printf("ELEMENTOS DA LISTA:\n");
  for (i = 0; i < n; i = i+1)
    if (l[i] == NULL){

    }
    else printf("%d\n", *(l[i]));
  printf("\n");
}

// =================================================

void criarCopia(int ***ln, int ***l, int n)
{
  int i;
  for(i=0; i < n; i = i+1){
    inserirNaLista(ln, n, *(l[i]));
  }
}

void criarConcatenada(int ***ln, int ***l1, int ***l2, int n)
{
  int i, b;
  for(i=0; i < n; i = i+1) {
    inserirNaLista(ln, n, *(l1[i]));
  }
  b = n + n;
  for(i=0; i < n; i = i+1) {
    inserirNaLista(ln, b, *(l2[i]));
  }
}

void inverteLista(int **a, int t) {
    int aux, i;
    int j = t-1;
    if (t % 2 == 0) {
        for (i = 0; i < t/2; i++) {
            aux = a[i];
            a[i] = a[j];
            a[j] = aux;
            j--;
        }
    } else {
        for (i = 0; i <= t/2; i++) {
            aux = a[i];
            a[i] = a[j];
            a[j] = aux;
            j--;
        }
    }
}


main()
{
  int N, **lista, **listaCop, **listaConc, i, opcao, chave;
  int T = N*2;

  printf("Tamanho da lista: ");
  scanf("%d", &N);

  criarLista(&lista, N);
  criarLista(&listaCop, N);
  criarLista(&listaConc, T);

  do
  {
    system ("CLS");

    printf("Menu de Opcoes\n\n");
    printf("1 - INCLUIR\n");
    printf("2 - EXCLUIR\n");
    printf("3 - IMPRIMIR\n");
    printf("4 - CRIAR LISTA COPIADA E IMPRIME\n");
    printf("5 - CONCATENA LISTAS E IMPRIME\n");
    printf("6 - INVERTE E IMPRIME\n");
    printf("7 - SAIR\n\n");
    printf("Entre sua Opcao: ");
    scanf("%d", &opcao);
    switch(opcao)
    {
      case 1: if (elementosNaLista(lista, N) != N)
              {
                printf("Entre o elemento a ser incluido: ");
                scanf("%d", &chave);
                inserirNaLista(lista, N, chave);
              }
              else printf("LISTA CHEIA. IMPOSSIVEL INCLUIR\n\n");
              break;
      case 2: if (elementosNaLista(lista, N) != 0)
              {
                printf("Entre o elemento a ser excluido: ");
                scanf("%d", &chave);
                excluirDaLista(lista, N, chave);
              }
              else printf("LISTA VAZIA. IMPOSSIVEL EXCLUIR\n\n");
              break;
      case 3: imprimirLista(lista, N);
              break;
      case 4: criarCopia(listaCop, lista, N);
              imprimirLista(listaCop, N);
              break;
      case 5: criarConcatenada(listaConc, lista, listaCop, N);
              imprimirLista(listaConc, T);
              break;
      case 6: inverteLista(lista, N);
              imprimirLista(lista, N);
              break;
    }
    system("PAUSE");
  } while (opcao != 7);

  limparLista(&lista, N);
}
