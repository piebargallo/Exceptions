#include <cmath> // para función sqrt()
#include <iostream>

// Una función raíz cuadrada modular
double miSqrt(double x)
{
    // Si el usuario escribe un número negativo, esta es una condición de error
    if (x < 0.0)
        throw "No se puede calcular la raíz cuadrada de un número negativo"; // throw excepción de tipo const char*

    return std::sqrt(x);
}

int main()
{
    setlocale(LC_ALL, "es_ES.utf8");
    std::cout << "Escribe un número: ";
    double x{};
    std::cin >> x;

    try // Busca excepciones que ocurran dentro del bloque try y enruta a los bloques catch vinculados
    {
        double d = miSqrt(x);
        std::cout << "La raíz cuadrada de " << x << " es " << d << '\n';
    }
    catch (const char* excepcion) // excepciones catch de tipo const char*
    {
        std::cerr << "Error: " << excepcion << std::endl;
    }

    return 0;
}



