#ifndef pessoa_hpp
#define pessoa_hpp

#include<cstring>
#include<iostream>
using std :: string;
using namespace std;

class Pessoa{
    string usuario;
    string senha;
public:
    Pessoa(string, string);
    Pessoa(){}
    ~Pessoa();
    void setUsuario(const string usuario);
    void setSenha(const string senha);
    string getUsuario(void)const;
    string getSenha(void)const;
};

#endif
