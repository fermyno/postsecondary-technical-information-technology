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
   Faca um programa usando enumeracao. Crie uma enumeracao de meses
   do ano, e utilize para indexar um vetor de nomes dos meses.
   Desta forma, apresente os nomes dos meses do ano na tela.
   ------------------------------------------------------------------
*/

/* Codigo: */

#include <stdio.h>

/* declara enumeracao */
enum mes
{
  JAN,
  FEV,
  MAR,
  ABR,
  MAI,
  JUN,
  JUL,
  AGO,
  SET,
  OUT,
  NOV,
  DEZ
};

/* funcao principal do programa */
void main()
{
  /* declaracao de variaveis */
  enum mes index;
  char *meses[12] = {"Janeiro", "Fevereiro", "Marco",
                     "Abril", "Maio", "Junho",
                     "Julho", "Agosto", "Setembro",
                     "Outubro", "Novembro", "Dezembro"};

  printf("\n\n### Programa que trabalha com enumeracoes de meses por anos ###\n\n");
  /* loop para mostrar os meses usando os dados da enumercao */
  for (index = JAN; index <= DEZ; index++)
    printf("\n%s", meses[index]);
}
