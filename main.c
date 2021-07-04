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

//ARCHIVOS CON LAS OTRAS metodos
#include "validate.h"


#include "optiones.h"
#include "variables.h"
#include "constante.h"
#include "operators.h"
#include "aritmeticos.h"
#include "condicion.h"
#include "loops.h"
#include "arrays.h"
#include "stringvar.h"
#include "pointer.h"
#include "typede.h"
#include "estructura.h"





#ifdef __linux__
#define SO "Linux"
#elif _WIN32
#define SO "Windows"
#endif

//METODO PARA LIMPIAR LA PANTALLA
void ClearDisplay()
{
//VALIDANDO TIPO DE SISTEMAS OPERATIVOS PARA LIMPIAR LA PANTALLA
#ifdef SO
    //CUANDO ES UBUNTU
    system("clear");
#else
    //CUNADO ES WINDOWS
    system("cls");
#endif
}



//METODO PARA PAUSAR ANTES DE CERRAR EL SISTEMA
void pause()
{
    //VALIDANDO TIPO DE SISTEMAS OPERATIVOS PARA LIMPIAR LA PANTALLA
#ifdef SO
    //CUANDO ES UBUNTU
    printf("\nPresiones una tecla para continuar");
    __fpurge(stdin);
    getchar();
#else
//CUNADO ES WINDOWS
//system("pause");
#endif
}

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
