#ifndef BLOQUE_H_INCLUDED
#define BLOQUE_H_INCLUDED


class Bloque
{
  public:

    Bloque(void); // constructor
    void ocupar_bloque(const char nuevo_valor_id[]);
    void desocupar_bloque(void);
    void obtener_valor(char valor[]) const;
    bool esta_ocupado(void) const {return ocupado;}

  private:

    static const int TAMANO_ID_BLOQUE = 4;
    char valor_id[TAMANO_ID_BLOQUE];
    bool ocupado;

};



#endif // BLOQUE_H_INCLUDED
