#include <exception> // para std::exception
#include <iostream>
#include <stdexcept> // para std::runtime_error

int main()
{
    setlocale(LC_ALL, "es_ES.utf-8");
    try
    {
        // Throw de tipo "std::runtime_error, con un mensaje personalizable
        throw std::runtime_error("Algo malo ha pasado");
    }
    // Este manejador capturará std::exception y todas las excepciones derivadas
    catch (const std::exception& e)
    {
        // Captura la fcn "what" sobrescrita para std::runtime_error
        std::cerr << "Excepción estándar: " << e.what() << '\n';
    }

    return 0;
}