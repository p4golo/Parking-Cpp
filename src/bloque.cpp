#include "bloque.h"

Bloque::Bloque()
	:ocupado(false)
{
	for (int i = 0; i < this->TAMANO_ID_BLOQUE; i++)
		valor_id[i] = 'X';
}

void Bloque::ocupar_bloque(const char nuevo_valor_id[])
{
	for (int i = 0; i < this->TAMANO_ID_BLOQUE; i++)
		this->valor_id[i] = nuevo_valor_id[i];
	this->ocupado = true;
}

void Bloque::desocupar_bloque(void)
{
	for (int i = 0; i < this->TAMANO_ID_BLOQUE; i++)
		this->valor_id[i] = 'X';
	this->ocupado = false;
}

void Bloque::obtener_valor(char valor[]) const
{
	for (int i = 0; i < this->TAMANO_ID_BLOQUE; i++)
		valor[i] = this->valor_id[i];
}