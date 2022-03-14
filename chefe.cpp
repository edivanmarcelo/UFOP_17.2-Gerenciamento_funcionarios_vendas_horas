#include"chefe.hpp"

// Construtor
Chefe :: Chefe(string usuario, string senha) : Pessoa(usuario, senha){}

//Destrutor desaloca a memoria alocada para os funcionarios
Chefe :: ~Chefe(){
    for(size_t i=0; i<funcionarios.size(); i++){
        delete funcionarios[i];
    }
    funcionarios.clear();
}

//Funcao para cadastrar um funcionario no vector de funcionarios da classe Chefe
void Chefe :: cadastrarFuncionario(string usuario, string senha, string nome, string funcao, string tipo, double salarioH){
    int aux = funcionarios.size();
    funcionarios.push_back(NULL);

    if(tipo == "vendedor"){
        funcionarios[aux] = new Vendedor;
    }
    else{
        funcionarios[aux] = new Supervisor;
    }

    funcionarios[aux]->setUsuario(usuario);
    funcionarios[aux]->setSenha(senha);
    funcionarios[aux]->setNome(nome);
    funcionarios[aux]->setFuncao(funcao);
    funcionarios[aux]->setTipo(tipo);
    funcionarios[aux]->setSalarioH(salarioH);
}

//Funcao para listar os funcionarios cadastrados
void Chefe :: listarFuncionarios(void){
    cout << "Funcionarios: " << endl;
    for(size_t i=0; i<funcionarios.size(); i++){
        cout << funcionarios[i]->getNome() << endl;
    }
    cout << endl;
}

//Funcao para checar os pontos cadastrados pelos funcionarios
void Chefe :: checarPontos(void){
    for(size_t i=0; i<funcionarios.size(); i++){
        funcionarios[i]->checarPontos();
    }
}

//Funcao que calcula e mostra os salarios dos funcionarios
void Chefe :: mostrarSalarios(void){
    cout << "Funcionarios: " << endl;
    for(size_t i=0; i<funcionarios.size(); i++){
        funcionarios[i]->calcularSalarioTotal();
        cout << funcionarios[i]->getNome() << endl;
        cout << "Salario: R$" << funcionarios[i]->getSalarioT() << endl << endl;
    }
    cout << endl;
}

//Funcao para manipular as opcoes relacionadas com os funcionarios
int Chefe :: manipulaFuncionarios(string usuario, string senha){
    int op = 1;
    for(size_t i=0; i<funcionarios.size(); i++){
        if(usuario == funcionarios[i]->getUsuario() && senha == funcionarios[i]->getSenha()){
            while(op != -1){
                cout << "1 - Cadastrar ponto" << endl;
                cout << "2 - Exibir salario" << endl;
                cout << "3 - Listar vendas" << endl;
                if(funcionarios[i]->getTipo() == "vendedor")
                    cout << "4 - Cadastrar Vendas" << endl;
                cout << "0 - Retornar a tela inicial" << endl;
                cout << "Escolhar: ";
                cin >> op;
                cout << endl;

                switch (op){
                    case 1:
                        int horas, minutos;
                        cout << "Horas trabalhadas (ex: 10 08): ";
                        cin >> horas >> minutos;
                        funcionarios[i]->inserirPontos(horas, minutos);
                        break;
                    case 2:
                        funcionarios[i]->exibirSalario();
                        break;
                    case 3:
                        funcionarios[i]->listarVendas();
                        break;
                    case 4:
                        if(funcionarios[i]->getTipo() == "supervisor")
                            cout << "Opcao invalida!" << endl;
                        else{
                            string produto;
                            double preco;
                            cout << "Nome do produto: ";
                            cin >> produto;
                            cout << "Preco: ";
                            cin >> preco;

                            funcionarios[i]->cadastrarVendas(produto, preco);
                            int aux = 0;
                            for(size_t j=0; j<funcionarios.size(); j++){
                                if(funcionarios[j]->getTipo() == "supervisor"){
                                    funcionarios[j]->cadastrarVendas(produto, preco);
                                    j = funcionarios.size();
                                }
                            }
                        }
                        break;
                    case 0:
                        op = -1;
                        return op;
                    default:
                        cout << "Opcao invalida" << endl;
                }
            }
        }
    }
}
