/*
 * Destino.c
 *
 *  Created on: 21 oct. 2022
 *      Author: Izzyto
 */


#include "Destino.h"

int eDestino_idAutoincremental = 20000;
int eDestino_ObtenerIdUnico()
{
	return eDestino_idAutoincremental++;
}

int eDestino_CargarDescripcion(eDestino ListaL[], int TamL, int idDestino, char* DescrDestino)
{
	int rtn=0;
	if(ListaL!=NULL && TamL>0 && DescrDestino!=NULL)
	{
		for(int i=0;i<TamL;i++)
		{
			if(ListaL[i].id==idDestino)
			{
				strcpy(DescrDestino,ListaL[i].Descripcion);
				rtn=1;
				break;
			}
		}
	}

	return rtn;
}

void eDestino_MostrarUno(eDestino* Destino)
{

	printf("    %d    %-10s   %.2f\n",Destino->id,Destino->Descripcion,Destino->Precio);
}

int eDestino_MostrarTodos(eDestino lista[], int longitud)
{
	int rtn=0;
	int bandera=1;
	if(lista!=NULL && longitud>0)
	{
		system("cls");
		printf("                  *** Lista de Destinos *** \n");
		printf("----------------------------------------------------------------\n");
		printf("    ID      Destino     Precio\n");
		printf("----------------------------------------------------------------\n");
		for(int i=0;i<longitud;i++)
		{
			if(lista[i].isEmpty==OCUPADO)
			{
				eDestino_MostrarUno(&lista[i]);
				bandera=0;
			}
		}
		if(bandera)
		{
			printf("no hay Destinos para mostrar\n");
		}

		rtn=1;
	}
	return rtn;
}

int eDestino_IngresarId(eDestino lista[], int longitud, int* ID)
{
	int rtn=-1;
	int reintentos = 3;
	int Auxid;
	int Errores;
	if(lista!=NULL && longitud>0)
	{
		eDestino_MostrarTodos(lista, longitud);
		do{
			Errores=getIntSinRango("Ingrese el id del Destino", "Error! debe ingresar el Id de la Tabla", 3, &Auxid);
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
