//
// Created by Iago Ferreira on 22/01/2021.
//

#ifndef C_PHARMACY_MODEL_VENDEDOR_H
#define C_PHARMACY_MODEL_VENDEDOR_H

typedef struct{
    int id;
    char matricula[10];
    char nome[100];
    char cpf[12];
    char email[50];
    char telefone[15];
}Vendedor;

#endif //C_PHARMACY_MODEL_VENDEDOR_H
