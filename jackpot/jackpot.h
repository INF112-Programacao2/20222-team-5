#ifndef JACKPOT
#define JACKPOT
#include <iostream>
#include "../jogo/jogo.h"
#include "../usuario/usuario.h"
#include "figuras.h"

class Jackpot:public Jogo{
    private:
    Usuario usuario;
    int _pos[3];
    int _aposta;
    int _apostaminima;
    Figuras _figuras;
    public:
    Jackpot(Usuario usuario,int aposta);
    void rodarJack(Usuario &usuario);
    int get_pos0();
    int get_pos1();
    int get_pos2();
    void set_pos(int pos1, int pos2, int pos3);
    void set_valorAposta(int aposta);
    int  get_valorAposta();
    int get_premiacao();
    void set_premiacao(int premiacao);
    int repetirJogada(Usuario &usuario);
    void adicionarFundos(Usuario &usuario);
};

#endif