//
// Created by Iago Ferreira on 22/01/2021.
//

#ifndef PHARMACY_MODEL_FORNECEDOR_H
#define PHARMACY_MODEL_FORNECEDOR_H

#include "../utils/Utils.h"

typedef struct{
    unsigned long int id;
    char cnpj[TAMANHO_CNPJ];
    char nome[TAMANHO_NOME];
    char email[TAMANHO_EMAIL];
    char telefone[TAMANHO_TELEFONE];
}Fornecedor;

#endif //PHARMACY_MODEL_FORNECEDOR_H
