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
   Escreva um programa que receba duas strings e retorne o valor.
   ------------------------------------------------------------------
*/

/* Codigo: */

#include <stdio.h>
main()
{
    /* definicao de variaveis */
    char str1[25], str2[25];
    printf("\n\n### Programa para leitura de Strings ###\n");
    printf("\nDigite a String 1: ");
    /* le string 1 */
    gets(str1);
    printf("\nDigite a String 2: ");
    /* Le string 2*/
    gets(str2);
    /* mostra resultado na tela */
    printf("\n\n A strings lidas sao:\n %s \n %s", str1, str2);
}
