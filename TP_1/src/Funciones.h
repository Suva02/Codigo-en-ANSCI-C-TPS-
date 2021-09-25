/*
 * Funciones.h
 *
 *  Created on: 11 sep. 2021
 *      Author: Neri y Valen
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <values.h>
#include <ctype.h>
#include <string.h>

/// @fn float calcularSuma(float, float)
/// @brief Calcula la suma de 2 numeros.
///
/// @param numeroUno
/// @param numeroDos
///
/// @return El resultado
float calcularSuma(float numeroUno, float numeroDos);

/// @fn float calcularResta(float, float)
/// @brief Calcula la resta de 2 numeros.
///
/// @param numeroUno
/// @param numeroDos
///
/// @return El resultado
float calcularResta(float numeroUno, float numeroDos);

/// @fn float calcularDivision(float, float)
/// @brief Calcula la division de 2 numeros.
///
/// @param numeroUno
/// @param numeroDos
///
/// @return El resultado
float calcularDivision(float numeroUno, float numeroDos);

/// @fn float calcularMultiplicacion(float, float)
/// @brief Calcula la multiplicacion de 2 numeros.
///
/// @param numeroUno
/// @param numeroDos
///
/// @return El resultado
float calcularMultiplicacion(float numeroUno, float numeroDos);

/// @fn float calcularFactorial(float, float)
/// @brief Calcula el factorial de un numero.
///
/// @param numeroUno
///
/// @return El factorial del numero.
unsigned long long int calcularFactorial(int numero);

/// @fn int esEntero(float)
/// @brief Verifica si un numero es entero.
///
/// @param numero
/// @return Retorna 1 en caso de que sea entero y retorna 0 en caso de que no.
int esEntero(float numero);

/// @fn int esPositivo(float)
/// @brief Verifica si un numero es positivo.
///
/// @param numero
/// @return Retorna 1 en caso de que sea positivo y retorna 0 en caso de que no.
int esPositivo(float numero);

/// @fn int verificarFactorial(float)
/// @brief Verifica si un numero es positivo, entero, mayor a 1 y menor a 13 para poder mostrar el resultado del factorial.
///
/// @param numero
/// @return Retorna 1 en caso de que la condicion se cumpla y se pueda mostrar el factorial, retorna 0 en caso de que no.
int verificarFactorial(float numero);

/// @fn void mostrarResultados(float, float, float, float, unsigned long long int, unsigned long long int, float, float)
/// @brief Muestro todos los resultados de todas las operaciones y al mismo tiempo llamo a las funciones que se encargan de validar la operacion conrrespondiente, para
/// poder mostrarla.
///
/// @param resultadoSuma
/// @param resultadoResta
/// @param resultadoDivision
/// @param resultadoMultiplicacion
/// @param resultadoFactorial
/// @param resultadoFactorialDos
/// @param numeroUno
/// @param numeroDos
void mostrarResultados(float resultadoSuma, float resultadoResta, float resultadoDivision, float resultadoMultiplicacion, unsigned long long int resultadoFactorial, unsigned long long int resultadoFactorialDos,float numeroUno, float numeroDos);

/// @fn int validarDivision(float)
/// @brief Se encarga de validar la division por 0
///
/// @param numeroDos
/// @return Si el numero por el que se divide es distinto de 0, retorna 0, sino retorna 1
int validarDivision(float numeroDos);

/// @fn void mostrarMensaje(char*)
/// @brief Muestra un mensaje en el main.
///
/// @param mensaje
void mostrarMensaje(char* mensaje);

/// @fn int pedirOpcion(char*, char*, int, int)
/// @brief Imprimo un mensaje desde el main pidiendo que se ingrese una opcion, utilizando esta funcion. Al mismo tiempo, valido la opcion minima y maxima e imprimo un
/// mensaje de error por si acaso.
///
/// @param mensaje
/// @param mensajeError
/// @param minimo
/// @param maximo
/// @return
int pedirOpcion(char* mensaje, char* mensajeError, int minimo, int maximo);

/// @fn float pedirNumero(float)
/// @brief Carga un numero
///
/// @param numero
///
/// @return Retorna el numero que se ingresó
float pedirNumero(char* mensaje);



#endif /* FUNCIONES_H_ */
