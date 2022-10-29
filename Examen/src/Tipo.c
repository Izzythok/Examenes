/*
 * Tipo.c
 *
 *  Created on: 21 oct. 2022
 *      Author: Izzyto
 */


#include "Tipo.h"

static int eTipo_ModificarDatos(eTipo lista[], int indice);
static int eTipo_MenuModifiacion();
//static int eTipo_ObtenerIdUnico();
int eTipo_idAutoincremental = 5000;
int eTipo_ObtenerIdUnico()
{
	return eTipo_idAutoincremental++;
}

int eTipo_CargarDescripcion(eTipo ListaL[], int TamL, int idTipo, char* DescrTipo)
{
	int rtn=0;
	if(ListaL!=NULL && TamL>0 && DescrTipo!=NULL)
	{
		for(int i=0;i<TamL;i++)
		{
			if(ListaL[i].id==idTipo)
			{
				strcpy(DescrTipo,ListaL[i].Descripcion);
				rtn=1;
				break;
			}
		}
	}

	return rtn;
}

void eTipo_MostrarUno(eTipo* Tipo)
{

	printf("    %d    %-10s\n",Tipo->id,Tipo->Descripcion);
}

int eTipo_MostrarTodos(eTipo lista[], int longitud)
{
	int rtn=0;
	int bandera=1;
	if(lista!=NULL && longitud>0)
	{
		system("cls");
		printf("                  *** Lista de Tipos *** \n");
		printf("----------------------------------------------------------------\n");
		printf("    ID      Tipo \n");
		printf("----------------------------------------------------------------\n");
		for(int i=0;i<longitud;i++)
		{
			if(lista[i].isEmpty==OCUPADO)
			{
				eTipo_MostrarUno(&lista[i]);
				bandera=0;
			}

		}
		if(bandera)
		{
			printf("no hay Tipos para mostrar\n");
		}

		rtn=1;
	}
	return rtn;
}

int eTipo_IngresarId(eTipo lista[], int longitud, int* ID)
{
	int rtn=-1;
	int reintentos = 3;
	int Auxid;
	int Errores;
	if(lista!=NULL && longitud>0)
	{
		eTipo_MostrarTodos(lista, longitud);
		do{
			Errores=getIntSinRango("Ingrese el id de la Tipo", "Error! debe ingresar el Id de la Tabla", 3, &Auxid);
			rtn=0;
			if(Errores)
			{
				for(int i=0;i<longitud;i++)
				{
					if(lista[i].id == Auxid)
					{
						rtn=1;
						*ID=Auxid;
						break;
					}
				}

				if(!rtn) {
					printf("Error! debe ingresar el Id de la Tabla\n");
					reintentos--;
				} else {
					reintentos=0;
				}

			} else {
				printf("Error! debe ingresar el Id de la Tabla\n");
				reintentos--;
			}


		}while(reintentos>0);


	}
	return rtn;
}


int eTipo_Inicializar(eTipo lista[],int longitud)
{
	int rtn=0;

	if(lista!=NULL && longitud>0)
	{
		for(int i =0;i<longitud;i++)
		{
			lista[i].isEmpty=VACIO;
		}
		rtn=1;
	}
	return rtn;
}

int eTipo_BuscarEspacioLibre(eTipo lista[], int longitud)
{
	int rtn=-1;
	if(lista!=NULL && longitud>0)
	{
		for(int i =0;i<longitud;i++)
		{
			if(lista[i].isEmpty==VACIO)
			{
				rtn=i;
				break;
			}
		}
	}

	return rtn;
}

int eTipo_Alta(eTipo lista[], int longitud)
{
	int rtn=0;
	eTipo AuxiTipo;
	int indice;
	int errores;
	char confirmar;
	if(lista!=NULL && longitud>0)
	{
		indice=eTipo_BuscarEspacioLibre(lista, longitud);

		if(indice==-1) {
			printf("No hay lugar disponible\n");
		} else {

			errores=eTipo_CargarDatos(&AuxiTipo);

			if(errores)
			{
				AuxiTipo.id=eTipo_ObtenerIdUnico();
				AuxiTipo.isEmpty=OCUPADO;
				if(Confirmar("Desea confirmar el Alta? precione: { S }",&confirmar))
				{
					lista[indice] = AuxiTipo;
					rtn= indice;
					printf("Alta Exitosa\n");
				} else {
					rtn=-1;
				}
			}
		}

	}

	return rtn;
}

