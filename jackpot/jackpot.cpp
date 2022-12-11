#include <iostream>
#include "jackpot.h"
#include "../jogo/jogo.h"
#include "../usuario/usuario.h"
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

Jackpot::Jackpot(Usuario usuario, int aposta)
{
    this->_aposta = aposta;
    this->_apostaminima = 10; // Aposta minima pre-setada como 10
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
void Jackpot::set_pos(int pos1, int pos2, int pos3) // implementado com vetor para n ter 3 sets separados
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
void Jackpot::rodarJack(Usuario &usuario) // funcao principal do Jackpot
{
    Figuras *figuras = new Figuras(); // deletado no final do programa, herda figuras
    int escolha;                      // implementada para depositar ou sair do programa
    int aposta;                       // implementada para escolher o valor apostado
    int zero;                         // iniciador do jogo, rodar o jackpot
    int pos[3];                       // 3 posicoes do jackpot
    std::cout << "Bem-vindo(a) ao Jackpot!! " << std::endl;
    std::cout << "Voce desejar:\n [0]- Sair\n [1]- Depositar para jogar\n";
    std::cin >> escolha;
    switch (escolha)
    {
    case 0:
        break;
    case 1:
        if (usuario.getSaldo() < _apostaminima) // caso o usuario tenha menos que a aposta minima, insere valor da aposta, herda usuario
        {
            int adc;
            std::cout << "Saldo menor que aposta minima :(\n Insira o valor do deposito\n";
            adicionarFundos(usuario); // Funcao craida para adicionar saldo na conta,herda usuario
        }
        std::cout << "Seu novo saldo: " << usuario.getSaldo() << std::endl;
        std::cout << "Escolha o valor que deseja apostar: " << std::endl;
        std::cout << "Voce tem: " << usuario.getSaldo() << std::endl;
        std::cout << "Aposta minima: " << _apostaminima << std::endl;
        std::cin >> aposta;
        if (aposta < 10 || aposta > usuario.getSaldo()) // se for menos que aposta minima ou maior que o saldo do usuario, tem de se apostar um valor valido
        {
            while (true)
            {
                if (aposta < 10)
                {

                    std::cerr << "Valor mais baixo que a aposta minima, por favor insira um valor valido: ";
                    std::cin >> aposta;
                }
                if (aposta > usuario.getSaldo())
                {
                    std::cerr << "Valor mais alto que seu saldo no cassino, por favor insira um valor valido: ";
                    std::cin >> aposta;
                }
                if (aposta >= 10 && aposta <= usuario.getSaldo())
                {
                    std::cout << "Pronto!! Aposta feita!!\n";
                    break;
                }
            }
        }
        break;
    }
    usuario.setSaldo((usuario.getSaldo() - aposta));
    std::cout << "Pressione [0] para rodar o Jackpot!!\n";
    std::cin >> zero;
    if (zero != 0)
    {
        while (true)
        {
            std::cerr << "Apenas o comando [0] inicia o jogo. Qualquer outro comando nao inicia o Jackpot\n Insira novamente:\n";
            std::cin >> zero;
            if (isdigit(zero) == 0)
            {
                break;
            }
        }
    }
    std::cout << "Girando o Jackpot!!" << std::endl; // Gira o Jackpot
    for (int i = 0; i < 3; i++)
    {
        pos[i] = figuras->sorteioGeral();
    }
    for (int i = 0; i < 3; i++)
    {
        switch (pos[i]) // Para cada posicao, uma figura associada, 5 posicoes para ter mais chance de ganhar
        {
        case 0:
            std::cout << "Limao ";
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
        sleep(1); // timer para nao dar cout nas 3 posicoes de vez
    }
    std::cout << std::endl;
    if (pos[0] == pos[1] && pos[1] == pos[2]) // se as 3 posicoes ao iguais, o usuario vence
    {
        std::cout << "Voce venceu!!!!" << std::endl;
        std::cout << "Aqui esta seu premio!!" << std::endl;
        switch (pos[0]) // multiplicadores diferentes de acordo com a imagem obtida
        {
        case 0:
            premiacao = aposta * 5; // Premiacoes herda de Jogo
            std::cout << getPremiacao() << std::endl;
            usuario.setSaldo((usuario.getSaldo() + premiacao)); // Soma as premiacoes com o que o usuario ja tem
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
            std::cout << getPremiacao() << std::endl; // getPremiacao vem de jogo
            usuario.setSaldo((usuario.getSaldo() + premiacao));
            std::cout << "Seu novo saldo: " << usuario.getSaldo();
            break;
        case 3: // Jackpot o de maior valor, entao tem uma interacao diferente
            premiacao = aposta * 20;
            std::cout << "Parabens!! Voce ganhou o Jackpot!!" << std::endl;
            std::cout << "Sua quantia: " << getPremiacao() << std::endl; // cout nas premiacoes
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
        repetirJogada(usuario); // Funcao criada caso o usuario deseje jogar novamente
    }
    else
    {
        std::cout << "Voce perdeu :(\n";
        repetirJogada(usuario);
    }
    delete figuras; // figuras deletadas
}
int Jackpot::repetirJogada(Usuario &usuario) // repete a jogada
{
    int repetir;
    std::cout << "Deseja apostar novamente?\n[0]-Nao\n[1]-Sim\n";
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
    if (repetir == 1)
    {
        rodarJack(usuario); // chama rodar blackjack para rodar o programa novamente
    }
    return 0;
}
void Jackpot::adicionarFundos(Usuario &usuario) // funcao adicionar fundos caso o saldo seja menor que a aposta minima
{
    int adiciona;
    std::cout << "Indique o valor que deseja depositar:\n ";
    std::cin >> adiciona;
    usuario.setSaldo((usuario.getSaldo() + adiciona)); // soma os valores adicionados ao saldo do usuario
}
