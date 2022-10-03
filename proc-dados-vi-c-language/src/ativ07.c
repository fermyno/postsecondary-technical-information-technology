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
   Escreva um programa que leia nomes pelo teclado e imprima na tela,
   utilizando as funcoes puts e gets.
   ------------------------------------------------------------------
*/

/* Codigo: */

#include <stdio.h>
void main()
{
  /* declaracao de variaveis */
  char nome[30];

  printf("\n\n### Programa que le nomes do teclado e imprime na tela ###\n\n");
  /* captura nome digitado no teclado */
  printf("\n\nEscreva um Nome: ");
  gets(nome);
  /* escreve nome digitado na tela */
  puts("\nO nome escrito foi:");
  puts(nome);
}
