#ifndef chefe_hpp
#define chefe_hpp

#include"pessoa.hpp"
#include"funcionario.hpp"
#include"vendedor.hpp"
#include"supervisor.hpp"
#include<vector>
#include<iterator>
using namespace std;

class Chefe : public Pessoa{
    vector <Funcionario*> funcionarios;
public:
    Chefe(string usuario, string senha);
    ~Chefe();
    void cadastrarFuncionario(string, string, string, string, string, double);
    void listarFuncionarios(void);
    void checarPontos(void);
    void mostrarSalarios(void);
    int manipulaFuncionarios(string, string);
};

#endif // chefe
