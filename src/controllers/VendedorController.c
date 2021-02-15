//
// Created by Iago Ferreira on 22/01/2021.
//
#include <stdio.h>
#include <string.h>
#include "../models/Vendedor.h"
#include "VendedorController.h"
#include "../utils/Utils.h"

int procurarVendedor(FILE* arquivo, int id){
    Vendedor vendedor;
    int posicao = 0;
    //Posicionando o file pointer no início do arquivo
    rewind(arquivo); // alternativa -> fseek(arquivo, 0, SEEK_SET);
    //Le do arquivo "arquivo", 1 registro do tamanho da estrutura "Vendedor" e guarda na variável "vendedor"
    while(fread(&vendedor, sizeof(Vendedor),1, arquivo) == 1){
        if (vendedor.id == id) {
            return posicao;
        }else
            posicao++;
    }
    return -1;
}

void atualizarVendedor(FILE* arquivo){
    Vendedor vendedor;
    printf("\nForneça o id do vendedor: ");
    scanf("%d", &vendedor.id);
    int posicao = procurarVendedor(arquivo, vendedor.id);
    if(posicao != -1) {
        lerString(vendedor.nome, TAMANHO_NOME, "Forneça o nome do vendedor: ");

        do{
            lerString(vendedor.cpf, TAMANHO_CPF, "Forneça o CPF do vendedor: ");
        }while(validaCPF(vendedor.cpf));

        do{
            lerString(vendedor.email, TAMANHO_EMAIL, "Forneça o e-mail do vendedor: ");
        }while(verificaEmailVendedor(arquivo, vendedor.email));

        lerString(vendedor.telefone, TAMANHO_TELEFONE, "Forneça o telefone do vendedor: ");

        lerString(vendedor.password, TAMANHO_PASSWORD, "Forneça a password: ");

        fseek(arquivo, sizeof(Vendedor) * vendedor.id, SEEK_SET);
        fwrite(&vendedor, sizeof(Vendedor), 1, arquivo);

    }else{
        printf("Vendedor não encontrado.");
    }
}

void listarVendedores(FILE* arquivo){
    Vendedor vendedor;
    //Posicionando o file pointer no início do arquivo
    rewind(arquivo);
    //Le do arquivo "arquivo", 1 registro do tamanho da estrutura "Vendedor" e guarda na variável "vendedor"
    while(fread(&vendedor, sizeof(Vendedor),1, arquivo) == 1)
        printf("\nId: %d\nNome: %s\nCPF: %s\ne-mail: %s\nTelefone: %s",
               vendedor.id, vendedor.nome, vendedor.cpf, vendedor.email, vendedor.telefone);
}

void lerVendedor(FILE* arquivo){
    Vendedor vendedor;
    printf("\nForneça o id do vendedor: ");
    scanf("%d", &vendedor.id);
    int posicao = procurarVendedor(arquivo, vendedor.id);
    if(posicao != -1) {
        rewind(arquivo);
        fseek(arquivo, posicao * sizeof(Vendedor), SEEK_SET);
        fread(&vendedor, sizeof(Vendedor), 1, arquivo);

        printf("\nId: %d\nNome: %s\nCPF: %s\ne-mail: %s\nTelefone: %s",
               vendedor.id, vendedor.nome, vendedor.cpf, vendedor.email, vendedor.telefone);
    }
}

void cadastrarVendedor(FILE* arquivo){
    Vendedor vendedor;
    int quit;

    int id;
    char nome[TAMANHO_NOME];
    char cpf[TAMANHO_CPF];
    char email[TAMANHO_EMAIL];
    char telefone[TAMANHO_TELEFONE];
    char password[TAMANHO_PASSWORD];

    do{
        vendedor.id = gerarID(arquivo, sizeof(Vendedor));

        lerString(vendedor.nome, TAMANHO_NOME, "Forneça o nome do vendedor: ");

        do{
            lerString(vendedor.cpf, TAMANHO_CPF, "Forneça o CPF do vendedor: ");
        }while(validaCPF(vendedor.cpf));

        do{
            lerString(vendedor.email, TAMANHO_EMAIL, "Forneça o e-mail do vendedor: ");
        }while(verificaEmailVendedor(arquivo, vendedor.email) != -1);

        lerString(vendedor.telefone, TAMANHO_TELEFONE, "Forneça o telefone do vendedor: ");

        lerString(vendedor.password, TAMANHO_PASSWORD, "Forneça a password: ");

        fseek(arquivo, 0, SEEK_END);
        fwrite(&vendedor, sizeof(Vendedor), 1, arquivo);

        printf("Deseja sair?\n1- Sim 2-Não");
        scanf("%d", &quit);
    }while(quit != 1);
}

int verificaEmailVendedor(FILE* arquivo, char* email){
    Vendedor vendedor;
    int posicao;
    while(fread(&vendedor, sizeof(Vendedor),1, arquivo) == 1){
        if (vendedor.email == email) {
            return posicao;
        }else
            posicao++;
    }
}
