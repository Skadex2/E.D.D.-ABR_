#include <iostream>
#include <string>
using namespace std;

struct Nodo {
    int id;
    string nombre;
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(int i, string nom) {
        id = i;
        nombre = nom;
        izquierdo = NULL;
        derecho = NULL;
    }
};

Nodo* raiz = NULL;


void mostrarPreorden(Nodo* nodo) {
    if (nodo == NULL) { return; }
    cout << nodo->id << " - " << nodo->nombre << endl;
    mostrarPreorden(nodo->izquierdo);
    mostrarPreorden(nodo->derecho);
}


bool eliminarMiembro(Nodo* nodo, int id) {
    if (nodo == NULL) { return false; }

    if (nodo->izquierdo != NULL && nodo->izquierdo->id == id) {
        if (nodo->izquierdo->izquierdo == NULL && nodo->izquierdo->derecho == NULL) {
            delete nodo->izquierdo;
            nodo->izquierdo = NULL;
            return true;
        } else {
            cout << "No se puede eliminar: tiene hijos.\n";
            return false;
        }
    }

    if (nodo->derecho != NULL && nodo->derecho->id == id) {
        if (nodo->derecho->izquierdo == NULL && nodo->derecho->derecho == NULL) {
            delete nodo->derecho;
            nodo->derecho = NULL;
            return true;
        } else {
            cout << "No se puede eliminar: tiene hijos.\n";
            return false;
        }
    }

    return eliminarMiembro(nodo->izquierdo, id) || eliminarMiembro(nodo->derecho, id);
}

void menuEliminarMiembro() {
    if (raiz == NULL) {
        cout << "Arbol vacio.\n";
        return;
    }

    int idEliminar;
    cout << "Ingrese ID a eliminar: ";
    cin >> idEliminar;

    if (raiz->id == idEliminar) {
        if (raiz->izquierdo == NULL && raiz->derecho == NULL) {
            delete raiz;
            raiz = NULL;
            cout << "Raiz eliminada.\n";
        } else {
            cout << "No se puede eliminar la raiz con hijos.\n";
        }
    } else {
        if (eliminarMiembro(raiz, idEliminar)) {
            cout << "Miembro eliminado.\n";
        } else {
            cout << "No se encontro el miembro o no se puede eliminar.\n";
        }
    }
}


int main() {
    mostrarPreorden(raiz);
    menuEliminarMiembro();
}

