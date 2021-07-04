#include <stdio.h>
#include <string.h>




void OPeradores()
{
    char operador;            
    printf("Ingrese operador a identificar:\n");    
    scanf(" %c",&operador);

    if(strcmp(&operador,"+") == 0)
    {
        printf("Esto es una suma:\n");    
    }
    else if(strcmp(&operador,"-") == 0)
    {
        printf("Esto es una resta\n");    
    }
    else if(strcmp(&operador,"/") == 0)
    {
        printf("Esto es una divicion\n");    
    }
    else if(strcmp(&operador,"*") == 0)
    {
        printf("Esto es una multiplicacion\n");    
    }     
    else{
        printf("Esto no es un operador matematico\n");    
    }



    
}