
//ESTRUCTURA DEL FACTURA
typedef struct
{
    //Cliente cliente;
    long cod_cli;
    long no_factura;
    char f_factura_inicio[9];
    char f_factura_cierre[9];   
    float medida_kwh; 
    float tarifa_fija;   
    float cargo_energia;
    float monto;
} Factura[3];
