#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <unistd.h>
#include "usuario/usuario.h"
#include "jogo/roleta/roleta.h"
#include "usuario/emailInvalido.h"
#include "usuario/limMaxDeCaracteres.h"
#include "usuario/senhaInvalida.h"

int getOpcao(int);
void adicionarFundos(std::string nome, std::string email, std::string senha);
void criarConta(std::vector<Usuario> &listaUsuarios);
void entrar();
void exibirCassino();

int main(void)
{
  std::vector<Usuario> listaUsuarios;
  exibirCassino();
  std::cout << "========================|   SEJA BEM VINDO AO CASSINO  |==============================" << std::endl;
  std::cout << "(0) - Criar conta" << std::endl;
  if (listaUsuarios.size() > 0)
  {
    std::cout << "(1) - Entrar" << std::endl;
  }
  
  
  if (listaUsuarios.size() > 0)
  {
    switch (getOpcao(1))
    {
      case 0:
      {
        try {
          criarConta(listaUsuarios);
        }
        catch(const std::exception& e) {
          std::cerr << e.what() << '\n';
        }

        system("cls||clear");
        
        break;
      }
      case 1:
      {
        entrar();
        break;
      }
    }
  }
  else {
    
      criarConta(listaUsuarios);
    
    
    system("cls||clear");
  }

  exibirCassino();
  std::cout << "Qual jogo gostaria de jogar?" << std::endl;
  std::cout << "(0) - Blackjack" << std::endl;
  std::cout << "(1) - Roleta" << std::endl;
  std::cout << "(2) - Jackpot" << std::endl;
  switch (getOpcao(1))
  {
  case 0:
  {
    break;
  }
  case 1:
  {
    // Roleta roleta = criarJogoRoleta();
  }
  case 3:
  {
    break;
  }
  }
}

// Roleta criarJogoRoleta()
// {
//   Roleta roleta()
// }

int getOpcao(int maximo)
{
  int opcao;
  while (true)
  {
    std::cin >> opcao;
    if (opcao >= 0 || opcao <= maximo)
    {
      return opcao;
    }
    else
    {
      std::cout << "Opção invalida, por favor digite um número entre 0 e " << maximo << std::endl;
    }
  }
}

void adicionarFundos(std::string nome, std::string email, std::string senha)
{
  int saldo;
  exibirCassino();
  std::cout << "Quanto voce deseja adicionar a sua carteira?: ";
  std::cin >> saldo;

  Usuario user(nome, email, senha, saldo);
};

void criarConta(std::vector<Usuario> &listaUsuarios) {
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
      
      if (nome.length() > 20) {
        throw limMaxDeCaracteres();
      }
      else {
        break;
      }
    }
    catch(const std::exception& e) {
      exibirCassino();
      std::cerr << e.what() << '\n';
    }
    
  }

  std::cout << "Digite o seu email: ";

  while (true) {
    try {
  
      std::getline(std::cin, email);

      for (int i = 0; i < email.length(); i++) {
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
      
      if (email.length() > 20) {
        throw limMaxDeCaracteres();
      }
      else if (arroba == false || ponto == false || maiorQue3Char == false) {
        throw emailInvalido();
      }
      else {
        break;
      }
    }
    catch(const std::exception& e) {
      exibirCassino();
      std::cerr << e.what() << '\n';
    }
  }

  std::cout << "Digite a sua senha: ";
  
  while (true) {
    try {
  
      std::getline(std::cin, senha);
      
      if (senha.length() > 20 || senha.length() < 6) {
        throw senhaInvalida();
      }
      else {
        break;
      }
    }
    catch(const std::exception& e) {
      exibirCassino();
      std::cerr << e.what() << '\n';
    }
  }

  std::cout << "Quer adicionar saldos a sua conta? (0) - Sim, (1) - Nao\n";
  std::cin >> opcao;

  while (opcao != 0 && opcao != 1)
  {
    std::cout << "Opcao invalida, tente novamente:";
    std::cin >> opcao;
  }

  if (opcao == 0)
  {
    adicionarFundos(nome, email, senha);
  }
  else
  {
    Usuario user(nome, email, senha);
    listaUsuarios.push_back(user);
    std::cout << "Parabens!! Seu usuario foi criado com sucesso, agora e so comecar a jogar!!" << std::endl;
    sleep(3);
  }
}

void entrar() {

};

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
