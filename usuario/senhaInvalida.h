#include <stdexcept>

class senhaInvalida : public std::exception
{
public:
    virtual const char *what() const noexcept override;
};

const char *senhaInvalida::what() const noexcept
{
    return "Senha invalida, deverá conter entre 6 e 20 caracteres!";
}