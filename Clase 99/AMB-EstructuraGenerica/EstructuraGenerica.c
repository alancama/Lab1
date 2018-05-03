#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EstructuraGenerica.h"
#define TAMANIO 10
#define OCUPADO 0
#define LIBRE 1



int eUser_init( eUsuario listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estado= LIBRE;
            listado[i].idUsuario= 0;
        }
    }
    return retorno;
}

int eUser_buscarLugarLibre(eUsuario listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eUser_siguienteId(eUsuario listado[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO)
            {
                    if(listado[i].idUsuario>retorno)
                    {
                         retorno=listado[i].idUsuario;
                    }

            }
        }
    }

    return retorno+1;
}


int eUser_buscarPorId(eUsuario listado[] ,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == OCUPADO && listado[i].idUsuario == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}



int eUser_mostrarUno(eUsuario parametro)
{
     printf("\n %s - %d - %d",parametro.nombre,parametro.idUsuario,parametro.estado);

}

int eUser_mostrarListado(eUsuario listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado==OCUPADO)
            {

                eUser_mostrarUno(listado[i]);
            }
        }
    }
    return retorno;
}


int eUser_mostrarListadoConBorrados(eUsuario listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado==LIBRE)
            {
                printf("\n[LIBRE]");
            }
            eUser_mostrarUno(listado[i]);
        }
    }
    return retorno;
}




int eUser_alta(eUsuario  listado[],int limite)
{
    int retorno = -1;
    char nombre[50];
    int id;
    int indice;

    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        indice = eUser_buscarLugarLibre(listado,limite);
        if(indice >= 0)
        {
            retorno = -3;
            id = eUser_siguienteId(listado,limite);

            //if(!getValidString("Nombre?","Error","Overflow", nombre,50,2))
            //{
                retorno = 0;
                strcpy(listado[indice].nombre,"Juan");
                listado[indice].idUsuario = id;
                listado[indice].estado = OCUPADO;
            //}
        }
    }
    return retorno;
}
int eUser_modificacion(eUsuario listadoUsuario[] ,int CANTIDADUSUARIO)
{
    eUser_mostrarListado(listadoUsuario, CANTIDADUSUARIO);

    int id,indiceUsuario;


    printf("\nIngrese ID a modificar: ");
    scanf("%d",&id);

    indiceUsuario=eUser_buscarPorId(listadoUsuario, CANTIDADUSUARIO, id);

    if(indiceUsuario>=0)
    {
        eUser_mostrarUno(listadoUsuario[indiceUsuario]);

        printf("\nIngrese nombre:");
        fflush(stdin);
        gets(listadoUsuario[indiceUsuario].nombre);
    }
}

int eUser_baja(eUsuario listadoUsuario[],int CANTIDADUSUARIO)
{
    int id,indiceUsuario;
    eUser_mostrarListado(listadoUsuario, CANTIDADUSUARIO);

    printf("\nIngrese ID de usuario a eliminar: ");
    scanf("%d",&id);

    indiceUsuario=eUser_buscarPorId(listadoUsuario, CANTIDADUSUARIO, id);

    if(indiceUsuario>=0)
    {
        eUser_mostrarUno(listadoUsuario[indiceUsuario]);

        strcpy(listadoUsuario[indiceUsuario].nombre, "");
        listadoUsuario[indiceUsuario].estado=0;
        listadoUsuario[indiceUsuario].idUsuario=0;

        printf("\n");
        eUser_mostrarUno(listadoUsuario[indiceUsuario]);
        printf("\n");
    }
}

int publicarProducto(eUsuario listadoUsuario[],int CANTIDADUSUARIO,eProducto productos[],int CANTIDADPRODUCTO)
{
    int id,indiceUsuario,stock,precio;
    eUser_mostrarListado(listadoUsuario, CANTIDADUSUARIO);

    printf("\nIngrese ID de usuario a publicar");

     scanf("%d",&id);

    indiceUsuario=eUser_buscarPorId(listadoUsuario, CANTIDADUSUARIO, id);

    if(indiceUsuario>=0)
    {
        printf("\nIngrese nombre: ");
        fflush(stdin);
        gets(productos[indiceUsuario].nombreProducto);

        printf("\nIngrese precio del producto: ");
        scanf("%d",&productos[indiceUsuario].precio);

        printf("\nIngrese stock: ")
        scanf("%d",&productos[indiceUsuario].precio);//Copiar el buscar id, el incializar en cero, y el buscar lugar libre y hacerlos para producto en vez de usuario
    }
}
