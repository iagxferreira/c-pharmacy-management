//
// Created by Iago Ferreira on 22/01/2021.
//

#ifndef C_PHARMACY_MODEL_FORNECEDOR_H
#define C_PHARMACY_MODEL_FORNECEDOR_H

typedef struct{
    unsigned long int id;
    char cnpj[15];
    char nome[100];
    char email[50];
    char telefone[15];
}Fornecedor;

#endif //C_PHARMACY_MODEL_FORNECEDOR_H