int eTipo_Baja(eTipo lista[], int longitud)
{
	int rtn=0;
	int indice;
	int id;
	char Confirma;
	int Errores;
	if(lista!=NULL && longitud>0)
	{
		system("cls");
		Errores=getInt("Ingrese el ID Para dar de baja", "Error! el dato ingresado no corresponde a lo pedido", 1000, 9999, 3, &id);
		if(Errores)
		{
			eTipo_MostrarTodos(lista, longitud);
			indice = eTipo_BuscarId(lista, longitud, &id);

			if(indice==-1) {
				printf("el ID %d no esta ingresado en el sistema\n",id);
			}
			else
			{
				eTipo_MostrarUno(&lista[indice]);
				Confirmar("Desea confirmar el BAJA? precione: { S }", &Confirma);
				if(Confirma=='s')
				{
					lista[indice].isEmpty=VACIO;
					rtn=1;
					printf("Baja EXITOSA!\n");
				} else {
					printf("Baja CANCELADA\n");
					rtn=-1;
				}
			}
		}
		else
		{
			printf("Error! no esta ingresando un valor correcto\n");
			rtn=1;
		}
	}

	return rtn;
}

int eTipo_Modificar(eTipo lista[], int longitud)
{
	int rtn=0;
	int indice;
	int id;
	char Confirma;
	int Errores;

	if(lista!=NULL && longitud>0)
	{
		system("cls");
		Errores=getInt("Ingrese el ID para la MODIFICACION", "Error! el dato ingresado no corresponde a lo pedido", 1000, 9999, 3, &id);
		if(Errores)
		{
			eTipo_MostrarTodos(lista, longitud);
			indice = eTipo_BuscarId(lista, longitud, &id);

			if(indice==-1) {
				printf("el ID %d no esta ingresado en el sistema\n",id);
			}
			else
			{
				eTipo_MostrarUno(&lista[indice]);
				Confirmar("Desea confirmar Modificar? precione: { S }", &Confirma);
				if(Confirma=='s')
				{
					rtn=eTipo_ModificarDatos(lista,indice);

				} else {
					printf("Modificacion CANCELADA\n");
					rtn=-1;
				}
			}
		}
		else
		{
			printf("Error! no esta ingresando un valor correcto\n");
			rtn=1;
		}
	}

	return rtn;
}

int eTipo_CargarDatos(eTipo* Tipo)
{
	int rtn=0;
	int Errores;
	int banderaError=0;

	if(Tipo!=NULL)
	{
		Errores=GetString("Ingrese el Tipo", 3, sizeof(Tipo->Descripcion), Tipo->Descripcion);
		if (Errores == 1) {
			rtn = 1;
		} else {
			banderaError = 1;
		}

		if(banderaError)
		{
			printf("Error! en el Alta\n");
		}
	}

	return rtn;
}

int eTipo_BuscarId(eTipo lista[], int longitud, int* id)
{
	int rtn=-1;

	if(lista!=NULL && longitud>0)
	{
		for(int i =0;i<longitud;i++)
		{
			if(lista[i].isEmpty==OCUPADO && lista[i].id == *id)
			{
				rtn=i;
				break;
			}
		}
	}
	return rtn;
}

static int eTipo_ModificarDatos(eTipo lista[], int indice)
{
	int rtn=0;

	if(lista!=NULL)
	{
		char Confirma;
		int Errores;
		char Descripcion[20];

		switch (eTipo_MenuModifiacion()) {
		case 1:
			Errores = GetString("Ingrese el Nuevo nombre", 3, 20, Descripcion);
			if (Errores == -1 || !Errores) {
				rtn = -1;
			} else {
				strcpy(lista[indice].Descripcion, Descripcion);
				rtn = 1;
			}
			break;
		case 2:
			Confirmar("DESEA SALIR? para confirmar precione: {s}", &Confirma);
			break;
		}

		if(rtn){
			printf("Modificacion EXITOSA!\n");
		} else {
			printf("Error! en la modificacion\n");
		}
	}
	return rtn;
}

static int eTipo_MenuModifiacion()
{
	int opciones=0;
	int Errores;

	printf("1- Descripcion\n");
	printf("2- Salir\n");

	Errores=getInt("Ingrese una de las opciones", "Error! el Valor esta mal ingresado o no corresponde a las opciones", 1, 2, 3, &opciones);
	if(Errores==-1)
	{
		printf("Error! No esta ingresando lo solicitado\n");
		opciones=-1;
	}

	system("cls");

	return opciones;
}
