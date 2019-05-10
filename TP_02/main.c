#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_arrays.h"
#define CANT_EMPLOYEE 1000
#include "arrayEmployee.h"

int main()
{
    Employee pEmployee [CANT_EMPLOYEE];
    int opcion=0;
    int posLibre;
    int flag=0;


    employee_initializeArray(pEmployee,CANT_EMPLOYEE);


   while(opcion!=5)
   {


    getIntInRange(&opcion,
                     "\n N1) Alta de Empleado \n N2) Modificar Empleado \n N3) Dar de baja Empleado \n N4) Ordenar y listar \n N5) Salir",
                      "Numero ingresado incorrecto",
                      1,5,2);



        switch(opcion)
        {
            case 1:
            {
                posLibre =  employee_searchFreeSpace(pEmployee,CANT_EMPLOYEE);
                if(posLibre>=0)
                {
                    printf("\n\n\tSe encontro lugar\t\n\n");
                    if(employee_create(pEmployee,CANT_EMPLOYEE, posLibre, "\nError,ingrese otra vez\n")==0)
                    {
                        printf("\n\nAlta dada con exito!\n\n");
                        employee_showArray(pEmployee,CANT_EMPLOYEE);
                        flag =1;
                        fflush(stdin);

                    }
                }
                else
                {
                    printf("\nNo hay lugar libre\n");
                }
                break;
            }
            case 2:
            {
                if(flag==1)
                {
                EmployeeModifyById(pEmployee, CANT_EMPLOYEE, "\nError, intente de nuevo\n",3);
                }
                break;
            }
            case 3:
                {
                printf("\nA que empleado desea eliminar? Ingrese id\n");
                EmployeeErase(pEmployee, CANT_EMPLOYEE,"Error",3);
                printf("\nEmpleado borrado con exito\n");
                employee_showArray(pEmployee,CANT_EMPLOYEE);
                break;
                }

            case 4:
                {
                    if(flag==1)
                {
                    employeeSortBySector(pEmployee, CANT_EMPLOYEE);
                    printf("\nOrdenado por Sector!\n");
                    employee_showArray(pEmployee,CANT_EMPLOYEE);


                }
                break;
                }
            case 5:
                {
                    break;
                }

        }
    }

    return 0;
}



