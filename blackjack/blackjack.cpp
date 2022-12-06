#include "blackjack.h"
#include <cstdlib>

Blackjack::Blackjack(std::string nome, int apostaMinima) : Jogo(nome,apostaMinima){
    _player = MaoBlackjack();
    _dealer = MaoBlackjack();
};

int Blackjack::sorteiaCarta(){

};