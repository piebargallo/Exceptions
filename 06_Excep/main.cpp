/* La divisi�n entre cero es uno de esos casos de excepci�n no est�ndar en C++
  y no hay manera de capturarlo de forma gen�rica. */

#include <iostream>

double division(double a, double b)
{
    if (b == 0)
        throw 0;
    return a / b;
}

int main()
{
    try
    {
        std::cout << division(4.1, 4.1)  << std::endl;
        std::cout << division(10, 0) << std::endl; // Excepcion: 0
    }
    catch (int ex)
    {
        std::cout << "Excepcion: " << ex << std::endl;
    }
    return 0;
}