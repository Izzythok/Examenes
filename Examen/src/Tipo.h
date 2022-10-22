/*
 * Tipo.h
 *
 *  Created on: 21 oct. 2022
 *      Author: Izzyto
 */

#ifndef TIPO_H_
#define TIPO_H_

#include "IngresoDeDatos.h"

#define TAM_Tipo 5

typedef struct{
	int id;
	char Descripcion[20];
}eTipo;

int eTipo_CargarDescripcion(eTipo ListaL[], int TamL, int idTipo, char DescrTipo[]);
void eTipo_MostrarUno(eTipo* Tipo);
int eTipo_MostrarTodos(eTipo lista[], int longitud);
int eTipo_IngresarId(eTipo lista[], int longitud, int* ID);

#endif /* TIPO_H_ */
