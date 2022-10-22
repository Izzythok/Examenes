/*
 ============================================================================
 Name        : Examen.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Micro.h"
#include "AlmacenDeDatos.h"
int main(void) {
	setbuf(stdout,NULL);

	eMicro Lista[TAM];
	eEmpresa ListaE[TAM_EMPRESA] = {{1000, "Plusmar"},{1001, "Flecha Bus"},{1002, "Tas"},{1003, "El Rapido"}};
	eTipo ListaT[TAM_Tipo] = {{5000, "Comun"},{5001, "CocheCama"},{5002, "Doble"},{5003, "Vip"}};
	eDestino ListaD[TAM_Destino];
	int opciones;
	char seguir= 'n';

	if(!eMicro_Inicializar(Lista, TAM))
	{
		printf("Error al inicializar!\n");
	}

	eMicro_Harcodear(Lista, TAM, 5);
	eDestino_Harcodear(ListaD,TAM_Destino,4);

	do
	{
		opciones=Menu();
		switch(opciones)
		{
		case 1:
			eMicro_Alta(Lista, TAM,ListaE,TAM_EMPRESA,ListaT,TAM_Tipo);
			break;
		case 2:
			eMicro_Baja(Lista, TAM,ListaE,TAM_EMPRESA,ListaT,TAM_Tipo);
			break;
		case 3:
			eMicro_Modificar(Lista, TAM,ListaE,TAM_EMPRESA,ListaT,TAM_Tipo);
			break;
		case 4:
			eMicro_MostrarTodos(Lista, TAM,ListaE,TAM_EMPRESA,ListaT,TAM_Tipo);
			break;
		case 5:
			eEmpresa_MostrarTodos(ListaE, TAM_EMPRESA);
			break;
		case 6:
			eTipo_MostrarTodos(ListaT, TAM_Tipo);
			break;
		case 7:
			eDestino_MostrarTodos(ListaD, TAM_Destino);
			break;
		case 8:
			Confirmar("Desea salir? {s} o {n}",&seguir);
			break;
		}

		fflush(stdin);
		system("pause");
		getchar();

	}while(seguir=='n');


	return EXIT_SUCCESS;
}
