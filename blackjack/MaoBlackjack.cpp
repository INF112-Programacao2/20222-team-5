#include "MaoBlackjack.h"
#include <iostream>

MaoBlackjack::MaoBlackjack(){
    _valorMao = 00;
};

int MaoBlackjack::getValorMao(){
    return this->_valorMao;
}

void MaoBlackjack::setValorMao(int valor){
    _valorMao = valor; 
}

void MaoBlackjack::compraCarta(int valor){
    _mao.push_back(valor);
}

void MaoBlackjack::imprimeMao(){
    for(int i=0;i<_mao.size();i++){
        std::cout << _mao[i] << " ";
    }
    std::cout << std::endl;
}

