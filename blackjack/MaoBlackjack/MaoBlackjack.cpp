#include "MaoBlackjack.h"
#include <iostream>

MaoBlackjack::MaoBlackjack(){
    _valorMao = 0;
};

int MaoBlackjack::getValorMao(){
    return this->_valorMao;
}

void MaoBlackjack::setValorMao(int valor){
    this->_valorMao = valor; 
}