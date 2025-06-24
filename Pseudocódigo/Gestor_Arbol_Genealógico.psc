Proceso GestorArbolGenealogico
	
    Definir padre_id, padre_izq, padre_der,pila, pila1,pila2 Como Entero
	Definir padre_nombre Como Cadena
	Definir totalMiembros, opcion, i Como Entero
	Definir nombreNuevo, lado Como Caracter
	Definir idNuevo, idPadre, idBuscar, idEliminar Como Entero
        Definir indicePadre Como Entero
	
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
					
			2:
                Si totalMiembros = 0 Entonces
                    Escribir "Árbol vacío."
                Sino
                    tope <- 0
                    indiceActual <- 1
					
                    tope <- tope + 1
                    pila[tope] <- indiceActual
					
                    Mientras tope > 0 Hacer
                        indiceActual <- pila[tope]
                        tope <- tope - 1
                        Escribir padre_id[indiceActual], " - ", padre_nombre[indiceActual]
						
                        Si padre_der[indiceActual] <> 0 Entonces
                            tope <- tope + 1
                            pila[tope] <- padre_der[indiceActual]
                        FinSi
						
                        Si padre_izq[indiceActual] <> 0 Entonces
                            tope <- tope + 1
                            pila[tope] <- padre_izq[indiceActual]
                        FinSi
                    FinMientras
                FinSi
					
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
					
			5: // Eliminar miembro
				Si totalMiembros = 0 Entonces
					Escribir "No hay miembros para eliminar."
				Sino
					Escribir "Ingrese ID del miembro a eliminar:"
					Leer idEliminar
					
					Definir indiceEliminar Como Entero
					indiceEliminar <- 0
					
					Para i <- 1 Hasta totalMiembros
						Si padre_id[i] = idEliminar Entonces
							indiceEliminar <- i
						FinSi
					FinPara
					
					Si indiceEliminar = 0 Entonces
						Escribir "Miembro no encontrado."
					Sino
						Si padre_izq[indiceEliminar] <> 0 O padre_der[indiceEliminar] <> 0 Entonces
							Escribir "No se puede eliminar un miembro con hijos."
						Sino
							// Buscar padre para desconectar al hijo eliminado
							Para i <- 1 Hasta totalMiembros
								Si padre_izq[i] = indiceEliminar Entonces
									padre_izq[i] <- 0
								FinSi
								Si padre_der[i] = indiceEliminar Entonces
									padre_der[i] <- 0
								FinSi
							FinPara
							
							// Reemplazar el nodo eliminado con el último nodo si no es el mismo
							Si indiceEliminar <> totalMiembros Entonces
								padre_id[indiceEliminar] <- padre_id[totalMiembros]
								padre_nombre[indiceEliminar] <- padre_nombre[totalMiembros]
								padre_izq[indiceEliminar] <- padre_izq[totalMiembros]
								padre_der[indiceEliminar] <- padre_der[totalMiembros]
								
								// Actualizar referencias que apuntaban al último nodo
								Para i <- 1 Hasta totalMiembros - 1
									Si padre_izq[i] = totalMiembros Entonces
										padre_izq[i] <- indiceEliminar
									FinSi
									Si padre_der[i] = totalMiembros Entonces
										padre_der[i] <- indiceEliminar
									FinSi
								FinPara
							FinSi
							
							totalMiembros <- totalMiembros - 1
							Escribir "Miembro eliminado correctamente."
						FinSi
					FinSi
				FinSi
					
			6:
				Escribir "Saliendo del programa."
				
			De Otro Modo:
				Escribir "Opción inválida, intente de nuevo."
		FinSegun
			
	Hasta Que opcion = 6
	
FinProceso
