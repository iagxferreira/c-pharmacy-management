//
// Created by Iago Ferreira on 22/01/2021.
//
#include <stdio.h>
#include "../models/Fornecedor.h"
#include "FornecedorController.h"
#include "../utils/Utils.h"

int procurarFornecedor(FILE* arquivo, int id){
    Fornecedor fornecedor;
    int posicao = 0;
    //Posicionando o file pointer no início do arquivo
    rewind(arquivo); // alternativa -> fseek(arquivo, 0, SEEK_SET);

    //Le do arquivo "arquivo", 1 registro do tamanho da estrutura "Fornecedor" e guarda na variável "cliente"
    while(fread(&fornecedor, sizeof(Fornecedor),1, arquivo) == 1){
        if (fornecedor.id == id) {
            return posicao;
        }else
            posicao++;
    }
    return -1;
}

void atualizarFornecedor(FILE* arquivo){
    Fornecedor fornecedor;
    int id, posicao;
    printf("\nForneça o ID do fornecedor: ");
    scanf("%d", &id);
    posicao = procurarFornecedor(arquivo, id);
    if(posicao != -1) {

        setbuf(stdin, NULL);
        printf("Forneça o CNPJ do fornecedor: ");
        fgets(fornecedor.cnpj, TAMANHO_CNPJ, stdin);
        strtok(fornecedor.cnpj, '\n');

        setbuf(stdin, NULL);
        printf("Forneça o nome do fornecedor: ");
        fgets(fornecedor.nome, TAMANHO_NOME, stdin);
        strtok(fornecedor.nome, '\n');

        setbuf(stdin, NULL);
        printf("Forneça o email do fornecedor: ");
        fgets(fornecedor.email, TAMANHO_EMAIL, stdin);
        strtok(fornecedor.email, '\n');

        setbuf(stdin, NULL);
        printf("Forneça o telefone do fornecedor: ");
        fgets(fornecedor.telefone, TAMANHO_TELEFONE, stdin);
        strtok(fornecedor.telefone, '\n');

        fseek(arquivo, 0, SEEK_END);
        fwrite(&cliente, sizeof(Fornecedor), 1, arquivo);
    }
}

void listarFornecedores(FILE* arquivo){
    Fornecedor cliente;
    //Posicionando o file pointer no início do arquivo
    rewind(arquivo);
    //Le do arquivo "arquivo", 1 registro do tamanho da estrutura "Fornecedor" e guarda na variável "cliente"
    while(fread(&cliente, sizeof(Fornecedor),1, arquivo) == 1)
        printf("\nMatricula: %d\nNome: %s\nCPF: %s\ne-mail: %s\nTelefone: %s",
               cliente.id, cliente.nome, cliente.cpf,cliente.email, cliente.telefone);
}

void lerFornecedor(FILE* arquivo){
    Fornecedor cliente;
    int id, posicao;
    printf("\nForneça o id: ");
    scanf("%d", &id);
    posicao = procurarFornecedor(arquivo, id);
    if(posicao != -1) {
        rewind(arquivo);
        fseek(arquivo, posicao * sizeof(cliente), SEEK_SET);
        fread(&fornecedor, sizeof(Fornecedor), 1, arquivo);
        printf("\nId: %d\nName: %s\nCPF: %s\n", fornecedor.id, fornecedor.nome, fornecedor.cpf);
    }
}

void deletarFornecedor(FILE* arquivo){
    printf("ok");
}

void cadastrarFornecedor(FILE* arquivo){
    Fornecedor fornecedor;
    int quit;
    do{
        printf("\nForneça a matrícula: ");
        scanf("%d", &fornecedor.id);
        if(procurarFornecedor(arquivo, cliente.id) == -1){

            setbuf(stdin, NULL);
            printf("Forneça o CNPJ do fornecedor: ");
            fgets(fornecedor.cnpj, TAMANHO_CNPJ, stdin);
            strtok(fornecedor.cnpj, '\n');

            setbuf(stdin, NULL);
            printf("Forneça o nome do fornecedor: ");
            fgets(fornecedor.nome, TAMANHO_NOME, stdin);
            strtok(fornecedor.nome, '\n');

            setbuf(stdin, NULL);
            printf("Forneça o email do fornecedor: ");
            fgets(fornecedor.email, TAMANHO_EMAIL, stdin);
            strtok(fornecedor.email, '\n');

            setbuf(stdin, NULL);
            printf("Forneça o telefone do fornecedor: ");
            fgets(fornecedor.telefone, TAMANHO_TELEFONE, stdin);
            strtok(fornecedor.telefone, '\n');

            fseek(arquivo, 0, SEEK_END);
            fwrite(&cliente, sizeof(Fornecedor), 1, arquivo);
        }else{
            printf("Matrícula já cadastrada");
            break;
        }
        printf("Deseja sair?\n1- Sim 2-Não");
        scanf("%d", &quit);
    }while(quit != 1);
}
