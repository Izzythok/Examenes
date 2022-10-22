/*
 * Empresa.c
 *
 *  Created on: 21 oct. 2022
 *      Author: Izzyto
 */


#include "Empresa.h"

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
				eEmpresa_MostrarUno(&lista[i]);
				bandera=0;

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
