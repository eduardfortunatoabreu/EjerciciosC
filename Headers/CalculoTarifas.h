

//CALCULAR CAGOS EN LA TARIFA BTS1
double CargoBTS1(float kWh)
{
    double Result = 0.00;
    //VALIDAMOS EL CARGO POR CONSUMO
    if(kWh <= 200)
    {    
        Result = Result + (kWh*4.44);
    }
    else if(kWh >= 201 && kWh <= 300)
    {        
        Result = Result + (kWh*6.97);
    }
    else if(kWh >= 301 && kWh <= 700)
    {     
        Result = Result + (kWh*10.86);
    }
    else
    {     
        Result = Result + (kWh*11.10);
    }

    return Result;

}


//CALCULAR TARIFA FIJA DE LOS KWH CONSUMIDO
double TarifaFijaBTS1(float kWh)
{
    double Result = 0.00;
    
    //VALIDAMOS LA CANTIDAD DE KWH PARA VALIDAR LA TARIFA FIJA QUE LE TOCA
    if(kWh <= 100.00)
    {
        Result = 37.95;
    }
    else
    {
        Result = 137.25;
    }

    return Result;
}