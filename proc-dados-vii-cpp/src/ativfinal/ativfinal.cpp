/*
 * Curso: Tec. Informatica - Colegio Santa Familia
 * Disciplina: Proc. Dados VII - C++
 * Atividade Final
 *
 * Instrucoes: O aluno deverá criar um programa que converta um arquivo em
 *             formato XML (ativfinal.xml) em outro arquivo em formato CSV
 *             (ativfinal.csv).
 *             O aluno poderá fazer uso de bibliotecas externas, porém, a
 *             pesquisa, escolha, e implantação dessas bibliotecas é de
 *             inteira responsabilidade do aluno.
 *             O programa deve permitir o acompanhamento de sua execução
 *             através da impressão de um "log" na tela.
 *             Atenção: a ordem dos campos do arquivo XML não corresponde
 *             exatamente com a ordem dos campos no arquivo XML, portanto,
 *             o aluno deverá ler os dados do arquivo XML, salvar em
 *             variáveis, e escrever o conteúdo no arquivo CSV na ordem correta!
 *             XML (ordem dos campos): nome + matricula + cargo + salario + departamento
 *             CSV (ordem dos campos): matricula + nome + departamento + cargo + salario
 *
 * Para criar o arquivo de objeto, execute o comando:
 *   g++ -c file.cpp -o file.o
 *   g++ file.o -o file
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include "pugixml-1.12/src/pugixml.hpp" // biblioteca pugixml < https://pugixml.org/ >

using namespace std;
using namespace pugi;

int main()
{
    // declaracao de variaveis dos arquivos (constantes)
    const char arquivoXML[20] = "ativfinal.xml";
    const char arquivoCSV[20] = "ativfinal.csv";
    // declaracao das variaveis dos campos
    string campoTemp = "";
    string campoMatricula = "";
    string campoNome = "";
    string campoDepartamento = "";
    string campoCargo = "";
    string campoSalario = "";

    // mostra mensagem na tela
    cout << "Programa que converte arquivo XML em CSV.\n\n";

    // mostra mensagem na tela
    cout << "* lendo  arquivo  XML ... ";

    // instancia a classe xml_document
    xml_document documento;

    // carrega o arquivo XML
    if (!documento.load_file(arquivoXML))
    {
        // erro na abertura do arquivo XML
        cout << " [Erro na abertura do arquivo XML " << arquivoXML << "]\n";
        return -1;
    }
    else
    {
        // arquivo XML aberto com sucesso
        cout << " [Arquivo XML aberto com sucesso]\n";

        // mostra mensagem na tela
        cout << "* abrindo arquivo CSV ... ";

        // abre arquivo CSV
        ofstream arquivoGravar(arquivoCSV);

        // testa se arquivo CSV pode ser manipulado
        if (arquivoGravar.is_open())
        {

            // arquivo aberto com sucesso
            cout << " [Arquivo CSV aberto com sucesso]\n";

            // grava cabecalho no arquivo CSV
            arquivoGravar << "matricula;nome;departamento;cargo;salario;" << endl;

            // ----------------------------------------------------------------------------------------

            cout << "* Exibindo conteudo do arquivo <" << arquivoXML << ">\n\n";

            // inspecciona o documento em busca das etiquetas XML
            // <EmployeesData FormatVersion="1">
            //    <Employees>
            xml_node tools = documento.child("DadosFuncionarios").child("Funcionarios");

            // le todo o arquivo xml
            for (xml_node_iterator it = tools.begin(); it != tools.end(); ++it)
            {
                // zera conteudo das variaveis
                campoTemp = "";
                campoMatricula = "";
                campoNome = "";
                campoDepartamento = "";
                campoCargo = "";
                campoSalario = "";

                // exibe dados na tela
                cout << "Funcionario:\n";

                // realiza loop entre todos os elementos da etiqueta
                for (xml_attribute_iterator ait = it->attributes_begin(); ait != it->attributes_end(); ++ait)
                {
                    // mostra dados na tela
                    cout << "   " << ait->name() << ": " << ait->value() << "\n";

                    // carrega conteudo do arquivo nas respectivas variaveis
                    campoTemp = ait->name();
                    // campoNome
                    if (campoTemp == "Nome")
                    {
                        campoNome = ait->value();
                    }
                    // campoMatricula
                    if (campoTemp == "Matricula")
                    {
                        campoMatricula = ait->value();
                    }
                    // campoCargo
                    if (campoTemp == "Cargo")
                    {
                        campoCargo = ait->value();
                    }
                    // campoSalario
                    if (campoTemp == "Salario")
                    {
                        campoSalario = ait->value();
                    }
                    // campoDepartamento
                    if (campoTemp == "Departamento")
                    {
                        campoDepartamento = ait->value();
                    }
                }

                // mostra na tela os dados capturados nas variaveis
                // cout << "CSV => " << campoMatricula << ";" << campoNome << ";" << campoDepartamento << ";" << campoCargo << ";" << campoSalario << ";\n";
                cout << endl;

                // grava dados no arquivo CSV
                arquivoGravar << campoMatricula << ";" << campoNome << ";" << campoDepartamento << ";" << campoCargo << ";" << campoSalario << ";" << endl;
            }

            // ----------------------------------------------------------------------------------------

            // fecha arquivo
            arquivoGravar.close();
        }
        else
        {
            // erro na abertura do arquivo
            cout << " [Erro na abertura do arquivo CSV " << arquivoCSV << "]\n";
            return -1;
        }

        // fim da listagem do arquivo na tela
        cout << "* Fim da leitura do arquivo XML." << endl;
        cout << "* Arquivo CSV gerado com sucesso!" << endl;
    }

    return 0;
}