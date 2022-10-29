/*
 * IngresoDeDatos.h
 *
 *  Created on: 21 oct. 2022
 *      Author: Izzyto
 */

#ifndef INGRESODEDATOS_H_
#define INGRESODEDATOS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define Ascendente 1
#define Descendete 0
#define Max_Buffer 2048


/// @fn Pide un valor entero y lo devuelve por referencia
/// @param mensaje: texto de mensaje
/// @param mensajeError: texto de error
/// @param minimo: pide un valor minimo
/// @param maximo: pide un valor maximo
/// @param reintentos: numero de reintentos
/// @param pValor: Devuelve el valor por referencia
/// @return retorna 1 si salio todo bn si no -1 o 0
int getInt(char* mensaje, char* mensajeError, int minimo, int maximo,int reintentos, int *pValor);

/// @fn Pide un valor entero y lo devuelve por referencia - sin un rango numerico
/// @param mensaje: texto de mensaje
/// @param mensajeError: texto de error
/// @param reintentos: numero de reintentos
/// @param pValor: Devuelve el valor por referencia
/// @return retorna 1 si salio todo bn si no -1 o 0
int getIntSinRango(char* mensaje, char* mensajeError,int reintentos, int *pValor);

/// @fn Verifica si un valor esta entre un rango
/// @param minimo valor minimo
/// @param maximo Valor Maximo
/// @param pValor Toma el valor a verificar.
/// @return devuelve 1 esta todo OK o 0 si no estra entre el rango
int RangoNumerico(int minimo, int maximo, int* pValor);

/// @fn Pide un valor flotante y lo devuelve por referencia
/// @param mensaje: texto de mensaje
/// @param mensajeError: texto de error
/// @param minimo: pide un valor minimo
/// @param maximo: pide un valor maximo
/// @param reintentos: numero de reintentos
/// @param pValor: Devuelve el valor por referencia
/// @return retorna 1 si salio todo OK si no -1 o 0
int getFloat(char* mensaje, char* mensajeError, int minimo, int maximo,int reintentos, float *pValor);

/// @fn Verifica la confirmacion de una accion.
/// @param char: recibe el caracter de salida.
/// @param mensaje Recibe un mensaje.
/// @return retorna 1 si confirmo.
int Confirmar(char* mensaje,char* pControl);

/// @fn Inicializa todas la posiciones del vecto en 0.
/// @param pArray: recibe el vector.
/// @param CantPosiciones: recibe las posiciones.
/// @return devuelve 1 si salio todo OK si no 0.
int InicializarArray(int* pArray, int CantPosiciones);

/// @fn Inicializa todas la posiciones del vecto flotante en 0.
/// @param pArray: recibe el vector flotante.
/// @param CantPosiciones: recibe las posiciones.
/// @return devuelve 1 si salio todo OK si no 0.
int InicializarArrayFlotante(float* pArray, int CantPosiciones);



/// @fn la cadena de caracteres ingresada se testea que no deborde la longitud indicada
/// @param mensaje Recibe el Mensaje de aviso de lo que pide ingresar.
/// @param reintentos REcibe el numero de reintentos por Errores mal ingresado
/// @param longitud Recibe la longitud de la cadena
/// @param String Recibe el array de cadena.
/// @return Devuelve 1 si salio todo bien si no 0 o -1
int GetString(char* mensaje,int reintentos,int longitud, char* String);


/// @fn Toma un caracter f o m
/// @param mensaje recibe un mensaje
/// @param mensajeError recibe un mensaje de Error
/// @param reintentos Recibe el numero de reintentos de error
/// @param pValor Recibe el puntero donde se va guardar el caracter.
/// @return Devuelve 1 ->ok 0 o -1->Errores
char get_Sexo(char* mensaje, char* mensajeError, int reintentos,char* pValor);

int getSoloLetras(char* cadena);

int GetStringSoloLetras(char* mensaje,int reintentos,int longitud, char* String);

#endif /* INGRESODEDATOS_H_ */
