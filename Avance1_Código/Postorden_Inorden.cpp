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

void mostrarInorden(Nodo* nodo) {
    if (nodo == NULL) { return; }
    mostrarInorden(nodo->izquierdo);
    cout << nodo->id << " - " << nodo->nombre << endl;
    mostrarInorden(nodo->derecho);
}

void mostrarPostorden(Nodo* nodo) {
    if (nodo == NULL) { return; }
    mostrarPostorden(nodo->izquierdo);
    mostrarPostorden(nodo->derecho);
    cout << nodo->id << " - " << nodo->nombre << endl;
}
// ================= MENÚ PRINCIPAL =================

int main() {
	mostrarInorden(raiz); 
	mostrarPostorden(raiz); 
}

