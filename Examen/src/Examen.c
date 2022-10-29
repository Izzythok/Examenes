/*
 ============================================================================
 Name        : Examen.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "AlmacenDeDatos.h"
#include "Viajes.h"
int main(void) {
	setbuf(stdout,NULL);

	eMicro Lista[TAM];
	eEmpresa ListaE[Empresa_TAM];
	eTipo ListaT[TAM_Tipo];
	eChofer ListaC[TAM_Chofer];
	eDestino ListaD[TAM_Destino];
	eViaje ListaV[TAM_Viaje];
	int opciones;
	char seguir= 'n';
	char seguir1= 'n';


	if(!eMicro_Inicializar(Lista, TAM))
	{
		printf("Error al inicializar!\n");
	}
	eViaje_Inicializar(ListaV, TAM_Viaje);
	//eChofer_Inicializar(ListaC, TAM_Chofer);

	eMicro_Harcodear(Lista, TAM, 9);
	eDestino_Harcodear(ListaD,TAM_Destino,4);
	eEmpresa_Harcodear(ListaE, Empresa_TAM, 4);
	eTipo_Harcodear(ListaT, TAM_Tipo, 4);
	eChofer_Harcodear(ListaC, TAM_Chofer, 4);

	do
	{
		opciones=Menu();
		switch(opciones)
		{
		case 1:
			eMicro_Alta(Lista, TAM,ListaE,Empresa_TAM,ListaT,TAM_Tipo,ListaC,TAM_Chofer);
			break;
		case 2:
			eMicro_Baja(Lista, TAM,ListaE,Empresa_TAM,ListaT,TAM_Tipo,ListaC,TAM_Chofer);
			break;
		case 3:
			eMicro_Modificar(Lista, TAM,ListaE,Empresa_TAM,ListaT,TAM_Tipo,ListaC,TAM_Chofer);
			break;
		case 4:
			eMicro_Ordenar(Lista, TAM, ListaE, Empresa_TAM);
			eMicro_MostrarTodos(Lista, TAM,ListaE,Empresa_TAM,ListaT,TAM_Tipo,ListaC,TAM_Chofer);
			break;
		case 5:
			eEmpresa_MostrarTodos(ListaE, Empresa_TAM);
			break;
		case 6:
			eTipo_MostrarTodos(ListaT, TAM_Tipo);
			break;
		case 7:
			eDestino_MostrarTodos(ListaD, TAM_Destino);
			break;
		case 8:
			eViaje_Alta(ListaV, TAM_Viaje, Lista, TAM, ListaD, TAM_Destino, ListaT, TAM_Tipo, ListaE, Empresa_TAM,ListaC,TAM_Chofer);
			break;
		case 9:
			eViaje_MostrarTodos(ListaV, TAM_Viaje, Lista, TAM, ListaD, TAM_Destino, ListaT, TAM_Tipo);
			break;
		case 10:

			switch (SubMenuInformes()) {
				case 1:
					eMicro_MostrarEmpresas(Lista, TAM,ListaE,Empresa_TAM,ListaT,TAM_Tipo,ListaC,TAM_Chofer);
					break;
				case 2:
					eMicro_MostrarTipos(Lista, TAM,ListaE,Empresa_TAM,ListaT,TAM_Tipo,ListaC,TAM_Chofer);
					break;
				case 3:
					eMicro_PorcentajeTipoVip(Lista, TAM,ListaE,Empresa_TAM);
					break;
				case 4:
					eMicro_SeparadosEmpresas(Lista, TAM,ListaE,Empresa_TAM);
					eMicro_MostrarTodos(Lista, TAM,ListaE,Empresa_TAM,ListaT,TAM_Tipo,ListaC,TAM_Chofer);
					break;
				case 5:
					break;
				case 6:
					eMicro_EmpresaMenorCantMicros(Lista, TAM,ListaE,Empresa_TAM);
					break;
				case 7:
					Confirmar("Desea salir? {s} o {n}",&seguir1);
					break;
				default:
					break;
			}
			break;
		case 11:
			Confirmar("Desea salir? {s} o {n}",&seguir);
			break;
		}

		fflush(stdin);
		system("pause");
		getchar();

	}while(seguir=='n');


	return EXIT_SUCCESS;
}
