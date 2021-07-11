#include <time.h>
#include <json-c/json.h>
#include "../Structs/StructCliente.h"

int Tamano = 0;


//ESTRUCTURA PARA EL TIEMPO
struct tm *tm;
int contador;

//GUARDAR DATOS
void CrearJSON(Cliente *c)
{
    // Creando un objeto json
    json_object * ObjetoJSON = json_object_new_object();

    // Creando una matriz json 
    //json_object * ArrayTelefonos = json_object_new_array();
    json_object * objTelefonos = json_object_new_object();
    json_object * ArrayTelefono = json_object_new_array();
    

    json_object_object_add(ObjetoJSON, "usuario", json_object_new_string(c->usuario));    
	json_object_object_add(ObjetoJSON, "f_actual", json_object_new_string(c->f_actual));    
    json_object_object_add(ObjetoJSON, "programa", json_object_new_string(c->programa));    
    json_object_object_add(ObjetoJSON, "cod_cli", json_object_new_int64 (c->cod_cli));    
    json_object_object_add(ObjetoJSON, "ape1_cli", json_object_new_string(c->ape1_cli));    
    json_object_object_add(ObjetoJSON, "ape2_cli", json_object_new_string(c->ape2_cli));    
    json_object_object_add(ObjetoJSON, "nom_cli", json_object_new_string(c->nom_cli));    
    
    //ABRIMOS EL ARRAY DE TELEFONOS
    for(int i = 0;i<contador;i++)
    {    
        //INSTANCIAMOS EL OBJETO PARA LIMPIARLO EN CADA VUELTA
        objTelefonos = json_object_new_object();
        //AGREGAMOS LOS DATOS A LAVARIBLE
        json_object_object_add(objTelefonos,"numero",json_object_new_string(c->telefono[i].Numero));        
        json_object_object_add(objTelefonos,"programa",json_object_new_string(c->programa));
        json_object_object_add(objTelefonos,"usuario",json_object_new_string(c->usuario));
        json_object_object_add(objTelefonos,"f_actual",json_object_new_string(c->f_actual));        
        //VAMOS CONCATENANDO EL ARRAY   
        json_object_array_add(ArrayTelefono,objTelefonos);
    }

    //AGREGAMOS EL ARRAY DE LOS TELEFONOS
    json_object_object_add(ObjetoJSON,"telefono", ArrayTelefono);    



    FILE *archivo; // Creamos la variable del fichero
    //VARIABLE PARA CREAR LA RUTA DEL ARCHIVO
    char NombreFile[] = "DATABASE/";  
    //ALAMCENAR EL CODIGO DEL CLIENTE
    char code[10];
    //CONVERTIR EL CODIGO LONG EN STRING
    sprintf(code, "%ld", c->cod_cli);          
    //CONCATENMOS PARA CREAR LA RUTA DEL ARCHIVO
    strcat(NombreFile,code);
    strcat(NombreFile,".json");    

    //ASIGNAR EL ARCHIVO AL FICHERO
    archivo = fopen(NombreFile, "a");
    //ABRIMOS EL ARCHIVO Y LE ENVIAMOS LOS DATOS EN FORMATO JSON AGREGANDO MAS DATOS        
    fprintf(archivo,"%s",json_object_get_string(ObjetoJSON));

    //VALIDAR SI EL ARCHIVO EXISTE
    /*if (checkIfFileExists("DATABASE/Clientes.json"))
    {
        //ASIGNAR EL ARCHIVO AL FICHERO
        archivo = fopen("DATABASE/Clientes.json", "a");
        //ABRIMOS EL ARCHIVO Y LE ENVIAMOS LOS DATOS EN FORMATO JSON DE PRIMER INGRESO
        fprintf(archivo,",\n");      
        fprintf(archivo,"%s",json_object_get_string(ObjetoJSON));        
          
    }
    else
    {
        //ASIGNAR EL ARCHIVO AL FICHERO
        archivo = fopen("DATABASE/Clientes.json", "a");
        //ABRIMOS EL ARCHIVO Y LE ENVIAMOS LOS DATOS EN FORMATO JSON AGREGANDO MAS DATOS        
        fprintf(archivo,"%s",json_object_get_string(ObjetoJSON));
    }*/

    fclose(archivo);
}


