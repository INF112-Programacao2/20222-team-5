#include "jogo.h"
#include "roleta.h"
#include "usuario.h"

int Jogo::apostaMinima = 50;
std::string nome = "Roleta";

Roleta::Roleta(Usuario user)
{
  this->user = user;
  this->corAposta = "";
  this->valorApostado = 0;
  premiacao = 0;
  resultado = "";
}

void Roleta::setCorAposta(std::string corAposta)
{
  this->corAposta = corAposta;
}

void Roleta::setValorApostado(int valorApostado)
{
  this->valorApostado = valorApostado;
}
