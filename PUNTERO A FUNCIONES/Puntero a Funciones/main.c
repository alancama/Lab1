#include <stdio.h>
#include <stdlib.h>
void funcionBienvenida(char* nombre);
void funcionDespedida(char* nombre);
void fdelegada(void(*punteroFuncion)(char* eldato),char* nombre);


int main()
{
    fdelegada(funcionBienvenida, "natalia natalia");
    getche();
    fdelegada(funcionDespedida,"natalia natalia");
    getche();
    return 0;
}

void funcionBienvenida(char* nombre)
{
    printf("Bienvenida %s , a la empresa.",nombre);
}
void funcionDespedida(char* nombre)
{
    printf("vos %s estas despedida -------->.",nombre);
}
void fdelegada(void(*punteroFuncion)(char* eldato),char* nombre)
{
    punteroFuncion(nombre);
}
