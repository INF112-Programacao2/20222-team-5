#include <iostream>
#include "jogo.h"
#include "MaoBlackjack.h"

class Blackjack : public Jogo{
    private:
    MaoBlackjack _player;
    MaoBlackjack _dealer;
    int _v[54];
    
    public:
    Blackjack(std::string nome, int apostaMinima);

    int sorteiaCarta();

    void somaValor(int valor, MaoBlackjack user);
    void main();
    void setPremiacao(double valor);
};