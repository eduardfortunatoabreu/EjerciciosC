#include <time.h>
#include <json-c/json.h>
#include "../Structs/StructCliente.h"
#include "../Structs/StrucFactura.h"
#include "CalculoTarifas.h"

int Tamano = 0;

//ESTRUCTURA PARA EL TIEMPO
struct tm *tm;
//LLEVAR EL CONTEO DE LAS VECES QUE SE AGREGO UN NUMERO DE TELEFONO
int contador;




//METODO PARA AGREGAR LOS CONSUMOS A UN CLIENTE YA REGISTRADO
void AgregarCosumo(long codigo)
{


    char code[10];
    //CONVERTIR EL CODIGO LONG EN STRING
    sprintf(code, "%ld", codigo);
    //CREANDO LA RUTA DE BUSQUEDA
    char ruta[] = "DATABASE/Facturas/";
    strcat(ruta, code);
    strcat(ruta, ".json");

    


    if(!checkIfFileExists(ruta))
    {
        //PARA ALMACENAR LOS VALORES DE LA FACTURA
        Cliente cliente;
        Factura factura;

        // Creando un objeto json
        json_object *ObjetoJSON = json_object_new_object();
        json_object *objconsumo = json_object_new_object();
        json_object *ArrayConsumo = json_object_new_array();


        //LIMPIAMOS LA PANTALLA
        ClearDisplay();

        for(int i=0;i<3;i++)
        {          
             
            objconsumo = json_object_new_object();
            printf("Ingrese cantidad de kwh \n");
            scanf("%f",&factura[i].medida_kwh);
            printf("Ingrese Fecha Inicio \n");
            scanf("%s",factura[i].f_factura_inicio);    
            printf("Ingrese Fecha Cierre \n");
            scanf("%s",factura[i].f_factura_cierre);   

            //COMPLETANDO LOS DATOS

            //ALMACENAMOS EL CODIGO DEL CLIENTE
            factura[i].cod_cli =  codigo; 
            //ALMACENAMOS EL VALOR DE LA TARIFA FIJA
            factura[i].tarifa_fija = TarifaFijaBTS1(factura[i].medida_kwh);
            //ALAMCENAMOS EL CARGO DE ENERGIA
            factura[i].cargo_energia = CargoBTS1(factura[i].medida_kwh);
            //ALMACENAMOS EL MONTO
            factura[i].monto = factura[i].tarifa_fija+factura[i].cargo_energia; 


            json_object_object_add(objconsumo, "cod_cli", json_object_new_int64(factura[i].cod_cli));                        
            json_object_object_add(objconsumo, "no_factura", json_object_new_int(i+1));                        
            json_object_object_add(objconsumo, "f_factura_inicio", json_object_new_string(factura[i].f_factura_inicio));                        
            json_object_object_add(objconsumo, "f_factura_cierre", json_object_new_string(factura[i].f_factura_cierre));                        
            json_object_object_add(objconsumo, "medida_kwh", json_object_new_double(factura[i].medida_kwh));                        
            json_object_object_add(objconsumo, "tarifa_fija", json_object_new_double(factura[i].tarifa_fija));                        
            json_object_object_add(objconsumo, "cargo_energia", json_object_new_double(factura[i].cargo_energia));                        
            json_object_object_add(objconsumo, "monto", json_object_new_double(factura[i].monto));      

            //VAMOS CONCATENANDO EL ARRAY
            json_object_array_add(ArrayConsumo, objconsumo);            
        } 

        //AGREGAMOS EL ARRAY DE LAS FACTURAS
        json_object_object_add(ObjetoJSON, "facturas", ArrayConsumo);


        FILE *archivo; // Creamos la variable del fichero
        //ASIGNAR EL ARCHIVO AL FICHERO
        archivo = fopen(ruta, "a");
        //ABRIMOS EL ARCHIVO Y LE ENVIAMOS LOS DATOS EN FORMATO JSON AGREGANDO MAS DATOS
        fprintf(archivo, "%s", json_object_get_string(ObjetoJSON));    
        //CERRAMOS EL ARCHIVO
        fclose(archivo);            

    }
    else
    {
       printf("EL CLIENTE YA TIENE SUS FACTURAS ASIGNADAS\n");                
    }
    
    pause();
}

