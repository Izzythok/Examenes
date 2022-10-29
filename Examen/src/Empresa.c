/*
 * Empresa.c
 *
 *  Created on: 21 oct. 2022
 *      Author: Izzyto
 */


#include "Empresa.h"

static int eEmpresa_ModificarDatos(eEmpresa lista[], int indice);
static int eEmpresa_MenuModifiacion();
//static int eEmpresa_ObtenerIdUnico();
int eEmpresa_idAutoincremental = 1000;
int eEmpresa_ObtenerIdUnico()
{
	return eEmpresa_idAutoincremental++;
}

int eEmpresa_CargarDescripcion(eEmpresa ListaL[], int TamL, int idEmpresa, char* DescrEmpresa)
{
	int rtn=0;
	if(ListaL!=NULL && TamL>0 && DescrEmpresa!=NULL)
	{
		for(int i=0;i<TamL;i++)
		{
			if(ListaL[i].id==idEmpresa)
			{
				strcpy(DescrEmpresa,ListaL[i].Descripcion);
				rtn=1;
				break;
			}
		}
	}

	return rtn;
}

void eEmpresa_MostrarUno(eEmpresa* Empresa)
{

	printf("    %d    %-10s\n",Empresa->id,Empresa->Descripcion);
}

int eEmpresa_MostrarTodos(eEmpresa lista[], int longitud)
{
	int rtn=0;
	int bandera=1;
	if(lista!=NULL && longitud>0)
	{
		system("cls");
		printf("                  *** Lista de Empresas *** \n");
		printf("----------------------------------------------------------------\n");
		printf("    ID      Empresa \n");
		printf("----------------------------------------------------------------\n");
		for(int i=0;i<longitud;i++)
		{
			if(lista[i].isEmpty==OCUPADO)
			{
				eEmpresa_MostrarUno(&lista[i]);
				bandera=0;
			}

		}
		if(bandera)
		{
			printf("no hay Empresas para mostrar\n");
		}

		rtn=1;
	}
	return rtn;
}

int eEmpresa_IngresarId(eEmpresa lista[], int longitud, int* ID)
{
	int rtn=-1;
	int reintentos = 3;
	int Auxid;
	int Errores;
	if(lista!=NULL && longitud>0)
	{
		eEmpresa_MostrarTodos(lista, longitud);
		do{
			Errores=getIntSinRango("Ingrese el id de la Empresa", "Error! debe ingresar el Id de la Tabla", 3, &Auxid);
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


static int eEmpresa_MenuModifiacion()
{
	int opciones=0;
	int Errores;

	printf("1- Empresa\n");
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

int eEmpresa_Inicializar(eEmpresa lista[],int longitud)
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

int eEmpresa_BuscarEspacioLibre(eEmpresa lista[], int longitud)
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

int eEmpresa_Alta(eEmpresa lista[], int longitud)
{
	int rtn=0;
	eEmpresa AuxiEmpresa;
	int indice;
	int errores;
	char confirmar;
	if(lista!=NULL && longitud>0)
	{
		indice=eEmpresa_BuscarEspacioLibre(lista, longitud);

		if(indice==-1) {
			printf("No hay lugar disponible\n");
		} else {

			errores=eEmpresa_CargarDatos(&AuxiEmpresa);

			if(errores)
			{
				AuxiEmpresa.id=eEmpresa_ObtenerIdUnico();
				AuxiEmpresa.isEmpty=OCUPADO;
				if(Confirmar("Desea confirmar el Alta? precione: { S }",&confirmar))
				{
					lista[indice] = AuxiEmpresa;
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

int eEmpresa_Baja(eEmpresa lista[], int longitud)
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
			eEmpresa_MostrarTodos(lista, longitud);
			indice = eEmpresa_BuscarId(lista, longitud, &id);

			if(indice==-1) {
				printf("el ID %d no esta ingresado en el sistema\n",id);
			}
			else
			{
				eEmpresa_MostrarUno(&lista[indice]);
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

int eEmpresa_Modificar(eEmpresa lista[], int longitud)
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
			eEmpresa_MostrarTodos(lista, longitud);
			indice = eEmpresa_BuscarId(lista, longitud, &id);

			if(indice==-1) {
				printf("el ID %d no esta ingresado en el sistema\n",id);
			}
			else
			{
				eEmpresa_MostrarUno(&lista[indice]);
				Confirmar("Desea confirmar Modificar? precione: { S }", &Confirma);
				if(Confirma=='s')
				{
					rtn=eEmpresa_ModificarDatos(lista,indice);

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

int eEmpresa_CargarDatos(eEmpresa* Empresa)
{
	int rtn=0;
	int Errores;
	int banderaError=0;

	if(Empresa!=NULL)
	{
		Errores=GetString("Ingrese el Nombre de la Empresa", 3, sizeof(Empresa->Descripcion), Empresa->Descripcion);
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

int eEmpresa_BuscarId(eEmpresa lista[], int longitud, int* id)
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

static int eEmpresa_ModificarDatos(eEmpresa lista[], int indice)
{
	int rtn=0;

	if(lista!=NULL)
	{
		char Confirma;
		int Errores;
		char nombre[20];


		switch (eEmpresa_MenuModifiacion()) {
		case 1:
			Errores = GetString("Ingrese el nuevo nombre de la Empresa", 3, 20, nombre);
			if (Errores == -1 || !Errores) {
				rtn = -1;
			} else {
				strcpy(lista[indice].Descripcion, nombre);
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
