Proceso GestorArbolGenealogico
	
  Definir padre_id, padre_izq, padre_der,pila, pila1,pila2 Como Entero
	Definir padre_nombre Como Cadena
	Definir totalMiembros, opcion, i Como Entero
	Definir nombreNuevo, lado Como Caracter
	Definir idNuevo, idPadre, idBuscar, idEliminar Como Entero
	
	Dimension padre_id[100], padre_nombre[100], padre_izq[100], padre_der[100], pila[100], pila1[100], pila2[100]
  Definir tope, actual Como Entero
  Definir indiceActual Como Entero
	Definir tope1, top2, nodo Como Entero
	
  totalMiembros <- 0
	
  Para i <- 1 Hasta 100
        padre_izq[i] <- 0
        padre_der[i] <- 0
  FinPara
FinProceso
