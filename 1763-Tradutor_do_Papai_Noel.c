#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int TAMANHO_MAX_STRING = 50;

typedef struct cel {
    char *pais;
    char *mensagem;
    struct cel *prox;
} cel;

void insere(char *pais, char *mensagem, cel **inicio, cel **fim) {
    cel *novaCel = (cel *)malloc(sizeof(cel));
    novaCel->pais = (char *)malloc(TAMANHO_MAX_STRING * sizeof(char));
    novaCel->mensagem = (char *)malloc(TAMANHO_MAX_STRING * sizeof(char));
    strcpy(novaCel->pais, pais);
    strcpy(novaCel->mensagem, mensagem);
    novaCel->prox = NULL;
    if (*fim == NULL)
        *inicio = *fim = novaCel;
    else {
        (*fim)->prox = novaCel;
        *fim = novaCel;
    }
}

char *buscarNaLista(char *pais, cel *cabeca) {
    cel *atual = cabeca;
    while (atual != NULL) {
        if (strcmp(atual->pais, pais) == 0) return atual->mensagem;
        atual = atual->prox;
    }
    return "--- NOT FOUND ---";
}

int main() {
    cel *inicio, *fim;
    inicio = fim = NULL;

    insere("brasil", "Feliz Natal!", &inicio, &fim);
    insere("alemanha", "Frohliche Weihnachten!", &inicio, &fim);
    insere("austria", "Frohe Weihnacht!", &inicio, &fim);
    insere("coreia", "Chuk Sung Tan!", &inicio, &fim);
    insere("espanha", "Feliz Navidad!", &inicio, &fim);
    insere("grecia", "Kala Christougena!", &inicio, &fim);
    insere("estados-unidos", "Merry Christmas!", &inicio, &fim);
    insere("inglaterra", "Merry Christmas!", &inicio, &fim);
    insere("australia", "Merry Christmas!", &inicio, &fim);
    insere("portugal", "Feliz Natal!", &inicio, &fim);
    insere("suecia", "God Jul!", &inicio, &fim);
    insere("turquia", "Mutlu Noeller", &inicio, &fim);
    insere("argentina", "Feliz Navidad!", &inicio, &fim);
    insere("chile", "Feliz Navidad!", &inicio, &fim);
    insere("mexico", "Feliz Navidad!", &inicio, &fim);
    insere("antardida", "Merry Christmas!", &inicio, &fim);
    insere("canada", "Merry Christmas!", &inicio, &fim);
    insere("irlanda", "Nollaig Shona Dhuit!", &inicio, &fim);
    insere("belgica", "Zalig Kerstfeest!", &inicio, &fim);
    insere("italia", "Buon Natale!", &inicio, &fim);
    insere("libia", "Buon Natale!", &inicio, &fim);
    insere("siria", "Milad Mubarak!", &inicio, &fim);
    insere("marrocos", "Milad Mubarak!", &inicio, &fim);
    insere("japao", "Merii Kurisumasu!", &inicio, &fim);

    char pais[TAMANHO_MAX_STRING];

    while (scanf("%s", pais) != EOF) {
        printf("%s\n", buscarNaLista(pais, inicio));
    }

    return 0;
}