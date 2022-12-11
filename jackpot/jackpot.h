#ifndef JACKPOT
#define JACKPOT
#include <iostream>
#include "../jogo/jogo.h"
#include "../usuario/usuario.h"
#include "figuras.h"

class Jackpot : public Jogo
{
private:
    Usuario usuario;   // um usuario
    int _pos[3];       // tres posicoes do jackpot
    int _aposta;       // valor da aposta
    int _apostaminima; // aposta minima setada para 10
    Figuras _figuras;  // classe figuras
public:
    Jackpot(Usuario usuario, int aposta); // funcoes utilizadas
    int rodarJack(Usuario &usuario);     // funcao principal, a que roda o jackpot, botei ela para a main nao ficar cheia
    int get_pos0();                       // get de cada posicao
    int get_pos1();
    int get_pos2();
    void set_pos(int pos1, int pos2, int pos3); // um set para todas as posicoes
    void set_valorAposta(int aposta);           // seta o valor da aposta
    int get_valorAposta();                      // pega o valor da posta para utilizar no codigo
    int repetirJogada(Usuario &usuario);        // funcao caso o usuario queira jogar novamente
    void adicionarFundos(Usuario &usuario);     // adiciona fundos caso o usuario nao tenha saldo suficiente para a aposta minima
};

#endif