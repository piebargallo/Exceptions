#include <cmath> // para funci�n sqrt()
#include <iostream>

// Una funci�n ra�z cuadrada modular
double miSqrt(double x)
{
    // Si el usuario escribe un n�mero negativo, esta es una condici�n de error
    if (x < 0.0)
        throw "No se puede calcular la ra�z cuadrada de un n�mero negativo"; // throw excepci�n de tipo const char*

    return std::sqrt(x);
}

int main()
{
    setlocale(LC_ALL, "es_ES.utf8");
    std::cout << "Escribe un n�mero: ";
    double x{};
    std::cin >> x;

    try // Busca excepciones que ocurran dentro del bloque try y enruta a los bloques catch vinculados
    {
        double d = miSqrt(x);
        std::cout << "La ra�z cuadrada de " << x << " es " << d << '\n';
    }
    catch (const char* excepcion) // excepciones catch de tipo const char*
    {
        std::cerr << "Error: " << excepcion << std::endl;
    }

    return 0;
}



