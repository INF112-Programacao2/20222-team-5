#include <iostream>
#include "jackpot.h"
#include "../jogo/jogo.h"
#include "../usuario/usuario.h"
#include <stdlib.h>
#include <unistd.h>

Jackpot::Jackpot(Usuario usuario, int aposta)
{
    this->_aposta = aposta;
    this->_apostaminima = 10;
};
int Jackpot::get_pos0()
{
    return this->_pos[0];
}
int Jackpot::get_pos1()
{
    return this->_pos[1];
}
int Jackpot::get_pos2()
{
    return this->_pos[2];
}
void Jackpot::set_pos(int pos1, int pos2, int pos3)
{
    int aux[3] = {pos1, pos2, pos3};
    for (int i = 0; i < 3; i++)
    {
        this->_pos[i] = aux[i];
    }
}
void Jackpot::set_valorAposta(int aposta)
{
    this->_aposta = aposta;
}
int Jackpot::get_valorAposta()
{
    return this->_aposta;
}
void Jackpot::rodarJack(Usuario &usuario)
{
    Figuras figuras;
    int escolha;
    int aposta;
    int zero;
    int pos[3];
    std::cout << "Bem-vindo(a) ao Jackpot!! " << std::endl;
    std::cout << "Voce desejar:\n [0]- Sair\n [1]- Depositar para jogar\n";
    std::cin >> escolha;
    switch (escolha)
    {
    case 0:
        break;
    case 1:
        if(usuario.getSaldo()< _apostaminima){
            std::cout <<"Saldo menor que aposta minima :(\nDeposite mais para continuar\n";
            adicionarFundos(usuario);
            std::cout << "Seu novo saldo: " << usuario.getSaldo() << std::endl;
        }
        std::cout << "Escolha o valor que deseja apostar: " << std::endl;
        std::cout << "Voce tem: " << usuario.getSaldo() << std::endl;
        std::cout << "Aposta minima: " << _apostaminima << std::endl;
        std::cin >> aposta;
        if (aposta < 10 || aposta > usuario.getSaldo())
        {
            while (true)
            {
                if (aposta < 10)
                {

                    std::cout << "Valor mais baixo que a aposta minima, por favor insira um valor valido: ";
                    std::cin >> aposta;
                }
                if (aposta > usuario.getSaldo())
                {
                    std::cout << "Valor mais alto que seu saldo no cassino, por favor insira um valor valido: ";
                    std::cin >> aposta;
                }
                if (aposta >= 10 && aposta < usuario.getSaldo())
                {
                    std::cout << "Pronto!! Aposta feita!!\n";
                    break;
                }
            }
        }
        break;
    }
    usuario.setSaldo((usuario.getSaldo() - aposta));
    std::cout << "Pressione 0 para rodar o Jackpot!!\n";
    std::cin >> zero;
    if (zero != 0)
    {
        while (true)
        {
            std::cout << "Apenas o comando 0 inicia o jogo qualquer outro comando nao inicia o Jackpot";
            std::cin >> zero;
            if (zero == 0)
            {
                break;
            }
        }
    }
    std::cout << "Girando o Jackpot!!" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        pos[i] = figuras.sorteiaFiguras();
    }
    for (int i = 0; i < 3; i++)
    {
        switch (pos[i])
        {
        case 0:
            std::cout << "Maca ";
            break;
        case 1:
            std::cout << "Banana ";
            break;
        case 2:
            std::cout << "Moeda ";
            break;
        case 3:
            std::cout << "Jackpot ";
            break;
        case 4:
            std::cout << "7 ";
            break;
        }
        sleep(1);
    }
    std::cout << std::endl;
    if (pos[0] == pos[1] && pos[1] == pos[2])
    {
        std::cout << "Voce venceu!!!!" << std::endl;
        std::cout << "Aqui esta seu premio!!" << std::endl;
        switch (pos[0])
        {
        case 0:
            premiacao = aposta * 5;
            std::cout << getPremiacao() << std::endl;
            usuario.setSaldo((usuario.getSaldo() + premiacao));
            std::cout << "Seu novo saldo: " << usuario.getSaldo();
            break;
        case 1:
            premiacao = aposta * 10;
            std::cout << getPremiacao() << std::endl;
            usuario.setSaldo((usuario.getSaldo() + premiacao));
            std::cout << "Seu novo saldo: " << usuario.getSaldo();
            break;
        case 2:
            premiacao = aposta * 8;
            std::cout << getPremiacao() << std::endl;
            usuario.setSaldo((usuario.getSaldo() + premiacao));
            std::cout << "Seu novo saldo: " << usuario.getSaldo();
            break;
        case 3:
            premiacao = aposta * 20;
            std::cout << "Parabens!! Voce ganhou o Jackpot!!" << std::endl;
            std::cout << "Sua quantia: " << getPremiacao() << std::endl;
            usuario.setSaldo((usuario.getSaldo() + premiacao));
            std::cout << "Seu novo saldo: " << usuario.getSaldo();
            break;
        case 4:
            premiacao = aposta * 15;
            std::cout << getPremiacao() << std::endl;
            usuario.setSaldo((usuario.getSaldo() + premiacao));
            std::cout << "Seu novo saldo: " << usuario.getSaldo();
            break;
        }
        std::cout << std::endl;
        std::cout << "Parabens !!\n";
        repetirJogada(usuario);
    }
    else
    {
        std::cout << "Voce perdeu :(\n";
        repetirJogada(usuario);
    }
}
int Jackpot::repetirJogada(Usuario &usuario)
{
    int repetir;
    std::cout << "Deseja apostar novamente?\n [0]-NAO\n [1]-SIM\n";
    std::cin >> repetir;
    if (repetir != 0 && repetir != 1)
        while (true)
        {
            std::cout << "Apenas 0 ou 1: ";
            std::cin >> repetir;
            if (repetir == 0 || repetir == 1)
            {
                break;
            }
        }
    if(repetir==1){
        rodarJack(usuario);
    }
    return 0;
}
void Jackpot::adicionarFundos(Usuario &usuario){
    int adiciona;
    std::cout << "Indique o valor que deseja depositar:\n ";
    std::cin >> adiciona;
    usuario.setSaldo((usuario.getSaldo()+adiciona));
}
