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
        models/ItemNotaFiscal.h
        models/Vendedor.h
        models/Fornecedor.h
        models/NotaCompra.h
        models/ItemCompra.h
        controllers/FornecedorController.c controllers/ClienteController.h
        controllers/ProdutoController.c controllers/ProdutoController.h
        utils/Utils.h
        view/Menu.c view/Menu.h
        controllers/NotaFiscalController.c controllers/NotaFiscalController.h controllers/CompraController.cpp controllers/CompraController.h controllers/VendaController.c controllers/VendaController.h controllers/NotaCompraController.cpp controllers/NotaCompraController.h controllers/RelatorioController.c controllers/RelatorioController.h)