#ifndef vendedor_hpp
#define vendedor_hpp

#include"funcionario.hpp"

class Vendedor : public Funcionario{
    vector <Venda> vendas;
public:
    Vendedor();
    ~Vendedor();

    virtual void cadastrarVendas(const string produto, const double preco);
    virtual void listarVendas(void);
    virtual double calcularSalarioTotal(void);
    virtual void exibirSalario(void);
};

#endif // vendedor
