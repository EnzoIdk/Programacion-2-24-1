/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Ficha.h
 * Author: alulab14
 *
 * Created on 5 de junio de 2024, 12:06 PM
 */

#ifndef FICHA_H
#define FICHA_H

class Ficha {
public:
    Ficha();
    virtual ~Ficha();
    void SetCol(int col);
    int GetCol() const;
    void SetFila(int fila);
    int GetFila() const;
    void SetId(const char *);
    void GetId(char *) const;
    void asigna(char*,int,int);
    virtual void imprime(ofstream &)=0;
    virtual void mover(char,int)=0;
private:
    char *id;
    int fila;
    int col;
};

#endif /* FICHA_H */

