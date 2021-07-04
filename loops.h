

void Bucle()
{
    char variable[20];


    printf("Ingrese Una palabra para recorrer\n");    
    scanf("%s",variable);


    printf("Su palabra es: \n\n");    
    for(int i =0;i<strlen(variable);i++)
    {
        printf("%c\n",variable[i]); 
    }
    


    
}