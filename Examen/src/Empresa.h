/*
 * Empresa.h
 *
 *  Created on: 21 oct. 2022
 *      Author: Izzyto
 */

#ifndef EMPRESA_H_
#define EMPRESA_H_

#include "IngresoDeDatos.h"

#define TAM_EMPRESA 5

typedef struct{
	int id;
	char Descripcion[20];
}eEmpresa;

int eEmpresa_CargarDescripcion(eEmpresa ListaL[], int TamL, int idEmpresa, char DescrEmpresa[]);
void eEmpresa_MostrarUno(eEmpresa* Empresa);
int eEmpresa_MostrarTodos(eEmpresa lista[], int longitud);
int eEmpresa_IngresarId(eEmpresa lista[], int longitud, int* ID);
#endif /* EMPRESA_H_ */
