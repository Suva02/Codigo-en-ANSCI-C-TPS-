#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Input.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);

	int option = 0;
    int TextModeControl = 0;
    int BinaryModeControl = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();


    do{
    		pedirNumero(&option,"\nIngrese alguna de las siguientes opciones: "
    				"\n\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto) "
    				"\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario) "
    				"\n3. Alta de empleado "
    				"\n4. Modificar datos de empleado "
    				"\n5. Baja de empleado "
    				"\n6. Listar empleados "
    				"\n7. Ordenar empleados "
    				"\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto). "
    				"\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario). "
    				"\n10.Salir ","\nError,reingrese opcion: "
					"\n\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto) "
					"\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario) "
					"\n3. Alta de empleado "
					"\n4. Modificar datos de empleado "
					"\n5. Baja de empleado "
					"\n6. Listar empleados "
					"\n7. Ordenar empleados "
					"\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto). "
					"\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario). "
					"\n10.Salir ", 1, 10);

    		switch(option)
    		{
    			case 1:
    				if(TextModeControl == 0 && BinaryModeControl == 0)
    				{
    					controller_loadFromText("data.csv", listaEmpleados);
    					TextModeControl = 1;
					}
					else
					{
						if(TextModeControl == 1)
						{
							printf("\nLa lista ya fue cargada en modo texto!\n\n");
						}
						if(BinaryModeControl == 1)
						{
							printf("\nLa lista ya fue cargada en modo binario!\n\n");
						}
					}

    				 systemPause("Presione una tecla para continuar...\n\n");
    			break;
    			case 2:
    				 if(TextModeControl == 0 && BinaryModeControl == 0)
    				 {
						controller_loadFromBinary("data.bin", listaEmpleados);
						BinaryModeControl = 1;
    				 }
    				 else
    				 {
						if(BinaryModeControl == 1)
						{
							printf("\nLa lista ya fue cargada en modo binario!\n\n");
						}
						if(TextModeControl == 1)
						{
							printf("\nLa lista ya fue cargada en modo texto!\n\n");
						}
    				 }

    				 systemPause("Presione una tecla para continuar...\n\n");
    			break;
    			case 3:
    				if(TextModeControl || BinaryModeControl)
    				{
    					if(controller_addEmployee(listaEmpleados) == -1)
    					{
    						printf("\nError!Puntero nulo\n\n");
    					}

					}
					else
					{
						printf("\nError! No hay empleados en el sistema...\n\n");
					}

    				systemPause("Presione una tecla para continuar...\n\n");
    			break;
    			case 4:
    				if(TextModeControl == 1 || BinaryModeControl == 1)
    				{
						controller_editEmployee(listaEmpleados);
					}
					else
					{
						printf("\nError! No hay empleados en el sistema...\n\n");
					}

    				systemPause("Presione una tecla para continuar...\n\n");
    			break;
    			case 5:
					if(TextModeControl == 1 || BinaryModeControl == 1)
					{
						controller_removeEmployee(listaEmpleados);
					}
					else
					{
						printf("\nError! No hay empleados en el sistema...\n\n");
					}

					systemPause("Presione una tecla para continuar...\n\n");
				break;
				case 6:
					if(TextModeControl == 1 || BinaryModeControl == 1)
					{
						controller_ListEmployee(listaEmpleados);
					}
					else
					{
						printf("\nError! No hay empleados en el sistema...\n\n");
					}

					systemPause("Presione una tecla para continuar...\n\n");
				break;
				case 7:
					if(TextModeControl == 1 || BinaryModeControl == 1)
					{
						controller_sortEmployee(listaEmpleados);
					}
					else
					{
						printf("\nError! No hay empleados en el sistema...\n\n");
					}

					systemPause("Presione una tecla para continuar...\n\n");
				break;
				case 8:
					if(TextModeControl == 1 || BinaryModeControl == 1)
					{
						  controller_saveAsText("data.csv",listaEmpleados);
					}
					else{
						printf("\nError al guardar datos! No hay empleados en el sistema...\n\n");
					}

					systemPause("Presione una tecla para continuar...\n\n");
				break;
				case 9:
					if(TextModeControl == 1 || BinaryModeControl == 1)
					{
						  controller_saveAsBinary("data.bin",listaEmpleados);
					}
					else
					{
						printf("\nError al guardar datos! No hay empleados en el sistema...\n\n");
					}

					systemPause("Presione una tecla para continuar...\n\n");
				break;
    			case 10:
    				printf("\n-------------------------------------------------\n");
    				printf("\n   Usted ha decidido terminar con el programa.\n");
    				printf("\n-------------------------------------------------\n");
    			break;
    		}

    	}while(option!= 10);

    return 0;
}
