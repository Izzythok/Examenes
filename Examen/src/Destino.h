/*
 * Destino.h
 *
 *  Created on: 21 oct. 2022
 *      Author: Izzyto
 */

#ifndef DESTINO_H_
#define DESTINO_H_


#include "IngresoDeDatos.h"

#define TAM_Destino 4

typedef struct{
	int id;
	char Descripcion[25];
	float Precio;
}eDestino;

/*Solo esta en el .h por el harcodeo*/
int eDestino_ObtenerIdUnico();

int eDestino_CargarDescripcion(eDestino ListaL[], int TamL, int idDestino, char DescrDestino[]);
void eDestino_MostrarUno(eDestino* Destino);
int eDestino_MostrarTodos(eDestino lista[], int longitud);
int eDestino_IngresarId(eDestino lista[], int longitud, int* ID);
#endif /* DESTINO_H_ */
