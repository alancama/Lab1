#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

typedef struct
{
    int idUsuario;
    char nombreUsuario[50];
}eUsuario;

ingresarUsuario(eUsuario nombreUsuario[], int idUsuario);

#endif // USUARIO_H_INCLUDED
