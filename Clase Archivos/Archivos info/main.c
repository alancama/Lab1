#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int a;
    char b;
}eDato;
int main()
{
    FILE *pArchivo;
    char cadena[50]="hola";
    int numero=64;
    int numerin;
    int lista[5];
    eDato d={1,'a'};
    //pArchivo= fopen("archivo.txt", "w");
    //pArchivo= fopen("archivo.txt", "r");
    //pArchivo= fopen("archivo.txt", "w");
    //pArchivo= fopen("archivo.txt", "r");
    //pArchivo=fopen("miBinario.bin","wb");
    //pArchivo=fopen("miBinario.bin","rb");
    /*
    if(pArchivo!=NULL)
    {
        fprintf(pArchivo,"%s %d",cadena,156);
        fclose(pArchivo);
        printf("Guardado!");
    }
    else
    {
        printf("Imposible guardar");
    }*/

    /*pArchivo=fopen("archivo.txt","r");

    if(pArchivo!=NULL)
    {
        //sin el while solo lee la primer linea
        while(!feof(pArchivo))//Mientras no sea el feof(final del archivo)
        {
            fgets(cadena,50,pArchivo);
            puts(cadena);
        }
        fclose(pArchivo);
    }*/
    /*
    fwrite(&numero,sizeof(int),1,pArchivo);//(origen,tamaño del archivo(depende de arquitectura),cantidad de datos a pasar,destino)
    fclose(pArchivo);*/
    /*fread(&numero,sizeof(int),1,pArchivo);
    fclose(pArchivo);

    printf("Numero: %d", numero);*/
    int i;
    /*
    for(i=0;i<5;i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d",&numerin);

        fwrite(&numerin,sizeof(int),1,pArchivo);
    }

    fclose(pArchivo);*/

    /*while(!feof(pArchivo))
    {
        fread(&numerin,sizeof(int),1,pArchivo);
        //fread(&lista[i],sizeof(int),1,pArchivo);
        if(feof(pArchivo))
        {
            break;
        }

        printf("%d\n",numerin);
        i++;
    }
    /*for(i=0;i<5;i++)
    {
        printf("%d",lista[i]);
    }
    fclose(pArchivo);*/


    /*if(pArchivo!=NULL)
    {
        fwrite(&d,sizeof(eDato),1,pArchivo);
        fclose(pArchivo);
    }*/
    /*if(pArchivo!=NULL)
    {
        fread(&d,sizeof(eDato),1,pArchivo);

        printf("%d--%c", d.a, d.b);
        fclose(pArchivo);
    }*/




    //
    return 0;
}
