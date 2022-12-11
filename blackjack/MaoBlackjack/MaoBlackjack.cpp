#include "MaoBlackjack.h"
#include <iostream>

MaoBlackjack::MaoBlackjack(){
    _valorMao = 0;
    _nCartas = -1;
};

int MaoBlackjack::getCartas(int i){
    return this->_mao[i];
}
int MaoBlackjack::setCartas(int carta){
    this->_cartas[_nCartas + 1] = carta;
}

int MaoBlackjack::getValorMao(){
    return this->_valorMao;
}

void MaoBlackjack::setValorMao(int valor){
    this->_valorMao = valor; 
}

void MaoBlackjack::imprimeMao(){
    
}

