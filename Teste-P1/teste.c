#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <math.h>

void criarLista (int ***l, int n) {
  int i;
  *l = (int **)malloc(sizeof(int*[n]));
  for(i=0; i < n; i = i+1)
    (*l)[i] = NULL;
}

// void limparLista (int ***l, int n) {
//   int i;
//   for(i=0; i < n; i = i+1)
//     if ((*l)[i] != NULL) free((*l)[i]);
//   free(*l);
// }

int elementosNaLista (int ** l, int n) {
  int i;
  for(i=0; i < n; i = i+1)
    if (l[i] == NULL) break;
  return i;
}

int buscarNaLista (int ** l, int n, int x) {
  int i, busca;
  busca = -1; //flag para erro
  for (i=0; i < n; i = i+1)
  {
    if (l[i] == NULL) break;
    else if (*(l[i]) == x)
         {
           busca = i;
           break;
         }
  }
  return busca;
}

int inserirNaLista (int ** l, int n, int x) {
  int i, M;
  M = elementosNaLista(l,n);
  if (M<n)
    if (buscarNaLista(l, n, x) == -1)
    {
       l[ M ] = (int *) malloc( sizeof( int ) );
      *l[ M ] = x;
      return 1;
    }
    else return 0; //Elemento já existe
  else return -1; //Overflow
}

// int excluirDaLista (int ** l, int n, int x) {
//   int i, indice, M;
//   M = elementosNaLista(l,n);
//   if (M != 0)
//   {
//     indice = buscarNaLista(l, n, x);
//     if (indice != -1)
//     {
//       if (indice == n-1)
//       {
//         free(l[indice]);
//         l[indice] = NULL;
//       }
//       else {
//              for (i = indice; i < M; i = i+1) l[i] = l[i+1];
//              l[n-1] = NULL;
//            }
//       return 1;
//     }
//     else return 0; //Elemento não existe
//   }
//   else return -1; //Underflow
// }

void imprimirLista (int ** l, int n) {
  int i, M;
  printf("ELEMENTOS DA LISTA:\n");
  for (i = 0; i < n; i = i+1)
    if (l[i] == NULL)
      printf("NULL\n");
    else printf("%d\n", *(l[i]));
  printf("\n");
}

// int ordemCrescente (int vetor[], int t) {
//   for (int i = 1; i < t; i++) {
//     if (vetor[i - 1] >= vetor[i]) {
//       return 0;
//     }
//   }
//   return 1;
// }

int ordemCrescenteComLista (int **l, int t) {
  for (int i = 1; i < t; i++) {
    if (*(l[i - 1]) >= *(l[i])) {
      return 0;
    }
  }
  return 1;
}

int main() {
  int T = 3;
  int **l;
  criarLista(&l,T);
  inserirNaLista(l,T,2);
  inserirNaLista(l,T,4);
  inserirNaLista(l,T,7);
  printf("Está em ordem crescente? %d\n", ordemCrescenteComLista(l, T));
  return 0;
}