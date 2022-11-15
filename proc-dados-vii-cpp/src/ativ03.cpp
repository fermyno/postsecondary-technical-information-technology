/*
 * Curso: Tec. Informatica - Colegio Santa Familia
 * Disciplina: Proc. Dados VII - C++
 * Atividade: Programa que exemplifiqua o uso do printf
 *
 * Instrucoes:
 * Para criar o arquivo de objeto, execute o comando:
 *   g++ -c file.cpp -o file.o
 *   g++ file.o -o file
 *
 * Bibliografia complementar:
 *   Introducao a Programacao em C++
 *   Lucas S. Vieira
 *
 */

#include <cstdio>
int main()
{
    int num = 15;
    float decimal = 9.89f;
    double ddec = 7.32;
    char caractere = 'a';

    puts("Teste de funcionamento do printf:");
    puts("---------------------------------");
    printf("Inteiro   : %d\nFloat     : %f\nDouble    : %lf\n",
           num, decimal, ddec);
    printf("Caractere : %c\n", caractere);
    printf("Uma casa decimal    : %0.1f\n", decimal);
    printf("Duas casas decimais : %0.2f\n", decimal);
    puts("---------------------------------");
}
