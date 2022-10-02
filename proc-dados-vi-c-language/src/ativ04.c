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
   Faca um programa que inverta uma string (sequencia de caracteres).
   Use o comando for para varrer toda a string ate o seu final.
   Lembre-se que a string sempre termina com o caracter '\0'.
   ------------------------------------------------------------------
*/

/* Codigo: */

/* inclusao de bibliotecas */
#include <stdio.h>
#include <string.h>

/* declaracao das constantes */
#define MAX 15

main()
{
  /* declaracao de variaveis */
  char str[MAX], copia[MAX];
  int i;

  printf("\n\n### Programa que inverte uma String ###\n\n");
    /* le caracteres digitados no teclado */
  printf("\n\nEntre com uma palavra: ");
  gets(str);
  /* loop para ler todos os caracteres da frase */
  for (i = 0; str[i] != '\0'; i++)
  {
    /* inverte todas as posicoes exceto a ultima (\0) */
    copia[i] = str[strlen(str) - i - 1];
  }
  /* adiciona a marca de fim de caracter */
  copia[i] = '\0';
  /* escreve resultado na tela */
  printf("\n\nString Invertida: %s\n", copia);
}
