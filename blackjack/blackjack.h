#ifndef BLACKJACK
#define BLACKJACK

#include <iostream>
#include "../jogo/jogo.h"
#include "MaoBlackjack.h"
#include "baralho.h"

class Blackjack : public Jogo{
    private:
//    MaoBlackjack _player;
//    MaoBlackjack _dealer;
    Baralho _baralho;
    
    public:
    Blackjack();
    MaoBlackjack _player;
    MaoBlackjack _dealer;

    int sorteiaCarta(MaoBlackjack user);

    void main();
    void setPremiacao(double valor);
};

#endif
