//
// Created by Iago Ferreira on 22/01/2021.
//

#ifndef C_PHARMACY_MODEL_ITEMCOMPRA_H
#define C_PHARMACY_MODEL_ITEMCOMPRA_H

typedef struct{
    unsigned long int id;
    unsigned long int idProduto;
    unsigned long int idNotaCompra;
    unsigned int quantidade;
    int valorUnitario;
}ItemCompra;

#endif //C_PHARMACY_MODEL_ITEMCOMPRA_H
