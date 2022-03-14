#include"hora.hpp"

//Construtor da classe Hora
Hora :: Hora(int horas, int minutos){
    setHoras(horas);
    setMinutos(minutos);
}

//Destrutor da classe Hora
Hora :: ~Hora(){}

//Atribui valor a horas
void Hora :: setHoras(const int horas){
    this->horas = horas;
}

//Atribui valor a minutos
void Hora :: setMinutos(const int minutos){
    this->minutos = minutos;
}

//Retorna valor de horas
int Hora :: getHoras(void)const{
    return horas;
}

//Retorna valor de minutos
int Hora :: getMinutos(void)const{
    return minutos;
}
