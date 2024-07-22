#include <cmath> // para función sqrt()
#include <iostream>
#include <exception>

// Una función raíz cuadrada modular
double miSqrt(double x)
{
    // Si el usuario escribe un número negativo, esta es una condición de error
    // El throw se encuentra dentro de una fcn, al pulsar el throw buscará el bloque try envolvente, al no encontrarlo
    // aquí lo buscará en su llamador, se produce la propagación, lo busca en su llamador
    if (x < 0.0)
        throw std::invalid_argument { "No se puede calcular la raíz cuadrada de un número negativo" };

    return std::sqrt(x);
}

int main()
{
    setlocale(LC_ALL, "es_ES.utf8");
    std::cout << "Escribe un número: ";
    double x{};
    std::cin >> x;

    // Este bloque try no incluye ningún throw, pero si la llamada 
    // a una fcn miSqrt que si incluye uno
    // Este bloque try gestiona un throw que se encuentra dentro de otro bloque
    try // Busca excepciones que ocurran dentro del bloque try y enruta a los bloques catch vinculados

    {
        double d = miSqrt(x);
        std::cout << "La raíz cuadrada de " << x << " es " << d << '\n';
    }
    catch (const std::invalid_argument& e) // excepciones catch de tipo const char*
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}


