#include <iostream>
using namespace std;

// Aqui creamos la estructura del nodo
struct Nodo {
    int dato;
    Nodo* siguiente;
};

// Funcion para agregar un nuevo nodo a la lista
void agregarNodo(Nodo*& cabeza, int valor) {

    // Reservamos memoria para el nuevo nodo
    Nodo* nuevo = new Nodo();

    nuevo->dato = valor;
    nuevo->siguiente = NULL;

    // Si la lista esta vacia, el nuevo nodo sera la cabeza
    if (cabeza == NULL) {
        cabeza = nuevo;
    }
    else {

        // Recorremos la lista hasta llegar al ultimo nodo
        Nodo* auxiliar = cabeza;

        while (auxiliar->siguiente != NULL) {
            auxiliar = auxiliar->siguiente;
        }

        // Enlazamos el ultimo nodo con el nuevo
        auxiliar->siguiente = nuevo;
    }

    cout << "\nValor agregado correctamente.\n";
}

// Funcion para mostrar todos los elementos de la lista
void mostrarLista(Nodo* cabeza) {

    // Verificamos si la lista esta vacia
    if (cabeza == NULL) {
        cout << "\nLa lista esta vacia.\n";
        return;
    }

    Nodo* auxiliar = cabeza;

    cout << "\n===== CONTENIDO DE LA LISTA =====\n\n";

    // Recorremos toda la lista mostrando cada nodo
    while (auxiliar != NULL) {

        cout << "[" << auxiliar->dato << " | ";

        // Si no hay siguiente nodo mostramos NULL
        if (auxiliar->siguiente == NULL) {
            cout << "NULL";
        }
        else {
            cout << "*";
        }

        cout << "]";

        if (auxiliar->siguiente != NULL) {
            cout << " -> ";
        }

        auxiliar = auxiliar->siguiente;
    }

    cout << "\n";
}

// Funcion para liberar toda la memoria utilizada
void liberarMemoria(Nodo*& cabeza) {

    Nodo* auxiliar;

    // Eliminamos nodo por nodo
    while (cabeza != NULL) {

        auxiliar = cabeza;
        cabeza = cabeza->siguiente;

        delete auxiliar;
    }

    cout << "\nMemoria liberada correctamente.\n";
}

int main() {

    Nodo* cabeza = NULL;

    int opcion;
    int valor;

    do {

        cout << "\n====================================";
        cout << "\n     LISTA ENLAZADA DINAMICA";
        cout << "\n====================================";
        cout << "\n1. Agregar valor";
        cout << "\n2. Mostrar lista";
        cout << "\n3. Salir";
        cout << "\n====================================";
        cout << "\nSeleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {

        case 1:

            cout << "\nIngrese un valor entero: ";
            cin >> valor;

            agregarNodo(cabeza, valor);

            break;

        case 2:

            mostrarLista(cabeza);

            break;

        case 3:

            // Antes de salir liberamos la memoria
            liberarMemoria(cabeza);

            cout << "\nPrograma finalizado.\n";

            break;

        default:

            cout << "\nOpcion invalida. Intente nuevamente.\n";
        }

    } while (opcion != 3);

    return 0;
}