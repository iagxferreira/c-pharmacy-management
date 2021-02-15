//
// Created by Iago Ferreira on 22/01/2021.
//

#ifndef PHARMACY_CONTROLLER_PRODUTO_H
#define PHARMACY_CONTROLLER_PRODUTO_H

#include "../utils/Utils.h"

int procurarProduto(FILE*, int);

void cadastrarProduto(FILE*);

void lerProduto(FILE*);

void atualizarProduto(FILE*);

void listarProdutos(FILE*);

#endif //PHARMACY_CONTROLLER_PRODUTO_H