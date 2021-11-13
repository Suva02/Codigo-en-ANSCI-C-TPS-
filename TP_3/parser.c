#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"



int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* this;
    int datosLeidos;
    char auxId[50];
    char auxNombre[50];
    char auxHorasTrabajadas[50];
    char auxSueldo[50];
    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
    while(!feof(pFile))
    {
        datosLeidos = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
        if(datosLeidos == 4)
        {
            this = employee_newParametros(auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
            ll_add(pArrayListEmployee, this);
        }
        else if(datosLeidos != 4 && this != NULL)
        {
            if(!feof(pFile))
            {
                printf("\nError al leer el ultimo dato.");
                break;
            }
            else
            {
                printf("\nSe leyo todo el archivo.");
            }
        }
    }
    printf("\nEmpleados cargados correctamente!\n\n");
    fclose(pFile);
    return 1;
}


int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* this;
    int datosLeidos;
    while(!feof(pFile))
    {
        this = employee_new();
        datosLeidos = fread(this, sizeof(Employee), 1, pFile);
        if(datosLeidos == 1 && this != NULL)
        {
            ll_add(pArrayListEmployee, this);
        }
        else if(datosLeidos != 1)
        {
            if(!feof(pFile))
            {
                printf("\nError al leer el ultimo dato.");
                break;
            }
            else
            {
                printf("\nEmpleados cargados correctamente!\n\n");
            }
        }
    }
    fclose(pFile);
    return 1;
}
