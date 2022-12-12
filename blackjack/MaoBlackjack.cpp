#include "MaoBlackjack.h"
#include <iostream>

MaoBlackjack::MaoBlackjack(){
    _valorMao = 0;          //inicializa uma mao nova sem nenhuma carta
};

int MaoBlackjack::getValorMao(){
    return this->_valorMao;
}

void MaoBlackjack::setValorMao(int valor){
    _valorMao = valor; 
}

void MaoBlackjack::compraCarta(int valor){ //adiciona a carta na ultima posiçao do vector correspondente a mao do jogador 
    _mao.push_back(valor);
}

void MaoBlackjack::imprimeMao(){
    for(int i=0;i<_mao.size();i++){     //imprime as cartas presentes na mao do jogador
        std::cout << _mao[i] << " ";
    }
    std::cout << std::endl;
}

