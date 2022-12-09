#include "../jogo.h"
#include "roleta.h"
#include "../../usuario/usuario.h"

int Jogo::apostaMinima = 50;

std::string Jogo::nome = "Roleta";

Roleta::Roleta(Usuario user, std::string corAposta, int valorApostado)
{
  this->user = user;
  this->corAposta = corAposta;
  this->valorApostado = valorApostado;
  premiacao = 0;
  resultado = "";
}