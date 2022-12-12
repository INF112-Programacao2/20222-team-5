#include "baralho.h"

Baralho::Baralho(){} //construtor

int Baralho::getCarta(int pos){ //retorna valor da carta da respectiva posiçao 
    return this->_cartas[pos];
}

void Baralho::tiraCarta(int pos){ //seta a posiçao do vetor pra zero, sendo assim, a carta foi retirada do baralho
    this->_cartas[pos] = 0;
}
void Baralho::initBaralho(){    //funçao que inicializa um baralho novo
    _cartas = {
        2,3,4,5,6,7,8,9,10,J,Q,K,A,
        2,3,4,5,6,7,8,9,10,J,Q,K,A,
        2,3,4,5,6,7,8,9,10,J,Q,K,A,
        2,3,4,5,6,7,8,9,10,J,Q,K,A,
    };
}