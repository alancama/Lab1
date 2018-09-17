#include <stdio.h>
#include <stdlib.h>
#define TAM 7
typedef struct
{
    int legajo;
    char nombre[30];
    char sexo;
    float salario;
}eEmpleado;

void mostrarEmpleado(eEmpleado employee);
void mostrarEmpleados(eEmpleado empleado[], int tamanio);
void ordenarEmpleados(eEmpleado lista[],int tam);

int main()
{
    //eEmpleado empleados[TAM];
    eEmpleado empleados[]=
    {
        {1234,"Juan",'m',12300},
        {2321,"Luisa",'f',14700},
        {2122,"Ariel",'m',11300},
        {4564,"Laura",'f',78945},
        {7894,"Hugo",'m',45646},
        {6464,"Maria",'f',12000},
        {7412,"Oscar",'m',16500}
    };
    /*int i;
    for(i=0;i<TAM;i++)
    {
        printf("\nIngrese nombre:");
        fflush(stdin);
        gets(empleados[i].nombre);

        printf("\nIngrese legajo:");
        scanf("%d",&empleados[i].legajo);

        printf("\nIngrese salario:");
        scanf("%f",&empleados[i].salario);

        printf("\nIngrese sexo, f o m:");
        fflush(stdin);
        scanf("%c",&empleados[i].sexo);
    }
    */
    mostrarEmpleados(empleados, TAM);
    ordenarEmpleados(empleados, TAM);
    printf("\n\n");
    mostrarEmpleados(empleados,TAM);

    return 0;
}

void mostrarEmpleado(eEmpleado employee)
{
    printf("Legajo:%d\tNombre:%s\tSexo:%c\tSueldo:%.2f\n",employee.legajo,employee.nombre,employee.sexo,employee.salario);

}

void mostrarEmpleados(eEmpleado empleados[], int tamanio)
{
    int i;
    for(i=0;i<tamanio;i++)
    {
       mostrarEmpleado(empleados[i]) ;
    }
}

void ordenarEmpleados(eEmpleado lista[],int tam)
{
    eEmpleado auxEmpleado;
    int i,j;
    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(lista[i].sexo > lista[j].sexo)
            {
                auxEmpleado = lista[i];
                lista[i]=lista[j];
                lista[j]=auxEmpleado;
            }else if(lista[i].sexo == lista[j].sexo && strcmp(lista[i].nombre,lista[j].nombre)>0)
            {
                auxEmpleado = lista[i];
                lista[i]=lista[j];
                lista[j]=auxEmpleado;
            }
        }
    }
}
