//
// Created by Iago Ferreira on 22/01/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "../controllers/ClienteController.h"
#include "../controllers/ProdutoController.h"
#include "../controllers/VendedorController.h"
#include "../controllers/FornecedorController.h"

#include "Menu.h"

int menu(){
    int opcao = 0;
    do {
        system("cls");
        printf("\n\n-----Pharmacy Management-----\n\n1- Clientes\n2- Vendedores\n3- Fornecedores\n4- Produtos\n"
               "5- Efetuar Venda\n6- Efetuar Compra\n7- Atualizar Preco\n8- Relatorios\n0-Sair: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                menuCliente();
                break;
            case 2:
                menuVendedor();
                break;
            case 3:
                menuFornecedor();
                break;
            case 4:
                menuProduto();
                break;
            case 5:
                menuEfetuarVenda();
                break;
            case 6:
                menuEfetuarCompra();
                break;
            case 7:
                menuAtualizarPreco();
                break;
            case 8:
                menuRelatorios();
        }
    }while (opcao != 0);
    return 0;
}

int menuCliente() {
    FILE *arquivoClientes;
    int opcao = 0;
    arquivoClientes = fopen(ARQUIVO_CLIENTE, "rb+");
    if (arquivoClientes == NULL)
        arquivoClientes = fopen(ARQUIVO_CLIENTE, "wb+");
    if (arquivoClientes != NULL) {
        do {
            system("cls");
            printf("\n\n-----Cliente-----\n\n1- Cadastro\n2- Consulta\n3- Alterar\n4- Listar\n5- Deletar\n0- Sair: ");
            scanf("%d", &opcao);
            switch (opcao) {
                case 1:
                    cadastrarCliente(arquivoClientes);
                    break;
                case 2:
                    lerCliente(arquivoClientes);
                    break;
                case 3:
                    atualizarCliente(arquivoClientes);
                    break;
                case 4:
                    listarClientes(arquivoClientes);
                    break;
                case 5:
                    deletarCliente(arquivoClientes);
                    break;
            }
        }while (opcao != 0);
    }
    return 0;
}

int menuProduto() {
    FILE *arquivo;
    int opcao = 0;
    arquivo = fopen(ARQUIVO_PRODUTO, "rb+");
    if (arquivo == NULL)
        arquivo = fopen(ARQUIVO_PRODUTO, "wb+");
    if (arquivo != NULL) {
        do {
            printf("\n\n-----Produto-----\n\n1- Cadastro\n2- Consulta\n3- Alterar\n4- Listar\n5- Deletar\n0- Sair: ");
            scanf("%d", &opcao);
            switch (opcao) {
                case 1:
                    cadastrarProduto(arquivo);
                    break;
                case 2:
                    lerProduto(arquivo);
                    break;
                case 3:
                    atualizarProduto(arquivo);
                    break;
                case 4:
                    listarProdutos(arquivo);
                    break;
                case 5:
                    deletarProduto(arquivo);
                    break;
            }
        }while (opcao != 0);
    }
    return 0;
}

int menuVendedor() {
    FILE *arquivo;
    int opcao = 0;
    arquivo = fopen(ARQUIVO_VENDEDOR, "rb+");
    if (arquivo == NULL)
        arquivo = fopen(ARQUIVO_VENDEDOR, "wb+");
    if (arquivo != NULL) {
        do {
            system("cls");
            printf("\n\n-----Vendedor-----\n\n1- Cadastro\n2- Consulta\n3- Alterar\n4- Listar\n5- Deletar\n0- Sair: ");
            scanf("%d", &opcao);
            switch (opcao) {
                case 1:
                    cadastrarVendedor(arquivo);
                    break;
                case 2:
                    lerVendedor(arquivo);
                    break;
                case 3:
                    atualizarVendedor(arquivo);
                    break;
                case 4:
                    listarVendedores(arquivo);
                    break;
                case 5:
                    deletarVendedor(arquivo);
                    break;
            }
        }while (opcao != 0);
    }
    return 0;
}

int menuFornecedor() {
    FILE *arquivo;
    int opcao = 0;
    arquivo = fopen(ARQUIVO_CLIENTE, "rb+");
    if (arquivo == NULL)
        arquivo = fopen(ARQUIVO_CLIENTE, "wb+");
    if (arquivo != NULL) {
        do {
            system("cls");
            printf("\n\n-----Cliente-----\n\n1- Cadastro\n2- Consulta\n3- Alterar\n4- Listar\n5- Deletar\n0- Sair: ");
            scanf("%d", &opcao);
            switch (opcao) {
                case 1:
                    cadastrarFornecedor(arquivo);
                    break;
                case 2:
                    lerFornecedor(arquivo);
                    break;
                case 3:
                    atualizarFornecedor(arquivo);
                    break;
                case 4:
                    listarFornecedores(arquivo);
                    break;
                case 5:
                    deletarFornecedor(arquivo);
                    break;
            }
        }while (opcao != 0);
    }
    return 0;
}

int menuEfetuarVenda() {
    FILE *arquivo;
    int opcao = 0;
    arquivo = fopen(ARQUIVO_CLIENTE, "rb+");
    if (arquivo == NULL)
        arquivo = fopen(ARQUIVO_CLIENTE, "wb+");
    if (arquivo != NULL) {
        do {
            system("cls");
            printf("\n\n-----Cliente-----\n\n1- Cadastro\n2- Consulta\n3- Alterar\n4- Listar\n5- Deletar\n0- Sair: ");
            scanf("%d", &opcao);
            switch (opcao) {
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
            }
        }while (opcao != 0);
    }
    return 0;
}

int menuEfetuarCompra(){
    FILE *arquivoClientes;
    int opcao = 0;
    arquivoClientes = fopen(ARQUIVO_CLIENTE, "rb+");
    if (arquivoClientes == NULL)
        arquivoClientes = fopen(ARQUIVO_CLIENTE, "wb+");
    if (arquivoClientes != NULL) {
        do {
            system("cls");
            printf("\n\n-----Cliente-----\n\n1- Cadastro\n2- Consulta\n3- Alterar\n4- Listar\n5- Deletar\n0- Sair: ");
            scanf("%d", &opcao);
            switch (opcao) {
                case 1:
                    cadastrarCliente(arquivoClientes);
                    break;
                case 2:
                    lerCliente(arquivoClientes);
                    break;
                case 3:
                    atualizarCliente(arquivoClientes);
                    break;
                case 4:
                    listarClientes(arquivoClientes);
                    break;
                case 5:
                    deletarCliente(arquivoClientes);
                    break;
            }
        }while (opcao != 0);
    }
    return 0;
}

int menuAtualizarPreco(){
    return 1;
}

int menuRelatorios(){
    return 1;
}