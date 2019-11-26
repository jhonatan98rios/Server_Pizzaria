#include "utils.h"

void Relatorio(char route[20]){

    char ano[8] = "";
    char mes[4] = "";
    char dia[4] = "";

    char data[20] = "";
    char path[60] = "";

    float total = 0.0;

    int index = 1;

    printf("   ----------------------------- Relatorios Mensais -----------------------------\n\n");
    printf("\nInforme o ano (ex: 2019): ");
    scanf("%s", ano);
    fflush(stdin);

    printf("Informe o mes (ex: 01): ");
    scanf("%s", mes);
    strcat(mes, "-");
    fflush(stdin);

// ============== Percorre todos os arquivos de relatorios ==========================

    for(index=1; index <= 31; index++){

        strcpy(data, "");
        strcpy(path, route);

        if(index<10){
            sprintf(dia, "0%d", index);
        }else{
            sprintf(dia, "%d", index);
        }
        
        strcat(dia, "-");
        strcat(data, dia);
        strcat(data, mes);
        strcat(data, ano);

        strcat(path, data);
        strcat(path, ".dat");

/* ================ Lê todos os arquivos ================ */

    FILE *infile;
        struct produtos prodt;
        infile = fopen(path, "r");
        if(infile != NULL){ /* Se o arquivo existir */
            printf("----------------------------- Dia %s -----------------------------\n\n", data);
            while(fread(&prodt, sizeof(struct produtos), 1, infile)){
                printf("\n\n      Nome.......: %s", prodt.name);
                printf("\n      Preco......: %.2f", prodt.price);
                printf("\n      Quantidade.: %d\n\n", prodt.quant);
                total += prodt.price;
            }
            fclose (infile);
        }
        
    /* for end */
    }

    printf("\nO lucro total nesse mes, foi de: R$ %.2f \n", total);

}

//========================================================================================================

void RelatorioGeral(){
    char ano[8] = "";
    char mes[4] = "";
    char dia[4] = "";

    char data[20] = "";
    char path[60] = "";

    float total = 0.0;

    int index = 1;
    int pizz = 1;;

    printf("   ----------------------------- Relatorios Mensais -----------------------------\n\n");
    printf("\nInforme o ano (ex: 2019): ");
    scanf("%s", ano);
    fflush(stdin);

    printf("Informe o mes (ex: 01): ");
    scanf("%s", mes);
    strcat(mes, "-");
    fflush(stdin);

// ============== Percorre todos os arquivos de relatorios ==========================

    for(index=1; index <= 31; index++){
        for(pizz=1; pizz <= 3; pizz ++){

            //Verifica os 3 diretorios
            if(pizz == 1){
                strcpy(path, ".\\Pizzaria_1\\data\\relatorio\\");
            }else if(pizz == 2){
                strcpy(path, ".\\Pizzaria_2\\data\\relatorio\\");
            }else if(pizz == 3){
                strcpy(path, ".\\Pizzaria_3\\data\\relatorio\\");
            }

            //Limpa as variaveis

            strcpy(data, "");
            
            if(index<10){
                sprintf(dia, "0%d", index);
            }else{
                sprintf(dia, "%d", index);
            }
            
            strcat(dia, "-");
            strcat(data, dia);
            strcat(data, mes);
            strcat(data, ano);

            strcat(path, data);
            strcat(path, ".dat");

/* ================ Lê todos os arquivos ================ */

            FILE *infile;
            struct produtos prodt;
            infile = fopen(path, "r");
            if(infile != NULL){ /* Se o arquivo existir */
                printf("----------------------------- Pizzaria %d -----------------------------\n\n", pizz);
                printf("----------------------------- Dia %s -----------------------------\n\n", data);
                while(fread(&prodt, sizeof(struct produtos), 1, infile)){
                    printf("\n\n      Nome.......: %s", prodt.name);
                    printf("\n      Preco......: %.2f", prodt.price);
                    printf("\n      Quantidade.: %d\n\n", prodt.quant);
                    total += prodt.price;
                }
                fclose (infile);
            }
        
    /* for ends */
        }
    }

    printf("\nO lucro total nesse mes, foi de: R$ %.2f \n", total);
}

//========================================================================================================

int main(){

    setlocale(LC_ALL, "Portuguese_Brasil");
    //Define a cor azul do terminal
    system("color 1F");
    //define o titulo da janela do prompt
    system("title Relatorios");

   int resposta;

   printf("   ---------------------------------------------------------------------------------\n");
   printf("  |                           Opcoes disponiveis:                                   |\n");
   printf("  |                                                                                 |\n");
   printf("  |                  (1) Pizzaria 1        (2) Pizzaria 2                           |\n");
   printf("  |                  (3) Pizzaria 3        (4) Relatorios Gerais                    |\n");
   printf("  |                  (0) Cancelar                                                   |\n");
   printf("   ---------------------------------------------------------------------------------\n");
   printf("\n \n Selecione uma das opcoes acima: ");
   scanf("%d", &resposta);

    switch (resposta){
    case 1:
        Relatorio(".\\Pizzaria_1\\data\\relatorio\\");
        break;
    case 2:
        Relatorio(".\\Pizzaria_2\\data\\relatorio\\");
        break;
    case 3:
        Relatorio(".\\Pizzaria_3\\data\\relatorio\\");
        break;
    case 4:
        RelatorioGeral();
        break;
    default:
        system("exit");
    }

    voltarMenu();

}