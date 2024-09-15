/*Imagina una oficina con varias impresoras compartidas por varios empleados. Cada vez que un
empleado envía un documento para imprimir, este se coloca en una cola de impresión. Las
impresoras trabajan de manera que el primer documento enviado es el primero en ser impreso.
Si una impresora está ocupada, el documento queda en espera en la cola hasta que la impresora
esté disponible.
Implementar un sistema de gestión de colas de impresión en el que se:
 Agreguen documentos a la cola de impresión.
 Se impriman documentos en el orden en que fueron enviados.
 Se pueda mostrar el estado de la cola de impresión y los documentos pendientes.*/

#include <iostream>
#include "Cola/Cola.h"
using namespace std;

struct Documento {
    string nombre;
    int paginas;

    Documento(const string& nombre = "", int paginas = 0) : nombre(nombre), paginas(paginas) {}

    void mostrar() const {
        cout << "Documento: " << nombre << ", Paginas: " << paginas << endl;
    }
};

void agregarDocumento(Cola<Documento> &cola) {
    string nombre;
    int paginas;

    cout << "Ingrese el nombre del documento: ";
    cin.ignore();
    getline(cin, nombre);

    cout << "Ingrese la cantidad de paginas: ";
    cin >> paginas;

    cola.encolar(Documento(nombre, paginas));
}

void imprimirDocumento(Cola<Documento> &cola) {
    if (cola.esVacia()) {
        cout << "No hay documentos en espera." << endl;
        return;
    }

    Documento documento = cola.desencolar();
    cout << "Imprimiendo documento:" << endl;
    documento.mostrar();
}

void mostrarDocumentos(Cola<Documento> &cola) {
    Cola<Documento> aux;

    cout << "Documentos en espera:" << endl;
    while (!cola.esVacia()) {
        Documento documento = cola.desencolar();
        documento.mostrar();
        aux.encolar(documento);
    }

    while (!aux.esVacia()) {
        cola.encolar(aux.desencolar());
    }
}

int main() {
    Cola<Documento> cola;
    int opcion;

    do {
        cout << "MENU:" << endl;
        cout << "1. Agregar documento" << endl;
        cout << "2. Imprimir documento" << endl;
        cout << "3. Mostrar documentos en espera" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarDocumento(cola);
                break;
            case 2:
                imprimirDocumento(cola);
                break;
            case 3:
                mostrarDocumentos(cola);
                break;
            case 4:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opcion != 4);

}



