#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //INCLUIDE QUE PERMITE MOSTRAR OS LOGS COM ACENTUAÇÃO
#include <stdbool.h> //INCLUDE QUE PERMITE USAR VARIAVEIS BOOLEANAS.
#include <string.h>
#define senha "1234"
#define login "admQuiz"

 
int main()
{
    setlocale(LC_ALL, "pt_BR.utf8"); 

    int admOuPlayer, linha, coluna, i, j, tentativas = 1, jogador1pt = 0, jogador2pt = 0;
    char loginADM[20], senhaADM[20], res[12][12];

    char pergunta[12][100] = {"Qual o conjunto númérico do tipo de variavel double? "                      ,
                              "Qual dessas estruturas de repetição não apresenta limite de repetição? "    ,
                              "A estrutura de repetição For precisa de quantas operações para funcionar? " ,
                              "Qual desses não são tipos primitivos? ",
                              "Para mostrar uma matriz de char em C, como deve ser feito ",
                              "O tipo char tem pelo menos quantos bits? ",
                              };

    char let[5][10]= {"A --- ","B --- ","C --- ","D --- ","E --- "};

    char opcoes[100][100] = {
                                "Real", "Racionais", "Irracionais", "Complexos", "Inteiros",
                                "For", "While", "DoWhile", "Todas as anteriores", "Nenhuma das anteriores",
                                "1", "2", "3", "4", "5",
                                "Double", "Int", "Char", "void", "Bool",
                                "for(i=0; i < tamMatriz; i++){\n printf(\"%s\", matriz[i]) }",
                                "for(i=0; i < tamMatriz; i++){\n printf(\"%s\", matriz[i])\nfor(j=0; j < tamMatriz; j++){ matriz[i][j] }",
                                "printf(\"%s\", matriz)", "printf(\"%c\", matriz)",
                                "for(i=0; i < matriz.length; i++){\n printf(\"%s\", matriz[i]) }",
                                "2", "Nenhuma das alternativas", "16", "8", "4",
                            };

    int x = 0;
    int jogadorVezAlt = 1;
    int jogadorVezOpc = 1;

    char respostas[12]= {'A','E','B','E','A', 'E'};
    printf("\n\nBem vindo ao QUIZ\n\n");

    printf("Você é administrador ?\n");
    printf("[1 - Sim]\n" );
    printf("[2 - Não]\n" );
    scanf("%d", &admOuPlayer);



    if (admOuPlayer == 1) {
        bool continua     = true;//alterar para true depois
        bool acesso       = false;//alterar para false depois
        int numTentativas = 1;

        printf("TELA DE LOGIN\n\n");

        //While responsavel pelo login do administrador do Quiz.
        while(continua) {

            printf("LOGIN: ");
            scanf("%s", loginADM);
            printf("SENHA: ");
            scanf("%s", senhaADM);

            //Verifica se o login e a senha estao corretos.
            if (strcmp(loginADM ,login) == 0 && strcmp(senhaADM ,senha) == 0) {
                continua = false;
                acesso   = true;
                printf("Bem vindo ao gerenciamento do QUIZ.\n\n");
            } else {
                //Exibe mensagem de erro na tela.
                printf("ERRO, Tente novamente.\n\n");

                //Verifica o numero de tentativas.
                if(numTentativas == 3) {

                    //Exibe mensagem do limite de tentativas na tela.
                    printf("Você atingiu o limite de 3 tentativas.\n\n");
                    continua      = false;
                }
                //A cada erro é adicionado 1 ao numero de tentativas.
                numTentativas++;
            }
        }

        if (acesso) {
            printf("GERENCIAMENTO DE QUESTÕES\n\n");

            int numQuestaoAltera;
            printf("Escolha o número da questão que deseja alterar.");
            scanf("%d", &numQuestaoAltera);
            getchar();

            printf("Digite a nova alternativa.\n");
            fgets(pergunta[numQuestaoAltera], sizeof(pergunta[numQuestaoAltera]), stdin);
            
            int teste = numQuestaoAltera * 5;
            for(j = 0; j < 5; j++){
                printf("Digite as alternativas  ");
                fgets(opcoes[teste+j], sizeof(opcoes[teste+j]), stdin);
            }
            
            printf("\nDigite a alternativa correta em letra maiuscula  ");
            scanf("%c", &respostas[numQuestaoAltera]);
            // fgets(respostas[numQuestaoAltera], sizeof(respostas[numQuestaoAltera]), stdin);

            for (i = 0; i < 4; i++) {
                printf("%d - %s\n", i, pergunta[i]);

                for(j = 0; j < 5; j++){
                    printf("X -> %d | ", x);
                    printf("J -> %d ", j);
                    printf(" | %s %s\n",let[j], opcoes[j+x]);
                }
                printf("\n\n");
                x += j;
                
            }

        }

    }
    x = 0;
    for (i = 0; i < 5; i++) {
        printf("\nJOGADOR DA VEZ DA QUESTÃO %d\n", jogadorVezAlt);
        printf("%s\n", pergunta[i]);

        for(j = 0; j < 5; j++){
            printf("%s %s\n",let[j], opcoes[j+x]);
        }

        x += j;
        j = 0;

        tentativas = 0;

        while(j < 3 ){
            printf("\nJOGADOR DA VEZ DAS OPÇÕES %d\n", jogadorVezOpc);
            
            printf("\nDigite sua opção: ");
            getchar();
            tentativas++;
            //fgets(res[i], sizeof(res[i]), stdin);
            scanf("%s", &res[i][0]);
            printf("%s", res[i]);

            if(res[i][0] == respostas[i]) {

                printf("\nCORRETO\n");

                if(tentativas == 1){
                    if (jogadorVezOpc == 1) {
                        jogador1pt = jogador1pt + 10;
                        printf("\nJOGADOR 1 GANHOU - > 10 pts\n");

                    } else {
                        jogador2pt = jogador2pt + 10;
                        printf("\nJOGADOR 2 GANHOU - > 10 pts\n");

                    }
                }else if(tentativas == 2){
                    if (jogadorVezOpc == 1) {
                        jogador1pt = jogador1pt + 7;
                        printf("\nJOGADOR 1 GANHOU - > 7 pts\n");

                    } else {
                        jogador2pt = jogador2pt + 7;
                        printf("\nJOGADOR 2 GANHOU - > 7 pts\n");

                    }
                }else{
                    if (jogadorVezOpc == 1) {
                        jogador1pt = jogador1pt + 5;
                        printf("\nJOGADOR 1 GANHOU - > 5 pts\n");

                    } else {
                        jogador2pt = jogador2pt + 5;
                        printf("\nJOGADOR 2 GANHOU - > 5 pts\n");

                    }
                }
                j = 3;

            }else {
                printf("\nErrou tente novamente\n");
            }
            if (jogadorVezOpc == 1) {
                printf("\nTROCA PARA JOGADOR 2 [OPCAO]\n");
                jogadorVezOpc = 2;
            } else {
                printf("\nTROCA PARA JOGADOR 1 [OPCAO]\n");
                jogadorVezOpc = 1;
            }
            j++;
            printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
            printf("\nPONTUAÇÃO");
            printf("\nJOGADOR 01 -> %d", jogador1pt);
            printf("\nJOGADOR 02 -> %d", jogador2pt);
            printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

        }
        if(j == 3){ printf("\nNINGUEM ACERTOU\n"); }
        if (jogadorVezAlt == 1) {
            printf("\nTROCA PARA JOGADOR 2 [ALTERNATIVA]\n");
            jogadorVezAlt = 2;
            jogadorVezOpc = 2;
        } else {
            printf("\nTROCA PARA JOGADOR 1 [ALTERNATIVA]\n");
            jogadorVezAlt = 1;
            jogadorVezOpc = 1;
        }
    }


    printf("\n\n\nPONTUAÇÃO FINAL\n");
    printf("\nJOGADOR 01 -> %d\n", jogador1pt);
    printf("\nJOGADOR 02 -> %d\n", jogador2pt);

    
    
    return 0;
}