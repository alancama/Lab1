#include "funciones.h"


int Menu(void)
{
    int opcion;
    system("cls");
    printf("\n¿Que desea hacer?\n\n");
    printf("~Administracion de propietarios~\n");
    printf("~1-Alta Propietario~\n");
    printf("~2-Modificar Tarjeta de Credito~\n");
    printf("~3-Baja Propietario~\n\n");
    printf("~Administracion de automoviles~\n");
    printf("~4-Ingreso Automovil~\n");
    printf("~5-Egreso Automovil~\n\n");
    printf("~Funciones~\n");
    printf("~6-Listas~\n");
    printf("~7-Recaudaciones~\n\n");
    printf("~8-Buscar Propietario~\n\n");
    printf("~0-Salir~\n\n\n\n");

    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);
    system("cls");

    return opcion;
}

void inicializarPropietarios(EPersona Persona[],int valor)
{
    for(int i=0; i<valor; i++)
    {
        Persona[i].Estado=0;
    }
}

void inicializarAutos(EAuto Auto[],int valor)
{
    for(int i=0; i<valor; i++)
    {
        Auto[i].Estado=0;
    }
}

void inicializarOutput(EOutput Output[],int valor)
{
    for(int i=0; i<valor; i++)
    {
        Output[i].Estado=0;
    }
}

int listarPropietarios(EPersona Persona[],int valor)
{
    int flag=1;
    int lenNombre;



    system("cls");
    printf("\n\n~ID~\t~Nombre~\t\t\t~Tarjeta de Credito~\t\t~Direccion~\n\n");
    for(int i=0; i<valor; i++)
    {
        if(Persona[i].Estado==1)
        {
            lenNombre=strlen(Persona[i].NombreCompleto);

            printf("%d\t%s\t\t",Persona[i].ID,Persona[i].NombreCompleto);

            if(lenNombre<16)
            {
                printf("\t");
            }

            printf("%s\t\t%s\n",Persona[i].Tarjeta,Persona[i].Direccion);
            flag=0;
        }

    }

    if(flag)
    {
        system("cls");
        return 0;
    }

    else
    {
        printf("\n");
        return 1;
    }

}

int listarAutos(EAuto Auto[],EPersona Persona[],int valor)
{
    int flag=1;
    system("cls");
    printf("\n~Lista de Autos en el estacionamiento~\n\nLugar\tPatente\t\t\tMarca\t\t\tPropietario\t\t\t\n\n");
    for(int i=0; i<valor; i++)
    {
        if(Auto[i].Estado==1)
        {

            int idProp= ((Auto[i].Propietario) - 1);
            printf("%d\t%s",Auto[i].Lugar,Auto[i].Patente);

            if(Auto[i].Marca==1)
            {
                printf("\t\t\tAlpha Romeo\t\t");
            }
            else if(Auto[i].Marca==2)
            {
                printf("\t\t\tFerrari\t\t\t");
            }
            else if(Auto[i].Marca==3)
            {
                printf("\t\t\tAudi\t\t\t");
            }
            else
            {
                printf("\t\t\tOtro\t\t\t");
            }

            printf("%s\t\t\t\n",Persona[idProp].NombreCompleto);
            flag=0;
        }

    }
    if(flag)
    {
        system("cls");
        return 0;
    }
    else
    {
        printf("\n");
        return 1;
    }

}

int listarAutosxPatente(EAuto Auto[],EPersona Persona[],int valor)
{
    int flag=1;
    EAuto auxAuto[valor];

    for(int i=0; i<valor; i++)
    {
        auxAuto[i].Estado=Auto[i].Estado;
        auxAuto[i].Lugar=Auto[i].Lugar;
        auxAuto[i].Marca=Auto[i].Marca;
        auxAuto[i].Propietario=Auto[i].Propietario;
        strcpy(auxAuto[i].Patente,Auto[i].Patente);
    }

    ordenarPatente(auxAuto,valor);

    system("cls");
    printf("\n~Lista de Autos en el estacionamiento~\n\nLugar\tPatente\t\t\tMarca\t\t\tPropietario\t\t\t\n\n");
    for(int i=0; i<valor; i++)
    {
        if(auxAuto[i].Estado==1)
        {

            int idProp= ((auxAuto[i].Propietario) - 1);
            printf("%d\t%s",auxAuto[i].Lugar,auxAuto[i].Patente);

            if(auxAuto[i].Marca==1)
            {
                printf("\t\t\tAlpha Romeo\t\t");
            }
            else if(auxAuto[i].Marca==2)
            {
                printf("\t\t\tFerrari\t\t\t");
            }
            else if(auxAuto[i].Marca==3)
            {
                printf("\t\t\tAudi\t\t\t");
            }
            else
            {
                printf("\t\t\tOtro\t\t\t");
            }

            printf("%s\t\t\t\n",Persona[idProp].NombreCompleto);
            flag=0;
        }

    }
    if(flag)
    {
        system("cls");
        return 0;
    }
    else
    {
        printf("\n");
        return 1;
    }

}

