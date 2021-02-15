//
// Created by Iago Ferreira on 22/01/2021.
//
#include <stdio.h>
#include "ClienteController.h"
#include "../models/Cliente.h"
#include "../utils/Utils.h"

int procurarCliente(FILE* arquivo, int id){
    Cliente cliente;
    int posicao = 0;
    //Posicionando o file pointer no início do arquivo
    rewind(arquivo); // alternativa -> fseek(arquivo, 0, SEEK_SET);

    //Le do arquivo "arquivo", 1 registro do tamanho da estrutura "Cliente" e guarda na variável "cliente"
    while(fread(&cliente, sizeof(Cliente),1, arquivo) == 1){
        if (cliente.id == id) {
            return posicao;
        }else
            posicao++;
    }
    return -1;
}

void atualizarCliente(FILE* arquivo){
    Cliente cliente;
    int id, posicao;
    printf("\nForneça o ID do cliente: ");
    scanf("%d", &id);
    posicao = procurarCliente(arquivo, id);
    if(posicao != -1) {

        lerString(cliente.nome, TAMANHO_NOME, "Forneça o nome do cliente: ");

        lerString(cliente.cpf, TAMANHO_CPF, "Forneça o CPF do cliente: ");

        lerString(cliente.email, TAMANHO_EMAIL, "Forneça o e-mail do cliente: ");

        lerString(cliente.telefone, TAMANHO_TELEFONE, "Forneça o telefone do cliente: ");

        fseek(arquivo, posicao*sizeof(Cliente), SEEK_SET);
        fwrite(&cliente, sizeof(Cliente), 1, arquivo);
    }else{
        printf("Cliente nao encontrado. ");
    }
}

void listarClientes(FILE* arquivo){
    Cliente cliente;
    //Posicionando o file pointer no início do arquivo
    rewind(arquivo);
    //Le do arquivo "arquivo", 1 registro do tamanho da estrutura "Cliente" e guarda na variável "cliente"
    while(fread(&cliente, sizeof(Cliente),1, arquivo) == 1)
        printf("\nMatricula: %d\nNome: %s\nCPF: %s\ne-mail: %s\nTelefone: %s",
               cliente.id, cliente.nome, cliente.cpf,cliente.email, cliente.telefone);
}

void lerCliente(FILE* arquivo){
    Cliente cliente;
    int id, posicao;
    printf("\nForneça a matrícula: ");
    scanf("%d", &id);
    posicao = procurarCliente(arquivo, id);
    if(posicao != -1) {
        rewind(arquivo);
        fseek(arquivo, posicao * sizeof(cliente), SEEK_SET);
        fread(&cliente, sizeof(Cliente), 1, arquivo);
        printf("\nId: %d\nName: %s\nCPF: %s\n", cliente.id, cliente.nome, cliente.cpf);
    }
}

void cadastrarCliente(FILE* arquivo){
    Cliente cliente;
    int quit;
    cliente.id = gerarID(arquivo, sizeof(Cliente));
    do{
        lerString(cliente.nome, TAMANHO_NOME, "Forneça o nome do cliente: ");

        lerString(cliente.cpf, TAMANHO_CPF, "Forneça o CPF do cliente: ");

        lerString(cliente.email, TAMANHO_EMAIL, "Forneça o e-mail do cliente: ");

        lerString(cliente.telefone, TAMANHO_TELEFONE, "Forneça o telefone do cliente: ");

        fseek(arquivo, 0, SEEK_END);
        fwrite(&cliente, sizeof(Cliente), 1, arquivo);

        printf("Deseja sair?\n1- Sim 2-Não");
        scanf("%d", &quit);
    }while(quit != 1);
}
