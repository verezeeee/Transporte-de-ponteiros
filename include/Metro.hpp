#ifndef METRO_H
#define METRO_H

#include "Trem.hpp"
#include <vector>

class Metro: public Trem{
  public:
    Metro(int cap, float valor_passagem);
    virtual ~Metro();
    virtual bool pagar_passagem(std::shared_ptr<Passageiro> passageiro) override;
    virtual void embarcar(std::shared_ptr<Passageiro> passageiro) override;
    virtual void desembarcar() override;
};

#endif