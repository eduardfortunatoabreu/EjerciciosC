#include "../Structs/StructTelefono.h"

//ESTRUCTURA DEL CLIENTE
typedef struct
{
    char usuario[31];
    char f_actual[9];
    char programa[16];
    long cod_cli;
    char ape1_cli[21];
    char ape2_cli[21];
    char nom_cli[31];
    Telefono *telefono;
} Cliente;


