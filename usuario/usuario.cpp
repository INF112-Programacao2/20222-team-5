#include <iomanip>
#include <string>
#include "usuario.h"

Usuario::Usuario(std::string nome, std::string email, std::string senha)
{
    this->nome = nome;
    this->email = email;
    this->senha = senha;
    this->saldo = 0;
};

Usuario::Usuario(std::string nome, std::string email, std::string senha, int saldo)
{
    this->nome = nome;
    this->email = email;
    this->senha = senha;
    this->saldo = saldo;
};

Usuario::Usuario() {}

Usuario::~Usuario() {}

int Usuario::getSaldo(){
    return saldo;
}

std::string Usuario::getEmail() {
    return email;
}

std::string Usuario::getSenha() {
    return senha;
}

void Usuario::setNome(std::string nome) {
    this->nome = nome;
};

void Usuario::setEmail(std::string email) {
    this->email = email;
};

void Usuario::setSenha(std::string senha) {
    this->senha = senha;
};

void Usuario::setSaldo(int saldo) {
    this->saldo = saldo;
};
