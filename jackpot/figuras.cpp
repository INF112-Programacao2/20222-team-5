#include<iostream>
#include"figuras.h"
#include "ctime"
#include<unistd.h>

Figuras::Figuras(){}
int Figuras::get_figuras(int sort){
  return _figuras[sort];
}
int Figuras::sorteiaFiguras(){
  sleep(1);
  unsigned seed = time(0);
  srand(seed);
   int sorteia;
   sorteia= std::rand() % 5;
   return sorteia;
}
