#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
#include <locale.h>
#include <locale.h>

struct produtos{
    int id;
    int category; 
    char name[20];
    float price;
    int quant;
};

void voltarMenu(){

    int continuar;

    printf("   ---------------------------------------------------------------------------------\n");
    printf("   Deseja voltar ao menu?\n");
    printf("   [1] Sim \n");
    printf("   [0] Nao\n");
    scanf("%d", &continuar);
    if(continuar == 1){
        system(".\\dist\\Relatorios");
    }else{
        printf("--------------------\n");
        printf("| Programa Encerrado |\n");
        printf("--------------------\n");
        
    }
};

void cab(){
    system("cls");
    printf("\n");
    printf("   ---------------------------------------------------------------------------------\n");
    printf("  |                                                                                 |\n");
    printf("  |                              Sistema para Pizzaria                              |\n");
    printf("  |                                                                                 |\n");
    printf("  |                                    Unip 2019                                    |\n");
    printf("  |                                                                                 |\n");
    printf("   ---------------------------------------------------------------------------------\n");
    printf("\n");

}


#endif