//CONSULTAR FACTURAS
void ConsultarFacturas(long codigo)
{   
    //VARIABLE PARA ALMACENAR EL CODIGO DEL CLIENTE
    char code[10];
    //CONVERTIR EL CODIGO LONG EN STRING
    sprintf(code, "%ld", codigo);
    //CREANDO LA RUTA DE BUSQUEDA
    char ruta[] = "DATABASE/Facturas/";
    //CONTATENAR LA RUTUA CON EL CODIGO PARA ENCONTRAR EL ARCHIVO
    strcat(ruta, code);
    //CONTATENAR EL FORMATO DEL ARCHIVO
    strcat(ruta, ".json");


    //BUFFER PARA ALMCENAR LOS DATOS
    char buffer[1024];
    //OBJETO JSON PARA ALMACENAR LOS DATOS DE LA FACTURAS
    json_object *facturas;  
    json_object *factura;  


    FILE *archivo;                   // Creamos la variable del fichero para cliente
    archivo = fopen(ruta, "r");      // ABRIMOS EL ARCHO SOLO DE LECTURA
    fread(buffer, 1024, 1, archivo); //AGREGAMOS EL ARCHIVO AL BUFFER
    fclose(archivo);                //CERRAMOS EL ARCHIVO

    struct json_object *parsed_json;          //CREAMOS LA VARIABLE TIPO OBEJETO JSON
    parsed_json = json_tokener_parse(buffer); //PASAMOS EL BUFFER A FORMATO JSON   
    json_object_object_get_ex(parsed_json, "facturas", &facturas);

    //RECORRER EL ARREGLO DE TELEFONO
    for (int i = 0; i < 3; i++)
    {
        //printf("esto son las facturas %s\n",json_object_get_string(json_object_array_get_idx(facturas, i)));
        factura = json_object_array_get_idx(facturas, i);             
        json_object *no_factura;
        json_object *f_factura_inicio;
        json_object *f_factura_cierre;
        json_object *medida_kwh;
        json_object *tarifa_fija;
        json_object *cargo_energia;
        json_object *monto;
        
        json_object_object_get_ex(factura, "no_factura", &no_factura);  
        json_object_object_get_ex(factura, "f_factura_inicio", &f_factura_inicio);  
        json_object_object_get_ex(factura, "f_factura_cierre", &f_factura_cierre);  
        json_object_object_get_ex(factura, "medida_kwh", &medida_kwh);  
        json_object_object_get_ex(factura, "tarifa_fija", &tarifa_fija);  
        json_object_object_get_ex(factura, "cargo_energia", &cargo_energia);  
        json_object_object_get_ex(factura, "monto", &monto);  
        
        printf("Datos de la facturas: \n\n\n");
        printf("No. Factura:---> %ld\n",json_object_get_int64(no_factura));
        printf("Fecha Inicio Ciclo:---> %s\n",json_object_get_string(f_factura_inicio));
        printf("Fecha Fin Ciclo:---> %s\n",json_object_get_string(f_factura_cierre));
        printf("KWh Consumido:---> %.2f\n",json_object_get_double(medida_kwh));
        printf("Tarifa Fija:---> %.2f\n",json_object_get_double(tarifa_fija));
        printf("Cargo por Energia:---> %.2f\n",json_object_get_double(cargo_energia));
        printf("Monto Total:---> %.2f\n",json_object_get_double(monto));        
    }  
}


