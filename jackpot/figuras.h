#ifndef FIGURAS
#define FIGURAS
#include<iostream>
#include<vector>
#include<string>

class Figuras{
    private:
    std::vector<int>_figuras;
    public:
    int get_figuras(int sort);
    void sorteiaFiguras();
};

#endif