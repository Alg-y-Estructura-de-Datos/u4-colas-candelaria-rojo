/*Crear una función que reciba una cola por referencia y un número. Dicha función debe: Eliminar
todas las ocurrencias de dicho número, menos la primera. Si dicho número no se repite, deja la
cola como esta. Si dicho número no está en la cola, debe anunciar un mensaje de error. Imprimir
la cola al final para verificar si hubo o no modificaciones.
*/

#include <iostream>
#include "Cola/Cola.h"
using namespace std;

void eliminarOcurrencias (Cola<int> &cola, int n) {
    Cola<int> aux; // Creamos una cola auxiliar para almacenar los elementos que no se deben eliminar
    bool encontrado = false; // Variable para indicar si se encontró la primera ocurrencia del número a eliminar
    
    while (!cola.esVacia()) { // Mientras la cola no esté vacía
        int dato = cola.desencolar(); // Desencolamos un elemento de la cola
        
        if (dato == n && !encontrado) { // Si el elemento es igual al número a eliminar y no se ha encontrado la primera ocurrencia
            encontrado = true; // Marcamos que se encontró la primera ocurrencia
            aux.encolar(dato); // Encolamos el elemento en la cola auxiliar
        } else if (dato != n) { // Si el elemento no es igual al número a eliminar
            aux.encolar(dato); // Encolamos el elemento en la cola auxiliar
        }
    }
    
    if (!encontrado) { // Si no se encontró ninguna ocurrencia del número a eliminar
        cout << "El número no se encuentra en la cola." << endl; // Imprimimos un mensaje de error
    }
    
    while (!aux.esVacia()) { // Mientras la cola auxiliar no esté vacía
        cola.encolar(aux.desencolar()); // Desencolamos un elemento de la cola auxiliar y lo encolamos en la cola original
    }
}

int main() {
    Cola<int> cola; // Creamos una cola de enteros
    int numero; // Variable para almacenar el número a eliminar

    cout << "Ingrese numeros para la cola (ingrese 0 para terminar): " << endl;
    int elem;
    while (cin >> elem && elem != 0) { // Leemos números de entrada hasta que se ingrese 0
        cola.encolar(elem); // Encolamos el número en la cola
    }

    cout << "Ingrese el numero a eliminar: ";
    cin >> numero; // Leemos el número a eliminar

    eliminarOcurrencias(cola, numero); // Llamamos a la función para eliminar las ocurrencias del número en la cola

    cout << "Cola resultante: ";
    while (!cola.esVacia()) { // Mientras la cola no esté vacía
        cout << cola.desencolar() << " "; // Desencolamos un elemento de la cola y lo imprimimos
    }
    cout << endl;
}