//METODO PARA CONSULTAR EL CLIENTE Y SUS TELEFONO
void ConsultarDatos(long codigo)
//void ConsultarDatos()
{
    char code[10];
    //CONVERTIR EL CODIGO LONG EN STRING
    sprintf(code, "%ld",codigo);       
    //CREANDO LA RUTA DE BUSQUEDA
    char ruta[] = "DATABASE/";    
    strcat(ruta,code);    
    strcat(ruta,".json");    

    //LIMPIAMOS LA PANTALLA
    ClearDisplay();



    json_object * usuario;
    json_object *f_actual;
    json_object *programa;
    json_object *cod_cli;
    json_object *ape1_cli;
    json_object *ape2_cli;
    json_object *nom_cli; 
    json_object *telefonos; 
    json_object *telefono; 


    //INSTANCIA DE ESTRUCTURA PARA ALMACENAR LOS DATOS DEL CLIENTE
    Cliente *clientes;
    //BUFFER PARA ALMCENAR LOS DATOS
    char buffer[1024];

    //VALIDAR QUE EXISTA EL ARCHIVO DE CLIENTE
    if(checkIfFileExists(ruta))
    {
        FILE *archivo; // Creamos la variable del fichero para cliente
        archivo = fopen(ruta, "r"); // ABRIMOS EL ARCHO SOLO DE LECTURA
        fread(buffer, 1024, 1, archivo); //AGREGAMOS EL ARCHIVO AL BUFFER
        fclose(archivo); //CERRAMOS EL ARCHIVO

        struct json_object *parsed_json; //CREAMOS LA VARIABLE TIPO OBEJETO JSON   
        parsed_json = json_tokener_parse(buffer); //PASAMOS EL BUFFER A FORMATO JSON
        size_t n_tels; //PARA ALMACENAR LA CANTIDAD DE TELEFONOS ALMACENADA


        //printf("%s\n",json_object_get_string(parsed_json)); //PARA VER EL CONTENIDO QUE TIENE EL JSON

        //EXTRAER DEL JSON:
        //DESDE DONDE SE EXTRAERA PARSED_JSON
        //EL PARAMETRO A TOMAR 'usuario'
        //DONDE SE ALMACENARA 'clientes->usario'
        json_object_object_get_ex(parsed_json,"usuario",&usuario);         
        json_object_object_get_ex(parsed_json,"f_actual",&f_actual); 
        json_object_object_get_ex(parsed_json,"programa",&programa); 
        json_object_object_get_ex(parsed_json,"cod_cli",&cod_cli); 
        json_object_object_get_ex(parsed_json,"ape1_cli",&ape1_cli); 
        json_object_object_get_ex(parsed_json,"ape2_cli",&ape2_cli); 
        json_object_object_get_ex(parsed_json,"nom_cli",&nom_cli);  
        json_object_object_get_ex(parsed_json,"telefono",&telefonos);  

        printf("Datos del Cliente\n\n\n");
        printf("Programa del cliente --> %s\n",json_object_get_string(programa));
        printf("Codigo del cliente --> %s\n",json_object_get_string(cod_cli));
        printf("Apellido 1 del cliente --> %s\n",json_object_get_string(ape1_cli));
        printf("Apellido 2 del cliente --> %s\n",json_object_get_string(ape2_cli));
        printf("Nombre del cliente --> %s\n",json_object_get_string(nom_cli));
        printf("Feccha del cliente --> %s\n",json_object_get_string(f_actual));
        
        //ALMACENAMOS EL TAMANO DEL ARREGLO DE TELEFONOS
        n_tels = json_object_array_length(telefonos);        
        
        //printf("teke %s\n",telefonos);

        //RECORRER EL ARREGLO DE TELEDONO
        for(int i=0;i<n_tels;i++)       
        {                             
            telefono = json_object_array_get_idx(telefonos,i);            
            json_object *tel; 
            json_object_object_get_ex(telefono,"numero",&tel);
            printf("Telefono %d -->  %s\n",i+1,json_object_get_string(tel));                        
        }

    }
    else
    {
        printf("Este codigo no posee datos de ningun cliente");
    }


    pause();
}





