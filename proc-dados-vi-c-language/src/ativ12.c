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
   Um problema tradicional de recursividade consiste em encontrar o
   termo da sequencia de Fibonacci. As series de Fibonacci sao de
   grande importancia matematica. A lei basica e que, a partir do
   terceiro termo, todos os termos sao a soma dos dois ultimos.
   A seguir sao apresentados os primeiros termos da sequencia.
   F = {1, 1, 2, 3, 5, 8, 13, 21, 34...}
   O primeiro e o segundo termos sao 1.
   O terceiro termo e 2 (1+1).
   O quarto termo e 3 (1+2).
   O proximo e 5 (3+2).
   E assim sucessivamente.
   Faca um programa que encontre o termo da sequencia de
   Fibonacci. Use recursividade.
   ------------------------------------------------------------------
*/

/* Codigo: */

#include <stdio.h>

/* funcao que retorna a soma dos ultimos termos */
int fib(int n)
{
  if (n > 2)
    return fib(n - 1) + fib(n - 2);
  else
    return 1;
}

/* programa principal */
void main()
{
  /* declaracao de variaveis */
  int n, fibon;

  printf("\n\n### Programa para calcular termo da sequencia de Fibonacci ###\n\n");
  /* le o numero digitado */
  printf("\n\nEntre com um numero: ");
  scanf("%d", &n);
  /* calcula o termo fibinacci */
  fibon = fib(n);
  /* exibe mensagem na tela */
  printf("\nO termo %d da serie de Fibonacci e: %d\n", n, fibon);
}
