#ifndef funcionario_hpp
#define funcionario_hpp

#include"pessoa.hpp"
#include"hora.hpp"
#include"venda.hpp"
#include<vector>
#include<iterator>
using namespace std;

class Funcionario : public Pessoa{
    string nome;
    string funcao;
    string tipo;
    double salarioT, salarioH;
    double bonificacao;
    vector <Hora> pontos;
public:
    Funcionario(double salarioT=0.0, double salarioH=0.0, double bonificacao=0.0);
    Funcionario(void){};
    virtual ~Funcionario();

    void setNome(const string nome);
    void setFuncao(const string funcao);
    void setTipo(const string tipo);
    void setSalarioH(const double salarioH);
    void setSalarioT(const double salarioT);
    void setBonificacao(const double bonificacao);
    string getNome(void)const;
    string getFuncao(void)const;
    string getTipo(void)const;
    double getSalarioH(void)const;
    double getSalarioT(void)const;
    double getBonificacao(void)const;

    double retornaHoras(void)const;
    void inserirPontos(const int horas, const int minutos);
    void checarPontos(void)const;
    virtual double calcularSalarioTotal(void)=0;
    virtual void exibirSalario(void)=0;

    virtual void cadastrarVendas(string produto, double preco){};
    virtual void listarVendas(void){};
};


#endif // funcionario
