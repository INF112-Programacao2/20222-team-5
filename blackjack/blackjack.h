#include <iostream>
#include "jogo.h"
#include "MaoBlackjack.h"

class Blackjack : public Jogo{
    private:
    MaoBlackjack _player;
    MaoBlackjack _dealer;
    
    public:
    Blackjack(std::string nome, int apostaMinima);

    int sorteiaCarta();

    void setValorApostado(int valor);
    void somaValor(int valor);
};