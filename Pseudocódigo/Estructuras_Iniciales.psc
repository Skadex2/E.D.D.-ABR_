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
        Escribir "ÁRBOL GENEALÓGICO "
        Escribir "1. Insertar miembro"
        Escribir "Seleccione opción:"
        Leer opcion
		
        Segun opcion Hacer
			
            1: // Insertar miembro
		Escribir "Ingrese ID del nuevo miembro:"
		Leer idNuevo
		Escribir "Ingrese nombre del nuevo miembro:"
		Leer nombreNuevo
		Escribir "Ingrese ID del padre (0 si es raíz):"
		Leer idPadre
				
		// Validar límite
		Si totalMiembros >= 100 Entonces
			Escribir "Límite máximo de miembros alcanzado."
		Sino
			// Agregar nuevo miembro temporalmente al final
			totalMiembros <- totalMiembros + 1
			padre_id[totalMiembros] <- idNuevo
			padre_nombre[totalMiembros] <- nombreNuevo
			padre_izq[totalMiembros] <- 0
			padre_der[totalMiembros] <- 0
					
			Si idPadre = 0 Entonces
				Escribir "Miembro raíz insertado."
			Sino
			   // Buscar índice del padre antes de usarlo
				Definir indicePadre Como Entero
				indicePadre <- 0
				Para i <- 1 Hasta totalMiembros - 1
					Si padre_id[i] = idPadre Entonces
					   indicePadre <- i
					// Opcional, si quieres salir al encontrar padre
					FinSi
				FinPara
						
			Si indicePadre = 0 Entonces
				Escribir "No se encontró el padre con ese ID."
				// Quitar el miembro agregado porque padre no existe
				totalMiembros <- totalMiembros - 1
			Sino
				Escribir "Ingrese lado del hijo (I = Izquierdo, D = Derecho):"
				Leer lado
							
				Si lado = "I" Entonces
					Si padre_izq[indicePadre] = 0 Entonces
					   padre_izq[indicePadre] <- totalMiembros
					   Escribir "Miembro insertado como hijo izquierdo."
				Sino
					Escribir "El padre ya tiene hijo izquierdo."
					totalMiembros <- totalMiembros - 1
				FinSi
			Sino
				Si lado = "D" Entonces
					Si padre_der[indicePadre] = 0 Entonces
					   padre_der[indicePadre] <- totalMiembros
					   Escribir "Miembro insertado como hijo derecho."
					Sino
					   Escribir "El padre ya tiene hijo derecho."
					   totalMiembros <- totalMiembros - 1
					FinSi
				Sino
					Escribir "Opción de lado inválida."
					totalMiembros <- totalMiembros - 1
				FinSi
			FinSi
		   FinSi
	      FinSi
         FinSi
				
				
     De Otro Modo:
	Escribir "Opción inválida, intente de nuevo."
   FinSegun
		
  Hasta Que opcion = 1

FinProceso
