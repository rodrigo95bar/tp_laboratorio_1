#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
char bufferId[2000];
char bufferSueldo[2000];
char bufferHoras[2000];
char bufferNombre[2000];
int cantidadDatos=0;
int retorno = -1;
Employee *pEmployee;

    if(pFile !=NULL && pArrayListEmployee !=NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferNombre,bufferHoras,bufferSueldo);
    }

    do
    {
        cantidadDatos = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferNombre,bufferHoras,bufferSueldo);

        if(cantidadDatos==4)
        {
            pEmployee = employee_newParametros(bufferId,bufferNombre,bufferHoras,bufferSueldo);

            if(pEmployee!=NULL)
            {
                if(ll_add(pArrayListEmployee,pEmployee)==0)
                {
                    retorno = 0;
                }
            }
        }
    }
      while(!feof(pFile));

      return retorno;


}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
Employee *pEmployee;
int cantidadDatos;
int retorno = -1;

do{

pEmployee = employee_new();

    if(pEmployee!=NULL && pFile!=NULL && pArrayListEmployee!=NULL)
    {
        cantidadDatos = fread(pEmployee,sizeof(Employee),1,pFile);

        if(cantidadDatos==1)
        {
            if(ll_add(pArrayListEmployee,pEmployee)==0)
            {
                retorno = 0;
            }

        }
        else
        {
            employee_delete(pEmployee);
        }
    }

 }
   while(!feof(pFile));

   return retorno;
}
