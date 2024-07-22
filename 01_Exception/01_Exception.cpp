#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

int main()
{
    try
    {
        throw 2.7; // throw (lanza) excepción de tipo double
        cout << "Esto nunca se imprime" << endl;;
    }
    catch (double x) // maneja excepción de tipo double
    {
        cerr << "Hemos capturado un double de valor: " << x << endl;
    }
    return 0;
}