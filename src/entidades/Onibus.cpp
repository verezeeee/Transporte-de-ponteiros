#include "Onibus.hpp"
#include <iostream>
#include <cmath>
#include <iomanip>

Onibus::Onibus(int cap, float valor_passagem): Transporte(cap, valor_passagem) {};

Onibus::~Onibus() {
  std::cout << "Destrutor Onibus" << std::endl;
}

bool Onibus::pagar_passagem(std::shared_ptr<Passageiro> passageiro) {
  if(passageiros.size() < capacidade){
    if(passageiro->getIdade() >= 65){
      passageiro->descontar_valor_passagem(0);
      std::string nome = passageiro->getNome();
      int idade = passageiro->getIdade();
      float saldo = passageiro->getSaldoPassagem();
      std:: cout << std::fixed << std::setprecision(2);
      std::cout << "Passagem gratuita: " << std::endl << "  Nome: " << nome << std::endl << "  Idade: " << idade << std::endl << "  Saldo: R$" << saldo << std::endl;
      return true;
    } else if (passageiro->getSaldoPassagem() >= valor_passagem){
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

void Onibus::mover() {
  double porcentagem_ocupacao_onibus = (static_cast<double>(passageiros.size()) / capacidade) * 100;
  int ocupacao_arredondada = (static_cast<int>(std::round(porcentagem_ocupacao_onibus)));
  std::cout << "Deslocando com " << ocupacao_arredondada << "% da capacidade" << std::endl;
}

void Onibus::embarcar(std::shared_ptr<Passageiro> passageiro) {
  if (pagar_passagem(passageiro)) {
    passageiros.push_back(passageiro);
  }
}

void Onibus::desembarcar() {
  int quantidade_passageiros = passageiros.size();
  if (quantidade_passageiros > 0) {
    passageiros.clear();
    std::cout << quantidade_passageiros << " passageiros desembarcaram do onibus" << std::endl;
  } else {
    std::cout << "Não há passageiros para desembarcar" << std::endl;
  }
}