#ifndef MAOBLACKJACK_H
#define MAOBLACKJACK_H

#include <vector>

class MaoBlackjack{
    private:
    int _valorMao;
    std::vector<int>_mao;
 
    public:
    MaoBlackjack();

    void compraCarta(int valor);

    void imprimeMao();

    int getValorMao();

    void setValorMao(int valor);

};

#endif