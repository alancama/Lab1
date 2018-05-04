#include <stdio.h>
#include <stdlib.h>
#include "EstructuraGenerica.h"
//#include "susFunciones.h"
#define CANTIDADUSUARIO 100
#define CANTIDADPRODUCTO 1000
/*
int main()
{
    eGenerica listadoGenerico[CANTIDAD];
    eGen_init(listadoGenerico,CANTIDAD);

    printf( "\n \t muestro el array... esta vacio");
    eGen_mostrarListado(listadoGenerico,CANTIDAD);
    getchar();

    printf( "\n \t muestro el array con los borrados y vacios");
    eGen_mostrarListadoConBorrados(listadoGenerico,CANTIDAD);
    getchar();

    eGen_alta(listadoGenerico,CANTIDAD);
    printf( "\n \t cargo dos elementos y muestro el array");
    eGen_mostrarListado(listadoGenerico,CANTIDAD);
    getchar();

    printf( "\n \t muestro el array con los borrados y vacios");
    eGen_mostrarListadoConBorrados(listadoGenerico,CANTIDAD);
    getchar();
*/
    int main()
{
    char seguir='s';
    int opcion=0;

    eUsuario listadoUsuario[CANTIDADUSUARIO];
    eUser_init(listadoUsuario, CANTIDADUSUARIO);
    eProducto listadoProducto[CANTIDADPRODUCTO];
    eProducto_init(listadoProducto, CANTIDADPRODUCTO);

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
        printf("9- Listar Publicaciones\n");
        printf("10- Listar Usuarios\n");
        printf("11- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                //system("cls");
                eUser_alta(listadoUsuario,CANTIDADUSUARIO);
                break;
            case 2:
                //system("cls");
                eUser_modificacion(listadoUsuario, CANTIDADUSUARIO);
                break;
            case 3:
                //system("cls");
                eUser_baja(listadoUsuario, CANTIDADUSUARIO);
                break;
            case 4:
                //system("cls");
                publicarProducto(listadoUsuario, CANTIDADUSUARIO, listadoProducto, CANTIDADPRODUCTO);
                break;
            case 5:
                //system("cls");
                eProd_modificacion(listadoUsuario, CANTIDADUSUARIO, listadoProducto, CANTIDADPRODUCTO);
                break;
            case 6:
                //system("cls");
                eProd_Baja(listadoUsuario,CANTIDADUSUARIO,listadoProducto,CANTIDADPRODUCTO);
                break;
            case 7:
                //system("cls");

                break;
            case 8:
                //system("cls");

                break;
            case 9:
                //system("cls");

                break;
            case 10:
               //system("cls");

                break;
            case 11:
                //system("cls");
                seguir = 'n';
                break;
        }

    }


        return 0;
}
