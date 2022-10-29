/*
 * Micro.c
 *
 *  Created on: 21 oct. 2022
 *      Author: Izzyto
 */

#include "Micro.h"


static int eMicro_ModificarDatos(eMicro lista[], int indice,eTipo listaT[], int TamT);
static int eMicro_MenuModifiacion();
int eMicro_idAutoincremental = 8000;
int eMicro_ObtenerIdUnico()
{
	return eMicro_idAutoincremental++;
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
	printf("8- Alta Viaje\n");
	printf("9- Listar Viajes\n");
	printf("10- Informes\n");
	printf("11- Salir\n");

	Errores=getInt("Ingrese una de las opciones", "Error! el Valor esta mal ingresado o no corresponde a las opciones", 1, 11, 3, &opciones);
	if(Errores==-1)
	{
		printf("Error! No esta ingresando lo solicitado\n");
	}

	system("cls");

	return opciones;
}

int SubMenuInformes()
{
	int opciones=0;
	int Errores;

	printf("    *** Informes ***\n\n");
	printf("1- Mostrar micros de la empresa seleccionada por el usuario.\n");
	printf("2- Mostrar micros de un tipo seleccionado.\n");
	printf("3- Informar Promedio de micros de tipo Vip sobre el total de micros de una empresa\n");
	printf("4- Mostrar un listado de los micros separados por empresa.\n");
	printf("5- \n");
	printf("6- Mostrar la empresa con menor cantidad de micros\n");
	printf("7- Salir\n");

	Errores=getInt("Ingrese una de las opciones", "Error! el Valor esta mal ingresado o no corresponde a las opciones", 1, 7, 3, &opciones);
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

int eMicro_Alta(eMicro lista[], int longitud, eEmpresa listaE[], int TamE, eTipo listaT[], int TamT, eChofer listaC[], int TamC)
{
	int rtn=0;
	eMicro AuxiMicro;
	int indice;
	int errores;
	char confirmar;
	if(lista!=NULL && longitud>0 && listaE!=NULL && TamE>0 && listaT!=NULL && TamT>0 && listaC!=NULL && TamC>0)
	{
		indice=eMicro_BuscarEspacioLibre(lista, longitud);

		if(indice==-1) {
			printf("No hay lugar disponible\n");
		} else {

			errores=eMicro_CargarDatos(&AuxiMicro,listaE,TamE,listaT,TamT,listaC,TamC);

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

int eMicro_Baja(eMicro lista[], int longitud, eEmpresa listaE[], int TamE, eTipo listaT[], int TamT, eChofer listaC[], int TamC)
{
	int rtn=0;
	int indice;
	int id;
	char Confirma;
	int Errores;
	if(lista!=NULL && longitud>0 && listaE!=NULL && TamE>0 && listaT!=NULL && TamT>0 && listaC!=NULL && TamC>0)
	{
		system("cls");
		Errores=eMicro_MostrarTodos(lista, longitud, listaE, TamE, listaT, TamT,listaC,TamC);
		if(Errores==1)
		{
			Errores=getInt("Ingrese el ID Para dar de baja", "Error! el dato ingresado no corresponde a lo pedido", 8000,9000,3, &id);
			if(Errores)
			{
				indice = eMicro_BuscarId(lista, longitud, &id);

				if(indice==-1) {
					printf("el ID %d no esta ingresado en el sistema\n",id);
				}
				else
				{
					eMicro_MostrarUno(&lista[indice],listaE,TamE,listaT,TamT,listaC,TamC);
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

int eMicro_Modificar(eMicro lista[], int longitud, eEmpresa listaE[], int TamE, eTipo listaT[], int TamT, eChofer listaC[], int TamC)
{
	int rtn=0;
	int indice;
	int id;
	char Confirma;
	int Errores;

	if(lista!=NULL && longitud>0 && listaE!=NULL && TamE>0 && listaT!=NULL && TamT>0 && listaC!=NULL && TamC>0)
	{
		system("cls");
		Errores=eMicro_MostrarTodos(lista, longitud, listaE, TamE, listaT, TamT,listaC,TamC);
		if(Errores==1)
		{
			Errores=getInt("Ingrese el ID para la MODIFICACION", "Error! el dato ingresado no corresponde a lo pedido", 1000, 9999, 3, &id);
			if(Errores)
			{
				indice = eMicro_BuscarId(lista, longitud, &id);

				if(indice==-1) {
					printf("el ID %d no esta ingresado en el sistema\n",id);
				}
				else
				{
					eMicro_MostrarUno(&lista[indice],listaE,TamE,listaT,TamT,listaC,TamC);
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
		else
		{
			printf("DEBE DAR DE ALTA\n");
			rtn=-1;
		}

	}

	return rtn;
}

void eMicro_MostrarUno(eMicro* Micro, eEmpresa listaE[], int TamE, eTipo listaT[], int TamT, eChofer listaC[], int TamC)
{
	if(Micro!=NULL && listaE!=NULL && TamE>0 && listaT!=NULL && TamT>0 && listaC!=NULL && TamC>0)
	{
		char DescripTipo[20];
		char DescripEmpresa[20];
		char DescripChofer[20];

		eTipo_CargarDescripcion(listaT, TamT, Micro->idTipo, DescripTipo);
		eEmpresa_CargarDescripcion(listaE, TamE, Micro->idEmpresa, DescripEmpresa);
		eChofer_CargarDescripcion(listaC, TamC, Micro->idChofer, DescripChofer);

		printf("    %d   %-10s    %-10s     %d     %-10s\n",Micro->id,DescripTipo,DescripEmpresa,Micro->Capacidad,DescripChofer);
	}
}

int eMicro_MostrarTodos(eMicro lista[], int longitud, eEmpresa listaE[], int TamE, eTipo listaT[], int TamT, eChofer listaC[], int TamC)
{
	int rtn=0;
	int bandera=1;
	if(lista!=NULL && longitud>0 && listaE!=NULL && TamE>0 && listaT!=NULL && TamT>0 && listaC!=NULL && TamC>0)
	{
		system("cls");
		printf("                  *** Lista de Micros *** \n");
		printf("----------------------------------------------------------------\n");
		printf("    ID     TIPO         EMPRESA       CAPACIDAD      Chofer\n");
		printf("----------------------------------------------------------------\n");
		for(int i=0;i<longitud;i++)
		{
			if(lista[i].isEmpty==OCUPADO)
			{
				eMicro_MostrarUno(&lista[i],listaE,TamE,listaT,TamT,listaC,TamC);
				bandera=0;
			}
		}
		rtn=1;
		if(bandera)
		{
			printf("no hay Micros para mostrar\n");
			rtn=-1;
		}
	}
	return rtn;
}

int eMicro_CargarDatos(eMicro* Micro, eEmpresa listaE[], int TamE, eTipo listaT[], int TamT, eChofer listaC[], int TamC)
{
	int rtn=0;
	int Errores;
	int banderaError=0;

	if(Micro!=NULL && listaE!=NULL && TamE>0 && listaT!=NULL && TamT>0 && listaC!=NULL && TamC>0)
	{
		Errores=eTipo_IngresarId(listaT, TamT, &Micro->idTipo);
		if(Errores==1)
		{
			Errores=eEmpresa_IngresarId(listaE, TamE, &Micro->idEmpresa);

			if(Errores==1)
			{
				Errores=eChofer_IngresarId(listaC, TamC, &Micro->idChofer);

					if(Errores==1)
					{
						Errores=getInt("Ingrese la Capacidad:", "Error! debe ingresar un numero o no corresponde al rango de la Capacidad", 1, 50, 3, &Micro->Capacidad);

						if(Errores==1)
						{
							rtn=1;
						} else {
							banderaError=1;
						}
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

	if(lista!=NULL && indice>=0 && listaT!=NULL && TamT>0)
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

int eMicro_Ordenar(eMicro lista[],int longitud, eEmpresa ListaE[], int TamE)
{
	int rtn=0;
	eMicro Aux;
	char EmpresaI[20];
	char EmpresaJ[20];

		if(lista!=NULL && longitud>0 && ListaE!=NULL && TamE>0)
		{
			for(int i=0;i<longitud-1;i++)
			{
				eEmpresa_CargarDescripcion(ListaE, TamE, lista[i].idEmpresa, EmpresaI);
				for(int j=i+1;j<longitud;j++)
				{
					eEmpresa_CargarDescripcion(ListaE, TamE, lista[j].idEmpresa, EmpresaJ);
					if( strcmp(EmpresaI,EmpresaJ)>0 || ( strcmp(EmpresaI,EmpresaJ)==0 && lista[i].Capacidad > lista[j].Capacidad) )
					{
						Aux=lista[i];
						lista[i]=lista[j];
						strcpy(EmpresaI,EmpresaJ);
						lista[j]=Aux;
					}
				}
			}

			rtn=1;
			//printf("Ordenamiento Exitoso\n");
		}

	return rtn;
}


int eMicro_CargarDescripcion(eMicro lista[], int longitud, eTipo listaT[], int TamT, int idMicro, char* DescrMicroTipo)
{
	int rtn=0;
	char DescrpTipo[20];
	if(lista!=NULL && longitud>0 && listaT!=NULL && TamT>0 && DescrMicroTipo!=NULL)
	{
		rtn=-1;
		for(int i=0;i<longitud;i++)
		{
			if(lista[i].id==idMicro)
			{
				eTipo_CargarDescripcion(listaT, TamT, lista[i].idTipo, DescrpTipo);
				strcpy(DescrMicroTipo,DescrpTipo);
				rtn=1;
				break;
			}
		}
	}

	return rtn;
}

int eMicro_IngresarId(eMicro lista[], int longitud, eEmpresa listaE[], int TamE, eTipo listaT[], int TamT, eChofer listaC[], int TamC, int* ID)
{
	int rtn=-1;
	int reintentos = 3;
	int Auxid;
	int Errores;
	if(lista!=NULL && longitud>0 && listaE!=NULL && TamE>0 && listaT!=NULL && TamT>0 && listaC!=NULL && TamC>0)
	{
		eMicro_MostrarTodos(lista, longitud,listaE,TamE,listaT,TamT,listaC,TamC);
		do{
			Errores=getIntSinRango("Ingrese el id del Micro", "Error! debe ingresar el Id de la Tabla", 3, &Auxid);
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

/*=================================================================================================================================*/

int eMicro_MostrarEmpresas(eMicro lista[], int longitud, eEmpresa listaE[], int TamE, eTipo listaT[], int TamT, eChofer listaC[], int TamC)
{
	int rtn=0;
	int id;
	int bandera=1;
	int Erorres;

	if(lista!=NULL && longitud>0 && listaE!=NULL && TamE>0 && listaT!=NULL && TamT>0 && listaC!=NULL && TamC>0)
	{
		Erorres=eEmpresa_IngresarId(listaE, TamE, &id);

		if(Erorres==1)
		{
			system("cls");
			printf("                  *** Lista de Micros por Empresa *** \n");
			printf("----------------------------------------------------------------\n");
			printf("    ID    TIPO      EMPRESA      CAPACIDAD    Chofer\n");
			printf("----------------------------------------------------------------\n");
			for(int i=0;i<longitud;i++)
			{
				if(lista[i].isEmpty==OCUPADO)
				{
					if(lista[i].idEmpresa == id)
					{
						eMicro_MostrarUno(&lista[i],listaE,TamE,listaT,TamT,listaC,TamC);
						bandera=0;
					}

				}
			}
			rtn=1;
			if(bandera)
			{
				printf("no hay Micros para mostrar\n");
				rtn=-1;
			}
		} else {
			rtn=-1;
		}

	}
	return rtn;
}

int eMicro_MostrarTipos(eMicro lista[], int longitud, eEmpresa listaE[], int TamE, eTipo listaT[], int TamT, eChofer listaC[], int TamC)
{
	int rtn=0;
	int id;
	int bandera=1;
	int Erorres;

	if(lista!=NULL && longitud>0 && listaE!=NULL && TamE>0 && listaT!=NULL && TamT>0 && listaC!=NULL && TamC>0)
	{
		Erorres=eTipo_IngresarId(listaT, TamT, &id);

		if(Erorres==1)
		{
			system("cls");
			printf("                  *** Lista de Micros por Tipos *** \n");
			printf("----------------------------------------------------------------\n");
			printf("    ID    TIPO      EMPRESA      CAPACIDAD    Chofer\n");
			printf("----------------------------------------------------------------\n");
			for(int i=0;i<longitud;i++)
			{
				if(lista[i].isEmpty==OCUPADO)
				{
					if(lista[i].idTipo == id)
					{
						eMicro_MostrarUno(&lista[i],listaE,TamE,listaT,TamT,listaC,TamC);
						bandera=0;
					}

				}
			}
			rtn=1;
			if(bandera)
			{
				printf("no hay Micros para mostrar\n");
				rtn=-1;
			}
		} else {
			rtn=-1;
		}

	}
	return rtn;
}

int eMicro_EmpresaMenorCantMicros(eMicro lista[], int longitud, eEmpresa listaE[], int TamE)
{
	int rtn=0;
	int menor;
	int bandera=1;
	int indice;
	char DescrpEmpresa[20];

	typedef struct{
		int IdEmpresa;
		int Contador;
	}aContador;


	aContador ArrayContador[TamE];

	for(int a=0;a<TamE;a++)
	{
		InicializarArray(&ArrayContador[a].Contador, TamE);
	}
	if(lista!=NULL && longitud>0 && listaE!=NULL && TamE>0)
	{
		for(int i=0;i<TamE;i++)
		{
			ArrayContador[i].IdEmpresa=listaE[i].id;
			for(int j=0;j<longitud;j++)
			{
				if(lista[j].idEmpresa == ArrayContador[i].IdEmpresa)
				{
					ArrayContador[i].Contador++;
				}
			}
		}

		for(int k=0;k<TamE-1;k++)
		{
			if(bandera)
			{
				menor=ArrayContador[k].Contador;
				bandera=0;
			}
			else
			{
				if(menor>ArrayContador[k].Contador)
				{
					menor=ArrayContador[k].Contador;
					indice=k;
					rtn=1;
				}
			}
		}

		eEmpresa_CargarDescripcion(listaE, TamE, ArrayContador[indice].IdEmpresa, DescrpEmpresa);

		printf("La Empresa con menor cantidad de microes es: { %s }\n",DescrpEmpresa);

	}
	return rtn;
}


int eMicro_PorcentajeTipoVip(eMicro lista[], int longitud, eEmpresa listaE[], int TamE)
{
	int rtn=0;
	int acumuladorVIP=0;
	float porcentaje=0;
	int idEmpresa;
	int valor;

	typedef struct{
		int Id;
		int Acumulador;
	}aCantidades;

	aCantidades Array[TamE];

	for(int a=0;a<TamE;a++)
	{
		InicializarArray(&Array[a].Acumulador, TamE);
	}

	if(lista!=NULL && longitud>0 && listaE!=NULL && TamE>0)
	{
		for(int i=0;i<longitud;i++)
		{
			Array[i].Id=listaE[i].id;
			for(int j=0;j<longitud;j++)
			{
				if(lista[j].idEmpresa == Array[i].Id && lista[j].idTipo == IDVIP)
				{
					Array[i].Acumulador++;
				}
			}
		}

		for(int h=0;h<TamE;h++)
		{
			acumuladorVIP=+Array[h].Acumulador;
		}

		eEmpresa_IngresarId(listaE, TamE, &idEmpresa);


		for(int k=0;k<TamE;k++)
		{
			if(Array[k].Id == idEmpresa)
			{
				valor=Array[k].Acumulador;
				break;
			}
		}

		porcentaje=(float)valor*acumuladorVIP/100;

		printf("El porcetaje es: %.2f\n",porcentaje);

	}
	return rtn;
}

int eMicro_SeparadosEmpresas(eMicro lista[],int longitud, eEmpresa ListaE[], int TamE)
{
	int rtn=0;
	eMicro Aux;
	char EmpresaI[20];
	char EmpresaJ[20];

		if(lista!=NULL && longitud>0 && ListaE!=NULL && TamE>0)
		{
			for(int i=0;i<longitud-1;i++)
			{
				eEmpresa_CargarDescripcion(ListaE, TamE, lista[i].idEmpresa, EmpresaI);
				for(int j=i+1;j<longitud;j++)
				{
					eEmpresa_CargarDescripcion(ListaE, TamE, lista[j].idEmpresa, EmpresaJ);
					if( strcmp(EmpresaI,EmpresaJ)>0)
					{
						Aux=lista[i];
						lista[i]=lista[j];
						strcpy(EmpresaI,EmpresaJ);
						lista[j]=Aux;
					}
				}
			}

			rtn=1;
			//printf("Ordenamiento Exitoso\n");
		}

	return rtn;
}

