#include"funcionario.hpp"

//Construtor da classe Funcionario
Funcionario :: Funcionario(double salarioT, double salarioH, double bonificacao): Pessoa(){
    this->salarioT = salarioT;
    this->salarioH = salarioH;
    this->bonificacao = bonificacao;
}

//Destrutor limpa a memoria alocada pelo vector
Funcionario :: ~Funcionario(){
    pontos.clear();
};

//Atribui valor a nome
void Funcionario :: setNome(const string nome){
    this->nome = nome;
}

//Atribui valor a funcao
void Funcionario :: setFuncao(const string funcao){
    this->funcao = funcao;
}

//Atribui valor a tipo
void Funcionario :: setTipo(const string tipo){
    this->tipo = tipo;
}

//Atribui valor a salarioH
void Funcionario :: setSalarioH(const double salarioH){
    this->salarioH = salarioH;
}

//Atribui valor a salarioT
void Funcionario :: setSalarioT(const double salarioT){
    this->salarioT = salarioT;
}

//Atribui valor a bonificacao
void Funcionario :: setBonificacao(const double bonificacao){
    this->bonificacao = bonificacao;
}

//Retorna valor de nome
string Funcionario :: getNome(void)const{
    return nome;
}

//Retorna valor de funcao
string Funcionario ::  getFuncao(void)const{
    return funcao;
}

//Retorna valor de tipo
string Funcionario ::  getTipo(void)const{
    return tipo;
}

//Retorna valor de salarioH
double Funcionario :: getSalarioH(void)const{
    return salarioH;
}

//Retorna valor de salarioT
double Funcionario :: getSalarioT(void)const{
    return salarioT;
}

//Retorna valor de bonificacao
double Funcionario :: getBonificacao(void)const{
    return bonificacao;
}

//Retorna valor das horas trabalhadas
double Funcionario :: retornaHoras(void)const{
    double aux=0.0;
    for(int i=0; i<pontos.size(); i++){
        aux += pontos[i].getHoras()*60 + pontos[i].getMinutos();
    }

    return aux;
}

//Funcao para inserir os Pontos
void Funcionario :: inserirPontos(const int horas, const int minutos){
    if(pontos.size() <= 5){

        if((horas*60+minutos) <= 600){
            int soma=horas*60+minutos;
            for(int i=0; i<pontos.size(); i++)
                soma += pontos[i].getHoras() * 60 + pontos[i].getMinutos();

            if(soma <= 3000){
                Hora aux;
                aux.setHoras(horas);
                aux.setMinutos(minutos);
                pontos.push_back(aux);
            }
            else{
                cout << "ERRO: Horas de trabalho exede o limite semanal" << endl;
            }
        }
        else{
            cout << "ERRO: Horas de trabalho exede o limeite diario" << endl;
        }
    }
    else
        cout << "Limite de pontos cadastrados já foi atingido!" << endl;
}

//Funcao que imprime os pontos
void Funcionario :: checarPontos(void)const{
    cout << "Funcionario: " << nome << endl;
    cout << "Pontos: " << endl;
    for(int i=0; i<pontos.size(); i++){
        cout << "Dia " << i+1 << ": ";
        cout << pontos[i].getHoras() << "h";
        cout << pontos[i].getMinutos() << endl;
    }
    cout << endl;
}
