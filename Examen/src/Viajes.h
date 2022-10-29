/*
 * Viajes.h
 *
 *  Created on: 26 oct. 2022
 *      Author: Izzyto
 */

#ifndef VIAJES_H_
#define VIAJES_H_

#include "Micro.h"
#include "Destino.h"

#define TAM_Viaje 9
#define VACIO 1
#define OCUPADO 0
#define ANIO_ACTUAL 2022

typedef struct{
	int dia;
	int mes;
	int anio;

}eFecha;

typedef struct{
	int id;
	int idMicro;
	int idDestino;
	int isEmpty;
	eFecha fecha;
}eViaje;


int eViaje_ObtenerIdUnico();

int eViaje_Inicializar(eViaje lista[],int longitud);
int eViaje_BuscarEspacioLibre(eViaje lista[], int longitud);

void eViaje_MostrarUno(eViaje* Viaje, eMicro listaM[], int TamM, eDestino listaD[], int TamD, eTipo ListaT[], int TamT);
int eViaje_MostrarTodos(eViaje lista[], int longitud, eMicro listaM[], int TamM, eDestino listaD[], int TamD, eTipo ListaT[], int TamT);

int eViaje_Alta(eViaje lista[], int longitud,
		eMicro listaM[], int TamM,
		eDestino listaD[], int TamD,
		eTipo ListaT[], int TamT,
		eEmpresa listaE[], int TamE,
		eChofer listaC[], int TamC);
int eViaje_CargarDatos(eViaje* Viaje, eMicro listaM[], int TamM, eDestino listaD[], int TamD, eTipo ListaT[], int TamT, eEmpresa listaE[], int TamE, eChofer listaC[], int TamC);
int eViaje_IngresarFecha(eViaje* Viaje);

/*
int eViaje_Modificar(eViaje lista[], int longitud, eMicro listaM[], int TamM, eDestino listaD[], int TamD, eTipo ListaT[], int TamT);
int eViaje_BuscarId(eViaje lista[], int longitud, int* id);
int eViaje_Modificar(eViaje lista[], int longitud, eMicro listaM[], int TamM, eDestino listaD[], int TamD, eTipo ListaT[], int TamT);
*/
#endif /* VIAJES_H_ */
