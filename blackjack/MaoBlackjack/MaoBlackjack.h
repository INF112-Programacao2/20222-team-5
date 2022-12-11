#ifndef MAOBLACKJACK_H
#define MAOBLACKJACK_H

class MaoBlackjack{
    private:
    int _valorMao;
    int _nCartas;
//    int _mao[10] = {0,0,0,0,0,0,0,0,0,0};
    std::vector<int> _mao;
    public:
    MaoBlackjack();

    int getValorMao();

    int setCartas(int carta);

    int getCartas(int i);

    void setValorMao(int valor);

    void imprimeMao();
};

#endif