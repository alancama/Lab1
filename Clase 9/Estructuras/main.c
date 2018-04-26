#include <stdio.h>
#include <stdlib.h>
#include "Estructuras.h"
#include "Localidad.h"
#define tamanio 3

int main()
{
    eLocalidad Glew;
    eLocalidad listadoLocalidades;
    Glew.estado=1;
    Glew.id=555;
    strcpy(Glew.nombreLocalidad, "Maria");
    //printf("%s", Glew.nombreLocalidad);
    loc_MostrarUno(Glew);



    estructuraEjemplo miEstructura;
    printf("%s", miEstructura.nombre);
    return 0;
}
