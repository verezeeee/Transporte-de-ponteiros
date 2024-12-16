#ifndef TRANSPORTE_H
#define TRANSPORTE_H

#include <memory>
#include "Passageiro.hpp"

class Transporte {
  public:
    Transporte(int capacidade, float valor_passagem);
    virtual ~Transporte();  

    virtual bool pagar_passagem(std::shared_ptr<Passageiro> passageiro) = 0;
    virtual void mover() = 0;
    virtual void embarcar(std::shared_ptr<Passageiro> passageiro) = 0;
    virtual void desembarcar() = 0;

  protected:
    int capacidade;
    float valor_passagem;
};

#endif