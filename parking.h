#ifndef PARKING_H_INCLUDED
#define PARKING_H_INCLUDED

#include "tvehiculo.h"
#include "planta.h"

class Parking
{
  public:

    Parking(const Planta nuevas_plantas[], int numero_plantas); // constructor
    bool estacionar_vehiculo( const tVehiculo vehiculo );
    bool retirar_vehiculo( const char valor_id[] );
    void visualizar_estado(void) const;
    int num_bloques_libres(void) const;

  private:

    static const int MAX_PLANTAS = 4;
    Planta plantas[MAX_PLANTAS];
    int num_plantas;
};

#endif // PARKING_H_INCLUDED
