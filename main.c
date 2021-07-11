//PARA ENTRADA Y SALIDA DE DATOS
#include <stdio.h>
//PARA DE IDENTIFICAR SISTEMAS OPERATIVOS
#include <stdlib.h>
//PARA USAR LA LIBRERIA DE ISDIGI
#include <ctype.h>
//PRA USAR VARIABLE TIPOS BOOLEANAS
#include <stdbool.h>
//VARIABLE DE STRING
#include <string.h>
//PARA USAR PURGE Y LIMPIAR EL BUFER
#include <stdio_ext.h>

//MACRO PARA IDENTIFICAR EL SISTEMA OPERATIVO

#ifdef __linux__
#define SO "Linux"
#elif _WIN32
#define SO "Windows"
#endif


//ARCHIVOS CON LAS OTRAS metodos
#include "Headers/validate.h"
#include "Headers/optiones.h"
#include "Headers/variables.h"
#include "Headers/constante.h"
#include "Headers/operators.h"
#include "Headers/aritmeticos.h"
#include "Headers/condicion.h"
#include "Headers/loops.h"
#include "Headers/arrays.h"
#include "Headers/stringvar.h"
#include "Headers/pointer.h"
#include "Headers/typede.h"
#include "Headers/estructura.h"
#include "Headers/datosClientes.h"

//HEADER PARA DECLARAR LOS METODOS
#include "Interfaces/InterfaceEjercicio.h"




//MENU DE OPCIONES
void Menu(int Opcion)
{    

    ClearDisplay();    
    
    switch (Opcion) {
        case 1:     
                 
            variables(); 
            pause();                    
            break;
        case 2:
            Constante();                                          
            pause();
            break;
        case 3:
            OPeradores(); 
            pause();
            break;
        case 4:
            Comparacion(); 
            pause();
            break;            
        case 5:
            Bucle(); 
            pause();
            break;
        case 6:
            arreglos(); 
            pause();
            break;  
        case 7:
            VariableString(); 
            pause();
            break;                        
        case 8:
            DireccionMemoria(); 
            pause();
            break; 
        case 9:
            tipo(); 
            pause();
            break;             
        case 10:
            estructuras(); 
            pause();
            break;
        case 11:            
            //ConsultarDatos();
            DatosClientes();
            pause();
            break;
        default:
            printf("ESta no es una opcion del menu");   
            pause();
            break;        
    }  

    ShowOptions();  
    
}





//METODO PRINCIPAL
int main(void)
{

    //LIMPIAR TODA LA PANTALLA
    ClearDisplay();

    ShowOptions();

    //VARIABLE PARA ALMACENAR LA OPCION DEL MENU
    char Option[3];

    while (true)
    {
        printf("*----->   ");
        //PARA ASIGNARLE UN VALOR A LA VARIABLE LE PASAMOS LA DIRECCION CON EL SIMBOLO &
        scanf("%s", Option);

        if (ValidateNumber(Option) == 1)
        {
            //FUNCION ATOI PARA CONVERTIR TEXTO EN NUMERO
            if (atoi(Option) == 0)
            {
                ClearDisplay();
                break;
            }
            else
            {
                Menu(atoi(Option));                
            }
        }
        else
        {
            printf("Please Select your option\n");
        }
    }

    return 0;
}


//gcc main.c -ljson-c -o main para copilar usando la libreria json 