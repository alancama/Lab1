#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* f;
    char mens[]="Hola a todos";


    f=fopen("mihtml.html","w");

    if(f!=NULL)
    {
        fprintf(f,"<html><head>");
        fprintf(f,mens);
        fprintf(f,"</html></head>");
        fclose(f);
    }

    return 0;
}
