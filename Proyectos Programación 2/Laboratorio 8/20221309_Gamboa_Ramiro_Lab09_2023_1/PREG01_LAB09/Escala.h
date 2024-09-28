/* 
 * File:   Escala.h
 * Author: ramir
 *
 * Created on 5 de junio de 2024, 02:44 PM
 */

#ifndef ESCALA_H
#define ESCALA_H

class Escala {
public:
    Escala();
    Escala(const Escala& orig);
    virtual ~Escala();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
private:
    int codigo;
    double precio;
};

#endif /* ESCALA_H */

