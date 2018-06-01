#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char nombre[50];
}ePersona;

//Getters/Setter
//Setters permiten asignar datos
int ePersona_setId(ePersona*,int);
int ePersona_setNombre(ePersona*,char*);
//Getters permiten obtener datos
int ePersona_getId(ePersona*);
char* ePersona_getNombre(ePersona*);

ePersona* newPersona();

int main()
{
    ePersona* pPersona;
    printf("%p\n",pPersona);//devuelve basura, del stack
    //pPersona=(ePersona*) malloc(sizeof(ePersona));//reserva dinamica de memoria, devuelve un puntero a void y recibe un tamaño, en este caso tamaño de estructura.
    pPersona=newPersona();
    ePersona* otro = newPersona();
    printf("%p\n",pPersona);//devuelve una direccion de memoria distinta cada vez

    if(pPersona!=NULL)//malloc devuelve null si no encontro espacio
    {
        if(ePersona_setId(pPersona, 45)==-1)
        {
            printf("Error id incorrecto");
        }
        else
        {
            if(ePersona_setNombre(pPersona,"Juan")==-1)
            {
                printf("Error nombre incorrecto");
            }
            else
            {
                printf("%d--%s", ePersona_getId(pPersona), ePersona_getNombre(pPersona));
            }
        }

    }



    return 0;
}


int ePersona_setId(ePersona* this,int id)
{
    int ret=-1;
    if(id>0 && this!=NULL)
    {
        this->id = id;
        ret=1;
    }

    return ret;
}

int ePersona_setNombre(ePersona* this,char* nombre)
{
    int ret=-1;
    if(this!=NULL && nombre!=NULL && (strlen(nombre)>3))
    {
        ret=1;
        strcpy(this->nombre,nombre);
    }

    return ret;
}

int ePersona_getId(ePersona* this)
{
    int ret =-1;
    if(this!=NULL)
    {
        ret = this->id;
    }
    return ret;
}

char* ePersona_getNombre(ePersona* this)
{
    char* ret=NULL;
    if(this!=NULL)
    {
        ret = this->nombre;
    }
    return ret;
}

ePersona* newPersona()
{
    ePersona* pAux;
    pAux=(ePersona*) malloc(sizeof(ePersona));
    return pAux;
}
