#include <iostream>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include "usuario/usuario.h"
#include "jogo/roleta/roleta.h"
#include "jackpot/jackpot.h"
#include "jackpot/figuras.h"
#include "jogo/jogo.h"
#include "usuario/limMaxDeCaracteres.h"
#include "usuario/senhaInvalida.h"
#include "usuario/emailInvalido.h"
#include "blackjack/blackjack.h"
#include "jackpot/jackpot.h"

int getOpcao(int maximo);
Usuario adicionarFundos(std::string nome, std::string email, std::string senha);
void criarConta(std::vector<Usuario> &listaUsuarios, int &indiceUsuarioLogado);
bool entrar(std::vector<Usuario> &listaUsuarios,int &indiceUsuarioLogado, bool &p);
void exibirCassino();
void exibirRoleta();
bool verificaAposta(std::vector <Usuario> &listaUsuarios, int &indiceUsuarioLogado, int &valor);
void depositar(std::vector <Usuario> &listaUsuarios, int &indiceUsuarioLogado);


int main(void)
{
  std::vector<Usuario> listaUsuarios;
  int indiceUsuarioLogado;
  Usuario adm("Admnistrador","adm@adm.com","adm123",200);
  listaUsuarios.push_back(adm);
  exibirCassino();
  std::cout << "========================|   SEJA BEM VINDO AO CASSINO  |==============================" << std::endl;
  std::cout << "(0) - Criar conta" << std::endl;
  if (listaUsuarios.size() > 0) //se a lista de usuarios estiver vazia so aparecera a opcao de criar conta
  {
    std::cout << "(1) - Entrar" << std::endl;
  }
  
  
  if (listaUsuarios.size() > 0) //se a lista de usuarios nao estiver vazia sera possivel entrar e criar uma nova conta
  {
    switch (getOpcao(1))
    {
      case 0:
      {
        try {
          criarConta(listaUsuarios, indiceUsuarioLogado);
        }
        catch(const std::exception& e) {
          std::cerr << e.what() << '\n';
        }

        system("cls||clear");
        
        break;
      }
      case 1:
      {
        bool p = true;
        while (!entrar(listaUsuarios,indiceUsuarioLogado , p)){}
        
        break;
      }
    }
  }
  else { //caso a lista de usuarios esteja vazia ira direto para a funcao de criar conta
    
      criarConta(listaUsuarios, indiceUsuarioLogado);
    
    system("cls||clear");
  }

  exibirCassino();
  std::cout << "Qual jogo gostaria de jogar?" << std::endl;
  std::cout << "(0) - Blackjack" << std::endl;
  std::cout << "(1) - Roleta" << std::endl;
  std::cout << "(2) - Jackpot" << std::endl;
  switch (getOpcao(2))
  {
    case 0:
    {
      bool sair=false;
      x:
      Blackjack b;
      while(!sair){
        b.mainBlackjack(listaUsuarios[indiceUsuarioLogado]);
        std::cout << "Deseja jogar novamente?\n(0)-Sim\n(1)-Nao\n";
        switch(getOpcao(1)){
          case 0:
          goto x;
          case 1:
          sair=true;
        }
      }
      break;
    }
    case 1:
    {
      int numeroApostado = -1; // valor "default", representa que nao teve numero apostado
      int valorApostado = 0;
      int codigoCor;
      std::string corApostada = "";
      exibirRoleta();
      std::cout << "Gostaria de apostar em numero ou cor?\n(0) - Numero\n(1) - Cor\n";
      switch(getOpcao(1)){
      case 0:
        exibirRoleta();
        std::cout << "Digite um numero de 0 a 36:\n";
          numeroApostado = getOpcao(36);
          break;
      case 1:
        exibirRoleta();
        std::cout << "Qual cor?\n(0) - Preto\n(1) - Vermelho\n(2) - Verde\n";
          codigoCor = getOpcao(2);
          if(codigoCor == 0){
            corApostada = "Preto";
          }else if(codigoCor == 1){
            corApostada = "Vermelho";
          }else{
            corApostada = "Verde";
          }
          break;
      }
      exibirRoleta();
      std::cout << "Qual valor ira apostar? (Seu saldo e de " << listaUsuarios[indiceUsuarioLogado].getSaldo() << ")\n";
      std::cin >> valorApostado;
      verificaAposta(listaUsuarios, indiceUsuarioLogado, valorApostado);
      Roleta *roleta = new Roleta(listaUsuarios[indiceUsuarioLogado], corApostada, valorApostado, numeroApostado);
      roleta->sorteiaResultado();
      if (roleta->getFileira() == 0) {
        exibirRoleta();
        std::cout << "O dado caiu na cor " << roleta->getResultadoCor() << std::endl;
        if (corApostada == roleta->getResultadoCor()) {
          std::cout << "Parabens voce ganhou!\nRetorno obtido: " << roleta->getPremiacao() << std::endl;
          listaUsuarios[indiceUsuarioLogado].setSaldo((listaUsuarios[indiceUsuarioLogado].getSaldo() + roleta->getPremiacao()));
          std::cout << "Novo saldo de: " << listaUsuarios[indiceUsuarioLogado].getSaldo() << std::endl;
        }
        else {
          std::cout << "Voce perdeu\n";
        }
      }
      else {
        exibirRoleta();
        std::cout << "O dado caiu no numero " << roleta->getResultadoNumero() << std::endl;
        if(numeroApostado == roleta->getResultadoNumero()){
          std::cout << "Parabens voce ganhou!\nRetorno obtido: " << roleta->getPremiacao() << std::endl;
          listaUsuarios[indiceUsuarioLogado].setSaldo((listaUsuarios[indiceUsuarioLogado].getSaldo() + roleta->getPremiacao()));
          std::cout << "Novo saldo de: " << listaUsuarios[indiceUsuarioLogado].getSaldo() << std::endl;
        }
        else {
        
          std::cout << "Voce perdeu\n";
        }
      }
      delete roleta;
    }
    break;
    case 2:
    Jackpot j(listaUsuarios[indiceUsuarioLogado],100);
    j.rodarJack(listaUsuarios[indiceUsuarioLogado]);
      break;
  }
}

