#include <stdio.h>
#include <stdlib.h>

int main()
{
    //punteros
    int *punteroNumero;
    int numero;
    int numeroDos;
    numeroDos=&numero;
    numero=66;
    punteroNumero=&numero;//(*)
    printf("\n a- %d",numeroDos);//direccion
    //*punteroNumero=&numero;
    //*punteroNumero=55;
    numeroDos=*punteroNumero;
    printf(" b- %d\n",numeroDos);

    printf("%d\n",numero);//valor de numero
    printf("%d\n",numeroDos);
    printf("%d\n",&numero);//le pasamos donde empieza el elemento(*) sino se tilda
    printf("%p\n",punteroNumero);//direccion donde empieza el puntero
    printf("%p\n",&punteroNumero);//direccion donde esta guardado el puntero
    printf("%d",*punteroNumero);//muestra el contenido del puntero, puede dar error si inicialo el puntero y no le doy ningun valor o tomar un null

    return 0;
}
