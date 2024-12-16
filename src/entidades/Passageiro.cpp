#include "Passageiro.hpp"

Passageiro::Passageiro(std::string nome, int idade, float saldo_passagem)
  : nome(nome), idade(idade), saldo_passagem(saldo_passagem) {}

Passageiro::~Passageiro() {}

void Passageiro::descontar_valor_passagem(float valor_passagem) {
  saldo_passagem -= valor_passagem;
}

//método que retorna o saldo do passageiro 
float Passageiro::getSaldoPassagem(){
  return saldo_passagem;
}

//método que retorna o nome do passageiro
std::string Passageiro::getNome(){
  return nome;
}

int Passageiro::getIdade(){
  return idade;
}