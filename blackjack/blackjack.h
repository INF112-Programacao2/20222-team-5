#ifndef BLACKJACK
#define BLACKJACK

#include <iostream>
#include "../jogo/jogo.h"
#include "MaoBlackjack.h"
#include "baralho.h"
#include "../usuario/usuario.h"

class Blackjack : public Jogo{
    private:
    Baralho _baralho; //variavel baralho que representa o baralho que vai ser utilizado no jogo
    
    public:
    Blackjack();
    MaoBlackjack _player; //variavel da maoblackjack que representa o jogador do jogo
    MaoBlackjack _dealer; // variavel maoblackjack que repesenta o dealer

    int sorteiaCarta(MaoBlackjack &user); //funçao para sortear uma nova carta para o player
    int getOpcao1(int max);             //funçao auxiliar para ajudar na seleçao de escolhas do jogador

    void mainBlackjack(Usuario &user);  //funçao que roda o jogo blackjack em si
};

#endif
