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
   Escreva um programa que leia uma string do teclado
   (usando o gets()) e remova todos os caracteres 'a' encontrados.
   Na tela, apresente a quantidades de caracteres retirados da string
   ------------------------------------------------------------------
*/

/* Codigo: */

/* declaracao de constantes */
#define TAMANHO 50
/* inclusao de bibliotecas */
#include <stdio.h>

main()
{
  /* declaracao de variaveis */
  char original[TAMANHO];
  int i, j;
  printf("\n\n### Programa que remove a letra <a> de uma frase. ###\n\n");  
  /* captura a frase digitada no teclado */
  printf("\n\nPor favor, digite uma frase com caracter <a>: ");
  gets(original);
  printf("\n\nFoi digitada a seguinte frase:\n%s", original);
  /* loop para verificar os caracteres que
     fazem parte da frase digitada */
  for (i = 0; original[i] != '\0'; i++)
  {
    /* quando o caracter e igual a 'a' */
    if ((original[i] == 'a') || (original[i] == 'A'))
    {
      for (j = i; original[j] != '\0'; j++)
        original[j] = original[j + 1];
      i--;
    }
  }
  /* escreve resultado na tela */
  printf("\n\nFrase com alteracoes:\n%s\n", original);
}
