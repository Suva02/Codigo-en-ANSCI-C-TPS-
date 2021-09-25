/*
 * Funciones.c
 *
 *  Created on: 11 sep. 2021
 *      Author: Neri y Valen
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include "Funciones.h"
#include <values.h>
#include <ctype.h>
#include <string.h>




int pedirOpcion(char* mensaje, char* mensajeError, int minimo, int maximo)
{
	int opcion;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%d", &opcion);

	while(isalpha(opcion)!= 0 || opcion<minimo || opcion>maximo)
	{
		printf("%s", mensajeError);
		fflush(stdin);
		scanf("%d", &opcion);
	}
	return opcion;
}

int verificarFactorial(float numero)
{

	int retorno;

	retorno = 0;
	if(esPositivo(numero)== 1 && esEntero(numero) == 1 && numero>0 && numero<21)
	{
		retorno = 1;
	}

	return retorno;
}


int validarDivision(float numeroDos)
{
	int retorno;

	retorno = 1;

	if(numeroDos!=0)
	{
		retorno = 0;
	}

	return retorno;
}


void mostrarMensaje(char* mensaje)
{
	printf("%s", mensaje);
	fflush(stdin);
}


int esPositivo(float numero)
{
	int retorno;

	retorno = 0;
	if(numero > 0)
	{
		retorno = 1;
	}

	return retorno;
}


int esEntero(float numero)
{
	int retorno;

	retorno = 0;
	if((int)numero - numero == 0)
	{
		retorno = 1;
	}

	return retorno;
}


float pedirNumero(char* mensaje)
{
	float numero;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%f", &numero);

	return numero;
}

float calcularSuma(float numeroUno, float numeroDos)
{
	float resultado;


	resultado = numeroUno + numeroDos;

	return resultado;
}


float calcularResta(float numeroUno, float numeroDos)
{

	float resultado;

	resultado = numeroUno - numeroDos;

	return resultado;
}


float calcularDivision(float numeroUno, float numeroDos)
{
	float resultado;


	resultado = numeroUno / numeroDos;

	return resultado;
}


float calcularMultiplicacion(float numeroUno, float numeroDos)
{
	float resultado;


	resultado = numeroUno * numeroDos;

	return resultado;
}


unsigned long long int calcularFactorial(int numero)
{
	unsigned long long int factorial = 1;

	if (numero != 0)
	{
		factorial = numero * calcularFactorial(numero-1);
	}

	return factorial;
}


void mostrarResultados(float resultadoSuma, float resultadoResta, float resultadoDivision, float resultadoMultiplicacion, unsigned long long int resultadoFactorial, unsigned long long int resultadoFactorialDos,float numeroUno, float numeroDos)
{
	resultadoSuma = calcularSuma(numeroUno, numeroDos);
	printf("El resultado de %.1f + %.1f es: %.1f\n", numeroUno, numeroDos, resultadoSuma);
	resultadoResta = calcularResta(numeroUno, numeroDos);
	printf("El resultado de %.1f - %.1f es: %.1f\n", numeroUno, numeroDos, resultadoResta);
	if(validarDivision(numeroDos) == 0)
	{
		resultadoDivision = calcularDivision(numeroUno, numeroDos);
		printf("El resultado de %.1f / %.1f es: %.1f\n", numeroUno, numeroDos, resultadoDivision);
	}
	else
	{
		printf("No es posible dividir por 0\n");
	}
	resultadoMultiplicacion = calcularMultiplicacion(numeroUno, numeroDos);
	printf("El resultado de %.1f * %.1f es: %.1f\n", numeroUno, numeroDos, resultadoMultiplicacion);

	if(verificarFactorial(numeroUno) == 1 && verificarFactorial(numeroDos) == 1)
	{
		printf("El factorial de %.1f es: %I64u y el factorial de %.1f es: %I64u\n", numeroUno, resultadoFactorial,  numeroDos, resultadoFactorialDos);
	}
	else
	{
		if(verificarFactorial(numeroUno) == 1 && verificarFactorial(numeroDos) == 0)
		{
			printf("El factorial de %.1f es: %I64u  y el factorial de %.1f no se pudo calcular.\n", numeroUno, resultadoFactorial, numeroDos);
		}
		else
		{
			if(verificarFactorial(numeroUno) == 0 && verificarFactorial(numeroDos) == 1)
			{
				printf("El factorial de %.1f no se pudo calcular. Y El factorial de %.1f es: %I64u\n", numeroUno, numeroDos, resultadoFactorialDos);
			}
			else
			{
				if(verificarFactorial(numeroUno) == 0 && verificarFactorial(numeroDos) == 0)
				{
					printf("\nERROR AL CALCULAR FACTORIAL.\n");
				}
			}
		}
	}
}
