#include <stdio.h>
#include <stdlib.h>
#define TAM 5
int main()
{
    int* pVector;
    int* aux;
    int i;
    pVector=(int*) malloc(sizeof(int)*TAM);//Espacio para 5 enteros

    if(pVector!=NULL)
    {
        for(i=0;i<TAM;i++)
        {
            *(pVector+i)=i+1;//Ingreso enteros i+1(Empezando de 1 a 5)
        }
        for(i=0;i<TAM;i++)
        {
            printf("%d\n",*(pVector+i));//Los muestro
        }

        aux=(int*) realloc(pVector, sizeof(int)*10);//Agrego tamaño,reorganizo en memoria y luego muestro
        if(aux!=NULL)
        {
            pVector=aux;
            for(i=TAM;i<TAM*2;i++)
            {
                *(pVector+i)=i+1;
            }
            printf("Luego de realloc\n");
            for(i=0;i<TAM*2;i++)
            {
                printf("%d\n",*(pVector+i));//Los muestro
            }
            aux=(int*) realloc(pVector, sizeof(int)*4);
            if(aux!=NULL)
            {
                pVector=aux;
                //free(aux); Libera espacio en memoria de esa variable, al ser un puntero que apunta a lo mismo que otro puntero me libera los datos y muestra basura
                printf("Quitando con realloc\n");
                for(i=0;i<4;i++)
                {
                    printf("%d\n",*(pVector+i));//Los muestro
                }
            }
            //Finalizo liberando los vectores
        free(aux);
        free(pVector);
        }
        else
        {
            printf("Error de memoria\n");
        }


    }



    return 0;
}
