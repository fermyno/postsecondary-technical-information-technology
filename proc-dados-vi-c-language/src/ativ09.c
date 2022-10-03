/*
   ------------------------------------------------------------------
   Curso:   Tecnico em Informatica
   Colegio: Santa Familia
   Exercicios de Estudo
   ------------------------------------------------------------------
   Bibliografia Sugerida:
   + Introducao a Linguagem C
     Centro de Computacao
     Universidade Estadual de Campinas
   + Como Programar em C
     Paul J. Deitel e Harvey M. Deitel
   ------------------------------------------------------------------
   Enunciado:
   Escreva um programa que leia uma matriz pelo teclado e
   apresente os resultados na tela.
   A funcao deve ter o seguinte formato: lermatriz(int *mat)
   ------------------------------------------------------------------
*/

/* Codigo: */

/* inclusao de bibliotecas */
#include <stdio.h>
/* declaracao de constantes */
#define MAX 3

/* funca que le uma matriz */
void lermatriz(int *p)
{
  /* declaracao de variaveis */
  int i, j;
  /* mostra mensagem na tela */
  printf("\n\nEntre com a matriz (%dX%d): \n", MAX, MAX);
  /* loop para leitura da matriz */
  for (i = 0; i < MAX; i++)
    for (j = 0; j < MAX; j++)
      /* le dados da matriz */
      scanf("%d", p + (i * MAX + j));
}

/* funca que mostra uma matrix na tela */
void mostramatriz(int mat[MAX][MAX])
{
  /* declaracao de variaveis */
  int i, j;
  /* mostra mensagem na tela */
  printf("\n\nMatriz digitada:\n");
  /* loop para leitura da matrix */
  for (i = 0; i < MAX; i++)
  {
    for (j = 0; j < MAX; j++)
      /* escreve na tela a matriz */
      printf("%d   ", mat[i][j]);
    printf("\n");
  }
}

/* programa principal */
main()
{
  printf("\n\n### Programa que le uma matriz do teclado e apresenta na tela ###\n\n");
  /* declaracao de variaveis */
  int mat[MAX][MAX];
  /* le matriz */
  lermatriz(&mat[0][0]);
  /* linha em branco */
  printf("\n");
  /* mostra matrix na tela */
  mostramatriz(mat);
}
