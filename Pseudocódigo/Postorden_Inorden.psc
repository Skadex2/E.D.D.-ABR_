Proceso GestorArbolGenealogico

	Dimension padre_id[100], padre_nombre[100], padre_izq[100], padre_der[100], pila[100], pila1[100], pila2[100]
    	Definir tope, actual Como Entero
    	Definir indiceActual Como Entero
	Definir tope1, top2, nodo Como Entero
	
    	Definir padre_id, padre_izq, padre_der,pila, pila1,pila2 Como Entero
	Definir padre_nombre Como Cadena
	Definir totalMiembros, opcion, i Como Entero
	Definir nombreNuevo, lado Como Caracter
	Definir idNuevo, idPadre, idBuscar, idEliminar Como Entero
	
	
	
    totalMiembros <- 0
	
    Para i <- 1 Hasta 100
        padre_izq[i] <- 0
        padre_der[i] <- 0
    FinPara
	
	Repetir
        Escribir ""
        Escribir "====== ÁRBOL GENEALÓGICO ======"
        Escribir "3. Mostrar Inorden"
        Escribir "4. Mostrar Postorden"
        Escribir "5. Salir"
        Escribir "Seleccione opción:"
        Leer opcion
		
        Segun opcion Hacer
			3: // Mostrar Inorden
				Si totalMiembros = 0 Entonces
					Escribir "Árbol vacío."
				Sino
					tope <- 0
					actual <- 1
					
					Mientras tope > 0 O actual <> 0 Hacer
						Mientras actual <> 0 Hacer
							tope <- tope + 1
							pila[tope] <- actual
							actual <- padre_izq[actual]
						FinMientras
						
						actual <- pila[tope]
						tope <- tope - 1
						
						Escribir padre_id[actual], " - ", padre_nombre[actual]
						
						actual <- padre_der[actual]
					FinMientras
				FinSi
				
			4: // Mostrar Postorden
				Si totalMiembros = 0 Entonces
					Escribir "Árbol vacío."
				Sino
					tope1 <- 0
					tope2 <- 0
					
					tope1 <- tope1 + 1
					pila1[tope1] <- 1
					
					Mientras tope1 > 0 Hacer
						nodo <- pila1[tope1]
						tope1 <- tope1 - 1
						tope2 <- tope2 + 1
						pila2[tope2] <- nodo
						
						Si padre_izq[nodo] <> 0 Entonces
							tope1 <- tope1 + 1
							pila1[tope1] <- padre_izq[nodo]
						FinSi
						Si padre_der[nodo] <> 0 Entonces
							tope1 <- tope1 + 1
							pila1[tope1] <- padre_der[nodo]
						FinSi
					FinMientras
					
					Mientras tope2 > 0 Hacer
						nodo <- pila2[tope2]
						tope2 <- tope2 - 1
						Escribir padre_id[nodo], " - ", padre_nombre[nodo]
					FinMientras
				FinSi
				
			5:
				Escribir "Saliendo del programa."
				
			De Otro Modo:
				Escribir "Opción inválida, intente de nuevo."
		FinSegun
		
	Hasta Que opcion = 5
	
FinProceso
