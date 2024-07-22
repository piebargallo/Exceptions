#include <iostream>
#include <stdexcept>

int divide(int numerator, int denominator) {
    try {
        if (denominator == 0) {
            throw std::runtime_error("¡División por cero!");
        }
        return numerator / denominator;
    }
    catch (const std::exception& e) {
        std::cout << "Excepción atrapada en divide(): " << e.what() << std::endl;
        throw; // Rethrow
    }
}


int main() {
    setlocale(LC_ALL, "es_ES.utf8");
    try {
        int result = divide(20, 0);
        std::cout << "Resultado: " << result << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Excepción atrapada en main: " << e.what() << std::endl;
    }
    return 0;
}
