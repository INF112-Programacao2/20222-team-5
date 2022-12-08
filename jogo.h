#ifndef JOGO
#define JOGO

#include <string>
#include "usuario.h"

class Jogo
{
private:

  static int apostaMinima;
  static std::string nome;
  Usuario user;
  int valorApostado;
  int premiacao;

public:

  Jogo();
  ~Jogo();
  static int getApostaMinima();
  static std::string getNome();
  Usuario getUsuario();
  int getValorApostado();
  int getPremiacao();
  void setValorApostado(double valor);
  void setPremiacao(double valor);
};

#endif