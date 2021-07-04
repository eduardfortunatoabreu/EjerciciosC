#include <stdio.h>


int main(void)
 {
     int suma = 5+5;
     int resta = 354-45-8;
    double divicion = 25/3;
    double multiplicacion = 78*85;
    double residuo = 3%2;




    printf("Mostrando el valor de una suma: %d \n",suma); 
    printf("Mostrando el valor de una resta: %d \n",resta); 
    printf("Mostrando el valor de una divicion: %lf \n",divicion); 
    printf("Mostrando el valor de una multiplicacion: %lf \n",multiplicacion);    
    printf("Mostrando el valor de una residuo: %lf \n",residuo);  

     printf("Mostrando un incremento de la suma: %d \n",++suma); 
     printf("Mostrando un descremento de la suma: %d \n",--suma);      
}