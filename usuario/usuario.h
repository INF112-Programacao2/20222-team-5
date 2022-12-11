#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario
{
private:
    std::string nome;
    std::string email;
    std::string senha;
    int saldo;

public:
    Usuario(std::string nome, std::string email, std::string senha);
    Usuario(std::string nome, std::string email, std::string senha, int saldo);
    Usuario();
    ~Usuario();

    std::string getNome();
    std::string getEmail();
    int getSaldo();

    void setNome(std::string nome);
    void setEmail(std::string email);
    void setSenha(std::string senha);
    void setSaldo(int saldo);
};

#endif
