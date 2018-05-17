#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>


typedef struct
{
    int ID;
    char NombreCompleto[100];
    char Direccion[100];
    char Tarjeta[100];
    int Estado;

}EPersona;

typedef struct
{
    int Lugar;
    char Patente[100];
    int Marca;
    int Propietario;
    int Estado;

}EAuto;

typedef struct
{
    int Cont;
    char Patente[100];
    int Marca;
    int Propietario;
    int Tiempo;
    int Monto;
    int Estado;

}EOutput;


/** \brief Function: Muestra el menu por pantalla y captura la opcion seleccionada.
*   \param Request: NULL.
*   \return Returns: Opcion elegida.
*/ int Menu(void);


/** \brief Function: Inicializa la estructura seleccionada en 0.
*   \param Request: Array de la estructura Persona.
*   \return NULL.
*/ void inicializarPropietarios(EPersona Persona[],int valor);


/** \brief Function: Inicializa la estructura seleccionada en 0.
*   \param Request: Array de la estructura Auto.
*   \return NULL.
*/ void inicializarAutos(EAuto Auto[],int valor);

/** \brief Function: Inicializa la estructura seleccionada en 0.
*   \param Request: Array de la estructura Output.
*   \return NULL.
*/void inicializarOutput(EOutput Output[],int valor);


/** \brief Function: Lista un array de la estructura Persona.
*   \param Request: Array de la estructura Persona.
*   \return 1 Si hay Propietarios, 0 si no los hay.
*/ int listarPropietarios(EPersona Persona[],int valor);


/** \brief Function: Lista un array de la estructura Auto.
*   \param Request: Array de la estructura Auto.
*   \param Request: Array de la estructura Persona.
*   \return 1 Si hay autos, 0 si no los hay.
*/ int listarAutos(EAuto Auto[],EPersona Persona[],int valor);

/** \brief Function: Lista un array de la estructura Auto.
*   \param Request: Array de la estructura Auto.
*   \param Request: Array de la estructura Persona.
*   \return 1 Si hay propietarios de audi, 0 si no los hay.
*/ int listarPropietariosAudi(EPersona Persona[],EAuto Auto[],int valor);

/** \brief Function: Lista un array de la estructura Auto.
*   \param Request: Array de la estructura Output.
*   \param Request: Array de la estructura Persona.
*   \return 1 Si hay autos, 0 si no los hay.
*/ int recaudacionTotal(EOutput Output[],EPersona Persona[],int valor,int out);


/** \brief Function: Lista un array de la estructura Auto pero solo los elementos con la marca seleccionada.
*   \param Request: Array de la estructura Output.
*   \param Request: Array de la estructura Persona.
*   \return 1 Si hay autos, 0 si no los hay.
*/ int recaudacionPorMarca(EOutput Output[],EPersona Persona[],int valor,int out);


/** \brief Obtiene el primer indice libre del array Persona.
 *  \param Request: Estructura Persona.
 *  \param Request: valor maximo de la estructura Persona.
 *  \return Returns: el primer indice disponible.
 */ int obtenerEspacioPersona(EPersona Persona[],int valor);


/** \brief Obtiene el primer indice libre del array Persona.
 *  \param Request: Estructura Auto.
 *  \param Request: valor maximo de la estructura Auto.
 *  \return Returns: el primer indice disponible.
 */ int obtenerEspacioAuto(EAuto Auto[],int valor);

 /** \brief Obtiene el primer indice libre del array Persona.
 *  \param Request: Estructura Auto.
 *  \param Request: valor maximo de la estructura Auto.
 *  \return Returns: el primer indice disponible.
 */ int obtenerEspacioOutput(EOutput Output[],int valor);

/** \brief Obtiene el indice que coincide con el ID pasado por parametro.
 *  @param Request: Array de la estructura Persona.
 *  @param Request: ID a ser buscado en el array.
 *  @param Request: valor maximo de la estructura Persona
 *  @return Returns: el indice en donde se encuentra el elemento que coincide con el parametro ID
 */ int buscarPorID(EPersona persona[],int id,int valor);

 /** \brief Obtiene el indice que coincide con la patente pasado por parametro.
 *  @param Request: Array de la estructura Auto.
 *  @param Request: Patente a ser buscada en el array.
 *  @param Request: valor maximo de la estructura Auto.
 *  @return Returns: el indice en donde se encuentra el elemento que coincide con el parametro Patente.
 */ int buscarPorPatente(EAuto Auto[],char patente[],int valor);

 /** \brief Analiza un string para verificar que no este vacio.
 *  \param  Request: Cadena a analizar.
 *  \return Returns: 1 si la cadena tiene al menos una letra o un numero. 0 si esta vacio.
 */int noVoid(char str[]);

/** \brief Muestra un mensaje y pide al usuario ingresar un string.
 *  \param  Request: mensaje a ser mostrado.
 *  \param  Request: cadena en la que el usuario va a escribir.
 *  \return Returns: NULL.
 */ void getString(char mensaje[],char input[]);


/** \brief Muestra un mensaje, pide al usuario un string y despues valida que solo contenga letras.
 *  \param  Request: mensaje a ser mostrado.
 *  \param  Request: cadena en la que el usuario va a escribir.
 *  \return Returns: 1 si esta todo validado, sino devuelve 0.
 *
 */ int getStringLetras(char mensaje[],char input[]);


/** \brief Muestra un mensaje, pide al usuario un string y despues valida que solo contenga numeros.
 *  \param  Request: mensaje a ser mostrado.
 *  \param  Request: cadena en la que el usuario va a escribir.
 *  \return Returns: 1 si esta todo validado, sino devuelve 0.
 */ int getStringNumeros(char mensaje[],char input[]);


