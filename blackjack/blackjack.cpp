#include "blackjack.h"
#include <cstdlib>
#include <ctime>
#include <exception>
#include <unistd.h>

Blackjack::Blackjack(){
    _player = MaoBlackjack();   //player e dealer quue jogam o jogo
    _dealer = MaoBlackjack();   //
    _baralho.initBaralho();     //função que inicia o baralho com todas as cartas
};

int Blackjack::sorteiaCarta(MaoBlackjack &jogador){ //funçao que sorteia uma carta para o jogador que esta jogando
    int valor;      //
    int aux=0;      //variaveis auxiliares
    
    sleep(1);   //funçao para dar mais realismo ao jogo na hora de entregar as cartas
    unsigned seed = time(0);
    srand(seed);
    x:
    valor = std::rand() % 52; //numero randomico entre 0 e 52 representando uma carta do baralho
    if(_baralho.getCarta(valor) == 0){//caso a carta ja tenha sido retirada do baralho, refaz o rand
        goto x; //vai para linha 19 
    }
    if(valor >52){
        goto x; //vai para linha 19
    }
    if(valor<0){
        goto x; //vai para a linha 19
    }
    
    aux = valor; //salvando a posiçao da carta no vextor
    valor = _baralho.getCarta(valor); //valor assume o valor numerico da carta que a posiçao randomizada representa
    _baralho.tiraCarta(aux);//tira a carta do baralho igualando sua posiçao a 0
    if((jogador.getValorMao()+valor) > 21 && valor == 11){ //if para implementar a regra em que o as pode valer 1 ou 11
        valor = 1;
    }   
    jogador.compraCarta(valor); //coloca a carta no vetor mao do jogador
    jogador.setValorMao((jogador.getValorMao()+valor)); //soma o valor da carta tirada a mao do jogador

    return valor; //retorna o valor que a carta possui para o jogo
};


void Blackjack::mainBlackjack(Usuario &user){
    bool venceu=NULL;   //
    bool empate=NULL;   //variaveis para indicar se o jogador venceu ou perdeu
    bool quit=false;    //variavel para o loop
    double aposta;      // variavel que representa a aposta
    Blackjack game;     
    
    game._baralho.initBaralho(); //iniccializando o baralho 
    std::cout << "===========================================\nSeja Bem-vindo ao BlackJack!\n===========================================\n";
    w:
    std::cout << "Qual sera o valor apostado?: " << std::endl;
    std::cin >> aposta;

    if(aposta<=0){
        std::cout << "O valor apostado deve ser maior que zero!" << std::endl;
        goto w;
    }
    if(user.getSaldo() < aposta){ //caso o usuario nao tenha o valor da aposta, pergunta novamente
        std::cout << "Saldo de fichas insuficiente!" << std::endl;
        goto w;
    }

    Jogo::setValorApostado(aposta);
    Jogo::setPremiacao(2*aposta);
    user.setSaldo(user.getSaldo()-Jogo::getValorApostado()); //seta o novo saldo da aposta

    std::cout << "\nO jogo comecou!\n";
    std::cout << "Lembre-se que o dealer para com 17!\n";

    std::cout << "O dealer tirou as cartas: " << game.sorteiaCarta(game._dealer) << " " <<game.sorteiaCarta(game._dealer) << std::endl; //compra as cartas do dealer
    std::cout << "Voce tirou as cartas: "<< game.sorteiaCarta(game._player) << " " <<game.sorteiaCarta(game._player) << std::endl; //compra as cartas do jogador

    while(!quit){ //loop do jogo
        z:
        if(game._player.getValorMao()>21){ //confere em todo loop se algum ganhou ou perdeu
            venceu = false;
            break;
        }
        if(game._player.getValorMao()==21){//confere em todo loop se algum ganhou ou perdeu
            std::cout << "Blackjack!" << std::endl;
            venceu = true;
            break;
        }
        if(game._dealer.getValorMao()==21){//confere em todo loop se algum ganhou ou perdeu
            std::cout << "Blackjack do dealer! " << std::endl;
            venceu = false;
            break;
        }

        std::cout << "O dealer tem: " << game._dealer.getValorMao() << " pontos\n"; //mostra as somas das maos do dealer e do player
        std::cout << "Voce tem: " << game._player.getValorMao() << " pontos\n";
        std::cout << "\no que voce deseja fazer?: \n(0)-Comprar carta\n(1)-Deixar o dealer comprar\n(2)-Ver suas cartas\n(3)-Ver cartas do dealer\n";

        switch(game.getOpcao1(3)){ //switch com uma funçao criada no final do arquivo para auxiliar a escolha de opçoes do jogador
            case 0:
            std:: cout << "Voce tirou: " << game.sorteiaCarta(game._player) << std::endl; //sorteia carta para o jogador
            goto z; //volta para a linha 71
            break;
            case 1:
            y:
            if(game._dealer.getValorMao()<17){
                std::cout << "O dealer tirou: " << game.sorteiaCarta(game._dealer) <<std::endl;//dealer compra até ter 17 pontos, como diz a regra do jogo
                goto y; //volta para a linha 97
            }
            if(game._dealer.getValorMao()>21){//confere em todo loop se algum ganhou ou perdeu
                venceu = true;
            }
            quit = true; // caso chegue ao final deve sair do loop do jogo, pois alguem ganhou ou perdeu ou deu empate
            break;
            case 2:
            std::cout << "suas cartas sao: "; 
            game._player.imprimeMao(); //imprime as cartas da mao do jogador
            std::cout << std::endl;
            goto z;//volta para a linha 71
            break;
            case 3: 
            std::cout << "as cartas do dealer sao: "; 
            game._dealer.imprimeMao();//imprime a mao do dealer
            goto z;//volta para a linha 71
            break;
        }
        if(venceu==true || venceu == false){ //caso alguem tenha ganhado break no switch
            break;
        }
    }
    if(game._player.getValorMao()<21 && game._dealer.getValorMao() < 21){ //caso os dois tenham menos que 21 , confere quem ganhou
        if(game._player.getValorMao()<game._dealer.getValorMao()){//se o dealer tem mais o jogador perde
            venceu = false;
        }
        else if(game._player.getValorMao()==game._dealer.getValorMao()){//se tiverem o msm tanto empata
            std::cout << "Empate!" << std::endl;
            empate = true;
        }
        else{//se o dealer tem menos o jogador ganha
            venceu = true;
        }
    }
    if(venceu){ //se ele venceu:
        std::cout << "Voce venceu!" << std::endl;
        user.setSaldo(user.getSaldo()+(Jogo::getPremiacao())); //da o valor apostado mais o ganho apra o jogador 
        std::cout << "A premiacao foi de: " << (Jogo::getPremiacao()) << std::endl;
    }
    if(!venceu && !empate){//se perdeu:
        std::cout << "O dealer venceu!" <<std::endl;
    }
    if(empate){//se empatou:
        std::cout << "O seu dinheiro foi devolvido!" << std::endl;
        user.setSaldo(user.getSaldo()+(Jogo::getValorApostado()));//como empatou, devolve o dinheiro pro jogador
    }
}



int Blackjack::getOpcao1(int maximo) //funçao para auxiliar os switchs do codigo
{
  int opcao;
  while (true)
  {
    std::cin >> opcao;
    if (opcao >= 0 && opcao <= maximo)  
    {
      return opcao;
    }
    else//caso nao seja valido, avisa e pede para colocar um novo valor
    {
      std::cout << "Opcao invalida, por favor digite um numero entre 0 e " << maximo << std::endl;
    }
  }
}