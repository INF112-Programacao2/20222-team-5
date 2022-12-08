#ifndef JACKPOT

#include <iostream>
#include "../jogo/jogo.h"
#include "../usuario/usuario.h"

class Jackpot:public Jogo{
    private:
    Usuario usuario;
    int *posicoes;
    int *premiacoes;
    int apostaMinima;
    public:
    Jackpot(Usuario usuario,int posicoes, int premiacoes);
    int getPosicoes();
    int getPremiacoes();
    void setPosicoes();
    void setPremiacoes();
};

#endif