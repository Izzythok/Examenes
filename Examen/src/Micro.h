/*
 * Micro.h
 *
 *  Created on: 21 oct. 2022
 *      Author: Izzyto
 */

#ifndef MICRO_H_
#define MICRO_H_

//#include "IngresoDeDatos.h"
#include "Chofer.h"
#include "Empresa.h"
#include "Tipo.h"

#define TAM 9
#define VACIO 1
#define OCUPADO 0

#define IDVIP 5003



typedef struct{
	int id;
	int idEmpresa;
	int idTipo;
	int idChofer;
	int Capacidad;
	int isEmpty;

}eMicro;

/*Solo esta en el .h por la funcion harcodeo*/
int eMicro_ObtenerIdUnico();

int Menu();
int SubMenuInformes();

int eMicro_Inicializar(eMicro lista[],int longitud);
int eMicro_BuscarEspacioLibre(eMicro lista[], int longitud);

void eMicro_MostrarUno(eMicro* Micro, eEmpresa listaE[], int TamE, eTipo listaT[], int TamT, eChofer listaC[], int TamC);
int eMicro_MostrarTodos(eMicro lista[], int longitud, eEmpresa listaE[], int TamE, eTipo listaT[], int TamT, eChofer listaC[], int TamC);

int eMicro_Alta(eMicro lista[], int longitud, eEmpresa listaE[], int TamE, eTipo listaT[], int TamT, eChofer listaC[], int TamC);
int eMicro_CargarDatos(eMicro* Micro, eEmpresa listaE[], int TamE, eTipo listaT[], int TamT, eChofer listaC[], int TamC);

int eMicro_Baja(eMicro lista[], int longitud,eEmpresa listaE[], int TamE, eTipo listaT[], int TamT, eChofer listaC[], int TamC);
int eMicro_BuscarId(eMicro lista[], int longitud, int* id);
int eMicro_Modificar(eMicro lista[], int longitud,eEmpresa listaE[], int TamE, eTipo listaT[], int TamT, eChofer listaC[], int TamC);

int eMicro_Ordenar(eMicro lista[],int longitud, eEmpresa ListaL[], int TamL);

int eMicro_CargarDescripcion(eMicro lista[], int longitud, eTipo listaT[], int TamT, int idMicro, char* DescrMicroTipo);
int eMicro_IngresarId(eMicro lista[], int longitud, eEmpresa listaE[], int TamE, eTipo listaT[], int TamT, eChofer listaC[], int TamC, int* ID);

/*==============================================================================================================================*/

int eMicro_MostrarEmpresas(eMicro lista[], int longitud, eEmpresa listaE[], int TamE, eTipo listaT[], int TamT, eChofer listaC[], int TamC);
int eMicro_MostrarTipos(eMicro lista[], int longitud, eEmpresa listaE[], int TamE, eTipo listaT[], int TamT, eChofer listaC[], int TamC);

int eMicro_EmpresaMenorCantMicros(eMicro lista[], int longitud, eEmpresa listaE[], int TamE);
int eMicro_PorcentajeTipoVip(eMicro lista[], int longitud, eEmpresa listaE[], int TamE);
int eMicro_SeparadosEmpresas(eMicro lista[],int longitud, eEmpresa ListaE[], int TamE);

#endif /* MICRO_H_ */
