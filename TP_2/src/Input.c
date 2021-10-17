/*
 * Input.c
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


int eEmployeesVerifyConfirmation(char* mensaje)
{
	int retorno;
	char respuesta;

	retorno = 1;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%c", &respuesta);

	if(respuesta == 'S' || respuesta == 's')
	{
		retorno = 0;
	}

	return retorno;
}


int askString(char* string,char* message,char* errormessage,int max)
{
    int retorno=-1;
    char Auxiliar[200];
    if(string!=NULL && max>0)
    {
        printf("%s", message);
        fflush(stdin);
        scanf("%[^\n]",Auxiliar);

        while(strlen(Auxiliar)>max || askForAccompaniedNumber(Auxiliar)==-1 || validateString(Auxiliar)==0)
        {
            printf("%s",errormessage);
            fflush(stdin);
            scanf("%[^\n]",Auxiliar);
        }
        strcpy(string,Auxiliar);
        retorno=0;
    }
    return retorno;
}
int askForAccompaniedNumber(char* string)
{
	  int retorno=-1;
	    int i;
	    int tam;

	    if(string!=NULL)
	    {
	        tam=strlen(string);

	        for(i=0;i<tam;i++)
	        {
	            if(isdigit(string[i])==0 && string[i]!='.' && string[0]!='+' && string[0]!='-')
	            {
	                retorno=0;
	                break;
	            }

	        }

	    }
	    return retorno;
}
int validateString(char* string)
{
    int i;
    int tam;
    int retorno=-1;
    if(string!=NULL)
    {
        tam=strlen(string);
        transformUppercase(string);
        for(i=0;i<tam;i++)
        {

            if(string[i] < 97 || string[i] > 122)
            {
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}
int transformUppercase(char* string)
{
    int retorno=-1;
    int i;
    int tam;
    if(string!=NULL)
    {
        tam=strlen(string);
        for(i=0;i<tam;i++)
        {
            string[i]=tolower(string[i]);
        }

        retorno=0;
    }
    return retorno;
}
int askFloatNumber(float* num,char* message,char* errormessage,int min, int max)
{
	int retorno=-1;
	char numAux[51];
	float numFloatAux;


	if(num!=NULL && message!=NULL && errormessage!=NULL)
	{

		printf("%s",message);
		fflush(stdin);
		scanf("%[^\n]",numAux);
		numFloatAux=atoi(numAux);


		while((!askForAccompaniedNumber(numAux) && !validateSpaces(message)) || (numFloatAux>max||numFloatAux<min))
		{
			printf("%s",errormessage);
			fflush(stdin);
			scanf("%[^\n]",numAux);
			numFloatAux=atoi(numAux);
		}

		*num=atoi(numAux);

		retorno=0;
	}

	return retorno;
}
int askIntNumber(int* num,char* message,char* errormessage,int min, int max)
{
		int retorno=-1;
		char numAux[51];
		int numIntAux;


		if(num!=NULL && message!=NULL && errormessage!=NULL)
		{

			printf("%s",message);
			fflush(stdin);
			scanf("%[^\n]",numAux);
			numIntAux=atoi(numAux);


			while((!askForAccompaniedNumber(numAux) && !validateSpaces(message)) || (numIntAux>max||numIntAux<min))
			{
				printf("%s",errormessage);
				fflush(stdin);
				scanf("%[^\n]",numAux);
				numIntAux=atoi(numAux);
			}

			*num=atoi(numAux);

			retorno=0;
		}

		return retorno;
}
int validateSpaces(char* string)
{
	   	int retorno=-1;
	    int i;
	    int tam;
	    tam=strlen(string);
	    for(i=0;i<tam;i++)
	    {
	    	if(string[i] == ' ' || string[i] == '\t'  || string[i] == '\v')
	        {
	            retorno=0;
	            break;
	        }

	    }
	    return retorno;
}
