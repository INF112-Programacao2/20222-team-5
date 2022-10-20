#include <iostream>
#include "jogo/roleta/roleta.h"

int getOpcao(int);

int main(void)
{
  std::cout << "Seja bem vindo ao cassino ..." << std::endl;
  Usuario u("Arthur", "arthur@gmail.com", "12345", 1000);
  std::cout << "Qual jogo gostaria de jogar?" << std::endl;
  std::cout << "(0) - Blackjack" << std::endl;
  std::cout << "(1) - Roleta" << std::endl;
  std::cout << "(2) - Jackpot" << std::endl;
  getOpcao(2);
  Roleta r(u, "vermelho", 1000);
}

int getOpcao(int maximo)
{
  int opcao;
  while (true)
  {
    std::cin >> opcao;
    if (opcao >= 0 || opcao <= maximo)
    {
      return opcao;
    }
    else
    {
      std::cout << "Opção invalida, por favor digite um número entre 0 e " << maximo << std::endl;
    }
  }
}