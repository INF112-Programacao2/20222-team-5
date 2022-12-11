#ifndef FIGURAS
#define FIGURAS
#include <iostream>
#include <vector>
#include <string>
static int _figuras[5] = {1, 2, 3, 4, 5};
class Figuras // Classe criada para randomizar as "figuras" que aparecerao no jackpot
{
public:
    Figuras();
    int get_figuras(int sort);
    int sorteiaFiguras();         // sorteia figuras, so da figuras diferentes, logo implementei uma para dar figuras iguais
    int sorteiaFigurascorretas(); // sorteia as figuras iguais e faz com que o usuario ganhe o jogo
    int sorteioGeral();           // esse sorteia de 1 a 10, caso 1, chama sorteia figuras corretas, caso o resto, sorteia figuras diferentes
};

#endif