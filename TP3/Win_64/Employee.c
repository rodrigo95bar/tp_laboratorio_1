#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "utn.h"

Employee* employee_new()
{
    return (Employee*) malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo)
{
    Employee* Empleado = employee_new();

    if(Empleado!=NULL)
    {

     employee_setId(Empleado,idStr);
     employee_setNombre(Empleado,nombreStr);
     employee_setHorasTrabajadas(Empleado,horasTrabajadasStr);
     employee_setSueldo(Empleado,sueldo);
    }
    return Empleado;
    }


 int employee_delete(Employee* this)
 {
 int retorno = -1;

    if (this != NULL)
    {
        free(this);
        retorno = 0;
    }
   return retorno;
 }




int employee_setId(Employee* this,char* value)
{
    int auxID;
    int retorno = -1;

    if(this!=NULL && value!= NULL && isValidNumber(value))
    {
           auxID = atoi(value);

        if(auxID>=0)
        {
            this->id = auxID;
            retorno = 0;
        }
    }

    return retorno;
}

int employee_setNombre(Employee* this,char* value)
{
    int retorno = -1;

   if(this!=NULL && value!=NULL && isLetter(value))
   {
       if (strlen(value) > 0)
       {
           strncpy(this->nombre,value,sizeof(this->nombre));
           retorno = 0;
       }

   }
   return retorno;
}

int employee_setHorasTrabajadas(Employee* this,char* value)
{
   int retorno = -1;
   int auxHoras;

   if(this!=NULL&& value!=NULL && isValidNumber(value))
   {
       auxHoras= atoi(value);
       if(value>=0)
       {
           this->horasTrabajadas = auxHoras;
           retorno = 0;
       }
   }
   return retorno;
}

int employee_setSueldo(Employee* this,char* value)
{
    int auxSueldo;
    int retorno = -1;

    if(this!=NULL&& value!=NULL && isValidNumber(value))
   {
       auxSueldo= atoi(value);
       if(value>=0)
       {
           this->sueldo = auxSueldo;
           retorno = 0;
       }
   }
   return retorno;
}

int employee_getId(Employee* this,int* value)
{
    int retorno = -1;

    if(this!=NULL && value!=NULL)
    {
        *value = this->id;
        retorno = 0;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* value)
{
    int retorno = -1;

    if(this!=NULL && value!=NULL)
    {
        *value = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* value)
{
    int retorno = -1;

    if(this!=NULL && value!=NULL)
    {
        strncpy(value,this->nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int employee_getSueldo(Employee* this,int* value)
{
    int retorno = -1;

    if(this!=NULL && value!=NULL)
    {
        *value = this->sueldo;
        retorno = 0;
    }
    return retorno;
}


int employee_sort(void* pFirstEmployee,void* pSecondEmployee)
{
    int retorno;
    Employee* pEmployeeA;
    Employee* pEmployeeB;

    pEmployeeA = (Employee*) pFirstEmployee;
    pEmployeeB = (Employee*) pSecondEmployee;

    if(strcmp(pEmployeeA->nombre,pEmployeeB->nombre) > 0)
    {
        retorno = 1;///mayor el primero
    }
    else if(strcmp(pEmployeeA->nombre,pEmployeeB->nombre) < 0)
    {
        retorno = -1;///menor el primero
    }
    else
    {
        retorno = 0;///ambos iguales
    }
    return retorno;
}
