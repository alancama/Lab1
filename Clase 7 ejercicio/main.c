#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANT 2



int main()
{
    char nombre[CANT][15],nomAux[15],apellido[CANT][15],apeAux[15],seguir='s',rta;
    int flagLegajo,edad[CANT],edadAux,opcion,legajo[CANT],legajoAux,i,j,isEmpty[CANT],isEmptyAux,opcionMod;

    for(i=0;i<CANT;i++)
    {
        isEmpty[i]=1;
    }

    while(seguir=='s'){
        printf("1-Alta\n");
        printf("2-Baja\n");
        printf("3-Modificacion\n");
        printf("4-Ordenar(Apellido)\n");
        printf("5-Salir\n");

        scanf("%d",&opcion);
        system("cls");
        switch(opcion)
        {
            case 1:
                    for(i=0;i<CANT;i++)
                    {
                        printf("\nIngrese nombre:");
                        fflush(stdin);
                        gets(nombre[i]);
                        printf("\nIngrese apellido:");
                        fflush(stdin);
                        gets(apellido[i]);
                        /*
                        fgets(apellido[i],,);
                        cantidad=strlen(apellido[i]);
                        apellido[i][cantidad-1]=\0);
                        */
                        printf("\nIngrese edad:");
                        scanf("%d",&edad[i]);
                        printf("\nIngrese legajo:");
                        scanf("%d",&legajo[i]);

                        isEmpty[i]=0;
                        system("cls");
                    }
                    break;
            case 2:
                system("cls");
                for(i=0;i<CANT;i++)
                {
                    if(isEmpty[i]==0)
                    {
                        printf("\nNombre:%s Apellido:%s Edad:%d Legajo:%d\n",nombre[i],apellido[i],edad[i],legajo[i]);
                    }
                }
                printf("\nIngrese legajo a dar de baja:");
                scanf("%d",&legajoAux);
                flagLegajo=0;
                for(i=0;i<CANT;i++)
                {
                    if(legajoAux==legajo[i])
                    {
                        isEmpty[i]=1;
                        flagLegajo=1;
                    }
                }
                if(flagLegajo==0)
                {
                    printf("Legajo no encontrado");
                }
                break;
            case 3:
                system("cls");
                for(i=0;i<CANT;i++)
                {
                    if(isEmpty[i]==0)
                    {
                        printf("\nNombre:%s Apellido:%s Edad:%d Legajo:%d\n",nombre[i],apellido[i],edad[i],legajo[i]);
                    }
                }
                printf("\nIngrese legajo a modificar:");
                scanf("%d",&legajoAux);
                flagLegajo=0;
                for(i=0;i<CANT;i++)
                {
                    if(legajoAux==legajo[i])
                    {
                        printf("\nNombre:%s Apellido:%s Edad:%d Legajo:%d\n",nombre[i],apellido[i],edad[i],legajo[i]);
                        printf("Desea modificar este usuario?:S/N\n");
                        fflush(stdin);
                        scanf("%c",&rta);
                        while(rta=='S')
                        {
                            printf("\n1-Nombre");
                            printf("\n2-Apellido");
                            printf("\n3-Edad");
                            printf("\n4-Salir");
                            scanf("%d",&opcionMod);

                            switch(opcionMod)
                                {
                                    case 1:
                                        printf("\nIngrese nombre:");
                                        fflush(stdin);
                                        gets(nomAux);
                                        strcpy(nombre[i],nomAux);
                                        break;
                                    case 2:
                                        printf("\nIngrese apellido:");
                                        fflush(stdin);
                                        gets(apeAux);
                                        strcpy(apellido[i],apeAux);
                                        break;
                                    case 3:
                                        printf("\nIngrese edad:");
                                        scanf("%d",&edadAux);
                                        edad[i]=edadAux;
                                    case 4:
                                        rta='N';

                                }
                        }
                        flagLegajo=1;
                    }
                }

                if(flagLegajo==0)
                {
                    printf("\nLegajo no encontrado");
                }
                break;
            case 4:
                for(i=0;i<CANT;i++)
                {
                    for(j=i+1;j<CANT;j++)
                    {
                        if(strcmp(apellido[i],apellido[j])>0)
                        {
                            strcpy(nomAux, nombre[i]);
                            strcpy(nombre[i],nombre[j]);
                            strcpy(nombre[j],nomAux);

                            strcpy(apeAux, apellido[i]);
                            strcpy(apellido[i], apellido[j]);
                            strcpy(apellido[j], apeAux);

                            edadAux=edad[i];
                            edad[i]=edad[j];
                            edad[j]=edadAux;

                            legajoAux=legajo[i];
                            legajo[i]=legajo[j];
                            legajo[j]=legajoAux;

                            isEmptyAux=isEmpty[i];
                            isEmpty[i]=isEmpty[j];
                            isEmpty[j]=isEmptyAux;
                        }
                        else if(strcmp(apellido[i],apellido[j])==0 && strcmp(nombre[i],nombre[j])>0)
                        {
                            strcpy(nomAux, nombre[i]);
                            strcpy(nombre[i],nombre[j]);
                            strcpy(nombre[j],nomAux);

                            edadAux=edad[i];
                            edad[i]=edad[j];
                            edad[j]=edadAux;

                            legajoAux=legajo[i];
                            legajo[i]=legajo[j];
                            legajo[j]=legajoAux;

                            isEmptyAux=isEmpty[i];
                            isEmpty[i]=isEmpty[j];
                            isEmpty[j]=isEmptyAux;
                        }
                    }
                }
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }


    return 0;
}
