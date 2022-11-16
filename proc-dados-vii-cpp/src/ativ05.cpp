/*
 * Curso: Tec. Informatica - Colegio Santa Familia
 * Disciplina: Proc. Dados VII - C++
 * Atividade: Programa que le dois numeros informados pelo usuario e apresenta um menu com as opcoes:
 *            1. Somar os dois numeros
 *            2. Multiplicar os dois numeros
 *            3. Calcular a media dos numeros
 *            0. Sair
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
    int a, b, opcao;

    cout << "Programa que manipula dois numeros informados pelo usuario.\n\n";

    cout << "Informe o primeiro numero: ";
    cin >> a;

    cout << "Informe o segundo numero : ";
    cin >> b;

    cout << "Insira uma das seguintes opcoes:" << endl
         << "1. Somar os dois numeros" << endl
         << "2. Multiplicar os dois numeros" << endl
         << "3. Calcular a media dos numeros" << endl
         << "0. Sair" << endl
         << "Sua opcao: ";

    cin >> opcao;

    switch (opcao)
    {
    case 1:
        cout << "A soma dos numeros eh : " << (a + b) << endl;
        break;
    case 2:
        cout << "A multiplicacao dos numeros eh : " << (a * b) << endl;
        break;
    case 3:
        cout << "A media dos numeros eh : " << (a + b) / 2.0f << endl;
        break;
    default:
        break;
    }

    return 0;
}
