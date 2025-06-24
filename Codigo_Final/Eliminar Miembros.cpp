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

bool insertarAutomatico(Nodo* nodo, int id, string nombre, int idPadre) {
    if (nodo == NULL) {
        return false;
    }

    if (nodo->id == idPadre) {
        if (nodo->izquierdo == NULL) {
            nodo->izquierdo = new Nodo(id, nombre);
            cout << "Insertado automaticamente como hijo izquierdo.\n";
            return true;
        } else if (nodo->derecho == NULL) {
            nodo->derecho = new Nodo(id, nombre);
            cout << "Insertado automaticamente como hijo derecho.\n";
            return true;
        } else {
            cout << "Error: El padre ya tiene dos hijos.\n";
            return false;
        }
    }

    bool insertadoIzq = insertarAutomatico(nodo->izquierdo, id, nombre, idPadre);
    if (insertadoIzq) {
        return true;
    }

    return insertarAutomatico(nodo->derecho, id, nombre, idPadre);
}

void insertarMiembro(int id, string nombre, int idPadre) {
    if (existeID(raiz, id)) {
        cout << "Error: Ya existe un miembro con ese ID.\n";
        return;
    }

    if (idPadre == 0) {
        if (raiz == NULL) {
            raiz = new Nodo(id, nombre);
            cout << "Raiz insertada.\n";
        } else {
            cout << "Ya existe una raiz.\n";
        }
    } else {
        bool insertado = insertarAutomatico(raiz, id, nombre, idPadre);
        if (!insertado) {
            cout << "No se pudo insertar el miembro.\n";
        }
    }
}

bool eliminarMiembro(Nodo* nodo, int id) {
    if (nodo == NULL) {
        return false;
    }

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

    bool eliminadoIzq = eliminarMiembro(nodo->izquierdo, id);
    if (eliminadoIzq) {
        return true;
    }

    return eliminarMiembro(nodo->derecho, id);
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
        bool eliminado = eliminarMiembro(raiz, idEliminar);
        if (eliminado) {
            cout << "Miembro eliminado.\n";
        } else {
            cout << "No se encontro el miembro o no se puede eliminar.\n";
        }
    }
}


// ================= MENUS =================

void menuInsertarMiembro() {
    int id, idPadre;
    string nombre;

    cout << "Ingrese ID del nuevo miembro: ";
    cin >> id;
    cout << "Ingrese nombre: ";
    cin >> nombre;
    cout << "Ingrese ID del padre (0 si es raiz): ";
    cin >> idPadre;

    insertarMiembro(id, nombre, idPadre);
}


int main(){
	menuInsertarMiembro();
	menuEliminarMiembro();
}
