/************************TIPOS*DE*DATOS*******************************************************************/
/*(1)*/ typedef struct//(1)Tipo de dato EFecha
        {
            int dia;
            int mes;
            int anio;
        }EFecha;

/*(2)*/ typedef struct//(2)Tipo de dato EPersona
        {
            int id;
            char nombre[100];
            char apellido[100];
            EFecha nacimiento;
            int isEmpty;
        }EPersona;
/**********************************************************************************************************/

/************************PROTOTIPOS************************************************************************/
int inicializar(EPersona* array, int indice);
static int generarNextId();
int altaPersona(EPersona* array,int indice, int cantidad);
int traerIndiceVacio(EPersona* array, int cantidad);
int getById(EPersona* array, int cantidad, int id);
/**********************************************************************************************************/



