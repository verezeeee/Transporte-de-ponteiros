#include "Transporte.hpp"

#include <iostream>

Transporte::Transporte(int capacidade, float valor_passagem)
  : capacidade(capacidade), valor_passagem(valor_passagem) {}

Transporte::~Transporte() {
  std::cout << "Destrutor Transporte" << std::endl;
}