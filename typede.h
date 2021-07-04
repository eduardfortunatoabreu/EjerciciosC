//ENUMAERADOR ES IGUAL QUE EL MODELO EN ANGULAR 
enum dias {
    lunes = 1,  
    martes,
    miercoles,
    jueves,
    viernes,
    sabado,
    domingo
};

//RENOMBRAMOS EL NOMBRE DEL ENUMAERADOR
typedef enum dias Diasemana;

//RENOMBRAMOS EL INT POR ENTERO
typedef int entero;


void tipo()
{

    Diasemana datos;
    datos = viernes;
    
    printf("%d\n",datos); 


    entero var = 1;    
    printf("%d\n",var); 

       
}





