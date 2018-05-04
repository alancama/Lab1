#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EstructuraGenerica.h"
#define TAMANIO 10
#define OCUPADO 0
#define LIBRE 1
#define BORRADO -1


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
     printf("\n Nombre: %s - ID: %d - Estado: %d",parametro.nombre,parametro.idUsuario,parametro.estado);

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
        scanf("%s",listadoUsuario[indiceUsuario].nombre);
    }

    return;
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

        //strcpy(listadoUsuario[indiceUsuario].nombre, "");
        listadoUsuario[indiceUsuario].estado=BORRADO;
        //listadoUsuario[indiceUsuario].idUsuario=0;

        printf("\n");
        eUser_mostrarUno(listadoUsuario[indiceUsuario]);
        printf("\n");
    }

    return;
}

int eProducto_init( eProducto listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estado= LIBRE;
            listado[i].idProducto= 0;
        }
    }
    return retorno;
}

int eProd_buscarLugarLibre(eProducto listado[],int limite)
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

int eProd_siguienteId(eProducto listado[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO)
            {
                    if(listado[i].idProducto>retorno)
                    {
                         retorno=listado[i].idProducto;
                    }

            }
        }
    }

    return retorno+1;
}


int eProd_buscarPorId(eProducto listado[] ,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == OCUPADO && listado[i].idProducto == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eProd_mostrarListadoPorIdUsuario(eProducto listado[],int limite, eUsuario listadoUsuario[],int limiteUsuario,int idUsuario)
{
    int retorno = -1;
    int i;

    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado==OCUPADO && listado[i].idUsuario==idUsuario)
            {

                printf("Nombre Producto: %s - ID Producto: %d - Precio Producto: %.2f - Stock: %d",listado[i].nombreProducto,listado[i].idProducto,listado[i].precio,listado[i].stock);
            }

        }
    }
    return retorno;
}

int eProd_mostrarUno(eProducto parametro)
{
     printf("\n Nombre Producto: %s - ID Producto: %d - Stock: %d - Estado: %d",parametro.nombreProducto,parametro.idProducto,parametro.stock,parametro.estado);

}


int publicarProducto(eUsuario listadoUsuario[],int CANTIDADUSUARIO,eProducto productos[],int CANTIDADPRODUCTO)
{
    int id,indiceProducto,stock,precio,idProducto;
    eUser_mostrarListado(listadoUsuario, CANTIDADUSUARIO);
    printf("\nIngrese ID de usuario a publicar");

     scanf("%d",&id);

    indiceProducto=eProd_buscarLugarLibre(productos,CANTIDADPRODUCTO);//COMPLETAMEEEEEEEEEEEEEEEEEEEEE

    if(indiceProducto>=0)
    {
        idProducto=eProd_siguienteId(productos,CANTIDADPRODUCTO);

        printf("\nIngrese nombre de producto: ");
        fflush(stdin);
        scanf("%s",productos[indiceProducto].nombreProducto);//PARA EL PARCIAL CAMBIAR A GETS();

        printf("\nIngrese stock: ");
        scanf("%d",&productos[indiceProducto].stock);


        printf("\nIngrese precio del producto: ");
        scanf("%f",&productos[indiceProducto].precio);

        productos[indiceProducto].idUsuario=id;
        productos[indiceProducto].estado=OCUPADO;
        productos[indiceProducto].idProducto=idProducto;

    }


    return;
}

int eProd_modificacion(eUsuario listadoUsuario[] ,int CANTIDADUSUARIO, eProducto listadoProducto[], int CANTIDADPRODUCTO)//FALTAN VERIFICACIONES
{
    eUser_mostrarListado(listadoUsuario, CANTIDADUSUARIO);

    int idUsuario,indiceUsuario,idProducto,indiceProducto;


    printf("\nIngrese ID de Usuario: ");
    scanf("%d",&idUsuario);

    indiceUsuario=eUser_buscarPorId(listadoUsuario, CANTIDADUSUARIO, idUsuario);


    eProd_mostrarListadoPorIdUsuario(listadoProducto,CANTIDADPRODUCTO,listadoUsuario,CANTIDADUSUARIO,idUsuario);

    printf("Ingrese ID de Producto: ");
    scanf("%d",&idProducto);

    indiceProducto=eProd_buscarPorId(listadoProducto,CANTIDADPRODUCTO,idProducto);

    if(indiceProducto>=0)
    {
        printf("Ingrese nuevo nombre de producto: ");
        scanf("%s",listadoProducto[indiceProducto].nombreProducto);

        printf("Ingrese nuevo precio: ");
        scanf("%f",&listadoProducto[indiceProducto].precio);

        printf("Ingrese stock: ");
        scanf("%d",&listadoProducto[indiceProducto].stock);
    }

    return;
}

int eProd_Baja(eUsuario listadoUsuario[] ,int CANTIDADUSUARIO, eProducto listadoProducto[], int CANTIDADPRODUCTO)//FALTAN VERIFICACIONES
{
    eUser_mostrarListado(listadoUsuario, CANTIDADUSUARIO);

    int idUsuario,indiceUsuario,idProducto,indiceProducto;


    printf("\nIngrese ID de Usuario: ");
    scanf("%d",&idUsuario);

    indiceUsuario=eUser_buscarPorId(listadoUsuario, CANTIDADUSUARIO, idUsuario);


    eProd_mostrarListadoPorIdUsuario(listadoProducto,CANTIDADPRODUCTO,listadoUsuario,CANTIDADUSUARIO,idUsuario);

    printf("\nIngrese ID de Producto: ");
    scanf("%d",&idProducto);

    indiceProducto=eProd_buscarPorId(listadoProducto,CANTIDADPRODUCTO,idProducto);

    if(indiceProducto>=0)
    {
        listadoProducto[indiceProducto].estado=BORRADO;
    }

    return;
}
