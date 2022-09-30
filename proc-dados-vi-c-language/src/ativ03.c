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
   Escreva um programa utilizando o comando switch que leia uma
   string (utilize gets()) e substitua todos os espacos e
   tabulacoes ('\t') por caracteres de nova linha.
   O loop acaba quando encontrar o caracter de final de linha '\0'.
   ------------------------------------------------------------------
*/

/* Codigo: */

#include <stdio.h>
main()
{
  /* declaracao de variaveis */
  int index;
  char frase[30];

  printf("\n\n### Programa que le uma string e substitui tabs e espacos por nova linha ###\n\n\n");
  /* le a frase digitada no teclado */
  printf("\n\nEntre com a frase (max 30 caracteres): ");
  gets(frase);
  /* loop para realizar substituicao na frase */
  for (index = 0; frase[index] != '\0'; index++)
  {
    switch (frase[index])
    {
    case '\t':
      /* encontrada tabulacao */
      frase[index] = '\n';
      break;
    case ' ':
      /* encontrado espaco em branco */
      frase[index] = '\n';
      break;
    }
  }
  /* mostra resultado na tela */
  printf("\n\nNova frase: \n%s", frase);
}
