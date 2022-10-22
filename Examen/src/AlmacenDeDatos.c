/*
 * AlmacenDeDatos.c
 *
 *  Created on: 21 oct. 2022
 *      Author: Izzyto
 */


#include "AlmacenDeDatos.h"






int idEmpresa[MAX_DATOS] = {1002,1003,1000,1001,1003,1002,1000,1001,1002,1001};
int idTipo[MAX_DATOS] = {5002,5003,5003,5001,5003,5002,5000,5001,5000,5001};
int capacidad[MAX_DATOS]={24,23,14,12,34,26,18,19,26,34};



int eMicro_Harcodear(eMicro lista[], int longitud, int Cant)
{
	int contador=-1;
	if(lista!=NULL && longitud>0 && Cant>0 && Cant<=longitud)
	{
		contador=0;
		for(int i =0;i<Cant;i++)
		{
			lista[i].id= eMicro_ObtenerIdUnico();
			lista[i].idEmpresa = idEmpresa[i];
			lista[i].idTipo = idTipo[i];
			lista[i].Capacidad = capacidad[i];
			lista[i].isEmpty = OCUPADO;
			contador++;
		}
	}
	return contador;
}


char destino[4][25] = {"Calafate","Bariloche","Salta","Mendoza"};
float Precio[4]={22250,103000,84400,95600};

int eDestino_Harcodear(eDestino lista[], int longitud, int Cant)
{
	int contador=-1;
	if(lista!=NULL && longitud>0 && Cant>0 && Cant<=longitud)
	{
		contador=0;
		for(int i =0;i<Cant;i++)
		{
			lista[i].id= eDestino_ObtenerIdUnico();
			strcpy(lista[i].Descripcion, destino[i]);
			lista[i].Precio = Precio[i];
			contador++;
		}
	}
	return contador;
}
