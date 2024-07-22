#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

bool imprimirDivision(int x, int y)
{
    try
    {
        if (y == 0)
            throw "No se puede dividir por cero"; // lanza excepción de tipo const char*

        cout << static_cast<double>(x) / y;
    }
    catch (const char* exception) // captura excepciones de tipo const char*
    {
        cerr << "Error: " << exception << endl;
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