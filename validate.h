
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