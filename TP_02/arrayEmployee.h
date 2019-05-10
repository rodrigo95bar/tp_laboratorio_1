#ifndef ARRAYEMPLOYEE_H_INCLUDED
#define ARRAYEMPLOYEE_H_INCLUDED
typedef struct {
    int idEmployee;
    char name[51];
    char surname[51];
    float salary;
    int sector;
    int isEmpty;
                }Employee;


int employee_initializeArray(Employee* pEmployee, int len);
int employee_create(Employee* pEmployee,int len, int pIndex, char* msgE);
int employee_showArray(Employee* pEmployee,int len);
int employee_searchFreeSpace(Employee* pEmployee, int len);
int EmployeeModifyById(Employee* pEmployee,int len, char* msgE,int tries);
int employeeGetId(Employee * pEmployee, int len, char* msgE, int tries);
int employee_findPosById(Employee* pEmployee, int len,int idEmpleado);
int EmployeeErase(Employee* pEmployee, int len,char* msgE,int tries);


int employeeSortBySurname(Employee* pEmployee,int len);
int employeeSortBySector(Employee* pEmployee,int len);
#endif // ARRAYEMPLOYEE_H_INCLUDED
