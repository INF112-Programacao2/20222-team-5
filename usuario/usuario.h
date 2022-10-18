#include <string>

class Usuario {
private:
    std::string nome;
    std::string email;
    std::string senha;
    int saldo;
    int fichas;

public:
    Usuario(std::string nome, std::string email, std::string senha);
    Usuario(std::string nome, std::string email, std::string senha, int saldo);
    ~Usuario();

    std::string getNome();
    std::string getEmail();
    int getSaldo();
    int getFichas();

    void setNome();
    void setEmail();
    void setSenha();
    void setSaldo();
};


