#include <iomanip>
#include "usuario.h"

Usuario::Usuario(std::string nome, std::string email, std::string senha)
{
    this->nome = nome;
    this->email = email;
    this->senha = senha;
    this->saldo = 0;
    this->fichas = 0;
}

Usuario::Usuario(std::string nome, std::string email, std::string senha, int saldo)
{
    this->nome = nome;
    this->email = email;
    this->senha = senha;
    this->saldo = saldo;
    this->fichas = 0;
}

Usuario::~Usuario()
{
}