int listarPropietariosAudi(EPersona Persona[],EAuto Auto[],int valor)
{
    int flag=1;
    int flagA[valor];
    int lenNombre,lenDireccion;
    int i,j;
    int cont[valor];

    for(i=0;i<valor;i++)
    {
        cont[i]=0;
        flagA[i]=1;
    }

    for(i=0;i<valor;i++)
    {
        for(j=0;j<valor;j++)
        {
            if((Persona[i].ID==Auto[j].Propietario) && (Auto[j].Marca==3))
            {
                cont[i]++;
            }
        }
    }
    system("cls");
    printf("\n\t\t\t\t\t~Propietarios de Audis~\n\n");
    printf("\n\n~ID~\t~Nombre~\t\t\t~Tarjeta de Credito~\t\t~Direccion~\t\t~Numero de audis~\n\n");
    for(i=0; i<valor; i++)
    {

        for(j=0; j<valor; j++)
        {
            if((Persona[i].ID==Auto[j].Propietario) && (Auto[j].Marca==3) && (flagA[i]))
            {
                lenNombre=strlen(Persona[i].NombreCompleto);
                lenDireccion=strlen(Persona[i].Direccion);

            printf("%d\t%s\t\t",Persona[i].ID,Persona[i].NombreCompleto);

            if(lenNombre<16)
            {
                printf("\t");
            }

            printf("%s\t\t%s\t",Persona[i].Tarjeta,Persona[i].Direccion);

            if(lenDireccion<16)
            {
                printf("\t");
            }

            printf("%d\n",cont[i]);

            flag=0;
            flagA[i]=0;
            }
        }
    }

    if(flag)
    {
        system("cls");
        return 0;
    }
    else
    {
        printf("\n");
        return 1;
    }
}

int recaudacionTotal(EOutput Output[],EPersona Persona[],int valor,int out)
{

    int flag=1;
    int idPersona;
    int lenNombre;
    int acumNeto=0;

    system("cls");
    printf("\n~Lista de Autos egresados~\n\nEgreso n\tPatente\t\tMarca\t\tPropietario\t\tHoras/Monto\t\n\n");
    for(int i=0; i<out; i++)
    {
        if(Output[i].Estado==1)
        {
            idPersona=buscarPorID(Persona,Output[i].Propietario,valor);
            lenNombre=strlen(Persona[idPersona].NombreCompleto);
            int idProp= ((Output[i].Propietario) - 1);
            printf("%d\t\t%s",Output[i].Cont,Output[i].Patente);

            if(Output[i].Marca==1)
            {
                printf("\t\tAlpha Romeo\t");
            }
            else if(Output[i].Marca==2)
            {
                printf("\t\tFerrari\t\t");
            }
            else if(Output[i].Marca==3)
            {
                printf("\t\tAudi\t\t");
            }
            else
            {
                printf("\t\tOtro\t\t");
            }


            printf("%s\t",Persona[idProp].NombreCompleto);

            if(lenNombre<16)
            {
                printf("\t");
            }

            printf("%dhs/$%d\n",Output[i].Tiempo,Output[i].Monto);
            flag=0;
        }

    }

    for(int j=0; j<out; j++)
    {
        acumNeto=acumNeto + Output[j].Monto;
    }

    printf("\n\n\n\n\t\t\t\t~El monto de la recaudacion total es de: $%d~\n\n\n",acumNeto);

    if(flag)
    {
        system("cls");
        return 0;
    }
    else
    {
        printf("\n");
        return 1;
    }


}

