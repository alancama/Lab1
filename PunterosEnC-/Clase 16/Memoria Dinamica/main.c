#include <stdio.h>
#include <stdlib.h>
int cargarArray(int*,int);
void mostrarArray(int*,int);
int main()
{
    int vector[3];


    if(cargarArray(vector,3))
    {
        printf("Carga exitosa!!!!");
    }
    else
    {
        printf("Error al cargar los datos");
    }
    mostrarArray(vector,3);
    return 0;
}

int cargarArray(int* array,int tamp)
{
    int i;
    int retorno=0;
    if(array!=NULL)
    {
        retorno=1;
        for(i=0;i<tamp;i++)
        {
            printf("Ingrese un numero: ");
            scanf("%d",array+i);
        }
    }
    else
    {
        printf("Nulo");
    }
    return retorno;
}

void mostrarArray(int* array,int tamp)
{
    int i;
    for(i=0;i<tamp;i++)
    {
        printf("\n%d",*(array+i));
    }
}
