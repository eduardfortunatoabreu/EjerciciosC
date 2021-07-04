//ASOCIANDOLO COMO UNA ENTIDAD 
struct persona
{
    int edad;
    char nombre[20];
    char color[10];    
};

//SE LE AGREGA EL * PARA INDICAR EL PUNTERO DONDE ESTA ALMACENADA LA ESTRUCTURA
void MostarDatos(struct persona *p)
{
    printf("los datos son:\n nombre:%s, con %d a%cos de edad y color favorito es el %s\n",p->nombre,164,p->edad,p->color);     
    printf("letra %c\n",64);     
    printf("letra %c\n",160);     
    printf("letra %c\n",164);     
    printf("letra %c\n",165);
    printf("letra %c\n",161);
}


void estructuras()
{
    
    //INSTANCIANDO LA ESTRUCTURA
   struct persona data;
   data.edad = 26;
   //PARA COPIAR UN TEXTO A UN UNA DA LA VARIABLE PERO ES HAY QUE TENER CUIDADO CON EL TAMANO
   strcpy(data.nombre,"Eduard Fortunato");
   strcpy(data.color,"Verde");
      


   //LO ENVIAMOS A UNA FUNCION PERO LO ENVIAMOS CON EL & PARA NO ENVIAR LA ESTRUCTURA, SINO ENVIAR LOS DATOS ALMACENADOS
    MostarDatos(&data);
   
   


       
}





