#include "blackjack.h"
#include <cstdlib>
#include <exception>

Blackjack::Blackjack() : Jogo(){
    _player = MaoBlackjack();
    _dealer = MaoBlackjack();
};

int Blackjack::sorteiaCarta(MaoBlackjack user){
    int valor;
    x:
    valor = std::rand() % 52;
    if(_baralho.getCarta(valor) == 0){
        goto x;
    }
    _baralho.tiraCarta(valor);

    user.setCartas(valor);

    return valor;
};

void Blackjack::somaValor(int valor, MaoBlackjack user){
    user.setValorMao(user.getValorMao()+valor);
}

void main(Usuario user){
    double aposta;
    Blackjack blackjack();
    while(true){
        std::cout << "===========================================\nSeja Bem-vindo ao BlackJack!\n===========================================";
        std::cout << "Qual será o valor apostado?: " << std::endl;
        std::cin >> aposta;

        if(user.getFichas() < aposta){
            throw "Saldo de fichas insuficiente!";
        }

        user.setSaldo(user.getSaldo()-aposta);

        while(true){
            std::cout << "O jogo comecou!\n";
        }
    }
}