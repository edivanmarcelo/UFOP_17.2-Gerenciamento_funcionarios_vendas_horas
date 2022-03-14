#include"venda.hpp"

//construtor da classe venda
Venda :: Venda(string produto, double preco){
    setProduto(produto);
    setPreco(preco);
}

//destrutor da classe venda
Venda :: ~Venda(){}

//Atribui valor a produto
void Venda :: setProduto(const string produto){
    this->produto = produto;
}

//Atribui valor a preco
void Venda :: setPreco(const double preco){
    this->preco = preco;
}

//Retorna o valor de produto
string Venda :: getProduto(void)const{
    return produto;
}

//Retorna o valor de preco
double Venda :: getPreco(void)const{
    return preco;
}
