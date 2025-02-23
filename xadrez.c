/*
Desafio de Xadrez - MateCheck
Este código já é a parte final da movimentação da peças.
*/

#include <stdio.h>

// movimento simples usando recursividade
void movimento(int casa, char peca[20])
{

    if (casa > 0)
    {
        movimento(casa - 1, peca); // remove -1

        printf("%s %d\n", peca, casa);
    }
}

// movimento do Cavalo com loop aninhado com tabuleiro para melhor visualização
void movimentoCavalo(int casa, char peca[2])
{

    int a = 1;

    while (a <= casa)
    {
        int b = 1;
        while (b <= casa)
        {
            //  printf("a%d , b%d\t", a , b); // nomeia cada casa da matrix
            // usei o switch para montar o tabuleiro, agora o xadrez irá ter base kkkk
            switch (a * 10 + b) // a multiplicação a * 10 + b é uma forma simples de criar um código único para cada par, ja que a birosca do switch so aceita verificação unica
            {
            case 21:                 // Movimentou uma casa para cima
            case 11:                 // Movimentou uma casa para cima
            case 12:                 // Movimentou uma casa para direita
                printf("%3s", peca); // para formar a letra D de Detonanet kkkk
                break;
            default:
                printf("%3s", ""); // os lugares que não será preenchidos
            }

            b++;
        }
        printf("\n"); // para pular a linha
        a++;
    }
}

// movimento do Bispo Função recursiva que percorre as linhas
void movimentoBispo(int L, int casa, char peca[20])
{
    if (L > casa)
        return; // Condição de parada da recursão

    // Loop interno para percorrer as colunas
    for (int C = 1; C <= casa; C++)
    {
        if (L == C)
        { // Verifica se está na diagonal principal
            printf("%s %d\n", peca, C);
        }
    }

    // Chama a função recursivamente para a próxima linha
    movimentoBispo(L + 1, casa, peca);
}

int main()
{
    // Nível Novato - Movimentação das Peças
    // variaveis
    int bispo = 5;  // devera ir para casa 5
    int torre = 5;  // devera ir para casa 5
    int rainha = 8; // devera ir para casa
    int cavalo = 4; // devera ir para casa 2 para baixo 1 casa para esquerda

    printf("----- Movimentando a Torre -----\n");
    movimento(torre, "Torre move para cima, para casa"); // Chama o movimento para o Torre com a quantidade de casa
    printf("\n\n");

    // tera que ret tambem loop aninhados
    printf("----- Movimentando o Bispo -----\n");
    movimentoBispo(1, bispo, "Bispo move para cima diagonal para casa"); // Chama o movimento para o bispo com a quantidade de casa
    printf("\n\n");

    printf("----- Movimentando o Rainha -----\n");
    movimento(rainha, "Rainha move para esquerda, para casa"); // Chama o movimento para o Rainha com a quantidade de casa
    printf("\n\n");

    printf("----- Movimentando o Cavalo -----\n");
    movimentoCavalo(cavalo, "*"); // Chama o movimento para o Cavalo com a quantidade de casa
    printf("\n\n");


    return 0;
}
