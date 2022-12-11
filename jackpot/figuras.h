#ifndef FIGURAS
#define FIGURAS
#include<iostream>
#include<vector>
#include<string>
    static int _figuras[5]={1,2,3,4,5};
class Figuras{
    public:
    Figuras();
    int get_figuras(int sort);
    int sorteiaFiguras();
};

#endif