int recaudacionPorMarca(EOutput Output[],EPersona Persona[],int valor,int out)
{
    int flag=1;
    int idPersona;
    int lenNombre;
    int acumNeto=0;
    int opcion;

    system("cls");
    printf("\nIngrese la marca para ver su recaudacion: \n\n1-Alpha Romeo\n2-Ferrari\n3-Audi\n4-Otro\n\nIngrese opcion: ");
    scanf("%d",&opcion);

    system("cls");
    printf("\n~Lista de Autos egresados~\n\nEgreso n\tPatente\t\tMarca\t\tPropietario\t\tHoras/Monto\t\n\n");
    for(int i=0; i<out; i++)
    {
        if((Output[i].Estado==1) && (Output[i].Marca==opcion))
        {
            idPersona=buscarPorID(Persona,Output[i].Propietario,valor);
            lenNombre=strlen(Persona[idPersona].NombreCompleto);
            int idProp= ((Output[i].Propietario) - 1);
            printf("%d\t\t%s",Output[i].Cont,Output[i].Patente);

            if(Output[i].Marca==1)
            {
                printf("\t\tAlpha Romeo\t");
            }
            else if(Output[i].Marca==2)
            {
                printf("\t\tFerrari\t\t");
            }
            else if(Output[i].Marca==3)
            {
                printf("\t\tAudi\t\t");
            }
            else
            {
                printf("\t\tOtro\t\t");
            }


            printf("%s\t",Persona[idProp].NombreCompleto);

            if(lenNombre<16)
            {
                printf("\t");
            }

            printf("%dhs/$%d\n",Output[i].Tiempo,Output[i].Monto);
            flag=0;

            acumNeto=acumNeto + Output[i].Monto;
        }

    }


    printf("\n\n\n\n\t\t\t\t~El monto de la recaudacion total de la marca es de: $%d~\n\n\n",acumNeto);

    if(flag)
    {
        system("cls");
        return 0;
    }
    else
    {
        printf("\n");
        return 1;
    }

}

int obtenerEspacioPersona(EPersona Persona[],int valor)
{
    for(int i=0; i<valor; i++)
    {
        if(Persona[i].Estado==0)
        {
            return i;
        }
    }
    return -1;
}

int obtenerEspacioAuto(EAuto Auto[],int valor)
{
    for(int i=0; i<valor; i++)
    {
        if(Auto[i].Estado==0)
        {
            return i;
        }
    }
    return -1;
}

int obtenerEspacioOutput(EOutput Output[],int valor)
{
    for(int i=0; i<valor; i++)
    {
        if(Output[i].Estado==0)
        {
            return i;
        }
    }
    return -1;
}

int buscarPorID(EPersona persona[],int id,int valor)
{
    for(int i=0; i<valor; i++)
    {
        if(persona[i].Estado==1 && persona[i].ID==id)
        {
            return i;
        }
    }
    return -1;
}

int buscarPorPatente(EAuto Auto[],char patente[],int valor)
{
    for(int i=0; i<valor; i++)
    {
        if((Auto[i].Estado==1) && (strcmp(Auto[i].Patente,patente)))
        {
            return i;
        }
    }
    return -1;
}

int noVoid(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] < 'a' || str[i] > 'z') || (str[i] < 'A' || str[i] > 'Z') || (str[i] < '0' || str[i] > '9'))
        {
            return 1;
        }
        i++;
    }
    system("cls");
    printf("\n\n\n\t\t\t\t\t~El dato que ingreso esta vacio~\n\t\t\t\t\tSera redirijido al menu principal.\n\n\n\n");
    system("pause");
    return 0;
}

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    fflush(stdin);
    gets(input);
}

int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int esSoloLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        {
            return 0;
        }
        i++;
    }
    if(!noVoid(str))
    {
        return 0;
    }
    return 1;
}

int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int esNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < '0' || str[i] > '9'))
        {
            return 0;
        }
        i++;
    }
    if(!noVoid(str))
    {
        return 0;
    }
    return 1;
}


int esAlfaNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] != '-') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
        {
            return 0;
        }
        i++;
    }
    if(!noVoid(str))
    {
        return 0;
    }
    return 1;
}

int getStringAlfaNumerico(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);

    if(esAlfaNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }

    return 0;
}

void ordenarNombre(EPersona Persona[],int valor)
{
    EPersona auxiliarPersona;
    for(int i=0; i <valor-1; i++)
    {
        if(Persona[i].Estado == 0)
        {
            continue;
        }
        for(int j=i+1; j < valor; j++)
        {
            if(Persona[j].Estado == 0)
            {
                continue;
            }
            if(strcmp(Persona[i].NombreCompleto,Persona[j].NombreCompleto) > 0)
            {
                auxiliarPersona = Persona[j];
                Persona[j] = Persona[i];
                Persona[i] = auxiliarPersona;
                //
            }
        }
    }

}

