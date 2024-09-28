/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NFalta.h
 * Author: ISA
 *
 * Created on 6 de junio de 2024, 04:04 PM
 */

#ifndef NFALTA_H
#define NFALTA_H
#include <fstream>
using namespace std;
#include "Infraccion.h"
#include "Falta.h"
#include "NFalta.h"
#include "LFalta.h"
class NFalta {
private:
    class Infraccion *pfalta;
    class Falta dfalta;
    class NFalta *sig;
public:
    NFalta();
    NFalta(const NFalta& orig);
    virtual ~NFalta();
    bool operator <= (int cod);
    void operator >= (ofstream &arch);
    friend class LFalta;
};

#endif /* NFALTA_H */

