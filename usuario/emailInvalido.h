#include <stdexcept>

class emailInvalido : public std::exception
{
public:
    virtual const char *what() const noexcept override;
};

const char *emailInvalido::what() const noexcept
{
    return "Insira um email valido, com no maximo 40 caracteres!";
}