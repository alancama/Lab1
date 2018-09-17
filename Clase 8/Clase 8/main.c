#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include <string.h>

void mostrarEmpleado(eEmpleado employee);


int main()
{
    //struct eEmpleado empleadoUno;//Creo una variable de tipo estructura y la nombro.

    eEmpleado empleadoUno;//La variable ya es una estructura y creo empleadoUno.
    eEmpleado otroEmpleado;
    eEmpleado emp3 = {2222, "Jose", 'm', 20000};
    eEmpleado emp4;
    eEmpleado emp5;

    printf("Ingrese nombre:");
    fflush(stdin);
    gets(emp5.nombre);

    printf("\nIngrese legajo:");
    scanf("%d",&emp5.legajo);

    printf("\nIngrese salario:");
    scanf("%f",&emp5.salario);

    printf("\nIngrese sexo, f o m:");
    fflush(stdin);
    scanf("%c",&emp5.sexo);

    emp4=emp3;

    empleadoUno.legajo=1234;
    strcpy(empleadoUno.nombre, "Juan");
    empleadoUno.sexo='m';
    empleadoUno.salario=10000.50;

    otroEmpleado.legajo=1122;
    strcpy(otroEmpleado.nombre, "Lucia");
    otroEmpleado.sexo='f';
    otroEmpleado.salario=15000.75;

    mostrarEmpleado(empleadoUno);
    mostrarEmpleado(otroEmpleado);
    mostrarEmpleado(emp3);
    mostrarEmpleado(emp4);
    mostrarEmpleado(emp5);

    return 0;
}

void mostrarEmpleado(eEmpleado employee)
{
    printf("%d\t%s\t%c\t%.2f\n",employee.legajo,employee.nombre,employee.sexo,employee.salario);

}
