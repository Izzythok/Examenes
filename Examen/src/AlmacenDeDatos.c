/*
 * AlmacenDeDatos.c
 *
 *  Created on: 21 oct. 2022
 *      Author: Izzyto
 */


#include "AlmacenDeDatos.h"



int idEmpresa[MAX_DATOS] = {1002,1000,1002,1003,1003,1002,1000,1001,1002,1001};
int idTipo[MAX_DATOS] = {5002,5003,5003,5001,5003,5002,5000,5001,5000,5001};
int idChofer[MAX_DATOS] = {2501,2500,2502,2503,2500,2502,2503,2501,2500,2501};
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
			lista[i].idChofer = idChofer[i];
			lista[i].Capacidad = capacidad[i];
			lista[i].isEmpty = OCUPADO;
			contador++;
		}
	}
	return contador;
}


char destino[MAX_DATOS][25] = {"Calafate","Bariloche","Salta","Mendoza"};
float Precio[MAX_DATOS]={22250,103000,84400,95600};

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
			lista[i].isEmpty = OCUPADO;
			contador++;
		}
	}
	return contador;
}


char nombres[MAX_DATOS][20] = {"Comun","CocheCama","Doble","Vip"};

int eTipo_Harcodear(eTipo lista[], int longitud, int Cant)
{
	int contador=-1;
	if(lista!=NULL && longitud>0 && Cant>0 && Cant<=longitud)
	{
		contador=0;
		for(int i =0;i<Cant;i++)
		{
			lista[i].id= eTipo_ObtenerIdUnico();
			strcpy(lista[i].Descripcion, nombres[i]);
			lista[i].isEmpty = OCUPADO;
			contador++;
		}
	}
	return contador;
}



char Empresas[MAX_DATOS][20] = {"Plusmar","Flecha bus","Tas","El rapido"};

int eEmpresa_Harcodear(eEmpresa lista[], int longitud, int Cant)
{
	int contador=-1;
	if(lista!=NULL && longitud>0 && Cant>0 && Cant<=longitud)
	{
		contador=0;
		for(int i =0;i<Cant;i++)
		{
			lista[i].id= eEmpresa_ObtenerIdUnico();
			strcpy(lista[i].Descripcion, Empresas[i]);
			lista[i].isEmpty = OCUPADO;
			contador++;
		}
	}
	return contador;
}

char NombreChofer[MAX_DATOS][25] = {"Juan","Flor","Roberto","Ignacio"};
char Sexo[MAX_DATOS]={'m','f','m','m'};
int eChofer_Harcodear(eChofer lista[], int longitud, int Cant)
{
	int contador=-1;
	if(lista!=NULL && longitud>0 && Cant>0 && Cant<=longitud)
	{
		contador=0;
		for(int i =0;i<Cant;i++)
		{
			lista[i].id= eChofer_ObtenerIdUnico();
			strcpy(lista[i].Nombre, NombreChofer[i]);
			lista[i].Sexo = Sexo[i];
			lista[i].isEmpty = OCUPADO;
			contador++;
		}
	}
	return contador;
}
