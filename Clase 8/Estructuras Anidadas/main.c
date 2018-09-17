#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;


typedef struct
{
    int legajo;
    char nombre[30];
    char sexo;
    float salario;
    eFecha fechaIngreso;
}eEmpleado;

void mostrarEmpleado(eEmpleado employee);

int main()
{
    eEmpleado unEmpleado;
    eFecha unaFecha;

    unEmpleado.legajo=1234;
    strcpy(unEmpleado.nombre, "Juan");
    unEmpleado.sexo='m';
    unEmpleado.salario=10000.50;
    unaFecha.anio=2018;
    unaFecha.dia=17;
    unaFecha.mes=9;
    unEmpleado.fechaIngreso=unaFecha;
    /*
    unEmpleado.fechaIngreso.dia = 17;
    unEmpleado.fechaIngreso.mes = 9;
    unEmpleado.fechaIngreso.anio = 2018;
    */
    mostrarEmpleado(unEmpleado);

    return 0;
}

void mostrarEmpleado(eEmpleado employee)
{
    printf("%d\t%s\t%c\t%.2f\t%02d/%02d/%4d\n",employee.legajo,employee.nombre,employee.sexo,employee.salario,employee.fechaIngreso.dia,employee.fechaIngreso.mes,employee.fechaIngreso.anio);

}
