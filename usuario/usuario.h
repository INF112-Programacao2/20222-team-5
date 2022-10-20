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
    Usuario();
    ~Usuario();

    std::string getNome();
    std::string getEmail();
    int getSaldo();
    int getFichas();

    void setNome(std::string nome);
    void setEmail(std::string email);
    void setSenha();
    void setSaldo();
};


