#ifndef venda_hpp
#define venda_hpp

#include<iostream>
#include<cstring>
using namespace std;

class Venda{
    string produto;
    double preco;
public:
    Venda(string, double preco=0.0);
    ~Venda();
    void setProduto(const string produto);
    void setPreco(const double preco);
    string getProduto(void)const;
    double getPreco(void)const;
};

#endif // venda
