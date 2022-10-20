#include <iostream>
#include "../jogo/jogo.h"

class Jackpot:public Jogo{
    private:
    int *posicoes;
    int *premiacoes;
    int apostaMinima;
    public:
    Jackpot(int posicoes, int premiacoes);
    int getPosicoes();
    int getPremiacoes();
    void setPosicoes();
    void setPremiacoes();
};