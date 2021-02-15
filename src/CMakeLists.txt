cmake_minimum_required(VERSION 3.17)
project(pharmacy-management C)

set(CMAKE_C_STANDARD 99)

add_executable(
        pharmacy-management
        main.c
        utils/Utils.h utils/Utils.c
        Pharmacy.c Pharmacy.h
        models/Cliente.h
        models/Fornecedor.h
        models/ItemCompra.h
        models/ItemNotaFiscal.h
        models/NotaCompra.h
        models/NotaFiscal.h
        models/Produto.h
        models/Vendedor.h
        controllers/ClienteController.c controllers/ClienteController.h
        controllers/FornecedorController.c controllers/FornecedorController.h
        controllers/ProdutoController.c controllers/ProdutoController.h
        controllers/VendedorController.c controllers/VendedorController.h
        view/Menu.c view/Menu.h
)