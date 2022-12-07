#include "blackjack.h"
#include <cstdlib>
#include <exception>

Blackjack::Blackjack(std::string nome, int apostaMinima) : Jogo(nome,apostaMinima){
    _player = MaoBlackjack();
    _dealer = MaoBlackjack();
    _v[54] = {0};
};

int Blackjack::sorteiaCarta(){
    int valor;
    x:
    valor = std::rand() % 54;
    if(_v[valor] == 0){
        goto x;
    }
    _v[valor] = 0;
    return valor;
};

void Blackjack::somaValor(int valor, MaoBlackjack user){
    user.setValorMao(user.getValorMao()+valor);
}

void main(Usuario user){
    double aposta;
    while(true){
        std::cout << "===========================================\nSeja Bem-vindo ao BlackJack!\n===========================================";
        std::cout << "Qual será o valor apostado?: " << std::endl;
        std::cin >> aposta;

        if(user.getFichas() < aposta){
            throw "Saldo de fichas insuficiente!";
        }

        user.setSaldo(user.getSaldo()-aposta);
        
//        setPremiacao(2*aposta);
    }
}