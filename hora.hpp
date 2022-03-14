#ifndef hora_hpp
#define hora_hpp

#include<iostream>

class Hora{
    int horas;
    int minutos;
public:
    Hora(int horas=0, int minutos=0);
    ~Hora();
    void setHoras(const int horas);
    void setMinutos(const int minutos);
    int getHoras(void)const;
    int getMinutos(void)const;
};


#endif // hora
