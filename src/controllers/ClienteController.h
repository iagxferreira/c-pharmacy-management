//
// Created by Iago Ferreira on 22/01/2021.
//

#ifndef PHARMACY_CONTROLLER_CLIENTE_H
#define PHARMACY_CONTROLLER_CLIENTE_H

int procurarCliente(FILE*, int);

void cadastrarCliente(FILE*);

void lerCliente(FILE*);

void atualizarCliente(FILE*);

void listarClientes(FILE*);

void deletarCliente(FILE*);

#endif //PHARMACY_CONTROLLER_CLIENTE_H