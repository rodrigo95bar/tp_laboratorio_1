#include <stdio.h>

/** \brief              Le pide un numero entero al usuario
 * \param  pNumero      El puntero del numero pedido
 * \param  msj          Indica al usuario que ingrese un numero
 * \param msjError      Indica al usuario que ocurrio un error
 * \return              0 esta bien,-1 esta mal.
 *
 */

 int utn_getNumber(int* pNumber, char* message, char* msgError)
 {
int ret = -1;
int number;
    do
{
     printf(message);
    if(scanf("%d",&number)==1)
    {
    *pNumber = number;
     ret = 0;
     }
    else
     {
     printf(msgError);
     }
    fflush(stdin);
}
  while(ret == 1);
return ret;
}
 /** \brief Suma los dos numeros ingresados por el usuario
  * \param  El primero numero ingresado por el usuario
  * \param  El segundo numero ingresado por el usuario
  * \param  Mensaje que muestra el resultado de la suma
  * \return Devuelve 0 si la funcion salio bien
  */
int utn_addNumber (int numberA, int numberB, char* msgResult)
 {
int add;
    add = numberA + numberB;
    printf("%s%.2f",msgResult,(float)add);
 return 0;
}
/** \brief Resta los dos numeros ingresados por el usuario
 * \param  El primero numero ingresado por el usuario
 * \param  El segundo numero ingresado por el usuario
 * \param  Mensaje que muestra el resultado de la resta
 * \return 0 si la función salio bien
 *
 */
int utn_subtractNumber (int numberA, int numberB, char* msgResult)
{
int subtract;
    subtract= numberA - numberB;
    printf("%s%.2f",msgResult,(float)subtract);
 return 0;
}
/** \brief Multiplica los dos numeros ingresados por el usuario
 * \param  El primero numero ingresado por el usuario
 * \param  El segundo numero ingresado por el usuario
 * \param  Mensaje que muestra el resultado de la multiplicacion
 * \return 0 si la función salio bien
 */
int utn_multiplynumber (int numberA, int numberB, char* msgResult)
{
int multiply;
    multiply= numberA * numberB;
    printf("%s%.2f",msgResult,(float)multiply);
 return 0;
}
/** \brief Divide los dos numeros ingresados por el usuario
 * \param  El primero numero ingresado por el usuario
 * \param  El segundo numero ingresado por el usuario
 * \param  Mensaje que muestra el resultado de la division
 * \return 0 si la función salio bien
 */
int utn_divideNumber (int numberA, int numberB, char* msgResult, char* msgError)
{
    int divide;
    if (numberA != 0 && numberB != 0)
    {
    divide= numberA / numberB;
    printf("%s%.2f",msgResult,(float)divide);
    }
    else if (numberB ==0){
    printf(msgError);
    }
    else if (numberA ==0){
        divide = 0;
        printf("%s%.2f",msgResult,(float)divide);
    }
 return 0;
}
/** \brief Obtiene el factorial de un numero ingresado
 * \param  Numero ingresado por el usuario
 * \return 0 si la función salio bien
 */
int utn_factorial(int number)
{
  int i;
  int result = 1;
        for (i=1;i <= number;i++)
        result = result * i;
        return result;
}
/** \brief Función que llama a todas las funciones para los numeros ingresados
 * \param  Primer numero ingresado por el usuario
 * \param  Segundo numero ingresado por el usuario
 * \return 0 si la función salio bien
 */
int utn_calculateAllFunctions(int numberA, int numberB)
{
   utn_addNumber(numberA,numberB,"El resultado de la suma A+B es de: ");
   utn_subtractNumber(numberA,numberB,"El resultado de la resta de A-B es de: ");
   utn_divideNumber(numberA,numberB,"El resultado de la división de A/B es de: ","Error, no se puede dividir por 0");
   utn_multiplynumber(numberA,numberB,"El resultado de la multiplicación de A*B es de: ");
   utn_factorial(numberA);
   utn_factorial(numberB);
   return 0;
}







