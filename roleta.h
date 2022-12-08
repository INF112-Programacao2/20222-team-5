#ifndef ROLETA
#define ROLETA

#include "jogo.h"
#include "usuario.h"
#include <string>

class Roleta : public Jogo
{
private:
  Usuario user;
  std::string corAposta;
  std::string resultado;
  int valorApostado;
  int premiacao;

public:
  Roleta(Usuario user);
  void setCorAposta(std::string corAposta);
  void setValorApostado(int valorApostado);
};

#endif