void ordenarPatente(EAuto Auto[],int valor)
{
    EAuto auxiliarAuto;
    for(int i=0; i <valor-1; i++)
    {
        if(Auto[i].Estado == 0)
        {
            continue;
        }
        for(int j=i+1; j < valor; j++)
        {
            if(Auto[j].Estado == 0)
            {
                continue;
            }
            if(strcmp(Auto[i].Patente,Auto[j].Patente) > 0)
            {
                auxiliarAuto = Auto[j];
                Auto[j] = Auto[i];
                Auto[i] = auxiliarAuto;
                //
            }
        }
    }

}

void transferirEstructuraPersona(EPersona Persona[],char nombre[],char tarjeta[],char direccion[],int libre)
{

    strlwr(nombre);
    for(int i=0; i<50; i++)
    {
        if(nombre[i]==' ')
        {
            nombre[i+1]=toupper(nombre[i+1]);
        }
    }

    nombre[0]=toupper(nombre[0]);
    Persona[libre].ID=libre+1;
    strcpy(Persona[libre].Tarjeta,tarjeta);
    strcpy(Persona[libre].NombreCompleto,nombre);
    strcpy(Persona[libre].Direccion,direccion);
    Persona[libre].Estado=1;
    system("cls");
    printf("\n\nID: %d\n",Persona[libre].ID);
    printf("\n\nNombre: %s\n",Persona[libre].NombreCompleto);
    printf("\n\nTarjeta de credito: %s\n",Persona[libre].Tarjeta);
    printf("\n\nDireccion: %s\n\n\n",Persona[libre].Direccion);
    system("pause");
    system("cls");

    printf("\n\n\n\t\t\t\t\t~Se ha dado de alta satisfactoriamente~\n\t\t\t\t\tSera redirijido al menu principal.\n\n\n\n");
    system("pause");
}


void transferirEstructuraAuto(EAuto Auto[],EPersona Persona[],char patente[],int marca,int propietario,int libre,int valor)
{
    int auxPropietario;

    Auto[libre].Lugar=libre+1;
    strcpy(Auto[libre].Patente,patente);
    Auto[libre].Marca=marca;
    Auto[libre].Propietario=propietario;
    Auto[libre].Estado=1;

    system("cls");
    printf("\n\nPatente: %s\n",Auto[libre].Patente);

    if(Auto[libre].Marca==1)
    {
        printf("\n\nMarca: Alpha Romeo.\n");
    }
    else if(Auto[libre].Marca==2)
    {
        printf("\n\nMarca: Ferrari.\n");
    }
    else if(Auto[libre].Marca==3)
    {
        printf("\n\nMarca: Audi.\n");
    }
    else
    {
        printf("\n\nMarca: Otro.\n");
    }

    auxPropietario=buscarPorID(Persona,propietario,valor);

    printf("\n\nPropietario: %s.\n\n\n",Persona[auxPropietario].NombreCompleto);
    system("pause");
    system("cls");

    printf("\n\n\n\t\t\t\t\t~Se ha dado de alta satisfactoriamente~\n\t\t\t\t\tSera redirijido al menu principal.\n\n\n\n");
    system("pause");


}

void egresoAuto(EAuto Auto[],EPersona Persona[],EOutput Output[],int lugar,int tiempo,int libre)
{

    int lugarIndice=lugar-1;
    int monto;
    int auxPropietario;


    if(Auto[lugarIndice].Marca==1)
    {
        monto = tiempo*150;
    }
    else if(Auto[lugarIndice].Marca==2)
    {
        monto = tiempo*175;
    }
    else if(Auto[lugarIndice].Marca==3)
    {
        monto = tiempo*200;
    }
    else
    {
        monto = tiempo*250;
    }

    strcpy(Output[libre].Patente,Auto[lugarIndice].Patente);
    Output[libre].Marca=Auto[lugarIndice].Marca;
    Output[libre].Tiempo=tiempo;
    Output[libre].Monto=monto;
    Output[libre].Propietario=Auto[lugarIndice].Propietario;
    Output[libre].Estado=1;
    Output[libre].Cont=libre+1;
    Auto[lugarIndice].Estado=0;

    system("cls");
    printf("\n\nPatente: %s\n",Output[libre].Patente);

    if(Output[libre].Marca==1)
    {
        printf("\n\nMarca: Alpha Romeo.\n");
    }
    else if(Output[libre].Marca==2)
    {
        printf("\n\nMarca: Ferrari.\n");
    }
    else if(Output[libre].Marca==3)
    {
        printf("\n\nMarca: Audi.\n");
    }
    else
    {
        printf("\n\nMarca: Otro.\n");
    }

    printf("\n\nHoras de estadia: %dhs\n",Output[libre].Tiempo);
    printf("\n\nMonto a pagar: $%d\n",Output[libre].Monto);

    auxPropietario=buscarPorID(Persona,Output[libre].Propietario,20);

    printf("\n\nPropietario: %s.\n\n\n",Persona[auxPropietario].NombreCompleto);
    system("pause");
    system("cls");

    printf("\n\n\n\t\t\t\t\t~Se ha retirado el auto correctamente~\n\t\t\t\t\tSera redirijido al menu principal.\n\n\n\n");
    system("pause");
}


