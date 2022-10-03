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
   Faca um programa que leia uma string do teclado.
   Em seguida, verifique se a string corresponde a um numero.
   Se sim, calcular o valor que a string representa (inclusive quando
           for negativo) e apresenta-lo na tela como float.
   Se nao, o numero apresentado devera ser zero.
   Observacoes:
   - E obrigatoria a utilizacao de ponteiros para percorrer a string.
   ------------------------------------------------------------------
*/

/* Codigo: */

/* inclusao de bibliotecas */
#include <stdio.h>
#include <ctype.h>

/* funcao principal do programa */
main()
{
  /* declaracao de variaveis */
  char buf[30], *p;
  float res = 0;
  int sinal = 1, pot;

  printf("\n\n### Programa para converter string em numeros ###\n");
    /* le numero digitado */
  printf("\n\nEntre com a string: ");
  scanf("%s", buf);
  p = &buf[0];

  /* retira espacos que pode existir no inicio da string */
  while ((!isdigit(*p)) && (*p != '\0'))
  {
    /* verifica se numero digitado tem sinal de negativo */
    if (*p == '-')
      sinal = -1;
    p++;
  }

  /* calcula a parte inteira do numero */
  for (res = 0.0; isdigit(*p); p++)
    res = 10.0 * res + (*p - '0');
  if (*p == '.')
    p++;

  /* calcula a parte decimal do numero */
  for (pot = 1.0; isdigit(*p); p++)
  {
    res = 10.0 * res + (*p - '0');
    pot *= 10.0;
  }

  /* apresenta resultado na tela */
  res = sinal * res / pot;
  printf("\nVeja o resultado: %f\n", res);
}
