#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"
#define CANTIDADUSUARIO 25
#define ALPHA_ROMEO 150
#define FERRARI 175
#define AUDI 200
#define OTROS 250

int main()
{
    char seguir='s';
    int opcion=0;

    eUsuario listadoUsuario[CANTIDADUSUARIO];
    eUser_init(listadoUsuario, CANTIDADUSUARIO);

    eUser_mostrarListado(listadoUsuario, CANTIDADUSUARIO);
    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Modificar persona\n");
        printf("3- Borrar persona\n");
        printf("4- Listado Usuarios\n");
        printf("5- Ingreso de Auto\n");
        printf("6- Salir\n");


        scanf("%d",&opcion);
        system("cls");

        switch(opcion)
        {
            case 1:
                system("cls");
                eUser_alta(listadoUsuario,CANTIDADUSUARIO);
                system("cls");
                break;
            case 2:
                system("cls");
                eUser_modificacion(listadoUsuario, CANTIDADUSUARIO);
                break;
            case 3:
                system("cls");
                eUser_baja(listadoUsuario, CANTIDADUSUARIO);
                break;
            case 4:
                system("cls");
                eUser_mostrarListado(listadoUsuario, CANTIDADUSUARIO);
                break;
            case 5:
                system("cls");

                break;
            case 6:
                system("cls");
                seguir = 'n';
                break;

        }
    }

    return 0;
}
