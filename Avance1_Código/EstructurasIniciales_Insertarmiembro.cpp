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

// Buscar un nodo por ID
Nodo* buscarPadre(Nodo* nodo, int id) {
    if (nodo == NULL) { return NULL; }
    if (nodo->id == id) { return nodo; }

    Nodo* izq = buscarPadre(nodo->izquierdo, id);
    if (izq != NULL) { return izq; }

    return buscarPadre(nodo->derecho, id);
}

// Insertar nodo
void insertarMiembro(int id, string nombre, int idPadre, char lado) {
    Nodo* nuevo = new Nodo(id, nombre);

    if (idPadre == 0) {
        if (raiz == NULL) {
            raiz = nuevo;
            cout << "Raiz insertada.\n";
        } else {
            cout << "Ya existe una raiz.\n";
            delete nuevo;
        }
        return;
    }

    Nodo* padre = buscarPadre(raiz, idPadre);
    if (padre == NULL) {
        cout << "Padre no encontrado.\n";
        delete nuevo;
        return;
    }

    if ((lado == 'I' || lado == 'i') && padre->izquierdo == NULL) {
        padre->izquierdo = nuevo;
        cout << "Insertado como hijo izquierdo.\n";
    } else if ((lado == 'D' || lado == 'd') && padre->derecho == NULL) {
        padre->derecho = nuevo;
        cout << "Insertado como hijo derecho.\n";
    } else {
        cout << "Ya hay un hijo en ese lado o el lado es invalido.\n";
        delete nuevo;
    }
}
// ================= FUNCIONES DE MENÚ =================

void menuInsertarMiembro() {
    int id, idPadre;
    string nombre;
    char lado;

    cout << "Ingrese ID del nuevo miembro: ";
    cin >> id;
    cout << "Ingrese nombre: ";
    cin >> nombre;
    cout << "Ingrese ID del padre (0 si es raiz): ";
    cin >> idPadre;

    if (idPadre != 0) {
        cout << "Lado del hijo (I = Izquierdo, D = Derecho): ";
        cin >> lado;
    } else {
        lado = 'R'; // raíz
    }

    insertarMiembro(id, nombre, idPadre, lado);
}

// ================= MENÚ PRINCIPAL =================
int main() {
     menuInsertarMiembro();
}
