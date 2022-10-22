/*
 * IngresoDeDatos.c
 *
 *  Created on: 21 oct. 2022
 *      Author: Izzyto
 */


#include "IngresoDeDatos.h"



/// @fn Ingresa una cadena de caracteres y lo recorta hasta el ultimo caracter ingresado
/// @param cadena recibe el Array de cadena de carateres
/// @param longitud Recibe la longitud de la cadena
/// @return retorna 1 si salio todo ok si no 0.
static int IngresarString(char* cadena, int longitud);

/// @fn verifica si es una cadena de numeros
/// @param cadena Recibe la cadena de caracteres.
/// @return devuelve 1 si es un numero con coma, 2 si es un numero y 0 si salio algo mal
static int esNumerico(char* cadena);

/// @fn verifica si recibio un numero entero y lo transforma a Entero
/// @param pNumero Recibe la variable donde se guarda el entero.
/// @return 1 -> TodoOK / 0-> algo salio Mal
static int Get_Entero(int* pNumero);

/// @fn verifica si recibio un numero con coma y lo transforma a flotante
/// @param pNumero Recibe la variable donde se guarda el flotante.
/// @return 1 -> TodoOK / 0-> algo salio Mal
static int Get_Racional(float* pNumero);

int getFloat(char* mensaje, char* mensajeError, int minimo, int maximo,int reintentos, float *pValor)
{
	float AuxValor;
	int rtnGetNumero;
	int rtn=0;

	if(minimo<maximo && mensaje!=NULL && mensajeError!=NULL && reintentos>0)
	{
		printf("%s\n",mensaje);
		rtnGetNumero = Get_Racional(&AuxValor);
		do
		{
			if(!rtnGetNumero || minimo>AuxValor || maximo<AuxValor)
			{
				printf("%s\n",mensajeError);

				if(reintentos==1) {
					reintentos=0;
				} else {
					printf("%s\n",mensaje);
					rtnGetNumero = Get_Racional(&AuxValor);
					reintentos--;
					rtn=-1;
				}
			}
			else
			{
				*pValor = AuxValor;
				reintentos=0;
				rtn=1;
			}

		}while(reintentos>0);

	}
	return rtn;
}

int getInt(char* mensaje, char* mensajeError, int minimo, int maximo,int reintentos, int *pValor)
{
	int AuxValor;
	int rtnNumero;
	int rtn=0;

	if(minimo<maximo && mensaje!=NULL && mensajeError!=NULL && reintentos>0)
	{
		printf("%s\n",mensaje);
		rtnNumero = Get_Entero(&AuxValor);
		do
		{
			if(rtnNumero!=1 || minimo>AuxValor || maximo<AuxValor)
			{
				printf("%s\n",mensajeError);

				if(reintentos==1) {
					reintentos=0;
				} else {
					printf("%s\n",mensaje);
					rtnNumero = Get_Entero(&AuxValor);
					reintentos--;
					rtn=-1;
				}
			}
			else
			{
				*pValor = AuxValor;
				reintentos=0;
				rtn=1;
			}

		}while(reintentos>0);

	}
	return rtn;
}

int getIntSinRango(char* mensaje, char* mensajeError,int reintentos, int *pValor)
{
	int rtn=0;
	int AuxValor;
	int rtnGetNumero;
	if(mensaje!=NULL && mensajeError!=NULL && reintentos>0)
		{
			printf("%s\n",mensaje);
			rtnGetNumero = Get_Entero(&AuxValor);

			do
			{
				if(rtnGetNumero!=1)
				{
					printf("%s\n",mensajeError);
					if(reintentos==1){
						reintentos=0;
					} else {
						printf("%s\n",mensaje);
						rtnGetNumero = Get_Entero(&AuxValor);
						reintentos--;
						rtn=-1;
					}
				}
				else
				{
					*pValor = AuxValor;
					reintentos=0;
					rtn=1;
				}

			}while(reintentos>0);

		}
		return rtn;
}


char get_Sexo(char* mensaje, char* mensajeError, int reintentos,char* pValor)
{
	int rtn=0;
	char pAux;

	if(mensaje!=NULL && mensajeError!=NULL && pValor!=NULL && reintentos>0)
	{
		printf("%s\n",mensaje);

		fflush(stdin);
		pAux = getchar();
		do
		{

				if(pAux=='f' || pAux=='m' || pAux=='F' || pAux=='M')
				{
					pAux=tolower(pAux);
					*pValor=pAux;
					reintentos=0;
					rtn=1;
				}
				else
				{
					printf("%s\n",mensajeError);

					if(reintentos==1) {
						reintentos=0;
					} else {
						printf("%s\n",mensaje);
						fflush(stdin);
						pAux = getchar();
						reintentos--;
						rtn=-1;
					}
				}



		}while(reintentos>0);
	}

	return rtn;
}