void listas(EPersona Persona[], EAuto Auto[], int valor)
{

    int opcion;


    printf("\n~Menu Listas: ~\n\n");
    printf("~1-Lista de socios~\n");
    printf("~2-Lista de Autos x ingreso~\n");
    printf("~3-Lista de Autos x patente~\n");
    printf("~4-Socios propietarios de audis~\n");
    scanf("%d",&opcion);

    switch(opcion)
    {
    case 1:

        if(!listarPropietarios(Persona,valor))
        {
            printf("\n\n\n\t\t\t\t\t~No hay propietarios~\n\t\t\t\t\tSera redirijido al menu principal.\n\n\n\n");
            system("pause");
        }
        break;

    case 2:
        if(!listarAutos(Auto,Persona,valor))
        {
            printf("\n\n\n\t\t\t\t\t~No hay Autos~\n\t\t\t\t\tSera redirijido al menu principal.\n\n\n\n");
            system("pause");

        }
        break;

    case 3:
        if(!listarAutosxPatente(Auto,Persona,valor))
        {
            printf("\n\n\n\t\t\t\t\t~No hay Autos~\n\t\t\t\t\tSera redirijido al menu principal.\n\n\n\n");
            system("pause");

        }
        break;
    case 4:
        if(!listarPropietariosAudi(Persona,Auto,valor))
        {
            printf("\n\n\n\t\t\t\t\t~No hay propietarios de audi~\n\t\t\t\t\tSera redirijido al menu principal.\n\n\n\n");
            system("pause");
        }
        break;
    default:

        system("cls");
        printf("\n\n\n\t\t\t\t\t~Opcion erronea.~\n\t\t\t\t\tSera redirijido al menu principal.\n\n\n\n");
        system("pause");
        break;


    }
    system("pause");
}

void recaudaciones(EPersona Persona[], EAuto Auto[],EOutput Output[],int valor,int out)
{

    int opcion;


    printf("\n~Menu Recaudaciones: ~\n\n");
    printf("~1-Recaudacion total del estacionamiento~\n");
    printf("~2-Recaudacion total por marca~\n\nIngrese opcion: ");
    scanf("%d",&opcion);

    switch(opcion)
    {
    case 1:

        if(!recaudacionTotal(Output,Persona,valor,out))
        {
            printf("\n\n\n\t\t\t\t\t~No hay egresos~\n\t\t\t\t\tSera redirijido al menu principal.\n\n\n\n");
            system("pause");
        }
        break;

    case 2:
        if(!recaudacionPorMarca(Output,Persona,valor,out))
        {
            printf("\n\n\n\t\t\t\t\t~No hay egresos~\n\t\t\t\t\tSera redirijido al menu principal.\n\n\n\n");
            system("pause");

        }
        break;

    default:

        system("cls");
        printf("\n\n\n\t\t\t\t\t~Opcion erronea.~\n\t\t\t\t\tSera redirijido al menu principal.\n\n\n\n");
        system("pause");
        break;


    }
    system("pause");
}

void informarSocio(EPersona Persona[],EAuto Auto[],int valor)
{
    int auxID,indicePersona;

    if(!listarPropietarios(Persona,valor))
    {
        printf("\n\n\n\t\t\t\t\t~No hay propietarios~\n\t\t\t\t\tSera redirijido al menu principal.\n\n\n\n");
        system("pause");

        return;
    }


    printf("\nIngrese el ID del socio sobre el que desea informarse: ");
    scanf("%d",&auxID);

    indicePersona=buscarPorID(Persona,auxID,valor);

    system("cls");
    printf("\n\t\t\t\t\t~Datos de: %s~\n\n",Persona[indicePersona].NombreCompleto);
    printf("ID: %d\n\n",Persona[indicePersona].ID);
    printf("Tarjeta de credito: %s\n\n",Persona[indicePersona].Tarjeta);
    printf("Direccion: %s\n\n\n",Persona[indicePersona].Direccion);

    if(!poseeAutos(Persona,Auto,valor,indicePersona))
    {
        printf("\n\n\n\t\t\t\t\t~El socio no posee autos estacionados~\n\t\t\t\t\tSera redirijido al menu principal.\n\n\n\n");
        system("pause");

        return;
    }

    system("pause");
    system("cls");

}

