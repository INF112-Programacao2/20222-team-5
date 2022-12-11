#include<iostream>
#include"figuras.h"

Figuras::Figuras(){
   _figuras={
     1,2,3,4,5
   };
}
int Figuras::get_figuras(int sort){
  return this-> _figuras[sort];
}
void Figuras::sorteiaFiguras(){
   int sorteia;
   sorteia= std::rand() % 5;
}
void set_figuras(int figuras[],int sort){
  
}