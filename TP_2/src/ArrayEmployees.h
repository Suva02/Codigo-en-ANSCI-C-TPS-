/*
 * ArrayEmployees.h
 *
 *  Created on: 14 oct. 2021
 *      Author: Neri y Valen
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <limits.h>
#include <values.h>
#include <ctype.h>
#include <string.h>
#include "Input.h"
#define LEN 1000
#define BUSY 0
#define EMPTY 1

struct{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}typedef Employee;


/** \brief Loops through the array and initializes it empty
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int initEmployees(Employee* list, int len);
/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok */
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);

/** \brief print the content of employees array
 * \param list Employee*
 * \param length int
 * \return int (0 or -1)
 */
int printEmployees(Employee* list, int length);

/** \brief Show an employee
 * \param list Employee
 * \return int (0 or -1)
 */
void eEmployeesshowone(Employee list);

/** \brief It is responsible for looking for a free space in the index
 * \param list Employee
 * \return If the index is busy it returns -1, if it is free it returns the index
 */
int eEmployeeSearchFreeSpace(Employee* list, int tam);

/** \brief find an Employee by Id en returns the index position in array.
 * \param list Employee*
 * \param len int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 */
int findEmployeeById(Employee* list, int len,int id);

/** \brief Remove a Employee by Id (put isEmpty define in 1)
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 */
int removeEmployee(Employee* list, int len, int id);

/** \brief Allows to modify name, last name, salary or sector through the entry of the id
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 */
int eEmployeeSubMenuModifyEmployee(Employee* list, int len);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int sortEmployees(Employee* list, int len, int order);

/** \brief This function contains a menu that has options for the user to choose from.
 * Therefore, it shows the list of employees sorted alphabetically by last name and Sector or the total and average salaries,
 *  and how many employees exceed the average salary; which are the options that the menu has.
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \param opcion
 */
void EmployeesSubMenuInform(Employee* list, int len, int opcion, int order);

/** \brief Function that is responsible for calculating and displaying the total and average salaries, and how many employees exceed the average salary.
 * \param list Employee*
 * \param len int
 * \param total*
 * \param acumulador*
 * \param contador*
 * \param promedio*
 * \param cantidadEmpleadosSup*
 */
void EmployeesReportSalaries(Employee* list, int len, float* total, float* acumulador, float* contador, float* promedio, int* cantidadEmpleadosSup);











#endif /* ARRAYEMPLOYEES_H_ */