int poseeAutos(EPersona Persona[],EAuto Auto[],int valor,int indice)
{

    int flag=1;
    printf("\n\t\t\t\t\t~Autos estacionados de %s~\n\n ",Persona[indice].NombreCompleto);
    printf("\nLugar\tPatente\t\t\tMarca\t\t\t\n\n");

    for(int i=0; i<valor; i++)
    {
        if(Persona[indice].ID==Auto[i].Propietario)
        {
            printf("%d\t%s",Auto[i].Lugar,Auto[i].Patente);

            if(Auto[i].Marca==1)
            {
                printf("\t\t\tAlpha Romeo\t\t\n");
            }
            else if(Auto[i].Marca==2)
            {
                printf("\t\t\tFerrari\t\t\t\n");
            }
            else if(Auto[i].Marca==3)
            {
                printf("\t\t\tAudi\t\t\t\n");
            }
            else
            {
                printf("\t\t\tOtro\t\t\t\n");
            }

            flag=0;
        }

    }

    if(flag)
    {
        system("cls");
        return 0;
    }

    else
    {
        printf("\n");
        return 1;
    }
}

void hardCodeProp(EPersona Persona[])
{
    int id[5]= {1,2,3,4,5};
    char nombre[][50]= {"Juan","Maria","Jose","Pepito","Marcelo"};
    char direccion[][50]= {"adrogue","burzaco","longchamp","???","¿¿¿¿"};
    char tarjeta[][50]= {"1234 1234 1234 1234","4567 4567 4567 4567","7894 7894 7894 7894","4561 4561 4561 4561","3214 3214 3214 3214"};

    for(int i=0; i<5; i++)
    {
        Persona[i].ID=id[i];
        strcpy(Persona[i].NombreCompleto,nombre[i]);
        strcpy(Persona[i].Direccion,direccion[i]);
        strcpy(Persona[i].Tarjeta,tarjeta[i]);
        Persona[i].Estado=1;
    }

}

void hardCodeAuto(EAuto Auto[])
{
    int lugar[]= {1,2,3,4,5,6,7,8,9};
    char patente[][20]= {"AAA-111","CCC-222","DDD-333","BBB-444","ZZZ-555","III-666","HHH-777","EEE-888","FFF-999"};
    int marca[]= {1,3,3,2,2,3,3,4,3};
    int propietario[]= {2,1,2,1,3,5,4,1,4};


    for(int i=0; i<9; i++)
    {
        Auto[i].Lugar=lugar[i];
        strcpy(Auto[i].Patente,patente[i]);
        Auto[i].Marca=marca[i];
        Auto[i].Propietario=propietario[i];
        Auto[i].Estado=1;
    }

}


void hardCodeOutput(EOutput Output[])
{
    int cont[]= {1,2,3,4,5,6,7,8,9};
    char patente[][20]= {"ABA-101","CDC-212","DED-323","BCB-434","ZAZ-545","IJI-656","HIH-767","EFE-878","FGF-989"};
    int marca[]= {1,3,3,1,2,3,3,4,3};
    int propietario[]= {2,1,2,1,3,5,4,1,4};
    int tiempo[]= {3,13,2,6,14,2,11,1,9};


    for(int i=0; i<9; i++)
    {

        Output[i].Cont=cont[i];
        strcpy(Output[i].Patente,patente[i]);
        Output[i].Marca=marca[i];
        Output[i].Propietario=propietario[i];
        Output[i].Estado=1;

        //tiempo=devolverHorasEstadia();

        if(Output[i].Marca==1)
        {
            Output[i].Monto = tiempo[i]*150;
        }
        else if(Output[i].Marca==2)
        {
            Output[i].Monto = tiempo[i]*175;
        }
        else if(Output[i].Marca==3)
        {
            Output[i].Monto = tiempo[i]*200;
        }
        else
        {
            Output[i].Monto = tiempo[i]*250;
        }

        Output[i].Tiempo=tiempo[i];

    }

}

int devolverHorasEstadia()
{
    int horas;

    srand(time(NULL));

    horas = (rand()%24)+1;

    return horas ;

}







