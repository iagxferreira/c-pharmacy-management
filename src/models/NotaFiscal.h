//
// Created by Iago Ferreira on 22/01/2021.
//

#ifndef C_PHARMACY_MODEL_NOTAFISCAL_H
#define C_PHARMACY_MODEL_NOTAFISCAL_H

typedef struct{
    unsigned long int id;
    unsigned long int idCliente;
    unsigned long int idVendedor;
    char numeroNota[8];
    char dataCompra[11];
    float valorTotal;
}NotaFiscal;

#endif //C_PHARMACY_MODEL_NOTAFISCAL_H