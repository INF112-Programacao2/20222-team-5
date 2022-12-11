#include <iostream>
#include "figuras.h"
#include "ctime"
#include <unistd.h>

Figuras::Figuras() {}
int Figuras::get_figuras(int sort)
{
  return _figuras[sort];
}
int Figuras::sorteiaFiguras()
{ // sorteia as figuras diferentes
  sleep(1);
  unsigned seed = time(0);
  srand(seed);
  int sorteia;
  sorteia = std::rand() % 5;
  return sorteia;
}
int Figuras::sorteiaFigurascorretas()
{ // sorteia figuras iguais e o usuario ganha o jogo
  unsigned seed = time(0);
  srand(seed);
  int sorteia;
  sorteia = std::rand() % 5;
  return sorteia;
}
int Figuras::sorteioGeral()
{ // sorteia se vai se figuras corretas o figuras diferentes, de 1 para 10 para dar certo
  int sorteia;
  int sorteia2;
  unsigned seed = time(0);    // faz com que o seed n de igual sempre
  srand(seed);                // randomiza o seed
  sorteia = std::rand() % 10; // sorteia de 1 a 10
  sorteia2= std::rand() % 10; //sorteia de 1 a 10 para nao dar o mesmo numero
  if (sorteia == sorteia2)
  {
    return sorteiaFigurascorretas(); // retorna para dar certo caso sorteia=1
  }
  else
  {
    return sorteiaFiguras(); // caso sorteia>1 retorna figuras diferentes
  }
}
