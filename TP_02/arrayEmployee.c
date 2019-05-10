#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_arrays.h"
#include "arrayEmployee.h"
#include "validations.h"

static int generarId()
{
    static int idEmployee=0;

    return idEmployee++;

}
/** \brief Esta función inicializa el array poniendo
     como TRUE (1) el valor del flag "isEmpty" en todas
     las posiciones del array a usar.
 *
 * \param Employee* pEmployee Es el puntero al array Employee
 * \param len  Es el tamaño del array, en este caso Employee.
 * \return Retorna 0 si la función fue exitosa.
 *
 */

int employee_initializeArray(Employee* pEmployee, int len)
{
    int i;
    for(i=0; i<len;i++)
    {
        pEmployee[i].isEmpty = 1;

    }
    return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////


/** \brief Esta función crea al empleado, con sus respectivos nombre, apellido, salario y sector.
 *
 * \param Employee* pEmployee Es el puntero al array Employee
 * \param len  Es el tamaño del array, en este caso Employee.
 * \param pIndex  Es el puntero de la posición del array actual.
 * \param msgE    Es el mensaje de error cuando la función no cumple su verdadera función.
 * \return Retorna 0 si la función fue exitosa.
 *
 */

int employee_create(Employee* pEmployee,int len, int pIndex, char* msgE)
{
    char bufferName[51];
    char bufferSurname[51];
    float bufferSalary;
    int bufferSector;


    if((getStringLetras(bufferName,"Ingrese nombre: ",msgE,2) == 0) && (getStringLetras(bufferSurname,"Ingrese apellido: ",msgE,2) == 0) && (getFloat(&bufferSalary,"Ingrese su salario : ",msgE)==0) && (getInt(&bufferSector, "Ingrese su sector: ", msgE)==0) )
    {
        strncpy(pEmployee[pIndex].name,bufferName,51);
        strncpy(pEmployee[pIndex].surname,bufferSurname,51);
        pEmployee[pIndex].salary = bufferSalary;
        pEmployee[pIndex].sector = bufferSector;
        pEmployee[pIndex].isEmpty=0;
        pEmployee[pIndex].idEmployee = generarId();

    }
    else
    {
        printf(msgE);
    }
    return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Esta función muestra el array de todos los empleaedos dados de alta hasta el momento.
 *
 * \param Employee* pEmployee Es el puntero al array Employee
 * \param len  Es el tamaño del array, en este caso Employee.
 * \return Retorna 0 si la función fue exitosa.
 *
 */

int employee_showArray(Employee* pEmployee,int len)
{
    int i;
    int flag=0;
    for(i=0;i<len;i++)
    {
        if(pEmployee[i].isEmpty==0)
        {


            printf("Empleado %d:\n Nombre :%s\n Apellido :%s\n Salario: %.2f \n Sector : %d\n",i,pEmployee[i].name,
                                                                                               pEmployee[i].surname,
                                                                                               pEmployee[i].salary,
                                                                                               pEmployee[i].sector);
                                                                                               flag=0;
    }
    }
        if(flag)
        {
        printf("\n\tNo se encontraron valores\t\n");
        }
    return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Esta función busca espacios libres (isEmpty en 1) recorriendo el array.
 *
 * \param Employee* pEmployee Es el puntero al array Employee
 * \param len  Es el tamaño del array, en este caso Employee.
 * \return Retorna la posición del array si encontro este espacio. De lo contrario -1.
 *
 */

int employee_searchFreeSpace(Employee* pEmployee, int len)
{
    int i;
    int ret=-1;
    if(pEmployee !=NULL&&len >0)
    {
       for(i=0;i<len;i++)
        {
            if(pEmployee[i].isEmpty==1)
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
}
//////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Esta función busca al empleado a traves de su ID.
 *
 * \param Employee* pEmployee Es el puntero al array Employee
 * \param len  Es el tamaño del array, en este caso Employee.
 * \param idEmpleado Es el buffer del ID del empleado.
 * \return Retorna el ID del empleaedo, de lo contrario -1.
 *
 */

int employee_findPosById(Employee* pEmployee, int len,int idEmpleado)
{
    int i;
    int ret=-1;

    if(pEmployee != NULL && len > 0)
    {
      for(i=0;i<len;i++)
        {
            if(pEmployee[i].idEmployee == idEmpleado)
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
}
//////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Esta función permite modificar valores del Empleado, a traves de un menu (switch).
 *
 * \param Employee* pEmployee Es el puntero al array Employee
 * \param len  Es el tamaño del array, en este caso Employee.
 * \param msgE Mensaje de error en caso de que no se haya podido modiicar.
 * \param tries Cantidad de intentos permitidos antes de salir de la función.
 * \return Retorna 0 para poder salir del switch y por lo tanto, de la función.
 *
 */

int EmployeeModifyById(Employee* pEmployee,int len, char* msgE,int tries)
{
    char bufferName[51];
    char bufferSurname[51];
    int bufferSector;
    float bufferSalary;
    int idEmpleado;
    int posID;
    int ret = -1;
    int opcion=0;
    if(pEmployee != NULL && len > 0)
    {
        do
        {
            idEmpleado = employeeGetId (pEmployee, len, "Error", 3);
            if(idEmpleado >= 1)
            {
                posID = employee_findPosById(pEmployee, len, idEmpleado);
                if(posID != -1)
                {
                    pEmployee[posID].isEmpty = 1;
                    ret = 0;
                }
                else
                {
                    printf("\n\tID inexistente\t\n");
                }
            }
            getIntInRange(&opcion,
                     "\n\nQUE DESEA MODIFICAR?\n\n N1) Nombre Empleado \n N2) Apellido Empleado \n N3) Salario \n N4) Sector \n N5) Salir",
                      "Numero ingresado incorrecto",
                      1,5,2);

        switch(opcion)
        {
        case 1:
            {
             if(getStringLetras(bufferName,"\nIngrese el nuevo nombre: \n",msgE,2) == 0)
                {
                 strncpy(pEmployee[posID].name,bufferName,51);
                 printf("\nSu nombre ahora es: %s\n",bufferName);
                 ret =0;
                }
                break;
            }
        case 2:
            {
              if(getStringLetras(bufferSurname,"\nIngrese el nuevo apellido: \n",msgE,2) == 0)
              {
                 strncpy(pEmployee[posID].surname,bufferSurname,51);
                 ret=0;
              }
               break;
            }
        case 3:
            {
              if(getFloat(&bufferSalary,"\nIngrese el nuevo salario : \n",msgE)==0)
              {
                  pEmployee[posID].salary = bufferSalary;
                  ret=0;
              }
              break;
            }
        case 4:
            {
              if(getInt(&bufferSector, "\nIngrese su sector: \n", msgE)==0)
              {
                  pEmployee[posID].sector = bufferSector;
                  ret=0;
              }
              break;
            }
        case 5:
            {
                ret=0;
            }
        }

        }while(ret == -1);
    }
    return ret;
}


//////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Esta función obtiene un bufferID para servir a la función de baja.
 *
 * \param Employee* pEmployee Es el puntero al array Employee.
 * \param len  Es el tamaño del array, en este caso Employee.
 * \param msgE Mensaje de error en caso de que no se pueda obtener.
 * \param tries Intentos para lograr obtener el ID.
 * \return Retorna el ID.
 *
 */

int employeeGetId(Employee * pEmployee, int len, char* msgE, int tries)
{
    char bufferID[1000];
    int auxiliarID;
    int ret = -1;
    if(pEmployee != NULL && len > 0)
    {
        if(getStringNumerosInt(bufferID,"\nIngrese el ID: \n",msgE,tries)==0)
        {
            auxiliarID = atoi(bufferID);
            ret = auxiliarID;
        }
    }
    return ret;
}
//////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Esta función da de baja (Borra) a todo el empleaedo, dejando el isEmpty en 1.
 *
 * \param Employee* pEmployee Es el puntero al array Employee.
 * \param len  Es el tamaño del array, en este caso Employee.
 * \param msgE Mensaje de error en caso de que el id ingresado no corresponda con el tipo.
 * \param tries Intentos para obtener el ID que desea borrar el usuario.
 * \return
 *
 */

int EmployeeErase(Employee* pEmployee, int len,char* msgE,int tries)
{
    int auxiliarID;
    int posID;
    int ret = -1;

    if(pEmployee != NULL && len > 0)
    {
       auxiliarID = employeeGetId (pEmployee, len, "Error,intente de nuevo", 3);
       if(auxiliarID >= 1)
       {
            posID = employee_findPosById(pEmployee, len, auxiliarID);
            if(posID != -1)
            {
                pEmployee[posID].isEmpty = 1;
                ret = 0;
            }
            else
            {
                printf("\nEl ID no existe\n");
            }

        }
    }
    return ret;
}
//////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Esta función ordena a los empleados por el criterio de su Apellido.
 *
 * \param Employee* pEmployee Es el puntero al array Employee.
 * \param len  Es el tamaño del array, en este caso Employee.
 * \return Retorna 0 si fue exitosa.
 *
 */

int employeeSortBySurname(Employee* pEmployee,int len)
{
    int i;
    int j;
    Employee buffer;

    if(pEmployee!= NULL && len > 0)
    {
        for(i=0;i<len-1;i++)
        {
            if(pEmployee[i].isEmpty == 1)
            {
                continue;
            }
            for(j=i+1;j<len;j++)
            {
                if(pEmployee[j].isEmpty == 1)
                {
                    continue;
                }
                if(pEmployee[i].surname>pEmployee[j].surname)
                {
                    buffer = pEmployee[i];
                    pEmployee[i] = pEmployee[j];
                    pEmployee[j] = buffer;
                }
            }
        }
    }
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Esta función ordena a los empleaedos por el criterio de su Sector.
 *
 * \param Employee* pEmployee Es el puntero al array Employee.
 * \param len  Es el tamaño del array, en este caso Employee.
 * \return Retorna 0 si fue exitosa.
 *
 */

int employeeSortBySector(Employee* pEmployee,int len)
{
    int i;
    int j;
    Employee buffer;

    if(pEmployee!= NULL && len > 0)
    {
        for(i=0;i<len-1;i++)
        {
            if(pEmployee[i].isEmpty == 1)
            {
                continue;
            }
            for(j=i+1;j<len;j++)
            {
                if(pEmployee[j].isEmpty == 1)
                {
                    continue;
                }
                if(pEmployee[i].sector>pEmployee[j].sector)
                {
                    buffer = pEmployee[i];
                    pEmployee[i] = pEmployee[j];
                    pEmployee[j] = buffer;
                }
            }
        }
    }
    return 0;
}
