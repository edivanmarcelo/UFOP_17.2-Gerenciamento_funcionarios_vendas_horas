#include"supervisor.hpp"
#define bSup 0.01
#define hSup 1.5

//construtor da classe supervisor
Supervisor :: Supervisor() : Funcionario(0.0,0.0,0.0){}

//Destrutor da classe supervisor
Supervisor :: ~Supervisor(){}

//Funcao que cadastra as vendas que todos os funcionarios fizeram
void Supervisor :: cadastrarVendas(const string produto, const double preco){
    Venda aux(produto, preco);
    vendas.push_back(aux);
}

//Funcao que lista as vendas de todos os funcionarios
void Supervisor :: listarVendas(void){
    for(int i=0; i<vendas.size(); i++){
        cout << "Produto: " << vendas[i].getProduto() << " ";
        cout << "Preco: R$" << vendas[i].getPreco() << endl;
    }
    cout << endl;
}

//Funcao que calcula o salario total
double Supervisor :: calcularSalarioTotal(void){
    int auxHoras = retornaHoras();
    double auxBon=0.0, auxSal=0.0;

    for(int i=0; i<vendas.size(); i++){
        auxBon += vendas[i].getPreco() * bSup;
    }
    setBonificacao(auxBon);

    if(auxHoras <= 480){
        auxSal = getSalarioH() * (auxHoras/60) + getBonificacao();
        setSalarioT(auxSal);
    }
    else{
        auxSal = getSalarioH() * 8 + getSalarioH() * ((auxHoras-480)/60 + ((auxHoras-480)/60)*hSup);
        auxSal += getSalarioH();
        setSalarioT(auxSal);
    }

    return getSalarioT();
}

//Funcao que exibe o salario detalhado
void Supervisor :: exibirSalario(void){
    calcularSalarioTotal();
    cout << "Salario por hora:       R$" << getSalarioH() << endl;
    cout << "Bonificacao por vendas: R$" << getBonificacao() << endl;
    cout << "Salario total:          R$" << getSalarioT() << endl << endl;
}
