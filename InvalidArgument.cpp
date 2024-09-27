// Ex logic error
#include <iostream>
#include <stdexcept> // Para std::invalid_argument
using namespace std;

void checkAge(int age) {
    if (age < 0) {
        throw invalid_argument("La edad no puede ser negativa");
    }
    cout << "Edad válida: " << age << endl;
}

int main() {
    setlocale(LC_ALL, "es-Es.utf8");
    try {
        checkAge(26);
        checkAge(-5); // Esto lanzará una excepción y el programa termina aquí.
        checkAge(33);
    }
    catch (const invalid_argument& e) {
        cerr << "Excepción capturada: " << e.what() << std::endl;
    }
    return 0;
}
