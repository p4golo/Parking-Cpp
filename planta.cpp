#include "planta.h"
#include "identificador.h"
#include <iostream>

Planta::Planta(void)
	:filas(MAX_FILAS), columnas(MAX_COLUMNAS), bloques_libres(MAX_FILAS * MAX_COLUMNAS) {}

Planta::Planta(const int num_filas, const int num_columnas) // constructor de la clase
	:filas(num_filas), columnas(num_columnas), bloques_libres(num_filas * num_columnas) {}

int Planta::num_bloques_libres(void) const
{
	int cnt = 0;
	for (int fila = 0; fila < this->filas; fila++) // Recorremos las filas
		for (int columna = 0; columna < this->columnas; columna++) // Recorremos las columnas
		{
			if (!this->bloques[fila][columna].esta_ocupado()) // Si el bloque no esta ocupado aumentamos el contador
				cnt++;
		}
	return cnt;
}

bool Planta::estacionar_vehiculo(tVehiculo vehiculo)
{
	bool flag = false;
	int busqueda = 4 - vehiculo;
	int filaIndice = 0, columnaIndice = 0;
	for (int fila = this->filas - 1; fila >= 0 && !flag; fila--)
	{
		int cnt = 0;
		for (int columna = 0; columna < this->columnas && !flag; columna++)
		{
			if (!this->bloques[fila][columna].esta_ocupado())
				cnt++;
			else
				cnt = 0;
			if (cnt == busqueda)
			{
				flag = true;
				filaIndice = fila;
				columnaIndice = columna;
			}
		}
	}
	if (flag)
	{
		char ident[4];
		Identificador id = Identificador();
		id.preparar_valor(vehiculo);
		id.generar_valor(ident);
		for (int i = 0; i < busqueda; i++, this->bloques_libres--)
			this->bloques[filaIndice][columnaIndice - i].ocupar_bloque(ident);
	}
	return flag;
}

void Planta::visualizar_estado(void) const // Visualiza el estado de la planta
{
	char temp[4];
	for (int fila = 0; fila < this->filas; fila++)
	{
		for (int columna = 0; columna < this->columnas; columna++)
		{
			Bloque bloque = this->bloques[fila][columna];
			bloque.obtener_valor(temp);
			std::cout << temp[0] << temp[1] << temp[2] << temp[3] << " ";
		}
		std::cout << std::endl;
	}
}

bool Planta::retirar_vehiculo(const char valor_id[])
{
	char temp[4]; // Creamos una variable temporal donde almacenaremos el valor del bloque y compararlos con el id
	bool flag = false;
	for (int fila = 0; fila < this->filas; fila++) // Recorremos las filas
		for (int columna = 0; columna < this->columnas; columna++) // Recorremos las columnas
		{
			 this->bloques[fila][columna].obtener_valor(temp); // Obtenemos el valor del bloque en el que estamos
			 if (temp[0] == valor_id[0])
				 if (temp[1] == valor_id[1])
					 if (temp[2] == valor_id[2])
						 if (temp[3] == valor_id[3]) // Comparamos uno a uno todos los digitos del identificador y si es igual desocupamos el bloque
						 {
							 this->bloques[fila][columna].desocupar_bloque();
							 flag = true;
							 this->bloques_libres++;
						 }
		}
	return flag;
}

bool Planta::obtener_hueco(int num_bloques, int& fila, int& columna)
{
	return this->bloques[fila][columna].esta_ocupado(); // Obtiene el hueco
}
