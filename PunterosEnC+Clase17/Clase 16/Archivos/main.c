#include <stdio.h>
#include <stdlib.h>

int main()
{
    //1.Abrir archivo
    //2.Obtener datos y escribir datos
    //3.Cerrar archivo
    //Para manipular archivos se usa FILE.
    //Puede guardar archivos tipo texto o de bloques de inf(enteros, char, incluso estructuras) estos se llaman binarios.
    FILE *fp;//Este puntero apunta al archivo

    char buffer[100]="Esto es un texto dentro del fichero";//Ejemplo
    char bufferIn[100];

    fp=fopen("D:\\clase17\\fichero.txt","w");//1)Donde esta el fichero(sino se pone nada se crear el archivo en la carpeta del proyecto) y para que lo quiero(w=write, r=read).

    fprintf(fp, buffer);//2)A que archivo y que texto quiero pasar.


    fclose(fp);//3)Cierro el archivo.

    system("pause");
    system("cls");
    //Leer

    fp=fopen("D:\\clase17\\fichero.txt", "r");

    if(fp==NULL)
    {
        printf("Archivo no encontrado");
    }
    else
    {
        while(!feof(fp))
        {
            fgets(bufferIn,100,fp);//Lo que pongo en el lugar de fp, lo guarda en el lugar del bufferIn, y en medio va el tamaño de este bufferIn
            puts(bufferIn);
        }
    }

    return 0;
}
