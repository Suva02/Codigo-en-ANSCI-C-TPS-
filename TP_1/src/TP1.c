/*
 ============================================================================

 1 Enunciado
Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:

1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)

3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)

4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”

5. Salir
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <limits.h>
#include "Funciones.h"
#include <values.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
	setbuf(stdout, NULL);


	float numeroIngresadoUno;
	float numeroIngresadoDos;
	int opcion;
	float resultadoSuma;
	float resultadoResta;
	float resultadoDivision;
	float resultadoMultiplicacion;
	unsigned long long int resultadoFactorial;
	unsigned long long int resultadoFactorialDos;
	char seguir;


	numeroIngresadoUno = 0;
	numeroIngresadoDos = 0;

	seguir = 's';


	do{

		opcion = pedirOpcion("\nIngrese alguna de las siguientes opciones:\n"
				"1.Ingresar 1er operando:\n"
				"2.Ingresar 2do operando:\n"
				"3.Calcular todas las operaciones\n"
				"4.Informar resultados\n"
				"5.Salir\n",
				"\nERROR. Reingrese opcion:\n"
				"\n1.Ingresar 1er operando:\n"
				"2.Ingresar 2do operando:\n"
				"3.Calcular todas las operaciones\n"
				"4.Informar resultados\n"
				"5.Salir\n", 1, 5);


		switch(opcion)
		{
			case 1:
				numeroIngresadoUno = pedirNumero("\nIngrese un numero (AVISO: Si desea calcular factorial, no ingrese numero MENOR A 1, DECIMAL O MAYOR A 20):\n");
				printf("\nA = %.1f\n", numeroIngresadoUno);
			break;
			case 2:
				numeroIngresadoDos =pedirNumero("\nIngrese un numero (AVISO: Si desea calcular factorial, no ingrese numero MENOR A 1, DECIMAL O MAYOR A 20):\n");
				printf("\nB = %.1f\n", numeroIngresadoDos);
			break;
			case 3:
				resultadoSuma = calcularSuma(numeroIngresadoUno, numeroIngresadoDos);
				resultadoResta = calcularResta(numeroIngresadoUno, numeroIngresadoDos);
				resultadoDivision = calcularDivision(numeroIngresadoUno, numeroIngresadoDos);
				resultadoMultiplicacion = calcularMultiplicacion(numeroIngresadoUno, numeroIngresadoDos);
				if(verificarFactorial(numeroIngresadoUno) == 1)
				{
					resultadoFactorial = calcularFactorial(numeroIngresadoUno);
				}
				if(verificarFactorial(numeroIngresadoDos) == 1)
				{
					resultadoFactorialDos = calcularFactorial(numeroIngresadoDos);
				}
			break;
			case 4:

				mostrarResultados(resultadoSuma, resultadoResta, resultadoDivision, resultadoMultiplicacion, resultadoFactorial, resultadoFactorialDos, numeroIngresadoUno,numeroIngresadoDos);

			break;
			case 5:
				mostrarMensaje("\nUsted ha seleccionado la opcion SALIR!");
				mostrarMensaje("\nDesea seguir ingresando numeros? s/n:\n");
				fflush(stdin);
				scanf("%c", &seguir);

				if(seguir == 'n')
				{
					mostrarMensaje("\nUsted ha decidido NO ingresar mas numeros.\n ¡GRACIAS!");
				}
			break;
		}
	}while(opcion!=5 || seguir!='n');


	return EXIT_SUCCESS;
}
