#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int a;//4 en 64, 2 en 32
    char b;//1
}dato;

int main()
{
    /*dato d;
    d.a=5;
    d.b='<';

    dato* pDato;
    pDato = &d;

    printf("%d--%d\n",&d,&d.a);


    //printf("TAM: %d\n", sizeof(dato));

    //printf("%d--%c",(*pDato).a,(*pDato).b);
    printf("%d--%c",pDato->a, pDato->b);*/
    dato l[2]={{1, 'a'},{1,'b'}};
    dato *pLista;

    pLista=l;

    int i;
    for(i=0;i<2;i++)
    {
        printf("%d--%c\n",(*(pLista+i)).a,(*(pLista+i)).b);
        printf("%d--%c\n",(pLista+i)->a,(pLista+i)->b);
    }


    return 0;
}
