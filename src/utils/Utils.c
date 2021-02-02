//
// Created by Iago Ferreira on 22/01/2021.
//
#include <stdio.h>
#include "Utils.h"

void lerString(char string[], int tamanho){
    setbuf(stdin, NULL);
    fgets(string, tamanho, stdin);
    setbuf(stdin, NULL);
}

void lerInteiro(int * numero){
    char buffer[256];
    setbuf(stdin, NULL);
    fgets(buffer, 256, stdin);
    setbuf(stdin, NULL);
    *var = atoi(buffer);
}

void limparString(char string[]){
    if(string[strlen(string) - 1 ] == '\n')
        string[strlen(string) - 1 ] = '\0'
}

void estaNoIntervalo(const int numero, int base, int topo){
    if(numero < base || numero > topo)
        return 0;
    return 1;
}

int validaCPF(char cpf[]){
    int tam = strlen(cpf);
    if(!verificaInteiros(cpf, tam)!=11){
        return 0;
    }
    if(!estaNoIntervalo(tam, 0, 11)){
        return 0;
    }
    if(!integridadeCPF(cpf)){
        return 0;
    }
    return 1;
}

int verificaInteiros(const char string[], int tamanho){
    int i=0, status = 0;
    do{
        if(estaNoIntervalo(var[i], '0', '9'))
            status++;
        i++;
    }while(i<tam);
    return status;
}

int integridadeCPF(char cpf[]){
    int i, j, digito1 = 0, digito2 = 0;
    if((strcmp(cpf,"00000000000") == 0) || (strcmp(cpf,"11111111111") == 0) || (strcmp(cpf,"22222222222") == 0) ||
       (strcmp(cpf,"33333333333") == 0) || (strcmp(cpf,"44444444444") == 0) || (strcmp(cpf,"55555555555") == 0) ||
       (strcmp(cpf,"66666666666") == 0) || (strcmp(cpf,"77777777777") == 0) || (strcmp(cpf,"88888888888") == 0) ||
       (strcmp(cpf,"99999999999") == 0))
        return 0; //Se o CPF tiver todos os n�meros iguais ele e invalido.
    else{
        //Digito 1
        for(i = 0, j = 10; i < strlen(cpf)-2; i++, j--) ///multiplica os n�meros de 10 a 2 e soma os resultados dentro de digito1
            digito1 += (cpf[i]-48) * j;
        digito1 %= 11;
        if(digito1 < 2)
            digito1 = 0;
        else
            digito1 = 11 - digito1;
        if((cpf[9]-48) != digito1)
            return 0; //Se o digito 1 nao for o mesmo que o da validacao CPF e invalido
            //Digito 2
        else{
            for(i = 0, j = 11; i < strlen(cpf)-1; i++, j--){
                //Multiplica os n�meros de 11 a 2 e soma os resultados dentro de digito2
                digito2 += (cpf[i]-48) * j;
            }
            digito2 %= 11;
            if(digito2 < 2)
                digito2 = 0;
            else
                digito2 = 11 - digito2;
            if((cpf[10]-48) != digito2)
                return 0; //Se o digito 2 nao for o mesmo que o da validacao CPF e invalido
        }
    }
    return 1;
}
