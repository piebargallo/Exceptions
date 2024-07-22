#include <iostream>
#include <exception>
using std::cout;
using std::endl;
using std::cerr;

bool imprimirDivision(int x, int y)
{
    try
    {
        if (y == 0)
            throw std::invalid_argument { "No se puede dividir por cero" }; 

        cout << static_cast<double>(x) / y;
    }
    catch (const std::invalid_argument& e) 
    {
        cerr << "Error: " << e.what() << endl;
    }
    return true;
}

int main()
{
    setlocale(LC_ALL, "es_ES.utf8");
    imprimirDivision(4, 0);
    cout << "continua flujo normal del programa" << endl;

    return 0;
}