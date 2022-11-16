/*
 * Curso: Tec. Informatica - Colegio Santa Familia
 * Disciplina: Proc. Dados VII - C++
 * Atividade: Programa que le um numero digitado pelo usuario e
 *            informa na tela se eh par ou impar.
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


#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    int a;

 cout << "Insira o numero a: ";
 cin >> a;

    if (a % 2 == 0)
    {
        cout << "O numero informado eh par" << endl;
    }
    else
    {
        cout << "O numero informado eh impar" << endl;
    }
    
    return 0;
}
