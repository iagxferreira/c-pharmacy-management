//
// Created by Iago Ferreira on 22/01/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "../models/Cliente.h"
#include "../models/Produto.h"
#include "../controllers/ClienteController.h"
#include "../controllers/ProdutoController.h"
#include "Menu.h"



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
    FILE *arquivoProdutos;
    int opcao = 0;
    arquivoProdutos = fopen(ARQUIVO_PRODUTO, "rb+");
    if (arquivoProdutos == NULL)
        arquivoProdutos = fopen(ARQUIVO_PRODUTO, "wb+");
    if (arquivoProdutos != NULL) {
        do {
            printf("\n\n-----Produto-----\n\n1- Cadastro\n2- Consulta\n3- Alterar\n4- Listar\n5- Deletar\n0- Sair: ");
            scanf("%d", &opcao);
            switch (opcao) {
                case 1:
                    cadastrarProduto(arquivoProdutos);
                    break;
                case 2:
                    lerProduto(arquivoProdutos);
                    break;
                case 3:
                    atualizarProduto(arquivoProdutos);
                    break;
                case 4:
                    listarProdutos(arquivoProdutos);
                    break;
                case 5:
                    deletarProduto(arquivoProdutos);
                    break;
            }
        }while (opcao != 0);
    }
    return 0;
}