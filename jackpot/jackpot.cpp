#include <iostream>
#include "jackpot.h"
#include "../jogo/jogo.h"
#include "../usuario/usuario.h"

Jackpot::Jackpot(Usuario usuario,int posicoes,int premiacoes, Figuras figuras,  int apostaminima){
    _figuras=figuras;
    this-> posicoes=new int[5];
    this-> premiacoes=new int[20];
    this-> _apostaMinima=apostaminima;
    apostaminima=10;
};

void Jackpot::rodarJack(Usuario usuario){
    int escolha;
    int aposta;
    std::cout << "Bem-vindo(a) ao Jackpot!! "<<std::endl;
    std::cout << "Voce desejar:\n [0]- Sair\n [1]- Depositar para jogar\n" << std::endl;
    std::cin >> escolha;
    switch(escolha){
        case 0:
        break;
        case 1:
        std::cout << "Escolha o valor que deseja depositar: "<< std::endl;
        std::cout << "Voce tem: "<< usuario.getSaldo() << std::endl;
        std::cout << "Aposta minima: " << 10 << std::endl;
        std::cin >> aposta;
        if(aposta<10){
        while(true){
           std::cerr << "Valor mais baixo que a aposta minima, por favor insira um valor valido: ";
           std::cin >> aposta;
           if(aposta>10){
            break;
           }
        }
        }
        if(aposta>usuario.getSaldo()){
        while(true){
            std::cerr << "Valor mais alto que seu saldo no cassino, por favor insira um valor valido: ";
            std::cin >> aposta;
            if(aposta<usuario.getSaldo()){
                break;
            }
        }
    }
}
}
