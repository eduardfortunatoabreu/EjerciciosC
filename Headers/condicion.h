


void Comparacion()
{
    int A,B;


    printf("Ingrese un numero entero para comparar\n");    
    scanf("%d", &A);       
    printf("\n");

    printf("Ingrese segundo numero entero para comparar\n");    
    scanf("%d", &B);       
    printf("\n");



    if(A == B)
    {        
        printf(" EL PRIMER NUMERO ES IGUAL AL SEGUNDO");   
    }
    else if(&A < &B)
    {
        printf("EL PRIMER NUMERO ES MENOR AL SEGUNDO ");   
    }
    else if(&A > &B)
    {
        printf("EL PRIMER NUMERO ES MAYOR AL SEGUNDO");   
    }
}


