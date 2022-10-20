#include <string>

class Jogo
{
private:
  static int apostaMinima;

public:
  static int getApostaMinima();
  Jogo(std::string nome, int apostaMinima);
  Jogo();
  ~Jogo();
};