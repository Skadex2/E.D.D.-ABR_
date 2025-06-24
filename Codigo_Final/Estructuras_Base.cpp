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

// ================= FUNCIONES =================

// Buscar si un ID ya existe en el arbol
bool existeID(Nodo* nodo, int id) {
    if (nodo == NULL) {
        return false;
    }
    if (nodo->id == id) {
        return true;
    }
    return existeID(nodo->izquierdo, id) || existeID(nodo->derecho, id);
}

Nodo* buscarPadre(Nodo* nodo, int id) {
    if (nodo == NULL) {
        return NULL;
    }
    if (nodo->id == id) {
        return nodo;
    }

    Nodo* izq = buscarPadre(nodo->izquierdo, id);
    if (izq != NULL) {
        return izq;
    }

    return buscarPadre(nodo->derecho, id);
}


int main (){
	Nodo*raiz;
}
	
