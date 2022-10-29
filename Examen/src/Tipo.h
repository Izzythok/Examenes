/*
 * Tipo.h
 *
 *  Created on: 21 oct. 2022
 *      Author: Izzyto
 */

#ifndef TIPO_H_
#define TIPO_H_

#include "IngresoDeDatos.h"

#define TAM_Tipo 4
#define VACIO 1
#define OCUPADO 0

typedef struct{
	int id;
	char Descripcion[20];
	int isEmpty;
}eTipo;

int eTipo_CargarDescripcion(eTipo ListaL[], int TamL, int idTipo, char DescrTipo[]);
void eTipo_MostrarUno(eTipo* Tipo);
int eTipo_MostrarTodos(eTipo lista[], int longitud);
int eTipo_IngresarId(eTipo lista[], int longitud, int* ID);


int eTipo_ObtenerIdUnico();

int eTipo_Alta(eTipo lista[], int longitud);
int eTipo_CargarDatos(eTipo* Tipo);
int eTipo_Inicializar(eTipo lista[],int longitud);
int eTipo_BuscarEspacioLibre(eTipo lista[], int longitud);

int eTipo_Baja(eTipo lista[], int longitud);
int eTipo_BuscarId(eTipo lista[], int longitud, int* id);

int eTipo_Modificar(eTipo lista[], int longitud);

#endif /* TIPO_H_ */
