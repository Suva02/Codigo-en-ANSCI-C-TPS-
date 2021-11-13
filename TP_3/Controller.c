#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Input.h"



int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pArchivo;
    if((pArchivo = fopen(path, "r")) != NULL)
    {
        parser_EmployeeFromText(pArchivo, pArrayListEmployee);
    }
    else
    {
        if((pArchivo = fopen(path, "w")) != NULL)
        {
            printf("\nNo se encontro el archivo. Se creo uno nuevo con el nombre \"%s\"\n\n", path);
            retorno = 0;
        }
    }
    return retorno;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pArchivo;
    if((pArchivo = fopen(path, "rb")) != NULL)
    {
        parser_EmployeeFromBinary(pArchivo, pArrayListEmployee);
    }
    else
    {
        if((pArchivo = fopen(path, "wb")) != NULL)
        {
            printf("\nNo se encontro el archivo. Se creo uno nuevo con el nombre \"%s\"\n\n", path);
            retorno = 0;
        }
    }
    return retorno;
    return 1;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    char auxId[128];
    char auxNombre[128];
    char auxHorasTrabajadas[128];
    char auxSueldo[128];
    int auxHorasInt;
    float auxSueldoFloat;
    Employee* this = employee_new();
    Employee* auxEmployee;
    int retorno = -1;
    int ultimoId;

    if(pArrayListEmployee!= NULL)
    {

    	ultimoId= (ll_len(pArrayListEmployee) + 1);
    	ultimoId++;
		itoa(ultimoId,auxId,10);

		printf("\n\n-----------------"
				" ALTA DE EMPLEADO "
				"------------------");

		pedirNombreCompleto(auxNombre,"\n\nIngrese nombre: ","Error!reingrese nombre: ",128);
		fflush(stdin);
		pedirNumero(&auxHorasInt,"\nIngrese horas trabajadas: ","Error! reingrese horas trabajadas (1-3000): ",1, 3000);
		itoa(auxHorasInt,auxHorasTrabajadas,10); //Transformo un ENTERO a CADENA
		fflush(stdin);
		pedirNumeroFlotante(&auxSueldoFloat, "\nIngrese sueldo: ", "Error! reingrese sueldo (10000-100000): ", 10000, 100000);
		gcvt(auxSueldoFloat,6,auxSueldo); //Transformo una CADENA a FLOTANTE
		fflush(stdin);
		auxEmployee = employee_newParametros(auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
		printf("\nEmpleado cargado...\n\n %-5s %-20s %-20s %-20s\n", "ID", "Nombre", "Horas trabajadas", "Sueldo\n");
		employee_printData(auxEmployee);


		if(Employee_checkconfirmation("\nDesea cargar el empleado? S/N ") == 0)
		{
			this = employee_newParametros(auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
			ll_add(pArrayListEmployee, this);
			printf("\n\nEmpleado dado de alta...\n\n %-5s %-20s %-20s %-20s\n", "ID", "Nombre", "Horas trabajadas", "Sueldo\n");
			employee_printData(this);
			printf("\n\nEmpleado dado de alta con exito!\n\n");
		}
		else
		{
			printf("\n\nSe cancelo el alta del empleado!\n\n");
		}

		retorno = 0;
    }

    return retorno;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int flag = 0;
    int idEmpleado;
    int opcion;
    char auxNombre[51];
    int auxHorasTrabajadas;
    float auxSueldo;
    int id;
    char nombre[51];
    int horasTrabajadas;
    float sueldo;

    Employee* this;


	printf("\n\n-----------------"
				" MODIFICACION DE EMPLEADO "
				"------------------");

	systemPause("\n\nPresione una tecla para mostrar lista de empleados...\n\n");
	controller_ListEmployee(pArrayListEmployee);

    pedirNumero(&idEmpleado,"\n\nIngrese ID del empleado que desea modificar: ","\nError! reingrese ID del empleado: ",1, 5000);
    fflush(stdin);
    for(int i=0; i<ll_len(pArrayListEmployee); i++)
    {
        this = (Employee*)ll_get(pArrayListEmployee, i);
        if(this->id == idEmpleado)
        {
            flag = 1;
            break;
        }
    }
    if(flag == 1)
    {
        employee_getId(this, &id);
        employee_getNombre(this, nombre);
        employee_getHorasTrabajadas(this, &horasTrabajadas);
        employee_getSueldo(this, &sueldo);
		printf("\n%-5s %-20s %-20s %-20s\n", "ID", "Nombre", "Horas trabajadas", "Sueldo\n");
		employee_printData(this);
		pedirNumero(&opcion,"\nIngrese alguna de las siguientes opciones: "
		    				"\n\n1. Modificar nombre "
		    				"\n2. Modificar horas trabajadas "
		    				"\n3. Modificar sueldo "
		    				"\n4. Salir ",
							"\nError,reingrese opcion: "
							"\n\n1. Modificar nombre "
							"\n2. Modificar horas trabajadas "
							"\n3. Modificar sueldo "
							"\n4. Salir ", 1, 4);

        fflush(stdin);
        switch(opcion)
        {
        case 1:
            printf("\nUsted ha seleccionado modificar el nombre...\n\n");
        	pedirNombreCompleto(auxNombre,"\n\nIngrese el nuevo nombre: ","Error!reingrese nombre: ",128);
            printf("\nSe modificara \"%s\" por \"%s\"\n\n", auxNombre, nombre);
            fflush(stdin);


    		if(Employee_checkconfirmation("\nDesea modificar el nombre? S/N ") == 0)
    		{
    			employee_setNombre(this, auxNombre);
    			printf("\n\nModificacion del nombre exitosa!\n");
    			printf("\n\nEmpleado modificado...\n\n %-5s %-20s %-20s %-20s\n", "ID", "Nombre", "Horas trabajadas", "Sueldo\n");
    			employee_printData(this);
    			retorno = 1;
    		}
    		else
    		{
    			printf("\n\nSe cancelo la modificacion del nombre!\n\n");
    		}
            break;
        case 2:
        	printf("\nUsted ha seleccionado modificar las horas trabajadas..\n\n");
            pedirNumero(&auxHorasTrabajadas,"\nIngrese horas trabajadas: ","Error! reingrese horas trabajadas (1-3000): ",1, 3000);
            printf("\nSe modificara \"%d\" por \"%d\"\n\n", auxHorasTrabajadas, horasTrabajadas);
            fflush(stdin);

            if(Employee_checkconfirmation("\nDesea modificar las horas trabajadas? S/N ") == 0)
			{
            	employee_setHorasTrabajadas(this, auxHorasTrabajadas);
				printf("\n\nModificacion de las horas exitosa!\n");
				printf("\n\nEmpleado modificado...\n\n %-5s %-20s %-20s %-20s\n", "ID", "Nombre", "Horas trabajadas", "Sueldo\n");
				employee_printData(this);
				retorno = 1;
			}
			else
			{
				printf("\n\nSe cancelo la modificacion de las horas!\n\n");
			}
            break;
        case 3:
        	printf("\nUsted ha seleccionado modificar el sueldo..\n\n");
            pedirNumeroFlotante(&auxSueldo, "\nIngrese nuevo sueldo: ", "Error! reingrese sueldo (10000-100000): ", 10000, 100000);
            printf("\nSe modificara \"%.2f\" por \"%.2f\"\n\n", auxSueldo, sueldo);
            fflush(stdin);

            if(Employee_checkconfirmation("\nDesea modificar el sueldo? S/N ") == 0)
			{
            	employee_setSueldo(this, auxSueldo);
				printf("\n\nModificacion del sueldo exitosa!\n");
				printf("\n\nEmpleado modificado...\n\n %-5s %-20s %-20s %-20s\n", "ID", "Nombre", "Horas trabajadas", "Sueldo\n");
				employee_printData(this);
				retorno = 1;
			}
			else
			{
				printf("\n\nSe cancelo la modificacion del sueldo!\n\n");
			}
            break;
        case 4:
            break;

        }
    }
    else
    {
        printf("\nNo existe empleado con el ID ingresado.\n\n");
    }
    return retorno;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int flag = 0;
    int index;
    Employee* this;
    int idEmpleado;


	printf("\n\n-----------------"
				" BAJA DE EMPLEADO "
				"------------------");

	systemPause("\n\nPresione una tecla para mostrar lista de empleados...\n\n");
	controller_ListEmployee(pArrayListEmployee);

	pedirNumero(&idEmpleado,"\n\nIngrese ID del empleado que desea eliminar: ","\nError! reingrese ID del empleado: ",1, 5000);
    for(int i=0; i<ll_len(pArrayListEmployee); i++)
    {
        this = (Employee*) ll_get(pArrayListEmployee, i);
        if(this->id == idEmpleado)
        {
            flag = 1;
            index = i;
            break;
        }
    }
    if(flag == 1)
    {
    	printf("\n%-5s %-20s %-20s %-20s\n", "ID", "Nombre", "Horas trabajadas", "Sueldo\n");
    	employee_printData(this);

    	 if(Employee_checkconfirmation("\nDesea eliminar el empleado? S/N ") == 0)
		{
    		 ll_remove(pArrayListEmployee, index);
			 printf("\nEmpleado dado de baja con exito.\n\n");
			 retorno = 1;
		}
		else
		{
			printf("\n\nSe cancelo la baja del empleado!\n\n");
		}
    }
    else
    {
        printf("\nNo existe empleado con el ID ingresado.\n");
    }
    return retorno;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    Employee* this;

    printf("\n\nLista de empleados...\n\n %-5s %-20s %-20s %-20s\n", "ID", "Nombre", "Horas trabajadas", "Sueldo\n");

    for(int i=0; i<ll_len(pArrayListEmployee); i++)
    {
        this = (Employee*)ll_get(pArrayListEmployee, i);
        employee_printData(this);
        retorno = 1;
    }
    printf("\n");
    return retorno;
}

void controller_sortEmployee(LinkedList* pArrayListEmployee)
{

		int opcion;
		int ordenLista;

		printf("\n\n-----------------"
						" ORDENAMIENTO DE EMPLEADOS "
						"------------------");
		systemPause("\nPresione una tecla para acceder al menu de opciones...\n");

		pedirNumero(&opcion, "Ingrese alguna de las siguientes opciones de ordenamiento: "
				"\n\n1. Ordenar por ID "
				"\n2. Ordenar por nombre "
				"\n3. Ordenar por horas trabajadas "
				"\n4. Ordenar por salario "
				"\n5. Salir.\n\n", "Error! reingrese opcion: "
				"\n1. Ordenar por ID "
				"\n2. Ordenar por nombre "
				"\n3. Ordenar por horas trabajadas "
				"\n4. Ordenar por salario "
				"\n5. Salir\n\n", 1, 5);


		switch(opcion)
		{
			case 1:
				printf("\nOrdenamiento por ID...\n");
				pedirNumero(&ordenLista, "\n • Ingrese 0 para ordenar de forma ascendente \n • ingrese 1 para ordenar de forma descendente: ", "\nError! reingrese opcion: ", 0, 1);
				if(ordenLista == 0)
				{
					printf("\n\nEsto puede tardar unos segundos...\n");
				}
				ll_sort(pArrayListEmployee, employee_SortById, ordenLista);
				printf("\nSe ordeno la lista por ID correctamente!\n\n");

				break;
			case 2:
				 printf("\nOrdenamiento por nombre...\n");
				 pedirNumero(&ordenLista, "\n • Ingrese 0 para ordenar de forma ascendente \n • ingrese 1 para ordenar de forma descendente: ", "\nError! reingrese opcion: ", 0, 1);
				 if(ordenLista == 1 || ordenLista == 0)
				 {
					printf("\n\nEsto puede tardar unos segundos...\n");
				 }
				 ll_sort(pArrayListEmployee, employee_SortByName, ordenLista);
				 printf("\nSe ordeno la lista por nombre correctamente!\n\n");


				break;
			case 3:
				printf("\nOrdenamiento por horas trabajadas...\n");
				pedirNumero(&ordenLista, "\n • Ingrese 0 para ordenar de forma ascendente \n • ingrese 1 para ordenar de forma descendente: ", "\nError! reingrese opcion: ", 0, 1);
				if(ordenLista == 1 || ordenLista == 0)
				{
					printf("\n\nEsto puede tardar unos segundos...\n");
				}
				ll_sort(pArrayListEmployee, employee_SortByHoursWorked, ordenLista);
				printf("\nSe ordeno la lista por horas trabajadas correctamente!\n\n");

				break;
			case 4:
				printf("\nOrdenamiento por salario...\n");
				pedirNumero(&ordenLista, "\n • Ingrese 0 para ordenar de forma ascendente \n • ingrese 1 para ordenar de forma descendente: ", "\nError! reingrese opcion: ", 0, 1);
				if(ordenLista == 1 || ordenLista == 0)
				{
					printf("\n\nEsto puede tardar unos segundos...\n");
				}
				ll_sort(pArrayListEmployee, employee_SortBySalary, ordenLista);
				printf("\nSe ordeno la lista por salario correctamente!\n\n");

				break;
			case 5:
				break;

		}
}

int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    Employee* this;
    int retorno = -1;

    char nombre[51];
    int id;
    int horasTrabajadas;
    float sueldo;
    //<---
    pArchivo = fopen(path, "w");
    if(pArchivo != NULL && pArrayListEmployee != NULL)
    {
        rewind(pArchivo);
        fprintf(pArchivo, "id,nombre,horasTrabajadas,sueldo\n");
        for(int i=0; i<ll_len(pArrayListEmployee); i++)
        {
            this = (Employee*)ll_get(pArrayListEmployee, i);
            employee_getId(this,&id);
            employee_getNombre(this, nombre);
            employee_getHorasTrabajadas(this, &horasTrabajadas);
            employee_getSueldo(this, &sueldo);
            fprintf(pArchivo, "%d,%s,%d,%f\n", id, nombre, horasTrabajadas, sueldo);
        }
        printf("\nDatos guardados exitosamente!\n\n");
        retorno = 0;
    }
    fclose(pArchivo);
    return retorno;
}

int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    Employee* this;
    int retorno = -1;
    int datosLeidos;
    pArchivo = fopen(path, "wb");
    if(pArchivo != NULL && pArrayListEmployee != NULL)
    {
        rewind(pArchivo);
        for(int i=0; i<ll_len(pArrayListEmployee); i++){
            this = (Employee*)ll_get(pArrayListEmployee,i);
            datosLeidos = fwrite(this, sizeof(Employee), 1, pArchivo);
            retorno = 0;
            if(datosLeidos != 1){
                printf("\nError al escribir los datos en el archivo.\n");
            }
        }
        printf("\nDatos guardados exitosamente!\n\n");
    }
    else
    {
        printf("\nNo se pudo acceder al archivo.\n");
    }
    fclose(pArchivo);
    return retorno;
}

int controller_freeLinkedList(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(pArrayListEmployee != NULL)
    {
        for(int i=0; i<ll_len(pArrayListEmployee); i++)
        {
            ll_remove(pArrayListEmployee, i);
        }
        ll_deleteLinkedList(pArrayListEmployee);
        retorno = 0;
    }
    printf("\nSe elimino la lista de empleados...\n");
    return retorno;
}
