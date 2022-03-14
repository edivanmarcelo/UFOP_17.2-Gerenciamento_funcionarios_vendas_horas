#ifndef supervisor_hpp
#define supervisor_hpp

#include"funcionario.hpp"

class Supervisor : public Funcionario{
    static vector <Venda> vendas;
public :
    Supervisor();
    ~Supervisor();

    virtual void cadastrarVendas(const string produto,const double preco);
    virtual void listarVendas(void);
    virtual double calcularSalarioTotal(void);
    virtual void exibirSalario(void);
};

#endif // supervisor
