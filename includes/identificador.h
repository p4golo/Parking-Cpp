#ifndef IDENTIFICADOR_H_INCLUDED
#define IDENTIFICADOR_H_INCLUDED

#include "tvehiculo.h"

const int NUM_CIFRAS_IDENT = 4;

class Identificador
{
  public:

    void preparar_valor(const tVehiculo vehiculo);
    void generar_valor(char valor[]) const;
    static void resetear_contador() { contador = VALOR_MIN; }

  private:

    char tipo_vehic_ident;
    int digitos_ident;
    static int contador;

    static const int VALOR_MIN = 100;
    static const int VALOR_MAX = 999;
};

#endif // IDENTIFICADOR_H_INCLUDED
