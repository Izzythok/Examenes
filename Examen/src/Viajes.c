/*
 * Viajes.c
 *
 *  Created on: 26 oct. 2022
 *      Author: Izzyto
 */

#include "Viajes.h"


//static int eViaje_ModificarDatos(eViaje lista[], int indice, eMicro listaM[], int TamM, eDestino listaD[], int TamD, eTipo ListaT[], int TamT);
//static int eViaje_MenuModifiacion();
static int eViaje_VerificarDiaDelMes(int mes , int dia);
int eViaje_idAutoincremental = 10000;
int eViaje_ObtenerIdUnico()
{
	return eViaje_idAutoincremental++;
}


int eViaje_Inicializar(eViaje lista[],int longitud)
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

int eViaje_BuscarEspacioLibre(eViaje lista[], int longitud)
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

int eViaje_Alta(eViaje lista[], int longitud, eMicro listaM[], int TamM, eDestino listaD[], int TamD, eTipo ListaT[], int TamT, eEmpresa listaE[], int TamE, eChofer listaC[], int TamC)
{
	int rtn=0;
	eViaje AuxiViaje;
	int indice;
	int errores;
	char confirmar;
	if(lista!=NULL && longitud>0)
	{
		indice=eViaje_BuscarEspacioLibre(lista, longitud);

		if(indice==-1) {
			printf("No hay lugar disponible\n");
		} else {

			errores=eViaje_CargarDatos(&AuxiViaje,listaM,TamM,listaD,TamD,ListaT,TamT,listaE,TamE,listaC,TamC);

			if(errores)
			{
				AuxiViaje.id=eViaje_ObtenerIdUnico();
				AuxiViaje.isEmpty=OCUPADO;
				if(Confirmar("Desea confirmar el Alta? precione: { S }",&confirmar))
				{
					lista[indice] = AuxiViaje;
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

int eViaje_CargarDatos(eViaje* Viaje, eMicro listaM[], int TamM, eDestino listaD[], int TamD, eTipo ListaT[], int TamT, eEmpresa listaE[], int TamE, eChofer listaC[], int TamC)
{
	int rtn=0;
	int Errores;
	int banderaError=0;

	if(Viaje!=NULL && listaM!=NULL && TamM>0 && listaD!=NULL && TamD>0 && ListaT!=NULL && TamT>0)
	{
		Errores = eMicro_IngresarId(listaM, TamM,listaE,TamE,ListaT,TamT,listaC,TamC, &Viaje->idMicro);
		if(Errores==1)
		{
			Errores=eDestino_IngresarId(listaD, TamD, &Viaje->idDestino);

			if(Errores==1)
			{
				Errores=eViaje_IngresarFecha(Viaje);

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

void eViaje_MostrarUno(eViaje* Viaje, eMicro listaM[], int TamM, eDestino listaD[], int TamD, eTipo ListaT[], int TamT)
{
	char DescripDestino[20];
	char DescripMicroTipo[20];

	eDestino_CargarDescripcion(listaD, TamD, Viaje->idDestino, DescripDestino);
	eMicro_CargarDescripcion(listaM, TamM, ListaT, TamT, Viaje->idMicro, DescripMicroTipo);

	printf("    %d   %-10s    %-10s     %d/%d/%d   \n",Viaje->id,DescripDestino,DescripMicroTipo,Viaje->fecha.dia,Viaje->fecha.mes,Viaje->fecha.anio);
}

int eViaje_MostrarTodos(eViaje lista[], int longitud, eMicro listaM[], int TamM, eDestino listaD[], int TamD, eTipo ListaT[], int TamT)
{
	int rtn=0;
	int bandera=1;
	if(lista!=NULL && longitud>0)
	{
		system("cls");
		printf("                  *** Lista de Viajes *** \n");
		printf("----------------------------------------------------------------\n");
		printf("    ID    Destino      Micro      Fecha \n");
		printf("----------------------------------------------------------------\n");
		for(int i=0;i<longitud;i++)
		{
			if(lista[i].isEmpty==OCUPADO)
			{
				eViaje_MostrarUno(&lista[i],listaM,TamM,listaD,TamD,ListaT,TamT);
				bandera=0;
			}
		}
		rtn=1;
		if(bandera)
		{
			printf("no hay Viajes para mostrar\n");
			rtn=-1;
		}
	}
	return rtn;
}


int eViaje_IngresarFecha(eViaje* Viaje)
{
	int rtn=0;
	int Errores;
	int reintentos = 3;
	int contador=0;
	if(Viaje!=NULL)
	{
		puts("Ingrese Fecha de Viaje\n");

		do{

			Errores=getInt("Ingrese el Dia:", "Error! ingrese un valor numerico, debe estar en el rango del mes", 1, 31, 3, &Viaje->fecha.dia);
			if(Errores==1)
			{
				contador++;
				Errores=getInt("Ingrese el Mes:", "Error! ingrese un valor numerico, debe estar en el rango de meses", 1, 12, 3, &Viaje->fecha.mes);

				if(Errores==1 && eViaje_VerificarDiaDelMes(Viaje->fecha.mes,Viaje->fecha.dia)==1)
				{
					contador++;
					Errores=getInt("Ingrese el Anio:", "Error! ingrese un valor numerico, la fecha debe ser al dia de hoy en adelante", ANIO_ACTUAL,2050, 3, &Viaje->fecha.anio);

					if(Errores==1)
					{
						contador++;
						rtn=1;
					}
				}
			}

			if(contador!=3)
			{
				reintentos--;
				rtn=-1;
			} else {
				reintentos=0;
			}
		}while(reintentos>0);
	}

	return rtn;
}

static int eViaje_VerificarDiaDelMes(int mes , int dia)
{
	int rtn=0;

	if(mes<=12 && mes>=1 && dia<=31 && dia>=1)
	{
			if(mes==2)
			{
				if(dia<=28)
				{
					rtn=1;
				} else {
					rtn=-1;
				}
			}
			else if(mes==4 || mes==6 || mes==9 || mes==11)
			{
				if(dia<=30)
				{
					rtn=1;
				} else {
					rtn=-1;
				}
			} else {
				rtn=1;
			}

			if(rtn==-1)
			{
				printf("Error! El dia no corresponde al maximo dias del mes\n");
			}
	}

	return rtn;
}
/*---------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------------------*/
/*
int eViaje_Baja(eViaje lista[], int longitud, eMicro listaM[], int TamM, eDestino listaD[], int TamD, eTipo ListaT[], int TamT)
{
	int rtn=0;
	int indice;
	int id;
	char Confirma;
	int Errores;
	if(lista!=NULL && longitud>0)
	{
		system("cls");
		Errores=eViaje_MostrarTodos(lista, longitud, listaM, TamM, listaD, TamD, ListaT, TamT);
		if(Errores==1)
		{
			Errores=getInt("Ingrese el ID Para dar de baja", "Error! el dato ingresado no corresponde a lo pedido", 10000,15000,3, &id);
			if(Errores)
			{
				indice = eViaje_BuscarId(lista, longitud, &id);

				if(indice==-1) {
					printf("el ID %d no esta ingresado en el sistema\n",id);
				}
				else
				{
					eViaje_MostrarUno(&lista[indice],listaM,TamM,listaD,TamD,ListaT,TamT);
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
		else
		{
			printf("DEBE DAR DE ALTA\n");
			rtn=-1;
		}

	}

	return rtn;
}

int eViaje_Modificar(eViaje lista[], int longitud, eMicro listaM[], int TamM, eDestino listaD[], int TamD, eTipo ListaT[], int TamT)
{
	int rtn=0;
	int indice;
	int id;
	char Confirma;
	int Errores;

	if(lista!=NULL && longitud>0)
	{
		system("cls");
		Errores=eViaje_MostrarTodos(lista, longitud, listaM, TamM, listaD, TamD, ListaT, TamT);
		if(Errores==1)
		{
			Errores=getInt("Ingrese el ID para la MODIFICACION", "Error! el dato ingresado no corresponde a lo pedido", 1000, 9999, 3, &id);
			if(Errores)
			{
				indice = eViaje_BuscarId(lista, longitud, &id);

				if(indice==-1) {
					printf("el ID %d no esta ingresado en el sistema\n",id);
				}
				else
				{
					eViaje_MostrarUno(&lista[indice],listaM,TamM,listaD,TamD,ListaT,TamT);
					Confirmar("Desea confirmar Modificar? precione: { S }", &Confirma);
					if(Confirma=='s')
					{
						rtn=eViaje_ModificarDatos(lista,indice,listaM,TamM,listaD,TamD,ListaT,TamT);

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
		else
		{
			printf("DEBE DAR DE ALTA\n");
			rtn=-1;
		}

	}

	return rtn;
}



int eViaje_BuscarId(eViaje lista[], int longitud, int* id)
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

static int eViaje_ModificarDatos(eViaje lista[], int indice, eMicro listaM[], int TamM, eDestino listaD[], int TamD, eTipo ListaT[], int TamT)
{
	int rtn=0;

	if(lista!=NULL)
	{
		char Confirma;
		int Errores;
		int Capacidad;
		int IDMicro;
		int IDDestino;

		switch (eViaje_MenuModifiacion()) {
		case 1:
			Errores = eMicro_IngresarId(listaM, TamM, &IDMicro);
			if (Errores == -1 || !Errores) {
				rtn = -1;
			} else {
				lista[indice].idMicro = IDDestino;
				rtn = 1;
			}
			break;
		case 2:
			Errores = eDestino_IngresarId(listaD, TamD, &IDDestino);
			if (Errores == -1 || !Errores) {
				rtn = -1;
			} else {
				lista[indice].idDestino = IDDestino;
				rtn = 1;
			}
			break;
		case 3:
			break;
		case 4:
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

int eViaje_Ordenar(eViaje lista[],int longitud, eMicro ListaE[], int TamE)
{
	int rtn=0;
	eViaje Aux;
	char MicroI[20];
	char MicroJ[20];

		if(lista!=NULL && longitud>0)
		{
			for(int i=0;i<longitud-1;i++)
			{
				eMicro_CargarDescripcion(ListaE, TamE, lista[i].idMicro, MicroI);
				for(int j=i+1;j<longitud;j++)
				{
					eMicro_CargarDescripcion(ListaE, TamE, lista[j].idMicro, MicroJ);
					if( strcmp(MicroI,MicroJ)>0 || ( strcmp(MicroI,MicroJ)==0 && lista[i].Capacidad > lista[j].Capacidad) )
					{
						Aux=lista[i];
						lista[i]=lista[j];
						strcpy(MicroI,MicroJ);
						lista[j]=Aux;
					}
				}
			}

			rtn=1;
			//printf("Ordenamiento Exitoso\n");
		}

	return rtn;
}

static int eViaje_MenuModifiacion()
{
	int opciones=0;
	int Errores;

	printf("1- Destino\n");
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
*/
