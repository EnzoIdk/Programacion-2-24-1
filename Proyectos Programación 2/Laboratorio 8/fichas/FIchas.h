/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FIchas.h
 * Author: margo
 *
 * Created on 11 de junio de 2024, 18:29
 */

#ifndef FICHAS_H
#define FICHAS_H
#include <fstream>

using namespace std;
class FIchas {
private:
    char* idficha;
    char tipo;
    int fila;
    int columna;

public:
    FIchas();
    FIchas(const FIchas& orig);
    virtual ~FIchas();
    void SetColumna(int columna);
    int GetColumna() const;
    void SetFila(int fila);
    int GetFila() const;
    void SetTipo(char tipo);
    char GetTipo() const;
    void SetIdficha(const char * idficha);
    void GetIdficha(char*) const;
    void SetFicha(char *, char, int, int);
    virtual void movimientos(char , int);
    virtual void impresion(ofstream &);
};
#endif /* FICHAS_H */

