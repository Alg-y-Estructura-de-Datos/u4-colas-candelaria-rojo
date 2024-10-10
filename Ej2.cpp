/*Implementar una función que suprima de la cola todos los elementos mayores que un número
“n” dado como límite. Al final se debe imprimir la cola depurada sin perder el orden que había
desde la cola original.*/

#include <iostream>
#include "Cola/Cola.h"
using namespace std;

// Función para eliminar elementos mayores a un límite dado de la cola
void suprimirMayores(Cola<int> &cola, int n) {
    Cola<int> aux;

    // Eliminar elementos de la cola original que sean menores o iguales al límite
    while (!cola.esVacia()) {
        int dato = cola.desencolar();
        if (dato <= n) {
            aux.encolar(dato);
        }
    }

    // Mover los elementos de vuelta a la cola original
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
