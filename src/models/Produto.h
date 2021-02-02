//
// Created by Iago Ferreira on 22/01/2021.
//

#ifndef C_PHARMACY_MODEL_PRODUTO_H
#define C_PHARMACY_MODEL_PRODUTO_H

typedef struct{
    int id;
    char nome[100];
    int quantidadeEstoque;
    float valorVenda;
}Produto;

#endif //C_PHARMACY_MODEL_PRODUTO_H
