#include <cstddef> // para std::size_t
#include <exception> // para std::exception
#include <iostream>
#include <limits>
#include <string> // para este ejemplo

int main()
{
    setlocale(LC_ALL, "es_ES.utf-8");
    try
    {
        // Nuestro código usando la biblioteca estándar va aquí
        // Activaremos una de estas excepciones intencional... para simplificar
        std::string s;
        // resize para modificar su tamaño
        s.resize(std::numeric_limits<std::size_t>::max()); // Activará una excepción std::length_error o de asignación
    }
    // Toda derivada es-un padre. Este controlador capturará std::exception y todas las excepciones derivadas también
    // Captura referencia std::exception, clase interface que capturará todas las excepciones
    // lanzadas desde la biblioteca "std"
    // std::length_error "es-un" std::exception
    catch (const std::exception& excepcion)
    {
        // exception.what devuelve una descripción como string estilo C de la excepción lanzada
        // std::exception cuenta con una descripción propia, pero sobrescrita
        // por muchas de sus clases derivadas.
        // Solo para mensajes no para comparaciones
        std::cerr << "Excepción estándar: " << excepcion.what() << '\n';
    }

    return 0;
}