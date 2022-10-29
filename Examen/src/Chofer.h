/*
 * Chofer.h
 *
 *  Created on: 28 oct. 2022
 *      Author: Izzyto
 */

#ifndef CHOFER_H_
#define CHOFER_H_

#include "IngresoDeDatos.h"

#define TAM_Chofer 4
#define VACIO 1
#define OCUPADO 0

typedef struct{
	int id;
	char Nombre[25];
	char Sexo;
	int isEmpty;
}eChofer;


/*Solo esta en el .h por el harcodeo*/
int eChofer_ObtenerIdUnico();

int eChofer_Inicializar(eChofer lista[],int longitud);
int eChofer_CargarDescripcion(eChofer Lista[], int Tam, int idChofer, char DescrChofer[]);
void eChofer_MostrarUno(eChofer* Chofer);
int eChofer_MostrarTodos(eChofer lista[], int longitud);
int eChofer_IngresarId(eChofer lista[], int longitud, int* ID);

#endif /* CHOFER_H_ */
