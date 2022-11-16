/*
 * Curso: Tec. Informatica - Colegio Santa Familia
 * Disciplina: Proc. Dados VII - C++
 * Atividade: Programa que mostra na tela o seno, cosseno e tangente de um angulo.
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
    // angulo em graus
    double angle = 60.0;

    // conversao do angulo para radianos
    angle *= M_PI / 180.0;

    // calcula seno, cosseno tangente
    double seno = sin(angle);
    double cosseno = cos(angle);
    double tangente = tan(angle);

    // informa resultado na tela
    cout << "Programa que calcula os dados do angulo de 60 graus:\n " << endl;
    cout << "Angulo (rad): " << angle << endl;
    cout << "Seno        : " << seno << endl;
    cout << "Cosseno     : " << cosseno << endl;
    cout << "Tangente    : " << tangente << endl;
}
