#include <stdexcept>

class limMaxDeCaracteres : public std::exception
{
public:
    virtual const char *what() const noexcept override;
};

const char *limMaxDeCaracteres::what() const noexcept
{
    return "No maximo 20 caracteres, tente novamente: ";
}