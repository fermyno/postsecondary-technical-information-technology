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
   Faca um programa que utilize os argumentos argv e argc.
   O programa devera receber dois numeros e apresentar a soma deles.
   Para isso e preciso uma funcao que transforme string em inteiro,
   pois o tipo de argv e char.
   Atencao:
   Este programa deve ser executado no console de comandos, de modo a
   permitir a passagem dos argumentos.
   Ex.: ativ11.exe 14 18
   ------------------------------------------------------------------
*/

/* Codigo: */

/* inclusao de bibliotecas */
#include <stdio.h>
#include <stdlib.h>

/* programa principal
   argv[0] é o nome do programa executavel
   argv[1] é o primeiro parâmetro
   e assim sucessivamente ...
*/
void main(int argc, char *argv[])
{
  /* declaracao de variaveis */
  int numa, numb;

  printf("\n\n### Programa que utiliza os argumentos argv e argc para somar numeros ###\n\n");
  /* testa validade dos valores passados por parametros */
  /* funcao atoi da biblioteca stdlib.h transforma char em int */
  if (((numa = atoi(argv[1])) == 0) ||
      ((numb = atoi(argv[2])) == 0))
    printf("\n\nArgumentos invalidos!! \n");
  else
    /* apresenta resultado na tela */
    printf("\n\nA soma de %d e %d = %d\n\n", numa, numb, numa + numb);
}
