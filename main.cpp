#include<iostream>
#include"pessoa.hpp"
#include"chefe.hpp"
#include"funcionario.hpp"
#include"vendedor.hpp"      //Inclusao das bibliotecas usadas
#include"supervisor.hpp"
#include"venda.hpp"
#include"hora.hpp"
#include<cstring>
using namespace std;

vector<Venda> Supervisor :: vendas; // Inicializa o vetor unico da classe Supervisor

//Funcao auxiliar para cadastrar um funcionario
void cadastrarFuncionario(Chefe *);


int main(){
    Chefe chefe("admin", "admin"); //Usuario e senga do chefe
    int op=0;

    string usuario; // variaveis axiliares
    string senha;

    do{
        cout << "1 - Fazer Login" << endl;
        cout << "0 - Sair" << endl; // menu de opcoes principal
        cout << "Escolha: ";
        cin >> op;
        cout << endl;

        if(op == 1){
            cout << "Usuario: ";
            cin >> usuario;
            cout << "Senha: ";
            cin >> senha;
            cout << endl;

            if(usuario == chefe.getUsuario() && senha == chefe.getSenha()){ //checagem do usuario e senha
                while(op != -1){
                    cout << "1 - Cadastrar Funcionario" << endl;
                    cout << "2 - Listar Funcionarios" << endl;
                    cout << "3 - Chegar Pontos" << endl;       //Menu de opcoes segundario
                    cout << "4 - Mostar salarios" << endl;
                    cout << "0 - Retornar a tela Inicial" << endl;
                    cout << "Escolha: ";
                    cin >> op;
                    cout << endl;

                    switch (op){
                        case 1:
                            cadastrarFuncionario(&chefe); //Cadastra o funcionario
                            break;
                        case 2:
                            chefe.listarFuncionarios(); //Lista os funcionarios
                            break;
                        case 3:
                            chefe.checarPontos(); //Lista os pontos
                            break;
                        case 4:
                            chefe.mostrarSalarios(); //Calcula e mostra os salarios
                            break;
                        case 0:
                            op = -1; //Volta ao menu principal
                            break;
                        default:
                            cout << "Opcao invalida!" << endl;
                    }
                }
            }
            else{
                op = chefe.manipulaFuncionarios(usuario, senha); //Manipulacoes dos funcionarios
            }
        }
        else if(op != 0)
            cout << "Opcao invalida!" << endl;
    }while(op != 0);

    return 0;
}

void cadastrarFuncionario(Chefe *chefe){
    string usuario;
    string senha;
    string nome;
    string funcao;
    string tipo;
    double salario;

    cout << "Usuario: ";
    cin >> usuario;
    cout << "Senha: ";
    cin >> senha;
    cout << "Nome: ";
    cin >> nome;
    cout << "Funcao: ";
    cin >> funcao;
    cout << "Tipo: ";
    cin >> tipo;
    cout << "Salario por hora: ";
    cin >> salario;
    cout << endl;

    chefe->cadastrarFuncionario(usuario, senha, nome, funcao, tipo, salario);
}
