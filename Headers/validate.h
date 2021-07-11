
//VALIDACION DE NUMERO
bool ValidateNumber(char numero[])
{
    for (int i = 0; i < strlen(numero); i++)
    {
        if (!isdigit(numero[i]))
        {
            printf("Only number\n");
            return false;
        }
    }

    return true;
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


//PARA VALIDAR SI EL ARCHIVO EXISTE
bool checkIfFileExists(const char *filename)
{
    FILE *file;
    if (file = fopen(filename, "r"))
    {
        fclose(file);
        return true;
    }

    return false;
}