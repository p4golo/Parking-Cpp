#include "identificador.h"

int Identificador::contador;

void Identificador::preparar_valor(tVehiculo vehiculo)
{
    switch (vehiculo)
    {
        case AUTOBUS:
            tipo_vehic_ident = 'A';
            break;
        case TURISMO:
            tipo_vehic_ident = 'T';
            break;
        case FURGONETA:
            tipo_vehic_ident = 'F';
            break;
        case MOTOCICLETA:
            tipo_vehic_ident = 'M';
            break;
    }

    digitos_ident = contador++;

    if (contador > VALOR_MAX)
        contador = VALOR_MIN;

}


void Identificador::generar_valor(char valor[]) const
{
    int numero = digitos_ident;
    valor[0] = tipo_vehic_ident;

    for (int i=1; i<=NUM_CIFRAS_IDENT - 1; i++)
    {
        valor[NUM_CIFRAS_IDENT - i] = (numero % 10) + '0';
        numero /= 10;
    }
    return;
}
