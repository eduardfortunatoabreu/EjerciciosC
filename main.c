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

#include "variables.h"
#include "constante.h"
#include "operators.h"






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
        system("clear");
    #endif
}





//VER LAS OPCIONES
void ShowOptions()
{

    printf("\n\n\n*******************************************************************************\n");     
        printf("*********************************** Welcome ***********************************\n"); 
        printf("*******************************************************************************\n");     
        printf("*                           Selected your option                              *\n");     
        printf("*                                                                             *\n");          
        printf("*       1 -> Variables and type                                               *\n");          
        printf("*       2 -> Contants                                                         *\n");          
        printf("*       3 -> Operators                                                        *\n");          
        printf("*       4 -> Conditionals                                                     *\n");          
        printf("*       5 -> Loops                                                            *\n");          
        printf("*       6 -> Arrays                                                           *\n");          
        printf("*       7 -> String                                                           *\n");  
        printf("*       8 -> Pointers                                                         *\n"); 
        printf("*       9 -> Functions                                                        *\n"); 
        printf("*       0 -> Exit                                                             *\n"); 
        printf("*                                                                             *\n");   
        printf("*******************************************************************************\n");   
}





//METODO PARA PAUSAR ANTES DE CERRAR EL SISTEMA
void pause()
{
        //VALIDANDO TIPO DE SISTEMAS OPERATIVOS PARA LIMPIAR LA PANTALLA
    #ifdef SO
    //CUANDO ES UBUNTU
    getchar();
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
        default:
            printf("ESta no es una opcion del menu");   
            pause();
            break;        
    }  

    ShowOptions();  
    
}




//VALIDACION DE NUMERO
bool ValidateNumber(char numero[])
{    
    for(int i = 0;i<strlen(numero);i++)
    {
        if(!isdigit(numero[i]))
        {
            printf("Only number\n");
            return false;
        }

    }

    return true;
}






int main(void)
 {

          //LIMPIAR TODA LA PANTALLA
        ClearDisplay();

    ShowOptions();
        
    //VARIABLE PARA ALMACENAR LA OPCION DEL MENU
    char Option[3];    
            
    while(true)
    {   
        printf("*----->   ");                    
        //PARA ASIGNARLE UN VALOR A LA VARIABLE LE PASAMOS LA DIRECCION CON EL SIMBOLO &
        scanf("%s", Option);        

        if(ValidateNumber(Option) == 1)
        {
            //FUNCION ATOI PARA CONVERTIR TEXTO EN NUMERO
            if(atoi(Option) == 0)
            {  
                pause();   
                ClearDisplay();               
                break;
            }
            else
            {
                Menu(atoi(Option));
                //break;
            }
        }
        else
        {
            printf("Please Select your option\n");
        }
    }

    return 0;
             
}


