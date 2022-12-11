#ifndef JACKPOT
#define JACKPOT
#include <iostream>
#include "../jogo/jogo.h"
#include "../usuario/usuario.h"
#include "figuras.h"

class Jackpot:public Jogo{
    private:
    Usuario usuario;
    int *posicoes;
    int *premiacoes;
    int _apostaMinima;
    Figuras _figuras;
    public:
    Jackpot(Usuario usuario,int posicoes, int premiacoes, Figuras figuras, int apostaminima);
    int rodarJack(Usuario usuario);
    // int getPremiacoes();
    // void setPosicoes();
    // void setPremiacoes();
    void valorAposta();
};

#endif