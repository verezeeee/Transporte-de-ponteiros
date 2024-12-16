#ifndef ONIBUS_H
#define ONIBUS_H

#include "Transporte.hpp"
#include <vector>

class Onibus: public Transporte{
  public:
    Onibus(int cap, float valor_passagem); 
    virtual ~Onibus();
    virtual bool pagar_passagem(std::shared_ptr<Passageiro> passageiro) override;
    virtual void mover() override;
    virtual void embarcar(std::shared_ptr<Passageiro> passageiro) override;
    virtual void desembarcar() override;
  protected:
    std::vector<std::shared_ptr<Passageiro>> passageiros;
};

#endif