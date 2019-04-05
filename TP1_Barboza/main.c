#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int A;
    int B;
    while(seguir=='s')
    {
        printf("\n1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1: utn_getNumber(&A,"ingrese el primer operando \n","Error");
            printf("Su numero A es %d",A);
                break;
            case 2: utn_getNumber(&B,"ingrese el segundo operando \n","Error");
                    printf("Su numero A es %d \n",A);
                    printf("Su numero B es %d\n",B);
                break;
            case 3: utn_addNumber(A,B,"El resultado de la suma A+B es : \n");
                break;
            case 4: utn_subtractNumber(A,B,"El resultado de la resta A-B es de : \n");
                break;
            case 5: utn_divideNumber(A,B,"El resultado de la división A/B es de : ","Error, no se puede dividir por 0\n");
                break;
            case 6: utn_multiplynumber(A,B,"El resultado de la multiplicacion A*B es de : \n");
                break;
            case 7: utn_factorial(A);
                    utn_factorial(B);
                    printf("El factorial de A es : %d y el resultado de factorial B es : %d\n",utn_factorial(A),utn_factorial(B));
                break;
            case 8: utn_calculateAllFunctions(A,B);
                    printf("Su numero A es %d \n",A);
                    printf("Su numero B es %d\n",B);
                    printf("El factorial de A es : %d y el resultado de factorial B es : %d\n",utn_factorial(A),utn_factorial(B));
                break;
            case 9:
                seguir = 'n';
                break;
        }



}
    return 0;
}
