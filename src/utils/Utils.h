//
// Created by Iago Ferreira on 27/01/2021.
//

#ifndef C_PHARMACY_MANAGEMENT_UTILS_H
#define C_PHARMACY_MANAGEMENT_UTILS_H
#include <string.h>

#define TAMANHO_CPF 12
#define TAMANHO_CNPJ 15
#define TAMANHO_NOME 100
#define TAMANHO_EMAIL 50
#define TAMANHO_TELEFONE 15


#define ARQUIVO_CLIENTE "Cliente.dat"
#define ARQUIVO_PRODUTO "Produto.dat"
#define ARQUIVO_VENDEDOR "Vendedor.dat"
#define ARQUIVO_NOTAFISCAL "NotaFiscal.dat"

void lerString(char*, int);

void lerInteiro(int*);

void limparString(char*);

void estaNoIntervalo(const int, int, int);

int validaCPF(char*);

int verificaInteiros(const char*, int);

int integridadeCPF(char*);



#endif //C_PHARMACY_GESTOR_UTILS_H
