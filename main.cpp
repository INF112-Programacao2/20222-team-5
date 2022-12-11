#include <iostream>
#include <string>
#include <stdio.h>
#include "usuario/usuario.h"
//#include "jogo/roleta/roleta.h"
#include "jackpot/jackpot.h"
#include "jackpot/figuras.h"
//#include "jogo/jogo.h"

int getOpcao(int);
void adicionarFundos(std::string nome, std::string email, std::string senha);
void criarConta();
void entrar();
void exibirCassino();

int main(void)
{
  exibirCassino();
  std::cout << "========================|   SEJA BEM VINDO AO CASSINO  |==============================" << std::endl;
  std::cout << "(0) - Criar conta" << std::endl;
  std::cout << "(1) - Entrar" << std::endl;

  switch (getOpcao(1)) {
  case 0:
    criarConta();
    break;
  case 1:
    entrar();
    break;
  }
  std::cout << "Qual jogo gostaria de jogar?" << std::endl;
  std::cout << "(0) - Blackjack" << std::endl;
  std::cout << "(1) - Roleta" << std::endl;
  std::cout << "(2) - Jackpot" << std::endl;
  switch (getOpcao(1)) {

  case 0:
    break;
  case 1:
    // Roleta roleta = criarJogoRoleta();
    break;
  case 2:
    break;
  }
}

/*Roleta criarJogoRoleta()
{
  Roleta roleta()
}*/

int getOpcao(int maximo) {
  int opcao;
  while (true) {
    std::cin >> opcao;
    if (opcao >= 0 || opcao <= maximo) {
      return opcao;
    }
    else {
      std::cout << "Opção invalida, por favor digite um número entre 0 e " << maximo << std::endl;
    }
  }
}

void adicionarFundos(std::string nome, std::string email, std::string senha) {
  int saldo;
  exibirCassino();
  std::cout << "Quanto voce deseja adicionar a sua carteira?: ";
  std::cin >> saldo;

  Usuario user(nome, email, senha, saldo);
}

void criarConta() {
  std::string nome;
  std::string email;
  std::string senha;
  int opcao;
  exibirCassino();
  std::cout << "Digite o seu nome: ";

  std::cin.ignore();
  std::getline(std::cin, nome);

  while (nome.length() > 20) {
    std::cout << "No maximo 20 caracteres, tente novamente: ";
    std::getline(std::cin, nome);
  }
  system("cls||clear");
  exibirCassino();
  std::cout << "Digite o seu email: ";
  std::getline(std::cin, email);

  exibirCassino();
  std::cout << "Digite a sua senha: ";
  std::getline(std::cin, senha);

  while (senha.length() > 20 || senha.length() < 6) {
    std::cout << "\nNo minimo 6 e no maximo 20 caracteres, tente novamente: ";
    std::getline(std::cin, senha);
  }

  exibirCassino();
  std::cout << "Quer adicionar saldos a sua conta? (0) - Sim, (1) - Nao\n";
  std::cin >> opcao;

  while (opcao != 0 && opcao != 1) {
    std::cout << "Opcao invalida, tente novamente:";
    std::cin >> opcao;
  }

  if (opcao == 0) {
    adicionarFundos(nome, email, senha);
  }
  else {
    Usuario* user = new Usuario(nome, email, senha);
  }

  system("cls||clear");
  exibirCassino();
  std::cout << "Parabens!! Seu usuario foi criado com sucesso, agora e so comecar a jogar!!" << std::endl;
}

void entrar() {

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