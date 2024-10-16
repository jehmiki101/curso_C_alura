#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// #define NUMERO_DE_TENTATIVAS 5

int main () {
    printf("**************************************\n");
    printf("Bem vindo ao nosso jogo de adivinhação\n");
    printf("**************************************\n");

    int segundos = time(0);
    srand(segundos);

    int numeroGrande = rand();

    int numeroSecreto = numeroGrande % 100;
    int chute;
    int ganhou = 0;
    int tentativas = 1;
    double pontos = 1000;

    int nivel;
    printf("Qual o nível de dificuldade?\n");
    printf("(1) Fácil (2) Médio (3) Difícil\n");
    printf("Escolha: \n");
    scanf("%d", &nivel);

    int numeroDeTentativas;

    switch(nivel) {
        case 1:
        numeroDeTentativas = 20;
        break;

        case 2:
        numeroDeTentativas = 15;
        break;

        default:
        numeroDeTentativas = 6;
        break;
    }

    for(int i = 1; i <= numeroDeTentativas; i++) {

        printf("Tentativa %d\n", tentativas);
        printf("Qual é o seu chute? ");

        scanf("%d", &chute);
        printf("Seu chute foi %d\n", chute);

        if(chute < 0) {
            printf("Você não pode chutar números negativos!\n");
            continue;
        }

        int acertou = (chute == numeroSecreto);
        int maior = chute > numeroSecreto;

        if(acertou) {
            printf("Parabéns! Você acertou!\n");
            printf("Jogue de novo, você é um bom jogador!\n");

            ganhou = 1;
            // break;
        }

        else if(maior) {
            printf("Seu número foi maior que o número secreto\n");
        }
        else {
            printf("Seu chute foi menor que o número secreto\n");
        }
        tentativas++;

        double pontosPerdidos = abs(chute - numeroSecreto) / 2.0;
        pontos = pontos - pontosPerdidos;
    }
    printf("Fim de jogo!\n");
    printf("Você acertou em %d tentativas!\n", tentativas-1);
    printf("Total de pontos: %.1f\n", pontos);
}

