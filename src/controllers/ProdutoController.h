//
// Created by Iago Ferreira on 22/01/2021.
//

#ifndef C_PHARMACY_CONTROLLER_PRODUTO_H
#define C_PHARMACY_CONTROLLER_PRODUTO_H
#include "../utils/Utils.h"

int procurarProduto(FILE*, int);

void cadastrarProduto(FILE*);

void lerProduto(FILE*);

void atualizarProduto(FILE*);

void listarProdutos(FILE*);

void deletarProduto(FILE*);


#endif //C_PHARMACY_MODEL_PRODUTO_H
