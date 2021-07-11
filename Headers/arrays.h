



void arreglos()
{

    char *dia[] = {"Domingo","Lunes","Martes","Miercoles","Jueves","Viernes","Sabado"};
    int DiaSelect;
    int arr[3][3];
    int fila = 0,columna = 0;

    printf("Seleccione un numero del 1 al 7 para ver el dia de la semana\n");
    scanf("%d", &DiaSelect); 


    for(int i =0;i<3;i++)
    {                     
        for(int j =0;j<3;j++)
        {
            arr[i][j] = i+1;            
        }
    }
    


    printf("Contenido del arreglo de dos dimensiones \n");  
    for(int a =0;a<3;a++)
    {
        for(int b =0;b<3;b++)
        {
            printf(" %d",arr[a][b]);    
            
        }    
        printf("\n");
    }
    printf("\n");
    
    printf("Dia de la semana es %s\n",dia[DiaSelect]);    
}