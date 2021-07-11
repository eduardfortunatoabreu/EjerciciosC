



void variables()
{
    int Entero;
    float Flotante;
    double Double;
    char CadenaCaracteresilimitado[10];    
    long Long;


    printf("Vamos a obtener los valores para las variables\n");
    printf("Ingrese un numero entero ejemplo: \"1 , 2 , 8, 6, ...\" \n");
    scanf("%d", &Entero);       
    printf("\n");
    


    printf("Ingrese un numero flotante ejemplo: \"1.54 , 0.5, 475.44, ...\" \n");
    scanf("%f", &Flotante);       
    printf("\n");


    printf("Ingrese un numero double ejemplo: \"1.54454 , 0.4455, 47.54544744, ...\" \n");
    scanf("%lf", &Double);       
    printf("\n");


 
   

    printf("Ingrese una linea de caractere limitado de 10 posiciones\n");
    scanf("%s", CadenaCaracteresilimitado);       
    printf("\n");



    printf("Estos son los datos ingresados\n");
    printf("\n");
    printf("Entero %d\n",Entero);    
    printf("Flotante %f\n",Flotante);
    printf("Double %lf\n",Double); 
    printf("Caracter "); 

    for(int i =0;i<strlen(CadenaCaracteresilimitado);i++)
    {
        printf("%c",CadenaCaracteresilimitado[i]);    
    }  
    printf("\n"); 

       
}







