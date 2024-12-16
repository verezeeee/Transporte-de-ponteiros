#ifndef TREM_H
#define TREM_H

#include "Transporte.hpp"
#include <vector>

class Trem : public Transporte{
  public:
    Trem(int capacidade, float valor_passagem);
    virtual ~Trem();

    virtual bool pagar_passagem(std::shared_ptr<Passageiro> passageiro) override;
    virtual void mover() override;
    virtual void embarcar(std::shared_ptr<Passageiro> passageiro) override;
    virtual void desembarcar() override;

  protected:
    std::vector<std::shared_ptr<Passageiro>> passageiros;
};

#endif