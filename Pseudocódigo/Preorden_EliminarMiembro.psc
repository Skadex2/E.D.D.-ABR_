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
        Escribir "1. Mostrar Preorden"
        Escribir "2. Eliminar miembro"
        Escribir "3. Salir"
        Escribir "Seleccione opción:"
        Leer opcion
		
        Segun opcion Hacer
			1: // Mostrar Preorden
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
					
			2: // Eliminar miembro
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
					
			3:
				Escribir "Saliendo del programa."
				
			De Otro Modo:
				Escribir "Opción inválida, intente de nuevo."
		FinSegun
			
	Hasta Que opcion = 3
	
FinProceso
