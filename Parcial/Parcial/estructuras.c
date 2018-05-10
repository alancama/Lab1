#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"
#define LIBRE 0
#define OCUPADO 1
#define BORRADO -1

int eUser_init(eUsuario listado[],int limite)
{
        int i;

        for(i=0; i<limite; i++)
        {
            listado[i].estado= LIBRE;
            listado[i].idPropietario= 0;
        }
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

        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO)
            {
                    if(listado[i].idPropietario>retorno)
                    {
                         retorno=listado[i].idPropietario;
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
            if(listado[i].estado == OCUPADO && listado[i].idPropietario == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eUser_alta(eUsuario  listado[],int limite)
{
    int retorno = -1;
    int id;
    char tarjeta[50];
    int indice;
    int validar;
    char direccion[50];
    char nombre[50];
    char apellido[50];

    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        indice = eUser_buscarLugarLibre(listado,limite);
        if(indice >= 0)
        {
            retorno = -3;
            id = eUser_siguienteId(listado,limite); //Me da el ID siguiente al ultimo usuario ocupado, este va a ser el id del nuevo usuario.

            do
            {
                printf("Ingrese nombre: ");
                fflush(stdin);
                gets(listado[indice].nombre);
                strcpy(nombre,listado[indice].nombre);
                validar=validarNombre(nombre);
                printf("Ingrese apellido: ");
                fflush(stdin);
                gets(listado[indice].apellido);
                strcpy(apellido,listado[indice].apellido);
                validar=validarNombre(apellido);
                printf("Ingrese direccion: ");
                fflush(stdin);
                gets(listado[indice].direccion);
                strcpy(direccion,listado[indice].direccion);
                printf("Ingrese tarjeta: ");
                fflush(stdin);
                gets(listado[indice].tarjeta);
                strcpy(tarjeta,listado[indice].tarjeta);



            }while(validar==0);

            retorno = 0;
            listado[indice].idPropietario = id;
            listado[indice].estado = OCUPADO;
        }
    }
    return retorno;
}

int validarNombre(char nombre[])
{
    int retorno=1;

    int i;
    for(i=0; i<strlen(nombre); i++)
    {
        if(!(isalpha(nombre[i])))
        {
            retorno=0;
            printf("Error, ingrese solo caracteres. \n");
            break;
        }
    }

    return retorno;
}

int validarNumero(char numero[])
{
    int retorno=1;

    int i;
    for(i=0; i<strlen(numero); i++)
    {
        if(!(isdigit(numero[i])))
        {
            retorno=0;
            printf("Error, ingrese solo numeros. \n");
            break;
        }
    }

    return retorno;
}

void eUser_mostrarUno(eUsuario parametro)
{
     printf("\n Nombre: %s -  Direccion: %s - Tarjeta: %s - ID: %d - \n",parametro.nombre,parametro.direccion,parametro.tarjeta,parametro.idPropietario);
}

void eUser_mostrarListado(eUsuario listado[],int limite)
{
    int i;

        for(i=0; i<limite; i++)
        {
            if(listado[i].estado==OCUPADO)
            {
                eUser_mostrarUno(listado[i]);
            }
        }

}

void eUser_baja(eUsuario listado[] ,int limiteUsuarios)
{
    int id, indiceUser=-1;
    char opcion;
    eUser_mostrarListado(listado,limiteUsuarios);

    do{
        printf("\nIngrese ID de usuario a dar de baja: ");
        fflush(stdin);
        scanf("%d",&id);

        indiceUser=eUser_buscarPorId(listado,limiteUsuarios,id);

    if(indiceUser>=0)
    {

        eUser_mostrarUno(listado[indiceUser]);

        printf("Desea borrar este usuario: S/N");
        scanf("%s",&opcion);
        if(opcion=='s' || opcion=='S')
        {
            listado[indiceUser].estado=BORRADO;
            listado[indiceUser].idPropietario=0;
            strcpy(listado[indiceUser].nombre, "");
            strcpy(listado[indiceUser].tarjeta, "");
            printf("\n");
        }
        else
        {
            break;
        }

    }
    else
        printf("El ID ingresado no coincide con ningun usuario.");
    }while(indiceUser<0);

}

void eUser_modificacion(eUsuario listado[] ,int limite)
{
    int id, indiceUser=-1, validar;
    char tarjeta[50];
    char opcion;

    eUser_mostrarListado(listado,limite);

    do{
        printf("\nIngrese ID de usuario a modificar: ");
        scanf("%d",&id);

    indiceUser=eUser_buscarPorId(listado,limite,id);

    if(indiceUser>=0)
    {
        eUser_mostrarUno(listado[indiceUser]);

        printf("Desea modificar este usuario: S/N");
        scanf("%s",&opcion);

        if(opcion=='S' || opcion=='s')
        {
            printf("\nIngrese nueva tarjeta: ");

        fflush(stdin);
        gets(listado[indiceUser].tarjeta);
        strcpy(tarjeta,listado[indiceUser].tarjeta);





        eUser_mostrarUno(listado[indiceUser]);
        }
        else
        {
            break;
        }

    }
    else
        printf("El ID ingresado no coincide con ningun usuario.");

    }while(indiceUser<0);
}

