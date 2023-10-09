#include <iostream>

using namespace std;

int main() {
    char operador;
    double num1, num2, resultado;

    cout << "Ingrese un numero: ";
    cin >> num1;

    cout << "Ingrese que operacion quiere realizar (+, -, *, /): ";
    cin >> operador;

    cout << "ingrese otro numero: ";
    cin >> num2;

    switch (operador) {
        case '+':
            resultado = num1 + num2;
            break;
        case '-':
            resultado = num1 - num2;
            break;
        case '*':
            resultado = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                resultado = num1 / num2;
            } else {
                cout << "Error: No se puede dividir por cero." << endl;
                return 1; // Salir del programa con un código de error
            }
            break;
        default:
            cout << "Operador no válido." << endl;
            return 1; // Salir del programa con un código de error
    }

    cout << "Resultado: " << resultado << endl;

    return 0;
}
