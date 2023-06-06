#include <stdio.h>
#include <stdlib.h> //INCLUDE QUE PERMITE USAR AS FUNCOES RAND E STRAND
#include <locale.h> //INCLUIDE QUE PERMITE MOSTRAR OS LOGS COM ACENTUAÇÃO
#include <stdbool.h> //INCLUDE QUE PERMITE USAR VARIAVEIS BOOLEANAS.
#include<time.h> //INCLUIDE QUE PERMITE USAR A FUNCAO TIME.
#include <string.h>
#define senha "1234"
#define login "admQuiz"


int main()
{
    setlocale(LC_ALL, "Portuguese");

    int admOuPlayer,alterarMais, linha, coluna, i, j, tentativas = 1, jogador1pt = 0, jogador2pt = 0;
    char loginADM[20], senhaADM[20], res[12][12], namePlayer01[20], namePlayer02[20];

    char pergunta[12][300] = {"Qual o conjunto númérico do tipo de variavel double? "                      ,
                              "Qual dessas estruturas de repetição não apresenta limite de repetição? "    ,
                              "A estrutura de repetição For precisa de quantas operações para funcionar? " ,
                              "Qual desses não são tipos primitivos? ",
                              "Para mostrar uma matriz de char em C, como deve ser feito ",
                              "O tipo char tem pelo menos quantos bits? ",
                              "Qual dessas opções são diretivas de pré-compilação em C",
                              "A função main na linguagem C pode ser inicializar de qual forma",
                              "Um array com 13 posições, como posso acessar a sua ultima posição? ",
                              "Qual dessas opções melhor representa inicializar uma matriz ",
                              "Qual dessas opções representa mostrar cada item de um array de inteiros com 5 elementos usando for",
                              "Qual dessas opções melhor completa essa frase\n Uma estrutura de repetição while é uma estrutura ____________"

                              };

    char let[5][10]= {"A --- ","B --- ","C --- ","D --- ","E --- "};

    char opcoes[100][200] = {
                                "Real", "Racionais", "Irracionais", "Complexos", "Inteiros",
                                "For", "While", "DoWhile", "Todas as anteriores", "Nenhuma das anteriores",
                                "1", "2", "3", "4", "5",
                                "Double", "Int", "Char", "void", "Bool",
                                "for(int i=0; i < tamMatriz; i++){\n printf(\"%s\", matriz[i]) }",
                                "for(int i=0; i < tamMatriz; i++){\n printf(\"%s\", matriz[i])\nfor(int j=0; j < tamMatriz; j++){ matriz[i][j] }",
                                "printf(\"%s\", matriz)", "printf(\"%c\", matriz)",
                                "for(int i=0; i < matriz.length; i++){\n printf(\"%s\", matriz[i]) }",
                                "2", "Nenhuma das alternativas", "16", "8", "4",
                                "#define", "#ifdef", "#error", "Nenhuma dessas", "Todos",
                                "int main()", "void main()", "int main(int argc, char *argv[])", "Nenhuma das anteriores", "Todas",
                                "array[].last()", "array[last]", "array[12]", "array[13]", "array[11]",
                                "tipo matriz[coluna][linha]", "matriz[linha][coluna]", "tipo [linha][coluna]", "tipo matriz[linha][coluna]", "matriz[coluna][linha]",
                                "for(int m=0;m <= 4; m++) printf(\"%d\", array[m]);", "for(int m=0;m <= 5; m++){ printf(\"%d\", array[m]); }",
                                "for(int i=0;i < 5; i++){ printf(\"%d\", array[1]); }", "for(int i=0;i <= 5; i++){ printf(\"%d\", array[i]); }",
                                "Nenhuma das anteriores",
                                " que se repete", "que se repete até determida condição", "que se repete quando condição é verdadeira", "condicional", "recursiva"

                            };

    int x = 0;
    

    char respostas[12]= {'A','E','C','E','A', 'D', 'E', 'E', 'C', 'D', 'A', 'C'};
    printf("\n\nBem vindo ao QUIZ\n\n\n\n");

    printf("Você é administrador ?\n");
    printf("[1 - Sim]\n");
    printf("[2 - Não]\n");
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
            bool continuaAlt = true;//alterar para true depois
            printf("GERENCIAMENTO DE QUESTÕES\n\n");

            for (i = 0; i < 12; i++) {
                printf("%d - %s\n",i, pergunta[i]);

                for(j = 0; j < 5; j++){
                    printf("%s %s\n",let[j], opcoes[j+x]);
                }
                printf("\n");
                x += j;
                j = 0;
            }

            while (continuaAlt) {

                int numQuestaoAltera;
                printf("Escolha o número da questão que deseja alterar.");
                scanf("%d", &numQuestaoAltera);
                getchar();

                printf("Digite a nova alternativa: \n");
                gets(pergunta[numQuestaoAltera]);

                int teste = numQuestaoAltera * 5;
                printf("Digite as alternativas:\n");
                char gabarito [5] = {'A', 'B', 'C', 'D', 'E'};

                for(j = 0; j < 5; j++){
                    printf("%c --- ", gabarito[j]);
                    gets(opcoes[teste+j]);
                }

                printf("\nDigite a alternativa correta em letra maiuscula  ");
                scanf("%c", &respostas[numQuestaoAltera]);
                // fgets(respostas[numQuestaoAltera], sizeof(respostas[numQuestaoAltera]), stdin);

                printf("\n\nPERGUNTA ALTERADA!\n\n");

                printf("Deseja alterar mais alguma pergunta? \n");
                printf("[1 - Sim]\n");
                printf("[2 - Não]\n");
                scanf("%d", &alterarMais);

                if (alterarMais == 1) {
                    continuaAlt = true;
                } else {
                    continuaAlt = false;
                }
            }
        }
    }


    int jogadorVezAlt = rand() %2;
    int jogadorVezOpc = jogadorVezAlt;
    int perguntasRestantes[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; 
    int numPerguntasRestantes = 12;

    printf("\nDigite o nome do primeiro jogador: ");
    scanf("%s", namePlayer01);

    printf("\n");

    printf("Digite o nome do segundo jogador: ");
    scanf("%s", namePlayer02);

    x = 0;
    for (i = 0; i < 12; i++) {

        int indicePergunta = rand() % numPerguntasRestantes; 
        int perguntaSelecionada = perguntasRestantes[indicePergunta];

        
        for (j = indicePergunta; j < numPerguntasRestantes - 1; j++) {
            perguntasRestantes[j] = perguntasRestantes[j + 1];
        }
        numPerguntasRestantes--;
        printf("\nJOGADOR DA VEZ DA QUESTÃO %s\n", jogadorVezAlt == 1 ? namePlayer01 : namePlayer02);
        
        printf("%s\n", pergunta[perguntaSelecionada]);
        x = perguntaSelecionada * 5;

        for(j = 0; j < 5; j++){
            printf("%s %s\n",let[j], opcoes[j+x]);
        }

        // x += j;
        j = 0;

        tentativas = 0;

        while(j < 3 ){
            
            printf("\nJOGADOR DA VEZ DAS OPÇÕES %s\n", jogadorVezOpc == 1 ? namePlayer01 : namePlayer02);

            printf("\nDigite sua opção: ");
            getchar();
            tentativas++;
            //fgets(res[i], sizeof(res[i]), stdin);
            scanf("%s", &res[i][0]);
            printf("%s", res[i]);

            if(res[i][0] == respostas[perguntaSelecionada]) {

                printf("\nCORRETO\n");

                if(tentativas == 1){
                    if (jogadorVezOpc == 1) {
                        jogador1pt = jogador1pt + 10;
                        printf("\n%s GANHOU - > 10 pts\n", namePlayer01);

                    } else {
                        jogador2pt = jogador2pt + 10;
                        printf("\n%s GANHOU - > 10 pts\n", namePlayer02);

                    }
                }else if(tentativas == 2){
                    if (jogadorVezOpc == 1) {
                        jogador1pt = jogador1pt + 7;
                        printf("\n%s GANHOU - > 7 pts\n", namePlayer01);

                    } else {
                        jogador2pt = jogador2pt + 7;
                        printf("\n%s GANHOU - > 7 pts\n", namePlayer02);

                    }
                }else{
                    if (jogadorVezOpc == 1) {
                        jogador1pt = jogador1pt + 5;
                        printf("\n%s GANHOU - > 5 pts\n", namePlayer01);

                    } else {
                        jogador2pt = jogador2pt + 5;
                        printf("\n%s GANHOU - > 5 pts\n", namePlayer02);

                    }
                }
                j = 3;

            }else {
                printf("\nErrou tente novamente\n");
            }
            if (jogadorVezOpc == 1) {
                printf("\nTROCA PARA JOGADOR %s [OPCAO]\n", namePlayer02);
                jogadorVezOpc = 2;
            } else {
                printf("\nTROCA PARA JOGADOR %s [OPCAO]\n", namePlayer01);
                jogadorVezOpc = 1;
            }
            j++;
            printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
            printf("\nPONTUAÇÃO");
            printf("\n%s -> %d",namePlayer01, jogador1pt);
            printf("\n%s -> %d",namePlayer02, jogador2pt);
            printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

        }
        if(j == 3){ printf("\nNINGUEM ACERTOU\n"); }
        if (jogadorVezAlt == 1) {
            printf("\nTROCA PARA JOGADOR %s [ALTERNATIVA]\n", namePlayer02);
            jogadorVezAlt = 2;
            jogadorVezOpc = 2;
        } else {
            printf("\nTROCA PARA JOGADOR %s [ALTERNATIVA]\n", namePlayer01);
            jogadorVezAlt = 1;
            jogadorVezOpc = 1;
        }
    }


    printf("\n\n\nPONTUAÇÃO FINAL\n");
    printf("\n%s -> %d\n",namePlayer01, jogador1pt);
    printf("\n%s -> %d\n",namePlayer02, jogador2pt);


    return 0;
}