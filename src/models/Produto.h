//
// Created by Iago Ferreira on 22/01/2021.
//

#ifndef PHARMACY_MODEL_PRODUTO_H
#define PHARMACY_MODEL_PRODUTO_H

#include "../utils/Utils.h"

typedef struct{
    int id;
    char nome[TAMANHO_NOME];
    int quantidadeEstoque;
    float valorVenda;
}Produto;

#endif //PHARMACY_MODEL_PRODUTO_H
