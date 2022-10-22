/*
 * Tipo.c
 *
 *  Created on: 21 oct. 2022
 *      Author: Izzyto
 */


#include "Tipo.h"

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
				eTipo_MostrarUno(&lista[i]);
				bandera=0;

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
