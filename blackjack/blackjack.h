#ifndef BLACKJACK
#define BLACKJACK

#include <iostream>
#include "jogo.h"
#include "MaoBlackjack.h"
#include "baralho.h"

class Blackjack : public Jogo{
    private:
    MaoBlackjack _player;
    MaoBlackjack _dealer;
    Baralho _baralho;
    
    public:
    Blackjack();

    int sorteiaCarta(MaoBlackjack user);

    void somaValor(int valor, MaoBlackjack user);
    void main();
    void setPremiacao(double valor);
};

#endif
