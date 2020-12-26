#include "bloque.h"

Bloque::Bloque()
	:ocupado(false) // Cuando lo creamos ocupado vale false ya que no esta ocupado
{
	for (int i = 0; i < this->TAMANO_ID_BLOQUE; i++)
		valor_id[i] = 'X'; // Crea un bloque vacio que representamos como XXXX
}

void Bloque::ocupar_bloque(const char nuevo_valor_id[])
{
	for (int i = 0; i < this->TAMANO_ID_BLOQUE; i++)
		this->valor_id[i] = nuevo_valor_id[i]; // Vamos rellenando el bloque con el valor del id pasado
	this->ocupado = true; // ahora estaría ocupado
}

void Bloque::desocupar_bloque(void)
{
	for (int i = 0; i < this->TAMANO_ID_BLOQUE; i++)
		this->valor_id[i] = 'X'; // Cambiamos el valor del bloque a XXXX
	this->ocupado = false; // Cambiamos la variable ocupado a false ya que se desocupa
}

void Bloque::obtener_valor(char valor[]) const
{
	for (int i = 0; i < this->TAMANO_ID_BLOQUE; i++)
		valor[i] = this->valor_id[i]; //obtenemos el valor del bloque
}
