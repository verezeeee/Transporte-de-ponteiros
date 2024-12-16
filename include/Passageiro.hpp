#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H

#include <string>

class Passageiro {
  public:
    Passageiro(std::string nome, int idade, float saldo_passagem);
    ~Passageiro();
    void descontar_valor_passagem(float valor_passagem);
    float getSaldoPassagem();
    std::string getNome();
    int getIdade();
  
  private:
    std::string nome;
    int idade;
    float saldo_passagem;
};

#endif