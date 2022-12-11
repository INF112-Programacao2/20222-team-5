#include "blackjack.h"
#include <cstdlib>
#include <exception>
#include <unistd.h>

Blackjack::Blackjack(){
    _player = MaoBlackjack();
    _dealer = MaoBlackjack();
    _baralho.initBaralho();
};

int Blackjack::sorteiaCarta(MaoBlackjack &jogador){
    int valor;
    int aux=0;
    
    sleep(1);
    unsigned seed = time(0);
    srand(seed);
    x:
    valor = std::rand() % 52;
    if(_baralho.getCarta(valor) == 0){
        goto x;
    }
    if(valor >52){
        goto x;
    }
    if(valor<0){
        goto x;
    }
    
    aux = valor;
    valor = _baralho.getCarta(valor);
    _baralho.tiraCarta(aux);
    if((jogador.getValorMao()+valor) > 21 && valor == 11){
        valor = 1;
    }   
    jogador.compraCarta(valor);
    jogador.setValorMao((jogador.getValorMao()+valor));

    return valor;
};


void Blackjack::mainBlackjack(Usuario &user){
    bool venceu=NULL;
    bool empate=NULL;
    bool quit=false;
    double aposta;
    Blackjack game;
    
    game._baralho.initBaralho();
    std::cout << "===========================================\nSeja Bem-vindo ao BlackJack!\n===========================================\n";
    std::cout << "Qual sera o valor apostado?: " << std::endl;
    try{
        std::cin >> aposta;

        if(user.getSaldo() < aposta){
            throw std::invalid_argument("Saldo de fichas insuficiente!");
        }
    }
    catch(std::invalid_argument &e){
        std::cerr << e.what();
    }

    user.setSaldo(user.getSaldo()-aposta);

    std::cout << "\nO jogo comecou!\n";
    std::cout << "Lembre-se que o dealer para com 17!\n";

    std::cout << "O dealer tirou as cartas: " << game.sorteiaCarta(game._dealer) << " " <<game.sorteiaCarta(game._dealer) << std::endl;
    std::cout << "Voce tirou as cartas: "<< game.sorteiaCarta(game._player) << " " <<game.sorteiaCarta(game._player) << std::endl;

    while(!quit){
        z:
        if(game._player.getValorMao()>21){
            venceu = false;
            break;
        }
        if(game._player.getValorMao()==21){
            std::cout << "Blackjack!" << std::endl;
            venceu = true;
            break;
        }
        if(game._dealer.getValorMao()==21){
            std::cout << "Blackjack do dealer! " << std::endl;
            venceu = false;
            break;
        }

        std::cout << "O dealer tem: " << game._dealer.getValorMao() << " pontos\n";
        std::cout << "Voce tem: " << game._player.getValorMao() << " pontos\n";
        std::cout << "\no que voce deseja fazer?: \n(0)-Comprar carta\n(1)-Deixar o dealer comprar\n(2)-Ver suas cartas\n(3)-Ver cartas do dealer\n";

        switch(game.getOpcao1(3)){
            case 0:
            std:: cout << "Voce tirou: " << game.sorteiaCarta(game._player) << std::endl;
            goto z;
            break;
            case 1:
            y:
            if(game._dealer.getValorMao()<17){
                std::cout << "O dealer tirou: " << game.sorteiaCarta(game._dealer) <<std::endl;
                goto y;
            }
            if(game._dealer.getValorMao()>21){
                venceu = true;
            }
            quit = true;
            break;
            case 2:
            std::cout << "suas cartas sao: "; 
            game._player.imprimeMao();
            std::cout << std::endl;
            goto z;
            break;
            case 3: 
            std::cout << "as cartas do dealer sao: "; 
            game._dealer.imprimeMao();
            goto z;
            break;
        }
        if(venceu==true || venceu == false){
            break;
        }
    }
    if(game._player.getValorMao()<21 && game._dealer.getValorMao() < 21){
        if(game._player.getValorMao()<game._dealer.getValorMao()){
            venceu = false;
        }
        else if(game._player.getValorMao()==game._dealer.getValorMao()){
            std::cout << "Empate!" << std::endl;
            empate = true;
        }
        else{
            venceu = true;
        }
    }
    if(venceu){
        std::cout << "Voce venceu!" << std::endl;
        user.setSaldo(user.getSaldo()+(2*aposta));
        std::cout << "A premiacao foi de: " << (2*aposta) << std::endl;
    }
    if(!venceu && !empate){
        std::cout << "O dealer venceu!" <<std::endl;
    }
    if(empate){
        std::cout << "O seu dinheiro foi devolvido!" << std::endl;
        user.setSaldo(user.getSaldo()+(aposta));
    }
}



int Blackjack::getOpcao1(int maximo)
{
  int opcao;
  while (true)
  {
    std::cin >> opcao;
    if (opcao >= 0 && opcao <= maximo)
    {
      return opcao;
    }
    else
    {
      std::cout << "Opcao invalida, por favor digite um número entre 0 e " << maximo << std::endl;
    }
  }
}