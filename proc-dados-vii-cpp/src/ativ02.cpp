/*
 * Curso: Tec. Informatica - Colegio Santa Familia
 * Disciplina: Proc. Dados VII - C++
 * Atividade: Programa que incrementa um numero inteiro informado pelo usuario
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

#include <iostream>
using namespace std;

int main()
{
    int numero;

    cout << "Por favor, digite um numero inteiro: " << endl;
    cin >> numero;

    numero++;

    cout << "Proximo numero inteiro: " << numero << endl;
    return 0;
}
