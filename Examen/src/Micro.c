/*
 * Micro.c
 *
 *  Created on: 21 oct. 2022
 *      Author: Izzyto
 */

#include "Micro.h"


static int eMicro_ModificarDatos(eMicro lista[], int indice,eTipo listaT[], int TamT);
static int eMicro_MenuModifiacion();
//static int eMicro_ObtenerIdUnico();
int idAutoincremental = 8000;
int eMicro_ObtenerIdUnico()
{
	return idAutoincremental++;
}

int Menu()
{
	int opciones=0;
	int Errores;

	printf("    *** ABM Micros ***\n\n");
	printf("1- Alta Micros\n");
	printf("2- Baja Micros\n");
	printf("3- Modificacion Micros\n");
	printf("4- Listar Micros\n");
	printf("5- Listar Empresas\n");
	printf("6- Listar Tipos\n");
	printf("7- Listar Destinos\n");
	printf("8- Salir\n");

	Errores=getInt("Ingrese una de las opciones", "Error! el Valor esta mal ingresado o no corresponde a las opciones", 1, 8, 3, &opciones);
	if(Errores==-1)
	{
		printf("Error! No esta ingresando lo solicitado\n");
	}

	system("cls");

	return opciones;
}

static int eMicro_MenuModifiacion()
{
	int opciones=0;
	int Errores;

	printf("1- Tipo\n");
	printf("2- Capacidad\n");
	printf("3- Salir\n");

	Errores=getInt("Ingrese una de las opciones", "Error! el Valor esta mal ingresado o no corresponde a las opciones", 1, 3, 3, &opciones);
	if(Errores==-1)
	{
		printf("Error! No esta ingresando lo solicitado\n");
		opciones=-1;
	}

	system("cls");

	return opciones;
}

int eMicro_Inicializar(eMicro lista[],int longitud)
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

int eMicro_BuscarEspacioLibre(eMicro lista[], int longitud)
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

