/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Espacio.h
 * Author: margo
 *
 * Created on 29 de mayo de 2024, 9:13
 */

#ifndef ESPACIO_H
#define ESPACIO_H

class Espacio {
private:
    char contenido;
    int posx;
    int posy;

public:
    Espacio();
    Espacio(const Espacio& orig);
    virtual ~Espacio();
    void SetPosy(int posy);
    int GetPosy() const;
    void SetPosx(int posx);
    int GetPosx() const;
    void SetContenido(char contenido);
    char GetContenido() const;

};
#endif /* ESPACIO_H */