//METODO PARA CONSULTAR EL CLIENTE Y SUS TELEFONO
void ConsultarDatos(long codigo)
{
    //STRUCT PARA ALMACENAR LOS DATOS
    Cliente clienteshow;
    Telefono *telefonoshow;

    //VARIABLE PARA ALMACENAR EL CODIGO DEL CLIENTE
    char code[10];
    //CONVERTIR EL CODIGO LONG EN STRING
    sprintf(code, "%ld", codigo);
    //CREANDO LA RUTA DE BUSQUEDA
    char ruta[] = "DATABASE/Clientes/";
    //CONTATENAR LA RUTUA CON EL CODIGO PARA ENCONTRAR EL ARCHIVO
    strcat(ruta, code);
    //CONTATENAR EL FORMATO DEL ARCHIVO
    strcat(ruta, ".json");
    
    //OBJETOS JSON PARA ALMACENAR LOS DATOS QUE EXTRAEMOS DEL DOCUMENTO
    json_object *usuario;
    json_object *f_actual;
    json_object *programa;
    json_object *cod_cli;
    json_object *ape1_cli;
    json_object *ape2_cli;
    json_object *nom_cli;
    json_object *telefonos;
    json_object *telefono;
   
    

    //BUFFER PARA ALMCENAR LOS DATOS
    char buffer[1024];

    //VALIDAR QUE EXISTA EL ARCHIVO DE CLIENTE
    if (checkIfFileExists(ruta))
    {
        FILE *archivo;                   // Creamos la variable del fichero para cliente
        archivo = fopen(ruta, "r");      // ABRIMOS EL ARCHO SOLO DE LECTURA
        fread(buffer, 1024, 1, archivo); //AGREGAMOS EL ARCHIVO AL BUFFER
        fclose(archivo);                 //CERRAMOS EL ARCHIVO

        struct json_object *parsed_json;          //CREAMOS LA VARIABLE TIPO OBEJETO JSON
        parsed_json = json_tokener_parse(buffer); //PASAMOS EL BUFFER A FORMATO JSON
        size_t n_tels;                            //PARA ALMACENAR LA CANTIDAD DE TELEFONOS ALMACENADA
        size_t n_factura;                         //PARA ALMACENAR LA CANTIDAD DE FACTURA ALMACENADA

        //EXTRAER DEL JSON:
        //DESDE DONDE SE EXTRAERA PARSED_JSON
        //EL PARAMETRO A TOMAR 'usuario'
        //DONDE SE ALMACENARA 'clientes->usario'
        json_object_object_get_ex(parsed_json, "usuario", &usuario);
        json_object_object_get_ex(parsed_json, "f_actual", &f_actual);
        json_object_object_get_ex(parsed_json, "programa", &programa);
        json_object_object_get_ex(parsed_json, "cod_cli", &cod_cli);
        json_object_object_get_ex(parsed_json, "ape1_cli", &ape1_cli);
        json_object_object_get_ex(parsed_json, "ape2_cli", &ape2_cli);
        json_object_object_get_ex(parsed_json, "nom_cli", &nom_cli);
        json_object_object_get_ex(parsed_json, "telefono", &telefonos);                        
        //ALMACENAMOS EL TAMANO DEL ARREGLO DE TELEFONOS
        n_tels = json_object_array_length(telefonos);

        //PASANDO LOS DATOS  A LA STRUCTURA
        strcpy(clienteshow.usuario, json_object_get_string(usuario));
        strcpy(clienteshow.programa, json_object_get_string(programa));
        clienteshow.cod_cli = json_object_get_int64(cod_cli);
        strcpy(clienteshow.ape1_cli, json_object_get_string(ape1_cli));
        strcpy(clienteshow.ape2_cli, json_object_get_string(ape2_cli));
        strcpy(clienteshow.nom_cli, json_object_get_string(nom_cli));
        strcpy(clienteshow.f_actual, json_object_get_string(f_actual));        

        int tamano = 1;        
 
        
        printf("Datos del Cliente\n\n\n");
        printf("Codigo del cliente --> %ld\n", clienteshow.cod_cli);
        printf("Programa del cliente --> %s\n", clienteshow.programa);    
        printf("Usuario del cliente --> %s\n", clienteshow.usuario);
        printf("Nombre del  cliente --> %s\n", clienteshow.nom_cli);
        printf("Apellido 1 del cliente --> %s\n", clienteshow.ape1_cli);
        printf("Apellido 2 del cliente --> %s\n", clienteshow.ape2_cli);    
        printf("Fecha del cliente --> %s\n", clienteshow.f_actual);

        //RECORRER EL ARREGLO DE TELEFONO
        for (int i = 0; i < n_tels; i++)
        { 
            telefono = json_object_array_get_idx(telefonos, i);
            json_object *tel;
            json_object_object_get_ex(telefono, "numero", &tel);            
            printf("este es el numero telefonico %s\n",json_object_get_string(tel));
        }    


        char rutafactura[] = "DATABASE/Facturas/";
        //CONTATENAR LA RUTUA CON EL CODIGO PARA ENCONTRAR EL ARCHIVO
        strcat(rutafactura, code);
        //CONTATENAR EL FORMATO DEL ARCHIVO
        strcat(rutafactura, ".json");

        //VALIDAMOS SI TIENE FACTURA
        if(checkIfFileExists(rutafactura))   
        {   
            printf("\n\n\n\n");
            ConsultarFacturas(clienteshow.cod_cli);
        }
        else
        {
            printf("Este cliente no posee factura generadas");
        }




    }
    else
    {
        printf("Este codigo no posee datos de ningun cliente");
    }

    pause();
}




