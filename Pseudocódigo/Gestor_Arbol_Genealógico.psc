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
	
	Repetir
        Escribir ""
        Escribir "====== ÁRBOL GENEALÓGICO ======"
        Escribir "1. Insertar miembro"
        Escribir "2. Mostrar Preorden"
        Escribir "3. Mostrar Inorden"
        Escribir "4. Mostrar Postorden"
        Escribir "5. Eliminar miembro"
        Escribir "6. Salir"
        Escribir "Seleccione opción:"
        Leer opcion
		
        Segun opcion Hacer
			
            1: // Insertar miembro
				
				
			2:
                
			4: // Mostrar Postorden
				
				
			5: // Eliminar miembro
				
				
			6:
				Escribir "Saliendo del programa."
				
			De Otro Modo:
				Escribir "Opción inválida, intente de nuevo."
		FinSegun
		
	Hasta Que opcion = 6
	
FinProceso
