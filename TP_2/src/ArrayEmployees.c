/*
 * ArrayEmployees.c
 *
 *  Created on: 14 oct. 2021
 *      Author: Neri y Valen
 */
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

int initEmployees(Employee* list, int len)
{
	int i;
	int retorno;

	retorno = -1;

	if(list!=NULL && len>0)
	{
		for(i = 0; i<len; i++)
		{
			list[i].isEmpty = EMPTY;
			retorno = 0;
		}
	}

	return retorno;
}
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	int indice = (eEmployeeSearchFreeSpace(list,len));
	int retorno;
	Employee aux;

	retorno = -1;


	if(list!=NULL && len>0)
	{
		if(indice != -1)
		{
				printf("\n\nCargando empleado...\n\n");
				aux.id = id + 1;
				askString(aux.name,"\nIngrese el nombre del empleado:\n","\nReingrese el nombre del empleado:\n",51);
				askString(aux.lastName,"\nIngrese el apellido del empleado:\n","\nReingrese el apellido del empleado:\n",51);
				askFloatNumber(&aux.salary,"\nIngrese el salario del empleado (30000-200000):\n","\nError,Reingrese el salario del empleado (30000-200000):\n",30000,200000);
				askIntNumber(&aux.sector,"\nIngrese el sector del empleado (1-100):\n","\nError,Reingrese el sector del empleado (1-100):\n",1,100);

				printf("\nEmpleado cargado...\n\n %-5s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
				eEmployeesshowone(aux);


				if(eEmployeesVerifyConfirmation("\nSi desea agregar el siguente empleado ingrese: 's' ")== 0)
				{
					if(list[indice].isEmpty == EMPTY)
					list[indice] = aux;
					list[indice].isEmpty = BUSY;
					printf("\nEmpleado cargado...\n\n %-5s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
					eEmployeesshowone(list[indice]);
					retorno = 0;
				}
				else
				{
					printf("\nSe cancelo la carga...\n");
				}
		}
		else
		{
			printf("\n\nError, no hay espacio disponible...\n\n");
		}

	}


	return retorno;

}
int printEmployees(Employee* list, int length)
{

	int i;
	int retorno;

	retorno = -1;

	if(list!= NULL && length>0)
	{
		printf("\nMostrando la lista de empleados...\n\n %-5s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");

		for(i = 0; i<length; i++)
		{
			if(list[i].isEmpty == BUSY)
			{
				eEmployeesshowone(list[i]);
				retorno = 0;
			}
		}
	}

	return retorno;
}

void eEmployeesshowone(Employee list)
{
	{
		printf("%-5d %-20s %-20s %-20.2f %-20d\n", list.id, list.name, list.lastName, list.salary, list.sector);
	}
}
int eEmployeeSearchFreeSpace(Employee* list, int tam)
{
	int i;
	int indice;

	indice = -1;

	for(i = 0; i<tam;i++)
	{
		if(list[i].isEmpty == EMPTY)
		{
			indice = i;
			break;
		}
	}
	return indice;
}
int findEmployeeById(Employee* list, int len,int id)
{
	int i;
	int index;

	index = -1;

	if(list!= NULL && len>0)
	{
		for(i = 0; i<len;i++)
		{
			if(list[i].isEmpty == BUSY && list[i].id == id)
			{
				index = i;
				break;
			}
		}
	}

	return index;
}
int removeEmployee(Employee* list, int len, int id)
{
	int retorno = -1;
	int index;

	if(list!=NULL && len>0)
	{
		askIntNumber(&id,"\nIngrese el id del empleado (1000-2000):\n","\nError,Reingrese el id del empleado (1000-2000):\n",1000,2000);
		index = findEmployeeById(list,len,id);

			if(index!= -1)
			{
				printf("\nEmpleado a eliminar...\n\n %-5s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
				eEmployeesshowone(list[index]);

				if(eEmployeesVerifyConfirmation("\nSi desea dar de baja el empleado ingrese: 's' ")== 0)
				{
					list[index].isEmpty = EMPTY;
					printf("\nEl empleado se ha dado de baja exitosamente!\n");
					retorno = 0;
				}
				else
				{
					printf("\nSe cancelo la baja del empleado\n\n");
				}
			}
			else
			{
				printf("\nNo se ha encontrado el empleado...\n");
			}
		}

	return retorno;
}



int eEmployeeSubMenuModifyEmployee(Employee* list, int len)
{
	int retorno = -1;
	int index;
	int idIngresado;
	int opcion;
	Employee auxEmployee;

	if(list!=NULL && len>0)
	{
		askIntNumber(&idIngresado,"\nIngrese el id del empleado (1000-2000):\n","\nError,Reingrese el id del empleado (1000-2000):\n",1000,2000);
		index = findEmployeeById(list,len,idIngresado);

		if(index!= -1)
		{
			printf("\nEmpleado a modificar...\n\n %-5s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
			eEmployeesshowone(list[index]);

			do
				{
					auxEmployee = list[index];
					askIntNumber(&opcion,"\nIngrese alguna de las siguientes opciones:\n"
					"1.Modificar NOMBRE\n"
					"2.Modificar APELLIDO\n"
					"3.Modificar SALARIO\n"
					"4.Modificar SECTOR\n"
					"5.ATRAS\n",
					"\nOPCION INVALIDA, reingrese opcion:\n"
					"1.Modificar NOMBRE\n"
					"2.Modificar APELLIDO\n"
					"3.Modificar SALARIO\n"
					"4.Modificar SECTOR\n"
					"5.ATRAS\n",1,5);

				switch(opcion)
				{
					case 1:
						printf("\nEmpleado a modificar...\n\n %-5s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
						eEmployeesshowone(auxEmployee);
						askString(auxEmployee.name,"\nIngrese el nuevo nombre del empleado:\n","\nReingrese el nuevo nombre del empleado:\n",51);

						printf("\nEmpleado luego de la modificacion...\n\n %-5s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
						eEmployeesshowone(auxEmployee);

						if(eEmployeesVerifyConfirmation("Si desea modificar el empleado ingrese: 's' ")== 0)
						{
							list[index] = auxEmployee;
							printf("\nEmpleado modificado exitosamente!\n");
							retorno = 0;
						}
						else
						{
							printf("\n\nSe cancelo la modificacion del empleado\n\n");
						}
					break;
					case 2:
						printf("\nEmpleado a modificar...\n\n %-5s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
						eEmployeesshowone(auxEmployee);
						askString(auxEmployee.lastName,"\nIngrese el nuevo apellido del empleado:\n","\nReingrese el nuevo apellido del empleado:\n",51);


						printf("\nEmpleado luego de la modificacion...\n\n %-5s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
						eEmployeesshowone(auxEmployee);

						if(eEmployeesVerifyConfirmation("\nIngrese 's' para modificar el empleado\n\n")== 0)
						{
							list[index] = auxEmployee;
							printf("\nEmpleado modificado exitosamente!\n");
							retorno = 0;
						}
						else
						{
							printf("\n\nSe cancelo la modificacion del empleado\n\n");
						}
					break;
					case 3:
						printf("\nEmpleado a modificar...\n\n %-5s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
						eEmployeesshowone(auxEmployee);
						askFloatNumber(&auxEmployee.salary,"\nIngrese el nuevo salario del empleado (30000-200000):\n","\nError,Reingrese el nuevo salario del empleado (30000-200000):\n",30000,200000);


						printf("\nEmpleado luego de la modificacion...\n\n %-5s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
						eEmployeesshowone(auxEmployee);

						if(eEmployeesVerifyConfirmation("\nIngrese 's' para modificar el empleado\n\n")== 0)
						{
							list[index] = auxEmployee;
							printf("\nEmpleado modificado exitosamente!\n");
							retorno = 0;
						}
						else
						{
							printf("\n\nSe cancelo la modificacion del empleado\n\n");
						}
					break;
					case 4:
						printf("\nEmpleado a modificar...\n\n %-5s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
						eEmployeesshowone(auxEmployee);
						askIntNumber(&auxEmployee.sector,"\nIngrese el sector del empleado (1-100):\n","\nError,Reingrese el sector del empleado (1-100):\n",1,100);

						printf("\nEmpleado luego de la modificacion...\n\n %-5s %-20s %-20s %-20s %-20s\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
						eEmployeesshowone(auxEmployee);

						if(eEmployeesVerifyConfirmation("\nIngrese 's' para modificar el empleado\n\n")== 0)
						{
							list[index] = auxEmployee;
							printf("\nEmpleado modificado exitosamente!\n");
							retorno = 0;
						}
						else
						{
							printf("\n\nSe cancelo la modificacion del empleado\n\n");
						}
					break;
					case 5:
					break;
				}
				}while(opcion!=5);
			}
			else
			{
				printf("\n\nError, empleado no encontrado...\n\n");
			}

		}

	return retorno;

}
int sortEmployees(Employee* list, int len, int order)
{
	int i;
	int j;
	int retorno = -1;
	Employee aux;


	if(list!=NULL && len>0)
	{
		retorno = 0;

		do
			{
			askIntNumber(&order,"\nIngrese el orden que desea:\n\n"
									"0.Ascendente\n"
									"1.Descendente\n"
									"2.Atras\n",
									"\nOPCION INVALIDA, reingrese opcion:\n"
									"0.Ascendente\n"
									"1.Descendente\n"
									"2.Atras\n",0,2);

				switch(order)
				{
					case 0:
						for(i = 0; i<len-1; i++)
						{
							for(j = i + 1; j<len; j++)
							{
								if(strcmp(list[i].lastName,list[j].lastName) == 1)
								{
									aux = list[i];
									list[i] = list[j];
									list[j] = aux;
								}
								else
								{
									if(strcmp(list[i].lastName,list[j].lastName) == 0)
									{
										if(list[i].sector<list[j].sector)
										{
											aux = list[i];
											list[i] = list[j];
											list[j] = aux;
										}
									}
								}
							}
						}


					if(printEmployees(list, len) == -1)
					{
						printf("\nError al mostrar empleados, el puntero a lista es NULO o el tamaño es menor a 0\n");
					}

					break;
					case 1:
						for(i = 0; i<len-1; i++)
						{
							for(j = i + 1; j<len; j++)
							{
								if(strcmp(list[i].lastName,list[j].lastName) == -1)
								{
									aux = list[i];
									list[i] = list[j];
									list[j] = aux;
								}
								else
								{
									if(strcmp(list[i].lastName,list[j].lastName) == 0)
									{
										if(list[i].sector>list[j].sector)
										{
											aux = list[i];
											list[i] = list[j];
											list[j] = aux;
										}
									}
								}
							}
						}

						if(printEmployees(list, len) == -1)
						{
							printf("\nError al mostrar empleados, el puntero a lista es NULO o el tamaño es menor a 0\n");
						}
					break;
					case 2:
					break;
				}
			}while(order!= 2);
	}

	return retorno;

}
void EmployeesSubMenuInform(Employee* list, int len, int opcion, int order)
{
	float total;
	float acumulador;
	float contador;
	float promedio;
	int cantidadEmpleadosSup;

	total = 0;
	acumulador = 0;
	contador = 0;
	cantidadEmpleadosSup = 0;

	do{

		askIntNumber(&opcion,"\nIngrese alguna de las siguientes opciones:\n\n"
									"1.Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n"
									"2.Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\n"
									"3.Atras\n",
									"\nOPCION INVALIDA, reingrese opcion:\n"
									"1.Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n"
									"2.Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\n"
									"3.Atras\n",1,3);

		switch(opcion)
		{
			case 1:

				if(sortEmployees(list,len,order)== -1)
				{
					printf("\nError al ordenar empleados, puntero a lista es NULO o el tamaño es menor a 0\n");
				}
				if(printEmployees(list, len) == -1)
				{
					printf("\nError al mostrar empleados, el puntero a lista es NULO o el tamaño es menor a 0\n");
				}
			break;
			case 2:
				EmployeesReportSalaries(list,len, &total, &acumulador, &contador, &promedio, &cantidadEmpleadosSup);
			break;
			case 3:
			break;
		}

	}while(opcion!=3);

}
void EmployeesReportSalaries(Employee* list, int len, float* total, float* acumulador, float* contador, float* promedio, int* cantidadEmpleadosSup)
{
	int i;
	float totalSalario;
	float acumuladorSalario;
	float contadorSalario;
	float promedioSalario;
	int cantidad;

	totalSalario = 0;
	acumuladorSalario = 0;
	contadorSalario = 0;
	cantidad = 0;

	for(i = 0; i<len; i++)
	{
		if(list[i].isEmpty == BUSY)
		{
			acumuladorSalario = acumuladorSalario + list[i].salary;
			contadorSalario = contadorSalario + 1;
		}
	}

	totalSalario = totalSalario + acumuladorSalario;
	printf("\nEl total de los salarios es de $%.2f\n", totalSalario);

	if(contadorSalario!=0)
	{
		promedioSalario = (float)acumuladorSalario / contadorSalario;
		printf("\nEl promedio de los salarios es de: %.2f\n", promedioSalario);
	}

	for(i = 0; i<len;i++)
	{
		if(list[i].isEmpty == BUSY && list[i].salary>promedioSalario)
		{
			cantidad = cantidad + 1;
		}
	}

	printf("\nLa cantidad de empleados que superan el salario promedio es de: %d", cantidad);

	*total = totalSalario;
	*acumulador = acumuladorSalario;
	*contador = contadorSalario;
	*promedio = promedioSalario;
	*cantidadEmpleadosSup = cantidad;
}


