//
// Created by Iago Ferreira on 22/01/2021.
//

#ifndef PHARMACY_MODEL_NOTAFISCAL_H
#define PHARMACY_MODEL_NOTAFISCAL_H

#include "../utils/Utils.h"

typedef struct{
    unsigned long int id;
    unsigned long int idCliente;
    char numeroNota[TAMANHO_NOTA];
    unsigned long int idVendedor;
    char dataCompra[TAMANHO_DATA];
    float valorTotal;
}NotaFiscal;

#endif //PHARMACY_MODEL_NOTAFISCAL_H
