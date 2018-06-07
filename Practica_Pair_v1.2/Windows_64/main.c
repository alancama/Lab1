#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/


int main()
{
//creacion de lista
    ArrayList* lista;
    lista=al_newArrayList();
//Creacion de empleado
    Employee* e1;
    Employee* e2;
    Employee* eAux;
    e1=employee_new();
    e2=employee_new();
    int i;
//Asignacion
    e1->id=666;

    strcpy(e1->name,"Auan");
    strcpy(e1->lastName,"Gomez");
    e1->isEmpty=1;

    al_add(lista,e1);//Agrega al array de lista el empleado
    al_add(lista,e2);
    int espacioOcupado =al_len(lista);//Cantidad de espacio ocupado, devuelve el size
    printf("El espacio ocupado es:%d\n",espacioOcupado);
//Creo empleado auxiliar
    //Movido arriba
    //eAux=(Employee*)al_get(lista,0);//Obtiene elemento de la lista en posicion 0
//Imprimo el empleado de la posiciòn cero
    //employee_print(eAux);

    //Creo otro empleado y lo agrego a la lista
     //movido arriba
     e2->id=123;
     strcpy(e2->name,"Zulio");
     strcpy(e2->lastName,"Cortazar");
     e2->isEmpty=1;



/*
     for(i=0;i<espacioOcupado;i++)
     {
         eAux=(Employee*)al_get(lista,i);
         employee_print(eAux);
     }
*/
    //ORDENAR

    al_sort(lista,employee_compare,0);

    for(i=0;i<espacioOcupado;i++)
    {
         eAux=(Employee*)al_get(lista,i);
         employee_print(eAux);
    }

    return 0;
}
