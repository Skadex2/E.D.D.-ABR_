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

// Buscar nodo por ID
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

// Mostrar recorridos
void mostrarPreorden(Nodo* nodo) {
    if (nodo == NULL) { return; }
    cout << nodo->id << " - " << nodo->nombre << endl;
    mostrarPreorden(nodo->izquierdo);
    mostrarPreorden(nodo->derecho);
}

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

// Eliminar miembro si no tiene hijos
bool eliminarMiembro(Nodo* nodo, int id) {
    if (nodo == NULL) { return false; }

    if (nodo->izquierdo != NULL && nodo->izquierdo->id == id) {
        if (nodo->izquierdo->izquierdo == NULL && nodo->izquierdo->derecho == NULL) {
            delete nodo->izquierdo;
            nodo->izquierdo = NULL;
            return true;
        } else {
            cout << "No se puede eliminar:   tiene hijos.\n";
            return false;
        }
    }

    if (nodo->derecho != NULL && nodo->derecho->id == id) {
        if (nodo->derecho->izquierdo == NULL && nodo->derecho->derecho == NULL) {
            delete nodo->derecho;
            nodo->derecho = NULL;
            return true;
        } else {
            cout << "No se puede eliminar:   tiene hijos.\n";
            return false;
        }
    }

    return eliminarMiembro(nodo->izquierdo, id) || eliminarMiembro(nodo->derecho, id);
}

// Funcion Menú
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
        cout << "¿Lado del hijo? (I = Izquierdo, D = Derecho): ";
        cin >> lado;
    } else {
        lado = 'R'; // raiz
    }

    insertarMiembro(id, nombre, idPadre, lado);
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
    int opcion;

    do {
        cout << "\n******** ARBOL GENEALOGICO *******\n";
        cout << "1. Insertar miembro\n";
        cout << "2. Mostrar Preorden\n";
        cout << "3. Mostrar Inorden\n";
        cout << "4. Mostrar Postorden\n";
        cout << "5. Eliminar miembro (si no tiene hijos)\n";
        cout << "6. Salir\n";

        do {
            cout << "Seleccione opcion: ";
            cin >> opcion;
            if (opcion < 1 || opcion > 6) {
                cout << "Opcion invalida. Intente de nuevo.\n";
            }
        } while (opcion < 1 || opcion > 6);

        
        switch (opcion) {
            case 1: 
				menuInsertarMiembro(); 
				break;
            case 2: 
                cout << "Preorden:\n"; 
                mostrarPreorden(raiz); 
                break;
            case 3: 
                cout << "Inorden:\n"; 
                mostrarInorden(raiz); 
                break;
            case 4: 
                cout << "Postorden:\n"; 
                mostrarPostorden(raiz); 
                break;
            case 5: 
				menuEliminarMiembro(); 
				break;
            case 6: 
				cout << "Saliendo...\n"; 
				break;
        }

    } while (opcion != 6);
}

