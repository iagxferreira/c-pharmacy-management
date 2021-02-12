//
// Created by Iago Ferreira on 22/01/2021.
//

#ifndef C_PHARMACY_MODEL_ITEMNOTAFISCAL_H
#define C_PHARMACY_MODEL_ITEMNOTAFISCAL_H

typedef struct{
    unsigned long int id;
    unsigned long int idNota;
    unsigned long int idProduto;
    int precoUnitario;
    int quantidade;
}ItemNotaFiscal;

#endif //C_PHARMACY_MODEL_ITEMNOTAFISCAL_H
