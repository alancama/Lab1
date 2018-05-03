#ifndef ESTRUCTURAGENERICA_H_INCLUDED
#define ESTRUCTURAGENERICA_H_INCLUDED
typedef struct
{
    char nombre[50];
    //------------
    int idUsuario;
    int estado;
}eUsuario;

typedef struct
{
    int idProducto;
    int idUsuario;
    char nombreProducto[50];
    int precio;
    int stock;
    int cantidadVendida;
    int estado;
}eProducto;

typedef struct
{
    int idVenta;
    int idProducto;
    int calificacion;
    int idUsuarioComprador;
}eVenta;
#endif // ESTRUCTURAGENERICA_H_INCLUDED

int eUser_init(eUsuario[],int limite);
int eUser_buscarPorId(eUsuario[] ,int limite, int id);
int eUser_siguienteId(eUsuario[] ,int limite);
int eUser_buscarLugarLibre(eUsuario listado[],int limite);

int eUser_mostrarUno(eUsuario parametro);
int eUser_mostrarListado(eUsuario[] ,int limite);
int eUser_mostrarListadoConBorrados(eUsuario[] ,int limite);

int eUser_alta(eUsuario[] ,int limite);
int eUser_baja(eUsuario[] ,int limite);
int eUser_modificacion(eUsuario[] ,int limite);

int eUser_ordenar(eUsuario[] ,int limite, int orden);


int publicarProducto(eUsuario[],int limiteUsuario, eProducto[], int limiteProducto);
