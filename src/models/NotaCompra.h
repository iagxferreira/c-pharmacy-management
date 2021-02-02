//
// Created by Iago Ferreira on 22/01/2021.
//

#ifndef C_PHARMACY_MODEL_NOTACOMPRA_H
#define C_PHARMACY_MODEL_NOTACOMPRA_H

typedef struct{
    unsigned long int id;
    char numero[10];
    unsigned long int idFornecedor;
    char dataCompra[11];
    float valorTotal;
}NotaCompra;

#endif //C_PHARMACY_MODEL_NOTACOMPRA_H
