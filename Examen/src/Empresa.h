/*
 * Empresa.h
 *
 *  Created on: 21 oct. 2022
 *      Author: Izzyto
 */

#ifndef EMPRESA_H_
#define EMPRESA_H_

#include "IngresoDeDatos.h"


#define Empresa_TAM 4
#define VACIO 1
#define OCUPADO 0

typedef struct{
	int id;
	char Descripcion[20];
	int isEmpty;
}eEmpresa;

int eEmpresa_CargarDescripcion(eEmpresa ListaL[], int TamL, int idEmpresa, char DescrEmpresa[]);
void eEmpresa_MostrarUno(eEmpresa* Empresa);
int eEmpresa_MostrarTodos(eEmpresa lista[], int longitud);
int eEmpresa_IngresarId(eEmpresa lista[], int longitud, int* ID);

int eEmpresa_ObtenerIdUnico();

int eEmpresa_Alta(eEmpresa lista[], int longitud);
int eEmpresa_CargarDatos(eEmpresa* Empresa);
int eEmpresa_Inicializar(eEmpresa lista[],int longitud);
int eEmpresa_BuscarEspacioLibre(eEmpresa lista[], int longitud);

int eEmpresa_Baja(eEmpresa lista[], int longitud);
int eEmpresa_BuscarId(eEmpresa lista[], int longitud, int* id);

int eEmpresa_Modificar(eEmpresa lista[], int longitud);
#endif /* EMPRESA_H_ */
