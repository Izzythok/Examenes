/*
 * Micro.h
 *
 *  Created on: 21 oct. 2022
 *      Author: Izzyto
 */

#ifndef MICRO_H_
#define MICRO_H_

#include "IngresoDeDatos.h"
#include "Empresa.h"
#include "Tipo.h"

#define TAM 10
#define VACIO 1
#define OCUPADO 0


typedef struct{
	int id;
	int idEmpresa;
	int idTipo;
	int Capacidad;
	int isEmpty;

}eMicro;

/*Solo esta en el .h por el harcodeo*/
int eMicro_ObtenerIdUnico();

int Menu();
int eMicro_Inicializar(eMicro lista[],int longitud);
int eMicro_BuscarEspacioLibre(eMicro lista[], int longitud);
int eMicro_Alta(eMicro lista[], int longitud, eEmpresa listaE[], int TamE, eTipo listaT[], int TamT);

void eMicro_MostrarUno(eMicro* Micro, eEmpresa listaE[], int TamE, eTipo listaT[], int TamT);
int eMicro_MostrarTodos(eMicro lista[], int longitud, eEmpresa listaE[], int TamE, eTipo listaT[], int TamT);
int eMicro_CargarDatos(eMicro* Micro, eEmpresa listaE[], int TamE, eTipo listaT[], int TamT);
int eMicro_Baja(eMicro lista[], int longitud,eEmpresa listaE[], int TamE, eTipo listaT[], int TamT);

int eMicro_BuscarId(eMicro lista[], int longitud, int* id);
int eMicro_Modificar(eMicro lista[], int longitud,eEmpresa listaE[], int TamE, eTipo listaT[], int TamT);




#endif /* MICRO_H_ */
