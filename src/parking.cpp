#include "parking.h"
#include <iostream>

Parking::Parking(const Planta nuevas_plantas[], int numero_plantas)
	:num_plantas(numero_plantas)
{
	for (int i = 0; i < num_plantas; i++)
		this->plantas[i] = nuevas_plantas[i];
}

bool Parking::estacionar_vehiculo(const tVehiculo vehiculo)
{
	bool estacionado = false;
	int plantaIndice = 0;
	for (int i = 0; i < this->num_plantas; i++)
	{
		if (this->plantas[i].num_bloques_libres() > this->plantas[plantaIndice].num_bloques_libres())
			plantaIndice = i;
	}
	estacionado = this->plantas[plantaIndice].estacionar_vehiculo(vehiculo);
	return estacionado;
}

bool Parking::retirar_vehiculo(const char valor_id[])
{
	bool retirado = false;

	for (int i = 0; i < this->num_plantas && !retirado; i++)
		retirado = plantas[i].retirar_vehiculo(valor_id);
	return retirado;
}

int Parking::num_bloques_libres(void) const
{
	int cnt = 0;
	for (int i = 0; i < this->num_plantas; i++)
		cnt += plantas[i].num_bloques_libres();
	return cnt;
}

void Parking::visualizar_estado(void) const
{
	for (int i = 0; i < this->num_plantas; i++)
	{
		std::cout << "Planta " << i << std::endl;
		plantas[i].visualizar_estado();
		std::cout << std::endl;
	}
}