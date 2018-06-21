#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"

int compareEmployee(void* pEmployeeA,void* pEmployeeB)
{

    if((strcmp((Employee*)pEmployeeA)->email , ((Employee*)pEmployeeB)->email))
    {
        //lo elimino
    }

    return;


}

void printEmployee(Employee* p)
{
    printf("Nombre:%s Salario:%.2f\r\n",p->name,p->salary);
}

/** \brief Set this employee the values recived as parameters
 *
 * \param pEmployee employee*
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [NULL pointer] - (0) if Ok
 *
 */
Employee* newEmployee(char name[],char email[])
{
    Employee* returnAux = NULL;
    Employee* pEmployee = malloc(sizeof(Employee));

    if(pEmployee != NULL)
    {
        strcpy(pEmployee->name,name);
        strcpy(pEmployee->email,email);
        pEmployee->isEmpty = 1;

        returnAux = pEmployee;
    }

    return returnAux;

}