/** \brief Pide un string y valida que contenga solo letras.
 *  \param  Request: cadena que va a ser validada.
 *  \return Returns: 0 si la cadena tiene numero, sino devuelve 1.
 */ int esSoloLetras(char str[]);


/** \brief Pide un string y valida que contenga solo numeros.
 *  \param  Request: cadena que va a ser validada.
 *  \return Returns: 0 si la cadena tiene letras, sino devuelve 1.
 */ int esNumerico(char str[]);


/**
 * \brief Verifica si el valor recibido contiene solo letras y números.
 * \param str Array con la cadena a ser analizada.
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es.
 */ int esAlfaNumerico(char str[]);


/** \brief Pide un string y valida que contenga solo letras o numeros.
 *  \param  Request: Mensaje a mostrar.
 *  \param  Request: Cadena que va a ser validada.
 *  \return Returns: 0 si la cadena tiene simbolos, sino devuelve 1.
 */ int getStringAlfaNumerico(char mensaje[],char input[]);

/** \brief Ordena los nombres de A-Z.
 *  \param  Request: estructura Persona.
 *  \param  Request: el valor maximo de la estructura Persona.
 *  \return Returns: NULL.
 */ void ordenarNombre(EPersona persona[],int valor);

/** \brief Ordena las patentes de A-Z.
 *  \param  Request: estructura Auto.
 *  \param  Request: el valor maximo de la estructura Persona.
 *  \return Returns: NULL.
 */ void ordenarPatente(EAuto Auto[],int valor);

/** \brief Transfiere los valores auxiliares a la estructura Persona y le asigna un ID autoincremental.
 *  \param  Request: estructura Persona.
 *  \param  Request: tarjeta auxiliar.
 *  \param  Request: direccion auxiliar.
 *  \param  Request: nombre auxiliar.
 *  \param  Request: indice libre de la estructura.
 *  \return Returns: NULL.
 */ void transferirEstructuraPersona(EPersona Persona[],char nombre[],char tarjeta[],char direccion[],int libre);

/** \brief Transfiere los valores auxiliares a la estructura Auto y le asigna un ID autoincremental.
 *  \param  Request: estructura Persona.
 *  \param  Request: estructura Auto.
 *  \param  Request: tarjeta auxiliar.
 *  \param  Request: direccion auxiliar.
 *  \param  Request: nombre auxiliar.
 *  \param  Request: indice libre de la estructura.
 *  \return Returns: NULL.
 */ void transferirEstructuraAuto(EAuto Auto[],EPersona Persona[],char patente[],int marca,int propietario,int libre,int valor);

 /** \brief Transfiere los valores auxiliares a la estructura Output.
 *  \param  Request: estructura Persona.
 *  \param  Request: estructura Auto.
 *  \param  Request: estructura Output.
 *  \param  Request: lugar auxiliar.
 *  \param  Request: tiempo auxiliar.
 *  \param  Request: nombre auxiliar.
 *  \param  Request: indice libre de la estructura.
 *  \return Returns: NULL.
 */ void egresoAuto(EAuto Auto[],EPersona Persona[],EOutput Output[],int lugar,int tiempo,int libre);

 /** \brief Menu para listar los elementos de los arrays de las estructuras.
 *  \param  Request: Array estructura Persona.
 *  \param  Request: Array estructura Auto.
 *  \param  Request: Valor maximo de los arrays.
 *  \return Returns: NULL.
 */ void listas(EPersona Persona[], EAuto Auto[], int valor);

/** \brief Menu para listar las recaudaciones.
 *  \param  Request: Array estructura Persona.
 *  \param  Request: Array estructura Auto.
 *  \param  Request: Array estructura Output.
 *  \param  Request: Valor maximo de los arrays.
 *  \return Returns: NULL.
 */  void recaudaciones(EPersona Persona[], EAuto Auto[],EOutput Output[],int valor,int out);

/** \brief Muestra la lista de autos de un socio especifico.
 *  \param  Request: Array estructura Persona.
 *  \param  Request: Array estructura Auto.
 *  \param  Request: Valor maximo de los arrays.
 *  \return Returns: NULL.
 */  void informarSocio(EPersona Persona[],EAuto Auto[],int valor);

 /** \brief Muestra la lista de autos de un socio especifico.
 *  \param  Request: Array estructura Persona.
 *  \param  Request: Array estructura Auto.
 *  \param  Request: Valor maximo de los arrays.
 *  \param  Request: Indice del array donde se encuentra el socio que se busca.
 *  \return Returns: NULL.
 */  int poseeAutos(EPersona Persona[],EAuto Auto[],int valor,int indice);

/** \brief Transfiere los datos hardcodeados al array de la estructura.
 *  \param  Request: estructura persona.
 *  \return Returns: NULL.
 */ void hardCodeProp(EPersona Persona[]);

/** \brief Transfiere los datos hardcodeados al array de la estructura.
 *  \param  Request: estructura Auto.
 *  \return Returns: NULL.
 */ void hardCodeAuto(EAuto Auto[]);

 /** \brief Transfiere los datos hardcodeados al array de la estructura.
 *  \param  Request: estructura Output.
 *  \return Returns: NULL.
 */ void hardCodeOutput(EOutput Output[]);

/** \brief Devuelve un numero entero RANDOM.
 *  \param  Request: NULL.
 *  \return Returns: Un numero entero.
 */ int devolverHorasEstadia(void);



#endif // FUNCIONES_H_INCLUDED
