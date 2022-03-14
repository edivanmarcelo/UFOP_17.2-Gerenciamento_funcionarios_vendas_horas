#include"vendedor.hpp"
#define bVend 0.1
#define hVend 1.0

//Constutor da classe vendedor
Vendedor :: Vendedor() : Funcionario(0.0,0.0,0.0){}

//Destrutor da classe vendedor
Vendedor :: ~Vendedor(){};

//Funcao que cadastra as vendas do vendedor em questao
void Vendedor :: cadastrarVendas(const string produto, const double preco){
    Venda aux(produto, preco);
    vendas.push_back(aux);
}

//Funcao que lista as vendas do vendedor
void Vendedor :: listarVendas(void){
    for(int i=0; i<vendas.size(); i++){
        cout << "Produto: " << vendas[i].getProduto() << " ";
        cout << "Preco: R$" << vendas[i].getPreco() << endl;
    }
    cout << endl;
}

//Funcao que calcula o salario total
double Vendedor :: calcularSalarioTotal(void){
    int auxHoras = retornaHoras();
    double auxBon=0.0, auxSal=0.0;

    for(int i=0; i<vendas.size(); i++){
        auxBon += vendas[i].getPreco() * bVend;
    }
    setBonificacao(auxBon);

    if(auxHoras <= 480){
        auxSal = getSalarioH() * (auxHoras/60) + getBonificacao();
        setSalarioT(auxSal);
    }
    else{
        auxSal = getSalarioH() * 8 + getSalarioH() * ((auxHoras-480)/60 + ((auxHoras-480)/60)*hVend);
        auxSal += getSalarioH();
        setSalarioT(auxSal);
    }

    return getSalarioT();
}

//Funcao que exibe o salario total de forma detalhada
void Vendedor :: exibirSalario(void){
    calcularSalarioTotal();
    cout << "Salario por hora:       R$" << getSalarioH() << endl;
    cout << "Bonificacao por vendas: R$" << getBonificacao() << endl;
    cout << "Salario total:          R$" << getSalarioT() << endl << endl;
}
