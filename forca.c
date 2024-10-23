#include <stdio.h>
#include <string.h>

char palavraSecreta[20];
char chutes[26];
int tentativas = 0;

void abertura()
{
    printf("/****************/\n");
    printf("/ Jogo de Forca */\n");
    printf("/****************/\n\n");
}

void chuta()
{
    char chute;
    printf("Qual letra? ");
    scanf(" %c", &chute);

    chutes[tentativas] = chute;
    tentativas++;
}

int jachutou(char letra)
{
    int achou = 0;
    for (int j = 0; j < tentativas; j++)
    {
        if(chutes[j] == letra)
        {
            achou = 1;
            break;
        }
    }
    return achou;
}

void desenhaForca()
{
    for (int i = 0; i < strlen(palavraSecreta); i++)
    {  
        int achou = jachutou(palavraSecreta[i]);
        if (achou)
        {
            printf("%c ", palavraSecreta[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

void escolhepalavra()
{
    sprintf(palavraSecreta, "MELANCIA");
}

int main()
{
    int acertou = 0;
    int enforcou = 0;

    escolhepalavra();
    abertura();

    do 
    {
        desenhaForca();
        //captura um novo chute
        chuta();
    } while (!acertou && !enforcou);
}