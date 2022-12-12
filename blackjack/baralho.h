#ifndef BARALHO_H  
#define BARALHO_H


#include <vector>
#include <cstdlib>

class Baralho {
    private:
    std::vector<int> _cartas; //vector com as 52 cartas do baralho
    public: 
    
    const int J = 10;   //
    const int Q = 10;   //  cartas nao numericas
    const int K = 10;   //
    const int A = 11;   //
    
    Baralho();
    int getCarta(int pos);
    
    void tiraCarta(int pos);//funçao para remover carta do do baralho
    
    void initBaralho(); //funçao que inicia o baralho com ttodas as suas cartas

};

#endif