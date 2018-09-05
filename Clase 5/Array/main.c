#include <stdio.h>
#include <stdlib.h>
#define CANT 5
int main()
{
    int legajo[CANT],i,isEmpty[CANT],legajoAux,flag=0;
    float salario[CANT];

    for(i=0;i<CANT;i++)
    {
        isEmpty[i]=1;
    }

    for(i=0;i<CANT;i++)
    {
        if(isEmpty[i]==1)
        {
            printf("Legajo: ");
            scanf("%d",&legajo[i]);
            printf("Salario: ");
            scanf("%f",&salario[i]);
            isEmpty[i]=0;
        }
        else
        {
            break;
        }
    }

    printf("\nIngrese legajo a buscar: ");
    scanf("%d",&legajoAux);

    for(i=0;i<CANT;i++)
    {
        if(legajoAux==legajo[i])
        {
            printf("\nDato encontrado");
            flag=1;
            break;
        }
    }

    if(flag==0)
    {
        printf("\nDato no encontrado.");
    }
    return 0;
}
