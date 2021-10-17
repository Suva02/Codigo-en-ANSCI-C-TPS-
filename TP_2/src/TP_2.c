/*
 ============================================================================
 Name        : TP_2.c
 Author      : Valentin
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <limits.h>
#include <values.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "Input.h"


int main(void)
{
	setbuf(stdout, NULL);
	int opcion;
	int lastId = 1000;
	int cantidadEmpleados = 0;
	char name[51] = {};
	char lastName[51] = {};
	float salary = 0;
	int sector = 0;
	int idIngresado;
	int order;


	idIngresado = 0;
	order = 0;



	Employee myemployee[LEN];
	if(initEmployees(myemployee, LEN) == -1)
	{
		printf("\nError al inicializar array, el puntero a lista es NULO o el tamaño es menor a 0\n");
	}

	do{

		askIntNumber(&opcion,"\nIngrese alguna de las siguientes opciones:\n"
						"1.ALTAS\n"
						"2.MODIFICAR\n"
						"3.BAJA\n"
						"4.INFORMAR\n"
						"5.SALIR\n",
						"\nOPCION INVALIDA, Reingrese opcion:\n"
						"1.ALTAS\n"
						"2.MODIFICAR\n"
						"3.BAJA\n"
						"4.INFORMAR\n"
						"5.SALIR\n",1,5);


				switch(opcion)
				{
					case 1:
						if(addEmployee(myemployee,LEN,lastId,name, lastName, salary, sector)==0)
						{
							cantidadEmpleados++;
							lastId++;
						}
						else
						{
							printf("\nError al agregar empleado, el puntero a lista es NULO o el tamaño es menor a 0\n");
						}
					break;
					case 2:
						if(cantidadEmpleados>0)
						{
							if(printEmployees(myemployee,LEN) == -1)
							{
								printf("\nError al mostrar empleados, el puntero a lista es NULO o el tamaño es menor a 0\n");
							}
							if(eEmployeeSubMenuModifyEmployee(myemployee, LEN) == -1)
							{
								printf("\nError al ingresar al menu de modificacion, el puntero a lista es NULO o el tamaño es menor a 0\n");
							}
						}
						else
						{
							printf("\nNo hay empleados en el sistema!\n");
						}
					break;
					case 3:
						if(cantidadEmpleados>0)
						{
							if(removeEmployee(myemployee,LEN, idIngresado)==0)
							{
								cantidadEmpleados--;
							}
							else
							{
								printf("\nError al eliminar empleado, el puntero a lista es NULO o el tamaño es menor a 0\n");
							}
						}
						else
						{
							printf("\nNo hay empleados en el sistema!\n");
						}
					break;
					case 4:
						if(cantidadEmpleados>0)
						{
							EmployeesSubMenuInform(myemployee, LEN, opcion, order);
						}
						else
						{
							printf("\nNo hay empleados en el sistema!\n\n");
						}
					break;
					case 5:
						printf("\nUsted ha seleccionado la opcion SALIR...\n\n");
					break;
				}

			}while(opcion!=5);

		return EXIT_SUCCESS;

}
