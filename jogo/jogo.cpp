#include "jogo.h"
#include <string>

int Jogo::getApostaMinima()
{
    return _apostaMinima;
}

std::string Jogo::getNome(){
    return _nome;
}

Usuario Jogo::getUsuario(){ 
}

int Jogo::getValorApostado(){
    return _valorApostado;
}

int Jogo::getPremiacao(){
    return _premiacao;
}

void Jogo::setValorApostado(double valor){
    _valorApostado = valor;
}

void Jogo::setPremiacao(double valor){
    _premiacao = valor;
}
