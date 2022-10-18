#include <iostream>
#include <string>
#include "usuario/usuario.h"

void criarConta(){
  std::string nome;
  std::string email;
  std::string senha;
  int opcao;

  std::cout << "Digite o seu nome: " << std::endl;
  std::cin >> nome;

  while (nome.length() > 20)
  {
    std::cout << "No maximo 20 caracteres, tente novamente: " << std::endl;
    std::cin >> nome;
  }

  std::cout << "Digite o seu email: " << std::endl;
  std::cin >> email;

  std::cout << "Digite a sua senha: " << std::endl;
  std::cin >> senha;

  while (senha.length() > 20 || senha.length() < 6)
  {
    std::cout << "No minimo 6 e no maximo 20 caracteres, tente novamente: " << std::endl;
    std::cin >> senha;
  }

  std::cout << "Quer adicionar saldos a sua conta? (0) - Sim, (1) - Nao" << std::endl;

  if (opcao == 0) {
    adicionarFundos(nome, email, senha);
  }
  else {
    Usuario user(nome, email, senha);
  }
  
  std::cout << "Parabens!! Seu usuario foi criado com sucesso, agora e so comecar a jogar!!" << std::endl;

}

void entrar() {

};

void adicionarFundos(std::string nome, std::string email, std::string senha){
  int saldo;
  std::cout << "Quanto voce deseja adicionar a sua carteira?" << std::endl;
  std::cin >> saldo;

  Usuario user(nome, email, senha, saldo);
};

int main(void) {
  
  std::cout << "Seja bem vindo ao cassino ..." << std::endl;
  std::cout << "(0) - Criar conta" << std::endl;
  std::cout << "(1) - Entrar" << std::endl;
  
  int opcao;

  while (true)
  {
    std::cin >> opcao;
    if(opcao == 0 || opcao == 1) {
      break;
    }
    else {
      std::cout << "Opcao invalida, tente novamente:" << std::endl;
    }
  }

  switch (opcao) {
  case 0:
    criarConta();
    break;
  case 1:
    entrar();
    break;
  }
}



