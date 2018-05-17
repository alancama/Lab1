#include "funciones.h"
#define ESP 20 //20 ESPACIOS DE ESTACIONAMIENTO
#define OUT 100

int main()
{
    //CREO E INICIO LAS ESTRUCTURAS CORRESPONDIENTES
    EPersona Persona[ESP];
    inicializarPropietarios(Persona,ESP);
    hardCodeProp(Persona);

    EAuto Auto[ESP];
    inicializarAutos(Auto,ESP);
    hardCodeAuto(Auto);

    EOutput Output[OUT];
    inicializarOutput(Output,OUT);
    hardCodeOutput(Output);

    //VARIABLES DE MENU Y SWITCH
    int opcion;
    int salir=0;
    int libre;
    int auxID,i;
    int flag=0;
    char confirm='n';

    //AUXILIARES DE PROPIETARIOS
    char auxTarjetaAr[100],auxNombreAr[100],auxDireccionAr[100];

    //AUXILIARES DE AUTOS
    char auxPatente[100];
    int auxPropietario,auxMarca,auxLugar,auxTiempo;


    do
    {
    opcion=Menu();
    switch(opcion)
        {
        case 1: //ALTA PROPIETARIO

             //OBTIENE INDICE LIBRE DE LA ESTRUCTURA
            libre=obtenerEspacioPersona(Persona,ESP);
            if(libre == -1)
            {
                printf("\n\n\n\t\t\t\t\t~No quedan lugares libres~\n\t\t\t\t\tSera redirijido al menu principal.\n\n\n\n");
                system("pause");
                break;
            }

            //VALIDA QUE NO HAYA NUMEROS EN EL NOMBRE
            if(!getStringLetras("\n\nIngrese nombre: \n\n",auxNombreAr))
            {
                printf("\n\n\n\t\t\t\t\t~El nombre ingresado debe tener solo letras~\n\n\n\n");
                system("pause");
                break;
            }

            //VALIDA QUE NO HAYA LETRAS EN LA TARJETA
            if(!getStringNumeros("\n\nIngrese Tarjeta de Credito: \n\n",auxTarjetaAr))
            {
                printf("\n\n\n\t\t\t\t\t~La tarjeta de credito debe tener solo numeros~\n\n\n\n");
                system("pause");
                break;
            }

            //VALIDA QUE SOLO HAYA LETRAS O NUMEROS EN LA DIRECCION
            if(!getStringAlfaNumerico("\n\nIngrese direccion: \n\n",auxDireccionAr))
            {
                printf("\n\n\n\t\t\t\t\t~La direccion que ingrese solo puede tener numeros, letras o espacios~\n\n\n\n");
                system("pause");
                break;
            }

            //TRANSFIERE LOS DATOS AUXILIARES AL ARRAY DE LA ESTRUCTURA ORIGINAL
            transferirEstructuraPersona(Persona,auxNombreAr,auxTarjetaAr,auxDireccionAr,libre);

            break;
        case 2:
            if(!listarPropietarios(Persona,ESP))
            {
                printf("\n\n\n\t\t\t\t\t~No hay propietarios modificables~\n\t\t\t\t\tSera redirijido al menu principal.\n\n\n\n");
                break;
            }


            printf("\nIngrese el ID del socio que desea modificar: ");
            scanf("%d",&auxID);


            //VALIDA QUE NO HAYA LETRAS EN LA NUEVA TARJETA
            if(!getStringNumeros("\n\nIngrese la nueva Tarjeta de Credito (xxxx-xxxx-xxxx-xxxx): \n\n",auxTarjetaAr))
            {
                printf("\n\n\n\t\t\t\t\t~La tarjeta de credito debe tener solo numeros~\n\t\t\t\t\tSera redirijido al menu principal.\n\n\n\n");
                system("pause");
                break;
            }

            i = buscarPorID(Persona,auxID,ESP);

            system("cls");
            printf("\n\nID: %d\n",Persona[i].ID);
            printf("\n\nNombre: %s\n",Persona[i].NombreCompleto);
            printf("\n\nTarjeta de credito: %s\n",Persona[i].Tarjeta);
            printf("\n\nNueva Tarjeta de credito: %s\n",auxTarjetaAr);
            printf("\n\nDireccion: %s\n\n\n",Persona[i].Direccion);

            printf("\n\n\n\nEsta seguro que desea modificar la tarjeta? S/N\n");
            confirm=getche();
            printf("\n\n");
            system("pause");
            system("cls");

            if((confirm=='s') || (confirm=='S'))
                {
                    strcpy(Persona[i].Tarjeta,auxTarjetaAr);
                    printf("\n\n\n\t\t\t\t\t~La tarjeta de credito se ha modificado con exito~\n\t\t\t\t\tSera redirijido al menu principal.\n\n\n\n");
                    system("pause");
                }

            else
                {
                    printf("\n\n\n\t\t\t\t\t~La tarjeta de credito NO se ha modificado~\n\t\t\t\t\tSera redirijido al menu principal.\n\n\n\n");
                    system("pause");
                }

            break;

        case 3:
                if(!listarPropietarios(Persona,ESP))
            {
                printf("\n\n\n\t\t\t\t\t~No hay propietarios modificables~\n\t\t\t\t\tSera redirijido al menu principal.\n\n\n\n");
                break;
            }

            printf("\nIngrese el ID del socio que desea dar de baja: \n");
            scanf("%d",&auxID);

             i = buscarPorID(Persona,auxID,ESP);

            system("cls");
            printf("\n\nID: %d\n",Persona[i].ID);
            printf("\n\nNombre: %s\n",Persona[i].NombreCompleto);
            printf("\n\nTarjeta de credito: %s\n",Persona[i].Tarjeta);
            printf("\n\nNueva Tarjeta de credito: %s\n",auxTarjetaAr);
            printf("\n\nDireccion: %s\n\n\n",Persona[i].Direccion);

            /**ACA VAN
            *LOS AUTOS
            *DEL USUARIO
            *Y EL MONTO
            *DE ESTADIA
            */

            printf("\n\n\n\nEsta seguro que desea dar de baja este usuario y terminar sus estadias (Debera abonar los egresos)? S/N\n");
            confirm=getche();
            printf("\n\n");
            system("pause");
            system("cls");



            if((confirm=='s') || (confirm=='S'))
                {
                    Persona[i].Estado=0;
                    printf("\n\n\n\t\t\t\t\t~El usuario se ha dado de baja con exito~\n\t\t\t\t\tSera redirijido al menu principal.\n\n\n\n");
                    system("pause");
                }

            else
                {
                    printf("\n\n\n\t\t\t\t\t~El usuario NO se ha dado de baja~\n\t\t\t\t\tSera redirijido al menu principal.\n\n\n\n");
                    system("pause");
                }

            break;
        case 4:

            libre=obtenerEspacioAuto(Auto,ESP);
            if(libre == -1)
            {
                printf("\n\n\n\t\t\t\t\t~No quedan lugares libres~\n\t\t\t\t\tSera redirijido al menu principal.\n\n\n\n");
                system("pause");
                break;
            }

            for(i=0;i<ESP;i++)
            {
                if(Persona[i].Estado==1)
                {
                    flag=1;
                }
            }

            if(!flag)
            {
                printf("\n\n\n\t\t\t\t\t~No hay ningun propietario en el sistema para asociar el ingreso de un auto~\n\n\n\n\t\t\t\t\t~Por favor de de alta un propietario antes de ingresar un auto~\n\t\t\t\t\tSera redirijido al menu principal.\n\n\n\n");
                break;
            }

            if(!getStringAlfaNumerico("\n\nIngrese patente (ABC-123): \n\n",auxPatente))
            {
                printf("\n\n\n\t\t\t\t\t~La patente ingrada solo puede tener numeros y letras~\n\n\n\n");
                system("pause");
                break;
            }

            printf("\nIngrese marca del vehiculo: \n1-Alpha Romeo ----- $150/hora \n2-Ferrari ----- $175/hora\n3-Audi ----- $200/hora\n4-Otro ----- $250/hora\n");
            scanf("%d",&auxMarca);

            if(!listarPropietarios(Persona,ESP))
            {
                printf("Este mensaje no deberia verse nunca");
                break;
            }

            printf("\nIngrese el ID del socio que ingresa el auto: ");
            scanf("%d",&auxPropietario);

            transferirEstructuraAuto(Auto,Persona,auxPatente,auxMarca,auxPropietario,libre,ESP);



            break;
        case 5:

            libre=obtenerEspacioOutput(Output,OUT);
            if(libre == -1)
            {
                printf("\n\n\n\t\t\t\t\t~No quedan lugares libres~\n\t\t\t\t\tSera redirijido al menu principal.\n\n\n\n");
                system("pause");
                break;
            }

            if(!listarAutos(Auto,Persona,ESP))
                    {
                        printf("\n\n\n\t\t\t\t\t~No hay Autos~\n\t\t\t\t\tSera redirijido al menu principal.\n\n\n\n");
                        system("pause");
                    }

            printf("\n\nIngrese el lugar correspondiente a donde se encuentra su auto: ");
            scanf("%d",&auxLugar);

            auxTiempo=devolverHorasEstadia();
            printf("\nSu auto estuvo estacionado %d horas... \n\n",auxTiempo);
            system("pause");

            egresoAuto(Auto,Persona,Output,auxLugar,auxTiempo,libre);

            break;
        case 6:
            //SE ABRE UN MENU PARA SELECCIONAR LA LISTA DESEADA
            listas(Persona,Auto,ESP);

            break;
        case 7:

            recaudaciones(Persona,Auto,Output,ESP,OUT);

            break;
        case 8:
            informarSocio(Persona,Auto,ESP);

            break;
        case 0:

            printf("\n\n\n\t\t\t\t\t\t~Programa terminado~\n\n\n");
            salir=1;
            break;

        default:
            printf("Error, opcion no valida\n\n");
            system("pause");
            break;

        }



    }while(salir==0);



    return 0;
}
