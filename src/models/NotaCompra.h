//
// Created by Iago Ferreira on 22/01/2021.
//

#ifndef C_PHARMACY_MODEL_NOTACOMPRA_H
#define C_PHARMACY_MODEL_NOTACOMPRA_H

#include "../utils/Utils.h"

typedef struct{
    unsigned long int id;
    char numero[TAMANHO_NUMERO];
    unsigned long int idFornecedor;
    char dataCompra[TAMANHO_DATA];
    float valorTotal;
}NotaCompra;

#endif //C_PHARMACY_MODEL_NOTACOMPRA_H