//GUARDAR DATOS
void GuardarCliente(Cliente *c)
{
    // Creando un objeto json
    json_object *ObjetoJSON = json_object_new_object();

    // Creando una matriz json    
    json_object *objTelefonos = json_object_new_object();
    json_object *ArrayTelefono = json_object_new_array();

    json_object_object_add(ObjetoJSON, "usuario", json_object_new_string(c->usuario));
    json_object_object_add(ObjetoJSON, "f_actual", json_object_new_string(c->f_actual));
    json_object_object_add(ObjetoJSON, "programa", json_object_new_string(c->programa));
    json_object_object_add(ObjetoJSON, "cod_cli", json_object_new_int64(c->cod_cli));
    json_object_object_add(ObjetoJSON, "ape1_cli", json_object_new_string(c->ape1_cli));
    json_object_object_add(ObjetoJSON, "ape2_cli", json_object_new_string(c->ape2_cli));
    json_object_object_add(ObjetoJSON, "nom_cli", json_object_new_string(c->nom_cli));

 //ABRIMOS EL ARRAY DE TELEFONOS
    for (int i = 0; i < contador; i++)
    {
        //INSTANCIAMOS EL OBJETO PARA LIMPIARLO EN CADA VUELTA
        objTelefonos = json_object_new_object();
        //AGREGAMOS LOS DATOS A LAVARIBLE
        json_object_object_add(objTelefonos, "numero", json_object_new_string(c->telefono[i].Numero));
        json_object_object_add(objTelefonos, "programa", json_object_new_string(c->programa));
        json_object_object_add(objTelefonos, "usuario", json_object_new_string(c->usuario));
        json_object_object_add(objTelefonos, "f_actual", json_object_new_string(c->f_actual));
        //VAMOS CONCATENANDO EL ARRAY
        json_object_array_add(ArrayTelefono, objTelefonos);
    }

    //AGREGAMOS EL ARRAY DE LOS TELEFONOS
    json_object_object_add(ObjetoJSON, "telefono", ArrayTelefono);

    FILE *archivo; // Creamos la variable del fichero
    //VARIABLE PARA CREAR LA RUTA DEL ARCHIVO
    char NombreFile[50] = "DATABASE/Clientes/";
    //ALAMCENAR EL CODIGO DEL CLIENTE
    char code[15];
    //CONVERTIR EL CODIGO LONG EN STRING
    sprintf(code, "%ld", c->cod_cli);
    //CONCATENMOS PARA CREAR LA RUTA DEL ARCHIVO
    strcat(NombreFile, code);
    strcat(NombreFile, ".json");

    //ASIGNAR EL ARCHIVO AL FICHERO
    archivo = fopen(NombreFile, "a");
    //ABRIMOS EL ARCHIVO Y LE ENVIAMOS LOS DATOS EN FORMATO JSON AGREGANDO MAS DATOS
    fprintf(archivo, "%s", json_object_get_string(ObjetoJSON));
    //CERRAMOS EL ARCHIVO
    fclose(archivo);    
   
}


