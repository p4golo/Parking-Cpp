#include <iostream>

#include "tvehiculo.h"
#include "identificador.h"
#include "planta.h"
#include "parking.h"

using namespace std;


int main()
{
    const int NUM_PLANTAS_PK1 = 2;
    Planta plantas[NUM_PLANTAS_PK1] = {Planta(5,10), Planta(5,8)};
    Parking pk1(plantas, NUM_PLANTAS_PK1);

    cout << "Bloques libres: " << pk1.num_bloques_libres() << endl << endl;

    Identificador::resetear_contador();
    for (int i=0; i<10; i++)
    {
        cout << pk1.estacionar_vehiculo(AUTOBUS);
        cout << pk1.estacionar_vehiculo(FURGONETA);
        cout << pk1.estacionar_vehiculo(TURISMO);
        cout << pk1.estacionar_vehiculo(MOTOCICLETA);
    }
    cout << endl;

    pk1.visualizar_estado();


    cout << "Bloques libres: " << pk1.num_bloques_libres() << endl << endl;

    char ident1[]  = {'F', '1', '2', '9'};
    cout << pk1.retirar_vehiculo(ident1);
    cout << pk1.retirar_vehiculo(ident1);

    char ident2[]  = {'A', '1', '3', '2'};
    cout << pk1.retirar_vehiculo(ident2);
    cout << endl;

    pk1.visualizar_estado();
    cout << "Bloques libres: " << pk1.num_bloques_libres() << endl << endl;

    cout << pk1.estacionar_vehiculo(AUTOBUS);
    cout << pk1.estacionar_vehiculo(FURGONETA);
    cout << pk1.estacionar_vehiculo(TURISMO);
    cout << pk1.estacionar_vehiculo(MOTOCICLETA);
    cout << endl;

    pk1.visualizar_estado();
    cout << "Bloques libres: " << pk1.num_bloques_libres() << endl << endl;

    return 0;
}
