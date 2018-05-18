#include <stdio.h>
#include <stdlib.h>

void intercambiar(int numUno, int numDos);
void intercambiarConPunteros(int *numUno, int *numDos);
void ponerEnCero(int *numUno);

int main()
{
    int edadUno;
    int edadDos;
    edadUno=22;
    edadDos=99;

    ponerEnCero(&edadDos);
    //intercambiar(edadUno,edadDos);
    intercambiarConPunteros(&edadUno,&edadDos);//Se puede pasar un puntero con *
    printf("\nEdad 1:%d",edadUno);
    printf("\nEdad 2:%d",edadDos);

    return 0;
}

void intercambiar(int numUno, int numDos)
{
    int aux;
    aux=numUno;
    numUno=numDos;
    numDos=aux;
}

void intercambiarConPunteros(int *numUno, int *numDos)//Deberia validar con if para que sea distinto de null
{
    int aux;
    aux=*numUno;
    *numUno=*numDos;
    *numDos=aux;
}

void ponerEnCero(int *numUno)
{
    *numUno=0;
}
