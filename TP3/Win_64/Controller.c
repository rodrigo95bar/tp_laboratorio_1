#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"
#define TRIES 3
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
 FILE* pFile;
 int retorno = -1;
 if(pArrayListEmployee!=NULL)
 {
     pFile = fopen(path,"r");

     if(pFile!=NULL)
     {
         parser_EmployeeFromText(pFile,pArrayListEmployee);
         fclose(pFile);
         retorno = 0;
     }
 }
  return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
 FILE* pFile;
 int retorno = -1;
 if(pArrayListEmployee!=NULL)
 {
   pFile = fopen(path,"rb");

     if(pFile!=NULL)
     {
         parser_EmployeeFromBinary(pFile,pArrayListEmployee);
         fclose(pFile);
         retorno = 0;
     }
 }
  return retorno;
}



/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
Employee* pEmployee;
    char bufferId[2000];
    char bufferNombre[2000];
    char bufferHoras[2000];
    char bufferSueldo[2000];
    int retorno = -1;

    if(pArrayListEmployee != NULL)
    {
        if((getStringNumerosInt(bufferId,"Ingrese ID: ","Error",TRIES)==0)
                &&(getStringLetras(bufferNombre,"Ingrese Nombre: ","Error",TRIES) == 0)
                &&(getStringNumerosInt(bufferHoras,"Ingrese Horas Trabajadas: ","Error",TRIES) == 0)
                &&(getStringNumerosInt(bufferSueldo,"Ingrese Sueldo: ","Error",TRIES) == 0))
        {
            pEmployee = employee_newParametros(bufferId,bufferNombre,bufferHoras,bufferSueldo);
            if(pEmployee != NULL)
            {
                if(ll_add(pArrayListEmployee,pEmployee) == 0)
                    {
                       retorno = 0;
                    }
            }
        }
    }
    return retorno;
}





/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
Employee *pEmployee;
int retorno = -1;
char bufferId[2000];
int size;
int auxId;
int i;
int id;


if(pArrayListEmployee!=NULL)
{
    size = ll_len(pArrayListEmployee);
    if (getStringNumerosInt(bufferId,"\nIngrese el ID que desea borrar \n","\nError \n",TRIES)==0)
    {
        auxId = atoi(bufferId);
        for (i=0;i<size;i++)
        {
            pEmployee= ll_get(pArrayListEmployee,i);
            employee_getId(pEmployee,&id);
            if (auxId == id)
            {

                ll_remove(pArrayListEmployee,i);
                employee_delete(pEmployee);
                retorno = 0;
            }

        }
    }

}
return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;
    int auxId;
    int auxSueldo;
    int auxHoras;
    char auxNombre[1500];
    int size;
    int i;

    if(pArrayListEmployee != NULL)
    {
        size = ll_len(pArrayListEmployee);
        for(i=0; i<size; i++)
        {
            pEmployee = ll_get(pArrayListEmployee,i);
            employee_getId(pEmployee,&auxId);
            employee_getNombre(pEmployee,auxNombre);
            employee_getSueldo(pEmployee,&auxSueldo);
            employee_getHorasTrabajadas(pEmployee,&auxHoras);
            if(pEmployee != NULL)
            {
                printf("%d,%s,%d,%d\n",auxId,
                       auxNombre,
                       auxSueldo,
                       auxHoras);
            }
        }
    }
    return 0;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;

     if(pArrayListEmployee!=NULL)
     {
         ll_sort(pArrayListEmployee,employee_sort,1);
         retorno = 0;
     }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int auxId;
    int auxSueldo;
    int auxHoras;
    char auxNombre[1500];
    int i;
    int size;
    Employee* pEmployee;
    int retorno = 1;

    FILE* fp = fopen(path,"a+");

    if(pArrayListEmployee!=NULL && fp!=NULL)
    {
        fprintf(fp, "id,nombre,horasTrabajadas,sueldo\n");
        size = ll_len(pArrayListEmployee);

        for(i=0;i<size;i++)
        {
            pEmployee = ll_get(pArrayListEmployee,i);
            employee_getId(pEmployee,&auxId);
            employee_getNombre(pEmployee,auxNombre);
            employee_getSueldo(pEmployee,&auxSueldo);
            employee_getHorasTrabajadas(pEmployee,&auxHoras);
            if(pEmployee!=NULL)
            {
                fprintf(fp,"%d,%s,%d,%d\n",auxId,auxNombre,auxSueldo,auxHoras);
                retorno = 0;
            }
            fclose(fp);
        }
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int i;
    int size;
    int retorno=1;
    Employee* pEmployee;

    FILE* fp = fopen(path,"wb+");

    if(fp!=NULL)
    {
        size = ll_len(pArrayListEmployee);

        for(i=0; i<size; i++)
        {
            pEmployee = ll_get(pArrayListEmployee,i);
            fwrite(pEmployee,sizeof(Employee),1,fp);
        }
        fclose(fp);
        retorno = 0;
    }
    return retorno;
}

