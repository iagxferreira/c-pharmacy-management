//
// Created by Iago Ferreira on 22/01/2021.
//
#include <stdio.h>
#include "../models/Produto.h"
#include "ProdutoController.h"
#include "../utils/Utils.h"

int procurarProduto(FILE* arquivo, int id){
    Produto produto;
    int posicao = 0;
    //Posicionando o file pointer no início do arquivo
    rewind(arquivo); // alternativa -> fseek(arquivo, 0, SEEK_SET);
    //Le do arquivo "arquivo", 1 registro do tamanho da estrutura "Produto" e guarda na variável "produto"
    while(fread(&produto, sizeof(Produto),1, arquivo) == 1){
        if (produto.id == id) {
            return posicao;
        }else
            posicao++;
    }
    return -1;
}

void atualizarProduto(FILE* arquivo){
    Produto produto;
    printf("\nForneça o id do produto: ");
    scanf("%d", &produto.id);
    int posicao = procurarProduto(arquivo, produto.id);
    if(posicao != -1) {
        setbuf(stdin, NULL);
        printf("Forneça o nome do produto: ");
        fgets(produto.nome, TAMANHO_NOME, stdin);
        setbuf(stdin, NULL);
        printf("Forneça a quantidade de estoque do produto: ");
        scanf("%d", &produto.quantidadeEstoque);
        printf("Forneça o valor de venda do produto: ");
        scanf("%f", &produto.valorVenda);
        fseek(arquivo, 0, SEEK_END);
        fwrite(&produto, sizeof(Produto), 1, arquivo);
    }else{
        printf("Produto não encontrado.");
    }
}

void listarProdutos(FILE* arquivo){
    Produto produto;
    //Posicionando o file pointer no início do arquivo
    rewind(arquivo);
    //Le do arquivo "arquivo", 1 registro do tamanho da estrutura "Produto" e guarda na variável "produto"
    while(fread(&produto, sizeof(Produto),1, arquivo) == 1)
        printf("\nId: %d\nNome: %s\nQuantidade em estoque: %d\nValor de venda: %f\n",
               produto.id, produto.nome, produto.quantidadeEstoque, produto.valorVenda);
}

void lerProduto(FILE* arquivo){
    Produto produto;
    printf("\nForneça o id do produto: ");
    scanf("%d", &produto.id);
    int posicao = procurarProduto(arquivo, produto.id);
    if(posicao != -1) {
        rewind(arquivo);
        fseek(arquivo, posicao * sizeof(produto), SEEK_SET);
        fread(&produto, sizeof(Produto), 1, arquivo);
        printf("\nId: %d\nNome: %s\nQuantidade em estoque: %d\nValor de venda: %f\n", produto.id, produto.nome, produto.quantidadeEstoque, produto.valorVenda);
    }
}

void deletarProduto(FILE* arquivo){
    printf("ok");
}

void cadastrarProduto(FILE* arquivo){
    Produto produto;
    int quit;
    do{
        produto.id = gerarID(arquivo, sizeof(Produto));
        if(procurarProduto(arquivo, produto.id) == -1){
            setbuf(stdin, NULL);
            printf("Forneça o nome do produto: ");
            fgets(produto.nome, TAMANHO_NOME, stdin);
            setbuf(stdin, NULL);
            printf("Forneça a quantidade de estoque do produto: ");
            scanf("%d", &produto.quantidadeEstoque);
            printf("Forneça o valor de venda do produto: ");
            scanf("%f", &produto.valorVenda);
            fwrite(&produto, sizeof(Produto), 1, arquivo);
        }else{
            printf("Produto já cadastrado!");
            break;
        }
        printf("Deseja sair?\n1- Sim 2-Não");
        scanf("%d", &quit);
    }while(quit != 1);
}