int RangoNumerico(int minimo, int maximo, int* pValor)
{
	int rtn=0;

	if(pValor!=NULL && minimo<maximo)
	{
		if(*pValor<=maximo && *pValor>=minimo)
		{
			rtn=1;
		}
		else
		{
			rtn=-1;
		}
	}
	return rtn;
}

int Confirmar(char* mensaje,char* pControl)
{
	char confirmar;
	int rtn=0;

	if(pControl!=NULL && mensaje!=NULL)
	{
		printf("%s\n",mensaje);
		fflush(stdin);
		confirmar = getchar();
		if(confirmar == 's' || confirmar=='S')
		{
			*pControl = 's';
			rtn =1;
		}
	}

	return rtn;
}

int InicializarArray(int* pArray, int CantPosiciones)
{
	int rtn=0;

	if(pArray!=NULL && CantPosiciones>0)
	{
		for (int i = 0; i < CantPosiciones; i++) {
			pArray[i] = 0;
		}
		rtn=1;
	}
	return rtn;
}

int InicializarArrayFlotante(float* pArray, int CantPosiciones)
{
	int rtn=0;

	if(pArray!=NULL && CantPosiciones>0)
	{
		for (int i = 0; i < CantPosiciones; i++) {
			pArray[i] = 0;
		}
		rtn=1;
	}
	return rtn;
}

int VerifivarValorRepitidoArray(int* pArray,int CantPosiciones, int Valor, int index)
{
	int rtn=0;

	if(pArray!=NULL && CantPosiciones>0)
	{
		rtn=1;
		for(int i=0;i<CantPosiciones;i++)
		{
			if(index != i)
			{
				if (pArray[i] == Valor) {
					rtn = -1;
					printf("El el dato ingresado se encuentra repetido\n");
					break;

				} else if (pArray[i] == 0) {
					break;
				}
			}
		}
	}

	return rtn;
}

int ImprimirArray(int* pArray, int CantPosiciones)
{
	int rtn=0;



	if(pArray!=NULL && CantPosiciones>0)
	{
		rtn=1;
		for (int i = 0; i < CantPosiciones; i++) {
			printf("{%d} -", pArray[i]);
		}
	}
	return rtn;
}

int CopiarArrayDeEnteros(int* pArray, int* pArray2, int CantPosiciones)
{
	int rtn=0;

	if(pArray!=NULL && pArray2!=NULL && CantPosiciones>0)
	{
		rtn=1;
		for(int i=0; i<CantPosiciones;i++)
		{
			pArray[i]=pArray2[i];
		}
	}

	return rtn;
}

int OrdenarVector(int* pArray, int CantPosiciones, int criterio)
{
	int rtn=0;
	int aux;

	if(pArray!=NULL && CantPosiciones>0 && (criterio==1 || !criterio))
	{
		for(int i=0;i<CantPosiciones-1;i++)
		{
			for(int j=i+1;j<CantPosiciones;j++)
			{
				if((criterio && pArray[i]>pArray[j]) || (!criterio && pArray[i]<pArray[j]))
				{
					aux=pArray[i];
					pArray[i]=pArray[j];
					pArray[j]=aux;
				}
			}
		}

		rtn=1;
	}

	return rtn;
}

static int IngresarString(char* cadena, int longitud)
{
	int rtn=0;
	char auxiliar[Max_Buffer];

	fflush(stdin);
	if(cadena!=NULL && fgets(auxiliar,sizeof(auxiliar),stdin) == auxiliar && longitud>0)
	{
		auxiliar[strnlen(auxiliar,sizeof(auxiliar))-1]='\0';
		strncpy(cadena,auxiliar,longitud);
		rtn=1;
	}
	return rtn;
}

