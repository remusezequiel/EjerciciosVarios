#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "apoyo22.09.h"

//(1)FUNCION INICIALIZAR
/** \brief Esta funcion inicializa un array en 1
 *
 * \param 1
 * \return int inicializar(EPersona* array, int
 *
 */
int inicializar(EPersona* array, int cantidad)//(1)
{
    int retorno=0,i;//valor que retorna si esta todo mal
    if(array != NULL && cantidad>0)//Chequeo que entre un array
    {
        retorno=1;
        for(i=0;i<cantidad;i++)
        {
            array[i].isEmpty = 1;
        }
    }
    return retorno;
}
//(2)FUNCION GENERAR NEXT ID
/** \brief Esta funcion va generando numeros. Es como un contador pero que esta inicializado
 *          en -1. Cada vez que es llamado aumenta en 1. id es un static int cada vez que este
 *          es llamado este aumenta y el valor del id se guarda en id.
 * \return int
 *
 */
static int generarNextId()
{
    static int id = -1;
    id++;
    return id;
}
//(3)FUNCION ALTA PERSONA
/** \brief
 *
 * \param array EPersona*
 * \param indice int
 * \param cantidad int
 * \return int
 *
 */
int altaPersona(EPersona* array,int indice, int cantidad)//Poner EPersona* array == EPersona array[]
{
    //int indice = traerIndiceVacio(array,cantidad);
    EPersona auxPersona;
    int retorno = 0;

//Mientras no se ingrese nada cuando se pide el nombre, vuelve a pedirlo
        do
        {
            printf("Ingrese nombre:\n");
            fflush(stdin);
            gets(auxPersona.nombre);
        }while(strlen(auxPersona.nombre) == 0);
//Mientras no se ingrese nada cuando se pide el apellido, vuelve a pedirlo
        do
        {
            printf("Ingrese apellido:\n");
            fflush(stdin);
            gets(auxPersona.apellido);
        }while(strlen(auxPersona.apellido) == 0);
//Ingresa los datos de la fecha de nacimiento
        printf("Ingrese el dia de su nacimiento");
        fflush(stdin);
        scanf(" %d",&auxPersona.nacimiento.dia);
        printf("Ingrese el mes de su nacimiento");
        fflush(stdin);
        scanf(" %d",&auxPersona.nacimiento.mes);
        printf("Ingrese el año de su nacimiento");
        fflush(stdin);
        scanf(" %d",&auxPersona.nacimiento.anio);

//Le doy el valor 0 a la variable isEmpty. Esto nos deja saber que esta dado
//de alta
        auxPersona.isEmpty =0;

    /// IMPORTANT
    auxPersona.id = generarNextId();
    auxPersona.isEmpty = 0;
    array[indice] = auxPersona;

    return retorno;
}
//(4)FUNCION TRAER INDICE VACIO
/** \brief
 *
 * \param array EPersona*
 * \param cantidad int
 * \return int
 *
 */
int traerIndiceVacio(EPersona* array, int cantidad)
{
    int retorno = -1;
    int i;
    if(array != NULL && cantidad > 0)
    {
        for(i=0;i<cantidad;i++)
        {
            if(array[i].isEmpty)
            {
                retorno=1;
                break;
            }
        }
    }
    return retorno;
}
//(5)FUNCION SELECCIONAR UN ID
/** \brief Esta funcion busca un id de alguna persona ingresada
 *
 * \param array EPersona*
 * \param cantidad int
 * \param id int
 * \return int
 *
 */
int getById(EPersona* array, int cantidad, int id)
{
    //FUNCION QUE BUSCA EN CUAL INDIDE SE ENCUENTRA LA PERSONA
    //CON id=idABuscar
    /*ALGORITMO:
            (1)Pedir el id y leerlo
            (2)recorrer la lista de arrays
            (3)cuando el id de la lista sea igual al id ingresado
            entonces mostrar los datos por pantalla
    */
    int retorno = -1;
    int i;

    if(array != NULL && cantidad>0)
    {
        for(i=0;i<cantidad;i++)
        {
            if(array[i].id == id)
            {
                retorno = i;
                break;
            }
        }

    }
    return retorno;
}
