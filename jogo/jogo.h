#include <string>
#include "usuario.h"

class Jogo
{
private:
  static int _apostaMinima;
  static std::string _nome;
  Usuario _user;
  int _valorApostado;
  int _premiacao;


public:
  
  Jogo(std::string nome, int apostaMinima);
  Jogo();
  ~Jogo();

  static int getApostaMinima();
  static std::string getNome();
  Usuario getUsuario();
  int getValorApostado();
  int getPremiacao();

  void setValorApostado(int valor);
  void setPremiacao(double valor);
};