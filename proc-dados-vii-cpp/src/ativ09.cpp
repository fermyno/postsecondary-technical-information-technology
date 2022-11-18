/*
 * Curso: Tec. Informatica - Colegio Santa Familia
 * Disciplina: Proc. Dados VII - C++
 * Atividade: Programa que abra um arquivo EXISTENTE e escreve uma mensagem secreta.
 *            Atencao: o arquivo deve EXISTIR.
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

#include <fstream>

int main()
{
    // escreve conteudo se arquivo existe
    std::ofstream arq;
    arq.open("ativ09.txt");
    // Apenas escreva no arquivo se ele existe
    if (arq.is_open())
    {
        arq << "Minha mensagem secreta!" << std::endl;
        arq.close();
    }


}