//METODO PARA CAPTURAR LOS DATOS DEL CLIENTE Y ALMACENARLO EN DOCUMENTO TXT
bool CapturarDatos()
{
    //VARIABLE PARA ALMACENAR LOS DATOS PARA ENVIAR
    Cliente data;

    //PARA ALAMCENAR LOS NUMERO DE TELEFONOS
    Telefono *telefonos =  NULL;    
    
    //Telefono *teefonoconvertido;
    

    int tamano = 1;
    //ASIGNAMOS EL VALOR INICIAL PARA CREAR EL ARRAY DE TELEFONOS
    contador = 0;

    //ASIGNAMOS EL ESPACIO PARA ALMACENAR TELEFONOS
    telefonos = malloc(tamano);


    //VARIABLES PARA PODER VALIDAR SI SE QUIERE OTRO TELEFONO
    bool otro = true;
    //PARA ALMACENAR LA RESPUESTA SI SE QUIE
    char seleccion;

    //LIMPIAR EL BUUFER
    __fpurge(stdin);

    //VARIABLE TIPO TIME PARA ALMACENA EL TIEMPO
    time_t tiempo;
    //VARIABLE PARA ALMACENAR EL TIEMPO RETORANADO
    char fechayhora[9];
    tiempo = time(NULL);

    tm = localtime(&tiempo);
    //ESCRIBIR EL TIEMPO EN LA VARAIBLE CON 9 POSICIONES CON EL FORMATO D/M/Y
    strftime(fechayhora, 9, "%d/%m/%y", tm);

    //COPIAMOS LA FECHA A LA ESTRUCTURA
    strcpy(data.f_actual, fechayhora);

    //INGRESAR LOS DATOS POR PANTALLA
    printf("Ingrese el codigo del cliente  \n");
    scanf("%ld", &data.cod_cli);

    printf("Ingrese el nombre del cliente \n");
    scanf("%s", data.nom_cli);

    printf("Ingrese el Apellido paterno del cliente \n");
    scanf("%s", data.ape1_cli);

    printf("Ingrese el Apellido materno del cliente \n");
    scanf("%s", data.ape2_cli);

    printf("Ingrese programa al que pertenece el cliente \n");
    scanf("%s", data.programa);

    //COPIAMOS EL NOMBRE PARA CREAR EL NICKNAME
    strcpy(data.usuario, data.nom_cli);
    //CONCATENAMOS EL APELLIDO 1 PARA COMPLETAR EL NICKNAME
    strcat(data.usuario, data.ape1_cli);

    //BUCLE PARA INGRESAR LOS NUMEROS DE TELEFONO NECESARIOS
    while (true)
    {
        //SI LA VARIABLE ES VERDADERA EL SISTEMA PEDIRA OTRO NUMERO
        if (otro)
        {
            //SOLICITAMOS EL TELEFONO DEL CLIENTE
            printf("Ingrese el telefono del cliente \n");            
            scanf("%s", telefonos[contador].Numero);


            //INCREMENTAR EL CONTADOR
            contador++;
                
            //VARIABLES PARA IDENTIFICAR SI EL CLIENTE DESEEA INGRESAR OTRO NUMERO
            printf("\nDesea ingresar otro numero? s / n \n");
            scanf(" %c", &seleccion);            

            //VALIDACION PARA AGREGAR OTRO NUMERO
            if (strcmp(&seleccion, "s") == 1 || strcmp(&seleccion, "S") == 1)
            {
                //AUMENTAMOS EN UNO LA CANTIDAD QUE SE QUIERE AGREGAR
                tamano++;                
                //REASIGNAMOS EL TAMANO DE LA POSICION                
                telefonos = realloc(telefonos, tamano);                            
                
                //CONCATENAR LOS DATOS EN UN SOLO JSON
                otro = true;
            }
            else
            {
                //AGREGAMOS LOS TELEFONOS A LA STRUCT
                data.telefono = telefonos;
                //LIBERAR LA MEMORIA
                free(telefonos);
                //printf("vamos a ver que queda en la variable del puntero %s",telefonos);
                //CONCATENAR LOS DATOS EN UN SOLO JSON
                GuardarCliente(&data);
                otro = false;
            }            
        }
        else
        {
            //TERMINAR EL BUCLE
            break;
        }
    }
}

//MANEJAR DATOS DE CLIENTES
void DatosClientes()
{

    //VARIABLES PARA MANEJO DEL MENU
    long capacidad = sizeof(long);
    char OptionCliente[2];
    long ClienteBuscar;
    //LIMPIAMOS LA PANTALLA ANTES DE MOSTRAR EL MENU
    ClearDisplay();    

    while (true)
    {

        printf("\n\n***************************************************************************\n");
        printf("*********************************** Welcome ***********************************\n");
        printf("*******************************************************************************\n");
        printf("*                           Selected your option                              *\n");
        printf("*                                                                             *\n");
        printf("*       1 -> Agregar Datos de CLientes                                        *\n");
        printf("*       2 -> Agregar Consumo de Cliente                                       *\n");
        printf("*       3 -> Consultar Datos de Clientes                                      *\n");
        //printf("*       4 -> Consultar Consumo de Cliente                                     *\n");
        printf("*       0 -> Exit                                                             *\n");
        printf("*                                                                             *\n");
        printf("*******************************************************************************\n");

        printf("*----->   ");
        //PARA ASIGNARLE UN VALOR A LA VARIABLE LE PASAMOS LA DIRECCION CON EL SIMBOLO &
        scanf("%s", OptionCliente);

        if (ValidateNumber(OptionCliente))
        {
            //FUNCION ATOI PARA CONVERTIR TEXTO EN NUMERO
            if (atoi(OptionCliente) == 0)
            {
                break;
            }
            else if (atoi(OptionCliente) == 1)
            {
                CapturarDatos();
            }
            else if (atoi(OptionCliente) == 2)
            {
                printf("ingrese codigo del de cliente\n");
                scanf("%ld", &ClienteBuscar);
                AgregarCosumo(ClienteBuscar);

                //ConsultarDatos(ClienteBuscar);
                //CapturarDatos();
            }
            else if (atoi(OptionCliente) == 3)
            {
                printf("ingrese codigo del de cliente\n");
                scanf("%ld", &ClienteBuscar);
                ConsultarDatos(ClienteBuscar);
            }
            else
            {
                printf("Esto no es una opcion\n");
            }
        }
        else
        {
            printf("Please Select your option\n");
        }
    }
}