//METODO PARA CAPTURAR LOS DATOS DEL CLIENTE Y ALMACENARLO EN DOCUMENTO TXT
bool CapturarDatos()
{
    //VARIABLE PARA ALMACENAR LOS DATOS PARA ENVIAR
    Cliente data;
    //PARA ALAMCENAR LOS NUMERO DE TELEFONOS
    Telefono *telefonos;
    Telefono *teefonoconvertido;


    int tamano = 1;
    //ASIGNAMOS EL VALOR INICIAL PARA CREAR EL ARRAY DE TELEFONOS
    contador = 0;

    //ASIGNAMOS EL ESPACIO PARA ALMACENAR 3 TELEFONOS
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
    while(true)
    {        
        //SI LA VARIABLE ES VERDADERA EL SISTEMA PEDIRA OTRO NUMERO
        if (otro)
        {                        
            //SOLICITAMOS EL TELEFONO DEL CLIENTE
            printf("Ingrese el telefono del cliente \n");
            scanf("%s", telefonos[contador].Numero); 
            

            //LISTAMOS LOS DATOS DESDE EL STRUCT PRINCIPAL
            //strcpy(telefonos[contador].f_actual,data.f_actual);
            //strcpy(telefonos[contador].programa,data.programa);             
            //strcpy(telefonos[contador].usuario,data.usuario);   

            //INCREMENTAR EL CONTADOR
            contador++;
                        
            //VARIABLES PARA IDENTIFICAR SI EL CLIENTE DESEEA INGRESAR OTRO NUMERO
            printf("\nDesea ingresar otro numero? s / n \n");
            scanf(" %c", &seleccion);
                        

            //VALIDACION PARA AGREGAR OTRO NUMERO
            if (strcmp(&seleccion, "s") == 1 || strcmp(&seleccion, "S") == 1)
            {                
                //tamano = tamano+sizeof(Telefono);
                tamano++;
                teefonoconvertido = realloc(telefonos,tamano);

                
                //CONCATENAR LOS DATOS EN UN SOLO JSON                
                otro = true;
            }
            else
            {



                //printf("debe de mandar a crear el json\n");
                data.telefono = telefonos;        
                /*printf("vamos a ver klk");        
                printf("%ld\n",data.cod_cli);
                printf("%s\n",data.usuario);
                printf("%s\n",data.f_actual);
                printf("%s\n",data.nom_cli);
                printf("%s\n",data.ape1_cli);
                printf("%s\n",data.ape2_cli);


                printf("%s\n",data.telefono[0].Numero);
                printf("%s\n",data.telefono[0].Numero);
                */

            
                
                //CONCATENAR LOS DATOS EN UN SOLO JSON                
                CrearJSON(&data);
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

    long capacidad = sizeof(long);
    char OptionCliente[2];
    long ClienteBuscar;

    ClearDisplay();    

    while (true)
    {

        printf("\n\n***************************************************************************\n");
        printf("*********************************** Welcome ***********************************\n");
        printf("*******************************************************************************\n");
        printf("*                           Selected your option                              *\n");
        printf("*                                                                             *\n");
        printf("*       1 -> Agregar Datos de CLientes                                        *\n");
        printf("*       2 -> Consultar Datos de Clientes                                      *\n");
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
            else
            {

                printf("ingrese codigo del de cliente\n");
                scanf("%ld", &ClienteBuscar);
                ConsultarDatos(ClienteBuscar);
            }
        }
        else
        {
            printf("Please Select your option\n");
        }
    }
}
