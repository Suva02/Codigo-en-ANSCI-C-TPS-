/*
 * Input.h
 *
 *  Created on: 14 oct. 2021
 *      Author: Neri y Valen
 */

#ifndef INPUT_H_
#define INPUT_H_
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <limits.h>
#include <values.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"



/// @fn int eEmployeesVerifyConfirmation (char *)
/// @brief I ask the user if they want to verify / confirm something by entering the letter 'S'
/// @param The memory address of a message
/// @return returns 0 if the user accessed or returns 1 if they did not
int eEmployeesVerifyConfirmation(char* mensaje);

/// @fn int askString (char *, char *, char *, int)
/// @brief Function that is in charge purely and exclusively to request a string, without having signs, spaces, numbers, etc.
///
/// @param The memory address of a string
/// @param The memory address of a message
/// @param The memory address of an error message
/// @param A maximum
/// @return returns 0 if the auxiliary could be copied into the string, otherwise it returns -1
int askString(char* string,char* message,char* errormessage,int max);

/// @fn int askForAccompaniedNumber (char *)
/// @brief Function that is responsible for asking for numbers validating that they may have signs, operators, etc.
///
/// @param The memory address of a string
/// @return returns 0 if it went well, returns -1 if it couldn't
int askForAccompaniedNumber(char* string);

/// @fn int validateString (char *)
/// @brief Function that validates that there are only letters in a string
///
/// @param The memory address of a string
/// @return returns 0 if it went well, returns -1 if not
int validateString(char* string);

/// @fn int transformUppercase (char *)
/// @brief Function that is responsible for passing a string of characters to lowercase letters
///
/// @param The memory address of a string
/// @return returns 0 if it could transform, otherwise it returns -1
int transformUppercase(char* string);

/// @fn int askFloatNumber (float *, char *, char *, int, int)
/// @brief Function purely and exclusively to request a floating number
///
/// @param The address of the variable number
/// @param The memory address of a message
/// @param The memory address of an error message
/// @param A minimum
/// @param A maximum
/// @return returns 0 if it could ask for the number and perform its respective validations, it returns -1 if it could not.
int askFloatNumber(float* num,char* mensaje,char* mensajeError,int min, int max);

/// @fn int askIntNumber (int *, char *, char *, int, int)
/// @brief Function purely and exclusively to request a floating number
///
/// @param The address of the variable number
/// @param The memory address of a message
/// @param The memory address of an error message
/// @param A minimum
/// @param A maximum
/// @return returns 0 if it could ask for the number and perform its respective validations, it returns -1 if it could not.
int askIntNumber(int* num,char* message,char* errormessage,int min, int max);

/// @fn int validateSpaces (char *)
/// @brief Function that is responsible for validating spaces, tabs, etc.
///
/// @param A memory address of a string
/// @return returns 0 if it could do what is asked, returns -1 if it did not
int validateSpaces(char* string);


#endif /* INPUT_H_ */