int eMicro_Alta(eMicro lista[], int longitud, eEmpresa listaE[], int TamE, eTipo listaT[], int TamT)
{
	int rtn=0;
	eMicro AuxiMicro;
	int indice;
	int errores;
	char confirmar;
	if(lista!=NULL && longitud>0)
	{
		indice=eMicro_BuscarEspacioLibre(lista, longitud);

		if(indice==-1) {
			printf("No hay lugar disponible\n");
		} else {

			errores=eMicro_CargarDatos(&AuxiMicro,listaE,TamE,listaT,TamT);

			if(errores)
			{
				AuxiMicro.id=eMicro_ObtenerIdUnico();
				AuxiMicro.isEmpty=OCUPADO;
				if(Confirmar("Desea confirmar el Alta? precione: { S }",&confirmar))
				{
					lista[indice] = AuxiMicro;
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

int eMicro_Baja(eMicro lista[], int longitud, eEmpresa listaE[], int TamE, eTipo listaT[], int TamT)
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
			indice = eMicro_BuscarId(lista, longitud, &id);

			if(indice==-1) {
				printf("el ID %d no esta ingresado en el sistema\n",id);
			}
			else
			{
				eMicro_MostrarUno(&lista[indice],listaE,TamE,listaT,TamT);
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

int eMicro_Modificar(eMicro lista[], int longitud, eEmpresa listaE[], int TamE, eTipo listaT[], int TamT)
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
			indice = eMicro_BuscarId(lista, longitud, &id);

			if(indice==-1) {
				printf("el ID %d no esta ingresado en el sistema\n",id);
			}
			else
			{
				eMicro_MostrarUno(&lista[indice],listaE,TamE,listaT,TamT);
				Confirmar("Desea confirmar Modificar? precione: { S }", &Confirma);
				if(Confirma=='s')
				{
					rtn=eMicro_ModificarDatos(lista,indice,listaT,TamT);

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

void eMicro_MostrarUno(eMicro* Micro, eEmpresa listaE[], int TamE, eTipo listaT[], int TamT)
{
	char DescripTipo[20];
	char DescripEmpresa[20];

	eTipo_CargarDescripcion(listaT, TamT, Micro->idTipo, DescripTipo);
	eEmpresa_CargarDescripcion(listaE, TamE, Micro->idEmpresa, DescripEmpresa);

	printf("   %-10s    %-10s     %d   \n",DescripTipo,DescripEmpresa,Micro->Capacidad);
}

int eMicro_MostrarTodos(eMicro lista[], int longitud, eEmpresa listaE[], int TamE, eTipo listaT[], int TamT)
{
	int rtn=0;
	int bandera=1;
	if(lista!=NULL && longitud>0)
	{
		system("cls");
		printf("                  *** Lista de Micros *** \n");
		printf("----------------------------------------------------------------\n");
		printf("    TIPO      EMPRESA      CAPACIDAD \n");
		printf("----------------------------------------------------------------\n");
		for(int i=0;i<longitud;i++)
		{
			if(lista[i].isEmpty==OCUPADO)
			{
				eMicro_MostrarUno(&lista[i],listaE,TamE,listaT,TamT);
				bandera=0;
			}
		}
		if(bandera)
		{
			printf("no hay Micros para mostrar\n");
		}

		rtn=1;
	}
	return rtn;
}

int eMicro_CargarDatos(eMicro* Micro, eEmpresa listaE[], int TamE, eTipo listaT[], int TamT)
{
	int rtn=0;
	int Errores;
	int banderaError=0;

	if(Micro!=NULL)
	{
		Errores=eTipo_IngresarId(listaT, TamT, &Micro->idTipo);
		if(Errores==1)
		{
			Errores=eEmpresa_IngresarId(listaE, TamE, &Micro->idEmpresa);

			if(Errores==1)
			{
				Errores=getInt("Ingrese la Capacidad:", "Error! debe ingresar un numero o no corresponde al rango de la Capacidad", 1, 50, 3, &Micro->Capacidad);

					if(Errores==1) {
						rtn=1;
					} else {
						banderaError=1;
					}

			}else {
				banderaError=1;
			}

		} else {
			banderaError=1;
		}

		if(banderaError)
		{
			printf("Error! en el Alta\n");
		}
	}

	return rtn;
}

int eMicro_BuscarId(eMicro lista[], int longitud, int* id)
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

static int eMicro_ModificarDatos(eMicro lista[], int indice,eTipo listaT[], int TamT)
{
	int rtn=0;

	if(lista!=NULL)
	{
		char Confirma;
		int Errores;
		int Capacidad;
		int IDTipo;

		switch (eMicro_MenuModifiacion()) {
		case 1:
			Errores = eTipo_IngresarId(listaT, TamT, &IDTipo);
			if (Errores == -1 || !Errores) {
				rtn = -1;
			} else {
				lista[indice].idTipo = IDTipo;
				rtn = 1;
			}
			break;
		case 2:
			Errores = getInt("Ingrese la Nueva Capacidad", "Error! debe ingresar un numero o no corresponde al rango de la Capidad", 1, 50, 3, &Capacidad);
			if (Errores == -1 || !Errores) {
				rtn = -1;
			} else {
				lista[indice].Capacidad = Capacidad;
				rtn = 1;
			}
			break;
		case 3:
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

/*int eMicro_Ordenar(eMicro lista[],int longitud, int criterio)
{
	int rtn=0;
	eMicro Aux;

		if(lista!=NULL && longitud>0 && (criterio==1 || !criterio))
		{
			for(int i=0;i<longitud-1;i++)
			{
				for(int j=i+1;j<longitud;j++)
				{
					if( (criterio && (lista[i].sexo > lista[j].sexo || (lista[i].sexo == lista[j].sexo && strcmp(lista[i].nombre,lista[j].nombre)>0)))
							||
							(!criterio && lista[i].sexo < lista[j].sexo))
					{
						Aux=lista[i];
						lista[i]=lista[j];
						lista[j]=Aux;
					}
				}
			}

			rtn=1;
			printf("Ordenamiento Exitoso\n");
		}

	return rtn;
}*/

