#include "jogo.h"
#include <string>

Jogo::Jogo() {}

Jogo::~Jogo() {}

Usuario Jogo::getUsuario(){ 
    return user;
}

int Jogo::getValorApostado(){
    return valorApostado;
}

int Jogo::getPremiacao(){
    return premiacao;
}

void Jogo::setValorApostado(double valor){
    valorApostado = valor;
}

void Jogo::setPremiacao(double valor){
    premiacao = valor;
}
