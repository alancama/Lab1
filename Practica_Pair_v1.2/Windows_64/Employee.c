#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"


int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
    Employee* e1;
    Employee* e2;
    int retorno=-5;
    //Casteo de void a tipo struct
    e1=(Employee*)pEmployeeA;
    e2=(Employee*)pEmployeeB;

    return (stricmp(e1->name, e2->name));
}


void employee_print(Employee* this)
{
    printf("ID: %d\n",this->id);
    printf("Nombre: %s\n",this->name);
    printf("Apellido: %s\n",this->lastName);
}


Employee* employee_new(void)
{

    Employee* returnAux = NULL;

    returnAux=(Employee*)malloc(sizeof(Employee));


    return returnAux;

}

void employee_delete(Employee* this)
{


}

int employee_setId(Employee* this, int id)
{

    return 0;

}

int employee_getId(Employee* this)
{

    return 0;

}


