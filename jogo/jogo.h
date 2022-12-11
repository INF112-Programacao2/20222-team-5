#ifndef JOGO
#define JOGO

#include <string>
#include "../usuario/usuario.h"

class Jogo
{
protected:
  Usuario user;
  int valorApostado;
  int premiacao;

public:

  Jogo();
  ~Jogo();
  static std::string getNome();
  Usuario getUsuario();
  int getValorApostado();
  int getPremiacao();
  void setValorApostado(double valor);
  void setPremiacao(double valor);
};

#endif