void depositar(std::vector <Usuario> &listaUsuarios, int &indiceUsuarioLogado){
  int valor;
  std::cout << "Quanto quer depositar?\n";
  std::cin >> valor;
  valor += listaUsuarios[indiceUsuarioLogado].getSaldo();
  listaUsuarios[indiceUsuarioLogado].setSaldo(valor);
}

bool verificaAposta(std::vector <Usuario> &listaUsuarios, int &indiceUsuarioLogado, int &valor){
  if(valor > listaUsuarios[indiceUsuarioLogado].getSaldo()){
    std::cout << "Voce nao tem esse saldo, gostaria de depositar mais ou digitar outro valor?\n(0) - Depositar mais\n(1) - Digitar outro valor\n";
        switch(getOpcao(1)){
          case 0:
            depositar(listaUsuarios, indiceUsuarioLogado);
            std::cout << "Qual valor ira apostar? (Seu saldo e de " << listaUsuarios[indiceUsuarioLogado].getSaldo() << ")\n";
            std::cin >> valor;
            verificaAposta(listaUsuarios, indiceUsuarioLogado, valor);
          break;
          case 1:
            std::cout << "Qual valor ira apostar? (Seu saldo e de " << listaUsuarios[indiceUsuarioLogado].getSaldo() << ")\n";
            std::cin >> valor;
            verificaAposta(listaUsuarios, indiceUsuarioLogado, valor);
          break;
        }
    return false;
  }
  if(valor <= 0){
    std::cout << "Por favor digite um numero maior que 0:\n";
    std::cin >> valor;
    verificaAposta(listaUsuarios, indiceUsuarioLogado, valor);
  }
  listaUsuarios[indiceUsuarioLogado].setSaldo((listaUsuarios[indiceUsuarioLogado].getSaldo() - valor));
  return true;
}

