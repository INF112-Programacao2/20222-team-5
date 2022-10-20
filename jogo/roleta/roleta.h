#include "../jogo.h"
#include "../../usuario/usuario.h"
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
  Roleta(Usuario user, std::string corAposta, int valorApostado);
};
