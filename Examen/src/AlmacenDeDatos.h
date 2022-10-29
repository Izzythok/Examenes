/*
 * AlmacenDeDatos.h
 *
 *  Created on: 21 oct. 2022
 *      Author: Izzyto
 */

#ifndef ALMACENDEDATOS_H_
#define ALMACENDEDATOS_H_

#include "Micro.h"
#include "Destino.h"
#define MAX_DATOS 10

int eMicro_Harcodear(eMicro lista[], int longitud, int Cant);
int eDestino_Harcodear(eDestino lista[], int longitud, int Cant);
int eTipo_Harcodear(eTipo lista[], int longitud, int Cant);
int eEmpresa_Harcodear(eEmpresa lista[], int longitud, int Cant);
int eChofer_Harcodear(eChofer lista[], int longitud, int Cant);

#endif /* ALMACENDEDATOS_H_ */
