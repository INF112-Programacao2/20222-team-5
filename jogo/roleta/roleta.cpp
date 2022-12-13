#include "../jogo.h"
#include "roleta.h"
#include "../../usuario/usuario.h"
#include <ctime>

Roleta::Roleta(Usuario user, std::string corAposta, int valorApostado, int numeroAposta)
{
  this->user = user;
  this->corAposta = corAposta;
  this->valorApostado = valorApostado;
  this->numeroAposta = numeroAposta;
  premiacao = 0;
  resultadoCor = "";
  resultadoNumero = -2;
  fileira = -1;
}

int Roleta::getFileira(){
  return fileira;
}

std::string Roleta::getResultadoCor(){
  return resultadoCor;
}

int Roleta::getResultadoNumero(){
  return resultadoNumero;
}

int Roleta::getPremiacao(){
  return premiacao;
}

void Roleta::setFileira(int fileira){
  this->fileira = fileira;
}

void Roleta::setPremiacao(int premiacao){
  this->premiacao = premiacao;
}

void Roleta::sorteiaResultado(){
  unsigned seed = time(0);
  srand(seed);
  fileira = rand() % 2;//0 = fileira das cores 1 = fileira dos numeros
  int numero = rand() % 37;// sorteia a posicao que o dado cai, de 0 a 36
  if(fileira == 1){// se caiu na fileira dos numeros, um numero foi sorteado 
    resultadoNumero = numero;
  }
  // idependentemente da fileira, uma cor foi sorteada
  if(numero == 0){
      resultadoCor = "Verde";
  }else{
    for(int i = 0; i < 18; i++){
      if(vermelho[i] == numero){
        resultadoCor = "Vermelho";
      }else if(preto[i] == numero){
        resultadoCor = "Preto";
      }
    }
  }
  // calcula a premiacao baseado em que o usuario apostou e na "raridade" da casa que o dado caiu
  if(resultadoNumero == numeroAposta && numeroAposta == 0){ // caiu 0
    premiacao = valorApostado*15;
  }
  if(resultadoNumero == numeroAposta && resultadoCor != "Verde"){ // caiu numero entre 1 e 36
    premiacao = valorApostado*5;
  }
  if(resultadoCor == corAposta && corAposta != "Verde"){ // caiu numa casa vermelha ou preta
    premiacao = valorApostado*2;
  }
  if(resultadoCor == corAposta && corAposta == "Verde"){ // caiu na casa verde
    premiacao = valorApostado*10;
  }
}
