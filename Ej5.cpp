#include <iostream>
#include "Cola/Cola.h"
#include "Pila/Pila.h"
using namespace std;

void separarParesEImpares(Cola<int> &cola, Pila<int> &pila) {
    if (cola.esVacia()) {
        cout << "Error: La cola está vacía." << endl;
        return;
    }

    Cola<int> colaAux;

    // Separar los números pares en la colaAux y los impares en la pila
    while (!cola.esVacia()) {
        int dato = cola.desencolar();

        if (dato % 2 == 0) {
            colaAux.encolar(dato); // Enqueue even numbers to colaAux
        } else {
            pila.push(dato); // Push odd numbers to the stack
        }
    }

    // Devolver los elementos de colaAux a la cola original
    while (!colaAux.esVacia()) {
        cola.encolar(colaAux.desencolar());
    }
}

void mostrarCola(Cola<int> &cola) {
    Cola<int> colaAux;

    // Mostrar los elementos de la cola y guardarlos en colaAux
    while (!cola.esVacia()) {
        int dato = cola.desencolar();
        cout << dato << " ";
        colaAux.encolar(dato);
    }
    cout << endl;

    // Devolver los elementos de colaAux a la cola original
    while (!colaAux.esVacia()) {
        cola.encolar(colaAux.desencolar());
    }
}

int main() {

    Cola<int> cola;
    Pila<int> pila;

    cout << "Ingrese numeros para la cola (ingrese -1 para terminar): " << endl;
    int input;
    while (cin >> input && input != -1) {
        cola.encolar(input);
    }

    separarParesEImpares(cola, pila);

    cout << "Cola despues de quitar numeros impares: ";
    mostrarCola(cola);

    cout << "Pila con elementos impares (orden inverso): ";
    while (!pila.esVacia()) {
        cout << pila.pop() << " ";
    }
    cout << endl;

}