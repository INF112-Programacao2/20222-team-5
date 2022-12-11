#ifndef BLACKJACK
#define BLACKJACK

#include <iostream>
#include "../jogo/jogo.h"
#include "MaoBlackjack.h"
#include "baralho.h"
#include "../usuario/usuario.h"

class Blackjack : public Jogo{
    private:
    Baralho _baralho;
    
    public:
    Blackjack();
    MaoBlackjack _player;
    MaoBlackjack _dealer;

    int sorteiaCarta(MaoBlackjack &user);
    int getOpcao1(int max);

    void mainBlackjack(Usuario &user);
    void setPremiacao(double valor);
};

#endif
