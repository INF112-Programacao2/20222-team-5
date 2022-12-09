#ifndef BARALHO_H  
#define BARALHO_H


#include <vector>
#include <cstdlib>

class Baralho {
    private:
    std::vector<int> _cartas;
    public: 
    
    const int J = 10;
    const int Q = 10;
    const int K = 10;
    int A = 11;
    
    Baralho();
    int getCarta(int pos);
    int Baralho::tiraCarta(int pos);

};

#endif