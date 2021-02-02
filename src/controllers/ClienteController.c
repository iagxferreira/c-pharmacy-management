//
// Created by Iago Ferreira on 22/01/2021.
//
#include <stdio.h>
#include "../models/Cliente.h"
#include "ClienteController.h"

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
    printf("\nForneça a matrícula: ");
    scanf("%d", &id);
    posicao = procurarCliente(arquivo, id);
    if(posicao != -1) {
        setbuf(stdin, NULL);
        printf("Forneça o nome do funcionário: ");
        fgets(cliente.nome, TAMANHO_NOME, stdin);
        setbuf(stdin, NULL);
        printf("Forneça o CPF do funcionário: ");
        fgets(cliente.cpf, TAMANHO_CPF, stdin);
        setbuf(stdin, NULL);
        printf("Forneça o telefone do funcionário: ");
        fgets(cliente.email, TAMANHO_EMAIL, stdin);
        setbuf(stdin, NULL);
        printf("Forneça o telefone do funcionário: ");
        fgets(cliente.telefone, TAMANHO_TELEFONE, stdin);
        setbuf(stdin, NULL);
        fseek(arquivo, 0, SEEK_END);
        fwrite(&cliente, sizeof(Cliente), 1, arquivo);
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

void deletarCliente(FILE* arquivo){
    printf("ok");
}

void cadastrarCliente(FILE* arquivo){
    Cliente cliente;
    int quit;
    do{
        printf("\nForneça a matrícula: ");
        scanf("%d", &cliente.id);
        if(procurarCliente(arquivo, cliente.id) == -1){
            setbuf(stdin, NULL);
            printf("Forneça o nome do funcionário: ");
            fgets(cliente.nome, TAMANHO_NOME, stdin);
            setbuf(stdin, NULL);
            printf("Forneça o CPF do funcionário: ");
            fgets(cliente.cpf, TAMANHO_CPF, stdin);
            fseek(arquivo, 0, SEEK_END);
            fwrite(&cliente, sizeof(Cliente), 1, arquivo);
        }else{
            printf("Matrícula já cadastrada");
            break;
        }
        printf("Deseja sair?\n1- Sim 2-Não");
        scanf("%d", &quit);
    }while(quit != 1);
}
