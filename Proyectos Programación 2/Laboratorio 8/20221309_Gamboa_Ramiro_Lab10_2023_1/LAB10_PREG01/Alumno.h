/* 
 * File:   Alumno.h
 * Author: ramir
 *
 * Created on 7 de junio de 2024, 11:05 AM
 */

#ifndef ALUMNO_H
#define ALUMNO_H

class Alumno {
public:
    Alumno();
    Alumno(const Alumno& orig);
    virtual ~Alumno();
    void SetTotal(double total);
    double GetTotal() const;
    void SetCreditos(double creditos);
    double GetCreditos() const;
    void SetEscala(int escala);
    int GetEscala() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void SetNombre(char *cad);
    void GetNombre(char *cad) const;
    virtual void lee(ifstream &);
    virtual void imprime(ofstream &);
private:
    int codigo;
    char *nombre;
    int escala;
    double creditos;
    double total;
};

#endif /* ALUMNO_H */

