#ifndef JOGO
#define JOGO

#include <string>
#include "../usuario/usuario.h"

static int apostaMinima;
static std::string nome;
class Jogo
{
public:
  virtual int getApostaMinima() = 0;
  virtual std::string getNome() = 0;
  virtual int getValorApostado() = 0;
  virtual int getPremiacao() = 0;
  virtual void setValorApostado(double valor) = 0;
  virtual void setPremiacao(double valor) = 0;
};

#endif