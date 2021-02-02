//
// Created by Iago Ferreira on 22/01/2021.
//

#ifndef C_PHARMACY_MODEL_CLIENTE_H
#define C_PHARMACY_MODEL_CLIENTE_H

#include "../utils/Utils.h"

typedef struct{
    unsigned long id;
    char nome[TAMANHO_NOME];
    char cpf[TAMANHO_CPF];
    char email[TAMANHO_EMAIL];
    char telefone[TAMANHO_TELEFONE];
}Cliente;

#endif //C_PHARMACY_MODEL_CLIENTE_H
