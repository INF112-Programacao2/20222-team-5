#include <iostream>
#include "jackpot.h"
#include "../jogo/jogo.h"

Jackpot::Jackpot(Usuario usuario,int posicoes,int premiacoes){
    this-> posicoes=new int[3];
    this-> premiacoes=new int[20];
    this-> apostaMinima=apostaMinima;
};