#include "Metro.hpp"
#include <iostream>
#include <iomanip>        

Metro::Metro(int cap, float valor_passagem): Trem(cap, valor_passagem) {};

Metro::~Metro() {
  std::cout << "Destrutor Metro" << std::endl;
}

bool Metro::pagar_passagem(std::shared_ptr<Passageiro> passageiro) {
  if(passageiros.size() < capacidade){
    if(passageiro->getSaldoPassagem() >= ( valor_passagem + 0.40)){
      passageiro->descontar_valor_passagem(valor_passagem + 0.40);
      return true;
    } else {
      std::string nome = passageiro->getNome();
      float saldo = passageiro->getSaldoPassagem();
      std:: cout << std::fixed << std::setprecision(2);
      std::cout << "Saldo insuficiente: " << std::endl << "  Nome: " << nome << std::endl << "  Saldo: R$" << saldo << std::endl;
      return false;
    }
  } else {
    return false;
  }
}

void Metro::embarcar(std::shared_ptr<Passageiro> passageiro) {
  if (pagar_passagem(passageiro)) {
    passageiros.push_back(passageiro);
  }
}

void Metro::desembarcar() {
  int quantidade_passageiros = passageiros.size();
  if (quantidade_passageiros > 0) {
    passageiros.clear();
    std::cout << quantidade_passageiros << " passageiros desembarcaram do metro" << std::endl;
  } else {
    std::cout << "Não há passageiros para desembarcar" << std::endl;
  }
}