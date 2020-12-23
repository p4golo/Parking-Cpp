#ifndef PLANTA_H_INCLUDED
#define PLANTA_H_INCLUDED

#include "tvehiculo.h"
#include "bloque.h"

class Planta
{
  public:

    Planta(void); // constructor
    Planta(const int num_filas, const int num_columnas); // constructor
    bool estacionar_vehiculo( tVehiculo vehiculo );
    bool retirar_vehiculo( const char valor_id[] );
    int num_bloques_libres(void) const;
    void visualizar_estado(void) const;
    int get_filas(void) const { return filas; }
    int get_columnas(void) const { return columnas; }

  private:

    int filas;
    int columnas;
    int bloques_libres;

    static const int MAX_FILAS = 6;
    static const int MAX_COLUMNAS = 10;
    Bloque bloques[MAX_FILAS][MAX_COLUMNAS];

    bool obtener_hueco(int num_bloques, int& fila, int& columna);

};

#endif // PLANTA_H_INCLUDED