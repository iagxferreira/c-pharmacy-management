cmake_minimum_required(VERSION 3.17)
project(pharmacy-management C)

set(CMAKE_C_STANDARD 99)

add_executable(
        pharmacy-management
        main.c
        Pharmacy.c Pharmacy.h
        models/Cliente.h
        models/Produto.h
        models/NotaFiscal.h
        models/NotaFiscalItem.h
        models/Vendedor.h
        models/Fornecedor.h
        models/NotaCompra.h
        models/ItemCompra.h
        controllers/ClienteController.c controllers/ClienteController.h
        controllers/ProdutoController.c controllers/ProdutoController.h
        utils/Utils.h
        view/Menu.c view/Menu.h
)