int getOpcao(int maximo) { // funcao para ler opcao, validando o valor de entrada
  int opcao;
  while (true) {
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

Usuario adicionarFundos(std::string nome, std::string email, std::string senha) {
  int saldo;
  exibirCassino();
  std::cout << "Quanto voce deseja adicionar a sua carteira? ";
  std::cin >> saldo;
  Usuario user(nome, email, senha, saldo); //segundo metodo construtor de usuario(polimorfismo)
  return user;
}

void criarConta(std::vector<Usuario> &listaUsuarios, int &indiceUsuarioLogado) {
  bool arroba = false, ponto = false, maiorQue3Char = false;

  std::string nome;
  std::string email;
  std::string senha;
  int opcao;
  exibirCassino();
  std::cout << "Digite o seu nome: ";

  while (true) {
    try {
      std::cin.ignore();
      std::getline(std::cin, nome);
      
      if (nome.length() > 20) { //se o nome tiver mais de 20 caracteres lanca a excecao
        throw limMaxDeCaracteres();
      }
      else {
        break; //se passou no teste sai do while
      }
    }
    catch(const std::exception& e) { //pega a excecao de mais de 20 caracteres no nome
      exibirCassino();
      std::cerr << e.what() << '\n';
    }
    
  }
  exibirCassino();
  std::cout << "Digite o seu email: ";

  while (true) {
    try {
  
      std::getline(std::cin, email);

      for (int i = 0; i < email.length(); i++) { //verifica se no email existe "@" e "." e se tem mais de 3 caracteres 
        if (email[i] == '@') {
          arroba = true;
        }
        else if (email[i] == '.') {
          ponto = true;
        }
        else if (email.length() > 3) {
          maiorQue3Char = true;
        }
      }
      
      if (arroba == false || ponto == false || maiorQue3Char == false || email.length() > 40) { // verifica as validacoes anteriores e se o email tem mais de 40 caracteres, e lanca uma excecao
        throw emailInvalido();
      }
      else {
        break; //se passou no teste sai do while
      }
    }
    catch(const std::exception& e) {
      exibirCassino();
      std::cerr << e.what() << '\n';
    }
  }
  exibirCassino();
  std::cout << "Digite a sua senha: ";
  
  while (true) {
    try {
  
      std::getline(std::cin, senha);
      
      if (senha.length() > 20 || senha.length() < 6) { //verifica se a senha tem entre 6 e 20 caracteres, se nao, lanca uma excecao
        throw senhaInvalida();
      }
      else {
        break; //se passou no teste sai do while
      }
    }
    catch(const std::exception& e) {
      exibirCassino();
      std::cerr << e.what() << '\n';
    }
  }
  exibirCassino();
  std::cout << "Quer adicionar saldos a sua conta? (0) - Sim, (1) - Nao\n";

  if (getOpcao(1) == 0)
  {
    listaUsuarios.push_back(adicionarFundos(nome, email, senha)); //se o usuario selecionar a opcao 0 insere o usuario da funcao adicionar fundos na lista de usuarios
  } else {
    Usuario user(nome, email, senha); //se o usuario optar por nao adcionar saldo a sua conta cria o usuario sem saldo
    listaUsuarios.push_back(user); //insere o usuario sem saldo na lista de usuarios
    exibirCassino();
    std::cout << "Parabens!! Seu usuario foi criado com sucesso, agora e so comecar a jogar!!" << std::endl;
    sleep(3);
  }
  indiceUsuarioLogado = (listaUsuarios.size()-1);
}

bool entrar(std::vector<Usuario> &listaUsuarios,int &indiceUsuarioLogado, bool &p) { 
  bool logado = false;
  std::string email;
  std::string senha;

  std::cout << "Digite o seu email: ";
  if (p == true) { // se for a primeira vez que esta chamando a funcao deve dar um ignore para que seja possivel ler corretamente os dados
    p = false;     // seta p como false para nao entrar mais nesse if
    std::cin.ignore();
  }
  
  std::getline(std::cin, email);

  std::cout << "Digite a sua senha: ";
  std::getline(std::cin, senha);
  
  for (int i = 0; i < listaUsuarios.size(); i++) { //verifica dentro da lista de usuarios se existe um email e senha compativeis
    if (listaUsuarios[i].getEmail() == email && listaUsuarios[i].getSenha() == senha)
    {
      logado = true;
      std::cout << "Login feito com sucesso!" << std::endl;
      sleep(2);
      indiceUsuarioLogado = i; //modifica o valor de indice usuario logado para passar para as funcoes de jogos
      return logado; //retorna o usuario logado
    }
  }
  std::cout << "Usuario ou senha incorretos!" << std::endl; //se nao existir nenhum email e senha compativeis na lista de usuarios retorna um logado = false
  sleep(2);
  return logado;
}

void exibirCassino() {
  system("cls||clear");
  std::cout << "\n======================================================================================";
  std::cout << "\n======================================================================================";
  std::cout << "\n|     CCCCC      A        SSSSSSSSS   SSSSSSSSS   IIIIIIIII  NN     NN    OOOOOOOO   |";
  std::cout << "\n|   CC          A  A      SS          SS             III     NN N   NN   OO      OO  |";
  std::cout << "\n|  CC          A    A     SSSSSSSSS   SSSSSSSSS      III     NN  N  NN   OO      OO  |";
  std::cout << "\n|   CC        AAAAAAAA           SS          SS      III     NN   N NN   OO      OO  |";
  std::cout << "\n|     CCCCC  A        A   SSSSSSSSS   SSSSSSSSS   IIIIIIIII  NN     NN    OOOOOOOO   |";
  std::cout << "\n======================================================================================";
  std::cout << "\n======================================================================================\n";
}

void exibirRoleta() {
system("cls||clear");
std::cout << "\n==========================================================================";
std::cout << "\n==========================================================================";
std::cout << "\n| RRRRRRR      OOOOOOOO     LLL        EEEEEEEE   TTTTTTTTT       A      |";
std::cout << "\n| RRR   RR    OO      OO    LLL        EE            TTT         A  A    |";
std::cout << "\n| RRR RRR     OO      OO    LLL        EEEEE         TTT        A    A   |";
std::cout << "\n| RRR RR      OO      OO    LLL        EE            TTT       AAAAAAAA  |";
std::cout << "\n| RRR  RRR     OOOOOOOO     LLLLLLLL   EEEEEEEE      TTT      A        A |";
std::cout << "\n==========================================================================";
std::cout << "\n==========================================================================\n";
}