int GetString(char* mensaje,int reintentos,int longitud, char* String)
{
	int rtn=0;
	int errores;
	char Auxiliar[Max_Buffer];
	if(mensaje!=NULL && reintentos>0 && longitud>0 && String!=NULL)
	{
		printf("%s\n",mensaje);
		errores=IngresarString(Auxiliar,Max_Buffer);

		do{

			if (strnlen(Auxiliar, sizeof(Auxiliar)) >= longitud || strnlen(Auxiliar, sizeof(Auxiliar)) == 0)
			{
				printf("Error! Se excedio del limite de caracteres o no ingreso ninguno\n");

				if (reintentos == 1) {
					reintentos = 0;
				} else {
					printf("%s\n",mensaje);
					errores = IngresarString(Auxiliar, Max_Buffer);
					reintentos--;
					rtn = -1;
				}

			} else if (errores == 0) {
				printf("Error! Puntero no encontrado\n");
				reintentos = 0;
				rtn = -1;
			} else {
				strncpy(String, Auxiliar, longitud);
				reintentos = 0;
				rtn = 1;
			}


		}while(reintentos>0);
	}
	return rtn;
}

int GetStringSoloLetras(char* mensaje,int reintentos,int longitud, char* String)
{
	int rtn=0;
	int errores;
	int errores2;
	char Auxiliar[Max_Buffer];
	if(mensaje!=NULL && reintentos>0 && longitud>0 && String!=NULL)
	{
		printf("%s\n",mensaje);
		errores=IngresarString(Auxiliar,Max_Buffer);
		errores2=getSoloLetras(Auxiliar);

		if(errores==1 && errores2==1)
		{
					do{

						if (strnlen(Auxiliar, sizeof(Auxiliar)) >= longitud || strnlen(Auxiliar, sizeof(Auxiliar)) == 0)
						{
							printf("Error! Se excedio del limite de caracteres o no ingreso ninguno\n");

							if (reintentos == 1) {
								reintentos = 0;
							} else {
								printf("%s\n",mensaje);
								errores = IngresarString(Auxiliar, Max_Buffer);
								reintentos--;
								rtn = -1;
							}

						} else if (errores == 0) {
							printf("Error! Puntero no encontrado\n");
							reintentos = 0;
							rtn = -1;
						} else {
							strncpy(String, Auxiliar, longitud);
							reintentos = 0;
							rtn = 1;
						}


					}while(reintentos>0);
		} else {
			printf("Errores!\n");
			rtn = 1;
		}

	}
	return rtn;
}

int getSoloLetras(char* cadena)
{
	int rtn=0;
	int contador=0;
	if(cadena!=NULL)
	{
		for(int i=0;cadena[i]!='\0';i++)
		{
			if((cadena[i]>='A' && cadena[i]<='Z') || (cadena[i]>='a' && cadena[i]<='z'))
			{
				contador++;
			}
		}

		if(contador==strlen(cadena))
		{
			rtn=1;
		} else {
			rtn=-1;
		}
	}
	return rtn;
}

static int esNumerico(char* cadena)
{
	int rtn=0;
	int i;
	int contador=0;
	int banderaComa=0;

	if(cadena!=NULL)
	{
		if(cadena[0]=='-' && cadena[1]!='.' && cadena[strlen(cadena)-1]!='.')
		{
			contador=1;
			for(i=1;cadena[i]!='\0';i++)
			{
				if(cadena[i]<='9' && cadena[i]>='0')
				{
					contador++;
				}else if(cadena[i]=='.' && !banderaComa)
				{
					contador++;
					banderaComa=1;
				}
			}
		}
		else
		{
			if(cadena[0]!='.' && cadena[strlen(cadena)-1]!='.')
			{
				for(i=0;cadena[i]!='\0';i++)
				{
					if(cadena[i]<='9' && cadena[i]>='0')
					{
						contador++;
					}else if(cadena[i]=='.' && !banderaComa)
					{
						contador++;
						banderaComa=1;
					}
				}
			}

		}

		if(contador==strlen(cadena) && banderaComa) {
			rtn =1;
		} else if(contador==strlen(cadena) && !banderaComa) {
			rtn =2;
		}
	}
	return rtn;
}

static int Get_Entero(int* pNumero)
{
	int rtn=0;
	char auxiliar[Max_Buffer];

	if(pNumero!=NULL)
	{
		if (IngresarString(auxiliar, Max_Buffer)==1)
		{
			if(esNumerico(auxiliar)==2)
			{
				*pNumero= atoi(auxiliar);
				rtn=1;
			}
		}
	}
	return rtn;
}

static int Get_Racional(float* pNumero)
{
	int rtn=0;
	char auxiliar[Max_Buffer];

	if(pNumero!=NULL)
	{
		if (IngresarString(auxiliar, Max_Buffer)==1)
		{
			if(esNumerico(auxiliar)!=0)
			{
				*pNumero= atof(auxiliar);
				rtn=1;
			}
		}
	}
	return rtn;
}
