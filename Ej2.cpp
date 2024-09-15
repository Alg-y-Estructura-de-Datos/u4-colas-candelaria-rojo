/*Implementar una función que suprima de la cola todos los elementos mayores que un número
“n” dado como límite. Al final se debe imprimir la cola depurada sin perder el orden que había
desde la cola original.*/

#include <iostream>
#include "Cola/Cola.h"
using namespace std;

void suprimirMayores(Cola<int> &cola, int n) {
    Cola<int> aux;
    while (!cola.esVacia()) {
        int dato = cola.desencolar();
        if (dato <= n) {
            aux.encolar(dato);
        }
    }
    while (!aux.esVacia()) {
        cola.encolar(aux.desencolar());
    }
}


int main() {

    Cola<int> cola;

    // Lectura de la cola
    cout << "Ingrese números para la cola (ingrese 0 para terminar): " << endl;
    int num;
    while (cin >> num && num != 0) {
        cola.encolar(num);
    }

    // Lectura del límite
    cout << "Ingrese el limite: ";
    int limite;
    cin >> limite;

    // Supresión de los elementos mayores al límite
    suprimirMayores(cola, limite);

    // Impresión de la cola depurada
    cout << "Cola depurada: ";
    while (!cola.esVacia()) {
        cout << cola.desencolar() << " ";
    }
    cout << endl;
}
