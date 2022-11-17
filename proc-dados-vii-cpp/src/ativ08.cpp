/*
 * Curso: Tec. Informatica - Colegio Santa Familia
 * Disciplina: Proc. Dados VII - C++
 * Atividade: Manipulacao de string usando a biblioteca <cctype>.
 *            Conversao de caracteres maiusculos/minusculos.
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

#include <cctype>
#include <iostream>
using namespace std;

int main()
{

    char x = 'x', y = 'Y';

    cout << "Programa que transforma caracteres em maiusculos e minusculos: \n" << endl;

    cout << "Caracteres originais   : " << x << ' ' << y << endl;

    // converte caracteres
    x = toupper(x);
    y = tolower(y);

    cout << "Caracteres convertidos : " << x << ' ' << y << endl;
}