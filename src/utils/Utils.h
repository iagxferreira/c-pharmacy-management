//
// Created by Iago Ferreira on 27/01/2021.
//

#ifndef PHARMACY_MANAGEMENT_UTILS_H
#define PHARMACY_MANAGEMENT_UTILS_H

#include <string.h>
#include <stdio.h>

#define TAMANHO_CPF 12
#define TAMANHO_CNPJ 15
#define TAMANHO_NOME 100
#define TAMANHO_EMAIL 50
#define TAMANHO_TELEFONE 15
#define TAMANHO_MATRICULA 10
#define TAMANHO_CNPJ 15
#define TAMANHO_NUMERO 10
#define TAMANHO_DATA 11
#define TAMANHO_NOTA 8


#define ARQUIVO_CLIENTE "Cliente.dat"
#define ARQUIVO_PRODUTO "Produto.dat"
#define ARQUIVO_VENDEDOR "Vendedor.dat"
#define ARQUIVO_NOTAFISCAL "NotaFiscal.dat"

void lerString(char*, int, const char*);

void lerInteiro(int*);

int estaNoIntervalo(const int, int, int);

int validaCPF(char*);

int verificaInteiros(const char*, int);

int integridadeCPF(char*);

int gerarID(FILE*, size_t);

#endif //PHARMACY_MANAGEMENT_UTILS_H
