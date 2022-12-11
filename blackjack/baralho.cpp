#include "baralho.h"

Baralho::Baralho(){}

int Baralho::getCarta(int pos){
    return this->_cartas[pos];
}

void Baralho::tiraCarta(int pos){
    this->_cartas[pos] = 0;
}
void Baralho::initBaralho(){
    _cartas = {
        2,3,4,5,6,7,8,9,J,Q,K,A,
        2,3,4,5,6,7,8,9,J,Q,K,A,
        2,3,4,5,6,7,8,9,J,Q,K,A,
        2,3,4,5,6,7,8,9,J,Q,K,A,
    };
}