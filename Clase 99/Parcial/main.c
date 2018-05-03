#include <stdio.h>
#include <stdlib.h>
#include "Usuario.h"

int main()
{
   char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        printf("1- Ingresar Usuario\n");
        printf("2- Modificar Usuario\n");
        printf("3- Eliminar Usuario\n");
        printf("4- Publicar Producto\n");
        printf("5- Modificar Publicacion\n");
        printf("6- Cancelar Publicacion\n");
        printf("7- Comprar Producto\n");
        printf("8- Listar Publicaciones de Usuario\n");
        printf("9- Listar Publicaciones");
        printf("10- Listar Usuarios");
        printf("11- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");

                break;
            case 2:
                system("cls");

                break;
            case 3:
                system("cls");

                break;
            case 4:
                system("cls");

                break;
            case 5:
                system("cls");

                break;
            case 6:
                system("cls");

                break;
            case 7:
                system("cls");

                break;
            case 8:
                system("cls");

                break;
            case 9:
                system("cls");
                seguir = 'n';
                break;
        }

    }


        return 0;
}
