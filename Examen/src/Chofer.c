/*
 * Chofer.c
 *
 *  Created on: 28 oct. 2022
 *      Author: Izzyto
 */

#include "Chofer.h"

int eChofer_idAutoincremental = 2500;
int eChofer_ObtenerIdUnico()
{
	return eChofer_idAutoincremental++;
}

int eChofer_Inicializar(eChofer lista[],int longitud)
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

int eChofer_CargarDescripcion(eChofer Lista[], int Tam, int idChofer, char* DescrChofer)
{
	int rtn=0;
	if(Lista!=NULL && Tam>0 && DescrChofer!=NULL)
	{
		for(int i=0;i<Tam;i++)
		{
			if(Lista[i].id==idChofer)
			{
				strcpy(DescrChofer,Lista[i].Nombre);
				rtn=1;
				break;
			}
		}
	}

	return rtn;
}

void eChofer_MostrarUno(eChofer* Chofer)
{

	printf("    %d    %-10s   %c\n",Chofer->id,Chofer->Nombre,Chofer->Sexo);
}

int eChofer_MostrarTodos(eChofer lista[], int longitud)
{
	int rtn=0;
	int bandera=1;
	if(lista!=NULL && longitud>0)
	{
		system("cls");
		printf("                  *** Lista de Choferes *** \n");
		printf("----------------------------------------------------------------\n");
		printf("    ID      Chofer     Sexo\n");
		printf("----------------------------------------------------------------\n");
		for(int i=0;i<longitud;i++)
		{
			if(lista[i].isEmpty==OCUPADO)
			{
				eChofer_MostrarUno(&lista[i]);
				bandera=0;
			}
		}
		if(bandera)
		{
			printf("no hay Choferes para mostrar\n");
		}

		rtn=1;
	}
	return rtn;
}

int eChofer_IngresarId(eChofer lista[], int longitud, int* ID)
{
	int rtn=-1;
	int reintentos = 3;
	int Auxid;
	int Errores;
	if(lista!=NULL && longitud>0)
	{
		eChofer_MostrarTodos(lista, longitud);
		do{
			Errores=getIntSinRango("Ingrese el id del Chofer", "Error! debe ingresar el Id de la Tabla", 3, &Auxid);
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
