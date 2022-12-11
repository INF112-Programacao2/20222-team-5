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
#include "jackpot/jackpot.h"

int getOpcao(int maximo);
void adicionarFundos(std::string nome, std::string email, std::string senha);
void criarConta(std::vector<Usuario> &listaUsuarios);
bool entrar(std::vector<Usuario> &listaUsuarios);
void exibirCassino();
bool verificaAposta(Usuario u, int valor);
void depositar(Usuario &u);


int main(void)
{
  std::vector<Usuario> listaUsuarios;
  Usuario a("Antonio","antonio@gmail.com","102030",200);
  listaUsuarios.push_back(a);
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
        entrar(listaUsuarios);
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
  switch (getOpcao(2))
  {
    case 0:
    {
      break;
    }
    case 1:
    {
      int numeroApostado = -1;
      int valorApostado = 0;
      int codigoCor;
      std::string corApostada = "";
      Usuario u("Arthur", "a@email.com", "12345", 100);
      std::cout << "Gostaria de apostar em numero ou cor?\n(0) - Numero\n(1) - Cor\n";
      switch(getOpcao(1)){
        case 0:
          std::cout << "Digite um numero de 0 a 36:\n";
          numeroApostado = getOpcao(36);
          break;
        case 1:
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
      std::cout << "Qual valor ira apostar? (Seu saldo e de " << u.getSaldo() << ")\n";
      std::cin >> valorApostado;
      verificaAposta(u, valorApostado);
      Roleta *roleta = new Roleta(u, corApostada, valorApostado, numeroApostado);
      roleta->sorteiaResultado();
      if(roleta->getFileira() == 0){
        std::cout << "O dado caiu na cor " << roleta->getResultadoCor() << std::endl;
        if(corApostada == roleta->getResultadoCor()){
          std::cout << "Parabens voce ganhou!\n Retorno obtido: " << roleta->getPremiacao() << std::endl;
          u.setSaldo((u.getSaldo() + roleta->getPremiacao()));
          std::cout << "Novo saldo de: " << u.getSaldo() << std::endl;
        }else{
          std::cout << "Voce perdeu\n";
        }
      }else{
        std::cout << "O dado caiu no numero " << roleta->getResultadoNumero() << std::endl;
        if(numeroApostado == roleta->getResultadoNumero()){
          std::cout << "Parabens voce ganhou!\nRetorno obtido: " << roleta->getPremiacao() << std::endl;
          u.setSaldo((u.getSaldo() + roleta->getPremiacao()));
          std::cout << "Novo saldo de: " << u.getSaldo() << std::endl;
        }else{
          std::cout << "Voce perdeu\n";
        }
      }
    }
    break;
    case 2:
    Jackpot j(a,100);
    j.rodarJack(a);
      break;
  }
}

void depositar(Usuario &u){
  int valor;
  std::cout << "Quanto quer depositar?\n";
  std::cin >> valor;
  valor += u.getSaldo();
  u.setSaldo(valor);
}

bool verificaAposta(Usuario u, int valor){
  if(valor > u.getSaldo()){
    std::cout << "Voce nao tem esse saldo, gostaria de depositar mais ou digitar outro valor?\n(0) - Depositar mais\n(1) - Digitar outro valor\n";
        switch(getOpcao(1)){
          case 0:
            depositar(u);
            std::cout << "Qual valor ira apostar? (Seu saldo e de " << u.getSaldo() << ")\n";
            std::cin >> valor;
            verificaAposta(u, valor);
          break;
          case 1:
            std::cout << "Qual valor ira apostar? (Seu saldo e de " << u.getSaldo() << ")\n";
            std::cin >> valor;
            verificaAposta(u, valor);
          break;
        }
    return false;
  }
  if(valor <= 0){
    std::cout << "Por favor digite um numero maior que 0:\n";
    std::cin >> valor;
    verificaAposta(u, valor);
  }
  u.setSaldo((u.getSaldo() - valor));
  return true;
}

int getOpcao(int maximo)
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

void adicionarFundos(std::string nome, std::string email, std::string senha)
{
  int saldo;
  exibirCassino();
  std::cout << "Quanto voce deseja adicionar a sua carteira? ";
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

  if (getOpcao(1) == 0)
  {
    adicionarFundos(nome, email, senha);
  } else {
    Usuario user(nome, email, senha);
    listaUsuarios.push_back(user);
    std::cout << "Parabens!! Seu usuario foi criado com sucesso, agora e so comecar a jogar!!" << std::endl;
    sleep(3);
  }
}

bool entrar(std::vector<Usuario> &listaUsuarios) {
  bool logado = false;
  std::string email;
  std::string senha;

  std::cout << "Digite o seu email: ";
  std::cin.ignore();
  std::getline(std::cin, email);

  std::cout << "Digite a sua senha: ";
  std::getline(std::cin, senha);
  
  for (int i = 0; i < listaUsuarios.size(); i++) {
    if (listaUsuarios[i].getEmail() == email && listaUsuarios[i].getSenha() == senha)
    {
      logado = true;
      return logado;
    }
  }

  std::cout << "Usuario ou senha incorretos!";
  sleep(2);
  return logado;
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
