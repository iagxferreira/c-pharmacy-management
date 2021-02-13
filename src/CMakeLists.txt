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
        controllers/CompraController.c controllers/CompraController.h
        controllers/FornecedorController.c controllers/FornecedorController.h
        controllers/NotaCompraController.c controllers/NotaCompraController.h
        controllers/NotaFiscalController.c controllers/NotaFiscalController.h
        controllers/ProdutoController.c controllers/ProdutoController.h
        controllers/RelatorioController.c controllers/RelatorioController.h
        controllers/VendaController.c controllers/VendaController.h
        controllers/VendedorController.c controllers/VendedorController.h
        view/Menu.c view/Menu.h
)