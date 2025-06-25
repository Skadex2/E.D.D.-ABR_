#include <iostream>
#include <string>
using namespace std;

//================= Estructuras =================
struct Nodo {
    int id;
    string nombre;
    Nodo* izquierdo;
    Nodo* derecho;
	
	//Inicializarmos Nodo
    Nodo(int i, string nom) {
        id = i;
        nombre = nom;
        izquierdo = NULL;
        derecho = NULL;
    }
};

Nodo* raiz = NULL; //Inicializamos la raíz como NULL

// Buscar si un ID ya existe en el arbol
bool existeID(Nodo* nodo, int id) {
    if (nodo == NULL) {
        return false;
    }
    if (nodo->id == id) {
        return true;
    }
    
    //Recursiva para buscar en los hijos
    return existeID(nodo->izquierdo, id) || existeID(nodo->derecho, id);
}

//Buscar un Nodo con ID
Nodo* buscarPadre(Nodo* nodo, int id) {
    if (nodo == NULL) {
        return NULL;
    }
    if (nodo->id == id) {
        return nodo;
    }
	
	//Buscar en los hijos
    Nodo* izq = buscarPadre(nodo->izquierdo, id);
    if (izq != NULL) {
        return izq;
    }

    return buscarPadre(nodo->derecho, id);
}

//Insertar un hijo bajo un padre especifico
bool insertarAutomatico(Nodo* nodo, int id, string nombre, int idPadre) {
    if (nodo == NULL) {
        return false;
    }

    if (nodo->id == idPadre) {  // Si encontramos el padre
    	
    	// Insertamos en el hijo izquierdo si está vacío
        if (nodo->izquierdo == NULL) {
            nodo->izquierdo = new Nodo(id, nombre); // Crear nuevo nodo izquierdo
            cout << "Insertado automaticamente como hijo izquierdo.\n";
            return true;
        } else if (nodo->derecho == NULL) {
            nodo->derecho = new Nodo(id, nombre); // Crear nuevo nodo derecho
            cout << "Insertado automaticamente como hijo derecho.\n";
            return true;
        } else {
            cout << "Error: El padre ya tiene dos hijos.\n";
            return false;
        }
    }
	
	//Recursiva para insertar en los hijos
    bool insertadoIzq = insertarAutomatico(nodo->izquierdo, id, nombre, idPadre);
    if (insertadoIzq) {
        return true;
    }

    return insertarAutomatico(nodo->derecho, id, nombre, idPadre);
}

// ================= FUNCIONES =================

//Función insertar Miembro con ID del padre
void insertarMiembro(int id, string nombre, int idPadre) {
    if (existeID(raiz, id)) {
        cout << "Error: Ya existe un miembro con ese ID.\n";
        return;
    }
	
	//Se inserta como raíz si la ID padre es 0
    if (idPadre == 0) {
        if (raiz == NULL) {
            raiz = new Nodo(id, nombre);
            cout << "Raiz insertada.\n";
        } else {
            cout << "Ya existe una raiz.\n";
        }
    } else {
    	
    	//Se inserta bajo  el nodo con esa ID
        bool insertado = insertarAutomatico(raiz, id, nombre, idPadre);
        if (!insertado) {
            cout << "No se pudo insertar el miembro.\n";
        }
    }
}

//Funcion mostrar Preorden (R, I, D)
void mostrarPreorden(Nodo* nodo) {
    if (nodo == NULL) {
        return;
    }
    cout << nodo->id << " - " << nodo->nombre << endl;  //Mostrar el nodo actual (padre)
    mostrarPreorden(nodo->izquierdo); // Mostrar el hijo izquierdo
    mostrarPreorden(nodo->derecho); // Mostrar el hijo derecho
}

//Funcion mostrar Inorden (I,R,D)
void mostrarInorden(Nodo* nodo) {
    if (nodo == NULL) {
        return;
    }
    mostrarInorden(nodo->izquierdo);
    cout << nodo->id << " - " << nodo->nombre << endl; 
    mostrarInorden(nodo->derecho);
}

//Funcion mostrar Postorden (I,D,R)
void mostrarPostorden(Nodo* nodo) {
    if (nodo == NULL) {
        return;
    }
    mostrarPostorden(nodo->izquierdo);
    mostrarPostorden(nodo->derecho);
    cout << nodo->id << " - " << nodo->nombre << endl; 
}

//Funcion eliminar Miembro, si no tiene hijos
bool eliminarMiembro(Nodo* nodo, int id) {
    if (nodo == NULL) {
        return false;
    }

    if (nodo->izquierdo != NULL && nodo->izquierdo->id == id) {  // Si encontramos el miembro en el hijo izquierdo
        if (nodo->izquierdo->izquierdo == NULL && nodo->izquierdo->derecho == NULL) {  // Si no tiene hijos
            delete nodo->izquierdo;    // Eliminar el nodo
            nodo->izquierdo = NULL;
            return true;
        } else {
            cout << "No se puede eliminar: tiene hijos.\n";
            return false;
        }
    }

    if (nodo->derecho != NULL && nodo->derecho->id == id) {   // Si encontramos el miembro en el hijo derecho
        if (nodo->derecho->izquierdo == NULL && nodo->derecho->derecho == NULL) {    // Si no tiene hijos
            delete nodo->derecho;   // Eliminar el nodo
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

//Funcion para Insertar Miembro
void menuInsertarMiembro() {
    int id, idPadre;
    string nombre;

    cout << "Ingrese ID del nuevo miembro: ";
    cin >> id;
    cout << "Ingrese nombre: ";
    cin >> nombre;
    cout << "Ingrese ID del padre (0 si es raiz): ";
    cin >> idPadre;

    insertarMiembro(id, nombre, idPadre);  // Llamar a la función para insertar el miembro
}

//Funcion EliminarMiembro
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

// ================= MAIN  MENU =================

int main() {
    int opcion;

    do {
        cout << "\n====== ARBOL GENEALOGICO ======\n";
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

    return 0;
}
