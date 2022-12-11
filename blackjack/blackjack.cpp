#include "blackjack.h"
#include <cstdlib>
#include <exception>

std::string Jogo::nome = "Blackjack";

Blackjack::Blackjack(){
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

    user.setValorMao(user.getValorMao()+valor);

    return valor;
};

void mainBlackjack(Usuario user){
    double aposta;
    Blackjack game;
    while(true){
        std::cout << "===========================================\nSeja Bem-vindo ao BlackJack!\n===========================================";
        std::cout << "Qual será o valor apostado?: " << std::endl;
        std::cin >> aposta;

        if(user.getSaldo() < aposta){
            throw std::invalid_argument("Saldo de fichas insuficiente!");
        }

        user.setSaldo(user.getSaldo()-aposta);

        while(true){
            std::cout << "O jogo comecou!\n";
        }
    }
}