/*Crear un programa que solicite números enteros al usuario hasta que desee, almacenar los
números en una cola, pedir también un numero entero "n". Luego crear una función que
recibiendo una cola y un número entero “n”, si el "n" se encuentra en una de las posiciones de
la cola. Devuelva la suma de los elementos de la cola hasta llegar a "n" (sin incluir a n). Si el
número "n" no se encuentra en la cola, la función devuelve la suma de todos los elementos de
la cola. Imprimir primero la cola antes de la suma de sus elementos.*/

#include <iostream>
#include "Cola/Cola.h"
using namespace std;

int sumaHastaN(Cola<int> &cola, int n) {
    Cola<int> aux;
    int suma = 0;
    bool encontrado = false;

    while (!cola.esVacia()) {
        int dato = cola.desencolar();
        if (dato == n) {
            encontrado = true;
            break;
        }
        suma += dato;
        aux.encolar(dato);
    }
    while (!aux.esVacia()) {
        cola.encolar(aux.desencolar());
    }
    return encontrado ? suma : suma + n;
}

void imprimirCola(Cola<int> cola) {  // Se pasa la cola por valor para no modificarla
    while (!cola.esVacia()) {
        cout << cola.desencolar() << " ";  // Desencola e imprime
    }
    cout << endl;
}

int main() {
    Cola<int> cola;
    int numero;

    cout<<"Ingrese numeros para la cola (ingrese 0 para terminar): " << endl;
    int elem;
    while (cin>>elem && elem!=0) {
        cola.encolar(elem);
    }

    cout<<"Ingrese el numero a buscar: ";
    cin>>numero;

    cout << "Cola: ";
    imprimirCola(cola); 

    cout<<"Suma: "<<sumaHastaN(cola, numero)<<endl; //CORREGIR
}
