//
// Created by Iago Ferreira on 22/01/2021.
//

#ifndef PHARMACY_CONTROLLER_VENDEDOR_H
#define PHARMACY_CONTROLLER_VENDEDOR_H

#include "../utils/Utils.h"
#include <stdio.h>

int procurarVendedor(FILE*, int);

void cadastrarVendedor(FILE*);

void lerVendedor(FILE*);

void atualizarVendedor(FILE*);

void listarVendedores(FILE*);

int verificaEmailVendedor(FILE* arquivo, char* email);

#endif //PHARMACY_CONTROLLER_VENDEDOR_H