#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

/*
Primer forma:

struct eEmpleado
{
    int legajo;
    char nombre[30];
    char sexo;
    float salario;
};

*/


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


#endif // STRUCT_H_INCLUDED
