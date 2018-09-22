//IMPORTE DE LIBRERIAS//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "apoyo22.09.h"

#define LEN 100     //Letras
#define CHARLEN 100 //Nombres

/*************CLASE*DE*APOmiPersona*22*09************************************************************************
    (1) Estructuras->sirven para no usar arrays paralelos
        Es un conjunto de variables de distinto tipo a la cual se hace referencia bajo un mismo nombre
    (2) La forma de acceder a los campos es mediante el operador punto "."
    (3) Los campos de una estructura se manejan de la misma manera que las variables sueltas
    El tipo definido que este definido adentro de otro tipo de dato tiene que estar definida por ensima
    de la cual necesita usar ese tipo
    (4) Asignacion-> se puede realizae la asignacion de una estructura a otra siempre y cuando las 2
    estructuras tengan el mismo formato
    (5) Comparacion-> no es posible realizar comparaciones entre 2 estructuras. Lo que se hace es
    comparar los campos del mismo tipo entre 2 estructuras
    (6) Los vectores de estructura se manejas ingual que los vectores de las variables que conocemos
    para cargar dicho vector hay que situarse en cada uno de los elementos del vector y recien ahi
    cargar loscampos de la estructura
    (7)
*********************************************************************************************************/
/**************************Ejercicio**********************************************************************
EPersona -> id; nombre; apellido; nacionalidad; isEmpty
EFecha   -> dia; mes anio
Hacer una funciones a hacer
void inicializar(EPersona* array, int cantidad);// Inicializar el isEmpty con -1
int altaPersona(Epersona* array,int indice, int cantidad);

lucianavarela@hotmail.es
*********************************************************************************************************/

/*--------------PROTOTIPOS------------------------------------------------------------------------------*/
int getById(EPersona* array, int cantidad, int id);
/*------------------------------------------------------------------------------------------------------*/

/*-------------FUNCION*PRINCIPAL------------------------------------------------------------------------*/
int main()
{
    system("color 1F");
    /*EJEMPLO*1
    EPersona miPersona;
    //ASIGNO VALORES A MIPERSONA = 0
    miPersona.id = 0;
    strcpy(miPersona.nombre,"Ezequiel");
    strcpy(miPersona.apellido,"Remus");
    miPersona.isEmpty = 0;
    miPersona.nacimiento.dia = 3;//cntr+d -> Duplica lo que esta escrito en la linea que esta parado
    miPersona.nacimiento.mes = 9;
    miPersona.nacimiento.anio = 1990;
    //ESCRIBO EN PANTALLA LOS DATOS ASIGNADOS
    printf("Persona %d:\n Nombre%s\nApellido%s\n(-Fecha: %d/%d/%d)\n",
           miPersona.id, miPersona.nombre, miPersona.apellido,
           miPersona.nacimiento.dia, miPersona.nacimiento.mes,
           miPersona.nacimiento.anio);
    system("pause");
    --------------------------------------------*/
/*************EJERCICIO**********************************************************************************/


/*............VARIABLES.................................................................................*/
    EPersona arrayPersonas[LEN];
    int i, indice, idPersona;
/*......................................................................................................*/
    if(!inicializar(arrayPersonas,LEN))//¿Para que sirve esto?
    {
        printf("ERROR!");
    }
/*
    indice = traerIndiceVacio(arrayPersonas, LEN);
    if(indice>-1)
    {
        altaPersona(arrayPersonas,0,LEN);
    }
    else
    {
        printf("NO HAY ESPACIO!!!\n");
    }
*/
    altaPersona(arrayPersonas,0,LEN);//

    printf("ingrese su id:\n");
    fflush(stdin);
    scanf(" %d",&idPersona);

    indice = getById(arrayPersonas,LEN, idPersona);

    for(i=0;i<LEN;i++)
    {
        if(!arrayPersonas[i].isEmpty)
        {
             printf("Persona %d:\n Nombre%s\nApellido%s\n(-Fecha: %d/%d/%d)\n",
                    arrayPersonas[i].id, arrayPersonas[i].nombre, arrayPersonas[i].apellido,
                    arrayPersonas[i].nacimiento.dia, arrayPersonas[i].nacimiento.mes,
                    arrayPersonas[i].nacimiento.anio);
        }
    }
    return 0;
}
/*--------------FIN*FUNCION*PRINCIPAL------------------------------------------------------------------*/

/*--------------FUNCIONES------------------------------------------------------------------------------*/

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
