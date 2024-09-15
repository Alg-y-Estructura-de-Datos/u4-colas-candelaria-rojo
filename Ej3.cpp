/*Crear una función que reciba una cola por referencia y un número. Dicha función debe: Eliminar
todas las ocurrencias de dicho número, menos la primera. Si dicho número no se repite, deja la
cola como esta. Si dicho número no está en la cola, debe anunciar un mensaje de error. Imprimir
la cola al final para verificar si hubo o no modificaciones.
*/

#include <iostream>
#include "Cola/Cola.h"
using namespace std;

void eliminarOcurrencias (Cola<int> &cola, int n) {
    Cola<int> aux;
    bool encontrado = false;
    
    while (!cola.esVacia()) {
        int dato = cola.desencolar();
        if (dato == n && !encontrado) {
            encontrado = true;
            aux.encolar(dato);
        } else if (dato != n) {
            aux.encolar(dato);
        }
    }
    if (!encontrado) {
        cout << "El número no se encuentra en la cola." << endl;
    }
    while (!aux.esVacia()) {
        cola.encolar(aux.desencolar());
    }

}

int main() {
    Cola<int> cola;
    int numero;

    cout<<"Ingrese numeros para la cola (ingrese 0 para terminar): " << endl;
    int elem;
    while (cin>>elem && elem!=0) {
        cola.encolar(elem);
    }

    cout<<"Ingrese el numero a eliminar: ";
    cin>>numero;

    eliminarOcurrencias(cola, numero);

    cout<<"Cola resultante: ";
    while(!cola.esVacia()){
        cout<<cola.desencolar()<<" ";
    }
    cout<<endl;
}
