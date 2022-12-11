#ifndef ROLETA

#include "../jogo.h"
#include "../../usuario/usuario.h"
#include <string>

static int vermelho[18] = {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36};
static int preto[18] = {2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24, 26, 28, 29, 31, 33, 35};

class Roleta : public Jogo
{
private:
  Usuario user;
  std::string corAposta;
  int numeroAposta;
  std::string resultadoCor;
  int resultadoNumero;
  int fileira;

public:
  Roleta(Usuario user, std::string corAposta, int valorApostado, int numeroAposta);
  void sorteiaResultado();
  int getFileira();
  void setFileira(int fileira);
  std::string getResultadoCor();
  int getResultadoNumero();
  int getPremiacao();
  void setPremiacao(int premiacao);
};

#endif
