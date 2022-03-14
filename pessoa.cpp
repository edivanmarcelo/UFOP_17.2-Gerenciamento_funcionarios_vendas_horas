#include"pessoa.hpp"

//Construtor da classe Pessoa
Pessoa :: Pessoa(string usuario, string senha){
    this->usuario = usuario;
    this->senha = senha;
}
//Destrutor da classe pessoa
Pessoa :: ~Pessoa(){}

//Atribui valor a usuario
void Pessoa :: setUsuario(const string usuario){
    this->usuario = usuario;
}

//Atribui valor a senha
void Pessoa :: setSenha(const string senha){
    this->senha = senha;
}

//Retorna valor de usuario
string Pessoa :: getUsuario(void)const{
    return usuario;
}

//Retorna valor de senha
string Pessoa :: getSenha(void)const{
    return senha;
}
