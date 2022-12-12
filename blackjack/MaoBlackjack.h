#ifndef MAOBLACKJACK_H
#define MAOBLACKJACK_H

#include <vector>

class MaoBlackjack{
    private:
    int _valorMao;      //valor da soma da mao do jogador
    std::vector<int>_mao; // vector com as cartas presentes na mao do jogador
 
    public:
    MaoBlackjack();

    void compraCarta(int valor); //adiciona carta no vector

    void imprimeMao(); //imprime cvartas presentes na mao do jogador

    int getValorMao(); //retorna a soma das cartas da mao

    void setValorMao(int valor); //setter

};

#endif