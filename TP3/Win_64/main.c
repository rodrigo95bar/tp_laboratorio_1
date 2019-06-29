#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"
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
    int option = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        utn_getUnsignedInt("\n 1)Cargar datos data.csv \n 2)Cargar datos data.csv BINARIO  \n 3)Agregar empleado \n 4)Modificar Empleado \n 5)Eliminar Empleado \n 6)Listar empleados \n 7)Ordenar Empleado \n 8)Guardar como texto \n 9)Guardar como texto binario \n 10)Salir",                   //cambiar
                    "\nError",1,sizeof(int),1,10,1,&option);
        switch(option)
        {
            case 1:
                if(controller_loadFromText("data.csv",listaEmpleados)!=0)
                {
                    printf("\n\t Error al cargar la lista\t\n");
                }
                else{
                    printf("\n\t Lista cargada con exito \t\n");
                }
                break;

            case 2:


                if(controller_loadFromBinary("data.csv",listaEmpleados)!=0)
                {
                    printf("\n\t Error al cargar la lista (Binario) \t\n");
                }
                else{
                    printf("\n\t Lista cargada con exito (Binario) \t\n");
                }
                break;

            case 3:

                if(controller_addEmployee(listaEmpleados)!=0)
                {
                    printf("\n\t Error al agregar empleado \t\n");
                }
                else
                {
                     printf("\n\t Empleado cargado con exito \t\n");
                }
                break;

            case 4:
                break;

            case 5:

                if(controller_removeEmployee(listaEmpleados)!=0)
                {
                     printf("\n\t No se pudo remover al empleado \t\n");
                }
                else{
                     printf("\n\t empleado removido con exito (Binario) \t\n");
                }
                break;

            case 6:
                if(controller_ListEmployee(listaEmpleados)!=0)
                {
                    printf("\n\t No se pudo listar \t\n");
                }
                else{
                    printf("\n\t Listado concretado \t\n");
                }
                break;
            case 7:
                if(controller_sortEmployee(listaEmpleados)!=0)
                {
                     printf("\n\t No se pudo ordenar \t\n");
                }
                else{
                     printf("\n\t ORDENADO! \t\n");
                }

            case 8:
                if(controller_saveAsText("data.csv",listaEmpleados)!=0)
                {
                   printf("\n\t No se pudo guardar \t\n");
                }
                else{
                    printf("\n\t GUARDADO! \t\n");
                }

            case 9:
                if(controller_saveAsBinary("data.csv",listaEmpleados)!=0)
                {
                   printf("\n\t No se pudo guardar \t\n");
                }
                else{
                    printf("\n\t GUARDADO! \t\n");
                }

            case 10:
                break;
        }

        }while(option != 10);

    ll_deleteLinkedList(listaEmpleados);
    return 0;
}
