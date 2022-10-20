#include <string>

class Jogo
{
private:
  std::string nome;
  int apostaMinima;

public:
  Jogo(std::string nome, int apostaMinima);
  Jogo();
  ~Jogo();
};