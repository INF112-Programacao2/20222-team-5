#include "../jogo.h"
#include "roleta.h"
#include "../../usuario/usuario.h"

int Jogo::apostaMinima = 50;

Roleta::Roleta(Usuario user, std::string corAposta, int valorApostado)
{
  this->user = user;
  this->corAposta = corAposta;
  this->valorApostado = valorApostado;
  premiacao = 0;
  resultado = "";
}