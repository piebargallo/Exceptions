#include <cmath> // para función sqrt()
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::cerr;
using std::sqrt;

// Se produce una separación total entre el flujo del programa y el flujo de la excepción
// Tras calcularse la raíz cuadrada, o controlarse la excepción, el flujo
// normal del programa continúa en el mismo punto.
int main()
{
    setlocale(LC_ALL, "es_ES.utf8");
    // El número pasado no puede ser negativo, usamos una excepción para controlarlo
    cout << "Escribe un número: ";
    double x{};
    cin >> x;

    try // 2)Busca excepciones que ocurren dentro del bloque try y enruta al bloque(s) catch vinculados
    {
        // 1)Si el usuario escribe un número negativo, esta es una condición de error
        if (x < 0.0)
            throw "No se puede calcular sqrt de número negativo"; // lanza excepción de tipo const char*

    // en otro caso, imprime la respuesta
        cout << "La raíz cuadrada de " << x << " es " << sqrt(x) << endl;
    }
    // 3)El catch actúa práctica... como una fcn, aquí recibe un pará...(exception)
    // que recogerá el valor lanzado por throw, que es un ptr char const (string estilo C)
    catch (const char* exception) // captura excepciones de tipo const char*
    {
        cerr << "Error: " << exception << endl;
    }
    cout << "continúa el flujo normal del programa" << endl;
    return 0;
}


