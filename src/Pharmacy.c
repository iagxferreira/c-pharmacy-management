//
// Created by Iago Ferreira on 22/01/2021.
//

#include <locale.h>
#include "Pharmacy.h"
#include "view/Menu.h"

int init(){
    setlocale(LC_ALL, "pt_BR");
    menuCliente();
    return 0;
}