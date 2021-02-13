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

        lerString(fornecedor.cnpj, TAMANHO_CNPJ, "\nForneça o CNPJ do fornecedor: ");

        lerString(fornecedor.nome, TAMANHO_NOME, "\nForneça o nome do fornecedor: ");

        lerString(fornecedor.email, TAMANHO_EMAIL, "\nForneça o e-mail do fornecedor: ");

        lerString(fornecedor.telefone, TAMANHO_TELEFONE, "\nForneça o telefone do fornecedor: ");

        fseek(arquivo, 0, SEEK_END);
        fwrite(&fornecedor, sizeof(Fornecedor), 1, arquivo);
    }else{
        printf("\nFornecedor nao encontrado.");
    }
}

void listarFornecedores(FILE* arquivo){
    Fornecedor fornecedor;
    //Posicionando o file pointer no início do arquivo
    rewind(arquivo);
    //Le do arquivo "arquivo", 1 registro do tamanho da estrutura "Fornecedor" e guarda na variável "cliente"
    while(fread(&fornecedor, sizeof(Fornecedor),1, arquivo) == 1)
        printf("\nId: %d\nNome: %s\nCNPJ: %s\ne-mail: %s\nTelefone: %s",
               fornecedor.id, fornecedor.nome, fornecedor.cnpj,fornecedor.email, fornecedor.telefone);
}

void lerFornecedor(FILE* arquivo){
    Fornecedor fornecedor;
    int id, posicao;
    printf("\nForneça o id: ");
    scanf("%d", &id);
    posicao = procurarFornecedor(arquivo, id);
    if(posicao != -1) {
        rewind(arquivo);
        fseek(arquivo, posicao * sizeof(Fornecedor), SEEK_SET);
        fread(&fornecedor, sizeof(Fornecedor), 1, arquivo);
        printf("\nId: %d\nNome: %s\nCNPJ: %s\ne-mail: %s\nTelefone: %s",
               fornecedor.id, fornecedor.nome, fornecedor.cnpj,fornecedor.email, fornecedor.telefone);
    }
}

void deletarFornecedor(FILE* arquivo){
    printf("ok");
}

void cadastrarFornecedor(FILE* arquivo){
    Fornecedor fornecedor;
    int quit;
    fornecedor.id = gerarID(arquivo, sizeof(Fornecedor));
    do{

        lerString(fornecedor.cnpj, TAMANHO_CNPJ, "Forneça o CNPJ do fornecedor: ");

        lerString(fornecedor.nome, TAMANHO_NOME, "Forneça o nome do fornecedor: ");

        lerString(fornecedor.email, TAMANHO_EMAIL, "Forneça o e-mail do fornecedor: ");

        lerString(fornecedor.telefone, TAMANHO_TELEFONE, "Forneça o telefone do fornecedor: ");

        fseek(arquivo, 0, SEEK_END);
        fwrite(&fornecedor, sizeof(Fornecedor), 1, arquivo);
        printf("Deseja sair?\n1- Sim 2-Não");
        scanf("%d", &quit);
    }while(quit != 1);
}
