#include "../jogo.h"
#include "roleta.h"
#include "../../usuario/usuario.h"
#include <ctime>

std::string Jogo::nome = "Roleta";

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
  fileira = rand() % 2;//0 = fileira cores 1 = fileira numeros
  int numero = rand() % 37;
  if(fileira == 1){
    resultadoNumero = numero;
  }
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
  if(resultadoNumero == numeroAposta && numeroAposta == 0){
    premiacao = valorApostado*15;
  }
  if(resultadoNumero == numeroAposta && resultadoCor != "Verde"){
    premiacao = valorApostado*5;
  }
  if(resultadoCor == corAposta && corAposta != "Verde"){
    premiacao = valorApostado*2;
  }
  if(resultadoCor == corAposta && corAposta == "Verde"){
    premiacao = valorApostado*10;
  }
}
