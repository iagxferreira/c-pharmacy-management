//
// Created by Iago Ferreira on 22/01/2021.
//

#ifndef PHARMACY_MODEL_VENDEDOR_H
#define PHARMACY_MODEL_VENDEDOR_H

#include "../utils/Utils.h"

typedef struct{
    int id;
    char matricula[TAMANHO_MATRICULA];
    char nome[TAMANHO_NOME];
    char cpf[TAMANHO_CPF];
    char email[TAMANHO_EMAIL];
    char telefone[TAMANHO_TELEFONE];
}Vendedor;

#endif //PHARMACY_MODEL_VENDEDOR_H
