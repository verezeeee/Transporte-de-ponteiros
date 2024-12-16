#include "Trem.hpp"
#include <iostream>
#include <cmath>
#include <iomanip>

Trem::Trem(int capacidade, float valor_passagem): Transporte(capacidade, valor_passagem) {};

Trem::~Trem() {
  std::cout << "Destrutror Trem" << std::endl;
}

bool Trem::pagar_passagem(std::shared_ptr<Passageiro> passageiro){
  if ( passageiros.size() < capacidade) {
    if (passageiro->getSaldoPassagem() >= valor_passagem) {
      passageiro->descontar_valor_passagem(valor_passagem);
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

void Trem::mover() {
  double porcentagem_ocupacao_trem = (static_cast<double>(passageiros.size()) / capacidade) * 100;
  int ocupacao_arredondada = static_cast<int>(std::round(porcentagem_ocupacao_trem));
  std::cout << "Deslocando com " << ocupacao_arredondada << "% da capacidade" << std::endl;
}

void Trem::embarcar(std::shared_ptr<Passageiro> passageiro) {
  if (pagar_passagem(passageiro)) {
    passageiros.push_back(passageiro);
  }
}

void Trem::desembarcar() {  
  int quantidade_passageiros = passageiros.size();
  if (quantidade_passageiros > 0) {
    passageiros.clear();
    std::cout << quantidade_passageiros << " passageiros desembarcaram do trem " << std::endl;
  } else {
    std::cout << "Não há passageiros para desembarcar" << std::endl;
  }
}