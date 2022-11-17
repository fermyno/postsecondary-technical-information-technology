/*
 * Curso: Tec. Informatica - Colegio Santa Familia
 * Disciplina: Proc. Dados VII - C++
 * Atividade: Programa que utiliza a biblioteca <ctime> e mostra a data no formato 1/1/1900, 0h0m0s
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

#include <ctime>
#include <iostream>
using namespace std;

int main()
{
    // estrutura "tempo" representa a data inicial: domingo, 1 de janeiro de 1900, 0h00m, UTC.
    struct tm tempo = {0};
    cout << 1 + tempo.tm_mday << "/"
         << 1 + tempo.tm_mon  << "/"
         << 1900 + tempo.tm_year << ", "
         << tempo.tm_hour << "h"
         << tempo.tm_min  << "m"
         << tempo.tm_sec  << "s" << endl;
}
